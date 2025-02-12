#include <iostream>
#include <string>
#include "ServicioRutina.h"
#include "ServicioEjercicio.h"
#include "Rutina.h"
using namespace std;


ServicioRutina::ServicioRutina()
{
	archivoRutinas = ArchivoRutinas("archivoRutinas.dat");
	archivoDetalleRutina = ArchivoDetalleRutina("archivoDetalleRutinas.dat");
}

int ServicioRutina::generarIdRutina()
{
	int cantRutinas = archivoRutinas.cantidadRegistros();

	if (cantRutinas != -1)
		return cantRutinas + 1;
	else
		return 1;
}

void ServicioRutina::crearRutina(int idEntrenador)
{
	system("cls");
	string nombre, descripcion;
	int frecuencia, idRutina;

	DetalleRutina detalle;

	cout << "   +-------------------------------------------+" << endl;
	cout << "   |               CREAR RUTINA                |" << endl;
	cout << "   +-------------------------------------------+" << endl;
	cout << endl;

	cout << " Nombre de la rutina      : ";
	cin >> nombre;
	cout << " Descripcion de la rutina : ";
	cin >> descripcion;
	cout << " Frecuencia semanal       : ";
	cin >> frecuencia;

	idRutina = generarIdRutina();

	Rutina rutina(idRutina, frecuencia, idEntrenador, nombre, descripcion);

	if (archivoRutinas.guardarReg(rutina))
	{
		system("cls");
		cout << "   +----------------------------------------------+" << endl;
		cout << "   |              CREAR NUEVA RUTINA              |" << endl;
		cout << "   +----------------------------------------------+" << endl;
		cout << endl;
		cout << " +-----------------------------------------+ " << endl;
		cout << " |   Rutina agregada exitosamente, ID #" << idRutina << endl;
		cout << " +-----------------------------------------+" << endl;
		cout << endl;
		cout << " Inicio de carga de detalles de la rutina..." << endl;
		cout << endl;
		system("pause");

		detalle = crearDetalleRutina(idRutina);

		if (archivoDetalleRutina.guardarReg(detalle))
		{
			cout << endl;
			cout << " +-------------------------------------+" << endl;
			cout << " |   Detalles agregados exitosamente   |" << endl;
			cout << " +-------------------------------------+" << endl;
		}
		else
		{
			cout << endl;
			cout << " Hubo un error, volve a intentarlo" << endl;
		}

	}
	else
	{
		cout << " Hubo un error, volve a intentarlo" << endl;
	}

	system("pause");
}

DetalleRutina ServicioRutina::crearDetalleRutina(int idRutina)
{
	ServicioEjercicio servEjercicio;
	int opcion = 1, contador = 0;
	int idEjercicio[10] = {}, repeticiones[10] = {};
	float peso[10] = {};

	cout << "  A continuacion se listaran los ejercicios, anota el id de los que vas a agregar" << endl;
	servEjercicio.verEjercicios();

	while (contador < 10 && opcion != 0)
	{
		system("cls");

		cout << "	+----------------------------------------------+" << endl;
		cout << "	|              DETALLES DE RUTINA              |" << endl;
		cout << "	+----------------------------------------------+" << endl;
		cout << endl;
		cout << " - Ejercicios cargados     : " << contador << endl;
		cout << endl;
		cout << " - Ingrese ID de Ejercicio : ";
		cin >> idEjercicio[contador];

		cout << " - Repeticiones            : ";
		cin >> repeticiones[contador];

		cout << " - Peso (0 si no aplica)   : ";
		cin >> peso[contador];

		cout << endl;
		cout << " Agregar otro ejercicio a la rutina? (Maximo 10) " << endl;
		cout << "                    1-SI | 0-NO " << endl;
		cout << endl;
		cout << " Su eleccion: ";
		cin >> opcion;

		contador++;
	}

	return DetalleRutina(idEjercicio, idRutina, repeticiones, peso);
}

