#include <iostream>
#include <string>
#include <iomanip>
#include "ServicioEmpleado.h"
#include "ServicioSocio.h"
#include "ServicioActividad.h"
using namespace std;

ServicioEmpleado::ServicioEmpleado()
{
	archivoEmpleado = ArchivoEmpleados("archivoEmpleados.dat");
}

int ServicioEmpleado::chequearExistenciaEmpleado(int dni)
{
	int cantEmp = archivoEmpleado.cantidadRegistros();
	Empleado empleado;

	if (cantEmp > 0)
	{
		for (int i = 0; i < cantEmp; i++)
		{
			empleado = archivoEmpleado.leerReg(i);
			if (empleado.getDni() == dni)
			{
				return empleado.getIdUsuario();
			}
		}
	}
	return -1;
}

int ServicioEmpleado::generarIdEmpleado()
{
	ServicioSocio socio;
	return socio.generarId();
}

void ServicioEmpleado::agregarEmpleado(int idRol)
{
	ServicioActividad servActi;

	string nombre, apellido, pass1, pass2;
	int dni, opcion;
	int dia, mes, anio;
	int idTurno, idActividadPrincipal = 0;
	Fecha fechaIngreso;
	bool estado = true;
	bool semana[7] = {};

	system("cls");
	cout << "		+-------------------------------------------+" << endl;
	cout << "		|         INGRESO DE DATOS PERSONALES		|" << endl;
	cout << "		+-------------------------------------------+" << endl;
	cout << endl;
	cout << " DNI: ";
	cin >> dni;

	if (chequearExistenciaEmpleado(dni) != 1)
	{
		cout << "  +------------------------------------------------------+" << endl;
		cout << "  |   El DNI ingresado ya existe. ID usuario" << chequearExistenciaEmpleado(dni) << endl;
		cout << "  +------------------------------------------------------+" << endl;
		return;
	}

	cout << "  Ahora te pediremos los datos del nuevo empleado" << endl;

	system("cls");
	cout << " Nombre: ";
	cin >> nombre;
	cout << " Apellido: ";
	cin >> apellido;

	system("cls");
	cout << "	+-----------------------+" << endl;
	cout << "	|  FECHA DE NACIMIENTO  |" << endl;
	cout << "	+-----------------------+" << endl;
	cout << endl;
	cout << " Dia: ";
	cin >> dia;
	cout << " Mes: ";
	cin >> mes;
	cout << " Anio: ";
	cin >> anio;

	Fecha fechaNacimiento(dia, mes, anio);

	do
	{
		system("cls");
		cout << "	+----------------------+" << endl;
		cout << "	|      CONTRASENIA     |" << endl;
		cout << "	+----------------------+" << endl;
		cout << endl;
		cout << " Ingresa contrasenia: ";
		cin >> pass1;
		cout << " Confirma la contrasenia: ";
		cin >> pass2;

		if (strcmp(pass1.c_str(), pass2.c_str()) != 0)
		{
			cout << " Contrasenias no coinciden, proba de nuevo" << endl;
			system("pause");
		}

	} while (strcmp(pass1.c_str(), pass2.c_str()) != 0);

	system("cls");
	cout << "	+------------------------+" << endl;
	cout << "	|      TURNO LABORAL     |" << endl;
	cout << "	+------------------------+" << endl;
	cout << endl;
	cout << " [0] 8hs a 13hs " << endl;
	cout << " [1] 13hs a 18hs " << endl;
	cout << " [2] 18hs a 23hs " << endl;
	cout << endl;
	cout << " Opcion elegida: ";
	cin >> idTurno;

	if (idRol == 1)
	{
		system("cls");
		cout << "+---------------------------------+" << endl;
		cout << "|            ACTIVIDAD            |" << endl;
		cout << "+---------------------------------+" << endl;
		cout << endl;
		cout << " [1] Ver actividades disponibles " << endl;
		cout << " [2] Agregar nueva actividad " << endl;
		cout << endl;
		cout << " Opcion elegida: ";
		cin >> opcion;
		if (opcion == 1)
		{
			servActi.listarActividades();
			cout << endl;
			cout << " Ingrese ID actividad principal: ";
			cin >> idActividadPrincipal;
		}
		else
		{
			servActi.agregarActividad();
		}
	}

	int idEmpleado = generarIdEmpleado();

	Empleado empleado(nombre, apellido, dni, idEmpleado, fechaNacimiento, fechaIngreso, pass1, estado, idRol, idTurno, idActividadPrincipal, semana);

	if (archivoEmpleado.guardarReg(empleado))
	{
		cout << "	+-------------------------------------+" << endl;
		cout << "	|   Empleado agregado exitosamente!   |" << endl;
		cout << "	+-------------------------------------+" << endl;
	}
	else
	{
		cout << "	+-------------------------------+" << endl;
		cout << "	|   Error, volve a intentarlo   |" << endl;
		cout << "	+-------------------------------+" << endl;
	}
	system("pause");
}

