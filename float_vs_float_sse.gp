reset
set xlabel 'numerical distribution'
set ylabel 'time(nsec)'
set title 'Performance Comparsion in fixed point and fix point with SSE'
set term png enhanced font 'Verdana,10'
set output 'fixed_vs_fixed_SSE.png'

plot [:][10:200]'float_plot_data_without_sse.txt' using 1 with points title 'float-point without SSE',\
'float_plot_data_sse.txt' using 1 with points title 'float-point with SSE'