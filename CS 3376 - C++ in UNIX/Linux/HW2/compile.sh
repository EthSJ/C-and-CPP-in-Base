#!/bin/bash

#Gen. use compile and run code

TEMPDIR=/scratch; export TMPDIR

#state HW1 compiled
#g++ -c HW2.cc

#linking
#g++ -o HW2.exe HW2.o
g++ -I ~/Linux/HW2/include HW2.cc -o HW2.exe

#remove old objects
rm -f HW2.o

#run change args here
./HW2.exe -u input.txt

#remove
rm -f HW2.exe 
