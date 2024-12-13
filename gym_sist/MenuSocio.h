#pragma once
#include "MenuPrincipal.h"
#include "ServicioSocio.h"

class MenuSocio
{
    public:
        MenuSocio(UsuarioAutenticado usuario);

        void mostrarMenuIngresoSocio();
        void mostrarSubmenuSocio();
        void mostrarMenuSocio();
        void gestionarPagos();

        void verRutina();
        void consultarHorarios();
        void presentarReclamo();

        void mostrarPreciosDePases();
        void verHorariosGimnasio();

    private:
        UsuarioAutenticado _usuario;
        ServicioSocio _servSocio;
};
