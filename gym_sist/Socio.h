#pragma once
#include "Usuario.h"

class Socio : public Usuario
{
    public:
        Socio();
        Socio(std::string nombre, std::string apellido, int dni, int idUsuario, Fecha fechaNacimiento, Fecha fechaIngreso, std::string contrasenia, bool estado, int idRol, int idPase, std::string estadoFisico, int idRutina, int idEntrenadorAsignado);

        void setPase(int pase);
        void setEstadoFisico(std::string estadoFisico);
        void setIdRutina(int idRutina);
        void setIdEntrenadorAsignado(int idEntrenadorAsignado);

        int getPase();
        std::string getEstadoFisico();
        int getIdRutina();
        int getIdEntrenadorAsignado();

    private:
        int _idPase;
        char _estadoFisico[50];
        int _idRutina;
        int _idEntrenadorAsignado;
};
