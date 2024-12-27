#pragma once
#include "Reclamo.h"

class ArchivoReclamos
{
    public:
        ArchivoReclamos();
        ArchivoReclamos(std::string nombreArchivo);
        bool guardarReg(const Reclamo &r);
        Reclamo leerReg(int pos);
        void leerRegistros(Reclamo r[], int cant);
        bool modificarReg(Reclamo& r, int pos);
        int cantidadRegistros();
        int buscarReg(int pos);

       
        int cantidadReclamosPorUsuario(int cantidadRegistros, int idUsuario);
        int leerReclamosPorUsuario(int cantidadRegistros, int vectReclamos[], int idUsuario);

    private:
        std::string _nombreArchivo;
};
