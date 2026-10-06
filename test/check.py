#!/usr/bin/env python3
"""Visualise one term of the GKE stored in gke.bin.

Run from the case directory (containing flow_field.in, gke.in and gke.bin).
"""

import re

import numpy as np
import matplotlib.pyplot as plt


def namelist(filename):
    """Values of a Fortran namelist file as {name: [numbers]}."""
    values = {}
    for line in open(filename):
        match = re.match(r'\s*(\w+)\s*=([^!]*)', line)
        if match:
            items = [s for s in match.group(2).replace(',', ' ').split()]
            values[match.group(1)] = [float(s) for s in items]
    return values


# Grid (see dataset.cpl): the wall-normal grid consists of the two walls and
# the cell centres, iy=-1..ny+1
# -------------------
flow = namelist('flow_field.in')
nx, n2m, nz = (int(n) for n in flow['num_grid'])
lx, ly, lz = flow['domainlength']
ny = n2m - 1
dx, dy, dz = lx / nx, ly / n2m, lz / nz
y = np.r_[0.0, (np.arange(n2m) + 0.5) * dy, ly]


# Undersampled separations (see gkedata.cpl)
# ----------------------
def undersampled_indices(n, d, uL1, uL2):
    im = []
    i = 0
    while i < n // 2:
        im.append(i)
        i += 1 if i * d <= uL1 else (4 if i * d <= uL2 else 8)
    im.append(n // 2)
    m = len(im)
    for k in range(1, m - 1):
        im.append(n - im[m - 1 - k])
    return np.array(im, dtype=int)


gke = namelist('gke.in')
imx = undersampled_indices(nx, dx, *gke['uLx'])
imz = undersampled_indices(nz, dz, *gke['uLz'])
mx = len(imx)
mz = len(imz)

# Define the startpos array
# ----------------------
#
# gke.bin is a C-ordered
# ARRAY(0..startpos(ny DIV 2 +1)-1,0..mx-1,0..mz-1) OF GKETERMS
# (see gkedata.cpl for the definition of GKETERMS)
#
# the second and third index in the array are the streamwise and spanwise
# separation, while the first is a flattened index corresponding to the
# touple [iy1,iy2], with iy1=-1:ny/2 and iy2=y1:ny-y1. iy1 and iy2 are the
# two wall-normal indices at which we evaluate the structure function.
# Remember that ry = y(iy2)-y(iy1) and Yc=0.5*(y(iy1)+y(iy2)). In this way,
# startpos[iy+1+i] will be the index pointing to the touple iy1=iy and
# iy2=iy+i, if available.
#
startpos = np.zeros(ny // 2 + 3, dtype=np.int64)
startpos[1:] = np.cumsum(ny - 2 * np.arange(-1, ny // 2 + 1) + 1)

# Load the GKE
# -----------------------
#
# This will load only the GKE for ry=0 and rx=0
gkei = np.zeros((6, mz, ny // 2 + 2))
IX = 0
with open('./gke.bin', 'rb') as f:
    for iy in range(-1, ny // 2 + 1):
        IY = iy + 1
        f.seek(8 * (6 * mz * mx * startpos[IY] + 6 * mz * IX))
        gkei[:, :, IY] = np.fromfile(f, dtype=np.float64, count=6 * mz).reshape(mz, 6).T

# Plot a term of the GKE
# ------------------------
k = 6  # 1: phiRx, 2: phiRy, 3: phiRz, 4: phiC, 5: <duidui>, 6: xi
labels = [r'$\phi_{r_x}$', r'$\phi_{r_y}$', r'$\phi_{r_z}$', r'$\phi_C$',
          r'$\langle\delta u_i \delta u_i\rangle$', r'$\xi$']

# positive separations only, sorted
order = np.argsort(imz)[: mz // 2 + 1]
rz = imz[order] * dz
fig, ax = plt.subplots()
pc = ax.pcolormesh(rz, y[: ny // 2 + 2], gkei[k - 1, order, :].T, shading='gouraud')
ax.contour(rz, y[: ny // 2 + 2], gkei[k - 1, order, :].T, levels=[0],
           colors='k', linestyles='--')
ax.set_xlabel(r'$r_z$')
ax.set_ylabel(r'$Y$')
ax.set_title(labels[k - 1] + r' at $r_x=r_y=0$')
fig.colorbar(pc, ax=ax)

plt.show()
