#ifndef FUNCIONESFECHA_H_INCLUDED
#define FUNCIONESFECHA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{   int d;
    int m;
    int a;
}Fecha;

void ingresarFecha(Fecha* f);
bool esFechaValida(const Fecha* Fecha);
int cantDiasMes(int m, int a);
bool esBisiesto(int anio);
Fecha sumarDiasAFecha(const Fecha* f, int dias);
Fecha restarDiasAFecha(const Fecha* f, int dias);
Fecha restarAniosAFecha(const Fecha* f, int anios);
int compararFecha(const Fecha* f1, const Fecha* f2);
void mostrarFecha( Fecha* f);

#endif // FUNCIONESFECHA_H_INCLUDED
