#ifndef FUNCIONESCADENA_H_INCLUDED
#define FUNCIONESCADENA_H_INCLUDED

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 28 //La palabra más extensa del español tiene 23 caracteres, agrego 5 por precaucion//
#define TEXTO 250
typedef struct
{
    char vec[TAM];
    bool mayus;// Variable auxiliar para aplicar mayus solo a primera letra de una oracion
}Palabra;

typedef struct
{
    char* cad;
    char* cursor;
    bool finSec;
} SecuenciaPal;

void crearSecuencia(SecuenciaPal* sec, char* cad);
bool leerPalabra(SecuenciaPal* sec, Palabra* pal);
void aTitulo(Palabra* pal);
void escribirPalabra(SecuenciaPal* sec, const Palabra* pal);
void normalizar(const char* textoAnorm, char* textoNorm);
void normalizaApeNom(const char* apeNom, char* apeNomNorm);
bool finSecuencia(const SecuenciaPal* sec);
void reposicionarCursor(SecuenciaPal* sec, int despl);
void cerrarSecuencia(SecuenciaPal* sec);
void escribirCaracter(SecuenciaPal* sec, char c);
char miToUpper(char c);
char miToLower(char c);
bool miIsAlpha(char c);
void aTituloUnico(Palabra* pal);

//MIS FUNCIONES DE STRING//
size_t miStrlen(const char *s);
int miStrcmp(const char *s1, const char *s2);
int miStrncmp(const char *s1, const char *s2, size_t n);
int miStrcmpi(const char *s1, const char *s2);
char* miStrcpy(char *s1, const char *s2);
char* miStrncpy(char *s1, const char *s2, size_t n);
char* miStrcat(char*s1, const char *s2);
char* miStrchr(char *s, int c);
char* miStrrchr(char *s, int c);
char* miStrstr(const char *s1, const char *s2);

#endif // FUNCIONESCADENA_H_INCLUDED
