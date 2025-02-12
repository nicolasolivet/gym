#pragma once
#include "Usuario.h"

class Empleado : public Usuario
{
    public:
        Empleado();
        Empleado(std::string nombre, std::string apellido, int dni, int idUsuario, Fecha fechaNacimiento, Fecha fechaIngreso, std::string contrasenia, bool estado, int idRol, int idTurno, int idActividad, bool* diaSem);

        void setIdTurno(int idTurno);
        void setIdActividad(int idActividad);
        void setDiaSem(bool* diaSem);

        int getIdTurno();
        int getIdActividad();
        bool *getDiaSem();

    private:
        int idTurno;
        int idActividad;
        bool diaSem[7];
};
