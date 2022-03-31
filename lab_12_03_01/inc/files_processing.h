#ifndef FILES_H
#include <stdio.h>
#include <stdlib.h>

#ifdef IO_EXPORTS
#define IO_DLL __declspec(dllexport)
#else
#define IO_DLL __declspec(dllimport)
#endif

#define IO_DECL __cdecl

IO_DLL int IO_DECL read_file(FILE *f, int **pb, int **pe);
IO_DLL void IO_DECL write_file(FILE *f, int *pb, int *pe);

#endif