#pragma once
#include "Fecha.h"

class Pago
{
    public:
        Pago();
        Pago(int idUsuario, float monto, Fecha periodo, Fecha fechaPago);

        void setIdUsuario(int idUsuario);
        void setMonto(float monto);
        void setPeriodo(Fecha periodo);
        void setFechaPago(Fecha fechaPago);

        int getIdUsuario();
        float getMonto();
        Fecha getPeriodo();
        Fecha getFechaPago();

    private:
        int _idUsuario;
        float _monto;
        Fecha _periodo;
        Fecha _fechaPago;
};
