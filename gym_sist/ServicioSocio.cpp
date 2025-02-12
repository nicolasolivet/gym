#include <iostream>
#include <iomanip>
#include <string>
#include "Socio.h"
#include "Fecha.h"
#include "ServicioSocio.h"
#include "ServicioEmpleado.h"
#include "ServicioRutina.h"
#include "ServicioPago.h"
#include "ServicioActividad.h"


using namespace std;

ServicioSocio::ServicioSocio()
{
	archivoSocio = ArchivoSocios("archivoSocios.dat");
	archivoEmpleado = ArchivoEmpleados("archivoEmpleados.dat");
}

int ServicioSocio::generarId()
{
	int cantEmpleados = archivoEmpleado.cantidadRegistros();
	int cantSocios = archivoSocio.cantidadRegistros();

	return 0 + cantEmpleados + cantSocios;
}

void ServicioSocio::agregarSocio()
{
	system("cls");
	int idUsuario = generarId();
	string nombre;
	string apellido;
	int dni;
	Fecha fechaNacimiento;
	Fecha fechaIngreso;
	string contrasenia;
	string contrasenia1;
	bool estado;
	string estadoFisico;
	int pase;
	int idRol = 2;
	int idRutina = 0;
	int idEntrenadorAsignado = 0;

	cout << "   +---------------------------------+" << endl;
	cout << "   |           AGREGAR SOCIO         |" << endl;
	cout << "   +---------------------------------+" << endl;
	cout << endl;

	cout << "  Ingresa un DNI: " << endl;
	cin >> dni;

	// uso
	if (buscarSocioPorDni(dni))
	{
		cout << endl;
		cout << "   +----------------------------------------+" << endl;
		cout << "   |      El socio ingresado ya existe      |" << endl;
		cout << "   +----------------------------------------+" << endl;
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

	pase = seleccionarPase();

	cout << "  Ingresa el estado fisico: ";
	cin >> estadoFisico;

	Socio socio(nombre, apellido, dni, idUsuario, fechaNacimiento, fechaIngreso, contrasenia, estado, idRol, pase, estadoFisico, idRutina, idEntrenadorAsignado);

	if (archivoSocio.guardarReg(socio))
	{
		cout << "+---------------------------------------+" << endl;
		cout << "|      Socio agregado exitosamente      |" << endl;
		cout << "+---------------------------------------+" << endl;
	}
	else {
		cout << "+---------------------------------------------+" << endl;
		cout << "|      Hubo un error, volve a intentarlo      |" << endl;
		cout << "+---------------------------------------------+" << endl;
	}

	system("pause");
}

void ServicioSocio::verSociosPorId()
{
	cout << "  +---------------------------------+" << endl;
	cout << "  |         LISTADO DE SOCIOS       |" << endl;
	cout << "  +---------------------------------+" << endl;
	cout << endl;

	int cantSocios = archivoSocio.cantidadRegistros();
	Socio* socios;
	socios = new Socio[cantSocios];
	if (socios == nullptr) {
		cout << "+-----------------------------+" << endl;
		cout << "|       NO EXISTEN SOCIOS     |" << endl;
		cout << "+-----------------------------+" << endl;

		return;
		system("pause");
	}

	for (int i = 0; i < cantSocios; i++)
	{
		socios[i] = archivoSocio.leerReg(i);
	}

	Socio aux;
	for (int j = 0; j < cantSocios; j++)
	{
		for (int k = 0; k < cantSocios - 1; k++)
		{
			if (socios[k].getIdUsuario() > socios[k + 1].getIdUsuario())
			{
				aux = socios[k + 1];
				socios[k + 1] = socios[k];
				socios[k] = aux;
			}
		}
	}

	listarSocios(socios, cantSocios);
	delete[]socios;
}

void ServicioSocio::verSociosPorApellido()
{
	cout << "  +---------------------------------------------+" << endl;
	cout << "  |         LISTADO DE SOCIOS POR APELLIDO      |" << endl;
	cout << "  +---------------------------------------------+" << endl;
	cout << endl;

	int cantReg = archivoSocio.cantidadRegistros();
	Socio* socios;
	socios = new Socio[cantReg];
	if (socios == nullptr) {
		cout << "+-----------------------------+" << endl;
		cout << "|       NO EXISTEN SOCIOS     |" << endl;
		cout << "+-----------------------------+" << endl;

		return;
	}

	for (int i = 0; i < cantReg; i++)
	{
		socios[i] = archivoSocio.leerReg(i);
	}

	Socio aux;
	for (int i = 0; i < cantReg; i++)
	{
		for (int h = 0; h < cantReg - 1; h++)
		{
			if (socios[h].getApellido() > socios[h + 1].getApellido())
			{
				aux = socios[h + 1];
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

	int cantReg = archivoSocio.cantidadRegistros();
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
		socios[x] = archivoSocio.leerReg(x);
	}

	Socio aux;
	for (int y = 0; y < cantReg; y++)
	{
		for (int z = 0; z < cantReg - 1; z++)
		{
			if (socios[z].getDni() > socios[z + 1].getDni())
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

void ServicioSocio::listarSocios(Socio socios[], int cantReg)
{
	Socio socio;

	cout << string(105, '-') << endl;
	cout << left << setw(5) << "ID" << "|"
		<< setw(25) << "NOMBRE" << "|"
		<< setw(14) << "FECHA ING." << "|"
		<< setw(45) << "PASE" << "|"
		<< setw(20) << "ESTADO" << endl;
	cout << string(105, '-') << endl;

	for (int i = 0; i < cantReg; i++)
	{
		socio = socios[i];
		//cout << string(78, '-') << endl;
		cout << left << setw(5) << socio.getIdUsuario() << "|"
			<< setw(13) << socio.getApellido() << " " << socio.getNombre() << "|"
			<< setw(14) << socio.getFechaIngreso().toString() << "|"
			<< setw(45) << paseToStr(socio.getPase()).c_str() << "|"
			<< setw(20) << (socio.getEstado() ? "Habilitado" : "Deshabilitado") << endl;
		cout << string(105, '-') << endl;
	}
	system("pause");
}

Socio ServicioSocio::buscarSocio(int idUsuario)
{
	int pos = archivoSocio.buscarReg(idUsuario);
	if (pos == -1)
	{
		cout << "  + - - - - - - - - - - - - - - - - - - - - - - +";
		cout << "  |   El socio con el ID ingresado no existe.   | ";
		cout << "  + - - - - - - - - - - - - - - - - - - - - - - + ";
		return Socio();
	}

	Socio socio = archivoSocio.leerReg(pos);

	return socio;
}

void ServicioSocio::buscarSocioPorId()
{
	system("cls");

	int idSocio;
	cout << "  +--------------------------------+" << endl;
	cout << "  |           BUSCAR SOCIO         |" << endl;
	cout << "  +--------------------------------+" << endl;
	cout << endl;
	cout << " Ingrese ID: ";
	cin >> idSocio;

	int pos = archivoSocio.buscarReg(idSocio);

	if (pos == -1) {
		cout << "  El socio no existe  ";
		system("pause");
		return;
	}

	Socio socio = archivoSocio.leerReg(pos);

	cout << string(78, '-') << endl;
	cout << left << setw(6) << "ID: " << "|"
		<< setw(5) << "Apellido: " << "|"
		<< setw(5) << "Nombre: " << "|"
		<< setw(5) << "Fecha de ingreso: " << "|"
		<< setw(5) << "Pase: " << "|"
		<< setw(5) << "Estado: " << endl;
	cout << string(78, '-') << endl;

	cout << left << setw(6) << socio.getIdUsuario() << "|"
		<< setw(5) << socio.getApellido() << "|"
		<< setw(5) << socio.getNombre() << "|"
		<< setw(5) << socio.getFechaIngreso().toString() << "|"
		<< setw(5) << paseToStr(socio.getPase()) << "|"
		<< setw(5) << (socio.getEstado() ? "Habilitado" : "Desabilitado") << endl;
	cout << string(78, '-') << endl;

	system("pause");
}

bool ServicioSocio::buscarSocioPorDni(int dni)
{
	// uso al dni como validacion para saber si existe socio o no.
	int cantReg = archivoSocio.cantidadRegistros();
	for (int i = 0; i < cantReg; i++)
	{
		if (archivoSocio.leerReg(i).getDni() == dni) {
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

	string nombre;
	string apellido;
	int dni;
	Fecha fechaNacimiento;
	Fecha fechaIngreso;
	string contra;
	string contrasenia;
	string contrasenia1;

	cout << "  Ingresa un ID: ";
	cin >> idUsuario;
	int pos = archivoSocio.buscarReg(idUsuario);

	while (pos < 0)
	{
		cout << endl;
		cout << "  +-----------------------------------------+ " << endl;
		cout << "  |   Socio no encontrado, ID inexistente   | " << endl;
		cout << "  +-----------------------------------------+ " << endl;
		system("pause");
		system("cls");
		cout << "  Ingresa un ID: ";
		cin >> idUsuario;
	}

	Socio socio = archivoSocio.leerReg(pos);

	do
	{
		system("cls");
		cout << "   +-----------------------------------------+" << endl;
		cout << "   |             MODIFICAR SOCIO             |" << endl;
		cout << "   +-----------------------------------------+" << endl;
		cout << endl;

		cout << string(78, '-') << endl;
		cout << " 1. Modificar datos personales" << endl;
		cout << " 2. Cambiar contrasenia" << endl;
		cout << " 3. Modificar pase" << endl;
		cout << " 4. Cambiar rutina" << endl;
		cout << " 5. Cambiar entrenador designado" << endl;
		cout << " 6. Cambiar estado de un socio" << endl;
		cout << " 0. Volver/Guardar" << endl;
		cout << string(78, '-') << endl;
		cout << " Su seleccion: ";
		cin >> opc;
		cout << endl;

		system("cls");

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

			cout << "  +------------------------------------------+" << endl;
			cout << "  |      Modificacion realizada con exito    |" << endl;
			cout << "  |  Recorda guardar cambios antes de salir  |" << endl;
			cout << "  +------------------------------------------+" << endl;

			break;

		case 2:
			//cambiar contra
			cout << endl;
			contra = socio.getContrasenia();
			cout << "   Tu contrasenia actual es: " << contra << endl << endl;

			do {
				cout << "   Ingresa la nueva contrasenia: ";
				cin >> contrasenia;
				cout << "   Confirma la contrasenia: ";
				cin >> contrasenia1;

				if (contrasenia != contrasenia1)
				{
					cout << "   Las contrasenias no coinciden. Volve a intentarlo.  ";
					cout << endl;
				}

			} while (contrasenia != contrasenia1);
			socio.setContrasenia(contrasenia);

			break;

		case 3:
			// modificar pase
			paseToStr(socio.getPase());
			socio.setPase(seleccionarPase());
			break;

		case 4:
			// cambiar rutina
			break;

		case 5:
			// cambiar entrenador designado
			break;

		case 6:
			if (socio.getEstado())
			{
				cout << endl << endl;
				cout << "   Esta seguro de cambiar el estado a Inhabilitado? (S/N): ";
			}
			else
			{
				cout << endl << endl;
				cout << "   Esta seguro de cambiar el estado a Habilitado? (S/N): ";
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
				cout << endl;
				cout << "   Estado modificado con exito.  " << endl;
				cout << endl;
			}
			else
			{
				cout << endl;
				cout << "   Cambio de estado cancelado.  " << endl;
			}
			break;

		case 0:
			break;

		default:
			cout << "   Error. Selecciona una opcion valida.  " << endl;
			system("pause");
			break;

			system("pause");
		}

	} while (opc != 0);

	cout << "   Confirmas cambios? 1 - SI | 0 - NO" << endl;
	cout << "   Su eleccion: ";
	cin >> opc;
	system("cls");
	cout << endl;

	if (opc == 1 && archivoSocio.modificarReg(socio, pos))
	{
		cout << endl;
		cout << "   +--------------------------------+ " << endl;
		cout << "   |   Cambios guardados con exito  |" << endl;
		cout << "   +--------------------------------+ " << endl;
	}
	else
	{
		cout << "   +---------------------------------+ " << endl;
		cout << "   |   Los cambios no se guardaron   |" << endl;
		cout << "   +---------------------------------+ " << endl;
	}

	//system("pause");
}

string ServicioSocio::paseToStr(int idMemb)
{
	string pase;
	switch (idMemb)
	{
	case 0:
		pase = "'Corro media cuadra y necesito respirador' ";
		break;
	case 1:
		pase = "'Me hago unas dominadas de chill' ";
		break;
	case 2:
		pase = "'Soy la reencarnacion de Swarzenegger' ";
		break;
	}
	return pase;
}

int ServicioSocio::seleccionarPase()
{
	int opc;
	do
	{
		cout << "   Ingrese 0 para 'NO ENTRENO HACE MIL', 1 para 'ME HAGO UNAS DOMINADAS', 2 para 'SOY LA REENCARNACION DEL  SWARZENEGGER' " << endl;
		cout << "   Su seleccion: ";
		cin >> opc;
	} while (opc <= 2 || opc >= 0);
	return opc;
}

void ServicioSocio::actualizarEstadoDelSocio(int idSocio, bool estado)
{
	int pos = archivoSocio.buscarReg(idSocio);

	Socio socio = archivoSocio.leerReg(pos);

	socio.setEstado(estado);

	archivoSocio.modificarReg(socio, pos);
}

void ServicioSocio::mostrarTurno(int idTurno)
{
	cout << " Turno: ";
	switch (idTurno)
	{
	case 0:
	{
		cout << "Maniana";
		break;
	}
	case 1:
	{
		cout << "Tarde";
		break;
	}
	case 2:
	{
		cout << "Noche";
		break;
	}
	}
	cout << endl;
}

void ServicioSocio::listarSociosPorEntrenador(int idEntrenador)
{
	system("cls");

	cout << "   + ------------------------------------- + " << endl;
	cout << "   |         SOCIOS POR ENTRENADOR         | " << endl;
	cout << "   + ------------------------------------- + " << endl;

	Socio socio;
	Socio* sociosPorEntrenador;

	int cantSocios = archivoSocio.cantidadRegistros();
	sociosPorEntrenador = new Socio[cantSocios];

	if (sociosPorEntrenador == nullptr) {
		cout << "	+ -------------------------------------------------------------------------- +" << endl;
		cout << "	|       Error. Volve a intentarlo, si el error persiste genera un reclamo    |" << endl;
		cout << "	+ -------------------------------------------------------------------------- +" << endl;

		return;
		system("pause");
	}

	int contadorSocios = 0;

	for (int q = 0; q < cantSocios; q++)
	{
		socio = archivoSocio.leerReg(q);
		if (socio.getIdEntrenadorAsignado() == idEntrenador)
		{
			sociosPorEntrenador[q] = socio;
			contadorSocios++;
		}
	}

	if (contadorSocios == 0)
	{
		cout << endl;
		cout << "   + ------------------------------ +" << endl;
		cout << "   |    No tenes socios asignados   |" << endl;
		cout << "   + ------------------------------ +" << endl;
		delete[]sociosPorEntrenador;
		return;
	}

	listarSocios(sociosPorEntrenador, cantSocios);
	delete[]sociosPorEntrenador;
}

void ServicioSocio::listarSociosSinEntrenador()
{
	system("cls");

	cout << endl;
	cout << "   + ------------------------------------- + " << endl;
	cout << "   |         SOCIOS SIN ENTRENADOR         | " << endl;
	cout << "   + ------------------------------------- + " << endl;

	Socio socio;
	Socio* sociosSinEntrenador;
	int contadorSocios = 0;

	int cantSocios = archivoSocio.cantidadRegistros();
	sociosSinEntrenador = new Socio[cantSocios];

	if (sociosSinEntrenador == nullptr)
	{
		cout << "	+ -------------------------------------------------------------------------- +" << endl;
		cout << "	|       Error. Volve a intentarlo, si el error persiste genera un reclamo    |" << endl;
		cout << "	+ -------------------------------------------------------------------------- +" << endl;

		return;
		system("pause");
	}

	for (int w = 0; w < cantSocios; w++)
	{
		socio = archivoSocio.leerReg(w);
		if (socio.getIdEntrenadorAsignado() == 0)
		{
			sociosSinEntrenador[w] = socio;
			contadorSocios;
		}
	}

	if (contadorSocios == 0)
	{
		cout << endl;
		cout << "   + --------------------------------------------------- +" << endl;
		cout << "   |    Todos los socios tienen un entrenador asignado   |" << endl;
		cout << "   + --------------------------------------------------- +" << endl;
		delete[]sociosSinEntrenador;
		return;
	}

	listarSocios(sociosSinEntrenador, cantSocios);
	delete[]sociosSinEntrenador;
}

void ServicioSocio::listarSociosSinRutina(int idEntrenador)
{
	system("cls");

	cout << endl;
	cout << "   + --------------------------------- + " << endl;
	cout << "   |         SOCIOS SIN RUTINA         | " << endl;
	cout << "   + --------------------------------- + " << endl;

	Socio socio;
	Socio* sociosSinRutina;
	int contadorSocios = 0;

	int cantSocios = archivoSocio.cantidadRegistros();
	sociosSinRutina = new Socio[cantSocios];

	if (sociosSinRutina == nullptr)
	{
		cout << "	+ -------------------------------------------------------------------------- +" << endl;
		cout << "	|       Error. Volve a intentarlo, si el error persiste genera un reclamo    |" << endl;
		cout << "	+ -------------------------------------------------------------------------- +" << endl;

		return;
		system("pause");
	}

	for (int w = 0; w < cantSocios; w++)
	{
		socio = archivoSocio.leerReg(w);
		if (socio.getIdRutina() == 0 && socio.getEstado() == true)
		{
			sociosSinRutina[w] = socio;
			contadorSocios++;
		}
	}

	if (contadorSocios == 0)
	{
		cout << endl;
		cout << "   + -------------------------------------------------------------------------------------- +" << endl;
		cout << "   |     Todos los socios tienen una rutina asignada o eligieron alguna clase/actividad     |" << endl;
		cout << "   + -------------------------------------------------------------------------------------- +" << endl;
		delete[]sociosSinRutina;
		return;
	}

	listarSocios(sociosSinRutina, cantSocios);
	delete[]sociosSinRutina;
}

void ServicioSocio::asignarRutina(int idEntrenador)
{
	Socio socio;
	ServicioRutina rutina;
	int idSocio, opcion;
	int cantSocios = archivoSocio.cantidadRegistros();

	system("cls");
	cout << "	+ ----------------------------------------------------------- +" << endl;
	cout << "	|                      ASIGNAR UNA RUTINA                     |" << endl;
	cout << "	+ ----------------------------------------------------------- +" << endl;
	cout << endl;
	cout << " Ingresa el ID del Socio: ";
	cin >> idSocio;

	int pos = archivoSocio.buscarReg(idSocio);

	if (pos != -1)
	{
		socio = archivoSocio.leerReg(pos);

		if (socio.getIdEntrenadorAsignado() == idEntrenador)
		{
			int idRutina = rutina.elegirRutina(idEntrenador);

			system("cls");
			cout << "	+ ----------------------------------------------------------- +" << endl;
			cout << "	|                      ASIGNAR UNA RUTINA                     |" << endl;
			cout << "	+ ----------------------------------------------------------- +" << endl;
			cout << endl;
			cout << " ID Socio: " << socio.getIdUsuario() << endl;
			cout << " ID Rutina Seleccionada: " << idRutina << endl;
			cout << endl;
			cout << " Confirmar cambios? [1] SI | [2] NO " << endl;
			cout << " Opcion elegida: ";
			cin >> opcion;

			if (opcion == 1)
			{
				socio.setIdRutina(idRutina);
				if (archivoSocio.modificarReg(socio, pos))
				{
					cout << "   + ------------------------------- +" << endl;
					cout << "   |   Cambios guardados con exito   |" << endl;
					cout << "   + ------------------------------- +" << endl;
				}
			}
		}
		else
		{
			cout << "   + --------------------------------------------------- +" << endl;
			cout << "   |   El Socio se encuentra asignado a otro entrenado   |" << endl;
			cout << "   + --------------------------------------------------- +" << endl;
		}
	}
	else
	{

		cout << "	+ -------------------- +" << endl;
		cout << "	|   ID no encontrado   |" << endl;
		cout << "	+ -------------------- +" << endl;
	}

	cout << endl;
	system("pause");
}

void ServicioSocio::mostrarFechaVencimiento(Fecha fechaIngreso, int idSocio)
{
	Fecha fecha, fechaActual;
	ServicioPago pago;

	if (pago.verificarUltimoPago(idSocio))
	{
		fechaIngreso.setMes(fechaActual.getMes());
		fecha = fecha.calcularDiasParaVencimiento(fechaIngreso);

		cout << "   +---------------------------------------------+" << endl;
		cout << "   | Tu proxima cuota vence el dia: " << fecha.toString() << "   |" << endl;
		cout << "   +---------------------------------------------+" << endl;

	}
	else
	{
		cout << "   + --------------------------------------------------------- +" << endl;
		cout << "   | Cuota vencida, debe realizar el pago para activar su pase |" << endl;
		cout << "   + --------------------------------------------------------- +" << endl;

	}

	system("pause");
	return;
}

bool ServicioSocio::consultarEstadoDeSocio(int idSocio)
{
	int pos = archivoSocio.buscarReg(idSocio);
	Socio socio = archivoSocio.leerReg(pos);

	ServicioPago pago;

	if (!pago.verificarUltimoPago(idSocio) && pago.cantidadDeDiasDelUltimoPago(idSocio) < 0)
	{
		socio.setEstado(false);
		archivoSocio.modificarReg(socio, pos);

		return false;
	}
	return true;
}


// metodos habilitados para el usuario
void ServicioSocio::modificarContrasenia(int idSocio)
{
	cout << endl;
	cout << "   +---------------------------+ " << endl;
	cout << "   |   MODIFICAR CONTRASENIA   | " << endl;
	cout << "   +---------------------------+ " << endl;
	int opc;
	string contra;
	string contrasenia;
	string contrasenia1;

	int pos = archivoSocio.buscarReg(idSocio);
	if (pos != -1)
	{
		Socio socio = archivoSocio.leerReg(pos);

		cout << endl;
		contra = socio.getContrasenia();
		cout << "   Tu contrasenia actual es: " << contra << endl << endl;

		do {
			cout << "   Ingresa la nueva contrasenia: ";
			cin >> contrasenia;
			cout << "   Confirma la contrasenia: ";
			cin >> contrasenia1;

			if (contrasenia != contrasenia1)
			{
				cout << "   Las contrasenias no coinciden. Volve a intentarlo.  ";
				cout << endl;
			}

		} while (contrasenia != contrasenia1);
		socio.setContrasenia(contrasenia);

		cout << endl;
		cout << "   Confirmar cambios? [1] SI | [2] NO" << endl;
		cout << "   Opcion elegida: ";
		cin >> opc;
		system("cls");
		cout << endl;

		if (opc == 1 && archivoSocio.modificarReg(socio, pos))
		{
			cout << endl;
			cout << "   +--------------------------------+ " << endl;
			cout << "   |   Cambios guardados con exito  | " << endl;
			cout << "   +--------------------------------+ " << endl;
			return;
		}
		else
		{
			cout << endl;
			cout << "   +---------------------------------+ " << endl;
			cout << "   |   Los cambios no se guardaron   | " << endl;
			cout << "   +---------------------------------+ " << endl;
			return;
		}
	}
	else
	{
		cout << endl;
		cout << "   + --------------------------------------------------------------------------------- + " << endl;
		cout << "   |   Error. Si el error persiste genera un reclamo comentando la sitacion. Gracias   | " << endl;
		cout << "   + --------------------------------------------------------------------------------- + " << endl;
		return;
	}


}

void ServicioSocio::verEntrenadorAsignado(int idSocio)
{
	system("cls");
	ServicioActividad servActi;
	string horarios;

	int pos = archivoSocio.buscarReg(idSocio);
	Socio socio = archivoSocio.leerReg(pos);
	int posEmp = archivoEmpleado.buscarReg(socio.getIdEntrenadorAsignado());

	if (posEmp != -1)
	{
		Empleado emp = archivoEmpleado.leerReg(pos);
		switch (emp.getIdTurno())
		{
		case 0:
			horarios = "08hs a 13hs";
			break;
		case 1:
			horarios = "13hs a 18hs";
			break;
		case 2:
			horarios = "18hs a 23hs";
			break;
		}
		
		cout << "		 + ----------------------------- +" << endl;
		cout << "		 |      ENTRENADOR ASIGNADO      |" << endl;
		cout << "		 + ----------------------------- +" << endl;
		cout << endl;
		cout << "   +--------------------------------------+" << endl;
		cout << "   |   Nombre: " << emp.getNombre() << endl;
		cout << "   |   Apellido: " << emp.getApellido() << endl;
		cout << "   |   Horario: " << horarios << endl;
				//	+--------------------------------------+" << endl;
				//	|   Actividad: Acrobacia
				//	+--------------------------------------+" << endl;

		/// el formato de la actividad lo trae 'buscarActividad'
		servActi.buscarActividad(emp.getIdActividad());
	}
	else
	{
		cout << "  + ---------------------------------------------------------------------------------------------------------------------------- +" << endl;
		cout << "  |   Aun no tenes asignado un entrenador. Te asignaremos uno, si dentro de las 24hs no tenes entrenador, carga un reclamo   |" << endl;
		cout << "  + ---------------------------------------------------------------------------------------------------------------------------- +" << endl;
		system("pause");
		return;
	}


	

	system("pause");
}

void ServicioSocio::verHorarios()
{
	cout << "								+------------------------+                            " << endl;
	cout << "								|		 Horarios		 |                            " << endl;
	cout << "								+------------------------+                            " << endl;
	cout << "								|      Lunes a Sabado    |                            " << endl;
	cout << "								|       08hs a 23hs      |                            " << endl;
	cout << "								+------------------------+                            " << endl;

	cout << "  +---------------------------------------------------------------------------------+" << endl;
	cout << "  | NO PODES ENTRAR ANTES, NI QUEDARTE DESPUES DEL HORARIO INFORMADO. NO SEAS PESAO |" << endl;
	cout << "  +---------------------------------------------------------------------------------+" << endl;
}

void ServicioSocio::verPase(int idSocio)
{
	int pos = archivoSocio.buscarReg(idSocio);
	Socio socio = archivoSocio.leerReg(pos);

	cout << " +----------------------------------------------------------------+" << endl;
	cout << " |   Pase actual: " << paseToStr(socio.getPase()) << " |   " << endl;
	cout << " +----------------------------------------------------------------+" << endl;

	//system("pause");
}