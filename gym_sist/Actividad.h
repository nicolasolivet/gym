#pragma once

class Actividad
{
    public:
        Actividad();
        Actividad(int idActividad, std::string nombreActividad);

        void setIdActividad(int idActividad);
        void setNombreActividad(std::string nombreActividad);

        int getIdActividad();
        std::string getNombreActividad();

    private:
        int _idActividad;
        char _nombreActividad[50];
};
