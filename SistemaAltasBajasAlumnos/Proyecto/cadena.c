#include "cadena.h"
int proximaPalabra(char* cad,char** ini,char** fin)
{
    int ce = 0;

    while(*cad && !ESLETRA(*cad))
        cad++;

    if(*cad == '\0')
    {
        *fin = NULL;
        *ini = NULL;
        return ce;
    }

    *ini = cad;
    while(*cad && ESLETRA(*cad))
    {
        ce++;
        cad++;
    }
    *fin = cad;
    return ce;
}
void normalizarApellidoNombre(char* str)
{
    int ce;
    char* ini;
    char* fin;

    ce=proximaPalabra(str,&ini,&fin);
    while(ce>0)
    {

        *ini=AMAYUS(*ini);
        ce=proximaPalabra(fin,&ini,&fin);
    }
}
