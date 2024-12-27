#pragma once
#include "ArchivoReclamos.h"

class ServicioReclamo
{
    public:
        ServicioReclamo();

        int autoGenerarIdReclamo();
        void iniciarReclamo(int idUsuario);
        void mostrarReclamo(bool resuelto);
        void verReclamosUsuario(int idUsuario);
        void cambiarEstadoReclamo();

    private:
        ArchivoReclamos _archivoReclamo;
};

