#include <iostream>
#include <string>
#include "UsuarioAutenticado.h"

using namespace std;

UsuarioAutenticado::UsuarioAutenticado() : idUsuario(0), nombre(), apellido(), dni(0), fechaNacimiento(), fechaIngreso(), rol(-3), estado(false) {}

UsuarioAutenticado::UsuarioAutenticado(int idUsuario, string nombre, string apellido, int dni, Fecha fechaNacimiento, Fecha fechaIngreso, int rol, bool estado)
// instancio la clase dando los valores a los atributos
	: idUsuario(idUsuario), dni(dni), fechaNacimiento(fechaNacimiento), fechaIngreso(fechaIngreso), rol(rol), estado(estado)
{
	strcpy(this->nombre, nombre.c_str());
	strcpy(this->apellido, apellido.c_str());
}

void UsuarioAutenticado::setEstado(bool estado) { this->estado = estado; }

int UsuarioAutenticado::getIdUsuario() { return idUsuario; }

string UsuarioAutenticado::getNombre() { return nombre; }

string UsuarioAutenticado::getApellido() { return apellido; }

int UsuarioAutenticado::getDni() { return dni; }

Fecha UsuarioAutenticado::getFechaNacimiento() { return fechaNacimiento; }

Fecha UsuarioAutenticado::getFechaIngreso() { return fechaIngreso; }

int UsuarioAutenticado::getRol() { return rol; }

bool UsuarioAutenticado::getEstado() { return estado; }