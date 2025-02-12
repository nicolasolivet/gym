#include <iostream>
#include <string>
#include "Rutina.h"
using namespace std;

Rutina::Rutina(){}

Rutina::Rutina(int idRutina, int frecuenciaSemanal, int idEntrenador, string nombreRutina, string descripcion)
{
    setIdRutina(idRutina);
    setFrecuenciaSemanal(frecuenciaSemanal);
    setIdEntrenador(idEntrenador);
    setNombreRutina(nombreRutina);
    setDescripcion(descripcion);
}


void Rutina::setIdRutina(int idRutina)
{
    this->idRutina = idRutina;
}

void Rutina::setFrecuenciaSemanal(int frecuenciaSemanal)
{
    this->frecuenciaSemanal = frecuenciaSemanal;
}

void Rutina::setIdEntrenador(int idEntrenador)
{
    this->idEntrenador = idEntrenador;
}

void Rutina::setNombreRutina(string nombreRutina)
{
    strcpy(this->nombreRutina, nombreRutina.c_str());
}

void Rutina::setDescripcion(string descripcion)
{
    strcpy(this->descripcion, descripcion.c_str());
}

int Rutina::getIdRutina()
{
    return idRutina;
}

int Rutina::getFrecuenciaSemanal()
{
    return frecuenciaSemanal;
}

int Rutina::getIdEntrenador()
{
    return idEntrenador;
}

string Rutina::getNombreRutina()
{
    return nombreRutina;
}

string Rutina::getDescripcion()
{
    return descripcion;
}
