# gke    


![Image of GKE](https://github.com/davecats/gke/blob/master/.image.png) 

This repository is the reference implementation of the GKE described in

``` D. Gatti et al., "An efficient numerical method for the Generalized Kolmogorov Equation", Journal of Turbulence, 20 (8), 457–480, 2018 ```

The code is:
* *Simple*: it consists of few lines of code 
* *Parallel*: with shared and distributed memory parallelization, and optional GPU offload
* *Efficient*: it leverages Fast Fourier Transform algorithms whenever possible

and written in the 
<span itemscope itemtype="http://schema.org/SoftwareApplication http://schema.org/ComputerLanguage"><meta itemprop="name" content="CPL"><meta itemprop="applicationCategory" content="DeveloperApplication"><meta itemprop="applicationSubCategory" content="Programming Language"><meta itemprop="operatingSystem" content="Linux, macOS, Windows Subsystem for Linux"><a itemprop="url" href="https://CPLcode.net" target="_blank" rel="noopener"><img src="https://img.shields.io/static/v1?label=CPL&message=Compiler+and+Programming+Language&color=success&style=plastic" style="vertical-align:middle" alt="CPL Compiler and Programming Language"></a></span>

### Description

The code is written in the programming language CPL, whose compiler can be downloaded [here](https://cplcode.net/).

The computation is divided in three steps, each of them provided as a separate program and run in sequence:
1) **step 1** computes the single-point budgets of the Reynolds stresses and the mean profiles, and writes them to *uiuj.bin*;
2) **step 2** computes the GKE terms that do not involve wall-normal derivatives, reading *uiuj.bin* and writing *gke.bin*;
3) **step 3** (*step3/step3_gke.cpl*) adds the GKE terms involving wall-normal derivatives, updating *gke.bin* in place.

Steps 1 and 2 exist in two interchangeable variants, so that three execution paths are available:

| path | programs | purpose |
|---|---|---|
| Fourier (default) | *step1_singlepoints_fourier*, *step2_gke_fourier* | fastest CPU path: statistics evaluated with Parseval's theorem and the convolution theorem |
| physical space | *step1_singlepoints_physical*, *step2_gke_physical* | statistics accumulated point by point (step 1) and over pairs of points (step 2); slower, but supports particle masking |
| physical space on GPU | same as above, step 2 built with the NVIDIA HPC SDK | offloads the pair-accumulation kernel, which dominates the cost of step 2, to a GPU |

For single-phase flows all paths produce identical results: the two CPU variants agree up to round-off, and within each variant the results are independent of the number of threads or processes down to the last bit. All programs are OpenMP-parallel; the distributed-memory parallelization of step 2 and the GPU offload are described below.

### Input and output files

The programs run in a case directory containing:
* *dns.in* — the simulation parameters (grid, box, Reynolds number, ...);
* *Dati.cart.〈n〉.fld* and *pField〈n〉.fld* — the velocity and pressure snapshots, n = nfmin ... nfmax;
* *mask.〈n〉.fld* — optional particle masks for the physical-space path (see below).

The snapshot range (nfmin, nfmax, dn), the limits of the undersampled separations (uLx1, uLx2, uLz1, uLz2) and the output file name are set at the top of *gkedata.cpl* and compiled into the programs: edit them and recompile for a new case. The outputs are *uiuj.bin* (single-point budgets, step 1) and *gke.bin* (GKE terms, steps 2 and 3); their binary layout is documented in *tutorial/check.py*, which also shows how to read and plot them (MATLAB equivalent: *tutorial/check.m*).

### Compiling

`./compile.bash` builds all five programs with gcc and OpenMP enabled. Individual programs are built with, e.g.,
```
cd step2; cpl make step2_gke_fourier.cpl -fopenmp
```
(omitting `-fopenmp` gives a serial build with identical results). For the GPU build of step 2, load the NVIDIA HPC SDK environment (e.g. `module load nvhpc`) and use
```
cd step2; GPU=1 cpl make step2_gke_physical.cpl -acc=gpu
```
The local *step2/Makefile* selects the compiler: gcc by default, nvc when `GPU=1` is set. The NVIDIA HPC SDK runtime libraries must also be available when running the GPU build.

### Running

From the case directory, run the three steps of the chosen path in sequence, e.g.
```
export OMP_WAIT_POLICY=passive
export OMP_NUM_THREADS=24
../step1/step1_singlepoints_fourier
../step2/step2_gke_fourier
../step3/step3_gke
```
`OMP_NUM_THREADS` selects the number of threads; setting `OMP_WAIT_POLICY=passive` is recommended, since the default busy-waiting policy can slow down the parallel regions considerably when all hardware threads are used (the programs print a hint if it is unset).

Step 2, by far the most expensive one, additionally supports distributed-memory parallelization: launched as
```
../step2/step2_gke_fourier <iproc> <nproc>
```
each of the nproc independently started processes computes its own range of wall-normal positions and writes its own disjoint part of *gke.bin* (which is shared, so the processes may run on different nodes of a common filesystem). All processes must complete before step 3 is run. For the GPU build, one GPU is used per process and can be selected with `ACC_DEVICE_NUM` or `CUDA_VISIBLE_DEVICES`.

The directory *tutorial* contains the bash script *tutorial/run_tutorial.bash*, which compiles the code and runs the Fourier path on simple test data corresponding to a Minimal Flow Unit (MFU) at a friction Reynolds number of $Re_\tau=200$, visualising the results with MATLAB (*check.m*) — or use `python3 check.py` if MATLAB is unavailable.

The memory requirement of step 2 can be reduced by commenting the line  
```#define wholefield```  
of *step2/step2_gke_fourier.cpl* (or *step2/step2_gke_physical.cpl*). Doing so will deactivate loading the whole velocity field and only a pair (iy1,iy2) of wall-parallel planes of the velocity field will be loaded at a time. Beware that this increases the I/O and possibly slows down calculations.

### Physical-space statistics and particle masking

The programs *step1/step1_singlepoints_physical.cpl* and *step2/step2_gke_physical.cpl* accumulate the statistics point by point (step 1) and over pairs of points (step 2) in physical space, instead of using Parseval's theorem and the convolution theorem. For single-phase flows the results are identical (to round-off) to those of the *_fourier* programs, but the computation is slower. Their purpose is masked statistics, e.g. for particle-laden flows: for each snapshot *Dati.cart.〈n〉.fld* an optional mask file *mask.〈n〉.fld* is read if present, a `STORED ARRAY(-1..ny+1, 0..2*nxd-1, 0..nzd-1) OF REAL` (i.e. double precision, C-ordered, on the fine physical grid nxc × nzc printed at startup) with 1.0 marking fluid points and 0.0 solid points. Points (step 1) and point pairs (step 2) with at least one point inside the solid phase are skipped, and every average is renormalized by the number of accumulated points or pairs. If no mask file exists all points are treated as fluid. In step 1 the velocity gradient is still computed spectrally from the global field; only the accumulation of the statistics is performed in physical space.

### GPU offload

The pair-accumulation kernel of *step2_gke_physical.cpl* carries OpenACC directives next to the OpenMP ones, so a single source serves the serial, multithreaded and GPU execution paths. In the GPU build the plane fields, the particle mask and the undersampled separations stay resident on the GPU; per pair of wall-parallel planes only the updated plane fields are copied in and the small buffer of raw pair sums out, while the renormalization by the pair counts and the GKE updates remain on the host. The GPU results coincide with the CPU ones up to round-off (the parallel reduction changes the summation order); on double-precision-capable data-center GPUs the kernel, which performs the overwhelming majority of the work, is essentially flop-bound.

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
