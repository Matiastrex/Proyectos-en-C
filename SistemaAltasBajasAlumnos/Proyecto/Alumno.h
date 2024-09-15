#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

#define TAM_APYN 39
#define TAM_NOM_CARRERA 3

typedef struct
{
    long dni;
    char apeNom[TAM_APYN+1];
    char fecNac[11];
    char sexo;
    char fecIng[11];
    char carrera[TAM_NOM_CARRERA+1];
    int matAprob;
    char fecUltMatAprob[11];
    char estado;
    char fecBaja[11];
}AlumnoEscritura;

typedef struct
{
    long dni;
    char apeNom[TAM_APYN+1];
    Fecha fecNac;
    char sexo;
    Fecha fecIng;
    char carrera[TAM_NOM_CARRERA+1];
    int matAprob;
    Fecha fecUltMatAprob;
    char estado;
    Fecha fecBaja;
}Alumno;

#endif // ALUMNO_H_INCLUDED
