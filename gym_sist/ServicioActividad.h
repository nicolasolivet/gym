#pragma once

#include "ArchivoActividades.h"

class ServicioActividad
{
    public:
        ServicioActividad();
    
        void listarActividades();
        int agregarActividad();
        void modificarActividad();
    
        void buscarActividad(int idActividad);
    
    
    private:
        ArchivoActividades _archivoActividad;
};


