#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include "generico.h"
#define TAM_DEP 25
#define TAM_NOMBREAPELLIDO 30
typedef struct
{
    int legajo;
    char departamento[TAM_DEP];
    char nomApe[TAM_NOMBREAPELLIDO];
    float salario;
}TEmpleado;

void generarEmpleadosDePrueba();
int compararLegajo(void*a,void*b);
void mostrarEmpleado(void*a);
void mostrarEncabezadoEmpleado();



#endif // EMPLEADO_H_INCLUDED
