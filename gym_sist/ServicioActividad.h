#pragma once
#include "ArchivoActividades.h"

class ServicioActividad
{
    public:
        ServicioActividad();
        
        int generarIdActividad();
        void agregarActividad();
        void listarActividades();
        void modificarActividad();
        void buscarActividad(int idActividad);

        bool inscribirParticipante();
        void mostrarDisponibilidad(int idActividad);
        bool hayLugar(int idActividad);
    
    private:
        ArchivoActividades archivoActividad;
};


