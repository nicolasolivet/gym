#include <iostream>
#include <cstring>
#include "ServicioAsistencia.h"
#include "Fecha.h"
#include "Asistencia.h"
using namespace std;


ServicioAsistencia::ServicioAsistencia()
{
	archivoAsistencia = ArchivoAsistencia("archivoAsistencia.dat");
}

bool ServicioAsistencia::validarRegistroDeAsistencia(int idSocio, Fecha fechaActual)
{
	Asistencia asist;

	int cantAsist = archivoAsistencia.cantidadRegistros();
	for (int q = 0; q < cantAsist; q++)
	{
		asist = archivoAsistencia.leerReg(q);
		if (fechaActual.compararSiFechasSonIguales(asist.getFecha()) && idSocio == asist.getIdSocio())
		{
			return false;
			//quiere decir que alguien ya registro la asistencia en el dia
		}
	}
	return true;
}

void ServicioAsistencia::registrarAsistencia(int idSocio)
{
	Fecha fechActual = Fecha();
	if (validarRegistroDeAsistencia(idSocio, fechActual))
	{
		Asistencia asist = Asistencia(idSocio, fechActual);

		if (archivoAsistencia.guardarReg(asist))
		{
			system("cls");
			cout << "   +------------------------------------------+" << endl;
			cout << "   |   Asistencia resgistrada exitosamente!   |" << endl;
			cout << "   +------------------------------------------+" << endl;
		}
	}
	else
	{
		system("cls");
		cout << "+---------------------------------------------------+" << endl;
		cout << "|   Ya se registro tu asistencia en el dia de hoy   |" << endl;
		cout << "+---------------------------------------------------+" << endl;
	}
}

void ServicioAsistencia::verTodasLasAsistencias()
{
	system("cls");

	cout << "       +--------------------------------------------+" << endl;
	cout << "       |      LISTADO DE TODAS LAS ASISTENCIAS      |" << endl;
	cout << "       +--------------------------------------------+" << endl;

	Asistencia asist;
	int cantAsist = archivoAsistencia.cantidadRegistros();

	for (int q = 0; q < cantAsist; q++)
	{
		asist = archivoAsistencia.leerReg(q);

		cout << string(60, '-') << endl;
		cout << "| Fecha \t|Socio ID \t" << endl;
		cout << string(60, '-') << endl;

		cout << asist.getFecha().toString() << "\t" << " #" << asist.getIdSocio() << " \t|" << endl;
	}
	system("pause");
}

void ServicioAsistencia::verAsistenciaPorSocio(int idSocio)
{
	system("cls");

	Asistencia asist;
	int cantReg = archivoAsistencia.cantidadRegistros();

	if (cantReg > -1)
	{
		for (int q = 0; q < cantReg; q++)
		{
			asist = archivoAsistencia.leerReg(q);
			if (asist.getIdSocio() == idSocio)
			{
				cout << string(60, '-') << endl;
				cout << "| Fecha \t|Socio ID \t" << endl;
				cout << string(60, '-') << endl;

				cout << asist.getFecha().toString() << "\t" << " #" << asist.getIdSocio() << " \t|" << endl;
			}
		}
	}
	system("pause");
}

void ServicioAsistencia::verAsistenciasEnPeriodo(int mes, int anio)
{    
	system("cls");

	Asistencia asist;
	int cantReg = archivoAsistencia.cantidadRegistros();

	if (cantReg > -1)
	{
		for (int q = 0; q < cantReg; q++)
		{
			asist = archivoAsistencia.leerReg(q);
			if (asist.getFecha().getMes() == mes && asist.getFecha().getAnio() == anio)
			{
				cout << string(60, '-') << endl;
				cout << "| Fecha \t|Socio ID \t" << endl;
				cout << string(60, '-') << endl;

				cout << asist.getFecha().toString() << "\t" << " #" << asist.getIdSocio() << " \t|" << endl;
			}
		}
	}
	system("pause");
}

void ServicioAsistencia::verAsistenciasEnAnio(int anio) 
{
	system("cls");

	Asistencia asist;
	int cantReg = archivoAsistencia.cantidadRegistros();

	if (cantReg > -1)
	{
		for (int q = 0; q < cantReg; q++)
		{
			asist = archivoAsistencia.leerReg(q);
			if (asist.getFecha().getAnio() == anio)
			{
				cout << string(60, '-') << endl;
				cout << "| Fecha \t|Socio ID \t" << endl;
				cout << string(60, '-') << endl;

				cout << asist.getFecha().toString() << "\t" << " #" << asist.getIdSocio() << " \t|" << endl;
			}
		}
	}
	system("pause");
}


