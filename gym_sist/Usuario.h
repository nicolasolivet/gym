#pragma once
#include "Fecha.h"

class Usuario
{
    public:
        Usuario();
        Usuario(std::string nombre, std::string apellido, int dni, int idUsuario, Fecha fechaNacimiento, Fecha fechaIngreso, std::string contrasenia, bool estado, int idRol);

        void setNombre(std::string nombre);
        void setApellido(std::string apellido);
        void setDni(int dni);
        void setIdUsuario(int idUsuario);
        void setFechaNacimiento(Fecha fechaNacimiento);
        void setFechaIngreso(Fecha fechaIngreso);
        void setContrasenia(std::string contrasenia);
        void setEstado(bool estado);
        void setIdRol(int idRol);

        int getIdUsuario() const;
        std::string getNombre() const;
        std::string getApellido() const;
        int getDni() const;
        std::string getContrasenia();
        Fecha getFechaNacimiento() const;
        Fecha getFechaIngreso() const;
        int getIdRol() const;
        bool getEstado() const;

    protected:
        int _idUsuario;
        char _nombre[50];
        char _apellido[50];
        int _dni;
        int _idRol;
        char _contrasenia[50];
        Fecha _fechaIngreso;
        Fecha _fechaNacimiento;
        bool _estado;
};

