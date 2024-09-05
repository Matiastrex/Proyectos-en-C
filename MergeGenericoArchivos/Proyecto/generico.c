#include "generico.h"
int mergeArchivos(const char vecNomArch[][TAM_PATH],const char* archFinal,size_t ce,size_t tam, int cmp1(void* a, void* b),void accion1(void* c)
                     ,size_t tamLista,float cmp2(void* a, void* b),void accion2(void* c))
{
    int i,j;
    TFiles* archivo;
    size_t ceLista=0;
    void* buffer = malloc(tam);
    void* lista = malloc(tamLista*tam);
    TFiles* vecArchivos = malloc(sizeof(TFiles)*ce);
    FILE* archivoResultante = fopen(archFinal,"wb");

    if(!vecArchivos)
    {
        free(buffer);
        free(lista);
        fclose(archivoResultante);
        return 0;
    }
    if(!lista)
    {
        free(buffer);
        free(vecArchivos);
        fclose(archivoResultante);
        return 0;
    }
    if(!buffer)
    {
        fclose(archivoResultante);
        free(lista);
        free(vecArchivos);
        return 0;
    }
    if(!archivoResultante)
    {
        free(vecArchivos);
        free(lista);
        free(buffer);
        return 0;
    }

    for(i=0;i<ce;i++)
    {
        vecArchivos->pf = fopen(vecNomArch[i],"rb");
        vecArchivos->regInicial = malloc(tam);
        if(vecArchivos->pf==NULL||vecArchivos->regInicial==NULL)
        {
            for(j=i;j>0;j--)
            {
                vecArchivos--;
                free(vecArchivos->regInicial);
                fclose(vecArchivos->pf);
            }
            return 0;
        }
        fread(vecArchivos->regInicial,tam,1,vecArchivos->pf);
        vecArchivos++;
    }

    vecArchivos-=ce;
    archivo=buscarMenorRegistro(vecArchivos,ce,sizeof(TFiles),cmp1);
    while(ce)
    {
        fseek(archivo->pf,-1L*tam,SEEK_CUR);
        fread(buffer,tam,1,archivo->pf);
        while(!feof(archivo->pf))
        {
            if(accion1!=NULL)
                accion1(buffer);
            if(cmp2!=NULL && accion2!=NULL)
                insertarOrdenadamente(lista,&ceLista,tamLista,tam,buffer,cmp2);

            fwrite(buffer,tam,1,archivoResultante);
            fread(buffer,tam,1,archivo->pf);
        }
        fclose(archivo->pf);
        eliminarElemento(vecArchivos,&ce,sizeof(TFiles),archivo,cmp1);
        archivo=buscarMenorRegistro(vecArchivos,ce,sizeof(TFiles),cmp1);
    }

    if(accion2!=NULL)
        accion2(lista);

    fclose(archivoResultante);
    free(vecArchivos);
    free(lista);
    free(buffer);
    return 1;
}
void* buscarMenorRegistro(const void* vec, size_t ce, size_t tam, int cmp(void* a, void* b))
{
    void* min = (void*)vec;
    void* fin = (void*)vec+(ce*tam)-tam;
    while(vec<fin)
    {
        if(cmp((void*)(vec+tam),min)<0)
            min = (void*)vec+tam;

        vec+=tam;
    }
    return min;
}
int eliminarElemento(void* vec, size_t* ce, size_t tamElem, void* elem, int cmp(void* a,void* b))
{
    void* fin = vec + ((*ce)-1)*tamElem;
    while(vec<=fin&&cmp(vec,elem)!=0)
        vec+=tamElem;
    if(cmp(vec,elem)==0)
    {
        memmove(vec,vec+tamElem,fin-vec+tamElem);
    }
    else
    {
        return 1;
    }
    (*ce)--;
    return 0;
}
int leerArchivoBinario(const char* nomArch, size_t tam, void accion(void* a))
{
    void* buffer = malloc(tam);
    FILE* pf = fopen(nomArch,"rb");

    if(!buffer)
    {
        fclose(pf);
        return 0;
    }
    if(!pf)
    {
        free(buffer);
        return 0;
    }
    fread(buffer,tam,1,pf);
    while(!feof(pf))
    {
        accion(buffer);
        fread(buffer,tam,1,pf);
    }
    free(buffer);
    fclose(pf);
    return 1;
}
void insertarOrdenadamente(void *vec, size_t *ce, size_t tamVector, size_t tamDato, void *val, float cmp(void *a,void *b))
{
    void *ini=vec;
    if(*ce<tamVector){
       vec+= (*ce)*tamDato;
       (*ce)++;
    }
    else{
        vec=vec+(*ce-1)*tamDato;
        if(cmp(vec,val)>0)
            return;
    }
    while((vec>ini) && (cmp(vec-tamDato,val)<0)){
        memcpy(vec,vec-tamDato,tamDato);
        vec-=tamDato;
    }
    memcpy(vec,val,tamDato);
}
