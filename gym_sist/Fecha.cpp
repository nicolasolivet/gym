#include <iostream>
#include <ctime>
#include "Fecha.h"

using namespace std;

Fecha::Fecha()
{
	establecerFechaActual();
}

Fecha::Fecha(int d, int m, int a)
{
	setDia(d);
	setMes(m);
	setAnio(a);

	validarFecha();
}

void Fecha::establecerFechaActual()
{
	time_t timestamp = time(0);

	tm* fechaActual = localtime(&timestamp);

	dia = fechaActual->tm_mday;

	mes = fechaActual->tm_mon + 1;

	anio = fechaActual->tm_year + 1900;
}

void Fecha::setDia(int d)
{
	dia = d;
}

void Fecha::setMes(int m)
{
	mes = m;
}

void Fecha::setAnio(int a)
{
	anio = a;
}

int Fecha::getDia() const { return dia; }

int Fecha::getMes() const { return mes; }

int Fecha::getAnio() const { return anio; }

void Fecha::setFechaDefecto()
{
	dia = 1;
	mes = 1;
	anio = 1;

	cout << dia << mes << anio << endl;
}

int Fecha::diasPorMes(int mes, int anio)
{
	int diasPorMeses[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (mes == 2 && esBisiesto(anio))
	{
		return 29;
	}
	else
	{
		return diasPorMeses[mes - 1];
	}
}

bool Fecha::validarDia()
{
	return dia >= 1 && dia <= diasPorMes(mes, anio);
}

bool Fecha::validarMes()
{
	return mes > 0 && mes <= 12;
}

bool Fecha::validarAnio()
{
	return anio > 0;
}

void Fecha::validarFecha()
{
	if (!validarDia() || !validarMes() || !validarAnio())
	{
		setFechaDefecto();
	}
}

bool Fecha::esBisiesto(int anio)
{
	return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

string Fecha::toString()
{
	return std::to_string(dia) + "/" + std::to_string(mes) + "/" + std::to_string(anio);
}

bool Fecha::compararSiFechasSonIguales(Fecha fecha)
{
	if (anio == fecha.getAnio() && mes == fecha.getMes() && dia == fecha.getDia())
	{
		return true;
	}
}

Fecha Fecha::calcularDiasParaVencimiento(Fecha fechaVencimiento)
{
	int dia = fechaVencimiento.getDia() + 35;
	int mes = fechaVencimiento.getMes();
	int anio = fechaVencimiento.getAnio();

	while (dia > diasPorMes(mes, anio))
	{
		dia -= diasPorMes(mes, anio);
		mes++;

		if (mes > 12)
		{
			mes = 1;
			anio++;
		}
	}
	return Fecha(dia, mes, anio);
}

Fecha Fecha::crearFecha()
{
	int dia, mes, anio;
	cout << endl;
	cout << " Ingrese dia: ";
	cin >> dia;
	cout << " Ingrese mes: ";
	cin >> mes;
	cout << " Ingrese anio: ";
	cin >> anio;

	return Fecha(dia, mes, anio);
}

