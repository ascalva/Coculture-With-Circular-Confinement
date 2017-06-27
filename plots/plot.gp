#
# filename: plot.gp
#
# @author: Alberto Serrano
#

set term wxt
#set terminal postscript enhanced
#set term xterm #on lenovo

#set autoscale
unset log
unset label
unset border
unset xtics
unset ytics

set title "Cocultures"
#set xr [-10.0:20.0]
set xr [-15.0:15.0]
set yr [-10.0:10.0]

set style fill transparent solid 0.7 border lt 3
set style circle radius 0.5

r = 9
set object 1 circle back at 0,0 size r fs empty border 4

if (!exists("filename")) filename='coculture.dat'
if (!exists("inst")) inst = 0

#stats "../meta.dat" every ::::1 using 2 nooutput
#stats "<(sed -n '2p' ../meta.dat)" using 3 nooutput
#cellNum = sprintf("Cell Number: %i", int(STATS_min))
#stats "../meta.dat" every ::::2 using 2 nooutput
#packFrac = sprintf("Packing Fraction: %0.3f", STATS_min)
#stats "../meta.dat" every ::::3 using 2 nooutput
#confRad = sprintf("Confinement Radius: %f", STATS_min)

#set label 1 cellNum at 10,7
#set label 2 packFrac at 10,6
#set label 3 confRad at 10,5

set term png
set output outfile

plot filename i inst u 2:($5 == 0 ? $3 : 1/0) with circles lc rgb "green" title "Healthy Cell", \
     filename i inst u 2:($5 == 1 ? $3 : 1/0) with circles lc rgb "red" title "Cancer Cell" 
