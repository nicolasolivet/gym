#pragma once

#include "ArchivoAsistencia.h"

class ServicioAsistencia
{
    public:
        ServicioAsistencia();

        bool validarRegistroDeAsistencia(int idSocio, Fecha fechaActual);
        void registrarAsistencia(int idSocio);
        
        void verTodasLasAsistencias();
        void verAsistenciasEnPeriodo(int mes, int anio);
        void verAsistenciasEnAnio(int anio);
        void verAsistenciaPorSocio(int idSocio);

    private:
        ArchivoAsistencia archivoAsistencia;
};

