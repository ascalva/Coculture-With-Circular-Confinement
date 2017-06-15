#
# filename: plot.gp
#
# @author: Alberto Serrano
#

set term wxt
#set term xterm #on lenovo

# set   autoscale
# unset log
# unset label
# set xtic auto
# set ytic auto
# set key top left

# change plot labels
set title "Cocultures"
set xlabel "something you measured (units go here)"
set ylabel "something else you measured (units go here)"
# set key 0.01,100
# set arrow from 0.0028,250 to 0.003,280

# set view map
# set pm3d at b map
# set dgrid3d 200,200,2
set xr [-20.0:20.0]
set yr [-20.0:20.0]
# set object circle at axis 0,0 size scr 0.1 fc rgb "navy"

set style fill transparent solid 0.5 noborder
set style circle radius 0.5
#plot "coculture.dat" i 0 using 2:3 with circles lc rgb "green"

plot "coculture.dat" i 0 u 2:3 every ::0::72 with circles lc rgb "green", \
     "coculture.dat" i 0 u 2:3 every ::73::144 with circles lc rgb "red"

set term jpeg
set output 'coculture.jpg'
replot
set term wxt