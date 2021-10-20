#include <stdio.h>
#include <stdlib.h>
#include "color.h"

int validarIdColor(eColor colores[], int tam, int idIngresado)
{
    int retorno = 0;

    if(colores != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(idIngresado == colores[i].id)
            {
                retorno = 1;
                break;
            }
        }
    }
    return retorno;
}

int mostrarColores(eColor colores[], int tam)
{
    int retorno = 0;

    if(colores != NULL && tam > 0)
    {
        printf("    *** Listado de Colores ***    \n");
        printf("----------------------------------------\n");
        for(int i = 0; i < tam; i++)
        {
            printf("  %d -> %10s\n", colores[i].id, colores[i].nombreColor);
        }
        retorno = 1;
    }

    return retorno;
}
