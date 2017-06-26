#
# filename: MSQ.gp
#
# @author: Alberto Serrano
#
set term wxt #must disable on lenovo laptop

set autoscale
set log
unset label
set xtic auto
set ytic auto
set key top left

set title "Mean Squared Displacements"
set xlabel "time (0.1hr = 6min)"
set ylabel "msd ({/Symbol m}m^2)"

# set xr [-10^(-2):10^2]
#set yr [-50:550]

plot "../meanSqrtDisp.dat" using 1:2 lc rgb "green" title 'Healthy', \
     "../meanSqrtDisp.dat" using 1:3 lc rgb "red" title "Cancer"

set term png
set output "MSQ.png"
replot
set term wxt
