#
# filename: MSQ.gp
#
# @author: Alberto Serrano
#
set term wxt #must disable on lenovo laptop
#set terminal postscript enhanced
#set terminal postscript eps enhanced 

#set autoscale
set logscale xy
unset label
set xtic auto
set ytic auto
set key top left

set title "Mean Squared Displacements"
set xlabel "time (0.1hr = 6min)"
set ylabel "msd ({/Symbol m}m^2)"

#f(x) = a*x+b
g(x) = (a*x**2) + b
fit [0.9:3] g(x) "../meanSqrtDisp.dat" using 1:2 via a, b
g = sprintf("g = %.5f x^2 + %.5f", a, b)
#errors = sprintf("Delta_a = %.5f", a_err)

f(x) = a*x
#f(x) = a*x**2 + b
fit [0.001:10] f(x) "../meanSqrtDisp.dat" using 1:2 via a
t = sprintf("f = %.5f x", a)
errors = sprintf("Delta_a = %.5f", a_err)

save var 'fit_params'


# set xr [-10^(-2):10^2]
set xr [0.01:100]
set yr [0.05:100] #was 12
set term png
set output "MSQ.png"

plot "../meanSqrtDisp.dat" using 1:2 lc rgb "green" title "Healthy", \
     "../meanSqrtDisp.dat" using 1:3 lc rgb "red" title "Cancer", \
     f(x) title t, \
     g(x) title g