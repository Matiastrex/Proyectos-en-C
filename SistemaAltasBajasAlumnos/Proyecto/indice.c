#include "indice.h"
void ind_crear(Indice* ind)
{
    ind->registros = malloc(100*sizeof(RegIndice));
    ind->cap = 100;
    ind->ce = 0;
    ind->finSec=false;
}
int ind_insertar(Indice* ind, const RegIndice* reg)
{
    if(ind->ce==ind->cap)
    {
        size_t nuevaCap = ind->cap*1.3;
        RegIndice* nuevoInd = realloc(ind->registros,ind->cap*sizeof(RegIndice));
        if(nuevoInd==NULL)
            return OPERACION_ERROR;
        ind->cap=nuevaCap;
        ind->registros=nuevoInd;
    }
    RegIndice* i = ind->registros;
    RegIndice* ult = ind->registros+ind->ce-1;

    while(i<=ult && reg->dni>i->dni)
        i++;

    if(i<=ult && reg->dni==i->dni)
        return DUPLICADO;

    for(RegIndice* j=ult;j>=i;j--)
    {
        (j+1)->dni=j->dni;
        (j+1)->nro_reg=j->nro_reg;
    }

    i->dni=reg->dni;
    i->nro_reg=reg->nro_reg;

    ind->ce++;
    return OPERACION_OK;
}
int ind_eliminar(Indice* ind, RegIndice* reg)
{
    if(ind->ce==0)
        return OPERACION_ERROR;

    RegIndice* i = ind->registros;
    RegIndice* ult = ind->registros+ind->ce-1;

    while(i<=ult&&reg->dni>i->dni)
        i++;

    if(i>ult || reg->dni<i->dni)
        return OPERACION_ERROR;

    for(RegIndice* j=i;j<ult;j++)
    {
        j->dni=(j+1)->dni;
        j->nro_reg=(j+1)->nro_reg;
    }
    ind->ce--;
    return OPERACION_OK;
}
int ind_buscar(const Indice* ind, RegIndice* reg)
{
    RegIndice* i = ind->registros;
    RegIndice* ult = ind->registros+ind->ce-1;

    if(reg->dni > ult->dni)
    {
        return OPERACION_ERROR;
    }

    while(i<ult&&reg->dni!=i->dni)
        i++;
    if(reg->dni!=i->dni)
        return OPERACION_ERROR;

    reg->dni=i->dni;
    reg->nro_reg=i->nro_reg;

    return OPERACION_OK;
}
int ind_cargar(Indice* ind, const char* path)
{
    FILE* archInd = fopen(path,"rt");
    if(archInd==NULL)
    {
        printf("Error al abrir/crear archivo Indice\n");
        return OPERACION_ERROR;
    }
    char linea[TAM_LINEA_IND];
    char* act;
    RegIndice* i = ind->registros;

    fgets(linea,TAM_LINEA_IND,archInd);
    while(!feof(archInd))
    {

        act = strchr(linea,'\n');
        if(act==NULL)
            return OPERACION_ERROR;
        *act='\0';


        act=strrchr(linea,'|');
        sscanf(act+1,"%u",&i->nro_reg);
        *act='\0';

        sscanf(linea,"%ld",&i->dni);

        i++;
        ind->ce++;

        fgets(linea,TAM_LINEA_IND,archInd);
    }

    fclose(archInd);
    return OPERACION_OK;
}
int ind_grabar(const Indice* ind, const char* path)
{
    FILE* archInd = fopen(path,"wt");
    if(archInd==NULL)
    {
        printf("Error al abrir/crear archivo indice\n");
        return OPERACION_ERROR;
    }
    RegIndice* i = ind->registros;
    RegIndice* ult = ind->registros+ind->ce-1;

    while(i<=ult)
    {
        fprintf(archInd,"%ld|%u\n",i->dni,i->nro_reg);
        i++;
    }
    fclose(archInd);
    return OPERACION_OK;
}

void ind_vaciar(Indice* ind)
{
    ind->ce=0;
}

int ind_primero(Indice* ind, RegIndice* reg)
{
    if(ind->ce==0)
    {
        ind->finSec=true;
        return OPERACION_ERROR;
    }

    reg->dni=ind->registros->dni;
    reg->nro_reg=ind->registros->nro_reg;

    return OPERACION_OK;
}

int ind_siguiente(Indice* ind, RegIndice* reg)
{
    RegIndice* ult = ind->registros+ind->ce-1;
    if(reg->dni==ult->dni)
    {
        ind->finSec=true;
        return OPERACION_ERROR;
    }
    RegIndice* pos = ind->registros+reg->nro_reg;

    reg->dni=pos->dni;
    reg->nro_reg=pos->nro_reg;

    return OPERACION_OK;
}

int ind_fin(const Indice* ind)
{
    if(ind->finSec==true)
        return OPERACION_OK;
    else
        return OPERACION_ERROR;
}

void ind_liberar(Indice* ind)
{
    free(ind->registros);
}

void ind_mostrar(Indice* ind)
{
    RegIndice* i = ind->registros;
    RegIndice* ult = ind->registros+ind->ce-1;
    while(i<=ult)
    {
        printf("%ld - %u\n", i->dni, i->nro_reg);
        i++;
    }
}
