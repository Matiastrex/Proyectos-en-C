#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include <stdio.h>
#include <time.h>
#define ESBISIESTO(x) ((x)%4==0 && ((x)%100!=0||(x)%400==0))
#define TAM_FECHA 20
 typedef struct
{
    int a;
    int m;
    int d;
}Fecha;

Fecha sumarDiasAFecha(const Fecha* f, int dias);
void mostrarFecha(Fecha* f);
int cantDiasMes(int m, int a);
Fecha* normalizarFecha(unsigned long long fecha,Fecha* fecNormalizar);
void formatFechaUnix(unsigned long long fecha, char *buffer, size_t tam);
#endif // FECHA_H_INCLUDED
