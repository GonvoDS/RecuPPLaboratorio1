#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define TamCli 100
#define TamPed 1000
#define TamLoc 100
#define TamDir 100
#include "clientes.h"
#include "localidades.h"
#include "pedidos.h"
#include "direcciones.h"
#include "filtros.h"

int main(void)
{
    setbuf(stdout,NULL);
    int opcion;
    int idCliente=1;
    int idLocalidad=1000;
    int idPedido=1;
    int flagAlta=0;
    int check=0;
    int salir=0;
    int flagPedido=0;
    eCliente listaClientes[TamCli];
    ePedido listaPedidos[TamPed];
    eLocalidad listaLocalidades[TamLoc];
    eDireccion listaDirecciones[TamDir];


    iniciarClientes(listaClientes,TamCli);
    iniciarPedidos(listaPedidos, TamPed);
    iniciarLocalidades(listaLocalidades,TamLoc);

    do
    {
        opcion=menu();

        switch(opcion)
        {
        case 1:
            system("cls");
            check=altaCliente(listaClientes,TamCli,listaLocalidades,TamLoc,listaDirecciones,TamDir,&idCliente,&idLocalidad);
            if(check==1)
            {
                printf("Cliente dado de alta con exito!\n");
                flagAlta=1;
            }
            else
            {
                printf("No se pudo dar de alta al cliente\n");
            }
            break;
        case 2:
            system("cls");
            if(flagAlta==1)
            {
                check=modificarCliente(listaClientes, TamCli, listaLocalidades, TamLoc, listaDirecciones, TamDir, &idLocalidad);
                if(check==1)
                {
                    printf("Cliente modificado con exito\n");
                }
                else if(check==2)
                {
                    printf("Modifiacion cancelada\n");
                }
                else
                {
                    printf("No se pudo modificar el cliente\n");
                }
            }
            else
            {
                printf("Aun no hay clientes cargados\n");
            }
            break;
        case 3:
            if(flagAlta==1)
            {
                system("cls");
                check=bajaCliente(listaClientes, TamCli, listaLocalidades, TamLoc, listaDirecciones, TamDir);
                if(check==1)
                {
                    printf("El cliente fue dado de baja con exito!\n");
                }
            }
            else
            {
                printf("Aun no hay clientes cargados\n");
            }
            break;
        case 4:
            if(flagAlta==1)
            {
                system("cls");
                check=agregarPedido(listaPedidos,TamPed,listaClientes,TamCli,listaLocalidades,TamLoc,listaDirecciones,TamDir,&idPedido);
                if(check==1)
                {
                    flagPedido=1;
                    printf("Pedido creado con exito!\n");
                }
            }
            else
            {
                printf("Aun no hay clientes cargados\n");
            }
            break;
        case 5:
            flagPedido=verificarEstadoPedidos(listaPedidos,TamPed,0);
            if(flagPedido==1)
            {
                system("cls");
                check=procesarResiduos(listaPedidos,TamPed,listaClientes,TamCli);
                if(check==1)
                {
                    printf("Pedido procesado correctamente\n");
                }

            }
            else
            {
                printf("Aun no se han creado pedidos\n");
            }
            break;
        case 6:
            if(flagAlta==1)
            {
                system("cls");
                mostrarClientesPedidoPendientes(listaClientes,TamCli,listaPedidos,TamPed,listaLocalidades,TamLoc,listaDirecciones,TamDir);
            }
            else
            {
                printf("Aun no se han cargado clientes\n");
            }
            break;
        case 7:
            flagPedido=verificarEstadoPedidos(listaPedidos,TamPed,0);
            if(flagPedido==1)
            {
                system("cls");
                mostrarPedidosPendientes(listaPedidos,TamPed,listaClientes,TamCli,listaDirecciones,TamDir);
            }
            else
            {
                printf("Aun no se han creado pedidos\n");
            }
            break;
        case 8:
            flagPedido=verificarEstadoPedidos(listaPedidos,TamPed,1);
            if(flagPedido==1)
            {
                system("cls");
                mostrarPedidosProcesados(listaPedidos,TamPed,listaClientes,TamCli,listaDirecciones,TamDir);
            }
            else
            {
                printf("Aun no hay pedidos procesados\n");
            }
            break;
        case 9:
            system("cls");
            flagPedido=verificarEstadoPedidos(listaPedidos,TamPed,0);
            if(flagPedido==1)
            {
                localidadPedidosPendientes(listaClientes,TamCli,listaPedidos,TamPed,listaLocalidades,TamLoc);
            }
            else
            {
                printf("Aun no hay pedidos creados\n");
            }

            break;
        case 10:
            flagPedido=verificarEstadoPedidos(listaPedidos,TamPed,1);
            if(flagPedido==1)
            {
                system("cls");
                cantidadDePPReciclado(listaClientes,TamCli,listaPedidos,TamPed);
            }
            else
            {
                printf("Aun no hay pedidos procesados\n");
            }
            break;
        case 11:
            if(flagAlta==1)
            {
                system("cls");
                clienteConMasPedidosEstado(listaClientes,TamCli,listaPedidos,TamPed,0);
            }
            else
            {
                printf("Aun no se han cargado clientes\n");
            }
            break;
        case 12:
            if(flagAlta==1)
            {
                system("cls");
                clienteConMasPedidosEstado(listaClientes,TamCli,listaPedidos,TamPed,1);
            }
            else
            {
                printf("Aun no se han cargado clientes\n");
            }
            break;
        case 13:
            if(flagAlta==1)
            {
                system("cls");
            direccionPedidosPendientes(listaClientes,TamCli,listaPedidos,TamPed,listaLocalidades,TamLoc,listaDirecciones,TamDir);
            }
            else{
                printf("Aun no se han cargado clientes\n");
            }
            break;
        case 14:
            printf("Gracias por utilizar nuestro programa!\n");
            salir=1;
            break;

        }
        system("pause");
    }
    while(salir!=1);

    return EXIT_SUCCESS;
}
