cc = tcc
exe = todo

todo: todo.c
	$(cc) todo.c -o $(exe)
