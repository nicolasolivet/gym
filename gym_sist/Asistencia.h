#pragma once
#include "Fecha.h"

class Asistencia
{
    public:
        Asistencia();
        Asistencia(int idSocio, Fecha fecha);
    
        int getIdSocio();
        Fecha getFecha();
        void setIdSocio(int idSocio);
        void setFecha(Fecha fecha);
    
        //int getIdActividad();
        //void setIdActividad(int idActividad);
    
    private:
    
        int _idSocio;
        Fecha _fecha;
    
        //int _idActividad;
};
