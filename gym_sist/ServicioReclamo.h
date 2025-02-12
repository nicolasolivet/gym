#pragma once
#include "ArchivoReclamos.h"

class ServicioReclamo
{
    public:
        ServicioReclamo();

        int generarIdReclamo();
        void iniciarReclamo(int idUsuario);
        void mostrarReclamos(bool resuelto);
        void verReclamosUsuario(int idUsuario);
        void cambiarEstadoReclamo();

    private:
        ArchivoReclamos archivoReclamos;
};