void ServicioRutina::verDetalleRutina()
{
	system("cls");

	DetalleRutina detalle;
	ServicioEjercicio seEjercicio;
	int idRutina;

	cout << "		+--------------------------------------------+" << endl;
	cout << "		|				DETALLE DE RUTINA            |" << endl;
	cout << "		+--------------------------------------------+" << endl;
	cout << endl;

	cout << "  Ingresa el ID de la rutina que buscas: #" << endl;
	cin >> idRutina;

	int pos = archivoDetalleRutina.buscarReg(idRutina);
	if (pos != 1)
	{
		detalle = archivoDetalleRutina.leerReg(pos);

		int* idEjercicio = detalle.getIdEjercicio();
		int* repeticiones = detalle.getRepeticiones();
		float* peso = detalle.getPeso();

		// diez vueltas xq solo se permite cargar 10 ejercicios como max
		for (int e = 0; e < 10; e++)
		{
			if (idEjercicio[e] != 0)
			{
				seEjercicio.verEjercicio(idEjercicio[e]);

				cout << "  Repeticiones: " << repeticiones[e] << endl;

				if (peso[e] != 0)
					cout << "  Peso: " << peso[e] << endl;

				cout << "+----------------------------------------------+" << endl;
			}
		}
	}
	else
	{
		cout << "   +---------------------------------------------------+" << endl;
		cout << "   |   No existe una rutina con ID o el ID no existe   |" << endl;
		cout << "   +---------------------------------------------------+" << endl;
	}
	system("pause");
}

void ServicioRutina::verRutinasEntrenador(int idEntrenador)
{
	system("cls");
	Rutina rutina;
	int* rutinas;
	int nroRutina = 1;

	int cantRutinas = archivoRutinas.cantidadRegistros();
	if (cantRutinas != -1)
	{
		int cantRutinasXEntrenador = archivoRutinas.cantidadRutinasPorEntrenador(cantRutinas, idEntrenador);
		rutinas = new int[cantRutinasXEntrenador];
		if (rutinas == nullptr) { return; }

		*rutinas = archivoRutinas.rutinasPorEntrenador(cantRutinas, rutinas, idEntrenador);
		//         0  1   2   3
		// rutinas[5, 8, 14, 15];

		cout << "	+----------------------------------------------------------------------+" << endl;
		cout << "	|                              MIS RUTINAS                             |" << endl;
		cout << "	+----------------------------------------------------------------------+" << endl;

		for (int q = 0; q < cantRutinas; q++)
		{
			rutina = archivoRutinas.leerReg(rutinas[q]);

			cout << " |  " << nroRutina << ".  Nombre             : " << rutina.getNombreRutina() << endl;
			cout << " |     ID                 : #" << rutina.getIdRutina() << endl;
			cout << " |     Descripcion        : " << rutina.getDescripcion() << endl;
			cout << " |     Frecuencia semanal : " << rutina.getFrecuenciaSemanal() << endl;
			cout << " +----------------------------------------------------------------------+" << endl;
			nroRutina++;
		}
		cout << endl;
		delete[]rutinas;
	}
	else
	{
		cout << "	+----------------------------------------+" << endl;
		cout << "	|		No tenes rutinas a tu cargo		 |" << endl;
		cout << "	+----------------------------------------+" << endl;
	}
	system("pause");
}

void ServicioRutina::verDetalleRutinaSocio(int idRutina)
{
	system("cls");

	DetalleRutina detalle;
	ServicioEjercicio seEjercicio;

	cout << "		+--------------------------------------------+" << endl;
	cout << "		|				DETALLE DE RUTINA            |" << endl;
	cout << "		+--------------------------------------------+" << endl;
	cout << endl;

	int pos = archivoRutinas.buscarReg(idRutina);

	if (pos != -1)
	{
		detalle = archivoDetalleRutina.leerReg(pos);

		int* idEjercicio = detalle.getIdEjercicio();
		int* repeticiones = detalle.getRepeticiones();
		float* peso = detalle.getPeso();

		for (int r = 0; r < 10; r++)
		{
			seEjercicio.verEjercicio(idEjercicio[r]);

			cout << "  Repeticiones: " << repeticiones[r] << endl;

			if (peso[r] != 0)
				cout << "  Peso: " << peso[r] << endl;

			cout << "+----------------------------------------------+" << endl;
		}
	}
	else
	{
		cout << "+----------------------------------------------------------------------------------+" << endl;
		cout << "|			No tenes asignada ninguna rutina, en breve te asignaremos una			|" << endl;
		cout << "+----------------------------------------------------------------------------------+" << endl;
	}
	system("pause");
}

