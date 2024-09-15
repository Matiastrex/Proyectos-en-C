#include "funcionesAlumno.h"

void mostrarEncabezado()
{
    printf("%-10s|%-25s|%-10s|%s|%-10s|%3s|%3s|%-10s|%s|%-10s\n","DNI","Apellido y nombre","NACIMIENTO","S"," INGRESO","CAR",
           "APR","ULTIMA APR","E","FECHA BAJA");
}

int generarArchivoDePruebaAlumnosParte1(const char* nomAlu)
{
    AlumnoEscritura reg[CANT_REGISTROS_PRUEBA1]=
    {
        {20002, "Perez#diaz joSe", "02/02/1991", 'F', "02/02/2011", "ELE", 30, "02/02/2021"},
        {10001, "giUliano Juan Carlos", "01/01/1990", 'M', "01/01/2010", "INF", 20, "01/01/2020"},
        {90009, "Rossi)#Mariano", "01/01/2005", 'M', "01/01/2011", "FIL", 106},
        {30003, "GonZAlEz mArIA", "45/12/1980", 'X', "15/01/2030", "XYZ", -5, "01/13/2015"},
        {70007, "Garcia MatIas", "31/12/2022", 'M', "31/12/2010", "DER", 0},
        {40004, "Torres&lISandro MaTiAs", "29/02/2021", 'F', "29/02/2022", "ECO", 100},
        {10010, "ValDez#% JuAn", "30/02/2022", 'F', "30/02/2021", "ECO", 55, "01/01/2022"},
        {50005, "fERNandeZ joSEFIna", "01/01/1970", 'M', "01/01/2075", "IND", 999, "01/01/2076"},
        {60006, "lEGuiZamon JuAn", "15/05/1988", 'F', "01/01/1990", "XYZ", 10, "01/01/1992"},
        {80008, "&/$&", "29/02/2011", 'F', "29/02/2020", "ADM", 99, "01/01/2022"},
    };

    FILE* alumnos = fopen(nomAlu,"wt");
    if(alumnos==NULL)
    {
        printf("Error para abrir/crear el archivo\n");
        return 0;
    }
    for(int i=0;i<CANT_REGISTROS_PRUEBA1;i++)
        fprintf
        (
            alumnos,
            "%ld|%s|%s|%c|%s|%s|%d|%s\n",
            reg[i].dni,
            reg[i].apeNom,
            reg[i].fecNac,
            reg[i].sexo,
            reg[i].fecIng,
            reg[i].carrera,
            reg[i].matAprob,
            reg[i].fecUltMatAprob
        );
    fclose(alumnos);
    return 1;
}

int generarArchivoDePruebaAlumnosParte2(const char* nomAlu)
{
    Alumno vecAlu[CANT_REGISTROS_PRUEBA2] = {
        {111111111, "Juan Perez", {1, 1, 1990}, 'M', {1, 1, 2020}, "INF", 5, {1, 1, 2022}, 'A', {0, 0, 0}},
        {222222222, "Maria Gomez", {2, 2, 1995}, 'F', {2, 2, 2021}, "MED", 4, {2, 2, 2023}, 'A', {0, 0, 0}},
        {1515151515, "Alejandro Torres", {15, 15, 1990}, 'M', {15, 15, 2022}, "PSI", 6, {15, 15, 2022}, 'A', {0, 0, 0}},
        {333333333, "Carlos Rodriguez", {3, 3, 1993}, 'M', {3, 3, 2019}, "DER", 6, {3, 3, 2022}, 'I', {0, 0, 0}},
        {555555555, "Luis Martinez", {5, 5, 1991}, 'M', {5, 5, 2022}, "ARQ", 7, {5, 5, 2023}, 'A', {0, 0, 0}},
        {444444444, "Ana Lopez", {4, 4, 1992}, 'F', {4, 4, 2020}, "PSI", 3, {4, 4, 2021}, 'A', {0, 0, 0}},
        {666666666, "Laura Fernandez", {6, 6, 1994}, 'F', {6, 6, 2020}, "MED", 5, {6, 6, 2022}, 'A', {0, 0, 0}},
        {777777777, "Martin Sanchez", {7, 7, 1993}, 'M', {7, 7, 2019}, "DER", 4, {7, 7, 2021}, 'I', {0, 0, 0}},
        {1212121212, "Carolina Lopez", {12, 12, 1993}, 'F', {12, 12, 2019}, "DER", 6, {12, 12, 2021}, 'I', {0, 0, 0}},
        {888888888, "Silvia Torres", {8, 8, 1990}, 'F', {8, 8, 2020}, "INF", 6, {8, 8, 2022}, 'A', {0, 0, 0}},
        {999999999, "Javier Perez", {9, 9, 1995}, 'M', {9, 9, 2021}, "ARQ", 3, {9, 9, 2023}, 'A', {0, 0, 0}},
        {1010101010, "Marta Garcia", {10, 10, 1992}, 'F', {10, 10, 2020}, "PSI", 7, {10, 10, 2022}, 'A', {0, 0, 0}},
        {1111111111, "Diego Martinez", {11, 11, 1991}, 'M', {11, 11, 2022}, "INF", 4, {11, 11, 2023}, 'A', {0, 0, 0}},
        {1313131313, "Pedro Sanchez", {13, 13, 1994}, 'M', {13, 13, 2020}, "ARQ", 5, {13, 13, 2022}, 'A', {0, 0, 0}},
        {1414141414, "Elena Fernandez", {14, 14, 1995}, 'F', {14, 14, 2021}, "MED", 4, {14, 14, 2023}, 'A', {0, 0, 0}},
    };

    FILE* alumnos = fopen(nomAlu,"wb");
    if(alumnos==NULL)
    {
        printf("Error para abrir/crear el archivo\n");
        return 0;
    }

    fwrite(vecAlu,sizeof(Alumno),CANT_REGISTROS_PRUEBA2,alumnos);

    fclose(alumnos);
    return 1;
}

