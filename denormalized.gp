reset
set xlabel 'numerical distribution'
set ylabel 'time(nsec)'
set title 'Performance Comparsion in Denormalized Float'
set term png enhanced font 'Verdana,10'
set output 'denormalized.png'

plot [:][10:70]'fixed_plot_data.txt' using 1 with points title 'fixed-point',\
'float_plot_data.txt' using 1 with points title 'float-point'
