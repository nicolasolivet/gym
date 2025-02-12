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
    idEjercicio = idEjercicio;
}

void Ejercicio::setNombreEjercicio(string nombreEjercicio)
{
    strcpy(this->nombreEjercicio, nombreEjercicio.c_str());
}

void Ejercicio::setDescripcion(string descripcion)
{
    strcpy(this->descripcion, descripcion.c_str());
}

int Ejercicio::getIdEjercicio()
{
    return idEjercicio;
}

string Ejercicio::getNombreEjercicio()
{
    return nombreEjercicio;
}

string Ejercicio::getDescripcion()
{
    return descripcion;
}