int procesarRegistros()
{
    ///////////////////INGRESO DE FECHA DE PROCESO///////////////////////
    Fecha fecProc;
    ingresarFecha(&fecProc);
    printf("Fecha de proceso: %d/%d/%d\n",fecProc.d,fecProc.m,fecProc.a);

    ///////////////////INGRESO DEL PATH DEL ARCHIVO .TXT///////////////////////
    char pathArch[TAM_PATH_ARCH];
    ingresarPathArchivo(pathArch);
    printf("El path del archivo es: %s\n",pathArch);

    FILE* alumnos = fopen(pathArch,"rt");
    if(alumnos==NULL)
    {
        printf("Error para abrir el archivo de origen\n");
        return ERR_ARCH;
    }

    //////EXTENSION .DAT AL ARCHIVO ALUMNOS//////
    char nomBin[TAM_PATH_IND];
    strcpy(nomBin,convertirExtension(pathArch,".dat"));

    FILE* archOK = fopen(nomBin,"wb");
    if(archOK==NULL)
    {
        printf("Error para abrir/crear el archivo procesado\n");
        fclose(alumnos);
        return ERR_ARCH;
    }

    FILE* archError = fopen("AlumnosErrores.txt","wt");
    if(archError==NULL)
    {
        printf("Error para abrir/crear el archivo de error \n");
        fclose(alumnos);
        fclose(archOK);
        return ERR_ARCH;
    }

    /////////VARIABLES PARA GESTIONAR CADA REGISTRO////////
    Alumno reg;
    char apeNomNormalizado[TAM_APYN+1];
    char linea[TAM_LINEA];
    bool errorFatal = false;
    int codRet;
    ///////VARIABLES PARA LA CARGA DEL INDICE////////
    Indice ind;
    RegIndice regInd;
    int contReg=1;
    ind_crear(&ind);


    fgets(linea,TAM_LINEA,alumnos);
    while(!errorFatal&&!feof(alumnos))
    {
        alumnoTxtARegBin(linea,&reg,&errorFatal);
        codRet=validarAlumno(&reg,&fecProc);

        if(codRet==TODO_OK)
        {
            //////CARGA AL ARCHIVO BINARIO///////
            normalizaApeNom(reg.apeNom,apeNomNormalizado);
            strcpy(reg.apeNom,apeNomNormalizado);
            escribirAlumnoABinario(archOK,&reg);
            /////CARGA AL INDICE EN MEMORIA////////
            regInd.dni=reg.dni;
            regInd.nro_reg=contReg;
            contReg++;
            ind_insertar(&ind,&regInd);
        }
        else
        {
            escribirAlumnoATexto(archError,&reg);
        }

        fgets(linea,TAM_LINEA,alumnos);
    }

    char pathInd[TAM_PATH_ARCH];
    strcpy(pathInd,convertirExtension(pathArch,".idx"));
    ind_grabar(&ind,pathInd);


    fclose(alumnos);
    fclose(archOK);
    fclose(archError);
    ind_liberar(&ind);

    return TODO_OK;
}

