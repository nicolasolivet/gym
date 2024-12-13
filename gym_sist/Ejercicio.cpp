#include <iostream>
#include <cstring>

#include "Ejercicio.h"

using namespace std;


Ejercicio::Ejercicio(){}

Ejercicio::Ejercicio(int idEjercicio, string nombreEjercicio, string descripcion)
{
    setIdEjercicio(idEjercicio);
    setNombreEjercicio(nombreEjercicio);
    setDescripcion(descripcion);
}


void Ejercicio::setIdEjercicio(int idEjercicio)
{
    _idEjercicio = idEjercicio;
}

void Ejercicio::setNombreEjercicio(string nombreEjercicio)
{
    strcpy(_nombreEjercicio, nombreEjercicio.c_str());
}

void Ejercicio::setDescripcion(string descripcion)
{
    strcpy(_descripcion, descripcion.c_str());
}

int Ejercicio::getIdEjercicio()
{
    return _idEjercicio;
}

string Ejercicio::getNombreEjercicio()
{
    return _nombreEjercicio;
}

string Ejercicio::getDescripcion()
{
    return _descripcion;
}
