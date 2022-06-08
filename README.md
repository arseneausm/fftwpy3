# FFTW Python Implementation

Codebase for my implementation of fftw C extension in python for D| (DPipe), the CLASS telescope data pipeline package

Work on learning how to write C extensions for python. omp is a library for parallelizing C code that is gonna be useful. We need to write connection functions to bridge fftw into Dpipe. A lot of this can be copy-pasted out of Moby2, but we've got edge cases for big data arrays. When we take the fourier transform, it sometimes fails and we don't know why. The way it's currently taken care of in Dpipe is ugly.

[moby2 repo](https://github.com/class-telescope/moby2)
[dpipe repo](https://github.com/class-telescope/dpipe)

## CBLAS Notes

In order to build the CBLAS wrapper, the following command should be run for installation:

```
CFLAGS="-lblas" python3 ./setup.py install
``` 
