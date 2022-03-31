CFLAGS := -std=gnu99 -Wall -Werror -Wpedantic -ggdb

app.exe : out/main.o out/process_files.o out/process_goods.o
	gcc -o $@ $^

unit_tests.exe : out/check_main.o out/check_select_goods.o out/process_goods.o
	gcc -o $@ $^


out/main.o : src/main.c inc/main.h
	gcc $(CFLAGS) -c -o $@ $<

out/process_files.o : src/process_files.c inc/main.h
	gcc $(CFLAGS) -c -o $@ $<

out/process_goods.o : src/process_goods.c inc/main.h
	gcc $(CFLAGS) -c -o $@ $<


out/check_main.o : unit_tests/check_main.c inc/main.h
	gcc $(CFLAGS) -c -o $@ $<

out/check_select_goods.o : unit_tests/check_select_goods.c
	gcc $(CFLAGS) -c -o $@ $<


.PHONY : clean
clean :
	rm out/*.o *.exe
