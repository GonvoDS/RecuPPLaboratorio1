#ifndef FILTROS_H_INCLUDED
#define FILTROS_H_INCLUDED
#include "pedidos.h"
#include "clientes.h"
#include "localidades.h"


#endif // FILTROS_H_INCLUDED
/** \brief Muestra la localidad con mas pedidos pendientes
 *
 * \param listaCli eCliente*
 * \param tamCli int
 * \param listaPed ePedido*
 * \param tamPed int
 * \param listaLoc eLocalidad*
 * \param tamLoc int
 * \return int 0 en caso de error 1 en caso de exito
 *
 */
int localidadPedidosPendientes(eCliente* listaCli,int tamCli,ePedido* listaPed,int tamPed,eLocalidad* listaLoc,int tamLoc);
/** \brief Muestra un promedio entre el pp reciclado y la cantidad de clientes que procesaron los residuos
 *
 * \param listaCli eCliente*
 * \param tamCli int
 * \param listaPed ePedido*
 * \param tamPed int
 * \return int retorna 0 en caso de error 1 en caso de exito
 *
 */
int cantidadDePPReciclado(eCliente* listaCli,int tamCli,ePedido* listaPed,int tamPed);
/** \brief Indica el cliente que mas posee pedidos en el estado que se le fue indicado en la variable correspondiente
 *
 * \param listaCli eCliente*
 * \param tamCli int
 * \param listaPed ePedido*
 * \param tamPed int
 * \param estado int
 * \return int retorna 0 en caso de error, 1 en caso de exito
 *
 */
int clienteConMasPedidosEstado(eCliente* listaCli,int tamCli, ePedido* listaPed,int tamPed,int estado);
/** \brief Muestra las direcciones de los clientes con pedidos pendientes segun la localidad que se le indica
 *
 * \param listaCli eCliente*
 * \param tamCli int
 * \param listaPed ePedido*
 * \param tamPed int
 * \param listaLoc eLocalidad*
 * \param tamLoc int
 * \param listaDir eDireccion*
 * \param tamDir int
 * \return int 0 en caso de error 1 o mas en caso de exito
 *
 */
int direccionPedidosPendientes(eCliente* listaCli,int tamCli,ePedido* listaPed,int tamPed,eLocalidad* listaLoc,int tamLoc,eDireccion* listaDir,int tamDir);
