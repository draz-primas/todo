cc = tcc
exe = todo
flags = -g -fsanitize=address

.PHONY: clean

todo: *.c
	$(cc) *.c -o $(exe) $(flags)

clean:
	rm -f $(exe)
