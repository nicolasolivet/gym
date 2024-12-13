#pragma once

#include "DetalleRutina.h"

class GestionArchivoDetalleRutinas
{
public:

    GestionArchivoDetalleRutinas();
    GestionArchivoDetalleRutinas(std::string nombreArchivo);

    bool guardarDetalleRutina(DetalleRutina detalle);
    bool guardarDetalleRutina(DetalleRutina detalle, int posicion);
    int buscarDetalleRutina(int idRutina);
    DetalleRutina leerRegistroDetalleRutina(int posicion);
    int cantidadRegistrosDetalleRutina();
    void leerRegistrosDetallesRutina(int cantidadRegistros, DetalleRutina *vecDetalleRutina);


private:

    std::string _nombreArchivo;
};
