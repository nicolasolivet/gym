#pragma once
#include "MenuPrincipal.h"
#include "ServicioSocio.h"
#include "ServicioPago.h"
#include "ServicioAsistencia.h"
#include "ServicioReclamo.h"
#include "ServicioActividad.h"
#include "ServicioRutina.h"
#include "ServicioEmpleado.h"

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
		void generarReclamo();
		void mostrarPreciosDePases();
		void verHorariosGimnasio();
	
	private:
		UsuarioAutenticado  usuario;
		ServicioSocio      servSocio;
		ServicioPago       servPago;
		ServicioAsistencia servAsist;
		ServicioReclamo   servReclamo;
		ServicioActividad  servActi;
		ServicioRutina     servRutina;
		ServicioEmpleado   servEmp;
};
