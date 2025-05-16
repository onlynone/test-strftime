CC ?= cc
OS ?= $(shell uname -s)
EXPECTED_OUTPUT ?= t/expected_output-$(OS).txt

PROG=s$(EXT)


$(PROG): s.c
	$(CC) -o $@ $<

t/actual_output.txt: $(PROG)
	./$< > $@

test: t/actual_output.txt
	diff -u $(EXPECTED_OUTPUT) $<

clean:
	rm -f $(PROG) t/actual_output.txt
