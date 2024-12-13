#pragma once
#include "Reclamo.h"

class ArchivoReclamos
{
    public:

        ArchivoReclamos();
        ArchivoReclamos(std::string nombreArchivo);
        bool guardarReclamo(const Reclamo &r);
        Reclamo leerReclamo(int pos);
        bool leerTodosReclamos(Reclamo r[], int cant);
        bool modificarReclamo(Reclamo& r, int pos);
        int getCantidadReclamos();
        int buscarReclamo(int pos);

        void leerRegistrosReclamo(int cantidadRegistros, Reclamo *vReclamos);
        int cantidadDeRegistrosPorUsuario(int cantidadRegistros, int idUsuario);
        int leerRegistrosPorUsuario(int cantidadRegistros, int vectReclamos[], int tam, int idUsuario);

    private:

        std::string _nombreArchivo;
};
