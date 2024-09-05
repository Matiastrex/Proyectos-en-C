#include "estudiante.h"
#include "empleado.h"
#include "fecha.h"
#include "cadena.h"
#include "generico.h"
int main()
{
    //SE DECLARA UN VECTOR DE CHAR QUE CONTENGA CADA UNA DE LAS RUTAS. SE PUEDEN AGREGAR MÁS DE SER NECESARIO
    char vecNomArch[][TAM_PATH]={"../estudiantes1.dat","../estudiantes2.dat","../estudiantes3.dat","../estudiantes4.dat","../estudiantes5.dat"};
    //SE DECLARA EL NOMBRE DEL ARCHIVO FINAL. BIEN PODRÍA SER UN INGRESO POR TECLADO
    char nomArchFinal[]="../EstudiantesFinal.dat";
    //SE OBTIENE LA CANTIDAD DE ARCHIVOS
    size_t ce = sizeof(vecNomArch)/TAM_PATH;

    mergeArchivos(vecNomArch,nomArchFinal,ce,sizeof(TEst),compararFecha,normalizar,CANT_PROMEDIOS,compararPromedio,exportarPromedios);
    //SE LEE EL ARCHIVO FINAL CON EL FIN DE VERIFICAR SU CONTENIDO
    mostrarEncabezadoEstudiante();
    leerArchivoBinario(nomArchFinal,sizeof(TEst),mostrarEstudiante);
    leerPromedios("../MejoresPromedios.csv");

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //SE GENERAN ARCHIVOS CON OTROS TIPOS DE DATOS Y EN DISTINTA CANTIDAD, PARA MOSTRAR QUE FUNCIONA CON OTROS TIPOS DE DATOS Y CON N ARCHIVOS
    generarEmpleadosDePrueba();
    char vecNomArch2[][TAM_PATH]={"../Empleados1.dat","../Empleados2.dat","../Empleados3.dat","../Empleados4.dat","../Empleados5.dat","../Empleados6.dat"};
    char nomArchFinal2[]="../EmpleadosFinal.dat";
    size_t ce2=sizeof(vecNomArch2)/TAM_PATH;
    //SE ENVÍA NULL y 0 A LOS ÚLTIMOS PARÁMETROS YA QUE SÓLO INTERESA MERGEAR LOS ARCHIVOS, NO LAS FUNCIONES ADICIONALES(GENERAR UNA LISTA POR EJ.)
    mergeArchivos(vecNomArch2,nomArchFinal2,ce2,sizeof(TEmpleado),compararLegajo,NULL,0,NULL,NULL);
    mostrarEncabezadoEmpleado();
    leerArchivoBinario(nomArchFinal2,sizeof(TEmpleado),mostrarEmpleado);

    return 0;
}

