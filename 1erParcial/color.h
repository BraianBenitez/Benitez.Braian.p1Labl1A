#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char nombreColor[20];
}eColor;

#endif // COLOR_H_INCLUDED

int validarIdColor(eColor colores[], int tam, int idIngresado);

int mostrarColores(eColor colores[], int tam);
