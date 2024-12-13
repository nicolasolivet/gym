#include <iostream>
#include <cstring>

#include "Rutina.h"

using namespace std;


Rutina::Rutina()
{

}

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
    _idRutina = idRutina;
}

void Rutina::setFrecuenciaSemanal(int frecuenciaSemanal)
{
    _frecuenciaSemanal = frecuenciaSemanal;
}

void Rutina::setIdEntrenador(int idEntrenador)
{
    _idEntrenador = idEntrenador;
}

void Rutina::setNombreRutina(string nombreRutina)
{
    strcpy(_nombreRutina, nombreRutina.c_str());
}

void Rutina::setDescripcion(string descripcion)
{
    strcpy(_descripcion, descripcion.c_str());
}

int Rutina::getIdRutina()
{
    return _idRutina;
}

int Rutina::getFrecuenciaSemanal()
{
    return _frecuenciaSemanal;
}

int Rutina::getIdEntrenador()
{
    return _idEntrenador;
}

string Rutina::getNombreRutina()
{
    return _nombreRutina;
}

string Rutina::getDescripcion()
{
    return _descripcion;
}
