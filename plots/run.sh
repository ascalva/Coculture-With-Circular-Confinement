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
EXT=.png
DIRECTORY=./out

FRAMES=0
CURR=1000
MAX=500

# Function to open gif file
ql () { qlmanage -p "$*" >& /dev/null; }

# Optional program argument replaces the default MAX value
if [ "$#" -eq 1 ]; then
    MAX=$(($(($1-1))*1))
fi

# Execute Gnuplot scripts MAX/100 number of times
if [ -f ../meanSqrtDisp.dat ]; then
    gnuplot MSQ.gp
fi

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

mv ./co*.png $DIRECTORY

# Convert images into a gif (requires ImageMagick)
echo Converting images into a gif...
convert -delay 6 -loop 0 $DIRECTORY/co*.png ./coculture.gif
#ffmpeg -start_number 837 -i '%3d_1.png' -c:v libx264 -pix_fmt yuv420p out.mp4

# Open gif
ql ./coculture.gif
