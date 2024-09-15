#include "funcionesAlumno.h"
#include "funcionesCadena.h"
#include "funcionesFecha.h"
#include "funcionesValidacion.h"
#include "indice.h"

int main()
{
//    char pathArch[TAM_PATH_ARCH]="Alumnos.txt";
//    generarArchivoDePruebaAlumnosParte1(pathArch);

    procesarRegistros();

//    char pathArch[TAM_PATH_ARCH]="Alumnos.dat";
//    generarArchivoDePruebaAlumnosParte2(pathArch);

    menuOperaciones();

    return 0;
}