int alumnoTxtARegBin(char* linea,Alumno* reg,bool* errorFatal)
{
    //BUSQUEDA FIN DE LINEA, SI ES NULL, EL VECTOR LINEA ES CORTO PARA CONTENER LA LINEA//
    char* act = strchr(linea,'\n');
    if(act==NULL)
    {
        *errorFatal=true;
        return ERR_LINEA_LARGA;
    }
    *act='\0';


    //LECTURA FECHA ULTIMA MATERIA APROBADA (PUEDE VENIR EN EL ARCHIVO O NO) //
    int cantPipes = contarCaracteres(linea,'|');
    if(cantPipes==7)
    {
        act=strrchr(linea,'|');
        sscanf(act+1,"%d/%d/%d",&reg->fecUltMatAprob.d,&reg->fecUltMatAprob.m,&reg->fecUltMatAprob.a);
        *act='\0';
    }

    //LECTURA MATERIAS APROBADAS//
    act=strrchr(linea,'|');
    sscanf(act+1,"%d",&reg->matAprob);
    *act='\0';

    //LECTURA CARRERA//
    act=strrchr(linea,'|');
    strncpy(reg->carrera,act+1,TAM_NOM_CARRERA);
    reg->carrera[TAM_NOM_CARRERA]='\0';
    *act='\0';

    //LECTURA FECHA DE INGRESO//
    act=strrchr(linea,'|');
    sscanf(act+1,"%d/%d/%d",&reg->fecIng.d,&reg->fecIng.m,&reg->fecIng.a);
    *act='\0';

    //LECTURA SEXO//
    act=strrchr(linea,'|');
    reg->sexo=*(act+1);
    *act='\0';

    //LECTURA FECHA DE NACIMIENTO//
    act=strrchr(linea,'|');
    sscanf(act+1,"%d/%d/%d",&reg->fecNac.d,&reg->fecNac.m,&reg->fecNac.a);
    *act='\0';

    //LECTURA APELLIDO Y NOMBRE//
    act=strrchr(linea,'|');
    strncpy(reg->apeNom,act+1,TAM_APYN);
    reg->apeNom[TAM_APYN]='\0';
    *act='\0';

    //LECTURA DNI//
    sscanf(linea,"%ld",&reg->dni);

    //UNA VEZ SE CARGO LA FECHA DE INGRESO YA PUEDO CARGARLA COMO FECHA DE ULTIMA MATERIA APROBADA SI NO SE INFORMO
    if(cantPipes<7)
    {
        reg->fecUltMatAprob.d=reg->fecIng.d;
        reg->fecUltMatAprob.m=reg->fecIng.m;
        reg->fecUltMatAprob.a=reg->fecIng.a;
    }

    return TODO_OK;
}
void escribirAlumnoABinario(FILE* arch,const Alumno* reg)
{
    fwrite(reg,sizeof(Alumno),1,arch);
}
void escribirAlumnoATexto(FILE* arch,const Alumno* reg)
{
    fprintf
    (
        arch,
        "%ld|%s|%d/%d/%d|%c|%d/%d/%d|%s|%d|%d/%d/%d\n",
        reg->dni,
        reg->apeNom,
        reg->fecNac.d,
        reg->fecNac.m,
        reg->fecNac.a,
        reg->sexo,
        reg->fecIng.d,
        reg->fecIng.m,
        reg->fecIng.a,
        reg->carrera,
        reg->matAprob,
        reg->fecUltMatAprob.d,
        reg->fecUltMatAprob.m,
        reg->fecUltMatAprob.a
    );
}
int contarCaracteres(const char* str, char c)
{
    char* linea = (char*)str;
    int i=0,contador=0;
    int longitud=strlen(linea);
    while(i<longitud)
    {
        if(*linea==c)
        {
            contador++;
        }
        i++;
        linea++;
    }
    return contador;
}

void ingresarPathArchivo(char* path)
{
    puts("Ingrese el PATH del archivo: ");
    fflush(stdin);
    fgets(path,TAM_PATH_ARCH,stdin);
    int longitud=strlen(path);
    path[longitud-1]='\0';
}

