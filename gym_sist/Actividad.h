#pragma once

class Actividad
{
    public:
        Actividad();
        Actividad(int idActividad, std::string nombreActividad, int capacidad, int lugaresOcupados);

        int getIdActividad();
        std::string getNombreActividad();
        int getCapacidad();
        int getLugaresOcupados();
        //bool getLugares();

        void setIdActividad(int idActividad);
        void setNombreActividad(std::string nombreActividad);
        void setCapacidad(int capacidad);
        void setLugaresOcupados(int lugaresOcuapados);

    private:
        int idActividad;
        char nombreActividad[50];
        int capacidad;           // Capacidad máxima de personas
        int lugaresOcupados;     // Contador de los lugares ocupados
        //bool *lugares;        // Vector para saber si el espacio está ocupado
};
