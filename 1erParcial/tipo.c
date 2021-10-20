#include <stdio.h>
#include <stdlib.h>
#include "tipo.h"

int validarIdTipo(eTipo tipos[], int tam, int idIngresado)
{
    int retorno = 0;

    if(tipos != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(idIngresado == tipos[i].id)
            {
                retorno = 1;
                break;
            }
        }
    }
    return retorno;
}

int mostrarTipos(eTipo tipos[], int tam)
{
    int retorno = 0;

    if(tipos != NULL && tam > 0)
    {
        printf("    *** Listado de Tipos ***    \n");
        printf("----------------------------------------\n");
        for(int i = 0; i < tam; i++)
        {
            printf("  %d -> %10s\n", tipos[i].id, tipos[i].descripcion);
        }
        retorno = 1;
    }

    return retorno;
}
