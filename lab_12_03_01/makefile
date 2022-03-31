CFLAGS := -std=c99 -Wall -Werror -pedantic

app.exe : out/main.o libsort.a libio.dll libkey.dll
	gcc -o $@ out/main.o -L. -lsort -lio

unit_tests.exe : out/check_main.o out/check_filter.o out/check_sorting.o
	gcc -o $@ $^ -L. -lsort -lio


libsort.a : out/sort_lib.o
	ar rc $@ $<
	ranlib $@

libio.dll : out/io_lib.o
	gcc -shared $< -Wl,--subsystem,windows -o $@

libkey.dll : out/key_lib.o
	gcc -shared $< -Wl,--subsystem,windows -o $@


out/sort_lib.o : src/sorting.c inc/sorting.h
	gcc $(CFLAGS) -c -o $@ $<

out/io_lib.o : src/files_processing.c inc/files_processing.h
	gcc $(CFLAGS) -D IO_EXPORTS -c -o $@ $<

out/key_lib.o : src/filter.c inc/filter.h
	gcc $(CFLAGS) -c -o $@ $<


out/main.o : src/main.c inc/main.h
	gcc $(CFLAGS) -c -o $@ $<


out/check_main.o : unit_tests/check_main.c inc/main.h
	gcc $(CFLAGS) -c -o out/check_main.o unit_tests/check_main.c

out/check_filter.o : unit_tests/check_filter.c inc/filter.h
	gcc $(CFLAGS) -c -o out/check_filter.o unit_tests/check_filter.c

out/check_sorting.o : unit_tests/check_sorting.c inc/sorting.h
	gcc $(CFLAGS) -c -o out/check_sorting.o unit_tests/check_sorting.c


.PHONY : clean
clean :
	$(RM) out/*.o *.exe *.a *.dll
