#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "direcciones.h"


eDireccion cargarDireccionId(eDireccion* lista,int tam,int idCliente)
{
    eDireccion auxDireccion;

    if(lista!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(lista[i].idCliente == idCliente)
            {
                auxDireccion=lista[i];
            }
        }

    }
    return auxDireccion;
}
