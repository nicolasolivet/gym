//#include <iostream>
//
//#include "MenuSocio.h"
//#include "ServicioPago.h"
//#include "ServicioReclamo.h"
//#include "ServicioAsistencia.h"
//#include "ServicioEmpleado.h"
//#include "ServicioRutina.h"
//
//using namespace std;
//
//MenuSocio::MenuSocio(UsuarioAutenticado usuario) : _usuario(usuario)
//{
//    ServicioSocio _sSocio();
//}
//
//void MenuSocio::mostrarSubmenuSocio()
//{
//    system("cls");
//    int opcion;
//
//    if(!_sSocio.consultarEstadoDeSocio(_usuario.getIdUsuario()))
//    {
//        _usuario.setEstadoHabilitado(false);
//    }
//
//    cout << "+--------------------------------------+" << endl;
//    cout << "|      BIENVENIDO "<< _usuario.getNombre() << endl;
//    cout << "+--------------------------------------+" << endl;
//    cout << "| 1 - INGRESO AL GIMNASIO              |" << endl;
//    cout << "| 2 - INGRESO AL MENU SOCIO            |" << endl;
//    cout << "+--------------------------------------+" << endl;
//    cout << endl;
//    cout << " Su seleccion: ";
//    cin >> opcion;
//
//    if(opcion == 1)
//    {
//        mostrarMenuIngresoSocio();
//    }
//    else
//    {
//        mostrarMenuSocio();
//    }
//}
//
//void MenuSocio::mostrarMenuIngresoSocio()
//{
//    system("cls");
//    if(_usuario.estaHabilitado())
//    {
//        ServicioSocio socio;
//        ServicioAsistencia asistencia;
//
//        cout << "+---------------------------------------+" << endl;
//        cout << "|  - Bienvenido" << _usuario.getNombre() << endl;
//        cout << "+---------------------------------------+" << endl;
//
//        asistencia.registrarAsistencia(_usuario.getIdUsuario());
//    }
//    else
//    {
//        cout << "+--------------------------------------------------------------+" << endl;
//        cout << "| Actualmente no se encuentra habilitado para ingresar al GYM  |" << endl;
//        cout << "|   Comuniquese con un gerente para regularizar su estado.     |" << endl;
//        cout << "|                                                              |" << endl;
//        cout << "|                   EQUIPO DE METALGYM                         |" << endl;
//        cout << "+--------------------------------------------------------------+" << endl;
//    }
//    system("pause");
//
//    mostrarSubmenuSocio();
//}
//
//void MenuSocio::mostrarMenuSocio()
//{
//    int opcion;
//    ServicioSocio socio;
//
//    do
//    {
//        system("cls");
//        cout << "+--------------------------------------+" << endl;
//        cout << "|            MENU SOCIO                |" << endl;
//        cout << "+--------------------------------------+" << endl;
//        cout << "| 1 - PAGOS                            |" << endl;
//        cout << "| 2 - RUTINAS                          |" << endl;
//        cout << "| 3 - HORARIOS                         |" << endl;
//        cout << "| 4 - RECLAMOS                         |" << endl;
//        cout << "| 5 - CAMBIAR CONTRASENIA              |" << endl;
//        cout << "+--------------------------------------+" << endl;
//        cout << "| 0 - SALIR                            |" << endl;
//        cout << "+--------------------------------------+" << endl;
//
//        cout << endl;
//        cout << " Su seleccion: ";
//        cin >> opcion;
//
//        system("cls");
//        switch(opcion)
//        {
//        case 1:
//            gestionarPagos();
//            break;
//        case 2:
//            verRutina();
//            break;
//        case 3:
//            consultarHorarios();
//            break;
//        case 4:
//            presentarReclamo();
//            break;
//        case 5:
//            _sSocio.modificarContrasenia(_usuario.getIdUsuario());
//            break;
//        case 0:
//            cout << " Adios! " << endl;
//            system("pause");
//            break;
//        default:
//            cout << " Opcion incorrecta, volve a intentarlo. " << endl;
//            system("pause");
//            break;
//        }
//
//    }
//    while(opcion != 0);
//}
//
//void MenuSocio::gestionarPagos()
//{
//    int opcion;
//    ServicioSocio servicioSocio;
//    ServicioPago pago;
//
//    Socio socio = servicioSocio.buscarSocioId(_usuario.getIdUsuario());
//
//    do
//    {
//        system("cls");
//        cout << "+--------------------------------------+" << endl;
//        cout << "|               PAGOS                  |" << endl;
//        cout << "+--------------------------------------+" << endl;
//        cout << "| 1 - REALIZAR UN PAGO                 |" << endl;
//        cout << "| 2 - VER PAGOS ANTERIORES             |" << endl;
//        cout << "| 3 - VER FECHA DE VENCIMIENTO         |" << endl;
//        cout << "| 4 - VER PRECIOS DIFERENTES PASES     |" << endl;
//        cout << "| 5 - VER MI MEMBRESIA                 |" << endl;
//        cout << "+--------------------------------------+" << endl;
//        cout << "| 0 - VOLVER ATRAS                     |" << endl;
//        cout << "+--------------------------------------+" << endl;
//        cout << endl;
//        cout << " Su seleccion: ";
//        cin >> opcion;
//
//
//        system("cls");
//        switch(opcion)
//        {
//        case 1:
//            if(pago.registrarPago(_usuario.getIdUsuario(), socio.getMembresia(), socio.getFechaDeIngreso()))
//            {
//                servicioSocio.actualizarEstadoDelSocio(_usuario.getIdUsuario(), true);
//            }
//            break;
//        case 2:
//            pago.verPago(_usuario.getIdUsuario());
//            break;
//        case 3:
//            servicioSocio.mostrarFechaVencimiento(socio.getFechaDeIngreso(), _usuario.getIdUsuario());
//            break;
//        case 4:
//            mostrarPreciosDePases();
//            break;
//        case 5:
//            _sSocio.verMembresia(_usuario.getIdUsuario());
//            break;
//        case 0:
//            break;
//        default:
//            cout << "Opcion incorrecta, proba de nuevo." << endl;
//            system("pause");
//            break;
//        }
//
//    }
//    while(opcion != 0);
//
//}
//
//void MenuSocio::mostrarPreciosDePases()
//{
//    system("cls");
//    cout << endl;
//    cout << "+-------------------------+" << endl;
//    cout << "| - Pase Full : $55.000 - |" << endl;
//    cout << "| - Pase Smart: $35.000 - |" << endl;
//    cout << "| - Pase Fit  : $25.000 - |" << endl;
//    cout << "+-------------------------+" << endl;
//
//    system("pause");
//}
//
//void MenuSocio::verRutina()
//{
//    int opcion;
//    ServicioRutina sRutina;
//    Socio socio = _sSocio.buscarSocioId(_usuario.getIdUsuario());
//
//    do
//    {
//        system("cls");
//        cout << "+--------------------------------------+" << endl;
//        cout << "|               RUTINAS                |" << endl;
//        cout << "+--------------------------------------+" << endl;
//        cout << "| 1 - VER MI RUTINA                    |" << endl;
//        cout << "| 2 - VER DETALLES DE RUTINA           |" << endl;
//        cout << "+--------------------------------------+" << endl;
//        cout << "| 0 - VOLVER ATRAS                     |" << endl;
//        cout << "+--------------------------------------+" << endl;
//        cout << endl;
//        cout << " Su seleccion: ";
//        cin >> opcion;
//
//
//        system("cls");
//        switch(opcion)
//        {
//        case 1:
//            sRutina.verRutinaAsignada(socio.getIdRutina());
//            break;
//        case 2:
//            sRutina.verDetallesDeRutina(socio.getIdRutina());
//            break;
//        case 0:
//            break;
//        default:
//            cout << "ERROR" << endl;
//            break;
//        }
//
//    }
//    while(opcion != 0);
//
//}
//
//void MenuSocio::consultarHorarios()
//{
//    int opcion;
//    ServicioSocio socio;
//    ServicioEmpleado entrenador;
//
//    do
//    {
//        system("cls");
//        cout << "+----------------------------------------+" << endl;
//        cout << "|                HORARIOS                |" << endl;
//        cout << "+----------------------------------------+" << endl;
//        cout << "| 1 - VER HORARIOS DE ENTRENADORES       |" << endl;
//        cout << "| 2 - VER HORARIO DE MI ENTRENADOR       |" << endl;
//        cout << "| 3 - VER HORARIOS DE APERTURA Y CIERRE  |" << endl;
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
//            entrenador.mostrarHorariosDeEntrenadores();
//            break;
//        case 2:
//            socio.verEntrenadorAsignado(_usuario.getIdUsuario());
//            break;
//        case 3:
//            verHorariosGimnasio();
//            break;
//        default:
//            cout << "Opcion incorrecta" << endl;
//            break;
//        }
//
//    }
//    while(opcion != 0);
//
//}
//
//void MenuSocio::verHorariosGimnasio()
//{
//    system("cls");
//    cout << endl;
//    cout << "+--------------------------+" << endl;
//    cout << "|  HORARIOS DEL GIMNASIO   |" << endl;
//    cout << "|                          |" << endl;
//    cout << "|  LUN a DOM 08hs a 00hs   |" << endl;
//    cout << "+--------------------------+" << endl;
//    system("pause");
//}
//
//void MenuSocio::presentarReclamo()
//{
//    int opcion;
//    ServicioReclamo sr;
//
//    do
//    {
//        system("cls");
//
//        cout << "+--------------------------------------+" << endl;
//        cout << "|              RECLAMOS                |" << endl;
//        cout << "+--------------------------------------+" << endl;
//        cout << "| 1 - REALIZAR UN RECLAMO              |" << endl;
//        cout << "| 2 - VER ESTADO DE UN RECLAMO         |" << endl;
//        cout << "+--------------------------------------+" << endl;
//        cout << "| 0 - VOLVER ATRAS                     |" << endl;
//        cout << "+--------------------------------------+" << endl;
//        cout << endl;
//        cout << " Su seleccion: ";
//        cin >> opcion;
//
//
//        system("cls");
//        switch(opcion)
//        {
//        case 1:
//            sr.cargarReclamo(_usuario.getIdUsuario());
//            break;
//        case 2:
//            sr.verReclamosUsuario(_usuario.getIdUsuario());
//            break;
//        case 0:
//            break;
//        default:
//            cout << " Opcion incorrecta, proba de nuevo" << endl;
//            system("pause");
//            break;
//        }
//
//    }
//    while(opcion != 0);
//
//}
