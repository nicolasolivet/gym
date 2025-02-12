#pragma once
#include "Fecha.h"

class UsuarioAutenticado
{
    public:
        UsuarioAutenticado();
        UsuarioAutenticado(int idUsuario, std::string nombre, std::string apellido, int dni, Fecha fechaNacimiento, Fecha fechaIngreso, int rol, bool estado);

        void setEstado(bool estado);

        int getIdUsuario();
        std::string getNombre();
        std::string getApellido();
        int getDni();
        Fecha getFechaNacimiento();
        Fecha getFechaIngreso();
        int getRol();
        bool getEstado();

    private:
        int idUsuario;
        int dni;
        int rol;
        char nombre[50];
        char apellido[50];
        bool estado;
        Fecha fechaNacimiento;
        Fecha fechaIngreso;
};
