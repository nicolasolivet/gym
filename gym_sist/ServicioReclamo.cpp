#include <iostream>
#include <iomanip>
#include "ServicioReclamo.h"
#include "Reclamo.h"
#include "Fecha.h"
#include "ServicioSocio.h"

using namespace std;

ServicioReclamo::ServicioReclamo()
{
	archivoReclamos = ArchivoReclamos("archivoReclamo.dat");
}

int ServicioReclamo::generarIdReclamo()
{
	int cantidad = archivoReclamos.cantidadRegistros();

	if (cantidad != -1)
		return cantidad + 1;
	else
		return 0;
}

void ServicioReclamo::iniciarReclamo(int idUsuario)
{
	system("cls");

	Fecha fechaActual;
	bool resuelto = false;
	string detalle;

	cout << "	+-------------------------------------------+" << endl;
	cout << "	|               NUEVO RECLAMO               |" << endl;
	cout << "	+-------------------------------------------+" << endl;

	cout << "   Por favor ingrese su reclamo " << endl;
	cout << endl;
	cin >> detalle;
	cout << endl;

	int idReclamo = generarIdReclamo();

	Reclamo reclamo(idReclamo, idUsuario, false, detalle, fechaActual);
	//Reclamo(int idReclamo, int idUsuario, bool resuelto, std::string detalle, Fecha fecha);

	if (archivoReclamos.guardarReg(reclamo))
	{
		cout << "	+-------------------------------------------+" << endl;
		cout << "	|   Reclamo registrado con exito. ID #" << idReclamo << endl;
		cout << "	|	Fecha: " << fechaActual.toString() << endl;
		cout << "	+-------------------------------------------+" << endl;
	}
	else
	{
		cout << "	+--------------------------------------------------------+" << endl;
		cout << "	|   No se pudo registar su reclamo. Volve a intentarlo " << idReclamo << endl;
		cout << "	+--------------------------------------------------------+" << endl;
	}
	system("pause");
}

void ServicioReclamo::mostrarReclamos(bool resuelto)
{
	system("cls");
	Reclamo reclamo;

	int cantReclamos = archivoReclamos.cantidadRegistros();

	if (cantReclamos > 0)
	{
		for (int c = 0; c < cantReclamos; c++)
		{
			reclamo = archivoReclamos.leerReg(c);
			if (reclamo.getResuelto() == false)
			{
				//cout << string(80, '-') << endl;
				//cout << left << setw(15) << "ID Reclamo" << "|"
				//	<< setw(15) << "ID Usuario" << "|"
				//	<< setw(15) << "Fecha" << "|"
				//	<< setw(15) << "Detalle" << endl;
				//cout << string(80, '-') << endl;
				//
				//cout << left << setw(15) << reclamo.getIdReclamo() << "|"
				//	<< setw(15) << reclamo.getIdUsuario() << "|"
				//	<< setw(15) << reclamo.getFecha().toString() << "|"
				//	<< setw(15) << reclamo.getDetalle() << endl;
				//cout << string(80, '-') << endl;

				cout << "+--------------------------------------+" << endl;
				cout << "| ID Reclamo #" << reclamo.getIdReclamo() << endl;
				cout << "| ID Usuario #" << reclamo.getIdUsuario() << endl;
				cout << "| Fecha: " << reclamo.getFecha().toString() << endl;
				cout << "| Detalle: " << reclamo.getDetalle() << endl;
				cout << "+--------------------------------------+" << endl;
			}
		}
	}
	else
	{
		cout << "+--------------------------------------+" << endl;
		cout << "|     No hay reclamos para mostrar     |" << endl;
		cout << "+--------------------------------------+" << endl;

	}
	system("pause");
}

void ServicioReclamo::verReclamosUsuario(int idUsuario)
{
	system("cls");
	Reclamo reclamo;
	int* reclamos;

	int cantReclamos = archivoReclamos.cantidadRegistros();
	int cantReclamosUsuario = archivoReclamos.cantidadReclamosPorUsuario(cantReclamos, idUsuario);

	reclamos = new int[cantReclamosUsuario];
	if (reclamos == nullptr) { return; }

	*reclamos = archivoReclamos.reclamosPorUsuario(cantReclamos, reclamos, idUsuario);

	cout << "   +--------------------------------+" << endl;
	cout << "   |      RECLAMOS POR USUARIO      |" << endl;
	cout << "   +--------------------------------+" << endl;

	for (int i = 0; i < cantReclamosUsuario; i++)
	{
		reclamo = archivoReclamos.leerReg(reclamos[i]);

		if (reclamo.getResuelto())
		{
			cout << "   +--------------------------------------+" << endl;
			cout << "   | ID Reclamo #" << reclamo.getIdReclamo() << endl;
			cout << "   | ID Usuario #" << reclamo.getIdUsuario() << endl;
			cout << "   | Fecha: " << reclamo.getFecha().toString() << endl;
			cout << "   | Detalle: " << reclamo.getDetalle() << endl;
			cout << "   +--------------------------------------+" << endl;
		}
		else
		{
			cout << "   +-------------------------------+" << endl;
			cout << "   |		Reclamo en proceso		|" << endl;
			cout << "   +-------------------------------+" << endl;
		}
	}

	delete[]reclamos;
	system("pause");
}

void ServicioReclamo::cambiarEstadoReclamo()
{
	system("cls");

	Reclamo reclamo;
	int idReclamo, opc;

	cout << "   + --------------------------- +" << endl;
	cout << "   |      MODIFICAR RECLAMO      |" << endl;
	cout << "   + --------------------------- +" << endl;
	cout << endl;

	cout << "   Por favor, ingresa el ID del reclamo" << endl;
	cin >> idReclamo;

	int pos = archivoReclamos.buscarReg(idReclamo);
	if (pos != -1)
	{
		reclamo = archivoReclamos.leerReg(pos);
		if (reclamo.getResuelto())
		{
			cout << "   Reclamo: RESUELTO" << endl;
			cout << " Queres establecer el estado del reclamo a ACTIVO? ";
			cout << " 1. SI | 0. NO ";
			cin >> opc;

			switch (opc)
			{
			case 1:
				reclamo.setResuelto(false);
				archivoReclamos.modificarReg(reclamo, pos);
				break;

			default:
				break;
			}
		}
		else
		{
			cout << "   Reclamo: ACTIVO" << endl;
			cout << " Queres establecer el estado del reclamo a RESUELTO? ";
			cout << " 1. SI | 0. NO ";
			cin >> opc;

			switch (opc)
			{
			case 1:
				reclamo.setResuelto(true);
				archivoReclamos.modificarReg(reclamo, pos);
				break;

			default:
				break;
			}
		}

		system("cls");

		cout << endl << endl << endl;
		cout << "   +--------------------------------+" << endl;
		cout << "   |   Cambio realizado con exito   |" << endl;
		cout << "   +--------------------------------+" << endl;
		cout << endl << endl << endl;
	}
	else
	{
		cout << "+--------------------------------------------------------------------+" << endl;
		cout << "|     EL ID ingresado no existe o no se han registrado reclamos.     |" << endl;
		cout << "|							Volve a intentarlo                        |" << endl;
		cout << "+--------------------------------------------------------------------+" << endl;
		cout << endl;
	}
	system("pause");

}