void ServicioEmpleado::verEmpleados(int idRol)
{
	system("cls");

	Empleado empleado;
	ServicioActividad servActi;
	int contador = 0;
	int cantEmpleados = archivoEmpleado.cantidadRegistros();

	if (idRol == 0)
	{
		cout << "		+--------------------------+" << endl;
		cout << "		|         GERENTES         |" << endl;
		cout << "		+--------------------------+" << endl << endl;
	}
	else
	{
		cout << "		+----------------------------------------------------------------------+" << endl;
		cout << "		|                              ENTRENADORES                            |" << endl;
		cout << "		+----------------------------------------------------------------------+" << endl << endl;
	}

	for (int q = 0; q < cantEmpleados; q++)
	{
		empleado = archivoEmpleado.leerReg(q);

		if (empleado.getIdRol() == idRol && empleado.getEstado())
		{
			cout << string(80, '-') << endl;
			cout << left << setw(20) << "NOMBRE: " << "|"
				<< setw(20) << "APELLIDO: " << "|"
				<< setw(20) << "ID: " << "|"
				<< setw(20) << "FECHA DE INGRESO:  " << "|" << endl;
			cout << string(80, '-') << endl;

			cout << left << setw(15) << empleado.getNombre() << "|"
				<< setw(20) << empleado.getApellido() << "|"
				<< setw(20) << empleado.getIdUsuario() << "|"
				<< setw(20) << empleado.getFechaIngreso().toString() << "|" << endl;

			if (empleado.getIdActividad() == 0)
			{
				cout << left << setw(20) << " ACTIVIDAD: Gerente" << endl;
			}
			else
			{
				servActi.buscarActividad(empleado.getIdActividad());
			}
			cout << string(80, '-') << endl;
			//cout << "+----------------------------------+" << endl;
			contador++;
			if (contador % 5 == 0)
			{
				cout << endl;
				cout << "Siguiente pagina..." << endl;
				system("pause");
				system("cls");
			}
		}
	}
	system("pause");
}

