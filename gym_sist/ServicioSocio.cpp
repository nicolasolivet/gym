#include <iostream>
#include <iomanip>
#include <string>
#include "Socio.h"
#include "Fecha.h"
#include "ServicioSocio.h"

using namespace std;

ServicioSocio::ServicioSocio()
{
	_archivoSocio = ArchivoSocios("archivoSocios.dat");
	//_archivoEmpleado = ArchivoEmpleados("archivoEmpleados.dat");
}

int ServicioSocio::autoGenerarId()
{
	return 0 + _archivoSocio.cantidadRegistros(); //agregar archivoEmpleado.cantidadRegistros();
} 

void ServicioSocio::agregarSocio()
{
	system("cls");
	int idUsuario = autoGenerarId();
	string nombre;
	string apellido;
	int dni;
	Fecha fechaNacimiento;
	Fecha fechaIngreso;
	string contrasenia;
	string contrasenia1;
	bool estado;
	string estadoFisico;
	int membresia;
	int idRol = 2;
	int idRutina = 0;
	int idEntrenadorAsignado = 0;

	cout << "+---------------------------------+" << endl;
	cout << "|           AGREGAR SOCIO         |" << endl;
	cout << "+---------------------------------+" << endl;
	cout << endl;

	cout << "  Ingresa un DNI: " << endl;
	cin >> dni;

	if (buscarSocioPorDni(dni))
	{
		cout << endl;
		cout << " | El socio ingresado ya existe | " << endl;
		cout << endl;
		system("pause");
	}

	estado = true;

	cout << "  Ingresa un nombre: ";
	cin >> nombre;

	cout << "  Ingresa un apellido: ";
	cin >> apellido;

	cout << "  Ingresa fecha de nacimiento: ";
	cout << endl;
	fechaNacimiento = Fecha::crearFecha();
	cout << "  Ingresa fecha de ingreso: ";
	cout << endl;
	fechaIngreso = Fecha::crearFecha();

	while (contrasenia != contrasenia1)
	{
		cout << "  Crea una contrasenia por favor: ";
		cin >> contrasenia;
		cout << "  Confirma la contrasenia: ";
		cin >> contrasenia1;
		
		if (contrasenia == contrasenia1)
			contrasenia = contrasenia;
	}

	membresia = seleccionarMembresia();

	cout << "  Ingresa el estado fisico: ";
	cin >> estadoFisico;

	Socio socio(nombre, apellido, dni, idUsuario, fechaNacimiento, fechaIngreso, contrasenia, estado, idRol, membresia, estadoFisico, idRutina, idEntrenadorAsignado);

	if (_archivoSocio.guardarReg(socio)) 
	{
		cout << "+--------------------------------------+" << endl;
		cout << "|     Socio agregado exitosamente.     |" << endl;
		cout << "+--------------------------------------+" << endl;
	}
	else {
		cout << "+--------------------------------------------+" << endl;
		cout << "|     Hubo un error, volve a intentarlo.     |" << endl;
		cout << "+--------------------------------------------+" << endl;
	}

	system("pause");
}

void ServicioSocio::verSociosPorId() 
{
	cout << "  +---------------------------------+" << endl;
	cout << "  |         LISTADO DE SOCIOS       |" << endl;
	cout << "  +---------------------------------+" << endl;
	cout << endl;
	
	int cantReg = _archivoSocio.cantidadRegistros();
	Socio *socios;
	socios = new Socio[cantReg];
	if (socios == nullptr) {
		cout << "+-----------------------------+" << endl;
		cout << "|       NO EXISTEN SOCIOS     |" << endl;
		cout << "+-----------------------------+" << endl;

		return;
		system("pause");
	}

	for (int i = 0; i < cantReg; i++)
	{
		socios[i] = _archivoSocio.leerReg(i);
	}

	Socio aux;
	for (int j = 0; j < cantReg; j++)
	{
		for (int k = 0; k < cantReg-1; k++)
		{
			if(socios[k].getIdUsuario() > socios[k+1].getIdUsuario())
			{
				aux = socios[k+1];
				socios[k + 1] = socios[k];
				socios[k] = aux;
			}
		}
	}

	listarSocios(socios, cantReg);
	delete[]socios;
}

void ServicioSocio::verSociosPorApellido() 
{
	cout << "  +---------------------------------------------+" << endl;
	cout << "  |         LISTADO DE SOCIOS POR APELLIDO      |" << endl;
	cout << "  +---------------------------------------------+" << endl;
	cout << endl; 

	int cantReg = _archivoSocio.cantidadRegistros();
	Socio *socios;
	socios = new Socio[cantReg];
	if (socios == nullptr) {
		cout << "+-----------------------------+" << endl;
		cout << "|       NO EXISTEN SOCIOS     |" << endl;
		cout << "+-----------------------------+" << endl;

		return;
	}

	for (int i = 0; i < cantReg; i++)
	{
		socios[i] = _archivoSocio.leerReg(i);
	}

	Socio aux;
	for (int i = 0; i < cantReg; i++)
	{
		for (int h = 0; h < cantReg-1; h++)
		{
			if (socios[h].getApellido() > socios[h+1].getApellido())
			{
				aux = socios[h+1];
				socios[h + 1] = socios[h];
				socios[h] = aux;
			}
		}
	}

	listarSocios(socios, cantReg);
	delete[]socios;
}

