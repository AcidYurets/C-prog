CFLAGS := -std=gnu99 -Wall -Werror -Wpedantic -ggdb

app.exe : out/main.o out/input.o out/list_operations.o out/cmp.o
	gcc -o $@ $^

unit_tests.exe : out/input.o out/list_operations.o out/cmp.o out/check_main.o out/check_find.o out/check_pop.o out/check_append.o out/check_sort.o
	gcc -o $@ $^


out/main.o : src/main.c
	gcc $(CFLAGS) -c -o $@ $<

out/input.o : src/input.c
	gcc $(CFLAGS) -c -o $@ $<

out/list_operations.o : src/list_operations.c
	gcc $(CFLAGS) -c -o $@ $<

out/cmp.o : src/cmp.c
	gcc $(CFLAGS) -c -o $@ $<

out/check_main.o : unit_tests/check_main.c
	gcc $(CFLAGS) -c -o $@ $<

out/check_find.o : unit_tests/check_find.c
	gcc $(CFLAGS) -c -o $@ $<

out/check_pop.o : unit_tests/check_pop.c
	gcc $(CFLAGS) -c -o $@ $<

out/check_append.o : unit_tests/check_append.c
	gcc $(CFLAGS) -c -o $@ $<

out/check_sort.o : unit_tests/check_sort.c
	gcc $(CFLAGS) -c -o $@ $<

.PHONY : clean
clean :
	rm out/*.o *.exe
