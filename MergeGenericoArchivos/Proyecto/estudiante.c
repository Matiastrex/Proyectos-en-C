#include "estudiante.h"

int compararFecha(void* a, void* b)
{
    TFiles *tfilesA = (TFiles *)a;
    TFiles *tfilesB = (TFiles *)b;

    TEst *testA = (TEst *)tfilesA->regInicial;
    TEst *testB = (TEst *)tfilesB->regInicial;

    return testA->fecInscrip-testB->fecInscrip;
}
float compararPromedio(void* a, void* b)
{
    TEst* estA = (TEst*)a;
    TEst* estB = (TEst*)b;
    return estA->prom-estB->prom;
}
void mostrarEstudiante(void* a)
{
    TEst* aux = (TEst*)a;
    printf("%I64u|%017I64u|%-20s|%.2f \n",aux->dni,aux->fecInscrip,aux->nomApe,aux->prom);
}
void mostrarEncabezadoEstudiante()
{
    printf("  DNI   |FECHA INSCRIPCION|NOMBRE Y APELLIDO   |PROMEDIO\n");
}

void normalizar(void* c)
{
    TEst* est = (TEst*)c;
    normalizarApellidoNombre(est->nomApe);
}
void exportarPromedios(void* vec)
{
    int i;
    char bufferFecha[TAM_FECHA];
    TEst* ptr = (TEst*)vec;
    FILE* pf = fopen("../MejoresPromedios.csv","wt");
    if(!pf)
        return;
    for(i=0;i<CANT_PROMEDIOS;i++)
    {
        formatFechaUnix(ptr->fecInscrip,bufferFecha,sizeof(bufferFecha));
        fprintf(pf,"%I64u;%s;%s;%.2f\n",ptr->dni,bufferFecha,ptr->nomApe,ptr->prom);
        ptr++;
    }
    fclose(pf);
}
int leerPromedios(const char* nomArch)
{
    FILE* pf = fopen(nomArch,"rt");
    char linea[TAM_REGISTRO_EST];
    char bufferFecha[TAM_FECHA];
    TEst est;
    if(!pf)
        return 0;
    puts("-------------------------------------------------------");
    puts("LOS ALUMNOS CON MEJORES PROMEDIOS SON:");
    while(fgets(linea,sizeof(linea),pf))
    {
        sscanf(linea,"%I64u;%[^;];%[^;];%f\n",&est.dni,bufferFecha,est.nomApe,&est.prom);
        printf("%I64u|%s|%-17s|%.2f\n",est.dni,bufferFecha,est.nomApe,est.prom);
    }
    puts("-------------------------------------------------------");
    fclose(pf);
    return 1;
}


