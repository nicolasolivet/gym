#include <iostream>
#include <cstring>
#include "UsuarioAutenticado.h"

using namespace std;

UsuarioAutenticado::UsuarioAutenticado() : _idUsuario(0), _nombre(), _apellido(), _dni(0), _fechaNacimiento(), _fechaIngreso(), _rol(5), _estado(false) {}

UsuarioAutenticado::UsuarioAutenticado(int idUsuario, string nombre, string apellido, int dni, Fecha fechaNacimiento, Fecha fechaIngreso, int rol, bool estado)
// instancio la clase dando los valores a los atributos
: _idUsuario(idUsuario), _dni(dni), _fechaNacimiento(fechaNacimiento), _fechaIngreso(fechaIngreso), _rol(rol), _estado(estado)
{
    strcpy(_nombre, nombre.c_str());
    strcpy(_apellido, apellido.c_str());
}

void UsuarioAutenticado::setEstado(bool estado)
{
    _estado = estado;
}

int UsuarioAutenticado::getIdUsuario() 
{
    return _idUsuario;
}

string UsuarioAutenticado::getNombre() 
{
    return _nombre;
}

string UsuarioAutenticado::getApellido() 
{
    return _apellido;
}

int UsuarioAutenticado::getDni() 
{
    return _dni;
}

Fecha UsuarioAutenticado::getFechaNacimiento() 
{
    return _fechaNacimiento;
}

Fecha UsuarioAutenticado::getFechaIngreso() 
{
    return _fechaIngreso;
}

int UsuarioAutenticado::getRol() 
{
    return _rol;
}

bool UsuarioAutenticado::getEstado() 
{
    return _estado;
}
