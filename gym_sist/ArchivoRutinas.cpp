#include <iostream>
#include "ArchivoRutinas.h"
using namespace std;

ArchivoRutinas::ArchivoRutinas() {}

ArchivoRutinas::ArchivoRutinas(string nombreArchivo)
{
	archivoRutinas = nombreArchivo;
}

bool ArchivoRutinas::guardarReg(Rutina rutina)
{
	FILE* pfile;
	pfile = fopen(archivoRutinas.c_str(), "ab");
	if (pfile == nullptr) { return false; }

	bool guardado = fwrite(&rutina, sizeof(Rutina), 1, pfile);
	fclose(pfile);

	return guardado;
}

bool ArchivoRutinas::modificarReg(Rutina rutina, int posicion)
{
	FILE* pfile;
	pfile = fopen(archivoRutinas.c_str(), "rb+");
	if (pfile == nullptr) { return false; }

	fseek(pfile, sizeof(Rutina) * posicion, SEEK_SET);
	bool modificado = fwrite(&rutina, sizeof(Rutina), 1, pfile);
	fclose(pfile);

	return modificado;
}

Rutina ArchivoRutinas::leerReg(int posicion)
{
	Rutina rutina;

	FILE* pfile;
	pfile = fopen(archivoRutinas.c_str(), "rb");
	if (pfile == nullptr) { return Rutina(); }

	fseek(pfile, sizeof(Rutina) * posicion, SEEK_SET);
	fread(&rutina, sizeof(Rutina), 1, pfile);
	fclose(pfile);

	return rutina;
}

int ArchivoRutinas::cantidadRegistros()
{
	int cantidad;

	FILE* pfile;
	pfile = fopen(archivoRutinas.c_str(), "rb");
	if (pfile == nullptr) { return -1; }

	fseek(pfile, 0, SEEK_END);
	cantidad = ftell(pfile) / sizeof(Rutina);
	fclose(pfile);

	return cantidad;
}

void ArchivoRutinas::leerRegistros(int cantidadRegistros, Rutina* rutinas)
{
	FILE* pfile;
	pfile = fopen(archivoRutinas.c_str(), "rb");
	if (pfile == nullptr) { return; }

	for (int i = 0; i < cantidadRegistros; i++)
	{
		fread(&rutinas[i], sizeof(Rutina), 1, pfile);
	}

	fclose(pfile);
}

int ArchivoRutinas::buscarReg(int idRutina)
{
	int posicion = 0;
	Rutina rutina;

	FILE* pfile;
	pfile = fopen(archivoRutinas.c_str(), "rb");
	if (pfile == nullptr) { return -1; }

	while (fread(&rutina, sizeof(Rutina), 1, pfile))
	{
		if (rutina.getIdRutina() == idRutina)
		{
			fclose(pfile);
			return posicion;
		}
		posicion++;
	}
	fclose(pfile);

	return -1;
}


int ArchivoRutinas::cantidadRutinasPorEntrenador(int cantidadRegistros, int idEntrenador)
{
	int cont = 0;
	Rutina rutina;

	FILE* pfile;
	pfile = fopen(archivoRutinas.c_str(), "rb");
	if (pfile == nullptr) { return -1; }

	for (int i = 0; i < cantidadRegistros; i++)
	{
		fread(&rutina, sizeof(Rutina), 1, pfile);
		if (rutina.getIdEntrenador() == idEntrenador)
		{
			cont++;
		}
	}
	fclose(pfile);

	return cont;
}

int ArchivoRutinas::rutinasPorEntrenador(int cantidadRegistros, int rutinas[], int idEntrenador)
{
	int indice = 0;
	Rutina rutina;

	FILE* pfile;
	pfile = fopen(archivoRutinas.c_str(), "rb");
	if (pfile == nullptr) { return -1; }

	for (int i = 0; i < cantidadRegistros; i++)
	{
		fread(&rutina, sizeof(Rutina), 1, pfile);
		if (rutina.getIdEntrenador() == idEntrenador)
		{
			rutinas[indice] = i;
			indice++;
		}
	}
	fclose(pfile);

	return *rutinas;
}


