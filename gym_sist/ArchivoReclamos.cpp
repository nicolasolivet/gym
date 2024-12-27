#include <iostream>
#include "ArchivoReclamos.h"
using namespace std;

ArchivoReclamos::ArchivoReclamos() {}

ArchivoReclamos::ArchivoReclamos(string nombreArchivo)
{
	_nombreArchivo = nombreArchivo;
}

bool ArchivoReclamos::guardarReg(const Reclamo& r)
{
	FILE* pfile;
	pfile = fopen(_nombreArchivo.c_str(), "ab");
	if (pfile == nullptr) { return false; }

	bool guardado = fwrite(&r, sizeof(Reclamo), 1, pfile);
	fclose(pfile);

	return guardado;
}

Reclamo ArchivoReclamos::leerReg(int pos)
{
	Reclamo r;
	FILE* pfile;
	pfile = fopen(_nombreArchivo.c_str(), "rb");
	if (pfile == nullptr) { return r; }

	fseek(pfile, sizeof(Reclamo) * pos, SEEK_SET);
	fread(&r, sizeof(Reclamo), 1, pfile);
	fclose(pfile);

	return r;
}

int ArchivoReclamos::cantidadRegistros()
{
	int cantReg;
	Reclamo r;
	FILE* pfile;
	pfile = fopen(_nombreArchivo.c_str(), "rb");
	if (pfile == nullptr) { return 0; }

	fseek(pfile, 0, SEEK_END);
	cantReg = ftell(pfile);
	fclose(pfile);

	return cantReg / sizeof(Reclamo);
}

void ArchivoReclamos::leerRegistros(Reclamo reclamos[], int cantReclamos)
{
	FILE* pfile;
	pfile = fopen(_nombreArchivo.c_str(), "rb");

	if (pfile == nullptr) { return; }

	for (int i = 0; i < cantReclamos; i++)
	{
		fread(&reclamos[i], sizeof(Reclamo), 1, pfile);
	}

	fclose(pfile);
}

bool ArchivoReclamos::modificarReg(Reclamo& r, int pos)
{
	FILE* pfile;
	pfile = fopen(_nombreArchivo.c_str(), "rb+");
	if (pfile == nullptr) { return false; }

	fseek(pfile, sizeof(Reclamo) * pos, SEEK_SET);
	bool modificado = fwrite(&r, sizeof(Reclamo), 1, pfile);
	fclose(pfile);

	return modificado;
}


///filtros
int ArchivoReclamos::buscarReg(int idUsuario)
{
	Reclamo r;
	int pos = 0;

	FILE* pfile;
	pfile = fopen(_nombreArchivo.c_str(), "rb");
	if (pfile == nullptr) { return 0; }

	while (fread(&r, sizeof(Reclamo), 1, pfile) == 1)
	{
		if (r.getIdReclamo() == idUsuario)
		{
			break;
		}
		pos++;
	}

	fclose(pfile);

	if (r.getIdReclamo() == idUsuario)
		return pos;
	else
		return -1;
}

int ArchivoReclamos::cantidadReclamosPorUsuario(int cantidadRegistros, int idUsuario)
{
	int cont = 0;
	Reclamo reclamo;

	FILE* pArchivo;
	pArchivo = fopen(_nombreArchivo.c_str(), "rb");
	if (pArchivo == nullptr) { return -1; }

	for (int i = 0; i < cantidadRegistros; i++)
	{
		fread(&reclamo, sizeof(Reclamo), 1, pArchivo);
		if (reclamo.getIdUsuario() == idUsuario)
		{
			cont++;
		}
	}

	fclose(pArchivo);

	return cont;
}

int ArchivoReclamos::leerReclamosPorUsuario(int cantidadRegistros, int vectReclamos[], int idUsuario)
{
	int indice = 0;
	Reclamo reclamo;

	FILE* pArchivo;
	pArchivo = fopen(_nombreArchivo.c_str(), "rb");
	if (pArchivo == nullptr) { return -1; }

	for (int i = 0; i < cantidadRegistros; i++)
	{
		fread(&reclamo, sizeof(Reclamo), 1, pArchivo);
		if (reclamo.getIdUsuario() == idUsuario)
		{
			vectReclamos[indice] = i;
			indice++;
		}
	}

	fclose(pArchivo);

	return *vectReclamos;
}


