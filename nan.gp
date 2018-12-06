reset
set xlabel 'numerical distribution'
set ylabel 'time(nsec)'
set title 'Performance Comparsion involving NaN Float'
set term png enhanced font 'Verdana,10'
set output 'NAN.png'

plot [:][10:100]'special_plot_data.txt' using 1 with points title 'normalized',\
'special_plot_data.txt' using 2 with points title 'denormalized'