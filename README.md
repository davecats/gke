# gke    


![Image of GKE](https://github.com/davecats/gke/blob/master/.image.png) 

This repository is the reference implementation of the GKE described in

``` D. Gatti et al., "An efficient numerical method for the Generalized Kolmogorov Equation", Journal of Turbulence, 20 (8), 457–480, 2018 ```

The code is:
* *Simple*: it consists of few lines of code 
* *Parallel*: with shared and distributed memory parallelization
* *Efficient*: it leverages Fast Fourier Transform algorithms whenever possible

and written in the  [![programming language CPL](https://img.shields.io/static/v1?label=CPL&message=Compiler+and+Programming+Language&color=success&style=plastic)](https://cplcode.net/)

### Description

The code is written in the programming language CPL, whose compiler can be downloaded [here](https://cplcode.net/).

The computation is divided in three steps, each of them provided as a separate program:
1) *step1/step1_singlepoints.cpl*: the computation of the single-point budgets of the Reynolds stresses
2) *step2/step2_gke.cpl*: the computation of the GKE terms that do not involve a wall-normal derivatives
3) *step3/step3_gke.cpl*: the computation of the GKE terms involving wall-normal derivatives

In the directory *tutorial* you can find the bash script *tutorial/run_tutorial.sh* which will compile the code and run it on simple test data, which correspond to a Minimal Flow Unit (MFU) at a friction Reynolds number of <img src="https://render.githubusercontent.com/render/math?math=Re_\tau=200">. The tutorial requires a working CPL installation and MATLAB, in order to visualise the results. 

The memory requirement of Step 2) can be further reduced by commenting the line  
```#define wholefiled```  
of *step2/step2_gke.cpl* (line 17). Doing so will deactivate loading the whole velocity field and only a pair (iy1,iy2) of wall-parallel planes of the velocity field will be loaded at a time. Beware that this increases the I/O and possibly slows down calculations.

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