void ServicioSocio::verSociosPorDni() 
{
	cout << "  +----------------------------------------+" << endl;
	cout << "  |         LISTADO DE SOCIOS POR DNI      |" << endl;
	cout << "  +----------------------------------------+" << endl;
	cout << endl;

	int cantReg = _archivoSocio.cantidadRegistros();
	Socio* socios;
	socios = new Socio[cantReg];
	if (socios == nullptr) {
		cout << "+-----------------------------+" << endl;
		cout << "|       NO EXISTEN SOCIOS     |" << endl;
		cout << "+-----------------------------+" << endl;

		return;
		system("pause");
	}

	for (int x = 0; x < cantReg; x++)
	{
		socios[x] = _archivoSocio.leerReg(x);
	}

	Socio aux;
	for (int y = 0; y < cantReg; y++)
	{
		for (int z = 0; z < cantReg-1; z++)
		{
			if (socios[z].getDni() > socios[z+1].getDni())
			{
				aux = socios[z + 1];
				socios[z + 1] = socios[z];
				socios[z] = aux;
			}
		}
	}
	
	listarSocios(socios, cantReg);
	delete[]socios;
}

void ServicioSocio::listarSocios(Socio* socios, int cantReg)
{
	Socio socio;

	cout << string(100, '-') << endl;
	cout << left << setw(5) << "ID" << "|"
		<< setw(13) << "Apellido" << "|"
		<< setw(12) << "Nombre" << "|"
		<< setw(14) << "Fecha Ing." << "|"
		<< setw(30) << "Membresia" << "|"
		<< setw(20) << "Estado" << endl;
	cout << string(100, '-') << endl;

	for (int i = 0; i < cantReg; i++)
	{
		socio = socios[i];
		//cout << string(78, '-') << endl;
		cout << left << setw(5) << socio.getIdUsuario() << "|"
			<< setw(13) << socio.getApellido() << "|"
			<< setw(12) << socio.getNombre() << "|"
			<< setw(14) << socio.getFechaIngreso().toString() << "|"
			<< setw(30) << membresiaToStr(socio.getMembresia()).c_str() << "|"
			<< setw(20) << (socio.getEstado() ? "Habilitado" : "Deshabilitado") << endl;
		cout << string(100, '-') << endl;
	}
	system("pause");
}

Socio ServicioSocio::buscarSocio(int idUsuario) 
{


	int pos = _archivoSocio.buscarReg(idUsuario);
	if (pos == -1)
	{
		cout << " | El socio con el ID ingresado no existe |  ";
		return Socio();
	}
	
	Socio socio = _archivoSocio.leerReg(pos);
	
	return socio;
}

void ServicioSocio::buscarSocioPorId() 
{
	system("cls");

	int idSocio;
	cout << "+----------------------------------------+" << endl;
	cout << "|               BUSCAR SOCIO             |" << endl;
	cout << "+----------------------------------------+" << endl;
	cout << endl;
	cout << " Ingrese ID: ";
	cin >> idSocio;

	int pos = _archivoSocio.buscarReg(idSocio);

	if (pos == -1) {
		cout << "El socio no existe.";
		system("pause");
		return;
	}

	Socio socio = _archivoSocio.leerReg(pos);

	cout << string(78, '-') << endl;
	cout << left << setw(6) << "ID: " << "|"
		<< setw(5) << "Apellido: " << "|"
		<< setw(5) << "Nombre: " << "|"
		<< setw(5) << "Fecha de ingreso: " << "|"
		<< setw(5) << "Membresia: " << "|"
		<< setw(5) << "Estado: " << endl;
	cout << string(78, '-') << endl;

	cout << left << setw(6) << socio.getIdUsuario() << "|"
		<< setw(5) << socio.getApellido() << "|"
		<< setw(5) << socio.getNombre() << "|"
		<< setw(5) << socio.getFechaIngreso().toString() << "|"
		<< setw(5) << membresiaToStr(socio.getMembresia()).c_str() << "|"
		<< setw(5) << (socio.getEstado() ? "Habilitado" : "Desabilitado") << endl;
	cout << string(78, '-') << endl;

	system("pause");
}

bool ServicioSocio::buscarSocioPorDni(int dni) 
{
	// uso al dni como validacion para saber si existe socio o no.
	int cantReg = _archivoSocio.cantidadRegistros();
	for (int i = 0; i < cantReg; i++)
	{
		if (_archivoSocio.leerReg(i).getDni() == dni) {
			return true;
		}
	}
	return false;
}

