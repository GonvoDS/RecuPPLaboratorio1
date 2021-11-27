#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "pedidos.h"
#include "utn.h"
int iniciarPedidos(ePedido* lista, int tam)
{
    int todoOk=-1;

    if(!(lista==NULL||tam>1000||tam<1))
    {
        todoOk=0;
        for(int i=0; i<tam; i++)
        {
            lista[i].estado=-1;
        }
    }
    return todoOk;
}
int buscarLibrePedido(ePedido* lista, int tam)
{
    int indice = -1;
    if(lista!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(lista[i].estado==-1)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}
int agregarPedido(ePedido* listaPed,int tamPed,eCliente listaCli[],int tam,eLocalidad listaLoc[], int tamLoc, eDireccion listaDir[], int tamDir, int *pIdPed)
{
    int todoOk=0;
    int idCliente;
    int indiceCli;
    int indicePed;
    ePedido auxPedido;

    indicePed=buscarLibrePedido(listaPed,tamPed);
    if(listaCli!=NULL)
    {
        printf("                    ***Carga de pedido***\n\n\n");
        mostrarClientes(listaCli,tam,listaLoc,tamLoc,listaDir,tamDir);
        idCliente=getInt("\n\nIngrese el ID del cliente que realiza el pedido: ",1,100);
        indiceCli=buscarClientePorId(listaCli,tam,idCliente);
        while(indiceCli==-1)
        {
            idCliente=getInt("Id invalido, por favor ingrese un id correcto",1,100);
            indiceCli=buscarClientePorId(listaCli,tam,idCliente);
        }
        auxPedido.idCliente=idCliente;
        auxPedido.idPedido= *pIdPed;
        (*pIdPed)++;
        auxPedido.kilos=getFloat("Ingrese la cantidad de kilos a recolectar: ",1,10000000);
        auxPedido.estado=0;
        listaPed[indicePed]=auxPedido;
        todoOk=1;
    }


    return todoOk;
}
int verificarEstadoPedidos(ePedido* lista, int tam, int estado)
{
    int todoOk=0;

    for (int i=0; i<tam; i++)
    {
        if(lista[i].estado == estado)
        {
            todoOk=1;
            break;
        }
    }

    return todoOk;
}
void mostrarPedidos(ePedido* listaPed,int tam,int estado)
{
    printf("|    ID pedido    |     ID empresa       |       Kilos recolectados    |\n");
    if(listaPed!=NULL)
    {
        for(int i = 0; i<tam; i++)
        {
            if(listaPed[i].estado==estado)
            {
                printf("|   %5d         |      %5d           |      %-20.3f   |\n",listaPed[i].idPedido,listaPed[i].idCliente,listaPed[i].kilos);
            }
        }
    }
}
int buscarPedidoPorId(ePedido lista[], int tam, int id)
{

    int indice = -1;
    if(lista!=NULL && tam>0)
    {
        for (int i=0; i<tam; i++)
        {
            if(lista[i].estado==0 && lista[i].idPedido==id)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}
int procesarResiduos(ePedido* listaPed,int tamPed, eCliente* listaCli, int tamCli)
{
    int todoOk=0;
    int id;
    int indice;
    int flag=0;
    if(listaPed!=NULL && listaCli!=NULL)
    {
        mostrarPedidos(listaPed,tamPed,0);
        id=getInt("Ingrese numero de ID del pedido a procesar: ",1,1000);
        indice=buscarPedidoPorId(listaPed,tamPed,id);
        while(indice==-1)
        {
            id=getInt("Id incorrecto, por favor ingrese el ID correspondiente al pedido a procesar: ",1,1000);
            indice=buscarPedidoPorId(listaPed,tamPed,id);
        }
            do
            {
                listaPed[indice].kilosReciclados[0] = getFloat("Ingrese la cantidad de kilos de HDPE: ",0,10000000);
                listaPed[indice].kilosReciclados[1] = getFloat("Ingrese la cantidad de kilos de LPDE: ",0,10000000);
                listaPed[indice].kilosReciclados[2] = getFloat("Ingrese la cantidad de kilos de PP: ",0,10000000);
                listaPed[indice].kilosReciclados[3] = listaPed[indice].kilos - (listaPed[indice].kilosReciclados[0]+listaPed[indice].kilosReciclados[1]+listaPed[indice].kilosReciclados[2]);
                if(listaPed[indice].kilosReciclados[3]<0 || listaPed[indice].kilosReciclados[3]>0)
                {
                    printf("Cantidad de Kilos invalido, es distinta a los kilos recolectados\n");
                }
                else
                {
                    flag=1;
                    listaPed[indice].estado=1;
                    todoOk=1;
                }

            }
            while(flag==0);
    }
    return todoOk;
}
int mostrarClientesPedidoPendientes(eCliente clientes[],int tamCli,ePedido pedidos[],int tamPed, eLocalidad* localidades, int tamLoc, eDireccion* direcciones, int tamDir)
{
    int todoOk=0;
    char strLocalidad[50];
   int pendientes;

    printf("                        ***Listado de clientes***\n\n\n");
    for(int i=0; i<tamCli; i++)
    {
        if(clientes[i].isEmpty==0)
        {
            eDireccion auxDireccion=cargarDireccionId(direcciones,tamDir,clientes[i].idCliente);
            cargarDescripcionLocalidad(localidades,tamLoc,clientes[i].idLocalidad,strLocalidad);
            todoOk=1;
            pendientes=0;
            printf("\nID: %d\n",clientes[i].idCliente);
            printf("Nombre de la empresa: %s\n",clientes[i].nombreEmpresa);
            printf("Cuit: %s\n",clientes[i].cuit);
            printf("Localidad: %s\n",strLocalidad);
            printf("Direccion: %s %d\n",auxDireccion.direccion,auxDireccion.altura);

            for(int j=0; j<tamPed; j++)
            {
                if(pedidos[j].idCliente==clientes[i].idCliente && pedidos[j].estado==0)
                {
                    pendientes++;
                }

            }
           printf("Cantidad de pedidos pendientes: %d\n",pendientes);

        }
    }
    return todoOk;
}
int mostrarPedidosPendientes(ePedido listaPed[],int tamPed,eCliente listaCli[],int tamCli,eDireccion listaDir[],int tamDir)
{
    int todoOk=0;
    eDireccion auxDireccion[tamDir];
    printf("                            ***Pedidos pendientes***                \n\n\n");
    printf("|         CUIT            |              DIRECCION               | KILOS A RECOLECTAR |\n");
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
                    printf("|       %10s       |         %-20s %-5d   |       %5.2f     |\n",listaCli[j].cuit,auxDireccion[j].direccion,auxDireccion[j].altura,listaPed[i].kilos);
                }

            }
        }
    }
    return todoOk;
}
int mostrarPedidosProcesados(ePedido listaPed[],int tamPed,eCliente listaCli[],int tamCli,eDireccion listaDir[],int tamDir)
{
    int todoOk=0;
    eDireccion auxDireccion[tamDir];
    printf("                            ***Pedidos procesados***                \n\n\n");
    printf("|         CUIT           |               DIRECCION               |     KILOS DE HDPE       |     KILOS DE LDPE       |       KILOS DE PP       |\n");
    for(int i=0; i<tamPed; i++)
    {
        if(listaPed[i].estado==1)
        {
            for(int j=0; j<tamCli; j++)
            {
               auxDireccion[j]=cargarDireccionId(listaDir,tamDir,listaCli[j].idCliente);
                if(listaCli[j].idCliente == listaPed[i].idCliente && listaCli[j].isEmpty == 0)
                {
                    todoOk=1;
                    printf("|       %10s      |     %-20s %-5d        |         %5.3f         |         %5.3f         |         %5.3f         |\n",listaCli[j].cuit,auxDireccion[j].direccion,auxDireccion[j].altura,listaPed[i].kilosReciclados[0],listaPed[i].kilosReciclados[1],listaPed[i].kilosReciclados[2]);
                }

            }
        }
    }
    return todoOk;
}
