# gke    


![Image of GKE](https://github.com/davecats/gke/blob/master/.image.png) 

This repository is the reference implementation of the GKE described in

``` D. Gatti et al., "An efficient numerical method for the Generalized Kolmogorov Equation", Journal of Turbulence, 20 (8), 457–480, 2018 ```

The code is:
* *Simple*: it consists of few lines of code 
* *Parallel*: with shared and distributed memory parallelization
* *Efficient*: it leverages Fast Fourier Transform algorithms whenever possible

and written in the 
<span itemscope itemtype="http://schema.org/SoftwareApplication http://schema.org/ComputerLanguage"><meta itemprop="name" content="CPL"><meta itemprop="applicationCategory" content="DeveloperApplication"><meta itemprop="applicationSubCategory" content="Programming Language"><meta itemprop="operatingSystem" content="Linux, macOS, Windows Subsystem for Linux"><a itemprop="url" href="https://CPLcode.net" target="_blank" rel="noopener"><img src="https://img.shields.io/static/v1?label=CPL&message=Compiler+and+Programming+Language&color=success&style=plastic" style="vertical-align:middle" alt="CPL Compiler and Programming Language"></a></span>

### Description

The code is written in the programming language CPL, whose compiler can be downloaded [here](https://cplcode.net/).

The computation is divided in three steps, each of them provided as a separate program:
1) *step1/step1_singlepoints.cpl*: the computation of the single-point budgets of the Reynolds stresses
2) *step2/step2_gke.cpl*: the computation of the GKE terms that do not involve a wall-normal derivatives
3) *step3/step3_gke.cpl*: the computation of the GKE terms involving wall-normal derivatives

In the directory *tutorial* you can find the bash script *tutorial/run_tutorial.bash* which will compile the code and run it on simple test data, which correspond to a Minimal Flow Unit (MFU) at a friction Reynolds number of $Re_\tau=200$. The tutorial requires a working CPL installation and MATLAB, in order to visualise the results. 

The memory requirement of Step 2) can be further reduced by commenting the line  
```#define wholefiled```  
of *step2/step2_gke.cpl* (line 17). Doing so will deactivate loading the whole velocity field and only a pair (iy1,iy2) of wall-parallel planes of the velocity field will be loaded at a time. Beware that this increases the I/O and possibly slows down calculations.

### Physical-space statistics and particle masking

By default Step 2) evaluates the two-point statistics pseudo-spectrally, via the convolution theorem. Uncommenting the line  
```#define physicalspace```  
of *step2/step2_gke.cpl* switches to a direct accumulation of the statistics over pairs of points in physical space. For single-phase flows the results are identical up to round-off, but the computation is slower. Its purpose is masked statistics, e.g. for particle-laden flows: for each snapshot *Dati.cart.〈n〉.fld* an optional indicator field *mask.〈n〉.fld* is read if present, a `STORED ARRAY(-1..ny+1, 0..2*nxd-1, 0..nzd-1) OF REAL` (i.e. double precision, C-ordered, on the fine physical grid nxc × nzc printed at startup) with 1.0 marking fluid points and 0.0 solid points. Point pairs with at least one point inside the solid phase are skipped, and every average is renormalized by the number of accumulated pairs of that snapshot. Without a mask file all points are treated as fluid, which reproduces the unmasked results exactly.

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
