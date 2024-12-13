#pragma once
#include "Asistencia.h"

class ArchivoAsistencia
{
    public:
        ArchivoAsistencia();
        ArchivoAsistencia(std::string nombreArchivo);

        bool guardarAsistencia(Asistencia Asistencia);
        bool guardarAsistencia(Asistencia Asistencia, int posicion);
        int buscarAsistencia(int idSocio);
        Asistencia leerRegistroAsistencia(int posicion);
        int cantidadRegistrosAsistencias();
        void leerRegistrosAsistencia(int cantidadRegistros, Asistencia *vecAsistencia);

    private:
        std::string _nombreArchivo;

};
