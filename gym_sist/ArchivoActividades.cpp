#include <iostream>
#include "ArchivoActividades.h"

using namespace std;

ArchivoActividades::ArchivoActividades() {}

ArchivoActividades::ArchivoActividades(string nombreArchivo)
{
	archivoActividades = nombreArchivo;
}

bool ArchivoActividades::guardarReg(Actividad actividad)
{
	FILE* pfile;
	pfile = fopen(archivoActividades.c_str(), "ab");
	if (pfile == nullptr) { return false; }

	bool guardado = fwrite(&actividad, sizeof(Actividad), 1, pfile);
	fclose(pfile);

	return guardado;
}

bool ArchivoActividades::modificarReg(Actividad actividad, int posicion)
{
	FILE* pfile;
	pfile = fopen(archivoActividades.c_str(), "rb+");
	if (pfile == nullptr) { return false; }

	fseek(pfile, sizeof(Actividad) * posicion, SEEK_SET);
	bool modificado = fwrite(&actividad, sizeof(Actividad), 1, pfile);
	fclose(pfile);

	return modificado;
}

Actividad ArchivoActividades::leerReg(int posicion)
{
	Actividad actividad;

	FILE* pfile;
	pfile = fopen(archivoActividades.c_str(), "rb");
	if (pfile == nullptr) { return Actividad(); }

	fseek(pfile, sizeof(Actividad) * posicion, SEEK_SET);
	fread(&actividad, sizeof(Actividad), 1, pfile);
	fclose(pfile);

	return actividad;
}

int ArchivoActividades::cantidadRegistros()
{
	int cantidad;

	FILE* pfile;
	pfile = fopen(archivoActividades.c_str(), "rb");
	if (pfile == nullptr) { return -1; }

	fseek(pfile, 0, SEEK_END);
	cantidad = ftell(pfile) / sizeof(Actividad);
	fclose(pfile);

	return cantidad;
}

void ArchivoActividades::leerRegistros(int cantidadRegistros, Actividad* actividades)
{
	FILE* pfile;
	pfile = fopen(archivoActividades.c_str(), "rb");
	if (pfile == nullptr) { return; }

	for (int i = 0; i < cantidadRegistros; i++)
	{
		fread(&actividades[i], sizeof(Actividad), 1, pfile);
	}

	fclose(pfile);
}

int ArchivoActividades::buscarReg(int idActividad)
{
	int posicion = 0;
	Actividad actividad;

	FILE* pfile;
	pfile = fopen(archivoActividades.c_str(), "rb");
	if (pfile == nullptr) { return -2; }

	while (fread(&actividad, sizeof(Actividad), 1, pfile))
	{
		if (actividad.getIdActividad() == idActividad)
		{
			fclose(pfile);
			return posicion;
		}
		posicion++;
	}

	fclose(pfile);

	return -1;
}

