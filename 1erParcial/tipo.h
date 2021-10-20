#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eTipo;

#endif // TIPO_H_INCLUDED

int validarIdTipo(eTipo tipos[], int tam, int idIngresado);

int mostrarTipos(eTipo tipos[], int tam);
