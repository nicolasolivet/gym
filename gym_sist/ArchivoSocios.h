#pragma once
#include "Socio.h"

class ArchivoSocios
{
    public:
        ArchivoSocios();
        ArchivoSocios(std::string nombreArchivo);

        bool guardarReg(Socio &socio);
        Socio leerReg(int posicion);
        bool modificarReg(Socio &socio, int posicion);
        int cantidadRegistros();
        void leerRegistros(int cantidadRegistros, Socio *vecSocio);
        int buscarReg(int idSocio);

    private:
        std::string _archivoSocios;
};