void ServicioSocio::modificarSocio() 
{
	//system("cls");

	cout << "		+-----------------------------------------+" << endl;
	cout << "		|             MODIFICAR SOCIO             |" << endl;
	cout << "		+-----------------------------------------+" << endl;
	cout << endl;
	int idUsuario, opc;


	cout << "  Ingresa un ID: ";
	cin >> idUsuario;
	int pos = _archivoSocio.buscarReg(idUsuario);

	if (pos == -2)
	{
		cout << endl;
		cout << " | Socio no encontrado, ID incorrecto | " << endl;
		return;
	}

	Socio socio = _archivoSocio.leerReg(pos);
	
	do
	{
		system("cls");
		cout << "   +-----------------------------------------+" << endl;
		cout << "   |             MODIFICAR SOCIO             |" << endl;
		cout << "   +-----------------------------------------+" << endl;
		cout << endl;

		cout << string(78, '-') << endl;
		cout << " 1. Modificar datos del socio" << endl;
		cout << " 2. Modificar membresia" << endl;
		cout << " 3. Cambiar rutina" << endl;
		cout << " 4. Cambiar entrenador designado" << endl;
		cout << " 5. Cambiar estado de un socio" << endl;
		cout << " 0. Volver/Guardar" << endl;
		cout << string(78, '-') << endl;
		cout << " Su seleccion: ";

		string nombre;
		string apellido;
		int dni;
		Fecha fechaNacimiento;
		Fecha fechaIngreso;
		string contrasenia;
		string contrasenia1;

		cin >> opc;

		switch (opc)
		{
			case 1:
				cout << "  Nombre: ";
				cin >> nombre;
				socio.setNombre(nombre);

				cout << "  Apellido: ";
				cin >> apellido;
				socio.setApellido(apellido);

				cout << "  DNI: ";
				cin >> dni;
				socio.setDni(dni);

				cout << "  Fecha de nacimiento: ";
				fechaNacimiento = Fecha::crearFecha();
				cout << endl;
				socio.setFechaNacimiento(fechaNacimiento);
				
				do {
					cout << "  Contrasenia: ";
					cin >> contrasenia;
					cout << "  Confirma la contrasenia: ";
					cin >> contrasenia1;

					if (contrasenia != contrasenia1)
					{
						cout << "  Las contrasenias no coinciden. Volve a intentarlo.  ";
						cout << endl;
					}

				} while (contrasenia != contrasenia1);
				socio.setContrasenia(contrasenia);
				break;

			case 2:
				// modificar membresia
				membresiaToStr(socio.getMembresia());
				socio.setMembresia(seleccionarMembresia());
				break;

			case 3:
				// cambiar rutina
				break;

			case 4:
				// cambiar entrenador designado
				break;

			case 5:
				if (socio.getEstado())
				{
					cout << "  Esta seguro de cambiar el estado a Inhabilitado? (S/N): ";
				}
				else
				{
					cout << "  Esta seguro de cambiar el estado a Habilitado? (S/N): ";
				}

				char confirm;
				cin >> confirm;
				if (confirm == 'S' || confirm == 's')
				{
					if (socio.getEstado())
					{
						socio.setEstado(false);
					}
					else {
						socio.setEstado(true);
					}
					cout << "  Estado modificado con exito.  " << endl;
					cout << endl;
				}
				else 
				{
					cout << endl;
					cout << "  Cambio de estado cancelado.  " << endl;
				}
				break;

			case 0: 
				break;

			default:
				cout << "  Error. Selecciona una opcion valida.  " << endl;
				break;

			system("pause");
		}
	} while (opc != 0);

	cout << "  Confirmar Cambios? 1 - SI | 0 - NO" << endl;
	cout << "  Su eleccion: ";
	cin >> opc;

	if (opc == 1 && _archivoSocio.modificarReg(socio, pos))
	{
		cout << endl;
		cout << "  Cambios guardados con exito. " << endl;
	}

	system("pause");
}

string ServicioSocio::membresiaToStr(int idMemb) 
{
	string membresia;
	switch (idMemb)
	{
		case 0:
			membresia = " CORRO MEDIA CUADRA Y NECESITO RESPIRADOR ";
			break;
		case 1:
			membresia = " ME HAGO UNAS DOMINADAS ";
			break;
		case 2:
			membresia = " SOY HIJO DEL SWARZENNEGER ";
			break;
	}
	return membresia;
}

int ServicioSocio::seleccionarMembresia()
{
	int opc;
	do
	{
		cout << " Ingrese 0 para 'NO ENTRENO HACE MIL', 1 para 'ME HAGO UNAS DOMINADAS', 2 para 'SOY EL HIJO DEL  SWARZENEGGER' " << endl;
		cout << " Su seleccion: ";
		cin >> opc;
	} while (opc > 2 || opc < 0);
	return opc;
}