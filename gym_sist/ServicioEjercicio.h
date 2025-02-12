#pragma once

#include "ArchivoEjercicios.h"

class ServicioEjercicio
{
    public:
        ServicioEjercicio();

        int generarIdEjercicio();
        void agregarEjercicio();
        void verEjercicio(int IdEjercicio);
        void verEjercicios();
        void modificarEjercicio();

    private:

        ArchivoEjercicios archivoEjercicios;
};

