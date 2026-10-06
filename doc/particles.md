# Particle effects in the GKE: open questions and plan

Status (October 2026): the GKE is computed over pairs of fluid points, with
points inside the particles excluded and every average renormalized by the
number of accumulated points or pairs. The budget does not yet contain any term
describing the action of the particles on the fluid. This note collects what is
known, the questions to be clarified with the data provider and the plan to
close the budget.

## Facts established on the xinju dataset (snapshot 20000)

- The stored velocity field is divergence-free to round-off (about 1e-14)
  everywhere, including inside the particles: the immersed-boundary (IB)
  formulation extends the momentum equation to the whole domain.
- The IB force `fib` is not confined to the solid. Its rms is about 1.5 just
  outside the particle surface (0 < levelset < 0.03) and still about 0.09 well
  inside the fluid (levelset > 0.1), i.e. the force is spread over a layer
  around the surface by the IB kernel. The current fluid-phase statistics hence
  include force-carrying points.
- The whole-domain mean wall-normal velocity vanishes (3e-18), as required by
  continuity between the walls, but the fluid-phase mean does not (up to 2e-3);
  the code accounts for a mean V(y) since October 2026.
- The conversion script `convert_h5.py` supplied with the dataset reshapes the
  rank files with the variable as fastest index, whereas the variables are
  stored as consecutive blocks; its HDF5 output is therefore scrambled (the
  correct reshape is `(n1m, n2drm, n3dcm, nvar), order="F"`). The GKE code reads
  the raw rank files and is not affected.

## Questions for the data provider

1. Exact discrete momentum equation: is `fib` an acceleration added to the
   right-hand side (sign, units, time level within the time step)?
2. Is the driving mean pressure gradient (fixed flow rate) contained in `p`, or
   applied as a separate uniform body force? (Uniform forces cancel in the
   velocity increments, so either is fine, but it must be known.)
3. Width of the IB force-spreading kernel, and whether the interior of the
   particles is forced to the rigid-body motion.
4. For the planned falling-particle cases: direction of gravity, density ratio,
   and how the particle weight is balanced in the fluid (e.g. by a mean
   pressure gradient).
5. Are the forcing terms `fturb` always zero in the channel cases?

## Plan

### Phase 1: whole-domain GKE with the IB force (closed by construction)

Since the momentum equation with `fib` holds at every grid point, the GKE of
the whole-domain field (no masking) is exact once the force term is added:
the increment equation gains `d f_i`, and the source term gains
`+2 <du_i df_i>`, the scale-by-scale energy exchange between particles and
fluid. The single-point budgets gain `<u_i' f_j'> + <u_j' f_i'>`.

- `dataset.cpl`: read `fib` (variables 7 to 9), interpolated to the cell
  centres like the velocity.
- step 2: one more pair sum `SUM du_i df_i` (4 more correlation terms in
  `step2_gke.cpl`); step 1: one more statistic; a new field of `GKETERMS`
  (changes the layout of `gke.bin`).
- `gke.in`: switch `mask = levelset | none`.
- Validation: a post-processing script evaluating every term, including the
  divergence of the fluxes, and the residual of the budget; first on the
  single-point energy budget (cheap, tests definition and sign of the force),
  then on the GKE. The residual must vanish up to discretization and
  statistical errors.

### Phase 2: fluid-phase GKE (the current statistics, completed)

Averaging over fluid pairs only multiplies the exact pair equation by the pair
indicator chi = m(x) m(x+r), which does not commute with the derivatives in r,
Y and t. This produces terms concentrated on the particle surfaces: with
no-slip the time-derivative and advective surface terms cancel, while the
pressure and viscous fluxes through the surfaces remain, together with the IB
force in the forcing layer. Furthermore:

- renormalizing by the pair count N(r,Y), which varies strongly with Y (solid
  fraction from about 1% at the walls to 50% at the centre), adds terms in
  grad N; the budget should be formulated for the unnormalized, phase-weighted
  sums <chi q> and divided by N only for presentation;
- the conditional means of the increments over fluid pairs, <du_i> and <dp>,
  do not vanish; terms proportional to them (e.g. `2 <du_i> dR_i` with the
  mean-momentum terms R_i, and `-2 <dp> d(dV/dy)`) are absent from the
  whole-domain budget and are currently neglected;
- the mean kinetic energy budget of step 1 still assumes V = 0.

The surface terms can be obtained without surface integrals: split all pairs
into the classes fluid-fluid, fluid-solid, solid-fluid and solid-solid (masks
m and 1-m, handled by the same FFT machinery). The four classes add up to the
closed Phase 1 budget, and the residual of the fluid-fluid class is exactly
the exchange through the particle surfaces (given statistical stationarity,
i.e. enough snapshots).
