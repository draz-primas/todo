target := todo
cc := gcc
flags := -O3
# flags = -g -fsanitize=address

.PHONY: clean install uninstall

$(target): *.c
	$(cc) *.c -o $(target) $(flags)

clean:
	rm -f $(target)

install: todo
	mv $(target) /usr/local/bin

uninstall:
	rm /usr/local/bin/$(target)
