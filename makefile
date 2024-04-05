cc = tcc
exe = todo

.PHONY: clean

todo: todo.c
	$(cc) todo.c -o $(exe) -fsanitize=address

clean:
	rm -f $(exe)
