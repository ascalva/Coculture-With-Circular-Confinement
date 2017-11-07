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

# Convert images into a movie (ffmpeg)
# Or convert to gif (ImageMagick)
echo Converting images into a gif...
ffmpeg -start_number 1000 -i 'co%4d.png' -c:v libx264 -pix_fmt yuv420p out.mp4
#convert -delay 6 -loop 0 co*.png ./coculture.gif

# Check if the specified directory exists
if [ -d "$DIRECTORY" ]; then
    rm -r $DIRECTORY/*
else
    mkdir $DIRECTORY
fi

mv ./co*.png $DIRECTORY


# Open gif
#ql ./coculture.gif
ql ./out.mp4
