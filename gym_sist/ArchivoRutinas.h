#pragma once
#include <string>
#include "Rutina.h"

class ArchivoRutinas
{
    public:
        ArchivoRutinas();
        ArchivoRutinas(std::string nombreArchivo);

        bool guardarReg(Rutina rutina);
        bool modificarReg(Rutina rutina, int posicion);
        Rutina leerReg(int posicion);
        int cantidadRegistros();
        void leerRegistros(int cantidadRegistros, Rutina *rutinas);
        int buscarReg(int idRutina);

        int cantidadRutinasPorEntrenador(int cantidadRegistros, int idEntrenador);
        int rutinasPorEntrenador(int cantidadRegistros, int vectRutina[], int idEntrenador);

    private:
        std::string archivoRutinas;
};
