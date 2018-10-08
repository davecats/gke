# gke
**gke** computes the Generalized Kolmogorov Equation (GKE) for turbulent channels and other plane flows with two directions of statistical homogeneity.  

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

An alternative implementation of the Step 2), which features reduced memory requirement at the cost of more frequent I/O and thus slower computation, is provided in *step2/step2_gke_lowmem.cpl*. 

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
