#pragma once
#include "Socio.h"

class ArchivoSocios
{
    public:
        ArchivoSocios();
        ArchivoSocios(std::string nombreArchivo);

        bool guardarReg(Socio socio);
        Socio leerReg(int posicion);
        bool modificarReg(Socio socio, int posicion);
        int buscarReg(int idSocio);
        int cantidadRegistros();
        void leerRegistros(int cantidadRegistros, Socio *vecSocio);

    private:
        std::string _nombreArchivo;
};
