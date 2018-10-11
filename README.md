# gke
**gke** computes the Generalized Kolmogorov Equation (GKE) for turbulent channels and other plane flows with two directions of statistical homogeneity.  


![Image of GKE](https://github.com/davecats/gke/blob/master/.image.png) 

This repository is the reference implementation of the GKE described in

``` D. Gatti et al., "An efficient numerical method for the Generalized Kolmogorov Equation", Journal of Turbulence, (submitted, 2018) ```

The code is:
* *Simple*: it consists of few lines of code 
* *Parallel*: with shared and distributed memory parallelization
* *Efficient*: it leverages Fast Fourier Transform algorithms whenever possible


### Description

The computation is divided in three steps, each of them provided as a separate program:
1) *step1/step1_singlepoints.cpl*: the computation of the single-point budgets of the Reynolds stresses
2) *step2/step2_gke.cpl*: the computation of the GKE terms that do not involve a wall-normal derivatives
3) *step3/step3_gke.cpl*: the computation of the GKE terms involving wall-normal derivatives

The memory requirement of Step 2) can be further reduced by commenting the line  
```#define wholefiled```  
of *step2/step2_gke.cpl* (line 17). Doing so will deactivate loading the whole velocity field and only a pair (iy1,iy2) of wall-parallel planes of the velocity field will be loaded at a time. Beware that this increases the I/O and possibly slows down calculations.

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
``` D. Gatti et al., "An efficient numerical method for the Generalized Kolmogorov Equation", Journal of Turbulence, (submitted, 2018) ```
