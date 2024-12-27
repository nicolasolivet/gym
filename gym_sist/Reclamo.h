#pragma once
#include "Fecha.h"

class Reclamo
{
public:
    Reclamo();

    Reclamo(int idReclamo, int idUsuario, bool resuelto, std::string detalle, Fecha fecha);

    void setIdReclamo(int idReclamo);
    void setIdUsuario(int idUsuario);
    void setResuelto(bool resuelto);
    void setDetalle(std::string detalle);
    void setFecha(Fecha fecha);

    int getIdReclamo();
    int getIdUsuario();
    bool getResuelto();
    std::string getDetalle();
    Fecha getFecha();

private:

    int _idReclamo;
    int _idUsuario;
    bool _resuelto;
    char _detalle[100];
    Fecha _fecha;
};
