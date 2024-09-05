#ifndef CADENA_H_INCLUDED
#define CADENA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define AMAYUS(x) ((x)>='a'&&(x)<='z')? (x)-('a'-'A') : (x)
#define ESLETRA(x) (((x)>='a' && (x)<='z') ||  ((x)>='A' && (x)<='Z'))

int proximaPalabra(char* cad,char** ini,char** fin);
void normalizarApellidoNombre(char* str);


#endif // CADENA_H_INCLUDED
