#pragma once
#include <string>
#include "Actividad.h"

class ArchivoActividades
{
    public:
        ArchivoActividades();
        ArchivoActividades(std::string nombreArchivo);
    
        bool guardarReg(Actividad actividad);
        bool modificarReg(Actividad actividad, int posicion);
        Actividad leerReg(int posicion);
        int cantidadRegistros();
        void leerRegistros(int cantidadRegistros, Actividad* actividades);
        int buscarReg(int idActividad);
    
    private:
        std::string archivoActividades;
};

