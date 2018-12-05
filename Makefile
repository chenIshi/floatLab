ANALYSIS=compare
EXEC:=gen_input
TESTBENCH:=fixed_testbench float_testbench
TEST_SCRIPT:=./testbench.sh
CC:=gcc
PLOT_NORMAL:=normalized.gp
PLOT_DENORMAL:=denormalized.gp
PLOT_D2N:=d2n.gp
PLOT_PROG:=gnuplot

ALL: $(EXEC) $(TESTBENCH)
	./$(EXEC)
	$(TEST_SCRIPT)

% : %.c
	$(CC) $< -o $@

nplot : $(PLOT_NORMAL)
	$(PLOT_PROG) $<

dplot : $(PLOT_DENORMAL)
	$(PLOT_PROG) $<

d2nplot : $(PLOT_D2N)
	$(PLOT_PROG) $<

check : $(ANALYSIS)
	./$<

.PHONY : ALL dplot nplot d2nplot clean check

clean :
	rm $(EXEC) $(TESTBENCH) $(ANALYSIS)
