#include <iostream>
#include "ArchivoAsistencia.h"
using namespace std;

ArchivoAsistencia::ArchivoAsistencia() {}

ArchivoAsistencia::ArchivoAsistencia(string nombreArchivo)
{
	archivoAsistencia = nombreArchivo;
}

bool ArchivoAsistencia::guardarReg(Asistencia asistencia)
{
	FILE* pfile;
	pfile = fopen(archivoAsistencia.c_str(), "ab");
	if (pfile == nullptr) { return false; }

	bool guardado = fwrite(&asistencia, sizeof(Asistencia), 1, pfile);
	fclose(pfile);

	return guardado;
}

bool ArchivoAsistencia::modificarReg(Asistencia asistencia, int posicion)
{
	FILE* pfile;
	pfile = fopen(archivoAsistencia.c_str(), "rb+");
	if (pfile == nullptr) { return false; }

	fseek(pfile, sizeof(Asistencia) * posicion, SEEK_SET);
	bool modificado = fwrite(&asistencia, sizeof(Asistencia), 1, pfile);
	fclose(pfile);

	return modificado;
}

Asistencia ArchivoAsistencia::leerReg(int posicion)
{
	Asistencia asistencia;

	FILE* pfile;
	pfile = fopen(archivoAsistencia.c_str(), "rb");
	if (pfile == nullptr) { return Asistencia(); }

	fseek(pfile, sizeof(Asistencia) * posicion, SEEK_SET);
	fread(&asistencia, sizeof(Asistencia), 1, pfile);
	fclose(pfile);

	return asistencia;
}

int ArchivoAsistencia::cantidadRegistros()
{
	int cantidad;
	FILE* pfile;
	pfile = fopen(archivoAsistencia.c_str(), "rb");
	if (pfile == nullptr) { return -1; }

	fseek(pfile, 0, SEEK_END);
	cantidad = ftell(pfile) / sizeof(Asistencia);
	fclose(pfile);

	return cantidad;
}

void ArchivoAsistencia::leerRegistros(int cantidadRegistros, Asistencia *asistencias)
{
	FILE* pfile;
	pfile = fopen(archivoAsistencia.c_str(), "rb");
	if (pfile == nullptr) { return; }
	
	for (int i = 0; i < cantidadRegistros; i++)
	{
		fread(&asistencias[i], sizeof(Asistencia), 1, pfile);
	}

	fclose(pfile);
}

int ArchivoAsistencia::buscarReg(int idSocio)
{
	int posicion = 0;
	Asistencia asistencia;

	FILE* pfile;
	pfile = fopen(archivoAsistencia.c_str(), "rb");
	if (pfile == nullptr) { return -2; }

	while (fread(&asistencia, sizeof(Asistencia), 1, pfile))
	{
		if (asistencia.getIdSocio() == idSocio)
		{
			fclose(pfile);
			return posicion;
		}
		posicion++;
	}
	fclose(pfile);

	return -1;
}