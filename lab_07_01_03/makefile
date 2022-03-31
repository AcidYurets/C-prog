CFLAGS := -std=c99 -Wall -Werror -pedantic

app.exe : out/main.o out/files.o out/filter.o out/sorting.o
	gcc -o app.exe out/main.o out/files.o out/filter.o out/sorting.o

unit_tests.exe : out/check_main.o out/check_filter.o out/check_sorting.o out/filter.o out/sorting.o
	gcc -o unit_tests.exe $^

# time.exe : out/sorting.o out/files.o
#	gcc -o time.exe $^

out/main.o : src/main.c inc/main.h
	gcc $(CFLAGS) -c -o out/main.o src/main.c

out/files.o : src/files_processing.c inc/files_processing.h
	gcc $(CFLAGS) -c -o out/files.o src/files_processing.c

out/filter.o : src/filter.c inc/filter.h
	gcc $(CFLAGS) -c -o out/filter.o src/filter.c

out/sorting.o : src/sorting.c inc/sorting.h
	gcc $(CFLAGS) -c -o out/sorting.o src/sorting.c


out/check_main.o : unit_tests/check_main.c inc/main.h
	gcc $(CFLAGS) -c -o out/check_main.o unit_tests/check_main.c

out/check_filter.o : unit_tests/check_filter.c inc/filter.h
	gcc $(CFLAGS) -c -o out/check_filter.o unit_tests/check_filter.c

out/check_sorting.o : unit_tests/check_sorting.c inc/sorting.h
	gcc $(CFLAGS) -c -o out/check_sorting.o unit_tests/check_sorting.c

.PHONY : clean
clean :
	$(RM) out/*.o *.exe
