#include "funcionesCadena.h"
void crearSecuencia(SecuenciaPal* sec, char* cad)
{
    sec->cad=cad;
    sec->cursor=cad;
    sec->finSec=false;
}
bool leerPalabra(SecuenciaPal* sec, Palabra* pal)
{
    while(*sec->cursor && !isalpha(*sec->cursor))
        sec->cursor++;
    if(!*sec->cursor)
    {
        sec->finSec = true;
        return false;
    }
    char* curPal = pal->vec;
    while(*sec->cursor && isalpha(*sec->cursor))
    {
        *curPal = *sec->cursor;
        curPal++;
        sec->cursor++;
    }
    *curPal='\0';
    return true;
}
void aTitulo(Palabra* pal)
{
    char* curPal = pal->vec;
    *curPal = toupper(*curPal);
    curPal++;
    while(*curPal)
    {
        *curPal=tolower(*curPal);
        curPal++;
    }
}
void escribirPalabra(SecuenciaPal* sec, const Palabra* pal)
{
    char* curPal = (char*)pal->vec;
    while(*curPal)
    {
        *sec->cursor=*curPal;
        sec->cursor++;
        curPal++;
    }
}
void normalizar(const char* textoAnorm, char* textoNorm)
{
    SecuenciaPal secL, secE;
    crearSecuencia(&secL,(char*)textoAnorm);
    crearSecuencia(&secE, textoNorm);
    Palabra pal;
    leerPalabra(&secL,&pal);
    bool primerApe = true;

    while(!finSecuencia(&secL))
    {
        aTitulo(&pal);
        escribirPalabra(&secE,&pal);
        leerPalabra(&secL,&pal);
        if(primerApe)
        {
            primerApe = false;
            escribirCaracter(&secE,',');
        }
        escribirCaracter(&secE,' ');
        cerrarSecuencia(&secE);
    }
}
void normalizaApeNom(const char* apeNom, char* apeNomNorm)
{
    normalizar(apeNom,apeNomNorm);
}
bool finSecuencia(const SecuenciaPal* sec)
{
    return sec->finSec;
}
void reposicionarCursor(SecuenciaPal* sec, int despl)
{
    sec->cursor+=despl;
}
void cerrarSecuencia(SecuenciaPal* sec)
{
    *sec->cursor='\0';
}
void escribirCaracter(SecuenciaPal* sec, char c)
{
    *sec->cursor=c;
    sec->cursor++;
}
char miToUpper(char c)
{
    return c>='a' && c<='z'? c-('a'-'A'):c;
}
char miToLower(char c)
{
    return c>='A' && c<='Z'? c+('a'-'A'):c;
}
bool miIsAlpha(char c)
{
    return (c>='A' && c<='Z') || (c>='a' && c<='z');
}
void aTituloUnico(Palabra* pal)
{
    char* curPal = pal->vec;
    if(pal->mayus)
    {
        *curPal = toupper(*curPal);
        curPal++;
        pal->mayus=false;
    }
    while(*curPal)
    {
        *curPal=tolower(*curPal);
        curPal++;
    }
}
size_t miStrlen(const char *s)
{
    int tam = 0;
    char* str = (char*)s;
    while(*str)
    {
        str++;
        tam++;
    }
    return tam;
}
int miStrcmp(const char *s1, const char *s2)
{
    char* str1 = (char*)s1;
    char* str2 = (char*)s2;
    while(*str1==*str2 && *str1 && *str2)
    {
        str1++;
        str2++;
    }
    if(!*str1&&!*str2)
            return 0;
    if(*str1>*str2)
        return 1;
    else
        return -1;
}
int miStrncmp(const char *s1, const char *s2, size_t n)
{
    int i=0;
    char* str1 = (char*)s1;
    char* str2 = (char*)s2;
    while(i<n && *str1==*str2)
    {
        str1++;
        str2++;
        i++;
    }
    if(i!=n)
    {
        if(*str1>*str2)
            return 1;
        else
            return -1;
    }
    return 0;
}
int miStrcmpi(const char *s1, const char *s2)
{
    char* str1 = (char*)s1;
    char* str2 = (char*)s2;
    while(miToLower(*str1)==miToLower(*str2) && *str1 && *str2)
    {
        str1++;
        str2++;
        if(!*str1&&!*str2)
            return 0;
    }
    if(miToLower(*str1)>miToLower(*str2))
        return 1;
    else
        return -1;
}
char* miStrcpy(char *s1, const char *s2)
{
    char* str1 = s1;
    char* str2 = (char*)s2;
    while(*str1&&*str2)
    {
        *str1=*str2;
        str1++;
        str2++;
    }
    *str1='\0';
    return s1;
}
char* miStrncpy(char *s1, const char *s2, size_t n)
{
    char* str1 = s1;
    char* str2 = (char*)s2;
    int i = 0;
    while(*str1 && *str2 && i<n)
    {
        *str1=*str2;
        str1++;
        str2++;
        i++;
    }
    *str1='\0';
    return s1;
}
char* miStrcat(char*s1, const char *s2)
{
    char* str2 = (char*)s2;
    char* str1 = (char*)s1;
    char* finS1 = s1+sizeof(s1);
    str1=str1+miStrlen(s1);
    while(*str2 && str1<finS1)
    {
        *str1=*str2;
        str1++;
        str2++;
    }
    *str1='\0';
    return s1;
}
char* miStrchr(char *s, int c)
{
    char* str = s;

    while(*str && *str!=(char)c)
        str++;

    if(*str==(char)c)
        return str;
    else
        return NULL;
}
char* miStrrchr(char *s, int c)
{
    char* str = s;
    char* loc;
    while(*str)
    {
        if(*str==(char)c)
            loc = str;
        str++;
    }
    if(*loc==(char)c)
        return loc;
    else
        return NULL;
}
char* miStrstr(const char *s1, const char *s2)
{
    char* str1 = (char*)s1;
    char* str2 = (char*)s2;
    char* loc;
    int tam = miStrlen(str2);

    if(tam==0)
        return (char*)s1;

    while(*str1)
    {
        if(!miStrncmp(str1,str2,tam))
            loc = str1;
        str1++;
    }
    if(loc<s1||loc>s1+sizeof(s1))
        return NULL;
    return loc;
}
