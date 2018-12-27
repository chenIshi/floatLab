ANALYSIS=compare
EXEC:=gen_input
TESTBENCH:=fixed_testbench float_testbench special_testbench fixed_testbench_sse fixed_testbench_without_sse
TEST_SCRIPT:=./testbench.sh
CC:=gcc
PLOT_NORMAL:=normalized.gp
PLOT_DENORMAL:=denormalized.gp
PLOT_D2N:=d2n.gp
PLOT_INF:=inf.gp
PLOT_NAN:=nan.gp
PLOT_FIX_SSE:=fixed_vs_fixed_sse.gp
PLOT_PROG:=gnuplot

PLOT_PIC:= normalized.png denormalized.png D2N.png NAN.png INF.png fixed_vs_fixed_sse.png float_vs_float_sse.png
PLOT_DATA:= fixed_plot_data.txt float_plot_data.txt special_plot_data.txt fixed_plot_data_sse.txt fixed_plot_data_without_sse.txt \
float_plot_data_sse.txt float_plot_data_without_sse.txt

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

infplot : $(PLOT_INF)
	$(PLOT_PROG) $<

nanplot : $(PLOT_NAN)
	$(PLOT_PROG) $<

fixedSSEplot : $(PLOT_FIX_SSE)
	$(PLOT_PROG) $<

check : $(ANALYSIS)
	./$<

.PHONY : ALL dplot nplot d2nplot clean check

clean :
ifneq (, $(wildcard $(EXEC)))
	rm $(EXEC)
endif
ifneq (, $(wildcard $(TESTBENCH)))
	rm $(TESTBENCH)
endif
ifneq (, $(wildcard $(ANALYSIS)))
	rm $(ANALYSIS)
endif
ifneq (, $(wildcard $(PLOT_PIC)))
	rm $(PLOT_PIC)
endif
ifneq (, $(wildcard $(PLOT_DATA)))
	rm $(PLOT_DATA)
endif
