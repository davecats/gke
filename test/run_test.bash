#!/bin/bash
# Regression test: runs the whole pipeline on a small synthetic case in the
# format of the xinju dataset with both implementations of step 2 and checks
# that they agree up to round-off. Requires the compiled programs
# (../compile.bash) and python3 with numpy.
set -e
DIR=$(cd "$(dirname "$0")/.." && pwd)
CASE=${1:-$(mktemp -d)}
export OMP_WAIT_POLICY=${OMP_WAIT_POLICY:-passive}

python3 "$DIR/test/make_testcase.py" "$CASE"
cd "$CASE"
"$DIR/step1/step1_singlepoints" > log_step1
"$DIR/step2/step2_gke" > log_step2
"$DIR/step3/step3_gke" > log_step3
mv gke.bin gke_fft.bin
"$DIR/step2/step2_gke_direct" > log_step2_direct
"$DIR/step3/step3_gke" > log_step3_direct
mv gke.bin gke_direct.bin

python3 - <<'PY'
import numpy as np
a = np.fromfile("gke_fft.bin").reshape(-1, 6)
b = np.fromfile("gke_direct.bin").reshape(-1, 6)
err = max(abs(a[:, k] - b[:, k]).max() / abs(b[:, k]).max() for k in range(6))
print(f"step2_gke vs step2_gke_direct: max relative difference {err:.1e}")
assert err < 1e-12, "the two implementations of step 2 disagree"
PY
echo "Test passed (case directory: $CASE)"
