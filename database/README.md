## gke databases
In this directory you can find GKE analysis results for turbulent channels at two different values of friction Reynolds number Retau=200 and Retau=1000. Information on the underlying database of turbulent channel velocity fields produced via Direct Numerical Simulation (DNS) can be found in 

``` D. Gatti et al., "An efficient numerical method for the Generalized Kolmogorov Equation", Journal of Turbulence, (submitted, 2018) ```   

The database is made up of several VTK files, which can be opened and visualzed with the open-source data analysis and visualization software [paraview](https://www.paraview.org). In each directory corresponsing to a differen value of friction Reynolds number, you can find several files with name   

``` ReXXX_rx_YYY.vtk ```

where XXX is the value of friction Reynolds number and YYY is the specific value of streamwise separation *rx* in viscous units considered in the file. In fact, each file contains the GKE terms for the three-dimensional space (*Y*,*ry*,*rz*) and *rx* is parametrized amond different files.    

All quantities are made nondimensional in viscous units, i.e. with the friction velocity and kinematic viscosity of the fluid.   
If you have question on the database refer to the aformentioned publication, file an issue or contact me at the contact information specified [here](https://github.com/davecats/gke).
