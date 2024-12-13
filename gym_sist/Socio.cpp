#include <iostream>
#include <string>
#include "Socio.h"

using namespace std;

Socio::Socio(){}

Socio::Socio(string nombre, string apellido, int dni, int idUsuario, Fecha fechaNacimiento, Fecha fechaIngreso, string contrasenia, bool estado, int idRol, int idMembresia, string estadoFisico, int idRutina, int idEntrenadorAsignado) : Usuario(nombre, apellido, dni, idUsuario, fechaNacimiento, fechaIngreso, contrasenia, estado, idRol)
{
    setMembresia(idMembresia);
    setEstadoFisico(estadoFisico);
    setIdRutina(idRutina);
    setIdEntrenadorAsignado(idEntrenadorAsignado);
    //setPinIngreso(pinIngreso);
}

void Socio::setMembresia(int idMembresia)
{
    _idMembresia = idMembresia;
}

void Socio::setEstadoFisico(string estadoFisico)
{
    strcpy(_estadoFisico, estadoFisico.c_str());
}

void Socio::setIdRutina(int idRutina)
{
    _idRutina = idRutina;
}
void Socio::setIdEntrenadorAsignado(int idEntrenadorAsignado)
{
    _idEntrenadorAsignado = idEntrenadorAsignado;
}

//void Socio::setPinIngreso(int pinIngreso)
//{
//    _pinIngreso = pinIngreso;
//}

int Socio::getMembresia()
{
    return _idMembresia;
}

string Socio::getEstadoFisico()
{
    return _estadoFisico;
}

int Socio::getIdRutina()
{
    return _idRutina;
}

int Socio::getIdEntrenadorAsignado()
{
    return _idEntrenadorAsignado;
}

//int Socio::getPinIngreso()
//{
//    return _pinIngreso;
//}
