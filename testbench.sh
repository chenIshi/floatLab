#!/bin/bash
FLOAT_TESTBENCH="./float_testbench"
FLOAT_PLOT_DATA="./float_plot_data.txt"

FIXED_TESTBENCH="./fixed_testbench"
FIXED_PLOT_DATA="./fixed_plot_data.txt"

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

# testbench
$FLOAT_TESTBENCH >> $FLOAT_PLOT_DATA
$FIXED_TESTBENCH >> $FIXED_PLOT_DATA 
$SP_TESTBENCH >> $SP_PLOT_DATA
