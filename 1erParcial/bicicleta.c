#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "fecha.h"
#include "tipo.h"
#include "color.h"
#include "bicicleta.h"
#include "servicio.h"
#include "trabajo.h"
#include "funciones.h"

// EN rodado se pone modificar material

int altaBicicleta(eBicicleta lista[], int tam, char marca[], eTipo tipos[], int tamTipo, eColor colores[], int tamColor, char material, int* pId)
{
    system("cls");
    printf("     *** Alta Bicicleta ***      \n");
    printf("--------------------------------\n");
    int retorno = 0;
    int indice;
    eBicicleta auxBicicleta;

    if(lista != NULL && tam > 0 && marca != NULL && tipos != NULL && colores != NULL && pId != NULL)
    {
        indice = buscarLibre(lista, tam);
        if(indice == -1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            auxBicicleta.id = *pId;
            (*pId)++;

            printf("Ingrese Marca: ");
            fflush(stdin);
            gets(auxBicicleta.marca);

            printf("Ingrese ID tipo: ");
            scanf("%d", &auxBicicleta.idTipo);
            while(!validarIdTipo(tipos, tamTipo, auxBicicleta.idTipo))
            {
                printf("El ID ingresado no corresponde a ningun tipo. Intente nuevamente: ");
                scanf("%d", &auxBicicleta.idTipo);
            }

            printf("Ingrese ID color: ");
            scanf("%d", &auxBicicleta.idColor);
            while(!validarIdColor(colores, tamColor, auxBicicleta.idColor))
            {
                printf("El ID ingresado no corresponde a ningun color. Intente nuevamente: ");
                scanf("%d", &auxBicicleta.idColor);
            }

            printf("Ingrese material ('c' Carbono, o 'a' Aluminio): ");
            fflush(stdin);
            scanf("%c", &auxBicicleta.material);
            auxBicicleta.material = tolower(auxBicicleta.material);
            while(auxBicicleta.material != 'c' && auxBicicleta.material != 'a')
            {
                printf("Indice de material no aceptado. Intente nuevamente\n");
                fflush(stdin);
                scanf("%c", &auxBicicleta.material);
                auxBicicleta.material = tolower(auxBicicleta.material);
            }

            auxBicicleta.isEmpty = 0;

            lista[indice] = auxBicicleta;

            retorno = 1;
        }
    }
    return retorno;
}

int cargarDescripcionTipo(eTipo tipos[], int tam, int idTipo, char descripcion[])
{
    int retorno = 0;

    if(tipos != NULL && tam > 0 && descripcion != NULL)
    {

        for(int i = 0; i < tam; i++)
        {
            if(tipos[i].id == idTipo)
            {
                strcpy(descripcion, tipos[i].descripcion);
                break;
            }
        }
        retorno = 1;
    }

    return retorno;
}

int cargarDescripcionColor(eColor colores[], int tam, int idColor, char descripcion[])
{
    int retorno = 0;

    if(colores != NULL && tam > 0 && descripcion != NULL)
    {

        for(int i = 0; i < tam; i++)
        {
            if(colores[i].id == idColor)
            {
                strcpy(descripcion, colores[i].nombreColor);
                break;
            }
        }
        retorno = 1;
    }

    return retorno;
}

void mostrarBicicleta(eBicicleta unaBicicleta, eColor colores[], int tamCol, eTipo tipos[], int tamTipos)
{
    char descColor[20];
    char descTipo[20];

    cargarDescripcionColor(colores, tamCol, unaBicicleta.idColor, descColor);
    cargarDescripcionTipo(tipos, tamTipos, unaBicicleta.idTipo, descTipo);

    printf(" %d  %20s    20%s      %s    %c    \n",
           unaBicicleta.id,
           descColor,
           descTipo,
           unaBicicleta.marca,
           unaBicicleta.material
          );
}

int mostrarBicicletas(eBicicleta lista[], int tam, eColor colores[], int tamCol, eTipo tipos[], int tamTipos)
{
    int retorno = 0;
    int flag = 1;

    if(lista != NULL && tam > 0 && colores != NULL && tamCol > 0 && tipos != NULL && tamTipos > 0)
    {
        system("cls");
        printf("   *** Listado De Bicicletas ***    \n");
        printf("  Id       Marca   Tipo   Color    Material     \n");
        printf("---------------------------------------------\n");
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                mostrarBicicleta(lista[i], colores, tamCol, tipos, tamTipos);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("No hay Bicicletas para mostrar\n");
        }
        retorno = 1;
    }
    return retorno;
}

int buscarBicicleta(eBicicleta lista[], int tam, int id)
{
    int indice = -1;

    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(!lista[i].isEmpty && lista[i].id == id)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int modificarBicicleta(eBicicleta lista[], int tam, eColor colores[], int tamCol, eTipo tipos[], int tamTipo)
{
    int retorno = 0;
    int id;
    int indice;
    char confirmacion;
    char auxTipo[20];
    int auxRodado;

    if(lista != NULL && tam > 0 && colores != NULL && tamCol > 0 && tipos != NULL && tamTipo > 0)
    {
        printf("Ingrese ID de la Bicicleta que desea modificar: ");
        scanf("%d", &id);
        indice = buscarBicicleta(lista, tam, id);
        if(indice == -1)
        {
            printf("No se encuentra ese ID en el sistema\n");
        }
        else
        {
            mostrarBicicleta(lista[indice], colores, tamCol, tipos, tamTipo);
            printf("Confirma la modificacion? (s/n): ");
            fflush(stdin);
            scanf("%c", &confirmacion);
            confirmacion = tolower(confirmacion);

            if(confirmacion == 's')
            {
                switch(menuBicicletas())
                {
                case 1:
                    printf("Ingrese nuevo Tipo: ");
                    fflush(stdin);
                    gets(auxTipo);
                    break;
                case 2:
                    printf("Ingrese nuevo Rodado: ");
                    scanf("%d", &auxRodado);
                    lista[indice].rodado = auxRodado;
                    break;
                default:
                    printf("Opcion invalida\n");
                    break;
                }
                retorno = 1;
            }
        }
    }
    return retorno;
}

int bajaBicicleta(eBicicleta lista[], int tam, eColor colores[], int tamCol, eTipo tipos[], int tamTipos)
{
    int retorno = 0;
    int id;
    int indice;
    char confirmacion;

    if(lista != NULL && tam > 0)
    {
        system("cls");
        printf("    *** Baja Bicicleta ***    \n\n");
        printf("Ingrese ID de la Bicicleta que desea dar de baja: ");
        scanf("%d", &id);

        indice = buscarBicicleta(lista, tam, id);
        if(indice == -1)
        {
            printf("No existe una persona con ese ID");
        }
        else
        {
            mostrarBicicleta(lista[indice], colores, tamCol, tipos, tamTipos);
            printf("Desea confirmar la baja? (s/n) ");
            fflush(stdin);
            scanf("%c", &confirmacion);
            confirmacion = tolower(confirmacion);
            if(confirmacion == 's')
            {
                lista[indice].isEmpty = 1;
                retorno = 1;
            }
        }
    }
    return retorno;
}




