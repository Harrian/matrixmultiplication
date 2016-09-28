#!/bin/bash

gcc -fopenmp msOpenMP.c -o omp > /dev/null
gcc -lpthread msPthread.c -o pth > /dev/null
gcc msSequental.c -o seq > /dev/null

echo "Sequental version with 1000 elements (./seq -s 1000):";
time ./seq -s 1000

echo "pthread version with 1000 elements and 2 threads (./pth -s 1000):";
time ./pth -s 1000

echo "pthread version with 1000 elements and 8 threads (./pth -s 1000 -t 8):";
time ./pth -s 1000 -t 8

echo "OpenMP version with 1000 elements and 2 threads (./omp -s 1000)";
time ./omp -s 1000

echo "OpenMP version with 1000 elements and 8 threads (./omp -s 1000 -t 8):";
time ./omp -s 1000 -t 8
