#include <iostream>
#include "ServicioSocio.h"
#include "ArchivoPagos.h"
using namespace std;

int main()
{
	ServicioSocio socio;
	//socio.agregarSocio();
	//socio.verSociosPorId();
	//socio.verSociosPorApellido();
	//socio.verSociosPorDni();
	//socio.modificarSocio();
	//socio.verMembresia(1);

	Pago p;
	ArchivoPagos ap("archivoPago.dat");
	ap.mostrarPago();
	//ap.mostrarTodos();
	//ap.pagosDelSocio();








	//cout << " +-----------------------------------+" << endl;
	//cout << " | 1 - Modificar Datos Personales    |" << endl;
	//cout << " + --------------------------------- +" << endl;
	//cout << " | 2 - Modificar Fecha de Nacimiento |" << endl;
	//cout << " + --------------------------------- +" << endl;
	//cout << " | 3 - Modificar Estado / Eliminar   |" << endl;
	//cout << " +-----------------------------------+" << endl;
	return 0;
}