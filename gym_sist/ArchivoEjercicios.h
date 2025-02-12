#pragma once
#include <string>
#include "Ejercicio.h"

class ArchivoEjercicios
{
    public:
        ArchivoEjercicios();
        ArchivoEjercicios(std::string nombreArchivo);
    
        bool guardarReg(Ejercicio ejercicio);
        bool modificarReg(Ejercicio ejercicio, int posicion);
        Ejercicio leerReg(int posicion);
        int cantidadRegistros();
        void leerRegistros(int cantidadRegistros, Ejercicio *vecEjercicio);
        int buscarReg(int idEjercicio);
    
    private:
        std::string archivoEjercicios;
};
