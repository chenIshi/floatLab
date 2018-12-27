#!/bin/bash
FLOAT_TESTBENCH="./float_testbench"
FLOAT_PLOT_DATA="./float_plot_data.txt"

FIXED_TESTBENCH="./fixed_testbench"
FIXED_PLOT_DATA="./fixed_plot_data.txt"

FIXED_TESTBENCH_SSE="./fixed_testbench_sse"
FIXED_PLOT_DATA_SSE="./fixed_plot_data_sse.txt"

FIXED_TESTBENCH_WITHOUT_SSE="./fixed_testbench_without_sse"
FIXED_PLOT_DATA_WITHOUT_SSE="./fixed_plot_data_without_sse.txt"

FLOAT_TESTBENCH_GCC_SSE2="./float_with_gcc_sse2"
FLOAT_PLOT_DATA_GCC_SSE2="./float_plot_data_gcc_sse2.txt"

SP_TESTBENCH="./special_testbench"
SP_PLOT_DATA="./special_plot_data.txt"

# clean up plot data
if [ -a $FLOAT_PLOT_DATA ]
then
    rm $FLOAT_PLOT_DATA
fi

if [ -a $FIXED_PLOT_DATA ]
then
    rm $FIXED_PLOT_DATA
fi

if [ -a $SP_PLOT_DATA ]
then
    rm $SP_PLOT_DATA
fi

if [ -a $FIXED_PLOT_DATA_SSE ]
then
    rm $FIXED_PLOT_DATA_SSE
fi

if [ -a $FIXED_PLOT_DATA_WITHOUT_SSE ]
then
    rm $FIXED_PLOT_DATA_WITHOUT_SSE
fi

if [ -a $FLOAT_PLOT_DATA_GCC_SSE2 ]
then
    rm $FLOAT_PLOT_DATA_GCC_SSE2
fi

# testbench
$FLOAT_TESTBENCH >> $FLOAT_PLOT_DATA
$FIXED_TESTBENCH >> $FIXED_PLOT_DATA 
$SP_TESTBENCH >> $SP_PLOT_DATA
$FIXED_TESTBENCH_SSE >> $FIXED_PLOT_DATA_SSE
$FIXED_TESTBENCH_WITHOUT_SSE >> $FIXED_PLOT_DATA_WITHOUT_SSE
$FLOAT_TESTBENCH_GCC_SSE2 >> $FIXED_PLOT_DATA_WITHOUT_SSE