void ServicioEmpleado::modificarEmpleado(int idRol)
{
	system("cls");

	Empleado empleado;
	string nombre, apellido;
	int dia, mes, anio;
	int idUsuario, opcion, eliminar;
	bool estado = true;
	Fecha fechaNacimiento;

	cout << "		+ -------------------------------------------------------------------- +" << endl;
	cout << "		|                          MODIFICAR EMPLEADO                          |" << endl;
	cout << "		+ -------------------------------------------------------------------- +" << endl << endl;

	cout << "  Ingresa el id del empleado que deseas modificar" << endl;
	cin >> idUsuario;

	int pos = archivoEmpleado.buscarReg(idUsuario);
	if (pos != -1)
	{
		empleado = archivoEmpleado.leerReg(pos);
		if (empleado.getIdRol() == idRol)
		{
			system("cls");
			cout << "+ ------------------------------- +" << endl;
			cout << "| 1 - Modificar datos personales  |" << endl;
			cout << "+ ------------------------------- +" << endl;
			cout << "| 2 - Modificar estado/eliminar   |" << endl;
			cout << "+ ------------------------------- +" << endl;
			cout << endl;
			cout << " Opcion elegida: ";
			cin >> opcion;

			system("cls");
			switch (opcion)
			{
			case 1:
				cout << " Nombre: " << empleado.getNombre() << ", Apellido: " << empleado.getApellido() << endl;
				cout << endl;
				cout << " Ingrese Nombre: ";
				cin >> nombre;
				cout << " Ingrese Apellido: ";
				cin >> apellido;

				empleado.setNombre(nombre);
				empleado.setApellido(apellido);

				cout << endl;
				cout << " Fecha de Nacimiento: " << empleado.getFechaNacimiento().toString() << endl;
				cout << endl;
				cout << " Ingrese Dia: ";
				cin >> dia;
				cout << " Ingrese Mes: ";
				cin >> mes;
				cout << " Ingrese Anio: ";
				cin >> anio;

				fechaNacimiento.setDia(dia);
				fechaNacimiento.setMes(mes);
				fechaNacimiento.setDia(anio);

				empleado.setFechaNacimiento(fechaNacimiento);
				break;

			case 2:

				if (empleado.getEstado())
				{
					cout << " Estado Actual: ACTIVO" << endl;
					cout << endl;
					cout << " Desea eliminar empleado: 1 - Si | 0 - NO" << endl;
					cout << " Opcion elegida: ";
					cin >> eliminar;
					if (eliminar == 1)
					{
						estado = false;
						empleado.setEstado(estado);
					}
				}
				break;

			default:
				cout << "  Opcion incorrecta, volve a intentarlo" << endl;
				break;
			}
		}

		cout << " Confirmar Cambios?: 1 - Si | 0 - NO" << endl;
		cin >> opcion;

		if (opcion == 1 && archivoEmpleado.modificarReg(empleado, pos))
		{
			cout << " " << endl;
			cout << "+ -------------------------------------- +" << endl;
			cout << "|   Empleado actualizado correctamente   |" << endl;
			cout << "+ -------------------------------------- +" << endl;
		}
	}
	else
	{
		cout << "	+ ---------------------------------------- + " << endl;
		cout << "	|   ID no encontrado, volve a intentarlo   |" << endl;
		cout << "	+ ---------------------------------------- +" << endl;
	}

	system("pause");
}

void ServicioEmpleado::buscarEmpleado(int idRol)
{
	system("cls");

	Empleado empleado;
	int idUsuario;

	cout << endl;
	cout << "		+ ---------------------------- +" << endl;
	cout << "		|		BUSCAR EMPLEADO		   |" << endl;
	cout << "		+ ---------------------------- +" << endl;

	cout << "  Ingresa el id del usuario: #";
	cin >> idUsuario;

	int pos = archivoEmpleado.buscarReg(idUsuario);
	if (pos != -1)
	{
		empleado = archivoEmpleado.leerReg(pos);
		if (empleado.getIdRol() == idRol)
		{
			cout << string(90, '-') << endl;
			cout << left << setw(20) << "NOMBRE: " << "|"
				<< setw(20) << "APELLIDO" << "|"
				<< setw(20) << "ID" << "|"
				<< setw(20) << "DNI" << "|"
				<< setw(20) << "FECHA DE INGRESO" << "|"
				<< setw(20) << "ESTADO" << endl;
			cout << string(90, '-') << endl;

			cout << left << setw(15) << empleado.getNombre() << "|"
				<< setw(20) << empleado.getApellido() << "|"
				<< setw(20) << empleado.getIdUsuario() << "|"
				<< setw(20) << empleado.getFechaIngreso().toString() << "|"
				<< setw(20) << empleado.getEstado() << endl;
			cout << string(90, '-') << endl;
		}
	}
	else
	{
		cout << endl;
		cout << "	+ ---------------------------------------- + " << endl;
		cout << "	|   ID no encontrado, volve a intentarlo   |" << endl;
		cout << "	+ ---------------------------------------- +" << endl;
	}
	system("pause");
}

