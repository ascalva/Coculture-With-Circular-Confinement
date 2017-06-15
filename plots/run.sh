#!/bin/bash

INST=0
FILENAME=../coculture.dat
echo Plotting frame $INST

gnuplot -e "inst=$INST" -e "filename='$FILENAME'" plot.gp

open coculture.jpg
