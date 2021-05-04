#!/usr/bin/env python3#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Nov 16 17:59:17 2020

@author: davide
"""

import numpy as np
from numpy import pi
import matplotlib.pyplot as plt
import re

def fftfit(x):
  while not x & 1:
    x = x >> 1
  return (x==1 or x==3)

def read_dnsin(path):
  with open(path) as fileHandle:
      lines = fileHandle.readlines()
      dns = {
        "ny" : int(re.search('ny=(.*)nx=', lines[0]).group(1)),
        "nx" : int(re.search('nx=(.*)nz=', lines[0]).group(1)),
        "nz" : int(re.search('nz=(.*)\n', lines[0]).group(1)),
        "alfa0" : int(re.search('alfa0=(.*)beta0', lines[1]).group(1)),
        "beta0" : int(re.search('beta0=(.*)\n', lines[1]).group(1)),
      }
      return dns

def load_field(filename):
    fileHandler = open(filename,"rb")
    # Read field size from file
    dns = {
    "nx" : np.fromfile(fileHandler,dtype=np.int32,count=1)[0],
    "ny" : np.fromfile(fileHandler,dtype=np.int32,count=1)[0],
    "nz" : np.fromfile(fileHandler,dtype=np.int32,count=1)[0],
    "alfa0" : np.fromfile(fileHandler,dtype=np.double,count=1)[0],
    "beta0" : np.fromfile(fileHandler,dtype=np.double,count=1)[0],
    "ni" : np.fromfile(fileHandler,dtype=np.double,count=1)[0],
    "a" :  np.fromfile(fileHandler,dtype=np.double,count=1)[0],
    "ymin" : np.fromfile(fileHandler,dtype=np.double,count=1)[0],
    "ymax" : np.fromfile(fileHandler,dtype=np.double,count=1)[0],
    "time" : np.fromfile(fileHandler,dtype=np.double,count=1)[0],
    }
    dns["nzd"]=3*dns["nz"]-1;
    while not fftfit(dns["nzd"]): dns["nzd"] += 1
    # Define grid
    mesh ={ 
    "y" : dns["ymin"] + (dns["ymax"]-dns["ymin"])*(np.tanh(dns["a"]*(np.arange(-1,dns["ny"]+2)/dns["ny"]-1))/np.tanh(dns["a"])+1),
    "z" : np.arange(dns["nzd"])/dns["nzd"]*(2*pi/dns["beta0"]),
    }
    # Read field in Fourier 
    field = np.zeros([3,2*dns["nx"]+1,dns["nzd"],dns["ny"]+3],dtype=np.complex128)
    tmp = np.fromfile(fileHandler,dtype=np.complex128,count=((dns["nx"]+1)*(2*dns["nz"]+1)*(dns["ny"]+3)*3)).reshape([3,dns["nx"]+1,2*dns["nz"]+1,dns["ny"]+3])
    field[:,0:dns["nx"],0:dns["nz"]+1,:] = tmp[:,0:dns["nx"],dns["nz"]:,:]
    field[:,0:dns["nx"],dns["nzd"]-dns["nz"]:dns["nzd"],:] = tmp[:,0:dns["nx"],0:dns["nz"],:]
    del tmp
    # Backward Fourier transform in z direction
    field = np.fft.ifft(field, n=None, axis=2, norm=None)
    # Use Hermitian symmetry
    field[:,dns["nx"]+1:,:,:] = np.conj(field[:,dns["nx"]+1:1:-1,:,:])
    # Backward Fourier transform in x direction
    field = np.fft.ifft(field, n=None, axis=1, norm=None); field=np.real(field);
    # Check the result is real
    #print(np.max(np.abs(np.imag(field))))
    # Rescale output
    field *= np.prod(field[0,:,:,0].shape)
    return dns,mesh,field

# Load the last N phases and plot them
N = 16
nfmax = N*10
nfmin = nfmax-N+1


# Plot force field
# -------------------------------------------
#
# This will plot the velocity profile w(y) at the center 
# of the actuator for a given number of phases
# 

# Select the component to plot
iC = 2
# Load the last N phases and plot them
N = 16
nfmax = N*10
nfmin = nfmax-N+1
# If this flag is true the results will be made dimensional
# with the characteristic velocity "uchar" and the length "hchar".
# This is useful to compare back against the experiment.
doRescale = True
uchar = 4.8332
hchar = 0.0125
rho=1.2


for iF in range(nfmin,nfmax+1):
   fig = plt.figure()
   dns, mesh, field = load_field('../1_quiescentFlowSimulation/Force.cart.'+str(iF)+'.out')
   if doRescale:
     mesh["y"] *= hchar; mesh["z"] *= hchar; field *= rho*uchar**2/hchar
   plt.pcolormesh(mesh["z"],mesh["y"],field[iC,0,:,:].transpose())
   plt.xlabel(r'$w$')
   plt.ylabel(r'$y$')
   plt.ylim([0, 2*mesh["z"][-1]])
plt.show()

#%%
# Plot velocity field
# -------------------------------------------
#
# This will plot the velocity profile w(y) at the center 
# of the actuator for a given number of phases
# 

# Select the component to plot
iC = 2
# If this flag is true the results will be made dimensional
# with the characteristic velocity "uchar" and the length "hchar".
# This is useful to compare back against the experiment.
doRescale = True
uchar = 4.8332
hchar = 0.0125
rho=1.2


for iF in range(nfmin,nfmax+1):
   fig = plt.figure()
   dns, mesh, field = load_field('../1_quiescentFlowSimulation/Dati.cart.'+str(iF)+'.out')
   if doRescale:
     mesh["y"] *= hchar; mesh["z"] *= hchar; field *= uchar
   plt.pcolormesh(mesh["z"],mesh["y"],field[iC,0,:,:].transpose())
   #plt.quiver(mesh["z"],mesh["y"],field[2,0,:,:].transpose(),field[1,0,:,:].transpose())
   plt.xlabel(r'$w$')
   plt.ylabel(r'$y$')
   plt.ylim([0, 2*mesh["z"][-1]])
plt.show()
