#include "empleado.h"
void generarEmpleadosDePrueba()
{
    TEmpleado empleados1[10] = {
        {1, "Ventas", "Juan Perez", 50000.0},{2, "Compras", "Maria Lopez", 55000.0},{3, "Recursos Humanos", "Carlos Gomez", 60000.0},
        {4, "Produccion", "Ana Martinez", 58000.0},{5, "Finanzas", "Pedro Sanchez", 62000.0},
        {6, "Marketing", "Lucia Fernandez", 56000.0},{7, "IT", "Jose Torres", 65000.0},{8, "Logistica", "Laura Diaz", 53000.0},
        {9, "Legal", "Santiago Ruiz", 61000.0},{10, "Calidad", "Marta Hernandez", 59000.0}};
    TEmpleado empleados2[10] = {
        {11, "Ventas", "Javier Morales", 52000.0},{12, "Compras", "Sofia Garcia", 57000.0},{13, "Recursos Humanos", "Diego Rojas", 61000.0},
        {14, "Produccion", "Carla Romero", 59000.0},{15, "Finanzas", "Andres Gutierrez", 63000.0},{16, "Marketing", "Paula Suarez", 57000.0},
        {17, "IT", "Roberto Vega", 66000.0},{18, "Logistica", "Alejandra Mendoza", 54000.0},{19, "Legal", "Fernando Navarro", 62000.0},
        {20, "Calidad", "Natalia Ortega", 60000.0}};

    TEmpleado empleados3[10] = {
        {21, "Ventas", "Oscar Aguirre", 53000.0},{22, "Compras", "Marta Rivera", 58000.0},{23, "Recursos Humanos", "Eduardo Chavez", 62000.0},
        {24, "Produccion", "Veronica Silva", 60000.0},{25, "Finanzas", "Francisco Reyes", 64000.0},{26, "Marketing", "Gabriela Ponce", 58000.0},
        {27, "IT", "Hector Morales", 67000.0},{28, "Logistica", "Elena Espinoza", 55000.0},{29, "Legal", "Ivan Delgado", 63000.0},
        {30, "Calidad", "Mariana Castro", 61000.0}};
    TEmpleado empleados4[10] = {
        {31, "Ventas", "Luis Herrera", 54000.0},{32, "Compras", "Adriana Ramos", 59000.0},{33, "Recursos Humanos", "Jorge Medina", 63000.0},
        {34, "Produccion", "Patricia Soto", 61000.0},{35, "Finanzas", "Miguel Torres", 65000.0},{36, "Marketing", "Raquel Ramirez", 59000.0},
        {37, "IT", "Felipe Ortiz", 68000.0},{38, "Logistica", "Claudia Lara", 56000.0},{39, "Legal", "Victor Flores", 64000.0},
        {40, "Calidad", "Silvia Sanchez", 62000.0}};

    TEmpleado empleados5[10] = {
        {41, "Ventas", "Sergio Vega", 55000.0},{42, "Compras", "Gloria Fernandez", 60000.0},{43, "Recursos Humanos", "Ramon Ramos", 64000.0},
        {44, "Produccion", "Cecilia Guzman", 62000.0},{45, "Finanzas", "Pablo Torres", 66000.0},{46, "Marketing", "Lucia Vargas", 60000.0},
        {47, "IT", "Ignacio Mendez", 69000.0},{48, "Logistica", "Teresa Herrera", 57000.0},{49, "Legal", "Julio Castillo", 65000.0},
        {50, "Calidad", "Emilia Reyes", 63000.0}};
    TEmpleado empleados6[10] = {
        {51, "Ventas", "Alejandro Nunez", 56000.0},{52, "Compras", "Vanesa Palacios", 61000.0},{53, "Recursos Humanos", "Roberto Martinez", 65000.0},
        {54, "Produccion", "Daniela Soto", 63000.0},{55, "Finanzas", "Victor Marquez", 67000.0},{56, "Marketing", "Carolina Diaz", 61000.0},
        {57, "IT", "Ricardo Villalba", 70000.0},{58, "Logistica", "Sandra Figueroa", 58000.0},{59, "Legal", "Enrique Peralta", 66000.0},
        {60, "Calidad", "Patricia Blanco", 64000.0}};

    FILE* pf1 = fopen("../Empleados1.dat","wb");
    if(!pf1)
    {
        return;
    }
    FILE* pf2 = fopen("../Empleados2.dat","wb");
    if(!pf2)
    {
        fclose(pf1);
        return;
    }
    FILE* pf3 = fopen("../Empleados3.dat","wb");
    if(!pf3)
    {
        fclose(pf1);
        fclose(pf2);
        return;
    }
    FILE* pf4 = fopen("../Empleados4.dat","wb");
    if(!pf4)
    {
        fclose(pf1);
        fclose(pf2);
        fclose(pf3);
        return;
    }
    FILE* pf5 = fopen("../Empleados5.dat","wb");
    if(!pf5)
    {
        fclose(pf1);
        fclose(pf2);
        fclose(pf3);
        fclose(pf4);
        return;
    }
    FILE* pf6 = fopen("../Empleados6.dat","wb");
    if(!pf6)
    {
        fclose(pf1);
        fclose(pf2);
        fclose(pf3);
        fclose(pf4);
        fclose(pf5);
        return;
    }

    fwrite(empleados4,sizeof(empleados4),1,pf3);
    fwrite(empleados1,sizeof(empleados1),1,pf5);
    fwrite(empleados3,sizeof(empleados3),1,pf1);
    fwrite(empleados2,sizeof(empleados2),1,pf6);
    fwrite(empleados5,sizeof(empleados5),1,pf4);
    fwrite(empleados6,sizeof(empleados5),1,pf2);

    fclose(pf1);
    fclose(pf2);
    fclose(pf3);
    fclose(pf4);
    fclose(pf5);
    fclose(pf6);
}
int compararLegajo(void*a,void*b)
{
    TFiles *tfilesA = (TFiles *)a;
    TFiles *tfilesB = (TFiles *)b;
    TEmpleado *tempA = (TEmpleado*)tfilesA->regInicial;
    TEmpleado *tempB = (TEmpleado*)tfilesB->regInicial;
    return tempA->legajo-tempB->legajo;
}
void mostrarEmpleado(void*a)
{
    TEmpleado* pa = (TEmpleado*)a;
    printf("%06d|%-19s|%-20s|%.2f\n",pa->legajo,pa->departamento,pa->nomApe,pa->salario);
}
void mostrarEncabezadoEmpleado()
{
    printf("LEGAJO|   DEPARATAMENTO   |NOMBRE Y APELLIDO   |SALARIO\n");
}
