#pragma once
#include "usuarioAutenticado.h"

class MenuPrincipal
{
    public:
        MenuPrincipal();
        void mostrarMenuPrincipal();
    
    protected:
        int opcion;
        UsuarioAutenticado user;
};

