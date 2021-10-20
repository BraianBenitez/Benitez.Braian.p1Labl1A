#include <stdio.h>
#include <stdlib.h>

#include "fecha.h"
#include "tipo.h"
#include "color.h"
#include "bicicleta.h"
#include "servicio.h"
#include "trabajo.h"
#include "funciones.h"

int menuPrincipal()
{
    int opcion;

    system("cls");
    printf("           *** ABM BICICLETAS***           \n");
    printf("----------------------------------------\n");
    printf("    1- Alta Bicicleta\n");
    printf("    2- Modificar Bicicleta\n");
    printf("    3- Baja Bicicleta\n");
    printf("    4- Listar Bicicletas\n");
    printf("    5- Listar Tipos\n");
    printf("    6- Listar Colores\n");
    printf("    7- Listar Servicios\n");
    printf("    8- Alta Trabajo\n");
    printf("    9- Listar Trabajos\n");
    printf("    10- Salir\n\n");

    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int buscarLibre(eBicicleta lista[], int tam)
{
    int indice = -1;

    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int menuBicicletas()
{
    int opcion;

    printf("Seleccione el numero correspondiente al campo que desea modificar\n");
    printf("1-  Tipo\n");
    printf("2-  Rodado\n");

    scanf("%d", &opcion);

    return opcion;
}

int inicializarBicicletas(eBicicleta lista[], int tam)
{
    int retorno = 0;

    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            lista[i].isEmpty = 1;
        }
        retorno = 1;
    }
    return retorno;
}

/*int modificarPersona(ePersona lista[], int tam, eLocalidad localidades[], int tamLoc)
{
    int retorno = 0;
    int id;
    int indice;
    char confirmacion;
    char auxNombre[20];
    char auxSexo;
    int auxEdad;
    float auxAltura;

    if(lista != NULL && tam > 0)
    {
        printf("Ingrese ID de la persona que desea modificar: ");
        scanf("%d", &id);
        indice = buscarPersona(lista, tam, id);
        if(indice == -1)
        {
            printf("No se encuentra ese ID en el sistema\n");
        }
        else
        {
            mostrarPersona(lista[indice], localidades, tamLoc);
            printf("Confirma la modificacion? (s/n): ");
            fflush(stdin);
            scanf("%c", &confirmacion);
            confirmacion = tolower(confirmacion);

            if(confirmacion == 's')
            {
                switch(menuModificar())
                {
                case 1:
                    printf("Ingrese nuevo nombre: ");
                    fflush(stdin);
                    gets(auxNombre);
                    strcpy(lista[indice].nombre, auxNombre);
                    break;
                case 2:
                    printf("Ingrese nuevo sexo: ");
                    fflush(stdin);
                    scanf("%c", &auxSexo);
                    lista[indice].sexo = auxSexo;
                    break;
                case 3:
                    printf("Ingrese nueva edad: ");
                    scanf("%d", &auxEdad);
                    lista[indice].edad = auxEdad;
                    break;
                case 4:
                    printf("Ingrese nueva altura: ");
                    scanf("%f", &auxAltura);
                    lista[indice].altura = auxAltura;
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
*/
