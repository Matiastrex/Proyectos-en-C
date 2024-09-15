#include "funcionesFecha.h"

void ingresarFecha(Fecha* f)
{
    puts("Ingresar una fecha(D/M/A):");
    scanf("%d/%d/%d",&f->d,&f->m,&f->a);
    while(!esFechaValida(f))
    {
        puts("Fecha invalida. Ingrese nuevamente");
        scanf("%d/%d/%d",&f->d,&f->m,&f->a);
    }
}

bool esFechaValida(const Fecha* Fecha)
{
    if(Fecha->a>=1601)
        if(Fecha->m>=1 && Fecha->m<=12)
            if(Fecha->d>=1 && Fecha->d<=cantDiasMes(Fecha->m,Fecha->a))
                return true;
    return false;
}

int cantDiasMes(int m, int a)
{
    int dm[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(m==2 && esBisiesto(a))
        return 29;
    return dm[m];
}

bool esBisiesto(int anio)
{
    return anio%4==0 && (anio%100!=0 || anio%400==0);
}

Fecha sumarDiasAFecha(const Fecha* f, int dias)
{
    int cd;
    Fecha fs = *f;
    fs.d+=dias;
    while(fs.d>(cd=cantDiasMes(fs.m,fs.a)))
    {
        fs.d-=cd;
        fs.m++;
        if(fs.m>12)
        {
            fs.m=1;
            fs.a++;
        }
    }
    return fs;
}

void mostrarFecha( Fecha* f)
{
    puts("\n La fecha resultante es: ");
    printf("%d/%d/%d",f->d,f->m,f->a);
}

Fecha restarDiasAFecha(const Fecha* f, int dias)
{
    int cd;
    Fecha fr = *f;
    fr.d-=dias;
    if(fr.m<2)
        cd=cantDiasMes(12,fr.a-1);
    else
        cd=cantDiasMes(fr.m-1,fr.a);
    while(fr.d<1)
    {
        fr.m--;
        fr.d+=cd;
        if(fr.m<1)
        {
            fr.a--;
            fr.m=12;
        }
        if(fr.m<2)
        cd=cantDiasMes(12,fr.a-1);
        else
        cd=cantDiasMes(fr.m-1,fr.a);
    }
    return fr;
}
Fecha restarAniosAFecha(const Fecha* f, int anios)
{
    int diasAnio;
    Fecha fr = *f;
    while(anios>0)
    {
        diasAnio=esBisiesto(fr.a)? 366 : 365;
        fr=restarDiasAFecha(&fr,diasAnio);
        anios--;
    }
    return fr;
}
int compararFecha(const Fecha* f1,const Fecha* f2)
{
    if(f1->a>f2->a)
        return 1;
    if(f1->a<f2->a)
        return -1;
    if(f1->m>f2->m)
        return 1;
    if(f1->m<f2->m)
        return -1;
    if(f1->d>f2->d)
        return 1;
    if(f1->d<f2->d)
        return -1;
    return 0;
}
