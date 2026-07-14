#!/bin/bash
CDIR=$(pwd)
DIR=$(git rev-parse --show-toplevel)
cd $DIR/step1
cpl make step1_singlepoints_fourier.cpl
cpl make step1_singlepoints_physical.cpl -fopenmp
cd $DIR/step2
cpl make step2_gke_fourier.cpl
cpl make step2_gke_physical.cpl -fopenmp
cd $DIR/step3
cpl make step3_gke.cpl