void ServicioEmpleado::restaurarEmpleado(int idRol)
{
	int idEmpleado;
	bool opcion;
	Empleado empleado;

	cout << endl;
	cout << "		+ -------------------------------- +" << endl;
	cout << "		|		RESTAURAR EMPLEADO		   |" << endl;
	cout << "		+ -------------------------------- +" << endl;

	cout << "  Ingresa el id del empleado: #";
	cin >> idEmpleado;

	int pos = archivoEmpleado.buscarReg(idEmpleado);

	if (pos != -1)
	{
		empleado = archivoEmpleado.leerReg(pos);

		if (empleado.getIdRol() == idRol)
		{
			if (!empleado.getEstado())
			{
				cout << " Nombre        : " << empleado.getNombre() << endl;
				cout << " Apellido      : " << empleado.getApellido() << endl;
				cout << " DNI           : " << empleado.getDni() << endl;
				cout << " Fecha Ingreso : " << empleado.getFechaIngreso().toString() << endl;

				cout << endl;
				cout << " Desea volver a activar al empleado? 1 - SI | 0 - NO " << endl;
				cout << " Opcion elegida: ";
				cin >> opcion;

				empleado.setEstado(opcion);

				if (archivoEmpleado.modificarReg(empleado, pos))
				{
					system("cls");
					cout << endl;
					cout << "	+ ---------------- +" << endl;
					cout << "   | ID # " << idEmpleado << "|" << endl;
					cout << "   | Estado: " << empleado.getEstado() ? cout << "ACTIVO" : cout << "INACTIVO" << "|" << endl;
					cout << "	+ ---------------- +" << endl;
				}
			}
			else
			{
				system("cls");
				cout << " + -------------- + " << endl;
				cout << " | Estado: ACTIVO | " << endl;
				cout << " + -------------- + " << endl;
			}
		}
		else
		{
			system("cls");
			cout << " + ----------------------------------------------- + " << endl;
			cout << " |   ID ingresado es erroneo, volve a intentarlo   | " << endl;
			cout << " + ----------------------------------------------- + " << endl;
		}
	}
	system("pause");
}

void ServicioEmpleado::asignarHorarios()
{
	Empleado empleado;
	int idUsuario, opcion;
	bool diaSemana[7] = {}, agregar;
	string horario;

	system("cls");
	cout << "	+ --------------------------------------- +" << endl;
	cout << "	|            ASIGNAR HORARIOS             |" << endl;
	cout << "	+ --------------------------------------- +" << endl;
	cout << endl;
	cout << " Ingrese ID del entrenador: ";
	cin >> idUsuario;

	int pos = archivoEmpleado.buscarReg(idUsuario);

	if (pos != -1)
	{
		empleado = archivoEmpleado.leerReg(pos);

		switch (empleado.getIdTurno())
		{
		case 0:
			horario = "08hs a 13hs";
			break;
		case 1:
			horario = "13hs a 18hs";
			break;
		case 2:
			horario = "18hs a 23hs";
			break;
		}

		for (int q = 0; q < 7; q++)
		{
			if (!diaSemana[q])
			{
				switch (q)
				{
				case 0:
					cout << " Lunes de " << horario << endl;
					break;
				case 1:
					cout << " Martes de " << horario << endl;
					break;
				case 2:
					cout << " Miercoles de " << horario << endl;
					break;
				case 3:
					cout << " Jueves de " << horario << endl;
					break;
				case 4:
					cout << " Viernes de " << horario << endl;
					break;
				case 5:
					cout << " Sabado de " << horario << endl;
					break;
				case 6:
					cout << " Domingo de " << horario << endl;
					break;
				}
				// si el dia esta en false/cero pregunta, si deseo agregar el dia o no
				cout << " Agregar? 1 - SI | 0 - NO: ";
				cin >> agregar;
				cout << "   + -------------------------------------- +" << endl;
				diaSemana[q] = agregar;
			}
		}

		cout << endl;
		cout << " Confirmas eleccion? 1 - SI | 0 - NO: ";
		cin >> opcion;

		if (opcion == 1)
		{
			empleado.setDiaSem(diaSemana);
			if (archivoEmpleado.modificarReg(empleado, pos))
			{
				system("cls");
				cout << "   + ---------------------------------- +" << endl;
				cout << "   |   Horarios cargados exitosamente   |" << endl;
				cout << "   + ---------------------------------- +" << endl;
			}
		}
	}
	else
	{
		system("cls");
		cout << " + ----------------------------------------------- + " << endl;
		cout << " |   ID ingresado es erroneo, volve a intentarlo   | " << endl;
		cout << " + ----------------------------------------------- + " << endl;
		system("pause");
		return;
	}
	system("pause");
}

