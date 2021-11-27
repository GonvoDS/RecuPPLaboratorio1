#ifndef LOCALIDADES_H_INCLUDED
#define LOCALIDADES_H_INCLUDED

typedef struct
{   int idLocalidad;
    char localidad[50];
    int isEmpty;
}eLocalidad;

#endif // LOCALIDADES_H_INCLUDED
/** \brief Inicia las localidades poniendo su campo isEmpty en 1
 *
 * \param lista eLocalidad*
 * \param tam int
 * \return int -1 en caso de error 0 en caso de exito
 *
 */
int iniciarLocalidades(eLocalidad* lista, int tam);
/** \brief Busca una localidad en las inicializadas que tenga su campo isEmpty en 1
 *
 * \param lista eLocalidad*
 * \param tam int
 * \return int -1 en caso de no encontrar ninguna, el indice del campo que se encontro en caso de ser exitosa la busqueda
 *
 */
int buscarLibreLocalidad(eLocalidad* lista, int tam);
/** \brief Compara una localidad que se le pasa con el resto de localidades cargadas en la estructura
 *
 * \param lista eLocalidad*
 * \param tam int
 * \param localidad char*
 * \return int 0 si no se encuentra la misma, 1 si se encuentra una coincidencia
 *
 */
int compararLocalidad(eLocalidad* lista, int tam, char* localidad);
/** \brief Se le pasa un string a la funcion y se compara con uno de los campos de la estructura
 *
 * \param lista eLocalidad*
 * \param tam int
 * \param localidad char*
 * \return int 0 en caso de error, el id de la localidad encontrada en caso de exito
 *
 */
int buscarLocalidadNombre(eLocalidad* lista, int tam, char* localidad);
/** \brief Carga la variable localidad de la estructura eLocalidad y la carga en el puntero
 *
 * \param lista eLocalidad*
 * \param tam int
 * \param idLocalidad int
 * \param descripcion char*
 * \return int 0 en caso de fallo 1 en caso de exito
 *
 */
int cargarDescripcionLocalidad(eLocalidad* lista, int tam, int idLocalidad, char* descripcion);
/** \brief Pide el nombre de una localidad y las compara con el resto de localidades cargadas en la estructura
 *
 * \param lista eLocalidad*
 * \param tamLoc int
 * \param localidad char*
 * \return int 0 en caso de que no se encuentre o haya un error el id de la localidad en caso de exito
 *
 */
int pedirLocalidad(eLocalidad* lista,int tamLoc,char* localidad);
/** \brief Muestra las localidades junto con su id
 *
 * \param lista eLocalidad*
 * \param tamLoc int
 * \return int 0 en caso de error 1 en caso de exito
 *
 */
int mostrarLocalidades(eLocalidad* lista, int tamLoc);
/** \brief Busca una localidad mediante el id que se le paso
 *
 * \param lista eLocalidad*
 * \param tam int
 * \param id int
 * \return int -1 en caso de error, el indice de la localidad en caso de encontrar una coincidencia
 *
 */
int buscarLocalidadPorId(eLocalidad* lista, int tam, int id);
