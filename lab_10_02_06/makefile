CFLAGS := -std=gnu99 -Wall -Werror -Wpedantic -ggdb

app.exe : out/main.o out/input.o out/list_operations.o out/matrix_operations.o
	gcc -o $@ $^

unit_tests.exe : out/check_main.o out/matrix_operations.o out/list_operations.o out/check_add.o out/check_mul.o out/check_lin.o
	gcc -o $@ $^


out/main.o : src/main.c
	gcc $(CFLAGS) -c -o $@ $<

out/input.o : src/input.c
	gcc $(CFLAGS) -c -o $@ $<

out/list_operations.o : src/list_operations.c
	gcc $(CFLAGS) -c -o $@ $<

out/matrix_operations.o : src/matrix_operations.c
	gcc $(CFLAGS) -c -o $@ $<


out/check_main.o : unit_tests/check_main.c
	gcc $(CFLAGS) -c -o $@ $<

out/check_add.o : unit_tests/check_add.c
	gcc $(CFLAGS) -c -o $@ $<

out/check_mul.o : unit_tests/check_mul.c
	gcc $(CFLAGS) -c -o $@ $<

out/check_lin.o : unit_tests/check_lin.c
	gcc $(CFLAGS) -c -o $@ $<

.PHONY : clean
clean :
	rm out/*.o *.exe
