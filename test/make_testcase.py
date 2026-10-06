#!/usr/bin/env python3
"""Write a small synthetic test case in the format of the xinju dataset.

The fields are smooth random fields (not a solution of the Navier-Stokes
equations) and the particles are spheres, which is enough to exercise the
input, the masking and the agreement between the two implementations of
step 2. Usage: make_testcase.py <case directory>
"""

import sys
from pathlib import Path

import numpy as np

n1m, n2m, n3m = 48, 32, 24          # grid
proc_r, proc_c = 4, 2               # MPI decomposition in y and z
lx, ly, lz = 3.0, 2.0, 1.5          # box
snapshots = (1, 2)

rng = np.random.default_rng(1)


def smooth_field(nmodes=6):
    """Random combination of a few low Fourier modes on the cell grid."""
    x = (np.arange(n1m) + 0.5) / n1m
    y = (np.arange(n2m) + 0.5) / n2m
    z = (np.arange(n3m) + 0.5) / n3m
    X, Y, Z = np.meshgrid(x, y, z, indexing="ij")
    f = np.zeros_like(X)
    for _ in range(nmodes):
        kx, kz = rng.integers(0, 4, 2)
        ky = rng.uniform(0.5, 3)
        f += rng.normal() * np.cos(2*np.pi*(kx*X + kz*Z) + np.pi*ky*Y + rng.uniform(0, 2*np.pi))
    return f


def levelset(nparticles=5, radius=0.35):
    """Signed distance to the nearest of a few spherical particles."""
    x = (np.arange(n1m) + 0.5) * lx / n1m
    y = (np.arange(n2m) + 0.5) * ly / n2m
    z = (np.arange(n3m) + 0.5) * lz / n3m
    X, Y, Z = np.meshgrid(x, y, z, indexing="ij")
    ls = np.full(X.shape, np.inf)
    for _ in range(nparticles):
        c = rng.uniform((0, radius, 0), (lx, ly - radius, lz))
        # periodic distance in x and z
        dX = (X - c[0] + lx/2) % lx - lx/2
        dZ = (Z - c[2] + lz/2) % lz - lz/2
        ls = np.minimum(ls, np.sqrt(dX**2 + (Y - c[1])**2 + dZ**2) - radius)
    return np.minimum(ls, 0.3)


def write_snapshot(case, n):
    y = (np.arange(n2m) + 0.5) / n2m
    wall = (4 * y * (1 - y))[None, :, None]
    u = wall * (1.5 + 0.3 * smooth_field())
    v = wall * 0.2 * smooth_field()
    w = wall * 0.2 * smooth_field()
    v[:, 0, :] = 0                                  # v at the lower wall
    p = 0.1 * smooth_field()
    ls = levelset()
    zero = np.zeros_like(u)
    variables = [u, v, w, zero, zero, zero, zero, zero, zero, p, ls]
    folder = case / f"fluid{n:07d}"
    folder.mkdir(parents=True, exist_ok=True)
    n2drm, n3dcm = n2m // proc_r, n3m // proc_c
    for rank in range(proc_r * proc_c):
        j0, k0 = (rank // proc_c) * n2drm, (rank % proc_c) * n3dcm
        block = [f[:, j0:j0+n2drm, k0:k0+n3dcm].ravel(order="F") for f in variables]
        np.concatenate(block).astype("<f8").tofile(folder / f"flowfield{rank:05d}.field")


def main():
    case = Path(sys.argv[1])
    case.mkdir(parents=True, exist_ok=True)
    (case / "flow_field.in").write_text(f"""&ini_input
proc_r            =  {proc_r},
proc_c            =  {proc_c},
num_grid          =  {n1m},{n2m},{n3m}
/
&fluid_parameters
re            =  500.0,
domainbound   =  0.0,0.0,0.0
domainlength  =  {lx},{ly},{lz},
bcond         =  0,1,0,
/
""")
    (case / "gke.in").write_text(f"""&gke
nfmin = {snapshots[0]}
nfmax = {snapshots[-1]}
dn    = 1
uLx   = 0.4, 0.8
uLz   = 0.2, 0.5
/
""")
    for n in snapshots:
        write_snapshot(case, n)


if __name__ == "__main__":
    main()