void ServicioRutina::verRutinaAsignadaSocio(int idRutina)
{
	system("cls");
	Rutina rutina;

	int pos = archivoRutinas.buscarReg(idRutina);

	cout << "   +--------------------------------------------------------------------------------+" << endl;
	cout << "   |                                RUTINA ASIGNADA                                 |" << endl;
	cout << "   +--------------------------------------------------------------------------------+" << endl;

	if (pos != -1)
	{
		rutina = archivoRutinas.leerReg(pos);

		cout << " +----------------------------------------------------------------------+" << endl;
		cout << " |  Nombre             : " << rutina.getNombreRutina() << endl;
		cout << " |  ID                 : #" << rutina.getIdRutina() << endl;
		cout << " |  Descripcion        : " << rutina.getDescripcion() << endl;
		cout << " |  Frecuencia Semanal : " << rutina.getFrecuenciaSemanal() << endl;
		cout << " +----------------------------------------------------------------------+" << endl;
	}
	else
	{
		cout << "	+----------------------------------------------------------------------------------+" << endl;
		cout << "	|			No tenes asignada ninguna rutina, en breve te asignaremos una		   |" << endl;
		cout << "	+----------------------------------------------------------------------------------+" << endl;
	}

	cout << endl;
	system("pause");
}

Rutina ServicioRutina::modificarRutina(Rutina rutina)
{
	string nombre, descripcion;
	int frecuencia;

	cout << endl;
	cout << " Nombre de la rutina      : ";
	cin >> nombre;

	cout << " Descripcion de la rutina : ";
	cin >> descripcion;

	cout << " Frecuencia semanal       : ";
	cin >> frecuencia;

	rutina.setNombreRutina(nombre);
	rutina.setDescripcion(descripcion);
	rutina.setFrecuenciaSemanal(frecuencia);

	return rutina;
}

DetalleRutina ServicioRutina::modificarDetalleRutina(DetalleRutina detalle)
{
	int opcion = 1, contador = 0;
	int idEjercicio[10] = {}, repeticiones[10] = {};
	float peso[10] = {};

	while (contador < 10 && opcion != 0)
	{
		// uso contador como indice
		cout << "Ejercicios cargados: " << contador << endl;
		cout << "  Ingresa el ID del ejercicio  : ";
		cin >> idEjercicio[contador];

		cout << "  Repeticiones                 : ";
		cin >> repeticiones[contador];

		cout << "  Peso                         : ";
		cin >> peso[contador];

		cout << endl;
		cout << "  Agregar otro ejercicio a la rutina? (Maximo 10)" << endl;
		cout << "                     1-SI | 0-NO " << endl;
		cout << endl;
		cout << " Su eleccion: ";
		cin >> opcion;

		contador++;
	}

	detalle.setIdEjercicio(idEjercicio);
	detalle.setRepeticiones(repeticiones);
	detalle.setPeso(peso);

	return detalle;
}

void ServicioRutina::buscarRutina()
{
	int idRutina;
	Rutina rutina;

	system("cls");
	cout << "	+-------------------------------------------------------------------------+" << endl;
	cout << "	|                                BUSCAR RUTINA                            |" << endl;
	cout << "	+-------------------------------------------------------------------------+" << endl;
	cout << endl;
	cout << " Ingrese ID de rutina: ";
	cin >> idRutina;

	int pos = archivoRutinas.buscarReg(idRutina);
	if (pos != -1)
	{
		rutina = archivoRutinas.leerReg(pos);
		cout << " Nombre             : " << rutina.getNombreRutina() << endl;
		cout << " ID                 : #" << rutina.getIdRutina() << endl;
		cout << " Descripcion        : " << rutina.getDescripcion() << endl;
		cout << " Frecuencia Semanal : " << rutina.getFrecuenciaSemanal() << endl;
		cout << "+------------------------------------------------------------------------+" << endl;

	}
	else
	{
		cout << "	+------------------------------------------------+" << endl;
		cout << "	|		ID no encontrado, volve a intentarlo	 |" << endl;
		cout << "	+------------------------------------------------+" << endl;
	}

	cout << endl;
	system("pause");
}

