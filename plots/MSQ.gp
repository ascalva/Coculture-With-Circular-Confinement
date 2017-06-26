
set term wxt #must disable on lenovo laptop

set   autoscale                        # scale axes automatically
set log                              # remove any log-scaling
unset label                            # remove any previous labels
set xtic auto                          # set xtics automatically
set ytic auto                          # set ytics automatically
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
