#include "funcionesValidacion.h"

int validaDni(const long dni)
{
    if(dni<=10000||dni>=100000000)
        return VALID_ERROR;
    else
        return VALID_OK;
}

int validaApeNom(const char* apeNom)
{
    int longitud = miStrlen(apeNom);
    if(longitud>1&&longitud<41)
        return VALID_OK;
    else
        return VALID_ERROR;
}

int validaSexo(const char sexo)
{
    if(sexo!='F'&&sexo!='M')
        return VALID_ERROR;
    else
        return VALID_OK;
}
int validaCarrera(const char* car)
{
    char carreras[CANT_CAR][4]={{"INF\0"},{"ELE\0"},{"IND\0"},{"ECO\0"},{"DER\0"},{"ADM\0"},{"MED\0"},{"EDF\0"},{"FIL\0"}};
    int i=0;
    while((strcmp(carreras[i],car)!=0)&&i<CANT_CAR)
        i++;
    if(i==CANT_CAR)
        return VALID_ERROR;
    else
        return VALID_OK;
}
int validaMatAprob(const int matAprob)
{
    if(matAprob<0)
        return VALID_ERROR;
    else
        return VALID_OK;
}
int validaFecNac(const Fecha* fec, const Fecha* fecProc)
{
    Fecha fecProcMenos10Anios=restarAniosAFecha(fecProc,10);

    if(esFechaValida(fec)&&compararFecha(fec,&fecProcMenos10Anios)<0)
        return VALID_OK;
    else
        return VALID_ERROR;
}
int validaFecIng(const Fecha* fec, const Fecha* fecProc, const Fecha* fecNac)
{
    if(esFechaValida(fec)&&compararFecha(fec,fecProc)<=0&&compararFecha(fec,fecNac)>0)
        return VALID_OK;
    else
        return VALID_ERROR;
}
int validaFecUltMatAprob(const Fecha* fec, const Fecha* fecIng, const Fecha* fecProc)
{
    if(compararFecha(fec,fecIng)>=0&&compararFecha(fec,fecProc)<=0)
        return VALID_OK;
    else
        return VALID_ERROR;
}
int validarAlumno(Alumno* reg, const Fecha* fecProc)
{
        if(!validaDni(reg->dni)&&!validaApeNom(reg->apeNom)&&!validaFecNac(&(reg->fecNac),fecProc)&&!validaSexo(reg->sexo)&&
           !validaFecIng(&(reg->fecIng),fecProc,&(reg->fecNac))&&!validaCarrera(reg->carrera)&&!validaMatAprob(reg->matAprob)&&
           !validaFecUltMatAprob(&(reg->fecUltMatAprob),&(reg->fecIng),fecProc))
            {
                return VALID_OK;
            }
        else
            {
                return VALID_ERROR;
            }
}
