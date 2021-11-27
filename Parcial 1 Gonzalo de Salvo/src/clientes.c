#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "clientes.h"
#include "utn.h"
#include "localidades.h"
#include "direcciones.h"


int menu()
{
    int opcion;

    system("cls");
    printf("        ----Menu pedidos---         \n\n\n");
    printf("1. Dar cliente de alta\n");
    printf("2. Modificar datos del cliente\n");
    printf("3. Dar cliente de baja \n");
    printf("4. Crear pedido de recoleccion\n");
    printf("5. Procesar residuos\n");
    printf("6. Imprimir clientes\n");
    printf("7. Imprimir pedidos pendientes\n");
    printf("8. Imprimir pedidos procesados\n");
    printf("9. Pedidos pendientes por localidad\n");
    printf("10. Mostrar kilos de polipropileno recilados promedio por cliente\n");
    printf("11. Cliente con mas pedidos pendientes \n");
    printf("12. Cliente con mas pedidos completados \n");
    printf("13. Direcciones con pedidos pendientes segun localidad\n");
    printf("14. Salir\n");
    opcion=getInt("Ingrese una opcion: ",1,14);

    return opcion;
}
int iniciarClientes(eCliente* lista, int tam)
{
    int todoOk=-1;
    if(!(lista==NULL||tam>100||tam<1))
    {
        todoOk=0;
        for(int i=0; i<tam; i++)
        {
            lista[i].isEmpty=1;
        }
    }
    return todoOk;
}
int altaCliente(eCliente* listaCli,int tam,eLocalidad* listaLoc, int tamLoc, eDireccion* listaDir, int tamDir, int* pIdCli, int* pIdLoc)
{
    int todoOk=0;
    eCliente auxCli;
    eLocalidad auxLoc;
    eDireccion auxDir;
    int indiceCli=-1;
    int indiceLoc=-1;

    if(listaCli!=NULL && listaLoc!=NULL && listaDir!=NULL && tam>0 && tamLoc>0 && tamDir>0)
    {
        indiceCli=buscarLibreCliente(listaCli,tam);
        indiceLoc=buscarLibreLocalidad(listaLoc,tamLoc);
        if(indiceLoc==-1 && indiceCli ==1)
        {
            printf("No hay mas espacio disponible en el sistema.\n");
        }
        else
        {
            printf("                ***Menu de alta***\n\n");
            auxCli.idCliente= *pIdCli;
            (*pIdCli)++;
            getString("Ingrese el nombre de la empresa: ",auxCli.nombreEmpresa,50);
            getValidCuit("Ingrese el cuit de la empresa(sin - ni espacios): ","Cuit invalido, debe tener 11 numeros sin - ni espacios, ingreselo nuevamente: ",auxCli.cuit);
            getString("Ingrese la localidad en la que se encuentra la empresa: ",auxLoc.localidad,50);
            if(!compararLocalidad(listaLoc, tamLoc, auxLoc.localidad))
            {
                buscarLibreLocalidad(listaLoc, tamLoc);
                auxLoc.idLocalidad = *pIdLoc;
                auxCli.idLocalidad= *pIdLoc;
                (*pIdLoc)++;
            }
            else
            {
                auxLoc.idLocalidad = buscarLocalidadNombre(listaLoc, tamLoc, auxLoc.localidad);
                auxCli.idLocalidad= buscarLocalidadNombre(listaLoc, tamLoc, auxLoc.localidad);
            }
            auxCli.isEmpty=0;
            auxLoc.isEmpty = 0;

            getString("Ingrese la calle: ", auxDir.direccion, 50);
            auxDir.altura = getInt("Ingrese la altura: ", 1, 99999);
            auxDir.idCliente = auxCli.idCliente;

            listaCli[indiceCli] = auxCli;
            listaLoc[indiceLoc] = auxLoc;
            listaDir[indiceCli] = auxDir;

            todoOk = 1;
        }
    }
    return todoOk;
}
int buscarLibreCliente(eCliente* lista, int tam)
{
    int indice = -1;
    if(lista!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(lista[i].isEmpty==1)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}
int menuModificacion()
{
    int opcion;

    printf("1. Modificar localidad\n");
    printf("2. Modificar direccion\n");
    printf("3. Salir\n\n");

    opcion=getInt("Seleccione una opcion: ",1,3);

    return opcion;
}
int modificarCliente(eCliente listaCli[],int tam,eLocalidad listaLoc[], int tamLoc, eDireccion listaDir[], int tamDir, int *pIdLoc)
{
    int todoOk=0;
    int indice=0;
    int id;
    char confirma;
    eDireccion auxDir;
    eLocalidad auxLoc;
    eCliente auxCli;


    if(listaCli!=NULL && tam>0 && listaDir!= NULL && tamDir>0 && listaLoc!=NULL && tamLoc>0)
    {
        system("cls");
        printf("                ***Menu modificacion***\n\n");
        mostrarClientes(listaCli,tam,listaLoc,tamLoc,listaDir,tamDir);
        printf("\n");
        id=getInt("Ingrese id del cliente que desea modificar: ",1,100);
        indice=buscarClientePorId(listaCli,tam,id);
        while(indice==-1)
        {
            id=getInt("Id invalido, por favor ingrese un id correcto: ",1,100);
            indice=buscarClientePorId(listaCli,tam,id);
        }
        printf("Confirma modificacion? (s/n): ");
        fflush(stdin);
        scanf("%c", &confirma);
        while(confirma!='s' && confirma!='n')
        {
            printf("\nRespuesta invalida, Confirma modificacion? (s/n): ");
            fflush(stdin);
            scanf("%c", &confirma);
        }
        while(confirma=='s')
        {
            system("cls");
            printf("                ***Menu modificacion***\n\n");
            mostrarClientes(listaCli,tam,listaLoc,tamLoc,listaDir,tamDir);
            printf("\n\n");
            switch(menuModificacion())
            {
            case 1:
                getString("Ingrese la nueva localidad: ",auxLoc.localidad,50);
                if(!compararLocalidad(listaLoc, tamLoc, auxLoc.localidad))
                {
                    buscarLibreLocalidad(listaLoc, tamLoc);
                    auxLoc.idLocalidad = *pIdLoc;
                    auxCli.idLocalidad= *pIdLoc;
                    (*pIdLoc)++;
                }
                else
                {
                    auxLoc.idLocalidad = buscarLocalidadNombre(listaLoc, tamLoc, auxLoc.localidad);
                    auxCli.idLocalidad= buscarLocalidadNombre(listaLoc, tamLoc, auxLoc.localidad);
                }
                listaCli[indice].idLocalidad=auxCli.idLocalidad;
                listaLoc[indice].idLocalidad=auxLoc.idLocalidad;
                strcpy(listaLoc[indice].localidad,auxLoc.localidad);
                todoOk=1;
                break;
            case 2:
                getString("Ingrese la nueva calle: ", auxDir.direccion,50);
                auxDir.altura = getInt("Ingrese la nueva altura: ",1,99999);
                strcpy(listaDir[indice].direccion, auxDir.direccion);
                listaDir[indice].altura = auxDir.altura;
                todoOk=1;
                break;
            case 3:
                if(todoOk==1)
                {
                    printf("Modificacion exitosa! Saliendo del menu de modificacion\n");
                    confirma='n';
                }
                else
                {
                    printf("Regresando al menu principal\n");
                    confirma='n';
                    todoOk=2;
                }
                break;
            }

        }

    }
    return todoOk;
}
void mostrarCliente(eCliente cliente, eLocalidad* localidades, int tamLoc, eDireccion* direcciones, int tamDir)
{
    char strLocalidad[50];
    eDireccion auxDireccion=cargarDireccionId(direcciones,tamDir,cliente.idCliente);
    cargarDescripcionLocalidad(localidades,tamLoc,cliente.idLocalidad,strLocalidad);

    printf(" |  %5d   |    %-20s     |    %10s   |      %-25s      |        %-25s %-5d    |\n",cliente.idCliente,cliente.nombreEmpresa,cliente.cuit,strLocalidad,auxDireccion.direccion,auxDireccion.altura);

}
int mostrarClientes(eCliente clientes[],int tamCli, eLocalidad* localidades, int tamLoc, eDireccion* direcciones, int tamDir)
{
    int todoOK = 0;
    int flag = 1;
    printf(" |Id cliente|    Nombre de la empresa     |      Cuit        |            Localidad                |                  Direccion                |\n");
    if(clientes!=NULL && localidades!=NULL && direcciones!=NULL && tamCli>0 && tamLoc>0 && tamDir>0)
    {
        for(int i=0; i<tamCli; i++)
        {
            if(clientes[i].isEmpty==0)
            {
                mostrarCliente(clientes[i],localidades,tamLoc,direcciones,tamDir);
                flag=0;
            }
        }
        todoOK = 1;
        if(flag)
        {
            printf("No hay clientes para mostrar\n");
        }
    }
    return todoOK;
}
int buscarClientePorId(eCliente lista[], int tam, int id)
{
    int indice = -1;
    if(lista!=NULL && tam>0)
    {
        for (int i=0; i<tam; i++)
        {
            if(!lista[i].isEmpty && lista[i].idCliente==id)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}
int bajaCliente(eCliente listaCli[],int tam,eLocalidad listaLoc[], int tamLoc, eDireccion listaDir[], int tamDir)
{
    int todoOk=0;
    int indice=0;
    int id;
    char confirma;


    if(listaCli!=NULL && tam>0 && listaDir!= NULL && tamDir>0 && listaLoc!=NULL && tamLoc>0)
    {
        system("cls");
        printf("            ***Menu de baja***\n\n");
        mostrarClientes(listaCli,tam,listaLoc,tamLoc,listaDir,tamDir);
        id=getInt("Ingrese el ID del cliente a dar de baja: ",1,100);
        indice=buscarClientePorId(listaCli,tam,id);
        while(indice==-1)
        {
            id=getInt("Id invalido, por favor ingrese un id correcto: ",1,100);
            indice=buscarClientePorId(listaCli,tam,id);
        }
        printf("Confirma baja? (s/n): ");
        fflush(stdin);
        scanf("%c", &confirma);
        while(confirma!='s' && confirma!='n')
        {
            printf("\nRespuesta invalida, Confirma baja? (s/n): ");
            fflush(stdin);
            scanf("%c", &confirma);
        }
        if(confirma=='s')
        {
            listaCli[indice].isEmpty = 1;
            if(compararLocalidad(listaLoc, tamLoc, listaLoc[indice].localidad))
            {
                listaLoc[indice].isEmpty=1;

            }
            printf("\nBaja exitosa!\n\n");
            todoOk = 1;
        }
        else
        {
            printf("\nSe ha cancelado la baja\n\n");
        }
    }
    return todoOk;
}

