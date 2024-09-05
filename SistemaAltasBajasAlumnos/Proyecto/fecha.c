#include "fecha.h"
int cantDiasMes(int m, int a)
{
    int dm[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(m==2 && ESBISIESTO(a))
        return 29;
    return dm[m];
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
    puts("\nLa fecha resultante es: ");
    printf("%d/%d/%d\n",f->d,f->m,f->a);
}
Fecha* normalizarFecha(unsigned long long fecha,Fecha* fecNormalizar)
{
    int cantDias = fecha/24/3600/1000;
    *fecNormalizar=sumarDiasAFecha(fecNormalizar,cantDias);
    return fecNormalizar;
}
void formatFechaUnix(unsigned long long fecha, char *buffer, size_t tam)
{
	time_t unix = (time_t)(fecha / 1000);
	struct tm * tm_info;
	tm_info = localtime(&unix);
	strftime(buffer, tam, "%d/%m/%Y %H:%M:%S", tm_info);
}
