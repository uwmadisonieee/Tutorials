# GPGPU and Compute

The aim of this workshop is to get you up and going with GPGPU and Compute programming

**NOTE**: All of the following is assuming running on a Debian based Linux machine. Results may vary otherwise.

## Need a Linux computer to work on?

- Checkout [how to access UW-Madison Linux Machines](/School%20Linux%20Machines)
- Need to learn how to use it? Checkout [our Linux 101 workshop](/Linux%20101)

# Outline
- [OpenMP](#openmp)
- [OpenCL](#opencl)
- [CUDA](#cuda)

## OpenMP

OpenMP is a great directive base addition to turn code parallel

### Hello World

- First create `helloMP.c` in a text editor of choice
- Copy in the following

```
#include <stdio.h>

int main(void)
{
    #pragma omp parallel
    printf("Hello, world.\n");
    return 0;
}
```

- Compile with `gcc -fopenmp helloMP.c -o helloMP`
- run `./helloMP` and it will print `Hello, world.` with each core on CPU

### Threads have overhead

It is **Very Important** you realize that there is a time and place to parallel your code. Computers have been designed to run well on a single core. The rule of thumb is "If it is currently not slow then don't try to over optimize it".

Here is a good point to showcase. Put the following code in `overhead.c`

```
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long ARRAY_SIZE = 10000000; // 10 Million floats

clock_t t_start, t_end;
double t_time;

int main(int argc, char **argv)
{
  float* a = (float*)malloc(sizeof(float) * ARRAY_SIZE);
  float* b = (float*)malloc(sizeof(float) * ARRAY_SIZE);
  long i;

  ////////////////
  // Normal Run //
  ////////////////
  t_start = clock();

  for (i = 0; i < ARRAY_SIZE; i += sizeof(float)) {
    *(a + i) = 2 * i;
  }

  t_end = clock();
  t_time = (double)(t_end - t_start) / CLOCKS_PER_SEC;
  printf("Normal speed: %f seconds\n", t_time);

  t_start = clock();

  ////////////////
  // OpenMP run //
  ////////////////
  #pragma omp parallel for
  for (i = 0; i < ARRAY_SIZE; i += sizeof(float)) {
    *(b + i) = 2 * i;
  }

  t_end = clock();
  t_time = (double)(t_end - t_start) / CLOCKS_PER_SEC;
  printf("OpenMP speed: %f seconds\n", t_time);

  free(a);
  free(b);

  return 0;
}
```

If you run it (same way as `helloMP`) you will probably notice the OpenMP is slower... so what gives!?!

The idea of this program is showing that something like `2 * i` is not a CPU intensive computation and the GCC compiler is smart enough to optimize it. This is also showing that it does take some time to run.

### Example of OpenMP being useful

- Lets say you want to accuratly calculate Pi and decide to use the [Monte Carlo](http://mathfaculty.fullerton.edu/mathews/n2003/montecarlopimod.html) method. Open a file called `monteCarlo.cpp` and copy [this code](examples/monteCarlo.cpp) into it.
  - Can also run `wget https://raw.githubusercontent.com/uwmadisonieee/Tutorials/master/GPGPU%20and%20Compute/examples/montoCarlo.cpp` if on machine
- Now compile it with `g++ -fopenmp -std=c++11 monteCarlo.cpp -o monteCarlo`
- You should get a result such as

```
Sequential version:
number of samples: 10000000
real Pi: 3.141592653589...
approx.: 3.142054
Time: 3295 millisecons.

Parallel version:
number of samples: 10000000
real Pi: 3.141592653589...
approx.: 3.1425556
Time: 479 millisecons.
```

## OpenCL

**Currently looking into how to get demo to work on school machines**

OpenCL is a great tool to exploit more massive parallelism while still being able to work on many device.

## CUDA

**Currently looking into how to get demo to work on school machines**

