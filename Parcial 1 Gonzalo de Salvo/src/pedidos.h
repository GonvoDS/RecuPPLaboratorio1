#ifndef PEDIDOS_H_INCLUDED
#define PEDIDOS_H_INCLUDED
#define Type 4
#include "clientes.h"
#include "localidades.h"
#include "direcciones.h"
typedef struct
{
    int idPedido;
    int idCliente;
    float kilos;
    float kilosReciclados[Type];
    int estado; // -1 vacio, 0 pendiente, 1 completado

} ePedido;


#endif // PEDIDOS_H_INCLUDED
/** \brief Inicializa los pedidos cambiando el campo estado en su estructura a -1 para indicar que esta vacio
 *
 * \param lista ePedido*
 * \param tam int
 * \return int -1 en caso de error 0 en caso de exito
 *
 */
int iniciarPedidos(ePedido* lista, int tam);
/** \brief Busca el indice del primer espacio en la estructura con el campo isEmpty en 1
 *
 * \param lista ePedido*
 * \param tam int
 * \return int -1 en caso de error, el indice correspondiente en caso de exito
 *
 */
int buscarLibrePedido(ePedido* lista, int tam);
/** \brief Carga un pedido al cliente indicado
 *
 * \param listaPed ePedido*
 * \param tamPed int
 * \param listaCli[] eCliente
 * \param tam int
 * \param listaLoc[] eLocalidad
 * \param tamLoc int
 * \param listaDir[] eDireccion
 * \param tamDir int
 * \param pIdPed int*
 * \return int retorna 0 en caso de error 1 en caso de exito
 *
 */
int agregarPedido(ePedido* listaPed,int tamPed,eCliente listaCli[],int tam,eLocalidad listaLoc[], int tamLoc, eDireccion listaDir[], int tamDir, int *pIdPed);
/** \brief Se le pasa un numero del -1 al 1 mediante la variable estado y la compara con los otros campos estado, si encuentra coincidencia deja de iterar
 *
 * \param lista ePedido*
 * \param tam int
 * \param estado int
 * \return int 0 en caso de error 1 en caso de exito
 *
 */
int verificarEstadoPedidos(ePedido* lista, int tam, int estado);
/** \brief carga la cantidad de kilos reciclados de cada tipo en la variable correspondiente e indica que sea el monto correcto, luego cambia el estado del pedido a 1
 *
 * \param listaPed ePedido*
 * \param tamPed int
 * \param listaCli eCliente*
 * \param tamCli int
 * \return int 0 en caso de error 1 en caso de exito
 *
 */
int procesarResiduos(ePedido* listaPed,int tamPed, eCliente* listaCli, int tamCli);
/** \brief muestra los pedidos
 *
 * \param listaPed ePedido*
 * \param tam int
 * \param estado int
 * \return void
 *
 */
void mostrarPedidos(ePedido* listaPed,int tam,int estado);
/** \brief Busca un pedido por el id correspondiente
 *
 * \param lista[] ePedido
 * \param tam int
 * \param id int
 * \return int retorna -1 en caso de error, el indice correspondiente en caso de exito
 *
 */
int buscarPedidoPorId(ePedido lista[], int tam, int id);
/** \brief Muestra los clientes junto a la cantidad de pedidos pendientes que tienen
 *
 * \param clientes[] eCliente
 * \param tamCli int
 * \param pedidos[] ePedido
 * \param tamPed int
 * \param localidades eLocalidad*
 * \param tamLoc int
 * \param direcciones eDireccion*
 * \param tamDir int
 * \return int 0 en caso de error, 1 en caso de exito
 *
 */
int mostrarClientesPedidoPendientes(eCliente clientes[],int tamCli,ePedido pedidos[],int tamPed, eLocalidad* localidades, int tamLoc, eDireccion* direcciones, int tamDir);
/** \brief muestra los pedidos pendientes con los datos correspondientes
 *
 * \param listaPed[] ePedido
 * \param tamPed int
 * \param listaCli[] eCliente
 * \param tamCli int
 * \param listaDir[] eDireccion
 * \param tamDir int
 * \return int 0 en caso de error 1 en caso de exito
 *
 */
int mostrarPedidosPendientes(ePedido listaPed[],int tamPed,eCliente listaCli[],int tamCli,eDireccion listaDir[],int tamDir);
/** \brief Muestra los pedidos procesados y los datos correspondientes
 *
 * \param listaPed[] ePedido
 * \param tamPed int
 * \param listaCli[] eCliente
 * \param tamCli int
 * \param listaDir[] eDireccion
 * \param tamDir int
 * \return int 0 en caso de error 1 en caso de exito
 *
 */
int mostrarPedidosProcesados(ePedido listaPed[],int tamPed,eCliente listaCli[],int tamCli,eDireccion listaDir[],int tamDir);
