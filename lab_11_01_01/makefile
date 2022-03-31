CC := gcc
PARAMS := -std=c99 -Wall -Werror -pedantic

app.exe: check_main.o my_snprintf.o check_my_snprintf.o
	$(CC) -o $@ $^

unit_tests.exe: check_main.o my_snprintf.o check_my_snprintf.o
	$(CC) -o $@ $^

my_snprintf.o: my_snprintf.c
	$(CC) $(PARAMS) -c $<

check_main.o: check_main.c
	$(CC) $(PARAMS) -c $<

check_my_snprintf.o: check_my_snprintf.c
	$(CC) $(PARAMS) -c $<

clean:
	rm *.o *.exe