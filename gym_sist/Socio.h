#pragma once
#include "Usuario.h"

class Socio : public Usuario
{
    public:
        Socio();
        Socio(std::string nombre, std::string apellido, int dni, int idUsuario, Fecha fechaNacimiento, Fecha fechaIngreso, std::string contrasenia, bool estado, int idRol, int idMembresia, std::string estadoFisico, int idRutina, int idEntrenadorAsignado /*int pinIngreso*/);

        void setMembresia(int membresia);
        void setEstadoFisico(std::string estadoFisico);
        void setIdRutina(int idRutina);
        void setIdEntrenadorAsignado(int idEntrenadorAsignado);
        //void setPinIngreso(int pinIngreso);

        int getMembresia();
        std::string getEstadoFisico();
        int getIdRutina();
        int getIdEntrenadorAsignado();
        //int getPinIngreso();

    private:
        int _idMembresia;
        char _estadoFisico[50];
        int _idRutina;
        int _idEntrenadorAsignado;
};
