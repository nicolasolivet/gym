#pragma once

#include "ArchivoAsistencia.h"

class ServicioAsistencia
{
    public:
        ServicioAsistencia();

        bool validarRegistroDeAsistencia(int idSocio, Fecha fechaActual);
        void verTodasLasAsistencia();
        void verAsistenciasEnPeriodo(int mes, int anio);
        void verAsistenciasEnAnio(int anio);
        void registrarAsistencia(int idSocio);
        void verAsistenciaPorSocio(int idSocio);

    private:

        ArchivoAsistencia _archivoAsistencia;
};

