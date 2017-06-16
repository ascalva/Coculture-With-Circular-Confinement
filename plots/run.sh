#!/bin/bash
#
# filename: run.sh
#
# @author: Alberto Serrano
#
# purpose: Simple shell script to assist with Gnuplot plots and convert
#          them into a gif

FILENAME=../coculture.dat
OUTFILE=co
EXT=.jpg
DIRECTORY=./out
FRAMES=1000

# Function to open gif file
ql () { qlmanage -p "$*" >& /dev/null; }

while [ $FRAMES -le 9900 ]; do
    gnuplot -e "inst=$FRAMES" -e "filename='$FILENAME'" -e "outfile='$OUTFILE$FRAMES$EXT'" plot.gp
    echo Plotting frame $INST in $OUTFILE$FRAMES$EXT
    FRAMES=$((FRAMES+100))
done

# Check if the specified directory exists
if [ -d "$DIRECTORY" ]; then
    rm -r $DIRECTORY/*
else
    mkdir $DIRECTORY
fi

mv ./*.jpg $DIRECTORY

# Convert images into a gif (requires ImageMagick)
convert -delay 10 -loop 10 $DIRECTORY/*.jpg ./coculture.gif

# Open gif
ql ./coculture.gif
