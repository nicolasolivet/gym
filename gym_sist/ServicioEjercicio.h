#pragma once

#include "ArchivoEjercicios.h"

class ServicioEjercicio
{
    public:
        ServicioEjercicio();

        void verEjercicios();
        void agregarEjercicio();
        void modificarEjercicio();
        int obtenerUltimoIdEjercicio();
        void verEjercicio(int IdEjercicio);

    private:

        ArchivoEjercicios _archivoEjercicio;
};

