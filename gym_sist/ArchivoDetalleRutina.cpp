#include <iostream>
#include "ArchivoDetalleRutina.h"
using namespace std;

ArchivoDetalleRutina::ArchivoDetalleRutina() {}

ArchivoDetalleRutina::ArchivoDetalleRutina(string nombreArchivo)
{
	_archivoDetalleRutina = nombreArchivo;
}

bool ArchivoDetalleRutina::guardarReg(DetalleRutina detalle)
{
	FILE* pfile;
	pfile = fopen(_archivoDetalleRutina.c_str(), "ab");
	if (pfile == nullptr) { return false; }

	bool guardado = fwrite(&detalle, sizeof(DetalleRutina), 1, pfile);
	fclose(pfile);

	return guardado;
}

bool ArchivoDetalleRutina::modificarReg(DetalleRutina detalle, int posicion)
{
	FILE* pfile;
	pfile = fopen(_archivoDetalleRutina.c_str(), "rb+");
	if (pfile == nullptr) { return false; }

	fseek(pfile, sizeof(DetalleRutina) * posicion, SEEK_SET);
	bool modificado = fwrite(&detalle, sizeof(DetalleRutina), 1, pfile);
	fclose(pfile);

	return modificado;
}

DetalleRutina ArchivoDetalleRutina::leerReg(int posicion)
{
	DetalleRutina detalle;

	FILE* pfile;
	pfile = fopen(_archivoDetalleRutina.c_str(), "rb");
	if (pfile == nullptr) { return DetalleRutina(); }

	fseek(pfile, sizeof(DetalleRutina) * posicion, SEEK_SET);
	fread(&detalle, sizeof(DetalleRutina), 1, pfile);
	fclose(pfile);

	return detalle;
}

int ArchivoDetalleRutina::cantidadRegistros()
{
	int cantidad;

	FILE* pfile;
	pfile = fopen(_archivoDetalleRutina.c_str(), "rb");
	if (pfile == nullptr) { return -1; }

	fseek(pfile, 0, SEEK_END);
	cantidad = ftell(pfile) / sizeof(DetalleRutina);
	fclose(pfile);

	return cantidad;
}

void ArchivoDetalleRutina::leerRegistros(int cantidadRegistros, DetalleRutina* detalleRutina)
{
	FILE* pfile;
	pfile = fopen(_archivoDetalleRutina.c_str(), "rb");
	if (pfile == nullptr) { return; }

	for (int i = 0; i < cantidadRegistros; i++)
	{
		fread(&detalleRutina[i], sizeof(DetalleRutina), 1, pfile);
	}

	fclose(pfile);
}

int ArchivoDetalleRutina::buscarReg(int idRutina)
{
	int posicion = 0;
	DetalleRutina detalle;

	FILE* pfile;
	pfile = fopen(_archivoDetalleRutina.c_str(), "rb");
	if (pfile == nullptr) { return -2; }

	while (fread(&detalle, sizeof(DetalleRutina), 1, pfile))
	{
		if (detalle.getIdRutina() == idRutina)
		{
			fclose(pfile);
			return posicion;
		}
		posicion++;
	}
	fclose(pfile);

	return -1;
}