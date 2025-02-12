#include <iostream>
#include <iomanip>
#include "ServicioActividad.h"

using namespace std;

ServicioActividad::ServicioActividad()
{
	archivoActividad = ArchivoActividades("archivoActividades.dat");
}

int ServicioActividad::generarIdActividad()
{
	int cantReg = archivoActividad.cantidadRegistros();

	if (cantReg != -1)
		return cantReg + 1;
	else
		return 1;
}

void ServicioActividad::agregarActividad()
{
	system("cls");

	string nombre;
	int opc, capacidad, lugaresOcupados;

	cout << endl << endl;
	cout << "   +------------------------------+" << endl;
	cout << "   |       AGREGAR ACTIVIDAD      |" << endl;
	cout << "   +------------------------------+" << endl << endl;

	int id = generarIdActividad();
	cout << "  Ingresa el nombre de la nueva actividad. " << endl;
	cin >> nombre;
	cout << "  Confirmar? 1. SI || 0. NO" << endl;
	cin >> opc;

	if (opc == 1)
	{
		Actividad actividad(id, nombre, capacidad = 30, lugaresOcupados = 0);
		if (archivoActividad.guardarReg(actividad))
		{
			system("cls");
			cout << endl << endl;
			cout << "  +-------------------------------------+" << endl;
			cout << "  |   Actividad agregada exitosamente   |" << endl;
			cout << "  |   ID actividad #" << id << "                   |" << endl;
			cout << "  +-------------------------------------+ " << endl;
			system("pause");
		}
	}
	else
	{
		cout << "  +------------------------------------------------+" << endl;
		cout << "  |   No se creo la actividad, volve a intentarlo  |" << endl;
		cout << "  +------------------------------------------------+ " << endl;
	}
	system("pause");
}

void ServicioActividad::listarActividades()
{
	system("cls");

	cout << endl << endl;
	cout << "	+---------------------------------------------------------------------+" << endl;
	cout << "	|                        LISTADO DE ACTIVIDADES                       |" << endl;
	cout << "	+---------------------------------------------------------------------+" << endl;
	cout << endl << endl;

	Actividad actividad;
	int contador = 0;
	int cantReg = archivoActividad.cantidadRegistros();

	if (cantReg != 1)
	{
		for (int q = 0; q < cantReg; q++)
		{
			actividad = archivoActividad.leerReg(q);

			cout << string(60, '-') << endl;
			cout << "| ID \t| Nombre " << endl;
			cout << string(60, '-') << endl;
			cout << "| #" << actividad.getIdActividad() << "\t| " << actividad.getIdActividad() << endl;
			cout << string(60, '|-') << endl;
		}
		contador++;

		if (contador % 5 == 0)
		{
			cout << "  Siguiente pagina..." << endl;
			system("pause");
			system("cls");

			contador = 0;
		}
	}

	if (contador == 0)
	{
		cout << endl;
		cout << "   +--------------------------------------------------------------------------------+" << endl;
		cout << "   |   Error en la carga de las actividades, estamos trabajando para solucionarlo   |" << endl;
		cout << "   +--------------------------------------------------------------------------------+" << endl;

		contador = 0;
	}
	system("pause");
}

