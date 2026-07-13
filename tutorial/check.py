#!/usr/bin/env python3
"""Python port of check.m: visualise one term of the GKE stored in gke.bin."""

import re

import numpy as np
import matplotlib.pyplot as plt


def fftfit(x):
    """True if x factors as 2^n or 3*2^n (FFT-friendly size)."""
    x = int(x)
    while x % 2 == 0:
        x //= 2
    return x in (1, 3)


def parse_number(s):
    """Parse a numeric value, allowing simple fractions like 200.0/1000.0."""
    s = s.strip().rstrip(';').strip()
    if '/' in s:
        num, den = s.split('/')
        return float(num) / float(den)
    return float(s)


# Read dns.in
# -------------------
with open('dns.in') as f:
    values = {}
    for _ in range(3):  # first three lines: ny nx nz / alfa0 beta0 / ymin ymax a
        line = f.readline()
        for name, val in re.findall(r'(\w+)\s*=\s*([^\s]+)', line):
            values[name] = parse_number(val)

ny = int(values['ny'])
nx = int(values['nx'])
nz = int(values['nz'])
alfa0 = values['alfa0']
beta0 = values['beta0']
ymin, ymax, a = values['ymin'], values['ymax'], values['a']

nxc = 3 * (nx // 2) - 1
while not fftfit(nxc):
    nxc += 1
nxc = 2 * nxc
nzc = 3 * nz - 1
while not fftfit(nzc):
    nzc += 1

# Read parameters in gkedata.cpl
# --------------------
with open('../gkedata.cpl') as f:
    text = f.read()
uLx1, uLx2 = (parse_number(v) for v in
              re.search(r'uLx1\s*=\s*([^;]+);\s*uLx2\s*=\s*([^;]+);', text).groups())
uLz1, uLz2 = (parse_number(v) for v in
              re.search(r'uLz1\s*=\s*([^;]+);\s*uLz2\s*=\s*([^;]+);', text).groups())

# Define grid
# ---------------------
x = np.linspace(0, 2 * np.pi / alfa0, nxc)
y = np.tanh(a * (2 * np.arange(-1, ny + 2) / ny - 1)) / np.tanh(a) + 1
z = np.linspace(0, 2 * np.pi / beta0, nzc)

L_x = 2 * np.pi / alfa0
L_z = 2 * np.pi / beta0
dz = L_z / nzc
dx = L_x / nxc


# Define indices
# (this is relevant for the undersampling)
# ----------------------
def undersampled_indices(nc, d, uL1, uL2):
    im = []
    i = 0
    while i < nc / 2:
        im.append(i)
        i += 1 if i * d <= uL1 else (4 if i * d <= uL2 else 8)
    if im[-1] < nc / 2:
        im.append(nc // 2)
    m = len(im)
    for k in range(1, m - 1):
        im.append((nc - im[m - 1 - k]) % nc)
    return np.array(im, dtype=int)


imx = undersampled_indices(nxc, dx, uLx1, uLx2)
imz = undersampled_indices(nzc, dz, uLz1, uLz2)
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
IZ = 0
with open('./gke.bin', 'rb') as f:
    for iy in range(-1, ny // 2 + 1):
        IY = iy + 1
        f.seek(8 * (6 * mz * mx * startpos[IY] + 6 * mz * IX + 6 * IZ))
        gkei[:, :, IY] = np.fromfile(f, dtype=np.float64, count=6 * mz).reshape(mz, 6).T

# Plot a term of the GKE
# ------------------------
k = 6  # 1: phiRx, 2: phiRy, 3: phiRz, 4: phiC, 5: <duidui>, 6: xi
labels = [r'$\phi_{r_x}$', r'$\phi_{r_y}$', r'$\phi_{r_z}$', r'$\phi_C$',
          r'$\langle\delta u_i \delta u_i\rangle$', r'$\xi$']

fig, ax = plt.subplots()
pc = ax.pcolormesh(z[imz], y[1:ny // 2 + 2], gkei[k - 1, :, 1:].T, shading='gouraud')
ax.contour(z[imz], y[1:ny // 2 + 2], gkei[k - 1, :, 1:].T, levels=[0],
           colors='k', linestyles='--')
ax.set_xlabel(r'$r_z$')
ax.set_ylabel(r'$Y$')
ax.set_title(labels[k - 1])
fig.colorbar(pc, ax=ax)

plt.show()
