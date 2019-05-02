#!/bin/bash

#compile  script for first homework

TEMPDIR=/scratch; export TMPDIR
echo Setting TEMPDIR environment var to /scratch

#state HW1 compiled
g++ -c HW1.cc
echo Compiling HW1.cc

#state HW1_P2 compiled
g++ -c HW1_P2.cc
echo Compiling HW1_P2.cc

#linking
echo Linking files to create HW1 exe
g++ -o HW1.exe HW1.o HW1_P2.o
echo Fini!
