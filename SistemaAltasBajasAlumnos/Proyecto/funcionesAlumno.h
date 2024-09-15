#ifndef FUNCIONESALUMNO_H_INCLUDED
#define FUNCIONESALUMNO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "funcionesFecha.h"
#include "funcionesValidacion.h"
#include "funcionesCadena.h"
#include "indice.h"
#include "Alumno.h"

#define TAM_PATH_ARCH 50
#define TAM_LINEA 500
#define CANT_REGISTROS_PRUEBA1 10
#define CANT_REGISTROS_PRUEBA2 15

#define TODO_OK 0
#define ERR_ARCH 1
#define ERR_MEM 2
#define ERR_LINEA_LARGA 3
#define ERR_FUERA_RANGO 4
#define ERR_DNI 5

void mostrarEncabezado();
int generarArchivoDePruebaAlumnosParte1(const char* nomAlu);
int generarArchivoDePruebaAlumnosParte2(const char* nomAlu);
int procesarRegistros();
int alumnoTxtARegBin(char* linea,Alumno* reg,bool* errorFatal);
void escribirAlumnoABinario(FILE* arch,const Alumno* reg);
void escribirAlumnoATexto(FILE* arch,const Alumno* reg);
int contarCaracteres(const char* str, char c);
void ingresarPathArchivo(char* path);
char* agregarExtension(const char* nomArch, char* ext);
char* convertirExtension(char* nomArch, char* ext);
int menuOperaciones();
int procesarAlta(FILE* archBin,Indice* ind,Fecha* fecProc);
int ingresarDatosAlta(Indice* ind,Alumno* alu,RegIndice* reg, Fecha* fecProc);
int procesarBaja(FILE* archBin, Indice* ind, Fecha* fecProc);
int ingresarDatosBaja(Indice* ind, Alumno* alu, RegIndice* reg);
void listarBajas(FILE* arch,Fecha* fecProc);
int listarActivos(FILE* archBin,Fecha* fecProc);
void listaOrdenar(Alumno* alu,int ce);
int buscarDatosAlumnoPorDni(FILE* arch,Alumno* alu,int ce);
Alumno* buscarMenorDni(Alumno* ini,Alumno* fin);


#endif // FUNCIONESALUMNO_H_INCLUDED
