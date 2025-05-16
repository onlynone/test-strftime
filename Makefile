CC ?= cc
OS ?= $(shell uname -s)
EXPECTED_OUTPUT ?= t/expected_output-$(OS).txt

PROG=s$(EXT)


$(PROG): s.c
	$(CC) -o $@ $<

t/actual_output.txt: $(PROG)
	./$(PROG) > $@

test: t/actual_output.txt
	@echo $(OS)
	uname -s
	diff -u $(EXPECTED_OUTPUT) t/actual_output.txt

clean:
	rm -f $(PROG) t/actual_output.txt
