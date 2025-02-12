#include "Usuario.h"
using namespace std;

Usuario::Usuario() {};

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
	idUsuario = idUsuario;
}

void Usuario::setNombre(string nombre)
{
	strcpy(this->nombre, nombre.c_str());
}

void Usuario::setApellido(string apellido)
{
	strcpy(this->apellido, apellido.c_str());
}

void Usuario::setDni(int dni)
{
	this->dni = dni;
}

void Usuario::setContrasenia(string contrasenia)
{
	strcpy(this->contrasenia, contrasenia.c_str());
}

void Usuario::setFechaNacimiento(Fecha fechaNacimiento)
{
	this->fechaNacimiento = fechaNacimiento;
}

void Usuario::setFechaIngreso(Fecha fechaIngreso)
{
	this->fechaIngreso = fechaIngreso;
}

void Usuario::setIdRol(int idRol)
{
	this->idRol = idRol;
}

void Usuario::setEstado(bool estado)
{
	this->estado = estado;
}


int Usuario::getIdUsuario() const { return idUsuario; }

int Usuario::getDni() const { return dni; }

string Usuario::getNombre() const { return nombre; }

string Usuario::getApellido() const { return apellido; }

string Usuario::getContrasenia() { return contrasenia; }

Fecha Usuario::getFechaIngreso() const { return fechaIngreso; }

Fecha Usuario::getFechaNacimiento()const { return fechaNacimiento; }

int Usuario::getIdRol() const { return idRol; }

bool Usuario::getEstado() const { return estado; }
