#include <iostream>
#include <string>
#include "Actividad.h"

using namespace std;

Actividad::Actividad(){}

Actividad::Actividad(int idActividad, string nombre, int capacidad, int lugaresOcupados)
{
    setIdActividad(idActividad);
    setNombreActividad(nombre);
    setCapacidad(capacidad);
    setLugaresOcupados(lugaresOcupados);
    
}

void Actividad::setIdActividad(int idActividad)
{
    this->idActividad = idActividad;
}

void Actividad::setNombreActividad(string nombreActividad)
{
    strcpy(this->nombreActividad, nombreActividad.c_str());
}

void Actividad::setCapacidad(int capacidad)
{
    this->capacidad = capacidad;
}

void Actividad::setLugaresOcupados(int lugaresOcupados)
{
    this->lugaresOcupados = lugaresOcupados;
}

int Actividad::getIdActividad()
{
    return idActividad;
}

string Actividad::getNombreActividad()
{
    return nombreActividad;
}

int Actividad::getCapacidad()
{
    return capacidad;
}

int Actividad::getLugaresOcupados()
{
    return lugaresOcupados;
}
