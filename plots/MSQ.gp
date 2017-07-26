#
# filename: MSQ.gp
#
# @author: Alberto Serrano
#
set term wxt #must disable on lenovo laptop
#set terminal postscript enhanced
#set terminal postscript eps enhanced 

set encoding utf8
set autoscale
set logscale xy
set format xy "10^{%L}"
unset label
set xtic auto
set ytic auto
set key top left

set title "Mean Squared Displacements"
set xlabel "t (hr)"
set ylabel "msd (µm^2)"

g(x) = a*x**2
fit [0.9:3] g(x) "../meanSqrtDisp.dat" using 1:2 via a
g = sprintf("g = %.5f x^2", a)
#errors = sprintf("Delta_a = %.5f", a_err)

f(x) = a*x
fit [0.001:10] f(x) "../meanSqrtDisp.dat" using 1:2 via a
t = sprintf("f = %.5f x", a)
errors = sprintf("Delta_a = %.5f", a_err)

save var 'fit_params'


# set xr [-10^(-2):10^2]
#set xr [0.01:100]
#set yr [0.01:100] #was 12
set term png
set output "MSQ.png"

plot "../meanSqrtDisp.dat" using 1:2 lc rgb "green" title "Healthy", \
     "../meanSqrtDisp.dat" using 1:3 lc rgb "red" title "Cancer", \
     f(x) title t, \
     g(x) title g, \
     81.0 w l
     #(0.4*x)**2 w l lt -1
