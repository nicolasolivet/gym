#include <iostream>
#include "ServicioReclamo.h"
#include "Reclamo.h"
#include "Fecha.h"
#include "ServicioSocio.h"

using namespace std;

ServicioReclamo::ServicioReclamo()
{

    _archivoReclamos = ArchivoReclamos("archivoReclamos.dat");
}

void ServicioReclamo::cargarReclamo(int idUsuario)
{
    system("cls");

    bool resuelto = false;
    Fecha fechaActual;
    string detalle;

    cout << "+-------------------------------------------+" << endl;
    cout << "|           ||| NUEVO RECLAMO |||           |" << endl;
    cout << "+-------------------------------------------+" << endl;
    cout << "|                                           |" << endl;
    cout << "|    --- Por favor ingrese su reclamo ---   | " << endl;
    cout << "+-------------------------------------------+" << endl;
    cout << endl;
    cout << " Detalles: ";

    cin.ignore();
    getline(cin, detalle);

    int idReclamo = obtenerUltimoIdReclamo();

    Reclamo reclamo(idReclamo, idUsuario, resuelto, detalle, fechaActual);

    if(_archivoReclamos.guardarReclamo(reclamo))
    {
        cout << "+-------------------------------------------+" << endl;
        cout << "   Reclamo realizado con exito, ID #" << idReclamo << " --- " << endl;
        cout << "   Fecha: " << fechaActual.toString() << endl;
        cout << "+-------------------------------------------+" << endl;
    }
    else
    {
        system("cls");
        cout << "+---------------------------------------------------------------+" << endl;
        cout << "| --- No se pudo registrar su reclamo, intentelo mas tarde. --- |";
        cout << "+---------------------------------------------------------------+" << endl;
    }

    system("pause");
}

void ServicioReclamo::mostrarReclamo(bool resuelto)
{

    system("cls");
    Reclamo r;

    int cantidad = _archivoReclamos.getCantidadReclamos();

    if(cantidad > 0)
    {
        for(int i=0; i<cantidad; i++)
        {
            r = _archivoReclamos.leerReclamo(i);

            if(r.getEstaResuelto() == resuelto)
            {
                cout << "-----------------------------------------" << endl;
                cout << " ID Reclamo #" << r.getIdReclamo() << endl;
                cout << " ID Usuario #" << r.getIdUsuario() << endl;
                cout << " Fecha: " << r.getFecha().toString() << endl;
                cout << " Detalle: " << r.getDetalle() << endl;
            }
        }
    }
    else
    {
        cout << " --- No existen reclamos --- " << endl;
    }

    cout << endl;
    system("pause");
}

void ServicioReclamo::verReclamosUsuario(int idUsuario)
{

    system("cls");

    Reclamo reclamo;
    int *vectReclamos;

    int cantidad = _archivoReclamos.getCantidadReclamos();

    int tam = _archivoReclamos.cantidadDeRegistrosPorUsuario(cantidad, idUsuario);

    vectReclamos = new int[tam];

    if(vectReclamos == nullptr)
    {
        return;
    }

    *vectReclamos = _archivoReclamos.leerRegistrosPorUsuario(cantidad, vectReclamos, tam, idUsuario);

    cout << "+-------------------------------------------+" << endl;
    cout << "|                   RECLAMOS                |" << endl;
    cout << "+-------------------------------------------+" << endl;

    for(int i=0; i<tam; i++)
    {

        reclamo = _archivoReclamos.leerReclamo(vectReclamos[i]);

        if(reclamo.getEstaResuelto())
        {
            cout << " Estado del reclamo: RESUELTO" << endl;
        }
        else
        {
            cout << " Estado del reclamo: EN PROCESO" << endl;
        }
        cout << " ID #" << reclamo.getIdReclamo() << endl;
        cout << " Detalle: " << reclamo.getDetalle() << endl;
        cout << "+-------------------------------------------+" << endl;
    }

    delete[]vectReclamos;

    system("pause");
}

void ServicioReclamo::cambiarEstadoReclamo()
{

    system("cls");
    int idReclamo, opcion;
    Reclamo reclamo;

    cout << "+-------------------------------------------+" << endl;
    cout << "|              MODIFICAR RECLAMO            |" << endl;
    cout << "+-------------------------------------------+" << endl;
    cout << endl;

    cout << " Ingrese ID de Reclamo: ";
    cin >> idReclamo;

    int pos = _archivoReclamos.buscarReclamo(idReclamo);

    if(pos != -1)
    {
        reclamo = _archivoReclamos.leerReclamo(pos);

        if(reclamo.getEstaResuelto())
        {
            cout << " Estado: RESUELTO" << endl;
            cout << endl;
            cout << " Desea cambiar el estado a ACTIVO: 1-SI | 2-NO" << endl;
            cin >> opcion;
            if(opcion)
            {
                reclamo.setEstaResuelto(false);
                _archivoReclamos.modificarReclamo(reclamo, pos);
            }
        }
        else
        {
            cout << " Estado: ACTIVO" << endl;
            cout << endl;
            cout << " Desea cambiar el estado a RESUELTO: 1-SI | 2-NO" << endl;
            cin >> opcion;
            if(opcion)
            {
                reclamo.setEstaResuelto(true);
                _archivoReclamos.modificarReclamo(reclamo, pos);
            }
        }
    }
    else
    {
        cout << "+---------------------------+" << endl;
        cout << "|  --- El ID no existe ---  |" << endl;
        cout << "+---------------------------+" << endl;
    }

    cout << endl;
    system("pause");
}

int ServicioReclamo::obtenerUltimoIdReclamo()
{
    int cantidad = _archivoReclamos.getCantidadReclamos();

    if(cantidad != -1)
    {
        return cantidad+1;
    }
    else
    {
        return 1;
    }
}
