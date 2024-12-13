#pragma once

#include "MenuPrincipal.h"

class MenuGerente
{
    public:

        MenuGerente(UsuarioAutenticado _usuario);

        void mostrarMenuGerente();
        void gestionarSocios();
        void gestionarEntrenadores();
        void gestionarGerentes();
        void gestionarPagos();
        void gestionarReclamos();
        void verEstadisticas();
        void modificarContrasenia();

        void verOpcionesDeListasSocios();
        void verOpcionesDeListasEntrenadores();

        void comprobarEstadoDeGerente();

    private:
        UsuarioAutenticado _usuario;
};
