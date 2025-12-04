#!/bin/bash
DIR=`pwd`
echo
echo "This will install "
echo "CPL (v2021-11-23) and set environment variables "
echo 
read -p "Are you sure to continue (y/n)? " -n 1 -r
echo    # (optional) move to a new line
if [[ ! $REPLY =~ ^[Yy]$ ]]
then
    exit 1
fi

# Install cpl
bash 2021-11-23-cpl.sh

# Set environment variables
export PATH=$DIR/fri/:$PATH
