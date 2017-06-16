#!/bin/bash

FILENAME=../coculture.dat
echo Plotting frame $INST

if [ "$#" -ne 3 ]; then
    OUTPUT=$2
else
    OUTPUT="coculture.jpg"
fi

gnuplot -e "inst=$1" -e "filename='$FILENAME'" -e "outfile='$OUTPUT'" plot.gp
