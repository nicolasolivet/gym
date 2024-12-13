#include <iostream>
#include <iomanip>
#include "ServicioActividad.h"

using namespace std;

ServicioActividad::ServicioActividad()
{
    _archivoActividad = ArchivoActividades("archivoActividades.dat");
}


void ServicioActividad::listarActividades()
{
    system("cls");

    Actividad actividad;

    int cantidad = _archivoActividad.cantidadRegistrosActividades();

    for(int i=0; i<cantidad; i++)
    {
        actividad = _archivoActividad.leerRegistroActividad(i);

        cout << "--------------------------" << endl;
        cout << " Nombre Actividad: " << actividad.getNombre() << endl;
        cout << " ID actividad: #" << actividad.getIdActividad() << endl;
    }

    cout << endl;
    system("pause");
}

int ServicioActividad::agregarActividad()
{
    system("cls");
    string nombre;
    int idActividad, opcion, cantidad;

    Actividad actividad;

    if(_archivoActividad.cantidadRegistrosActividades() != -1)
    {
        cantidad = _archivoActividad.cantidadRegistrosActividades()+1;
    }
    else
    {
        cantidad = 1;
    }

    cout << "---------------------------------------------" << endl;
    cout << " Nombre Actividad que realizara: ";
    cin >> nombre;
    cout << endl;
    cout << " Confirmar accion? 1-SI | 2-NO" << endl;
    cin >> opcion;

    if(opcion == 1)
    {
        actividad = Actividad(cantidad, nombre);

        if(_archivoActividad.guardarActividad(actividad))
        {
            system("cls");
            cout << " Actividad agregada exitosamente." << endl;
            cout << " ID actividad: #" << cantidad << endl;
            system("pause");
            return cantidad;
        }
        else
        {
            cout << "Error de registro..." << endl;
            system("pause");
            return -1;
        }
    }

    return -1;
}

void ServicioActividad::modificarActividad()
{
    system("cls");
    int idActividad;
    string nombre;
    Actividad actividad;

    cout << "Ingrese ID de Actividad a modificar: ";
    cin >> idActividad;

    int posicion = _archivoActividad.buscarActividad(idActividad);

    if(posicion != -1)
    {
        actividad = _archivoActividad.leerRegistroActividad(posicion);

        cout << "Ingrese nombre de la actividad: ";
        cin >> nombre;

        actividad.setNombre(nombre);

        if(_archivoActividad.guardarActividad(actividad, posicion))
        {
            system("cls");
            cout << "Cambio realizado con exito" << endl;
        }

    }
    else
    {
        cout << "ID no econtrado." << endl;
    }

    system("pause");
}

void ServicioActividad::buscarActividad(int idActividad)
{
    Actividad actividad;

    int pos = _archivoActividad.buscarActividad(idActividad);

    if (pos != -1)
    {
        actividad = _archivoActividad.leerRegistroActividad(pos);

        cout << " Actividad:      " << actividad.getNombre() << endl;
    }
    else
    {
        cout << " Actividad no encontrada..." << endl;
    }

}
