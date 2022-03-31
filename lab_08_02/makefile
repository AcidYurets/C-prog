CFLAGS := -std=c99 -Wall -Werror -Wpedantic -ggdb

app.exe : out/main.o out/allocate.o out/in_out.o out/add_del.o out/matrix_operations.o
	gcc -o app.exe $^

unit_tests.exe : out/check_main.o out/check_delete.o out/add_del.o out/matrix_operations.o out/check_add.o
	gcc -o unit_tests.exe $^

out/main.o : src/main.c inc/main.h
	gcc $(CFLAGS) -c -o out/main.o $<

out/allocate.o : src/allocate.c inc/main.h
	gcc $(CFLAGS) -c -o out/allocate.o $<

out/in_out.o : src/in-out_processing.c inc/main.h
	gcc $(CFLAGS) -c -o out/in_out.o $<

out/add_del.o : src/add-del_operations.c inc/main.h
	gcc $(CFLAGS) -c -o out/add_del.o $<

out/matrix_operations.o : src/matrix_operations.c inc/main.h
	gcc $(CFLAGS) -c -o out/matrix_operations.o $<


out/check_main.o : unit_tests/check_main.c inc/main.h
	gcc $(CFLAGS) -c -o out/check_main.o $<

out/check_delete.o : unit_tests/check_delete.c
	gcc $(CFLAGS) -c -o out/check_delete.o $<

out/check_add.o : unit_tests/check_add.c
	gcc $(CFLAGS) -c -o out/check_add.o $<


.PHONY : clean
clean :
	rm out/*.o *.exe
