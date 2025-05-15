s: s.c
	cc -o s s.c

test: s
	./s > t/actual_output.txt
	diff -u t/expected_output.txt t/actual_output.txt
