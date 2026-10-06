# gke    


![Image of GKE](https://github.com/davecats/gke/blob/master/.image.png) 

This repository is the reference implementation of the GKE described in

``` D. Gatti et al., "An efficient numerical method for the Generalized Kolmogorov Equation", Journal of Turbulence, 20 (8), 457–480, 2018 ```

The code is:
* *Simple*: it consists of few lines of code 
* *Parallel*: with shared and distributed memory parallelization
* *Efficient*: it leverages Fast Fourier Transform algorithms whenever possible, also for the averages restricted to the fluid phase of particle-laden flows

and written in the 
<span itemscope itemtype="http://schema.org/SoftwareApplication http://schema.org/ComputerLanguage"><meta itemprop="name" content="CPL"><meta itemprop="applicationCategory" content="DeveloperApplication"><meta itemprop="applicationSubCategory" content="Programming Language"><meta itemprop="operatingSystem" content="Linux, macOS, Windows Subsystem for Linux"><a itemprop="url" href="https://CPLcode.net" target="_blank" rel="noopener"><img src="https://img.shields.io/static/v1?label=CPL&message=Compiler+and+Programming+Language&color=success&style=plastic" style="vertical-align:middle" alt="CPL Compiler and Programming Language"></a></span>

### Description

The code is written in the programming language CPL, whose compiler can be downloaded [here](https://cplcode.net/).

This branch computes the GKE in physical space for the particle-resolved channel DNS described in *simulation_data_description.pdf* (the "xinju dataset"): every average is taken over the fluid points only, i.e. points (single-point statistics) and pairs of points (two-point statistics) with at least one point inside a particle are excluded, and averages are renormalized by the number of accumulated points or pairs.

The computation is divided in three steps, each of them provided as a separate program and run in sequence:
1) **step 1** (*step1/step1_singlepoints.cpl*) computes the mean profiles and the single-point budgets of the Reynolds stresses, and writes them to *uiuj.bin*;
2) **step 2** (*step2/step2_gke.cpl*) computes the GKE terms that do not involve wall-normal derivatives, reading *uiuj.bin* and writing *gke.bin*;
3) **step 3** (*step3/step3_gke.cpl*) adds the GKE terms involving wall-normal derivatives, updating *gke.bin* in place.

Step 2 exists in two interchangeable implementations, which compute the same averages over pairs of fluid points and agree up to round-off:

| program | method | cost |
|---|---|---|
| *step2_gke* (default) | each pair sum is expanded into correlations of mask-weighted fields, evaluated for all separations at once with FFTs | about 1 minute per snapshot of the xinju dataset on 24 cores |
| *step2_gke_direct* | explicit accumulation over all pairs of points and all sampled separations; OpenMP or OpenACC (GPU) | about 6 hours per snapshot on 24 cores; serves as reference |

All programs are OpenMP-parallel, and their results do not depend on the number of threads.

### Input and output files

The programs run in a case directory containing:
* *flow_field.in* — the parameter file of the simulation (Fortran namelist; grid, box, Reynolds number, MPI decomposition);
* *fluid〈n〉/flowfield〈rank〉.field* — the snapshots, n written with seven digits, one file per MPI rank of the simulation;
* *gke.in* — the parameters of the analysis, e.g.
```
&gke
nfmin = 20000          ! first snapshot
nfmax = 20000          ! last snapshot
dn    = 1000           ! snapshot increment
uLx   = 0.2, 0.5       ! x-separations: all points up to uLx(1), every 4th up to uLx(2), every 8th beyond
uLz   = 0.2, 0.5       ! z-separations: as above
/
```
The outputs are *uiuj.bin* (single-point budgets, step 1) and *gke.bin* (GKE terms, steps 2 and 3); their binary layout is documented in *test/check.py*, which also shows how to read and plot them.

All knowledge of the input format is confined to *dataset.cpl*, which reads one snapshot and provides the fields to the rest of the code; *namelist.cpl* reads the parameter files. Another dataset can be analysed by replacing *dataset.cpl* with a module providing the same interface (documented at its top). For the xinju dataset:
* only u, v, w, p and the level set are read; the fluid points are those with positive level set;
* the velocity, stored on the faces of the staggered grid, is interpolated to the cell centres, where all quantities are evaluated;
* the wall-normal grid consists of the two walls and of the cell centres; at the walls the velocity vanishes and the pressure is extrapolated;
* all derivatives are standard (explicit) second-order finite differences: dudx, dvdy and dwdz are differences of the values on the two opposite faces of each cell, so that the discrete divergence of the simulation is preserved; the other velocity derivatives are central differences in x and z and 3-point differences in y (one-sided at the walls). Only the smooth averaged profiles are differentiated in y with 5-point stencils.

The mean velocity (U,V,W)(y) is fully accounted for: in particular the mean wall-normal velocity V of the fluid phase, which does not vanish in particle-laden flows, enters the fluctuations, the transport by the mean flow and the production terms. The terms describing the action of the particles on the fluid are not yet included; the open questions and the plan are collected in *doc/particles.md*.

### Compiling

`./compile.bash` builds all programs with gcc and OpenMP enabled. Individual programs are built with, e.g.,
```
cd step2; cpl make step2_gke.cpl -fopenmp
```
(omitting `-fopenmp` gives a serial build). For the GPU build of *step2_gke_direct*, load the NVIDIA HPC SDK environment (e.g. `module load nvhpc`) and use
```
cd step2; GPU=1 cpl make step2_gke_direct.cpl -acc=gpu
```
The local *step2/Makefile* selects the compiler: gcc by default, nvc when `GPU=1` is set. The NVIDIA HPC SDK runtime libraries must also be available when running the GPU build.

### Running

From the case directory, run the three steps in sequence, e.g.
```
export OMP_WAIT_POLICY=passive
export OMP_NUM_THREADS=24
../step1/step1_singlepoints
../step2/step2_gke
../step3/step3_gke
```
`OMP_NUM_THREADS` selects the number of threads; setting `OMP_WAIT_POLICY=passive` is recommended, since the default busy-waiting policy can slow down the parallel regions considerably when all hardware threads are used (the programs print a hint if it is unset).

Memory: a snapshot occupies 8 fields of (n1m)×(n2m+2)×(n3m) doubles, and *step2_gke* additionally keeps the spectra of 24 quantities in all planes (about 3.4 GiB for the xinju dataset, printed at startup).

Step 2 additionally supports distributed-memory parallelization: launched as
```
../step2/step2_gke <iproc> <nproc>
```
each of the nproc independently started processes computes its own range of wall-normal positions and writes its own disjoint part of *gke.bin* (which is shared, so the processes may run on different nodes of a common filesystem). All processes must complete before step 3 is run.

### Testing

`test/run_test.bash` generates a small synthetic case in the format of the xinju dataset (*test/make_testcase.py*), runs the whole pipeline with both implementations of step 2 and checks that they agree up to round-off.

### Database

The directory *database* constains the GKE analysis performed for turbulent channels at two different values of friction Reynolds number Retau=200 and Retau=1000. Refer to database/README.md for further information! 

### Contacts

Dr. Davide Gatti  
davide.gatti [at] kit.edu  
msc.davide.gatti [at] gmail.com  

Karlsruhe Institute of Technology  
Institute of Fluid Dynamics  
Kaiserstraße 10  
76131 Karlsruhe  

### How to cite this code

If you use this code and find it helpful, please cite:  
``` D. Gatti et al., "An efficient numerical method for the Generalized Kolmogorov Equation", Journal of Turbulence, 20 (8), 457–480, 2018 ```
