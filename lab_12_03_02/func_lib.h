#ifndef __GEN__H__
#define __GEN__H__

#ifdef FUNC_EXPORTS
#define FUNC_DLL __declspec(dllexport)
#else
#define FUNC_DLL __declspec(dllimport)
#endif

#define FUNC_DECL __cdecl

#define YES 1
#define NO 0
#define OK 0
#define ERR -1

FUNC_DLL void FUNC_DECL generate_simple(int n, int *arr);
FUNC_DLL int FUNC_DECL modif_array(int *src, int n, int *dst, int m, int x);

#endif