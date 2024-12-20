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

void Fecha::setDia(int d)
{
	_dia = d;
}

void Fecha::setMes(int m)
{
	_mes = m;
}

void Fecha::setAnio(int a)
{
	_anio = a;
}

int Fecha::getDia() const { return _dia; }

int Fecha::getMes() const { return _mes; }

int Fecha::getAnio() const { return _anio; }


void Fecha::setFechaDefecto()
{
	_dia = 1;
	_mes = 1;
	_anio = 1;

	cout << _dia << _mes << _anio << endl;
}

void Fecha::establecerFechaActual()
{
	time_t timestamp = time(0);

	tm* diaActual = localtime(&timestamp);

	_dia = diaActual->tm_mday;

	_mes = diaActual->tm_mon + 1;

	_anio = diaActual->tm_year + 1900;
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

int Fecha::diasPorMes() {
	int diasPorMeses[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
}

bool Fecha::validarDia()
{
	return _dia >= 1 && _dia <= diasPorMes(_mes, _anio);
}

bool Fecha::validarMes()
{
	return _mes > 0 && _mes <= 12;
}

bool Fecha::validarAnio()
{
	return _anio > 0;
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
	return std::to_string(_dia) + "/" + std::to_string(_mes) + "/" + std::to_string(_anio);
}

bool Fecha::compararSiFechasSonIguales(Fecha fecha)
{
	if (_anio == fecha.getAnio() && _mes == fecha.getMes() && _dia == fecha.getDia())
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

