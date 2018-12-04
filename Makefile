
EXEC:=gen_input
TESTBENCH:=fixed_testbench float_testbench
TEST_SCRIPT:=./testbench.sh
CC:=gcc
PLOT_SRC:=normalized.gp
PLOT_PROG:=gnuplot

ALL: $(EXEC) $(TESTBENCH)

% : %.c
	$(CC) $< -o $@

plot : $(PLOT_SRC)
	$(TEST_SCRIPT)
	$(PLOT_PROG) $<

.PHONY : ALL plot clean

clean :
	rm $(EXEC) $(TESTBENCH)