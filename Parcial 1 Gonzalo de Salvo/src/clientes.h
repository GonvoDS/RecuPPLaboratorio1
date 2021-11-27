#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#include "localidades.h"
#include "direcciones.h"


typedef struct
{
    int idCliente;
    char nombreEmpresa[50];
    char cuit[15];
    int idLocalidad;
    int isEmpty;
} eCliente;

#endif // CLIENTES_H_INCLUDED
/** \brief muestra el menu principal del programa
 *
 * \return int retorna la opcion seleccionada
 *
 */
int menu();
/** \brief inicia los clientes poniendo su estado isEmpty a 1
 *
 * \param lista eCliente*
 * \param tam int
 * \return int retorna -1 en caso de error 0 en caso de poder inicializar la estructura
 *
 */
int iniciarClientes(eCliente* lista, int tam);
/** \brief Da un cliente de alta y lo carga en la estructura, rellenando sus campos y cambiando el campo isEmpty a 0
 *
 * \param listaCli eCliente*
 * \param tam int
 * \param listaLoc eLocalidad*
 * \param tamLoc int
 * \param listaDir eDireccion*
 * \param tamDir int
 * \param pIdCli int*
 * \param pIdLoc int*
 * \return int retorna 0 en caso de no poder dar de alta un cliente y 1 en caso de que el alta sea exitosa
 *
 */
int altaCliente(eCliente* listaCli,int tam,eLocalidad* listaLoc, int tamLoc, eDireccion* listaDir, int tamDir, int* pIdCli, int* pIdLoc);
/** \brief Busca un espacio en la estructura eCliente que tenga la variable isEmpty en 1
 *
 * \param lista eCliente*
 * \param tam int
 * \return int retorna -1 en caso de error y el indice del espacio libre en caso de exito
 *
 */
int buscarLibreCliente(eCliente* lista, int tam);
/** \brief Menu para la funcion de modificacion
 *
 * \return int la opcion seleccionada dentro del menu
 *
 */
int menuModificacion();
/** \brief Permite modificar la localidad y la direccion de un cliente ingresado
 *
 * \param listaCli[] eCliente
 * \param tam int
 * \param listaLoc[] eLocalidad
 * \param tamLoc int
 * \param listaDir[] eDireccion
 * \param tamDir int
 * \param pIdLoc int*
 * \return int retorna 0 en caso de no confirmar la modificacion 1 si la modificacion es exitosa y 2 si se cancela la modificacion sin cambios
 *
 */
int modificarCliente(eCliente listaCli[],int tam,eLocalidad listaLoc[], int tamLoc, eDireccion listaDir[], int tamDir, int *pIdLoc);
/** \brief Muestra un cliente
 *
 * \param cliente eCliente
 * \param localidades eLocalidad*
 * \param tamLoc int
 * \param direcciones eDireccion*
 * \param tamDir int
 * \return void
 *
 */
void mostrarCliente(eCliente cliente, eLocalidad* localidades, int tamLoc, eDireccion* direcciones, int tamDir);
/** \brief Muestra los clientes que se encuentren en la estructura encolumnados
 *
 * \param clientes[] eCliente
 * \param tamCli int
 * \param localidades eLocalidad*
 * \param tamLoc int
 * \param direcciones eDireccion*
 * \param tamDir int
 * \return int retorna 0 en caso de no haber nada para mostrar 1 si puede mostrar
 *
 */
int mostrarClientes(eCliente clientes[],int tamCli, eLocalidad* localidades, int tamLoc, eDireccion* direcciones, int tamDir);
/** \brief Se le pasa un id y busca un otro ID en la estructura que coincida con el que le fue pasado
 *
 * \param lista[] eCliente
 * \param tam int
 * \param id int
 * \return retorna -1 en caso de error o indice en la estructura del elemento que coincide
 *
 */
int buscarClientePorId(eCliente lista[], int tam, int id);
/** \brief Elimina un cliente ya cargado cambiando su campo isEmpty a 1 nuevamente
 *
 * \param listaCli[] eCliente
 * \param tam int
 * \param listaLoc[] eLocalidad
 * \param tamLoc int
 * \param listaDir[] eDireccion
 * \param tamDir int
 * \return int 0 en caso de error o cancelar la baja y 1 en caso de exito
 *
 */
int bajaCliente(eCliente listaCli[],int tam,eLocalidad listaLoc[], int tamLoc, eDireccion listaDir[], int tamDir);

