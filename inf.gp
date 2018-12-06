reset
set xlabel 'numerical distribution'
set ylabel 'time(nsec)'
set title 'Performance Comparsion involving INF Float'
set term png enhanced font 'Verdana,10'
set output 'INF.png'

plot [:][10:100]'special_plot_data.txt' using 3 with points title 'normalized',\
'special_plot_data.txt' using 4 with points title 'denormalized'