void ServicioEmpleado::verHorariosAsignados(int idUsuario)
{
	system("cls");

	Empleado empleado;
	string horario;
	bool diasTrabajo[7] = {};

	system("cls");
	cout << "   + ---------------------------------- + " << endl;
	cout << "   |         HORARIOS ASIGNADOS         | " << endl;
	cout << "   + ---------------------------------- + " << endl;

	int pos = archivoEmpleado.buscarReg(idUsuario);
	if (pos != -1)
	{
		empleado = archivoEmpleado.leerReg(pos);

		switch (empleado.getIdTurno())
		{
		case 0:
			horario = "08hs a 13hs";
			break;
		case 1:
			horario = "13hs a 18hs";
			break;
		case 2:
			horario = "18hs a 23hs";
			break;
		}

		for (int q = 0; q < 7; q++)
		{
			diasTrabajo[q] = empleado.getDiaSem();
			if (diasTrabajo[q])
			{
				switch (q)
				{
				case 0:
					cout << " Lunes de " << horario << endl;
					break;
				case 1:
					cout << " Martes de " << horario << endl;
					break;
				case 2:
					cout << " Miercoles de " << horario << endl;
					break;
				case 3:
					cout << " Jueves de " << horario << endl;
					break;
				case 4:
					cout << " Viernes de " << horario << endl;
					break;
				case 5:
					cout << " Sabado de " << horario << endl;
					break;
				case 6:
					cout << " Domingo de " << horario << endl;
					break;
				}
				cout << "   + ---------------------------------- + " << endl;
			}
		}

		cout << "   + ---------------------------- +" << endl;
		cout << "   |            FRANCOS           |" << endl;
		cout << "   + ---------------------------- +" << endl;

		for (int q = 0; q < 7; q++)
		{
			diasTrabajo[q] = empleado.getDiaSem();
			if (!diasTrabajo[q])
			{
				switch (q)
				{
				case 0:
					system("cls");
					cout << "  Lunes FRANCO" << endl;
					break;
				case 1:
					system("cls");
					cout << "  Martes FRANCO" << endl;
					break;
				case 2:
					system("cls");
					cout << "  Miercoles FRANCO" << endl;
					break;
				case 3:
					system("cls");
					cout << "  Jueves FRANCO" << endl;
					break;
				case 4:
					system("cls");
					cout << "  Viernes FRANCO" << endl;
					break;
				case 5:
					system("cls");
					cout << "  Sabado FRANCO" << endl;
					break;
				case 6:
					system("cls");
					cout << "  Domingo FRANCO" << endl;
					break;
				}
				cout << "   + ---------------------------- +" << endl;
			}
		}

	}
	else
	{
		system("cls");
		cout << "   + ------------------------------- + " << endl;
		cout << "   |   No tenes horario asignados   | " << endl;
		cout << "   + ------------------------------- + " << endl;
		system("pause");
		return;
	}
	system("pause");

}

void ServicioEmpleado::modificarContrasenia(int idUsuario)
{
	system("cls");

	Empleado empleado;
	string pass1, pass2;
	int opcion;
	int pos = archivoEmpleado.buscarReg(idUsuario);

	cout << endl;
	cout << "   + ------------------------------------- + " << endl;
	cout << "   |         MODIFICAR CONTRASENIA         | " << endl;
	cout << "   + ------------------------------------- + " << endl;


	if (pos != -1)
	{
		empleado = archivoEmpleado.leerReg(pos);

		cout << "  Contrasenia actual: " << empleado.getContrasenia() << endl << endl;

		do
		{
			system("cls");
			cout << endl;
			cout << "  Ingresa una nueva contrasenia: " << endl;
			cin >> pass1;
			cout << "  Confirma la contrasenia: " << endl;
			cin >> pass2;
			cout << "  Tu nueva contrasenia: " << endl;
			cin >> pass1;
		} while (pass1 != pass2);

		cout << "  Confirmas el cambio de contrasenia? [1] SI - [2] NO " << endl;
		cout << "  Opcion elegida: ";
		cin >> opcion;

		if (opcion == 1)
		{
			system("cls");
			empleado.setContrasenia(pass1);
			if (archivoEmpleado.modificarReg(empleado, pos))
			{
				cout << endl;
				cout << "   + ------------------------------ + " << endl;
				cout << "   |   Cambio realizado con exito   | " << endl;
				cout << "   + ------------------------------ + " << endl;
			}
			else
			{
				cout << endl;
				cout << "   + ------------------------------------- + " << endl;
				cout << "   |   Hubo un error, volve a intentarlo   | " << endl;
				cout << "   + ------------------------------------- + " << endl;
			}
		}
	}
	else
	{
		system("cls");
		cout << " + ----------------------------------------------- + " << endl;
		cout << " |   ID ingresado es erroneo, volve a intentarlo   | " << endl;
		cout << " + ----------------------------------------------- + " << endl;
		return;
	}
	system("pause");

}

