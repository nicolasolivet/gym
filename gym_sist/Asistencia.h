#pragma once
#include "Fecha.h"

class Asistencia
{
    public:
        Asistencia();
        Asistencia(int idSocio, Fecha fecha);
    
        int getIdSocio();
        Fecha getFecha();
    
        //int getIdActividad();
    
        void setIdSocio(int idSocio);
        void setFecha(Fecha fecha);
    
        //void setIdActividad(int idActividad);
    
    private:
    
        int _idSocio;
        Fecha _fecha;
    
        //int _idActividad;
};
