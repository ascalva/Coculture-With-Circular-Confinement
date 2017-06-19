#
# filename: plot.gp
#
# @author: Alberto Serrano
#

set term wxt
#set term xterm #on lenovo

#set autoscale
unset log
unset label
unset border
unset xtics
unset ytics

set title "Cocultures"
set xr [-14.0:14.0]
set yr [-10.0:10.0]

set style fill transparent solid 0.5 noborder
set style circle radius 0.5

r = 9
set object 1 circle back at 0,0 size r fs empty border 4

if (!exists("filename")) filename='coculture.dat'
if (!exists("inst")) inst = 0

plot filename i inst u 2:3 every ::0::72 with circles lc rgb "green" title "Healthy Cell", \
     filename i inst u 2:3 every ::73::144 with circles lc rgb "red" title "Cancer Cell"
# pause -1

set term jpeg
set output outfile
replot
set term wxt
