#include <iostream>
#include "ArchivoAsistencia.h"

using namespace std;

ArchivoAsistencia::ArchivoAsistencia(){}

ArchivoAsistencia::ArchivoAsistencia(string nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
}

bool ArchivoAsistencia::guardarAsistencia(Asistencia asistencia)
{
    bool guardo;
    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "ab");

    if(pArchivo == nullptr)
    {
        return false;
    }

    guardo = fwrite(&asistencia, sizeof(Asistencia), 1, pArchivo);

    fclose(pArchivo);

    return guardo;
}

bool ArchivoAsistencia::guardarAsistencia(Asistencia asistencia, int posicion)
{
    bool guardo;
    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb+");

    if(pArchivo == nullptr)
    {
        return false;
    }

    fseek(pArchivo, sizeof(Asistencia) * posicion, SEEK_SET);

    guardo = fwrite(&asistencia, sizeof(Asistencia), 1, pArchivo);

    fclose(pArchivo);

    return guardo;
}

int ArchivoAsistencia::buscarAsistencia(int idSocio)
{
    int posicion = 0;
    Asistencia asistencia;

    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr)
    {
        return -1;
    }

    while(fread(&asistencia, sizeof(Asistencia), 1, pArchivo))
    {
        if(asistencia.getIdSocio() == idSocio)
        {
            fclose(pArchivo);
            return posicion;
        }
        posicion++;
    }

    fclose(pArchivo);

    return -1;
}

Asistencia ArchivoAsistencia::leerRegistroAsistencia(int posicion)
{
    Asistencia asistencia;

    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr)
    {
        return Asistencia();
    }

    fseek(pArchivo, sizeof(Asistencia) * posicion, SEEK_SET);

    fread(&asistencia, sizeof(Asistencia), 1, pArchivo);

    fclose(pArchivo);

    return asistencia;
}

int ArchivoAsistencia::cantidadRegistrosAsistencias()
{
    int cantidad;

    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr)
    {
        return -1;
    }

    fseek(pArchivo, 0, SEEK_END);

    cantidad = ftell(pArchivo) / sizeof(Asistencia);

    fclose(pArchivo);

    return cantidad;
}

void ArchivoAsistencia::leerRegistrosAsistencia(int cantidadRegistros, Asistencia *vecAsistencia)
{
    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr)
    {
        return;
    }

    for(int i = 0; i < cantidadRegistros; i++)
    {
        fread(&vecAsistencia[i], sizeof(Asistencia), 1, pArchivo);
    }

    fclose(pArchivo);
}
