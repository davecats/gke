#!/bin/bash
DIR=`pwd`
echo
echo "This will run the tutorial. This will install "
echo "CPL (v2021-11-23) and requires a working MATLAB installation "
echo 
read -p "Are you sure (y/n)? " -n 1 -r
echo    # (optional) move to a new line
if [[ ! $REPLY =~ ^[Yy]$ ]]
then
    exit 1
fi

# Install cpl
bash 2021-11-23-cpl.sh

# Compile all files
cd ..; cd step1; makecpl -a step1_singlepoints.cpl;
cd ..; cd step2; makecpl -a step2_gke.cpl; 
cd ..; cd step3; makecpl -a step3_gke.cpl; 
cd $DIR

# Run the calculation of the GKE
../step1/step1_singlepoints
../step2/step2_gke
../step3/step3_gke
echo "GKE computation completed!"

# Visualise the result with matlab
echo "Visualising example results with MATLAB..."
matlab -r "run('check.m'); input('Press any key to finish'); exit;" 
