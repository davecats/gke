#!/bin/bash
CDIR=$(pwd)
DIR=$(git rev-parse --show-toplevel)
cd $DIR/step1
cpl make step1_singlepoints.cpl
cd $DIR/step2
cpl make step2_gke.cpl
cd $DIR/step3
cpl make step3_gke.cpl
