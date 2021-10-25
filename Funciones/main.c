#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>


//#include "funciones.h"
#define TAM 5

typedef struct
{
    int id;
    char procesador[20];
    char marca[20];
    int precio;
}eNotebook;

float aplicarDescuento(float precioProducto);

int contarCaracteres(char cadena[], char caracter);

int main()
{

    float producto;
    char cadena[20];
    char caracter;

    eNotebook notebook[TAM] =
    {
        {0, "Celeron", "Intel", 5000},
        {1, "Ryzen 5", "AMD", 7000},
        {2, "I 5", "Intel", 10000},
        {3, "I 3", "Intel", 6000},
        {4, "FX 8350", "AMD", 55000}
    };

    printf("Ingrese el valor de un producto al que desea descontarle un 5%%: ");
    scanf("%f", &producto);

    printf("%.2f", aplicarDescuento(producto));


    printf("\nIngrese una cadena y luego un caracter, para comparar: ");
    __fpurge(stdin);
    scanf("%s", cadena);
    __fpurge(stdin);
    scanf("%c", &caracter);

    printf("%d", contarCaracteres(cadena, caracter));

    for(int i = 0; i < TAM; i++)
    {
        printf("%d, %s, %s , %d",
               notebook[i].id,
               notebook[i].procesador,
               notebook[i].marca,
               notebook[i].precio);
    }


    return 0;
}









float aplicarDescuento(float precioProducto)
{
    int porcDesc = 5;
    float descuento;
    float precioProductoDescuento;

    if(precioProducto > 0)
    {
        descuento = (float) porcDesc / 100;
        precioProducto -= (precioProducto * descuento);
        precioProductoDescuento = precioProducto;
    }
    return precioProductoDescuento;
}




int contarCaracteres(char cadena[], char caracter)
{
    int contador = 0;
    int cantCaracteres;

    if(cadena != NULL)
    {
        cantCaracteres = strlen(cadena);
        for(int i = 0; i < cantCaracteres; i++)
        {
            if(cadena[i] == caracter)
            {
                contador++;
            }
        }
    }
    return contador;
}

int ordenarPorMarca(eNotebook notebooks[], int tam)
{
    int retorno = 0;
    eNotebook auxNotebook;

    if(notebooks != NULL && tam > 0)
    {
        for(int i = 0; i < tam - 1; i++)
        {
            for(int j = i + 1; j < tam; j++)
            {
                if( notebooks[i].marca > notebooks[j].marca ||
                (notebooks[i].marca == notebooks[j].marca && notebooks[i].precio > notebooks[j].precio))
                {
                    strcpy(auxNotebook.marca, notebooks[i].marca);
                    strcpy(notebooks[i].marca, notebooks[j].marca);
                    strcpy(notebooks[j].marca, auxNotebook.marca);
                }
            }
        }
        retorno = 1;
    }
    return retorno;
}






































