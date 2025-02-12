#include <iostream>
#include "MenuSocio.h"
using namespace std;

 ///Dependency Injection
MenuSocio::MenuSocio(UsuarioAutenticado usuario) : usuario(usuario) {}

void MenuSocio::mostrarSubmenuSocio()
{
	system("cls");
	int opcion;

	if (!servSocio.consultarEstadoDeSocio(usuario.getIdUsuario()))
	{
		usuario.setEstado(false);
	}

	cout << "+-----------------------------------------+" << endl;
	cout << "|      BIENVENIDO " << usuario.getNombre() << endl;
	cout << "+-----------------------------------------+" << endl;
	cout << "|   [1]  INGRESO AL GIMNASIO              |" << endl;
	cout << "|   [2]  INGRESO AL MENU SOCIO            |" << endl;
	cout << "+-----------------------------------------+" << endl;
	cout << endl;
	cout << " Opcion elegida: ";
	cin >> opcion;

	if (opcion == 1)
	{
		mostrarMenuIngresoSocio();
	}
	else
	{
		mostrarMenuSocio();
	}
}

void MenuSocio::mostrarMenuIngresoSocio()
{
	system("cls");
	if (usuario.getEstado())
	{
		ServicioSocio socio;
		ServicioAsistencia asistencia;

		cout << "+---------------------------------------+" << endl;
		cout << "|   Bienvenido " << usuario.getNombre() << endl;
		cout << "+---------------------------------------+" << endl;

		asistencia.registrarAsistencia(usuario.getIdUsuario());
	}
	else
	{
		cout << "+ -------------------------------------------------------------------- +" << endl;
		cout << "|           No estas habilitado/a para ingresar al gimnasio            |" << endl;
		cout << "|   Se vencio tu cuota. Podes realizar el pago en la seccion 'PAGOS'   |" << endl;
		cout << "+ -------------------------------------------------------------------- +" << endl;
	}
	system("pause");

	mostrarSubmenuSocio();
}

void MenuSocio::mostrarMenuSocio()
{
	int opcion;

	do
	{
		system("cls");
		cout << "      +----------------------------------+" << endl;
		cout << "      |            MENU SOCIO            |" << endl;
		cout << "      +----------------------------------+" << endl;
		cout << "      |   [1]  PAGOS                     |" << endl;
		cout << "      |   [2]  RUTINAS                   |" << endl;
		cout << "      |   [3]  HORARIOS                  |" << endl;
		cout << "      |   [4]  RECLAMOS                  |" << endl;
		cout << "      |   [5]  CAMBIAR CONTRASENIA       |" << endl;
		cout << "      +----------------------------------+" << endl;
		cout << "      |   [0]  SALIR                     |" << endl;
		cout << "      +----------------------------------+" << endl;

		cout << endl;
		cout << " Opcion elegida: ";
		cin >> opcion;

		system("cls");
		switch (opcion)
		{
		case 1:
			gestionarPagos();
			break;
		case 2:
			verRutina();
			break;
		case 3:
			consultarHorarios();
			break;
		case 4:
			generarReclamo();
			break;
		case 5:
			servSocio.modificarContrasenia(usuario.getIdUsuario());
			break;
		case 0:
			cout << endl;
			cout << "       |   NOS VEMOSSS   |" << endl;
			system("pause");
			break;
		default:
			cout << " Pifiaste, volve a intentarlo " << endl;
			system("pause");
			break;
		}

	} while (opcion != 0);
}

void MenuSocio::gestionarPagos()
{
	int opcion;
	Socio socio = servSocio.buscarSocio(usuario.getIdUsuario());

	do
	{
		system("cls");
		cout << "+--------------------------------------+" << endl;
		cout << "|               PAGOS                  |" << endl;
		cout << "+--------------------------------------+" << endl;
		cout << "|   [1] REALIZAR UN PAGO               |" << endl;
		cout << "|   [2] VER PAGOS ANTERIORES           |" << endl;
		cout << "|   [3] VER FECHA DE VENCIMIENTO       |" << endl;
		cout << "|   [4] VER PRECIOS DIFERENTES PASES   |" << endl;
		cout << "|   [5] VER MI PASE                    |" << endl;
		cout << "+--------------------------------------+" << endl;
		cout << "|   [0] - VOLVER ATRAS                 |" << endl;
		cout << "+--------------------------------------+" << endl;
		cout << endl;
		cout << " Opcion elegida: ";
		cin >> opcion;


		system("cls");
		switch (opcion)
		{
		case 1:
			if (servPago.registrarPago(usuario.getIdUsuario(), socio.getPase(), socio.getFechaIngreso()))
			{
				servSocio.actualizarEstadoDelSocio(usuario.getIdUsuario(), true);
			}
			break;
		case 2:
			servPago.verPagosPorSocio(usuario.getIdUsuario());
			break;
		case 3:
			servSocio.mostrarFechaVencimiento(socio.getFechaIngreso(), usuario.getIdUsuario());
			break;
		case 4:
			mostrarPreciosDePases();
			break;
		case 5:
			servSocio.verPase(usuario.getIdUsuario());
			break;
		case 0:
			break;
		default:
			cout << "  Pifiaste, intenta de nuevo" << endl;
			system("pause");
			break;
		}

	} while (opcion != 0);

}

