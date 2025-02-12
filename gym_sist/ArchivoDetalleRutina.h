#pragma once
#include "DetalleRutina.h"

class ArchivoDetalleRutina
{
	public:
		ArchivoDetalleRutina();
		ArchivoDetalleRutina(std::string nombreArchivo);

		bool guardarReg(DetalleRutina detalle);
		bool modificarReg(DetalleRutina detalle, int posicion);
		DetalleRutina leerReg(int posicion);
		void leerRegistros(int cantidadRegistros, DetalleRutina* vecDetalleRutina);
		int cantidadRegistros();
		int buscarReg(int idRutina);

	private:
		std::string _archivoDetalleRutina;
};
