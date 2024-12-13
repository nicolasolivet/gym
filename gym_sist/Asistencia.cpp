#include <iostream>
#include "Asistencia.h"

using namespace std;

Asistencia::Asistencia(){}

Asistencia::Asistencia(int idSocio, Fecha fecha)
{
    setIdSocio(idSocio);
    setFecha(fecha);
}

void Asistencia::setIdSocio(int idSocio)
{
    _idSocio = idSocio;
}

void Asistencia::setFecha(Fecha fecha)
{
    _fecha = fecha;
}

int Asistencia::getIdSocio()
{
    return _idSocio;
}

Fecha Asistencia::getFecha()
{
    return _fecha;
}
