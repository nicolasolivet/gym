#include <iostream>

#include "MenuGerente.h"

#include "ServicioSocio.h"
#include "ServicioEmpleado.h"
#include "ServicioReclamo.h"
#include "ServicioPago.h"
#include "ServicioRutina.h"

using namespace std;
//
//MenuGerente::MenuGerente(UsuarioAutenticado usuario) : _usuario(usuario) {}
//
//void MenuGerente::comprobarEstadoDeGerente()
//{
//    system("cls");
//    if(!_usuario.estaHabilitado())
//    {
//        cout << "+--------------------------------------------------------------+" << endl;
//        cout << "| Actualmente no se encuentra habilitado para ingresar al Menu |" << endl;
//        cout << "|   Comuniquese con un gerente para regularizar su estado.     |" << endl;
//        cout << "|                                                              |" << endl;
//        cout << "|                   EQUIPO DE METALGYM                         |" << endl;
//        cout << "+--------------------------------------------------------------+" << endl;
//        return;
//    }
//
//    mostrarMenuGerente();
//}
//
//void MenuGerente::mostrarMenuGerente()
//{
//    int opcion;
//
//    do
//    {
//        system("cls");
//        cout << "  GERENTE: #" << _usuario.getIdUsuario()  << endl;
//        cout << "+--------------------------------------+" << endl;
//        cout << "|             MENU GERENTE             |" << endl;
//        cout << "+--------------------------------------+" << endl;
//        cout << "| 1 - GESTIONAR SOCIOS                 |" << endl;
//        cout << "| 2 - GESTIONAR ENTRENADORES           |" << endl;
//        cout << "| 3 - GESTIONAR GERENTE                |" << endl;
//        cout << "| 4 - GESTIONAR PAGOS                  |" << endl;
//        cout << "| 5 - GESTIONAR RECLAMOS               |" << endl;
//        cout << "| 6 - VER ESTADISTICAS                 |" << endl;
//        cout << "+--------------------------------------+" << endl;
//        cout << "| 0 - SALIR                            |" << endl;
//        cout << "+--------------------------------------+" << endl;
//        cout << endl;
//        cout << " Su seleccion: ";
//        cin >> opcion;
//
//        system("cls");
//        switch(opcion)
//        {
//        case 1:
//            gestionarSocios();
//            break;
//        case 2:
//            gestionarEntrenadores();
//            break;
//        case 3:
//            gestionarGerentes();
//
//            break;
//        case 4:
//            gestionarPagos();
//
//            break;
//        case 5:
//            gestionarReclamos();
//
//            break;
//        case 6:
//            verEstadisticas();
//            break;
//        case 0:
//            break;
//        default:
//            cout << "Opcion incorrecta" << endl;
//            system("pause");
//            break;
//        }
//
//    }
//    while(opcion != 0);
//
//}
//
//void MenuGerente::gestionarSocios()
//{
//    int opcion;
//    ServicioSocio socio;
//
//    do
//    {
//        system("cls");
//        cout << "+----------------------------------------+" << endl;
//        cout << "|                SOCIOS                  |" << endl;
//        cout << "+----------------------------------------+" << endl;
//        cout << "| 1 - VER LISTA DE SOCIOS                |" << endl;
//        cout << "| 2 - AGREGAR NUEVO SOCIO                |" << endl;
//        cout << "| 3 - MODIFICAR SOCIO                    |" << endl;
//        cout << "| 4 - BUSCAR SOCIO                       |" << endl;
//        cout << "| 5 - SOCIOS SIN ENTRENADOR              |" << endl;
//        cout << "+----------------------------------------+" << endl;
//        cout << "| 0 - VOLVER ATRAS                       |" << endl;
//        cout << "+----------------------------------------+" << endl;
//        cout << endl;
//        cout << " Su seleccion: ";
//        cin >> opcion;
//
//        system("cls");
//        switch(opcion)
//        {
//        case 1:
//            verOpcionesDeListasSocios();
//            break;
//        case 2:
//            socio.agregarSocio();
//            break;
//        case 3:
//            socio.modificarSocio();
//            break;
//        case 4:
//            socio.buscarSocioPorId();
//            break;
//            case 5:
//            socio.verListaDeSociosSinEntrenador();
//            break;
//        case 0:
//            break;
//        default:
//            cout << "Opcion incorrecta" << endl;
//            system("pause");
//            break;
//        }
//
//    }
//    while(opcion != 0);
//
//}
//
//void MenuGerente::verOpcionesDeListasSocios()
//{
//    int opcion;
//    ServicioSocio socio;
//
//    do
//    {
//        system("cls");
//        cout << "+----------------------------------------+" << endl;
//        cout << "|           LISTAS DE SOCIOS             |" << endl;
//        cout << "+----------------------------------------+" << endl;
//        cout << "| 1 - VER LISTA ORDENADA POR ID          |" << endl;
//        cout << "| 2 - VER LISTA ORDENADA POR DNI         |" << endl;
//        cout << "| 3 - VER LISTA ORDENADA POR APELLIDO    |" << endl;
//        cout << "+----------------------------------------+" << endl;
//        cout << "| 0 - VOLVER ATRAS                       |" << endl;
//        cout << "+----------------------------------------+" << endl;
//        cout << endl;
//        cout << " Su seleccion: ";
//        cin >> opcion;
//
//        system("cls");
//        switch(opcion)
//        {
//        case 1:
//            socio.verSocios();
//            break;
//        case 2:
//            socio.verSociosPorDni();
//            break;
//        case 3:
//            socio.verSociosPorApellido();
//            break;
//        case 0:
//            break;
//        default:
//            cout << "Opcion incorrecta" << endl;
//            system("pause");
//            break;
//        }
//
//    }
//    while(opcion != 0);
//}
//
//void MenuGerente::gestionarEntrenadores()
//{
//    int opcion;
//    ServicioEmpleado entrenador;
//    ServicioRutina rutina;
//
//    do
//    {
//        system("cls");
//        cout << "+--------------------------------------------+" << endl;
//        cout << "|                ENTRENADORES                |" << endl;
//        cout << "+--------------------------------------------+" << endl;
//        cout << "| 1 - VER LISTAS DE ENTRENADORES             |" << endl;
//        cout << "| 2 - AGREGAR NUEVO ENTRENADOR               |" << endl;
//        cout << "| 3 - MODIFICAR ENTRENADOR                   |" << endl;
//        cout << "| 4 - BUSCAR ENTRENADOR                      |" << endl;
//        cout << "| 5 - RESTAURAR ENTRENADOR                   |" << endl;
//        cout << "| 6 - ASIGNAR HORARIOS                       |" << endl;
//        cout << "| 7 - LISTA DE TODAS LAS RUTINAS ORDENADAS   |" << endl;
//        cout << "+--------------------------------------------+" << endl;
//        cout << "| 0 - VOLVER ATRAS                           |" << endl;
//        cout << "+--------------------------------------------+" << endl;
//        cout << endl;
//        cout << " Su seleccion: ";
//        cin >> opcion;
//
//
//        system("cls");
//        switch(opcion)
//        {
//        case 1:
//            verOpcionesDeListasEntrenadores();
//            break;
//        case 2:
//            entrenador.agregarEmpleado(1);
//            break;
//        case 3:
//            entrenador.modificarEmpleado(1);
//            break;
//        case 4:
//            entrenador.buscarUnEmpleado(1);
//            break;
//        case 5:
//            entrenador.restaurarUnEmpleado(1);
//            break;
//        case 6:
//            entrenador.asignarHorarios();
//            break;
//            case 7:
//            rutina.mostrarRutinaPorNombre();
//            break;
//        case 0:
//            break;
//        default:
//            cout << "Opcion incorrecta" << endl;
//            system("pause");
//            break;
//        }
//
//    }
//    while(opcion != 0);
//
//}
//
//void MenuGerente::verOpcionesDeListasEntrenadores()
//{
//    int opcion;
//    ServicioEmpleado entrenador;
//
//    do
//    {
//        system("cls");
//        cout << "+----------------------------------------+" << endl;
//        cout << "|         LISTAS DE ENTRENADORES         |" << endl;
//        cout << "+----------------------------------------+" << endl;
//        cout << "| 1 - VER LISTA ORDENADA POR ID          |" << endl;
//        cout << "| 2 - VER LISTA ORDENADA POR DNI         |" << endl;
//        cout << "| 3 - VER LISTA ORDENADA POR APELLIDO    |" << endl;
//        cout << "+----------------------------------------+" << endl;
//        cout << "| 0 - VOLVER ATRAS                       |" << endl;
//        cout << "+----------------------------------------+" << endl;
//        cout << endl;
//        cout << " Su seleccion: ";
//        cin >> opcion;
//
//        system("cls");
//        switch(opcion)
//        {
//        case 1:
//            entrenador.verEmpleados(1);
//            break;
//        case 2:
//            entrenador.listarEmpleadoOrdenados(1, 1);
//            break;
//        case 3:
//            entrenador.listarEmpleadoOrdenados(1, 0);
//            break;
//        case 0:
//            break;
//        default:
//            cout << "Opcion incorrecta" << endl;
//            system("pause");
//            break;
//        }
//
//    }
//    while(opcion != 0);
//}
//
//void MenuGerente::gestionarGerentes()
//{
//    int opcion;
//    ServicioEmpleado gerente;
//
//    do
//    {
//        system("cls");
//        cout << "+----------------------------------------+" << endl;
//        cout << "|                GERENTES                |" << endl;
//        cout << "+----------------------------------------+" << endl;
//        cout << "| 1 - VER LISTA DE GERENTES              |" << endl;
//        cout << "| 2 - AGREGAR NUEVO GERENTE              |" << endl;
//        cout << "| 3 - MODIFICAR GERENTE                  |" << endl;
//        cout << "| 4 - BUSCAR GERENTE                     |" << endl;
//        cout << "| 5 - RESTAURAR GERENTE                  |" << endl;
//        cout << "| 6 - CAMBIAR CONTRASENIA                |" << endl;
//        cout << "+----------------------------------------+" << endl;
//        cout << "| 0 - VOLVER ATRAS                       |" << endl;
//        cout << "+----------------------------------------+" << endl;
//        cout << endl;
//        cout << " Su seleccion: ";
//        cin >> opcion;
//
//
//        system("cls");
//        switch(opcion)
//        {
//        case 1:
//            gerente.verEmpleados(0);
//            break;
//        case 2:
//            gerente.agregarEmpleado(0);
//            break;
//        case 3:
//            gerente.modificarContrasenia(0);
//            break;
//        case 4:
//            gerente.buscarUnEmpleado(0);
//            break;
//        case 5:
//            gerente.restaurarUnEmpleado(0);
//            break;
//        case 6:
//            gerente.modificarContrasenia(_usuario.getIdUsuario());
//            break;
//        case 0:
//            break;
//        default:
//            cout << "Opcion incorrecta" << endl;
//            system("pause");
//            break;
//        }
//
//    }
//    while(opcion != 0);
//
//}
//void MenuGerente::gestionarPagos()
//{
//    int opcion;
//    ServicioPago pago;
//
//    do
//    {
//        system("cls");
//        cout << "+----------------------------------------+" << endl;
//        cout << "|            PAGOS DE SOCIOS             |" << endl;
//        cout << "+----------------------------------------+" << endl;
//        cout << "| 1 - VER LISTA DE PAGOS POR MES         |" << endl;
//        cout << "| 2 - VER LISTA DE PAGOS POR ANIO        |" << endl;
//        cout << "| 3 - VER LISTA POR TIPOS DE PASES       |" << endl;
//        cout << "| 4 - VER LISTA ANUAL POR SOCIO          |" << endl;
//        cout << "+----------------------------------------+" << endl;
//        cout << "| 0 - VOLVER ATRAS                       |" << endl;
//        cout << "+----------------------------------------+" << endl;
//        cout << endl;
//        cout << " Su seleccion: ";
//        cin >> opcion;
//
//        system("cls");
//        switch(opcion)
//        {
//        case 1:
//            pago.verPagosPorMes();
//            break;
//        case 2:
//            pago.verPagosPorAnio();
//            break;
//        case 3:
//            pago.mostrarListaDePagosPorTipoDePase();
//            break;
//        case 4:
//            pago.verIngresosAnualesPorSocios();
//            break;
//        case 0:
//            break;
//        default:
//            cout << "Opcion incorrecta" << endl;
//            system("pause");
//            break;
//        }
//
//    }
//    while(opcion != 0);
//
//}
//
//void MenuGerente::gestionarReclamos()
//{
//    int opcion;
//    ServicioReclamo reclamo;
//
//    do
//    {
//        system("cls");
//        cout << "+-------------------------------------------+" << endl;
//        cout << "|                 RECLAMOS                  |" << endl;
//        cout << "+-------------------------------------------+" << endl;
//        cout << "| 1 - VER LISTA DE RECLAMOS ACTIVOS         |" << endl;
//        cout << "| 2 - VER LISTA DE RECLAMOS RESUELTOS       |" << endl;
//        cout << "| 3 - MODIFICAR RECLAMO                     |" << endl;
//        cout << "+-------------------------------------------+" << endl;
//        cout << "| 0 - VOLVER ATRAS                          |" << endl;
//        cout << "+-------------------------------------------+" << endl;
//        cout << endl;
//        cout << " Su seleccion: ";
//        cin >> opcion;
//
//
//        system("cls");
//        switch(opcion)
//        {
//        case 1:
//            reclamo.mostrarReclamo(false);
//            break;
//        case 2:
//            reclamo.mostrarReclamo(true);
//            break;
//        case 3:
//            reclamo.cambiarEstadoReclamo();
//            break;
//        case 0:
//            break;
//        default:
//            cout << "Opcion incorrecta" << endl;
//            system("pause");
//            break;
//        }
//
//    }
//    while(opcion != 0);
//
//}
//void MenuGerente::verEstadisticas()
//{
//    int opcion;
//
//    ServicioPago pago;
//    do
//    {
//        system("cls");
//        cout << "+---------------------------------------------+" << endl;
//        cout << "|                 ESTADISTICAS                |" << endl;
//        cout << "+---------------------------------------------+" << endl;
//        cout << "| 1 - VER ESTADISTICAS DE INGRESOS POR ANIO   |" << endl;
//        cout << "| 2 - VER ESTADISTICA DE INGRESOS POR MES     |" << endl;
//        cout << "+---------------------------------------------+" << endl;
//        cout << "| 0 - VOLVER ATRAS                            |" << endl;
//        cout << "+---------------------------------------------+" << endl;
//        cout << endl;
//        cout << " Su seleccion: ";
//        cin >> opcion;
//
//
//        system("cls");
//        switch(opcion)
//        {
//        case 1:
//            pago.verIngresosAnuales();
//            break;
//        case 2:
//            pago.verIngresosMensuales();
//            break;
//        case 0:
//            break;
//        default:
//            cout << "Opcion incorrecta" << endl;
//            system("pause");
//            break;
//        }
//
//    }
//    while(opcion != 0);
//
//}

