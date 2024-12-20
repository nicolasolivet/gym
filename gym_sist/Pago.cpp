#include <iostream>
#include "Pago.h"

using namespace std;

Pago::Pago(){}

Pago::Pago(int idUsuario, float monto, Fecha periodo, Fecha fechaPago)
{
    setIdUsuario(idUsuario);
    setMonto(monto);
    setPeriodo(periodo);
    setFechaPago(fechaPago);
}

void Pago::setIdUsuario(int idUsuario)
{
    _idUsuario = idUsuario;
}

void Pago::setMonto(float monto)
{
    _monto = monto;
}

void Pago::setPeriodo(Fecha periodo)
{
    _periodo = periodo;
}

void Pago::setFechaPago(Fecha fechaPago)
{
    _fechaPago = fechaPago;
}

int Pago::getIdUsuario()
{
    return _idUsuario;
}

float Pago::getMonto()
{
    return _monto;
}

Fecha Pago::getPeriodo()
{
    return _periodo;
}

Fecha Pago::getFechaPago()
{
    return _fechaPago;
}
