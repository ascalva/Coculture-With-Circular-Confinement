#!/bin/bash

FILENAME=../coculture.dat
OUTFILE=co
EXT=.jpg
FRAMES=0

while [ $FRAMES -le 5000 ]; do
    gnuplot -e "inst=$FRAMES" -e "filename='$FILENAME'" -e "outfile='$OUTFILE$FRAMES$EXT'" plot.gp
    echo Plotting frame $INST in $OUTFILE$FRAMES$EXT
    FRAMES=$((FRAMES+100))
done

mkdir out
mv ./*.jpg ./out/
open ./out/*.jpg
