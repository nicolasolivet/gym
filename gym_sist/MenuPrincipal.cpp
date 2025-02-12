#include <iostream>
#include "MenuPrincipal.h"
#include "MenuSocio.h"
#include "MenuEntrenador.h"
#include "MenuGerente.h"    
#include "ServicioSocio.h"
#include "ServicioEmpleado.h"
#include "ServicioAsistencia.h"
#include "UsuarioAutenticado.h"
#include "Autenticador.h"

using namespace std;

MenuPrincipal::MenuPrincipal()
{
    ServicioSocio servSocio;
    Autenticador autenticador;
    user = autenticador.autenticar();
}

void MenuPrincipal::mostrarMenuPrincipal()
{
    switch(user.getRol())
    {
        case 0:
            cout << "   Menu Gerente" << endl;
            MenuGerente menuGerente(user);
            menuGerente.comprobarEstadoDeGerente();
            break;
        
        case 1:
            cout << "   Menu Entrenador" << endl;
            MenuEntrenador menuEntrenador(user);
            menuEntrenador.comprobarEstadoDeEntrenador();
            break;
        
        case 2:
            cout << "   Menu Socio" << endl;
            MenuSocio menuSocio(user);
            menuSocio.mostrarSubmenuSocio();
            break;
    }
}
