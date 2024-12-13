#include "Usuario.h"
using namespace std;

Usuario::Usuario(){};

Usuario::Usuario(std::string nombre, std::string apellido, int dni, int idUsuario, Fecha fechaNacimiento, Fecha fechaIngreso, std::string contrasenia, bool estado, int idRol)
{
    setNombre(nombre);
    setApellido(apellido);
    setDni(dni);
    setIdUsuario(idUsuario);
    setFechaNacimiento(fechaNacimiento);
    setFechaIngreso(fechaIngreso);
    setContrasenia(contrasenia);
    setEstado(estado);
    setIdRol(idRol);
}

void Usuario::setIdUsuario(int idUsuario)
{
    _idUsuario = idUsuario;
}

void Usuario::setNombre(string nombre)
{
    strcpy(_nombre, nombre.c_str());
}

void Usuario::setApellido(string apellido)
{
    strcpy(_apellido, apellido.c_str());
}

void Usuario::setDni(int dni)
{
    _dni = dni;
}

void Usuario::setContrasenia(string contrasenia)
{
    strcpy(_contrasenia, contrasenia.c_str());
}

void Usuario::setFechaNacimiento(Fecha fechaNacimiento)
{
    _fechaNacimiento = fechaNacimiento;
}

void Usuario::setFechaIngreso(Fecha fechaIngreso)
{
    _fechaIngreso = fechaIngreso;
}

void Usuario::setIdRol(int idRol)
{
    _idRol = idRol;
}

void Usuario::setEstado(bool estado)
{
    _estado = estado;
}


int Usuario::getIdUsuario() const
{
    return _idUsuario;
}

int Usuario::getDni() const
{
    return _dni;
}

string Usuario::getNombre() const
{
    return _nombre;
}

string Usuario::getApellido() const
{
    return _apellido;
}

string Usuario::getContrasenia()
{
    return _contrasenia;
}

Fecha Usuario::getFechaIngreso() const
{
    return _fechaIngreso;
}

Fecha Usuario::getFechaNacimiento()const
{
    return _fechaNacimiento;
}

int Usuario::getIdRol() const
{
    return _idRol;
}

bool Usuario::getEstado() const
{
    return _estado;
}