void MenuSocio::mostrarPreciosDePases()
{
	system("cls");
	cout << endl;
	cout << "+----------------------------------------------------+" << endl;
	cout << "|  NO ENTRENO HACE MIL..................... $25.000  |" << endl;
	cout << "|  ME HAGO UNAS DOMINADAS.................. $35.000  |" << endl;
	cout << "|  SOY LA REENCARNACION DE SWARZENEGGER.... $55.000  |" << endl;
	cout << "+----------------------------------------------------+" << endl;

	system("pause");
}

void MenuSocio::verRutina()
{
	int opcion;
	Socio socio = servSocio.buscarSocio(usuario.getIdUsuario());

	do
	{
		system("cls");
		cout << "+--------------------------------------+" << endl;
		cout << "|               RUTINAS                |" << endl;
		cout << "+--------------------------------------+" << endl;
		cout << "|   [1]  VER MI RUTINA                 |" << endl;
		cout << "|   [2]  VER DETALLE DE LA RUTINA      |" << endl;
		cout << "+--------------------------------------+" << endl;
		cout << "|   [0]  VOLVER                        |" << endl;
		cout << "+--------------------------------------+" << endl;
		cout << endl;
		cout << " Opcion elegida: ";
		cin >> opcion;


		system("cls");
		switch (opcion)
		{
		case 1:
			servRutina.verRutinaAsignadaSocio(socio.getIdRutina());
			break;
		case 2:
	        servRutina.verDetalleRutinaSocio(socio.getIdRutina());
			break;
		case 0:
			break;
		default:
			cout << " Pifiaste, volve a intentarlo " << endl;
			system("pause");
			break;
		}

	} while (opcion != 0);
}

void MenuSocio::consultarHorarios()
{
	int opcion;

	do
	{
		system("cls");
		cout << "+--------------------------------------------+" << endl;
		cout << "|                HORARIOS                    |" << endl;
		cout << "+--------------------------------------------+" << endl;
		cout << "|   [1]  VER HORARIOS DE ENTRENADORES        |" << endl;
		cout << "|   [2]  VER HORARIO DE MI ENTRENADOR        |" << endl;
		cout << "|   [3]  VER HORARIOS DE APERTURA Y CIERRE   |" << endl;
		cout << "+--------------------------------------------+" << endl;
		cout << "|   [0]  VOLVER ATRAS                        |" << endl;
		cout << "+--------------------------------------------+" << endl;
		cout << endl;
		cout << " Su seleccion: ";
		cin >> opcion;


		system("cls");
		switch (opcion)
		{
		case 1:
			servEmp.mostrarHorariosEntrenadores();
			break;
		case 2:
			servSocio.verEntrenadorAsignado(usuario.getIdUsuario());
			break;
		case 3:
			verHorariosGimnasio();
			break;
		default:
			cout << " Pifiaste, proba de nuevo " << endl;
			system("pause");
			break;
		}

	} while (opcion != 0);

}

void MenuSocio::verHorariosGimnasio()
{
	system("cls");
	cout << endl;
	cout << "			+--------------------------+" << endl;
	cout << "			|  HORARIOS DEL GIMNASIO   |" << endl;
	cout << "			|                          |" << endl;
	cout << "			|  LUN a DOM 08hs a 23hs   |" << endl;
	cout << "			+--------------------------+" << endl;
	system("pause");
}

void MenuSocio::generarReclamo()
{
	int opcion;

	do
	{
		system("cls");

		cout << "+--------------------------------------+" << endl;
		cout << "|              RECLAMOS                |" << endl;
		cout << "+--------------------------------------+" << endl;
		cout << "|   [1]  REALIZAR UN RECLAMO           |" << endl;
		cout << "|   [2]  VER ESTADO DE UN RECLAMO      |" << endl;
		cout << "+--------------------------------------+" << endl;
		cout << "|   [0]  VOLVER ATRAS                  |" << endl;
		cout << "+--------------------------------------+" << endl;
		cout << endl;
		cout << " Opcion elegida: ";
		cin >> opcion;

		system("cls");
		switch (opcion)
		{
		case 1:
			servReclamo.iniciarReclamo(usuario.getIdUsuario());
			break;
		case 2:
			servReclamo.verReclamosUsuario(usuario.getIdUsuario());
			break;
		case 0:
			break;
		default:
			cout << " Pifiaste, proba de nuevo " << endl;
			system("pause");
			break;
		}

	} while (opcion != 0);

}