char* agregarExtension(const char* nomArch, char* ext)
{
    char* str = (char*)nomArch;
    strcpy(str+strlen(str),ext);
    return str;
}

char* convertirExtension(char* nomArch, char* ext)
{
    char* str=(char*)nomArch;
    str=strchr(str,'.');
    strcpy(str,ext);
    return nomArch;
}
int menuOperaciones()
{
    ////////////////APERTURA ARCHIVO BINARIO/////////////////
    char pathBin[TAM_PATH_ARCH];
    ingresarPathArchivo(pathBin);

    FILE* archBin = fopen(pathBin,"rb+");
    if(archBin==NULL)
    {
        printf("Error al abrir el archivo binario\n");
        return ERR_ARCH;
    }

    ////////////////APERTURA ARCHIVO INDICE/////////////////
    char pathIdx[TAM_PATH_ARCH];
    strcpy(pathIdx,convertirExtension(pathBin,".idx"));

    Indice ind;
    ind_crear(&ind);
    if(ind_cargar(&ind,pathIdx)==0)
    {
        return ERR_ARCH;
    }
    Fecha fecProc;
    ingresarFecha(&fecProc);

    int opcion;
    do{
        system("cls");
        printf("Fecha de proceso: %d/%d/%d\n",fecProc.d,fecProc.m,fecProc.a);
        printf("//////////////////////////////////////MENU PRINCIPAL//////////////////////////////////////\n");
        printf("1. Efectuar mantenimiento (altas, bajas)\n");
        printf("2. Listar los registros dados de baja\n");
        printf("3. Listar los registros en orden (sin los dados de baja)\n");
        printf("4. Salir\n");

        printf("Selecciona una opcion: ");
        scanf("%d", &opcion);
        switch (opcion)
        {
            int subopcion;
            case 1:
                do{
                    system("cls");
                    printf("Fecha de proceso: %d/%d/%d\n",fecProc.d,fecProc.m,fecProc.a);
                    printf("//////////////////////////////////////MANTENIMIENTO///////////////////////////////////////\n");
                    printf("1. Alta\n");
                    printf("2. Baja\n");
                    printf("3. Volver atras\n");
                    printf("Selecciona una opcion: ");
                    scanf("%d", &subopcion);
                    switch (subopcion)
                    {
                        case 1:
                            procesarAlta(archBin,&ind,&fecProc);
                            system("pause");
                            break;
                        case 2:
                            procesarBaja(archBin,&ind,&fecProc);
                            system("pause");
                            break;
                        case 3:
                            printf("Volviendo al menu principal.\n");
                            break;
                        default:
                            printf("Opcion no valida en el submenu de Mantenimiento.\n");
                            system("pause");
                            break;
                    }
                } while (subopcion != 3);
                  break;

            case 2:
                system("cls");
                listarBajas(archBin,&fecProc);
                system("pause");
                break;
            case 3:
                system("cls");
                listarActivos(archBin,&fecProc);
                system("pause");
                break;
            case 4:
                system("cls");
                printf("SALIENDO DEL PROGRAMA...\n");
                break;
            default:
                printf("Opcion no valida. Intentalo de nuevo\n");
                system("pause");
                break;
        }

      }while(opcion!=4);
    ind_grabar(&ind,pathIdx);
    ind_liberar(&ind);
    fclose(archBin);
    return OPERACION_OK;
}

void listarBajas(FILE* archBin,Fecha* fecProc)
{
    Alumno alu;
    printf("Fecha de proceso: %d/%d/%d\n",fecProc->d,fecProc->m,fecProc->a);
    printf("//////////////////////////////////////LISTA DE BAJAS///////////////////////////////////////\n");
    mostrarEncabezado();

    fread(&alu,sizeof(alu),1,archBin);
    while(!feof(archBin))
    {
        if(alu.estado=='B')
        {
            printf
            (
                "%-10ld|%-25s|%02d/%02d/%04d|%c|%02d/%02d/%02d|%s|%03d|%02d/%02d/%04d|%c|%02d/%02d/%04d\n",
                alu.dni,alu.apeNom,alu.fecNac.d,alu.fecNac.m,alu.fecNac.a,
                alu.sexo,alu.fecIng.d,alu.fecIng.m,alu.fecIng.a,alu.carrera,
                alu.matAprob,alu.fecUltMatAprob.d,alu.fecUltMatAprob.m,
                alu.fecUltMatAprob.a,alu.estado,alu.fecBaja.d,alu.fecBaja.m,
                alu.fecBaja.a
            );
        }
        fread(&alu,sizeof(alu),1,archBin);
    }
    rewind(archBin);
}

