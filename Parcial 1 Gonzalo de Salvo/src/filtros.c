#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "pedidos.h"
#include "clientes.h"
#include "localidades.h"
int localidadPedidosPendientes(eCliente* listaCli,int tamCli,ePedido* listaPed,int tamPed,eLocalidad* listaLoc,int tamLoc)
{
    int todoOk=0;
    char localidad[51];
    int indice;
    int cantidadPendientes=0;
    int flag=0;

    todoOk=pedirLocalidad(listaLoc,tamLoc,localidad);
    if(todoOk==0)
    {
        printf("No se han encontrado pedidos pendientes en esa localidad\n");
    }
    else
    {
        for(int i=0; i<tamCli; i++)
        {
            if(listaCli[i].idLocalidad==todoOk && listaCli[i].isEmpty==0)
            {

                for(int j=0; j<tamLoc; j++)
                {
                    if(listaCli[i].idCliente==listaPed[j].idCliente && listaPed[i].estado==0)
                    {
                    	flag=1;
                        cantidadPendientes++;
                    }
                }
            }
            if(flag==1)
            {
                indice=buscarLocalidadPorId(listaLoc,tamLoc,todoOk);
                printf("En la localidad %s hay %d pedidos pendientes\n",listaLoc[indice].localidad,cantidadPendientes);
            }
            else
            {
                printf("No se han encontrado clientes en %s\n",localidad);
            }
        }

    }



    return todoOk;
}
int cantidadDePPReciclado(eCliente* listaCli,int tamCli,ePedido* listaPed,int tamPed)
{
    int todoOk=0;
    float kilosDePP=0;
    int cantidadClientes=0;
    float promedioPP;
    if(listaCli!=NULL && listaPed!=NULL)
    {
        for(int i=0; i<tamCli; i++)
        {
            if(listaCli[i].isEmpty==0)
            {
                cantidadClientes++;
                kilosDePP+=listaPed[i].kilosReciclados[2];

            }
        }

        todoOk=1;
        promedioPP=kilosDePP/cantidadClientes;
        printf("El promedio de pp reciclado es igual a %2.f entre %d clientes\n",promedioPP,cantidadClientes);
    }
    return todoOk;
}
int clienteConMasPedidosEstado(eCliente* listaCli,int tamCli, ePedido* listaPed,int tamPed,int estado)
{
    int todoOk=0;
    int flag=0;
    int cantidad=0;
    int indice;
    int cantMayor;
    int idMayor;

    for(int i=0; i<tamCli; i++)
    {
        if(listaCli[i].isEmpty==0)
        {
            for(int j=0; j<tamPed; j++)
            {
                if(listaPed[j].idCliente==listaCli[i].idCliente && listaPed[j].estado==estado)
                {
                    cantidad++;
                }
            }
            if(flag==0||cantidad>cantMayor)
            {
                cantMayor=cantidad;
                idMayor=listaCli[i].idCliente;
                flag=1;
            }
        }
    }
    todoOk=1;
    indice=buscarClientePorId(listaCli,tamCli,idMayor);
    if(estado==0 && cantMayor>0)
    {
        printf("El cliente con mas pedidos pendientes es %s con un total de %d\n",listaCli[indice].nombreEmpresa,cantMayor);
    }
    else if(estado==1 && cantMayor>0)
    {
        printf("El cliente con mas pedidos procesados es %s con un total de %d\n",listaCli[indice].nombreEmpresa,cantMayor);
    }
    else if(estado==0 && cantMayor==0)
    {
        printf("No hay clientes con pedidos pendientes\n");
    }
    else if(estado==1 && cantMayor==0)
    {
        printf("No hay clientes con pedidos procesados\n");
    }

    return todoOk;
}
int direccionPedidosPendientes(eCliente* listaCli,int tamCli,ePedido* listaPed,int tamPed,eLocalidad* listaLoc,int tamLoc,eDireccion* listaDir,int tamDir)
{
    int todoOk=0;
    int flagPedidos=0;
    char localidad[51];
    eDireccion auxDireccion[tamDir];

    todoOk=pedirLocalidad(listaLoc,tamLoc,localidad);
    if(todoOk>0)
    {
        flagPedidos=verificarEstadoPedidos(listaPed,tamPed,0);
        if(flagPedidos==1)
        {
            system("cls");
            printf("                    ***Direcciones de recoleccion: ''%s''***            \n\n\n",localidad);
            printf("| ID Pedido   |       Empresa       |          Direccion           |       Kilos a recolectar        |\n");
            for(int i=0; i<tamPed; i++)
            {

                if(listaPed[i].estado==0)
                {
                    for(int j=0; j<tamCli; j++)
                    {
                        if(listaCli[j].idCliente == listaPed[i].idCliente && listaCli[j].isEmpty == 0)
                        {
                            auxDireccion[j]=cargarDireccionId(listaDir,tamDir,listaCli[j].idCliente);
                            todoOk=1;
                            printf("|   %5d    |   %15s   |  %15s%d  |        %5.3f           |\n",listaPed[i].idPedido,listaCli[j].nombreEmpresa,auxDireccion[j].direccion,auxDireccion[j].altura,listaPed[i].kilos);
                        }

                    }
                }

            }
        }
        else
        {
            printf("No hay pedidos pendientes en esa localidad\n");
        }
    }
    return todoOk;
}
