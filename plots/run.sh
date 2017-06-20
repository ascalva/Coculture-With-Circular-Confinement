#!/bin/bash
#
# filename: run.sh
#
# @author: Alberto Serrano
#
# purpose: Simple shell script to assist with Gnuplot plots and convert
#          them into a gif

# Handle names of input/output files
FILENAME=../coculture.dat
OUTFILE=co
EXT=.jpg
DIRECTORY=./out

FRAMES=0
CURR=1000
MAX=1000

# Function to open gif file
ql () { qlmanage -p "$*" >& /dev/null; }

# Optional program argument replaces the default MAX value
if [ "$#" -eq 1 ]; then
    MAX=$(($(($1-1))*1))
fi

# Execute Gnuplot script MAX/100 number of times
while [ $FRAMES -le $MAX ]; do
    gnuplot -e "inst=$FRAMES" -e "filename='$FILENAME'" -e "outfile='$OUTFILE$CURR$EXT'" plot.gp
    echo Plotting frame $FRAMES in $OUTFILE$CURR$EXT
    FRAMES=$((FRAMES+1))
    CURR=$((CURR+1))
done

# Check if the specified directory exists
if [ -d "$DIRECTORY" ]; then
    rm -r $DIRECTORY/*
else
    mkdir $DIRECTORY
fi

mv ./*.jpg $DIRECTORY

# Convert images into a gif (requires ImageMagick)
convert -delay 8 -loop 10 $DIRECTORY/*.jpg ./coculture.gif

# Open gif
ql ./coculture.gif
