#include <iostream>
#include "ArchivoEmpleados.h"

using namespace std;

ArchivoEmpleados::ArchivoEmpleados() {}

ArchivoEmpleados::ArchivoEmpleados(string nombreArchivo)
{
	archivoEmpleados = nombreArchivo;
}

bool ArchivoEmpleados::guardarReg(Empleado empleado)
{
	FILE* pfile;
	pfile = fopen(archivoEmpleados.c_str(), "ab");
	if (pfile == nullptr) { return false; }

	bool guardado = fwrite(&empleado, sizeof(Empleado), 1, pfile);
	fclose(pfile);

	return guardado;
}

bool ArchivoEmpleados::modificarReg(Empleado empleado, int posicion)
{
	FILE* pfile;
	pfile = fopen(archivoEmpleados.c_str(), "rb+");
	if (pfile == nullptr) { return false; }

	fseek(pfile, sizeof(Empleado) * posicion, SEEK_SET);
	bool modificado = fwrite(&empleado, sizeof(Empleado), 1, pfile);
	fclose(pfile);

	return modificado;
}

Empleado ArchivoEmpleados::leerReg(int posicion)
{
	Empleado empleado;

	FILE* pfile;
	pfile = fopen(archivoEmpleados.c_str(), "rb");
	if (pfile == nullptr) { return Empleado(); }

	fseek(pfile, sizeof(Empleado) * posicion, SEEK_SET);
	fread(&empleado, sizeof(Empleado), 1, pfile);
	fclose(pfile);

	return empleado;
}

int ArchivoEmpleados::cantidadRegistros()
{
	int cantidad;

	FILE* pfile;
	pfile = fopen(archivoEmpleados.c_str(), "rb");
	if (pfile == nullptr) { return -1; }

	fseek(pfile, 0, SEEK_END);
	cantidad = ftell(pfile) / sizeof(Empleado);
	fclose(pfile);

	return cantidad;
}

void ArchivoEmpleados::leerRegistros(int cantidadRegistros, Empleado* vectEmpleado)
{
	FILE* pfile;

	pfile = fopen(archivoEmpleados.c_str(), "rb");

	if (pfile == nullptr)
	{
		return;
	}

	for (int i = 0; i < cantidadRegistros; i++)
	{
		fread(&vectEmpleado[i], sizeof(Empleado), 1, pfile);
	}

	fclose(pfile);
}

int ArchivoEmpleados::buscarReg(int idEmpleado)
{
	int posicion = 0;

	Empleado empleado;
	FILE* pfile;
	pfile = fopen(archivoEmpleados.c_str(), "rb");
	if (pfile == nullptr) { return -2; }

	while (fread(&empleado, sizeof(Empleado), 1, pfile))
	{
		if (empleado.getIdUsuario() == idEmpleado)
		{
			fclose(pfile);
			return posicion;
		}
		posicion++;
	}
	fclose(pfile);

	return -1;
}


int ArchivoEmpleados::cantidadEmpleadosPorEstado(int cantidadRegistros, bool estado, int idRol)
{
	int contador = 0;
	Empleado empleado;

	FILE* pfile;
	pfile = fopen(archivoEmpleados.c_str(), "rb");
	if (pfile == nullptr) { return -1; }

	for (int i = 0; i < cantidadRegistros; i++)
	{
		fread(&empleado, sizeof(Empleado), 1, pfile);
		if (empleado.getIdRol() == idRol && empleado.getEstado() == estado)
		{
			contador++;
		}
	}
	fclose(pfile);

	return contador;
}

int ArchivoEmpleados::empleadosActivos(int cantReg, int empleados[], int idRol)
{
	int indice = 0;
	Empleado empleado;

	FILE* pfile;
	pfile = fopen(archivoEmpleados.c_str(), "rb");
	if (pfile == nullptr) { return -1; }

	for (int i = 0; i < cantReg; i++)
	{
		fread(&empleado, sizeof(Empleado), 1, pfile);
		if (empleado.getIdRol() == idRol && empleado.getEstado() == true)
		{
			empleados[indice] = i;
			indice++;
		}
	}
	fclose(pfile);
	
	return *empleados;
}