int ServicioEmpleado::obtenerUltimoId()
{
	Empleado empleado;

	int cantEmpleados = archivoEmpleado.cantidadRegistros();

	if (cantEmpleados > 0)
	{
		empleado = archivoEmpleado.leerReg(cantEmpleados - 1);
		return empleado.getIdUsuario() + 1;
	}

	return -1;
}

int ServicioEmpleado::elegirEntrenador()
{
	int* empleados;
	int* idsEmpleados;
	int opcion;
	Empleado entrenador;
	ServicioActividad actividad;

	int cantEmpleados = archivoEmpleado.cantidadRegistros();
	int entrenadoresActivos = archivoEmpleado.cantidadEmpleadosPorEstado(cantEmpleados, true, 1);

	empleados = new int[entrenadoresActivos];
	idsEmpleados = new int[entrenadoresActivos];

	if (empleados == nullptr || idsEmpleados == nullptr)
	{
		return -1;
	}

	*empleados = archivoEmpleado.empleadosActivos(cantEmpleados, empleados, entrenadoresActivos, 1);

	cout << "      +-------------------------------------------+" << endl;
	cout << "      |          ENTRENADORES DISPONIBLES         |" << endl;
	cout << "      +-------------------------------------------+" << endl;

	for (int i = 0; i < entrenadoresActivos; i++)
	{
		entrenador = archivoEmpleado.leerReg(empleados[i]);
		idsEmpleados[i] = entrenador.getIdUsuario();

		cout << " " << i + 1 << ". Nombre: " << entrenador.getNombre() << endl;
		cout << "  Apellido: " << entrenador.getApellido() << endl;
		actividad.buscarActividad(entrenador.getIdActividad());

		cout << "+--------------------------------+" << endl;
	}

	cout << endl;
	cout << " Seleccione un entrenador: [1 - " << entrenadoresActivos << "]: ";
	cin >> opcion;

	int entrenadorSelected = idsEmpleados[opcion - 1];

	delete[]empleados;
	delete[]idsEmpleados;

	return entrenadorSelected;
}


void ServicioEmpleado::verSociosAsignados(int idEntrenador)
{
	system("cls");
	string horario;
	ServicioSocio socio;
	Empleado entrenador;

	int pos = archivoEmpleado.buscarReg(idEntrenador);
	entrenador = archivoEmpleado.leerReg(pos);

	switch (entrenador.getIdTurno())
	{
	case 0:
		horario = "08hs a 13hs";
		break;
	case 1:
		horario = "13hs a 18hs";
		break;
	case 2:
		horario = "18hs a 23hs";
		break;
	}

	cout << string(65, '-') << endl;
	cout << left << setw(25) << "| ENTRENADOR" << "|"
		<< setw(25) << "| HORARIO" << endl;
	cout << string(65, '-') << endl;
	cout << left << setw(20) << "| " << entrenador.getNombre() << " " << entrenador.getApellido() << "|"
		<< setw(20) << "| " << horario << endl;
	cout << string(65, '-') << endl;

	socio.listarSociosPorEntrenador(idEntrenador);

	system("pause");
}

