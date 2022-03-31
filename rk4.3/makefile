CFLAGS := -std=gnu99 -Wall -Werror -Wpedantic -ggdb

app.exe : main.o input.o list_operations.o cmp.o
	gcc -o $@ $^


main.o : main.c
	gcc $(CFLAGS) -c -o $@ $<

input.o : input.c
	gcc $(CFLAGS) -c -o $@ $<

list_operations.o : list_operations.c
	gcc $(CFLAGS) -c -o $@ $<

cmp.o : cmp.c
	gcc $(CFLAGS) -c -o $@ $<


.PHONY : clean
clean :
	rm *.o *.exe
