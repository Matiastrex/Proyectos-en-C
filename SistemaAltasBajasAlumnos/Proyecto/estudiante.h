#ifndef ESTUDIANTE_H_INCLUDED
#define ESTUDIANTE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "generico.h"
#include "fecha.h"
#include "cadena.h"
#define CANT_PROMEDIOS 5
#define TAM_NOMBRE_EST 30
#define TAM_REGISTRO_EST 65

typedef struct{
    unsigned long long dni;
    unsigned long long fecInscrip;
    char nomApe[TAM_NOMBRE_EST];
    float prom;
}TEst;
typedef struct{
    unsigned long long dni;
    Fecha fecInscrip;
    char nomApe[TAM_NOMBRE_EST];
    float prom;
}TEst2;

int compararFecha(void* a, void* b);
float compararPromedio(void* a, void* b);
void mostrarEstudiante(void* a);
void mostrarEncabezadoEstudiante();
void normalizar(void* c);
void exportarPromedios(void* vec);
int leerPromedios(const char* nomArch);
#endif // ESTUDIANTE_H_INCLUDED
