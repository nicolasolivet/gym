#include <iostream>
#include "DetalleRutina.h"
using namespace std;

DetalleRutina::DetalleRutina() {}

DetalleRutina::DetalleRutina(int* idEjercicio, int idRutina, int* repeticiones, float* peso)
{
	setIdEjercicio(idEjercicio);
	setIdRutina(idRutina);
	setRepeticiones(repeticiones);
	setPeso(peso);
}

void DetalleRutina::setIdEjercicio(int* idEjercicio)
{
	for (int i = 0; i < 10; i++) {
		this->idEjercicio[i] = idEjercicio[i];
	}
}

void DetalleRutina::setIdRutina(int idRutina)
{
	this->idRutina = idRutina;
}

void DetalleRutina::setRepeticiones(int* repeticiones)
{
	for (int i = 0; i < 10; i++) {
		this->repeticiones[i] = repeticiones[i];
	}
}

void DetalleRutina::setPeso(float* peso)
{
	for (int i = 0; i < 10; i++)
	{
		this->peso[i] = peso[i];
	}
}


int* DetalleRutina::getIdEjercicio()
{
	return idEjercicio;
}
int DetalleRutina::getIdRutina()
{
	return idRutina;
}
int* DetalleRutina::getRepeticiones()
{
	return repeticiones;
}
float* DetalleRutina::getPeso()
{
	return peso;
}
