#include <stdio.h>
#include <stdlib.h>

#include "fecha.h"
#include "tipo.h"
#include "color.h"
#include "bicicleta.h"
#include "servicio.h"
#include "trabajo.h"
#include "funciones.h"

#define TAM 1000
#define TAM_TIP 4
#define TAM_COL 5
#define TAM_SERV 4

int main()
{
    char seguir = 's';
    int nextIdBici = 0;

    eBicicleta lista[TAM];

    eTipo tipos[TAM_TIP] =
    {
        {1000, "Rutera"},
        {1001, "Carrera"},
        {1002, "Mountain"},
        {1003, "BMX"}
    };

    eColor colores[TAM_COL] =
    {
        {5000, "Gris"},
        {5001, "Blanco"},
        {5002, "Azul"},
        {5003, "Negro"},
        {5004, "Rojo"}
    };

    eServicio servicios[TAM_SERV] =
    {
        {20001, "Limpieza", 30},
        {20002, "Parche", 400},
        {20003, "Centrado", 500},
        {20004, "Cadena", 450}
    };

    if(!inicializarBicicletas(lista, TAM))
    {
        printf("Hubo un error al inicializar las bicicletas\n");
    }
    do
    {
        switch(menuPrincipal())
        {
        case 1:
            if(altaBicicleta(lista, TAM, lista->marca, tipos, TAM_TIP, colores, TAM_COL, lista->material, &nextIdBici))
            {
                printf("Alta exitosa\n");
            }
            break;
        case 2:
            if(!modificarBicicleta(lista, TAM, colores, TAM_COL, tipos, TAM_TIP))
            {
                printf("Ocurrio un error al modificar la bicicleta\n");
            }
            else
            {
                printf("Modificacion exitosa\n");
            }
            break;
        case 3:
            if(bajaBicicleta(lista, TAM, colores, TAM_COL, tipos, TAM_TIP))
            {
                printf("Baja realizada con exito\n");
            }
            else
            {
                printf("Ocurrio un error con la baja\n");
            }
            break;
        case 4:
            mostrarBicicletas(lista, TAM, colores, TAM_COL, tipos, TAM_TIP);
            break;
        case 5:
            mostrarTipos(tipos, TAM_TIP);
            break;
        case 6:
            mostrarColores(colores, TAM_COL);
            break;
        case 7:
           mostrarServicios(servicios, TAM_SERV);
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            seguir = 'n';
            break;
        default:
            printf("Opcion invalida\n");
            break;
        }
        system("pause");
    }while(seguir == 's');

    return 0;
}
























