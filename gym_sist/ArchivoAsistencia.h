#pragma once
#include "Asistencia.h"

class ArchivoAsistencia
{
    public:
        ArchivoAsistencia();
        ArchivoAsistencia(std::string nombreArchivo);

        bool guardarReg(Asistencia Asistencia);
        bool modificarReg(Asistencia Asistencia, int posicion);
        Asistencia leerReg(int posicion);
        int cantidadRegistros();
        void leerRegistros(int cantidadRegistros, Asistencia *vecAsistencia);
        int buscarReg(int idSocio);

    private:
        std::string archivoAsistencia;
};
