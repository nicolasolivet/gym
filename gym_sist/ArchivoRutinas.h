#pragma once
#include <string>
#include "Rutina.h"

class ArchivoRutinas
{
    public:
        ArchivoRutinas();
        ArchivoRutinas(std::string nombreArchivo);

        bool guardarRutina(Rutina rutina);
        bool guardarRutina(Rutina rutina, int posicion);
        int buscarRutina(int idRutina);
        Rutina leerRegistroRutina(int posicion);
        int cantidadRegistrosRutinas();
        void leerRegistrosRutina(int cantidadRegistros, Rutina *vecRutina);

        int cantidadDeRegistrosPorEntrenador(int cantidadRegistros, int idEntrenador);
        int leerRegistrosRutinasPorEntrenador(int cantidadRegistros, int vectRutina[], int tam, int idEntrenador);

    private:
        std::string _nombreArchivo;
};
