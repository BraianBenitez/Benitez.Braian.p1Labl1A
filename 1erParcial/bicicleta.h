#include "tipo.h"
#include "color.h"

#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED

typedef struct
{
    int id;
    char marca[20];
    int idTipo;
    int idColor;
    char material;
    int isEmpty;
    int rodado;
}eBicicleta;

#endif // BICICLETA_H_INCLUDED

int altaBicicleta(eBicicleta lista[], int tam, char marca[], eTipo tipos[], int tamTipo, eColor colores[], int tamColor, char material, int* pId);

int cargarDescripcionTipo(eTipo tipos[], int tam, int idTipo, char descripcion[]);
int cargarDescripcionColor(eColor colores[], int tam, int idColor, char descripcion[]);
void mostrarBicicleta(eBicicleta unaBicicleta, eColor colores[], int tamCol, eTipo tipos[], int tamTipos);
int mostrarBicicletas(eBicicleta lista[], int tam, eColor colores[], int tamCol, eTipo tipos[], int tamTipos);
int buscarBicicleta(eBicicleta lista[], int tam, int id);

int modificarBicicleta(eBicicleta lista[], int tam, eColor colores[], int tamCol, eTipo tipos[], int tamTipo);

int bajaBicicleta(eBicicleta lista[], int tam, eColor colores[], int tamCol, eTipo tipos[], int tamTipos);