void ServicioActividad::modificarActividad()
{
	system("cls");

	Actividad actividad;
	int idActividad, opc, pos;
	string nombre;


	cout << endl << endl;
	cout << "   +--------------------------------+" << endl;
	cout << "   |       MODIFICAR ACTIVIDAD      |" << endl;
	cout << "   +--------------------------------+" << endl << endl;

	cout << "  Ingresa el Id de la actividad, si no lo recordas podes listar todas las actividades para identificarlo" << endl;
	cout << "  1. Para modificar la actividad" << endl;
	cout << "  2. Para listar todas las actividades" << endl;
	cin >> opc;

	switch (opc)
	{
	case 1:
		system("cls");
		cout << endl;
		cout << "  ID #" << endl;
		cin >> idActividad;

		pos = archivoActividad.buscarReg(idActividad);
		if (pos != -1)
		{
			actividad = archivoActividad.leerReg(pos);
			cout << "  Nombre actual: " << actividad.getNombreActividad();
			cout << "  Ingresa el nuevo nombre de la actividad" << endl;
			cin >> nombre;
			actividad.setNombreActividad(nombre);

			if (archivoActividad.modificarReg(actividad, pos))
			{
				system("cls");
				cout << endl << endl;
				cout << "  +------------------------------------+" << endl;
				cout << "  |   Actividad modificada con exito   |" << endl;
				cout << "  |   ID actividad #" << idActividad << "                  |" << endl;
				cout << "  +------------------------------------+ " << endl;
				system("pause");
			}
			else
			{
				cout << endl << endl;
				cout << "   +---------------------------------------+" << endl;
				cout << "   |   Hubo un error, volve a intentarlo   |" << endl;
				cout << "   +---------------------------------------+" << endl << endl;
			}

		}
		else
		{
			system("cls");
			cout << endl << endl;
			cout << "  +--------------------------------+" << endl;
			cout << "  |   El ID no existe o pifiaste   |" << endl;
			cout << "  +--------------------------------+ " << endl;
			system("pause");
		}
		break;

	case 2:
		system("cls");
		cout << endl << endl;
		listarActividades();
		break;
	}
}

void ServicioActividad::buscarActividad(int idActividad)
{
	Actividad actividad;

	int pos = archivoActividad.buscarReg(idActividad);

	if (pos != -1)
	{
		system("cls");
		actividad = archivoActividad.leerReg(pos);
		cout << "	+--------------------------------------+" << endl;
		cout << "	|   Actividad: " << actividad.getNombreActividad() << endl;
		cout << "	+--------------------------------------+" << endl;
	}
	else
	{
		system("cls");
		cout << endl << endl;
		cout << "	+-----------------------------+" << endl;
		cout << "	|   Actividad no encontrada   |" << endl;
		cout << "	+-----------------------------+" << endl;
	}

}

bool ServicioActividad::inscribirParticipante()
{
	int capacidad, lugares_ocupados, idActividad;
	Actividad actividad;

	cout << "	+--------------------------------------------------------------------------------------+" << endl;
	cout << "	|					          INSCRIPCION A ACTIVIDAD / CLASE						   |" << endl;
	cout << "	+--------------------------------------------------------------------------------------+" << endl << endl;

	cout << "  Se listaran todas las actividades, recorda el id de la actividad en la que estas interesada/o que te lo solicitaremos para hacer la inscripcion " << endl;

	listarActividades();

	cout << "  Ingresa el id de la actividad a la que te queres anotar: " << endl;
	cin >> idActividad;
	int pos = archivoActividad.buscarReg(idActividad);

	if (pos != -1)
	{
		actividad = archivoActividad.leerReg(pos);
		if (actividad.getLugaresOcupados() < actividad.getCapacidad())
		{
			actividad.setLugaresOcupados(actividad.getLugaresOcupados() + 1);

			cout << "  Inscripcion exitosa!!! Clase/actividad: " << actividad.getNombreActividad() << endl;
			return true;
		}
		else
		{
			cout << "  La clase ya esta llena" << endl;
			return false;
		}
	}
}

void ServicioActividad::mostrarDisponibilidad(int idActividad)
{
	Actividad actividad;

	int pos = archivoActividad.buscarReg(idActividad);
	if (pos != -1)
	{
		actividad = archivoActividad.leerReg(pos);
		cout << "   Actividad: " << actividad.getNombreActividad();
		cout << "   Lugares ocupados: " << actividad.getLugaresOcupados() << "/" << actividad.getCapacidad() << endl;
	}
	else
		cout << "  No hay actividades/clases con ese ID" << endl;
}

bool ServicioActividad::hayLugar(int idActividad)
{
	Actividad actividad;

	int pos = archivoActividad.buscarReg(idActividad);

	if (pos != -1)
	{
		actividad = archivoActividad.leerReg(pos);
		return actividad.getLugaresOcupados() < actividad.getCapacidad();
	}
	else
		cout << "  El ID que ingresaste no existe o pifiaste" << endl;
}
