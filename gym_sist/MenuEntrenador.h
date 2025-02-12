#pragma once
#include "MenuPrincipal.h"
#include "ServicioEmpleado.h"
#include "ServicioSocio.h"
#include "ServicioReclamo.h"
#include "ServicioEjercicio.h"
#include "ServicioRutina.h"

class MenuEntrenador
{
    public:
        MenuEntrenador(UsuarioAutenticado usuario);
    
        void comprobarEstadoDeEntrenador();
        void mostrarMenuEntrenador();
        void verHorariosYSociosAsignados();
        void crearModificarRutina();
        void verReclamos();

    private:
        UsuarioAutenticado usuario;
        ServicioReclamo    servReclamo;
        ServicioRutina     servRutina;
        ServicioEjercicio  servEjercicio;
        ServicioEmpleado   servEmpleado;
};