int ServicioRutina::elegirRutina(int idEntrenador)
{
	system("cls");
	int* rutinas;
	int opcion, nroRutinas = 1;
	Rutina rutina;

	int cantRutinas = archivoRutinas.cantidadRegistros();
	if (cantRutinas != -1)
	{
		int cantRutinasEntrenador = archivoRutinas.cantidadRutinasPorEntrenador(cantRutinas, idEntrenador);

		rutinas = new int[cantRutinasEntrenador];
		if (rutinas == nullptr)
		{
			cout << "   + -------------------------------------------------- +" << endl;
			cout << "   |   Error. Si el error persiste, genera un reclamo   |" << endl;
			cout << "   + -------------------------------------------------- +" << endl;
			return -2;
		}

		*rutinas = archivoRutinas.rutinasPorEntrenador(cantRutinas, rutinas, idEntrenador);

		cout << "+-------------------------------------------------------------------+" << endl;
		cout << "|                              ELEGIR RUTINA                        |" << endl;
		cout << "+-------------------------------------------------------------------+" << endl << endl;

		for (int q = 0; q < cantRutinasEntrenador; q++)
		{
			rutina = archivoRutinas.leerReg(rutinas[q]);

			cout << " " << nroRutinas << ". Nombre: " << rutina.getNombreRutina() << endl;
			cout << "  Descripcion: " << rutina.getDescripcion() << endl;
			cout << "  Frecuencia semanal: " << rutina.getFrecuenciaSemanal() << endl;
			cout << "+--------------------------------------------------------------+" << endl;

			nroRutinas++;
		}

		cout << endl;
		cout << "  Seleccione su rutina [1 a " << cantRutinasEntrenador << "]: ";
		cin >> opcion;

		rutina = archivoRutinas.leerReg(rutinas[opcion - 1]);

		int idRutina = rutina.getIdRutina();

		delete[]rutinas;

		return idRutina;
	}
	else
	{
		cout << "	+---------------------------------------------------------------------------------------------------+" << endl;
		cout << "	|	El entrenador no tiene rutina asignadas. Volve a intentarlo a la brevedad o genera un reclamo   |" << endl;
		cout << "	+---------------------------------------------------------------------------------------------------+" << endl;
		return -1;
	}
	system("pause");
}

void ServicioRutina::menuModificarRutina_Detalle(int idEntrenador)
{
	system("cls");

	int idRutina, opcion;
	Rutina rutina;
	DetalleRutina detalle;

	cout << "  Ingrese ID rutina: ";
	cin >> idRutina;

	int pos = archivoRutinas.buscarReg(idRutina);

	system("cls");
	if (pos != -1)
	{
		rutina = archivoRutinas.leerReg(pos);
		detalle = archivoDetalleRutina.leerReg(pos);

		cout << "		+-------------------------------------------------------------------+" << endl;
		cout << "		|                          MODIFICAR RUTINA                         |" << endl;
		cout << "		+-------------------------------------------------------------------+" << endl;
		cout << endl;

		if (rutina.getIdEntrenador() == idEntrenador)
		{
			cout << " Rutina: " << rutina.getNombreRutina() << endl;
			cout << endl;
			cout << "  [1]  Cambiar Datos de la Rutina " << endl;
			cout << "  [2]  Cambiar Detalles de la Rutina " << endl;
			cout << "  [3]  Salir " << endl;
			cout << endl;
			cout << "  Su seleccion: ";
			cin >> opcion;

			switch (opcion)
			{
			case 1:
				rutina = modificarRutina(rutina);
				break;
			case 2:
				detalle = modificarDetalleRutina(detalle);
				break;
			case 3:
				return;
				system("pause");
				break;
			default:
				cout << "  Opcion incorrecta" << endl;
				return;
				system("pause");
				break;
			}

			cout << endl;
			cout << " Confirmar cambios: 1 - SI | 2 - NO " << endl;
			cout << " Su eleccion: ";
			cin >> opcion;

			if (opcion == 1)
			{
				if (archivoRutinas.modificarReg(rutina, pos) && archivoDetalleRutina.modificarReg(detalle, pos))
				{
					system("cls");
					cout << "   +----------------------------------+" << endl;
					cout << "   |   Cambios realizados con exito   |" << endl;
					cout << "   +----------------------------------+" << endl;
				}
				else
				{
					cout << "   +---------------------------------------------+" << endl;
					cout << "   |   Error inesaperado, consulte con soporte   |" << endl;
					cout << "   +---------------------------------------------+" << endl;
				}
			}

		}
		else
		{
			cout << "   +--------------------------------------------------------------------------+" << endl;
			cout << "   |   La rutina no puede ser modificada, rutina creada por otro entrenador   |" << endl;
			cout << "   +--------------------------------------------------------------------------+" << endl;
		}
	}
	else
	{
		cout << "   +----------------------------------+" << endl;
		cout << "   |  ID ingresado no encontrado" << endl;
		cout << "   +----------------------------------+" << endl;
	}
	system("pause");
}

