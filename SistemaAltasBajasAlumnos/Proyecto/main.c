#include "funcionesAlumno.h"
#include "funcionesCadena.h"
#include "funcionesFecha.h"
#include "funcionesValidacion.h"
#include "indice.h"

int main()
{
//    char pathArch[TAM_PATH_ARCH]="Alumnos.txt";
//    generarArchivoDePruebaAlumnosParte1(pathArch);
    /// PARA USAR EL ARCHIVO: ../ArchivoDummyParaProcesarRegistros/Alumnos.txt

    procesarRegistros();

//    char pathArch2[TAM_PATH_ARCH]="Alumnos.dat";
//    generarArchivoDePruebaAlumnosParte2(pathArch2);
    /// PARA USAR EL ARCHIVO: ../ArchivosDummyParaMenuOperaciones/Alumnos.dat

    menuOperaciones();

    return 0;
}
