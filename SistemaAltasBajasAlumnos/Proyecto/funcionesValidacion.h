#ifndef FUNCIONESVALIDACION_H_INCLUDED
#define FUNCIONESVALIDACION_H_INCLUDED

#include <stdlib.h>

#include "funcionesFecha.h"
#include "funcionesCadena.h"
#include "Alumno.h"

#define VALID_OK 0
#define VALID_ERROR 1
#define CANT_CAR 9

int validaDni(const long dni);
int validaApeNom(const char* apeNom);
int validaSexo(const char sexo);
int validaCarrera(const char* car);
int validaMatAprob(const int matAprob);
int validaFecNac(const Fecha* fec, const Fecha* fecProc);
int validaFecIng(const Fecha* fec, const Fecha* fecProc, const Fecha* fecNac);
int validaFecUltMatAprob(const Fecha* fec, const Fecha* fecIng, const Fecha* fecProc);
int validarAlumno(Alumno* reg, const Fecha* fecProc);

#endif // FUNCIONESVALIDACION_H_INCLUDED
