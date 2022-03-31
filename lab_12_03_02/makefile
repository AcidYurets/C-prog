libfunc.dll : func_lib.c
	gcc -std=c99 -Wall -Werror -D FUNC_EXPORTS -c func_lib.c
	gcc -shared func_lib.o -Wl,--subsystem,windows -o libfunc.dll