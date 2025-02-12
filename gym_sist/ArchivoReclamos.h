#pragma once
#include "Reclamo.h"

class ArchivoReclamos
{
    public:
        ArchivoReclamos();
        ArchivoReclamos(std::string nombreArchivo);

        bool guardarReg(const Reclamo &r);
        bool modificarReg(Reclamo& r, int pos);
        Reclamo leerReg(int pos);
        int cantidadRegistros();
        void leerRegistros(Reclamo r[], int cant);
        int buscarReg(int pos);

        int cantidadReclamosPorUsuario(int cantidadRegistros, int idUsuario);
        int reclamosPorUsuario(int cantidadRegistros, int vectReclamos[], int idUsuario);

    private:
        std::string _nombreArchivo;
};
