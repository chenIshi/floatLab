#!/bin/bash
FLOAT_TESTBENCH="./float_testbench"
FLOAT_PLOT_DATA="./float_plot_data.txt"

FIXED_TESTBENCH="./fixed_testbench"
FIXED_PLOT_DATA="./fixed_plot_data.txt"

DATA_AMOUNT=100000

# clean up plot data
if [ -a $FLOAT_PLOT_DATA ]
then
    rm $FLOAT_PLOT_DATA
fi

if [ -a $FIXED_PLOT_DATA ]
then
    rm $FIXED_PLOT_DATA
fi


# testbench
for i in $(seq 1 $DATA_AMOUNT);
do
    $FLOAT_TESTBENCH >> $FLOAT_PLOT_DATA
    $FIXED_TESTBENCH >> $FIXED_PLOT_DATA 
done