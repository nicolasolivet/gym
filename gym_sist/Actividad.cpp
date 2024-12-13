#include <iostream>
#include <cstring>
#include "Actividad.h"

using namespace std;

Actividad::Actividad(){}

Actividad::Actividad(int idActividad, string nombre)
{
    setIdActividad(idActividad);
    setNombreActividad(nombre);
}

void Actividad::setIdActividad(int idActividad)
{
    _idActividad = idActividad;
}

void Actividad::setNombreActividad(string nombreActividad)
{
    strcpy(_nombreActividad, nombreActividad.c_str());
}

int Actividad::getIdActividad()
{
    return _idActividad;
}

string Actividad::getNombreActividad()
{
    return _nombreActividad;
}
