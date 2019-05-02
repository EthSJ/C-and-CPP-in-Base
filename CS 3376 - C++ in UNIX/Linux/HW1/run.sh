#!/bin/bash

#Runs homework 1

#running with 0 args
echo Running 'HW1' with 0 args:
./HW1.exe 1>>stdout.log 2>>stderr.log
echo   stdout appended to stdout.log
echo   stderr appended to stderr.log
echo  

#running with 1 args
echo Running 'HW1' with 1 args:
./HW1.exe a 1>>stdout.log 2>>stderr.log
echo   stdout appended to stdout.log
echo   stderr appended to stderr.log
echo 

#running with 5 args
echo Running 'HW1' with 5 args:
./HW1.exe a b c d e 1>>stdout.log 2>>stderr.log
echo   stdout appended to stdout.log
echo   stderr appended to stderr.log
echo  
