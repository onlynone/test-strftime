OS ?= $(shell uname)
CC ?= cc

PROG=s$(EXT)

$(PROG): s.c
	$(CC) -o $@ $^

t/actual_output-$(OS).txt: $(PROG)
	./$< > $@

test: t/actual_output-$(OS).txt
	diff -u t/expected_output-$(OS).txt $<

clean:
	rm -f $(PROG) t/actual_output-$(OS).txt
