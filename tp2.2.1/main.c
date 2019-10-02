#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 1000
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} eEmployee;

int modifyEmploye(eEmployee vec[], int tam);
eEmployee newEmployee(int id,char name[],char lastName[],float salary,int sector);
int searchFree(eEmployee vec[], int len);
int addEmployees(eEmployee listEmployees[], int len,int lastId);
int initEmployees(eEmployee list[], int len);
int findEmpleyeesById(eEmployee vec[],int len, int id);
int removeEmployees(eEmployee list[],int len,int id);
int printEmployees(eEmployee vec[],int len);
int printEmployee(eEmployee x,int len);
int menu();
int main()
{
    eEmployee listEmployees[TAM];
    initEmployees(listEmployees, TAM);
    int lastId = 1;
    int respuesta;
    char next = 's';
    do
    {
        switch (menu())
        {
        case 1:
            respuesta = addEmployees(listEmployees, TAM, lastId);
            if(respuesta)
            {
                lastId++;
            }
            break;
        case 2:
             modifyEmploye(listEmployees,TAM);
            break;
        case 3:
            break;
        case 4:
            printEmployees(listEmployees,TAM);
            break;
        default:
            printf("opcion incorrecta, reintente\n");
        }

    }
    while (next != 'n');
    return 0;

    printf("¿Desea continuar? S o N\n");
    fflush(stdin);
    scanf("%c",&next);
    system("cls");

}
int menu()
{

    int opcion;
    printf("**** EMPLEADOS ****\n\n");
    printf("1-ALTAS\n");
    printf("2-MODIFICAR\n");
    printf("3-BAJA\n");
    printf("4-INFORMAR\n");
    scanf("%d", &opcion);
    return opcion;
}
eEmployee newEmployee(int id,char name[51],char lastName[51],float salary,int sector)
{
    eEmployee al;

    al.id = id;
    strcpy(al.name, name);
    strcpy(al.lastName, lastName);
    al.salary = salary;
    al.sector = sector;
    al.isEmpty = 0;

    return al;
}
int addEmployees(eEmployee vec[], int len,int lastId)
{
    int todoOk = -1;
    int id;
    int indice;
    char name[51];
    char lastName[51];
    float salary;
    int sector;


    system("cls");
    printf("****ALTA DE EMPLEADOS****\n\n");
    indice = searchFree(vec,len);

    if(indice == -1)
    {
        printf("\nSISTEMA COMPLETO\n\n");
    }
    else
    {
        printf("Ingrese Nombre\n");
        fflush(stdin);
        gets(name);

        printf("Ingrese Apellido\n");
        fflush(stdin);
        gets(lastName);

        printf("Ingrese Salario\n");
        scanf("%f", &salary);

        printf("Ingrese Sector\n");
        scanf("%d", &sector);
        id=lastId;
        vec[indice] = newEmployee(id,name, lastName,salary,sector);

        todoOk = 1;
        printf("Carga Exitosa\n\n");
    }
    return todoOk;
}
int findEmpleyeesById(eEmployee vec[],int len, int id)
{
    int indice = -1;
    for(int i=0; i<len; i++)
    {
        if( vec[i].id==id && vec[i].isEmpty==0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
int removeEmployees(eEmployee vec[],int len,int id)
{

}
int sortEmployees(eEmployee listEmployees[], int len, int order)
{



}
int printEmployees(eEmployee vec[],int len)
{
    int flag = 0;
    system("cls");
    printf("  ID     NOMBRE      APEllIDO      SALARIO      SECTOR\n\n ");
    for(int i=0; i<len; i++)
    {
        if(vec[i].isEmpty==0)
        {
            printEmployee(vec[i], len);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("\nNo hay empleados que mostrar\n");
    }
    printf("\n\n");


}
int printEmployee(eEmployee x,int len)
{
    printf(" %d      %s        %s        %.2f        %d\n",
           x.id,
           x.name,
           x.lastName,
           x.salary,
           x.sector);
}
int initEmployees(eEmployee vec[], int len)
{
    for(int i=0; i<len; i++)
    {
        vec[i].isEmpty = 1;
    }
}
int searchFree(eEmployee vec[], int len)
{
    int indice = -1;
    for(int i=0; i<len; i++)
    {
        if(vec[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
int modifyEmploye(eEmployee vec[], int len)
{
    int todoOk = 0;
    int lastId;
    int indice;
    int salary;
    int sector;
    printEmployees( vec, len);
    system("cls");
    printf("***** Modificar Empleado*****");
    printf("Ingrese id");
    scanf("%d", &lastId);

    int opcion;


    indice = findEmpleyeesById(vec,len,lastId);

    if(indice == -1)
    {
        printf("No existe el empleado");
    }
    else
    {
        printEmployee(vec[indice],len);
        printf("1- Modificar salario\n");
        printf("2- Modificar sector\n");
        printf("3- Salir\n\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            printf("ingrese nuevo salario: ");
            scanf("%f", &vec[indice].salary);
            //vec[indice].promedio = (float) (vec[indice].nota1  + vec[indice].nota2)/2;
            break;

        case 2:
            printf("Ingrese nuevo sector: ");
            scanf("%d", &vec[indice].sector);
            //vec[indice].promedio = (float) (vec[indice].nota1  + vec[indice].nota2)/2;
            break;
        case 3:
            printf("Se ha cancelado la mofdificacion ");
            break;

        }
    }
    return todoOk;
}