int listarActivos(FILE* archBin,Fecha* fecProc)
{
    fseek(archBin,0L,SEEK_END);
    int ce = ftell(archBin)/sizeof(Alumno);
    fseek(archBin,0L,SEEK_SET);

    Alumno* i = malloc(ce*sizeof(Alumno));
    if(i==NULL)
    {
        printf("Sin memoria disponible para trabajar...\n");
        return ERR_MEM;
    }

    Alumno* alu = i;
    Alumno* ult = alu+ce-1;
    printf("Fecha de proceso: %d/%d/%d\n",fecProc->d,fecProc->m,fecProc->a);
    printf("//////////////////////////////////////LISTA DE ACTIVOS///////////////////////////////////////\n");
    mostrarEncabezado();
    fread(alu,sizeof(Alumno),ce,archBin);
    listaOrdenar(alu,ce);

    while(alu<=ult)
    {
        if(alu->estado!='B')
        {
          printf
            (
                "%-10ld|%-25s|%02d/%02d/%04d|%c|%02d/%02d/%04d|%s|%03d|%02d/%02d/%04d|%c|%02d/%02d/%04d\n",
                alu->dni,alu->apeNom,alu->fecNac.d,alu->fecNac.m,alu->fecNac.a,
                alu->sexo,alu->fecIng.d,alu->fecIng.m,alu->fecIng.a,alu->carrera,
                alu->matAprob,alu->fecUltMatAprob.d,alu->fecUltMatAprob.m,
                alu->fecUltMatAprob.a,alu->estado,alu->fecBaja.d,alu->fecBaja.m,
                alu->fecBaja.a
            );
        }
        alu++;
    }
    free(i);
    rewind(archBin);
    return TODO_OK;
}
void intercambioAlumnos(Alumno* a, Alumno* b)
{
    Alumno aluTemp;
    aluTemp=*a;
    *a=*b;
    *b=aluTemp;
}
void listaOrdenar(Alumno* alu, int ce)
{
    Alumno* ult = alu+ce-1;
    Alumno* m;
    for(Alumno* i=alu;i<ult;i++)
    {
        m = buscarMenorDni(i,ult);
        intercambioAlumnos(i,m);
    }
}

Alumno* buscarMenorDni(Alumno* ini,Alumno* fin)
{
    Alumno* m = ini;
    for(Alumno* j=ini+1;j<=fin;j++)
    {
        if(j->dni<m->dni)
            m=j;
    }
    return m;
}

int procesarAlta(FILE* archBin,Indice* ind,Fecha* fecProc)
{
    int codRet;
    Alumno alu;
    RegIndice reg;
    codRet=ingresarDatosAlta(ind,&alu,&reg,fecProc);
    if(codRet!=VALID_OK)
    {
        return VALID_ERROR;
    }
    reg.nro_reg=ind->ce+1;
    fseek(archBin,ind->ce*sizeof(Alumno),SEEK_SET);
    escribirAlumnoABinario(archBin,&alu);
    ind_insertar(ind,&reg);
    rewind(archBin);
    printf("Alumno dado de alta correctamente...\n");
    return codRet;
}