void ServicioRutina::ordenarRutinasPorNombre(Rutina rutinas[], int tam)
{
	/// Ordenamiento por intercambio o SWAP, similar al burbujeo
	Rutina aux;

	for (int q = 0; q < tam - 1; q++)
	{
		for (int r = q + 1; r < tam; r++)
		{
			if (strcmp(rutinas[q].getNombreRutina().c_str(), rutinas[r].getNombreRutina().c_str()) > 0)
			{
				aux = rutinas[q];
				rutinas[q] = rutinas[r];
				rutinas[r] = aux;
			}
		}
	}

}

void ServicioRutina::mostrarRutinasPorNombre()
{
	system("cls");
	Rutina* rutinas;
	int nroRutina = 1;

	int cantRutinas = archivoRutinas.cantidadRegistros();

	rutinas = new Rutina[cantRutinas];
	if (rutinas == nullptr) { return; }

	for (int a = 0; a < cantRutinas; a++)
	{
		rutinas[a] = archivoRutinas.leerReg(a);
	}

	ordenarRutinasPorNombre(rutinas, cantRutinas);
	cout << endl;
	cout << "   +-----------------------------------------------------------------------------+" << endl;
	cout << "   |                            RUTINAS ORDENADAS POR NOMBRE                     |" << endl;
	cout << "   +-----------------------------------------------------------------------------+" << endl;
	cout << endl;

	for (int c = 0; c < cantRutinas; c++)
	{
		cout << nroRutina << ". Nombre           : " << rutinas[c].getNombreRutina() << endl;
		cout << " ID                : #" << rutinas[c].getIdRutina() << endl;
		cout << " Descripcion       : " << rutinas[c].getDescripcion() << endl;
		cout << " Frecuencia semanal: " << rutinas[c].getFrecuenciaSemanal() << endl;
	}

	delete[]rutinas;
	system("pause");
}

void ServicioRutina::mostrarRutinasPorEntrenador(int idEntrenador)
{
	system("cls");
	Rutina rutina;
	int nroRutina = 1;

	int cantRutinas = archivoRutinas.cantidadRegistros();

	cout << "	+----------------------------------------------------------------------+" << endl;
	cout << "	|                            RUTINAS DISPONIBLES                       |" << endl;
	cout << "	+----------------------------------------------------------------------+" << endl;
	cout << endl;

	if (cantRutinas > 0)
	{
		for (int i = 0; i < cantRutinas; i++)
		{
			rutina = archivoRutinas.leerReg(i);
			if (rutina.getIdEntrenador() == idEntrenador)
			{
				cout << " " << nroRutina << ". Nombre             : " << rutina.getNombreRutina() << endl;
				cout << "     ID                 : #" << rutina.getIdRutina() << endl;
				cout << "     Descripcion        : " << rutina.getDescripcion() << endl;
				cout << "     Frecuencia Semanal : " << rutina.getFrecuenciaSemanal() << endl;
				cout << "+----------------------------------------------+" << endl;
				nroRutina++;
			}
		}
	}

	system("pause");
}
