#include <iostream>
#include "ServicioReclamo.h"
#include "Reclamo.h"
#include "Fecha.h"
#include "ServicioSocio.h"

using namespace std;

ServicioReclamo::ServicioReclamo()
{
	_archivoReclamo = ArchivoReclamos("archivoReclamo.dat");
}

int ServicioReclamo::autoGenerarIdReclamo()
{
	int cantidad = _archivoReclamo.cantidadRegistros();

	if (cantidad != -1)
		return cantidad + 1;
	else
		return 0;
}

void ServicioReclamo::iniciarReclamo(int idUsuario)
{
	system("cls");

	Fecha fechaActual;
	bool resuelto = false;
	string detalle;

	cout << "	+-------------------------------------------+" << endl;
	cout << "	|               NUEVO RECLAMO               |" << endl;
	cout << "	+-------------------------------------------+" << endl;
	cout << "	|        Por favor ingrese su reclamo       | " << endl;
	cout << "	+-------------------------------------------+" << endl;
	cout << endl;
	cin >> detalle;
	cout << endl;

	int idReclamo = autoGenerarIdReclamo();

	Reclamo reclamo(idReclamo, idUsuario, false, detalle, fechaActual);
	//Reclamo(int idReclamo, int idUsuario, bool resuelto, std::string detalle, Fecha fecha);

	if (_archivoReclamo.guardarReg(reclamo))
	{
		cout << "	+-------------------------------------------+" << endl;
		cout << "	|   Reclamo registrado con exito. ID #" << idReclamo << endl;
		cout << "	|	Fecha: " << fechaActual.toString() << endl;
		cout << "	+-------------------------------------------+" << endl;
	}
	else
	{
		cout << "	+-------------------------------------------+" << endl;
		cout << "	|   No se pudo registar su reclamo. Intentalo mas tarde. " << idReclamo << endl;
		cout << "	+-------------------------------------------+" << endl;
	}
	system("pause");
}

void ServicioReclamo::mostrarReclamo(bool resuelto)
{
	system("cls");
	Reclamo reclamo;

	int cantReclamos = _archivoReclamo.cantidadRegistros();

	if (cantReclamos > 0)
	{
		for (int c = 0; c < cantReclamos; c++)
		{
			reclamo = _archivoReclamo.leerReg(c);
			if (reclamo.getResuelto() == false)
			{
				cout << " ID Reclamo #" << reclamo.getIdReclamo() << endl;
				cout << " ID Usuario #" << reclamo.getIdUsuario() << endl; 
				cout << " Fecha: " << reclamo.getFecha().toString() << endl; 
				cout << " Detalle: " << reclamo.getDetalle() << endl; 
			}
		}
	}
}

//void ServicioReclamo::mostrarReclamo(bool resuelto)
//{
//
//    system("cls");
//    Reclamo r;
//
//    int cantidad = _archivoReclamos.cantidadRegistros();
//
//    if(cantidad > 0)
//    {
//        for(int i=0; i<cantidad; i++)
//        {
//            r = _archivoReclamos.leerReclamo(i);
//
//            if(r.getResuelto() == resuelto)
//            {
//                cout << "-----------------------------------------" << endl;
//                cout << " ID Reclamo #" << r.getIdReclamo() << endl;
//                cout << " ID Usuario #" << r.getIdUsuario() << endl;
//                cout << " Fecha: " << r.getFecha().toString() << endl;
//                cout << " Detalle: " << r.getDetalle() << endl;
//            }
//        }
//    }
//    else
//    {
//        cout << " --- No existen reclamos --- " << endl;
//    }
//
//    cout << endl;
//    system("pause");
//}


//void ServicioReclamo::verReclamosUsuario(int idUsuario)
//{
//
//    system("cls");
//
//    Reclamo reclamo;
//    int *vectReclamos;
//
//    int cantidad = _archivoReclamos.getCantidadReclamos();
//
//    int tam = _archivoReclamos.cantidadDeRegistrosPorUsuario(cantidad, idUsuario);
//
//    vectReclamos = new int[tam];
//
//    if(vectReclamos == nullptr)
//    {
//        return;
//    }
//
//    *vectReclamos = _archivoReclamos.leerRegistrosPorUsuario(cantidad, vectReclamos, tam, idUsuario);
//
//    cout << "+-------------------------------------------+" << endl;
//    cout << "|                   RECLAMOS                |" << endl;
//    cout << "+-------------------------------------------+" << endl;
//
//    for(int i=0; i<tam; i++)
//    {
//
//        reclamo = _archivoReclamos.leerReclamo(vectReclamos[i]);
//
//        if(reclamo.getResuelto())
//        {
//            cout << " Estado del reclamo: RESUELTO" << endl;
//        }
//        else
//        {
//            cout << " Estado del reclamo: EN PROCESO" << endl;
//        }
//        cout << " ID #" << reclamo.getIdReclamo() << endl;
//        cout << " Detalle: " << reclamo.getDetalle() << endl;
//        cout << "+-------------------------------------------+" << endl;
//    }
//
//    delete[]vectReclamos;
//
//    system("pause");
//}

//void ServicioReclamo::cambiarEstadoReclamo()
//{
//
//    system("cls");
//    int idReclamo, opcion;
//    Reclamo reclamo;
//
//    cout << "+-------------------------------------------+" << endl;
//    cout << "|              MODIFICAR RECLAMO            |" << endl;
//    cout << "+-------------------------------------------+" << endl;
//    cout << endl;
//
//    cout << " Ingrese ID de Reclamo: ";
//    cin >> idReclamo;
//
//    int pos = _archivoReclamos.buscarReclamo(idReclamo);
//
//    if(pos != -1)
//    {
//        reclamo = _archivoReclamos.leerReclamo(pos);
//
//        if(reclamo.getResuelto())
//        {
//            cout << " Estado: RESUELTO" << endl;
//            cout << endl;
//            cout << " Desea cambiar el estado a ACTIVO: 1-SI | 2-NO" << endl;
//            cin >> opcion;
//            if(opcion)
//            {
//                reclamo.setResuelto(false);
//                _archivoReclamos.modificarReclamo(reclamo, pos);
//            }
//        }
//        else
//        {
//            cout << " Estado: ACTIVO" << endl;
//            cout << endl;
//            cout << " Desea cambiar el estado a RESUELTO: 1-SI | 2-NO" << endl;
//            cin >> opcion;
//            if(opcion)
//            {
//                reclamo.setResuelto(true);
//                _archivoReclamos.modificarReclamo(reclamo, pos);
//            }
//        }
//    }
//    else
//    {
//        cout << "+---------------------------+" << endl;
//        cout << "|  --- El ID no existe ---  |" << endl;
//        cout << "+---------------------------+" << endl;
//    }
//
//    cout << endl;
//    system("pause");
//}

