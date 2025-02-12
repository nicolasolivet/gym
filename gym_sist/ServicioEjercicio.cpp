#include <iostream>
#include "Ejercicio.h"
#include "ServicioEjercicio.h"

using namespace std;

ServicioEjercicio::ServicioEjercicio()
{
	archivoEjercicios = ArchivoEjercicios("archivoEjercicios.dat");
}

int ServicioEjercicio::generarIdEjercicio()
{
	int cantEjercicios = archivoEjercicios.cantidadRegistros();

	if (cantEjercicios != -1)
		return cantEjercicios + 1;
	else
		return 1;
}

void ServicioEjercicio::agregarEjercicio()
{
	system("cls");
	string nombre, descripcion;

	cout << "   +------------------------------------------+" << endl;
	cout << "   |            AGREGAR EJERCICIO             |" << endl;
	cout << "   +------------------------------------------+" << endl;
	cout << endl;
	cout << " Nombre del ejercicio: ";
	cin >> nombre;
	cout << endl;
	cout << " Descripcion         : ";
	cin >> descripcion;

	int idEjercicio = generarIdEjercicio();

	Ejercicio ejercicio(idEjercicio, nombre, descripcion);

	if (archivoEjercicios.guardarReg(ejercicio))
	{
		cout << endl;
		cout << " Ejercicio guardado con exito. ID #" << idEjercicio << endl;
	}
	else
	{
		cout << endl;
		cout << " Hubo un error, volve a intentarlo" << endl;
	}
	cout << endl;

	system("pause");
}

void ServicioEjercicio::verEjercicios()
{
	system("cls");
	Ejercicio ejercicio;
	int contador = 0;

	int cantEjercicios = archivoEjercicios.cantidadRegistros();

	cout << "	+---------------------------------------------------------------------------------------+" << endl;
	cout << "	|                            LISTADO DE EJERCICIOS                                      |" << endl;
	cout << "	+---------------------------------------------------------------------------------------+" << endl;

	for (int i = 0; i < cantEjercicios; i++)
	{
		ejercicio = archivoEjercicios.leerReg(i);

		cout << "+-------------------------------------------------------------------------+" << endl;
		cout << "|  Nombre      : " << ejercicio.getNombreEjercicio() << endl;
		cout << "|  ID #        : " << ejercicio.getIdEjercicio() << endl;
		cout << "|  Descripcion : " << ejercicio.getDescripcion() << endl;
		cout << "+-------------------------------------------------------------------------+" << endl;
		contador++;
		if (contador % 5 == 0)
		{
			cout << endl;
			cout << "Siguiente pagina..." << endl;
			system("pause");
			system("cls");
		}
	}
	cout << endl;
	system("pause");
}

void ServicioEjercicio::verEjercicio(int idEjercicio)
{
	system("cls");

	int pos = archivoEjercicios.buscarReg(idEjercicio);
	Ejercicio ejercicio = archivoEjercicios.leerReg(pos);

	cout << "  ID           : #" << ejercicio.getIdEjercicio() << endl;
	cout << "  Nombre       : " << ejercicio.getNombreEjercicio() << endl;
}

void ServicioEjercicio::modificarEjercicio()
{
    system("cls");
    Ejercicio ejercicio;
    int idEjercicio;
    string nombre, descripcion;

    cout << "	+--------------------------------------------+" << endl;
    cout << "	|             MODIFICAR EJERCICIO            |" << endl;
    cout << "	+--------------------------------------------+" << endl;
    cout << endl;

    cout << " Ingrese id del ejercicio a modificar: ";
    cin >> idEjercicio;

    int pos = archivoEjercicios.buscarReg(idEjercicio);

    if(pos != -1)
    {
        ejercicio = archivoEjercicios.leerReg(pos);

        cout << endl;
        cout << " Nombre: " << ejercicio.getNombreEjercicio() << endl;
        cout << " Descripcion: " << ejercicio.getDescripcion() << endl;
        system("pause");

        system("cls");
        cout << "+--------------------------------------------+" << endl;
        cout << "|             MODIFICAR EJERCICIO            |" << endl;
        cout << "+--------------------------------------------+" << endl;
        cout << endl;
		cout << "  Nuevo nombre: " << endl;
		cin >> nombre;
        cout << endl;
        cout << "  Nueva descripcion: " << endl;
        cin >> descripcion;

        ejercicio.setNombreEjercicio(nombre);
        ejercicio.setDescripcion(descripcion);

        if(archivoEjercicios.modificarReg(ejercicio, pos))
        {
            cout << endl;
            cout << " +---------------------------------------+" << endl;
            cout << " |   Modificacion realizada con exito!   |" << endl;
            cout << " +---------------------------------------+" << endl;
        }
        else
        {
            cout << endl;
			cout << " +-------------------------------+" << endl;
            cout << " |   Error, volve a intentarlo   |" << endl;
			cout << " +-------------------------------+" << endl;
        }
    }
    else
    {
        cout << endl;
		cout << " +-------------------------------+" << endl;
        cout << " |   El ID ingresado no existe   |" << endl;
		cout << " +-------------------------------+" << endl;
    }
    system("pause");
}


