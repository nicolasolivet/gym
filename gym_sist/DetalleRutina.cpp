#include <iostream>

#include "DetalleRutina.h"

using namespace std;

DetalleRutina::DetalleRutina(){}

DetalleRutina::DetalleRutina(int *idEjercicio, int idRutina, int *repeticiones,  float *peso)
{
    setIdEjercicio(idEjercicio);
    setIdRutina(idRutina);
    setRepeticiones(repeticiones);
    setPeso(peso);
}


void DetalleRutina::setIdEjercicio(int *idEjercicio)
{
    for(int i = 0; i < 10; i++){
        _idEjercicio[i] = idEjercicio[i];
    }
}

void DetalleRutina::setIdRutina(int idRutina)
{
    _idRutina = idRutina;
}

void DetalleRutina::setRepeticiones(int *repeticiones)
{
    for(int i = 0; i < 10; i++){
        _repeticiones[i] = repeticiones[i];
    }
}

void DetalleRutina::setPeso(float *peso)
{
    for(int i=0; i<10; i++)
    {
        _peso[i] = peso[i];
    }
}


int *DetalleRutina::getIdEjercicio()
{
    return _idEjercicio;
}
int DetalleRutina::getIdRutina()
{
    return _idRutina;
}
int *DetalleRutina::getRepeticiones()
{
    return _repeticiones;
}
float *DetalleRutina::getPeso()
{
    return _peso;
}
