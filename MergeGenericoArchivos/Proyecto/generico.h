#ifndef GENERICO_H_INCLUDED
#define GENERICO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_PATH 200
typedef struct{
    FILE* pf;
    void* regInicial;
}TFiles;


void* buscarMenorRegistro(const void* vec, size_t ce, size_t tam, int cmp(void* a, void* b));
int eliminarElemento(void* vec, size_t* ce, size_t tamElem, void* elem, int cmp(void* a,void* b));
int leerArchivoBinario(const char* nomArch, size_t tam, void accion(void* a));
void insertarOrdenadamente(void *vec, size_t *ce, size_t tamVector, size_t tamDato, void *val, float cmp(void *a,void *b));
int mergeArchivos(const char vecNomArch[][TAM_PATH],const char* archFinal,size_t ce,size_t tam, int cmp1(void* a, void* b),void accion1(void* c),
                  size_t tamLista,float cmp2(void* a, void* b),void accion2(void* c));

#endif // GENERICO_H_INCLUDED