void ServicioEmpleado::mostrarHorariosEntrenadores()
{
	system("cls");
	string horario, nombre, apellido;
	Empleado entrenador;
	ServicioActividad actividad;

	int cantEmpleados = archivoEmpleado.cantidadRegistros();

	cout << "   + -------------------------------------------------------------------------- +" << endl;
	cout << "   |                           HORARIOS DE ENTRENADORES                         |" << endl;
	cout << "   + -------------------------------------------------------------------------- +" << endl;

	for (int q = 0; q < cantEmpleados; q++)
	{
		entrenador = archivoEmpleado.leerReg(q);
		if (entrenador.getIdRol() == 1 && entrenador.getEstado())
		{
			switch (entrenador.getIdTurno())
			{
			case 0:
				horario = "08hs a 13hs";
				break;
			case 1:
				horario = "13hs a 18hs";
				break;
			case 2:
				horario = "18hs a 23hs";
				break;
			}

			cout << string(105, '-') << endl;
			cout << left << setw(5) << "ID" << "|"
				<< setw(20) << "Entrenador/a" << "|"
				<< setw(14) << "Horarios" << endl;
			cout << string(105, '-') << endl;

			system("cls");
			cout << "----------------------------------------------" << endl;
			cout << "   Entrenador/a: " << entrenador.getNombre() << " " << entrenador.getApellido() << endl;
			cout << "   ID: " << entrenador.getIdUsuario() << endl;
			cout << "   Horarios" << horario << endl;
			actividad.buscarActividad(entrenador.getIdActividad());
		}
	}
	cout << endl;
	system("pause");
}

void ServicioEmpleado::listarEmpleadoOrdenados(int idRol, int lista)
{
	system("cls");
	Empleado* empleado;
	int* posEmpleado;
	int indice = 1;

	int cantidad = archivoEmpleado.cantidadRegistros();
	int cantActivos = archivoEmpleado.cantidadEmpleadosPorEstado(cantidad, true, idRol);

	empleado = new Empleado[cantActivos];
	posEmpleado = new int[cantActivos];

	if (empleado == nullptr || posEmpleado == nullptr)
	{
		return;
	}

	*posEmpleado = archivoEmpleado.empleadosActivos(cantidad, posEmpleado, cantActivos, idRol);

	for (int i = 0; i < cantActivos; i++)
	{
		empleado[i] = archivoEmpleado.leerReg(posEmpleado[i]);
	}

	if (lista == 0)
	{
		ordenarPorApellido(empleado, cantActivos);
		cout << "+------------------------------------------------------+" << endl;
		cout << "|              LISTA ORDENADA POR APELLIDO             |" << endl;
		cout << "+------------------------------------------------------+" << endl;
	}
	else
	{
		ordenarPorDni(empleado, cantActivos);
		cout << "+------------------------------------------------------+" << endl;
		cout << "|                 LISTA ORDENADA POR DNI               |" << endl;
		cout << "+------------------------------------------------------+" << endl;
	}

	for (int i = 0; i < cantActivos; i++)
	{
		cout << " " << indice << ". DNI: " << empleado[i].getDni() << ", " << empleado[i].getApellido() << ", " << empleado[i].getNombre() << "   ID #" << empleado[i].getIdUsuario() << endl;
		cout << "+------------------------------------------------------+" << endl;
		indice++;
	}

	cout << endl;

	delete[]empleado;
	delete[]posEmpleado;

	system("pause");
}

void ServicioEmpleado::ordenarPorApellido(Empleado empleado[], int tam)
{
	Empleado aux;

	///Ordenamiento por intercambio o SWAP, similar al burbujeo, sacado del libro pag 428
	for (int i = 0; i < tam - 1; i++)
	{
		for (int j = i + 1; j < tam; j++)
		{
			if (strcmp(empleado[i].getApellido().c_str(), empleado[j].getApellido().c_str()) > 0)
			{
				aux = empleado[i];
				empleado[i] = empleado[j];
				empleado[j] = aux;
			}
		}
	}
}

void ServicioEmpleado::ordenarPorDni(Empleado empleado[], int tam)
{
	Empleado aux;

	for (int i = 0; i < tam - 1; i++)
	{
		for (int j = i + 1; j < tam; j++)
		{
			if (empleado[i].getDni() > empleado[j].getDni())
			{
				aux = empleado[i];
				empleado[i] = empleado[j];
				empleado[j] = aux;
			}
		}
	}
}