int ingresarDatosAlta(Indice* ind,Alumno* alu,RegIndice* reg, Fecha* fecProc)
{
    puts("Ingresar DNI del alumno a realizar su alta: ");
    scanf("%ld",&alu->dni);
    reg->dni=alu->dni;

    while(ind_buscar(ind,reg)==OPERACION_OK)
    {
        puts("DNI ya existe. Ingrese nuevamente\n");
        scanf("%ld",&alu->dni);
        reg->dni=alu->dni;
    }

    fflush(stdin);
    puts("Ingrese Apellido y nombre: ");
    fgets(alu->apeNom,TAM_APYN,stdin);

    puts("Ingrese Fecha de nacimiento(D/M/A): ");
    scanf("%d/%d/%d",&alu->fecNac.d,&alu->fecNac.m,&alu->fecNac.a);

    fflush(stdin);
    puts("Ingrese Sexo(F/M): ");
    scanf("%c",&alu->sexo);

    puts("Ingrese Fecha de Ingreso(D/M/A): ");
    scanf("%d/%d/%d",&alu->fecIng.d,&alu->fecIng.m,&alu->fecIng.a);

    fflush(stdin);
    puts("Ingrese carrera: ");
    fgets(alu->carrera,TAM_NOM_CARRERA+1,stdin);

    fflush(stdin);
    puts("Ingrese cantidad de materias aprobadas: ");
    scanf("%d",&alu->matAprob);

    fflush(stdin);
    puts("Ingrese Fecha de aprobacion de la ultima materia(D/M/A): ");
    scanf("%d/%d/%d",&alu->fecUltMatAprob.d,&alu->fecUltMatAprob.m,&alu->fecUltMatAprob.a);

    if(validarAlumno(alu,fecProc)==VALID_ERROR)
    {
        printf("Se ingreso algun dato erroneo. Vuelva a iniciar el proceso\n");
        return VALID_ERROR;
    }
    char apeNomNormalizado[TAM_APYN+1];
    normalizaApeNom(alu->apeNom,apeNomNormalizado);
    strcpy(alu->apeNom,apeNomNormalizado);

    alu->estado='R';
    alu->fecBaja.d=31;
    alu->fecBaja.m=12;
    alu->fecBaja.a=9999;

    return VALID_OK;
}

int procesarBaja(FILE* archBin, Indice* ind, Fecha* fecProc)
{
    int codRet;
    Alumno alu;
    RegIndice reg;
    codRet=ingresarDatosBaja(ind,&alu,&reg);
    if(codRet!=TODO_OK)
    {
        return ERR_DNI;
    }
    buscarDatosAlumnoPorDni(archBin,&alu,ind->ce);
    if(alu.estado!='B')
    {
        alu.estado='B';
        alu.fecBaja.d=fecProc->d;
        alu.fecBaja.m=fecProc->m;
        alu.fecBaja.a=fecProc->a;
    }
    else
    {
        printf("Ese DNI corresponde a un alumno dado de baja.\n");
        return ERR_DNI;
    }
    fseek(archBin,(reg.nro_reg-1)*sizeof(Alumno),SEEK_SET);
    escribirAlumnoABinario(archBin,&alu);
    ind_eliminar(ind,&reg);
    rewind(archBin);
    printf("Alumno dado de baja correctamente...\n");
    return TODO_OK;
}
int ingresarDatosBaja(Indice* ind,Alumno* alu,RegIndice* reg)
{
    puts("Ingresar DNI del alumno a realizar su baja: ");
    scanf("%ld",&alu->dni);
    reg->dni=alu->dni;
    if(ind_buscar(ind,reg)!=OPERACION_OK)
    {
        puts("DNI inexistente\n");
        return ERR_DNI;
    }
    return TODO_OK;
}
int buscarDatosAlumnoPorDni(FILE* arch,Alumno* alu,int ce)
{
    Alumno* ini = malloc(ce*sizeof(Alumno));
    if(ini==NULL)
    {
        printf("Sin memoria disponible para trabajar...\n");
        return ERR_MEM;
    }
    Alumno* i = ini;
    Alumno* ult = ini+ce-1;

    fread(i,sizeof(Alumno),ce,arch);

    while(i<=ult&&alu->dni!=i->dni)
        i++;
    if(i==ult+1)
        return ERR_FUERA_RANGO;
    else
    {
        strcpy(alu->apeNom,i->apeNom);
        alu->fecNac.d=i->fecNac.d;
        alu->fecNac.m=i->fecNac.m;
        alu->fecNac.a=i->fecNac.a;
        alu->sexo=i->sexo;
        alu->fecIng.d=i->fecIng.d;
        alu->fecIng.m=i->fecIng.m;
        alu->fecIng.a=i->fecIng.a;
        strcpy(alu->carrera,i->carrera);
        alu->matAprob=i->matAprob;
        alu->fecUltMatAprob.d=i->fecUltMatAprob.d;
        alu->fecUltMatAprob.m=i->fecUltMatAprob.m;
        alu->fecUltMatAprob.a=i->fecUltMatAprob.a;
        alu->estado=i->estado;
        return TODO_OK;
    }
    free(ini);
    rewind(arch);
}
