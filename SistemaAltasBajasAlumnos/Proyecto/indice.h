#ifndef INDICE_H_INCLUDED
#define INDICE_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "funcionesCadena.h"

#define DUPLICADO 2
#define OPERACION_OK 1
#define OPERACION_ERROR 0

#define TAM_LINEA_IND 100
#define TAM_PATH_IND 50

typedef struct
{
    long dni;
    unsigned nro_reg;
}
RegIndice;
typedef struct
{
    RegIndice* registros;
    int ce;
    int cap;
    bool finSec;
}
Indice;

void ind_crear(Indice* ind);
int ind_insertar(Indice* ind, const RegIndice* reg);
int ind_eliminar(Indice* ind, RegIndice* reg);
int ind_buscar(const Indice* ind, RegIndice* reg);
int ind_cargar(Indice* ind, const char* path);
int ind_grabar(const Indice* ind, const char* path);
void ind_vaciar(Indice* ind);
int ind_primero(Indice* ind, RegIndice* reg);
int ind_siguiente(Indice* ind, RegIndice* reg);
int ind_fin(const Indice* ind);
void ind_liberar(Indice* ind);

void ind_mostrar(Indice* ind);

#endif // INDICE_H_INCLUDED
