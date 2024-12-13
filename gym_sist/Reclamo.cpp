#include <iostream>
#include <cstring>

#include "Reclamo.h"

using namespace std;

Reclamo::Reclamo(){}

Reclamo::Reclamo(int idReclamo, int idUsuario, bool estaResuelto, string detalle, Fecha fecha)
{
    setIdReclamo(idReclamo);
    setIdUsuario(idUsuario);
    setEstaResuelto(estaResuelto);
    setDetalle(detalle);
    setFecha(fecha);
}

void Reclamo::setIdReclamo(int idReclamo)
{
    _idReclamo = idReclamo;
}
void Reclamo::setIdUsuario(int idUsuario)
{
    _idUsuario = idUsuario;
}
void Reclamo::setEstaResuelto(bool estaResuelto)
{
    _estaResuelto = estaResuelto;
}
void Reclamo::setDetalle(string detalle)
{
    strcpy(_detalle, detalle.c_str());
}
void Reclamo::setFecha(Fecha fecha)
{
    _fecha = fecha;
}

int Reclamo::getIdReclamo()
{
    return _idReclamo;
}
int Reclamo::getIdUsuario()
{
    return _idUsuario;
}
bool Reclamo::getEstaResuelto()
{
    return _estaResuelto;
}
string Reclamo::getDetalle()
{
    return _detalle;
}
Fecha Reclamo::getFecha()
{
    return _fecha;
}


