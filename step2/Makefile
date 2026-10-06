# Local Makefile picked up by "cpl make" instead of the default one of the
# CPL installation: it selects the C compiler and its flags, so that the
# OpenACC GPU build of step2_gke_direct.cpl can use the NVIDIA HPC
# compiler, e.g. (after loading the NVIDIA HPC SDK environment)
#
#   GPU=1 cpl make step2_gke_direct.cpl -acc=gpu
#
# while the default remains gcc with the standard CPL flags, e.g.
#
#   cpl make step2_gke_direct.cpl -fopenmp
#
BASEFLAGS:=$(CFLAGS)
ifeq ($(GPU),1)
  CC:=nvc
  LD:=nvc
  CFLAGS:= -O3 -fPIC --diag_suppress declared_but_not_referenced --diag_suppress set_but_not_used $(BASEFLAGS)
else
  CC:=gcc
  LD:=gcc
  CFLAGS:= -z execstack -O3 -Wno-free-nonheap-object -fPIC $(BASEFLAGS)
endif
export CC LD
