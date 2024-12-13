#include <iostream>

#include "GestionArchivoDetalleRutinas.h"

using namespace std;

GestionArchivoDetalleRutinas::GestionArchivoDetalleRutinas()
{

}

GestionArchivoDetalleRutinas::GestionArchivoDetalleRutinas(string nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
}

bool GestionArchivoDetalleRutinas::guardarDetalleRutina(DetalleRutina detalle)
{
    bool guardo;
    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "ab");

    if(pArchivo == nullptr)
    {
        return false;
    }

    guardo = fwrite(&detalle, sizeof(DetalleRutina), 1, pArchivo);

    fclose(pArchivo);

    return guardo;
}

bool GestionArchivoDetalleRutinas::guardarDetalleRutina(DetalleRutina detalle, int posicion)
{
    bool guardo;
    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb+");

    if(pArchivo == nullptr)
    {
        return false;
    }

    fseek(pArchivo, sizeof(DetalleRutina) * posicion, SEEK_SET);

    guardo = fwrite(&detalle, sizeof(DetalleRutina), 1, pArchivo);

    fclose(pArchivo);

    return guardo;
}

int GestionArchivoDetalleRutinas::buscarDetalleRutina(int idRutina)
{
    int posicion = 0;
    DetalleRutina detalle;

    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr)
    {
        return -1;
    }

    while(fread(&detalle, sizeof(DetalleRutina), 1, pArchivo))
    {
        if(detalle.getIdRutina() == idRutina)
        {
            fclose(pArchivo);
            return posicion;
        }
        posicion++;
    }

    fclose(pArchivo);

    return -1;
}

DetalleRutina GestionArchivoDetalleRutinas::leerRegistroDetalleRutina(int posicion)
{
    DetalleRutina detalle;

    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr)
    {
        return DetalleRutina();
    }

    fseek(pArchivo, sizeof(DetalleRutina) * posicion, SEEK_SET);

    fread(&detalle, sizeof(DetalleRutina), 1, pArchivo);

    fclose(pArchivo);

    return detalle;
}

int GestionArchivoDetalleRutinas::cantidadRegistrosDetalleRutina()
{
    int cantidad;

    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr)
    {
        return -1;
    }

    fseek(pArchivo, 0, SEEK_END);

    cantidad = ftell(pArchivo) / sizeof(DetalleRutina);

    fclose(pArchivo);

    return cantidad;
}

void GestionArchivoDetalleRutinas::leerRegistrosDetallesRutina(int cantidadRegistros, DetalleRutina *vecDetalleRutina)
{
    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr)
    {
        return;
    }

    for(int i = 0; i < cantidadRegistros; i++)
    {
        fread(&vecDetalleRutina[i], sizeof(DetalleRutina), 1, pArchivo);
    }

    fclose(pArchivo);
}
