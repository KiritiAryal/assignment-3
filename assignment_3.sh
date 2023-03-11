#!/bin/bash -

#=====================================================================
#title        : assignment_3.sh
#description  : This is a script that decrypts a file and then transforms it using a key integer
#author       : Kiriti Aryal
#date         : 02/26/2023
#version      : 1.1
#usage        : bash assignment_3.sh
#notes        : This script is presented within a zip file
#bash_version : 4.2.46(2)-release
#=====================================================================

#Loaded gnu module for running of cpp as well as c programs
module load gnu/5.4.0
touch a3_results.txt
echo Kiriti Aryal > a3_results.txt 
echo R11722758 >> a3_results.txt
cd code/decrypt

#Storing the decrypted key in a variable
var=./decrypt /lustre/work/errees/courses/cs4352/assignment3/input/encrypted.txt
../transform/transform 11722758

#Extracting the line number stored in var
sed -n "$var{p;q}" /lustre/work/errees/courses/cs4352/assignment3/input/.hidden_file >> ../../a3_results.txt 
