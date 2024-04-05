exe := todo
cc := gcc
flags := -O3
# flags = -g -fsanitize=address

.PHONY: clean install uninstall

$(exe): *.c
	$(cc) *.c -o $(exe) $(flags)

clean:
	rm -f $(exe)

install: todo
	mv $(exe) /usr/local/bin

uninstall:
	rm /usr/local/bin/$(exe)
