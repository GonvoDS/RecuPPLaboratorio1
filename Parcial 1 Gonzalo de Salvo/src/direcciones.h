#ifndef DIRECCIONES_H_INCLUDED
#define DIRECCIONES_H_INCLUDED
typedef struct
{
    int idCliente;
    char direccion[50];
    int altura;
} eDireccion;


#endif // DIRECCIONES_H_INCLUDED
/** \brief carga un auxiliar con los datos de la estructura en el id que se le paso
 *
 * \param lista eDireccion*
 * \param tam int
 * \param idCliente int
 * \return eDireccion retorna un auxiliar de la estructura con los datos de la misma
 *
 */
eDireccion cargarDireccionId(eDireccion* lista,int tam,int idCliente);
