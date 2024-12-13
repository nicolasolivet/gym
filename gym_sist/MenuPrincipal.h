#pragma once
#include "usuarioAutenticado.h"

class MenuPrincipal
{
    public:
        MenuPrincipal();
        void mostrarMenuInicio();
    
    protected:
        int _opcion;
        UsuarioAutenticado _usuario;
};

