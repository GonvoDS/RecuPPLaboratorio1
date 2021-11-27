#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "localidades.h"
#include "utn.h"


int iniciarLocalidades(eLocalidad* lista, int tam)
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
int buscarLibreLocalidad(eLocalidad* lista, int tam)
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
int compararLocalidad(eLocalidad* lista, int tam, char* localidad)
{
    int todoOk = 0;
    if(lista!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(strcmp(lista[i].localidad, localidad)==0)
            {
                todoOk = 1;
            }
        }
    }
    return todoOk;
}
int buscarLocalidadNombre(eLocalidad* lista, int tam, char* localidad)
{
    int id = 0;
    if(lista!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(strcmp(lista[i].localidad, localidad)==0)
            {
                id = lista[i].idLocalidad;
            }
        }
    }
    return id;
}
int cargarDescripcionLocalidad(eLocalidad* lista, int tam, int idLocalidad, char* descripcion)
{
    int retorno = 0;

    if(lista!=NULL && tam>0 && descripcion!=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if(lista[i].idLocalidad == idLocalidad)
            {
                strcpy(descripcion, lista[i].localidad);
                break;
            }
        }
        retorno = 1;
    }
    return retorno;
}
int pedirLocalidad(eLocalidad* lista,int tamLoc,char* localidad)
{
    int todoOk=0;
    int comparar;
    mostrarLocalidades(lista,tamLoc);
    getString("Ingrese nombre de la localidad: ",localidad,51);
    for(int i=0; i<tamLoc; i++)
    {
        comparar = strcmp(localidad,lista[i].localidad);
        if(comparar == 0 && lista[i].idLocalidad != -1)
        {
            todoOk = lista[i].idLocalidad;
            break;
        }
    }

    return todoOk;
}
int mostrarLocalidades(eLocalidad* lista, int tamLoc)
{
    int todoOk=0;
    if(lista!=NULL && tamLoc>0)
    {
        printf("                ***Localidades***           \n\n\n");
        printf("|   Id    |         Localidad           |\n");
        for(int i=0; i<tamLoc; i++)
        {
            if(lista[i].isEmpty==0)
            {
                printf("|  %5d  |      %15s        |\n",lista[i].idLocalidad,lista[i].localidad);
            }
        }
        todoOk=1;
    }
    return todoOk;
}
int buscarLocalidadPorId(eLocalidad* lista, int tam, int id)
{
    int indice = -1;
    if(lista!=NULL && tam>0)
    {
        for (int i=0; i<tam; i++)
        {
            if(!lista[i].isEmpty && lista[i].idLocalidad==id)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}
