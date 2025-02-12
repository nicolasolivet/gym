#include <iostream>
#include "Empleado.h"
using namespace std;

Empleado::Empleado(){}

Empleado::Empleado(string nombre, string apellido, int dni, int idUsuario, Fecha fechaNacimiento, Fecha fechaIngreso, string contrasenia, bool estado, int idRol, int idTurno, int idActividad, bool* diaSem) : Usuario(nombre, apellido, dni, idUsuario, fechaNacimiento, fechaIngreso, contrasenia, estado, idRol)
{
	setIdTurno(idTurno);
	setIdActividad(idActividad);
	setDiaSem(diaSem);
}


void Empleado::setIdTurno(int idTurno)
{
	this->idTurno = idTurno;
}

void Empleado::setIdActividad(int idActividad)
{
	idActividad = idActividad;
}

void Empleado::setDiaSem(bool* diaSem)
{
	for (int i = 0; i < 7; i++)
	{
		this->diaSem[i] = diaSem[i];
	}
}

int Empleado::getIdTurno() { return idTurno; }

int Empleado::getIdActividad() { return idActividad; }

bool* Empleado::getDiaSem() { return diaSem; }