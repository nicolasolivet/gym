#include <iostream>
#include "MenuEntrenador.h"
using namespace std;

MenuEntrenador::MenuEntrenador(UsuarioAutenticado usuario) : usuario(usuario) {}

void MenuEntrenador::comprobarEstadoDeEntrenador()
{
    system("cls");
    if(!usuario.getEstado())
    {
        cout << "+--------------------------------------------------------------------+" << endl;
        cout << "|   Actualmente no se encuentra habilitado/a para ingresar al Menu   |" << endl;
        cout << "|                   comunicate con tu gerente                        |" << endl;
        cout << "+--------------------------------------------------------------------+" << endl;
        return;
    }

    mostrarMenuEntrenador();
}

void MenuEntrenador::mostrarMenuEntrenador()
{
    int opcion;
    do
    {
        system("cls");
        cout << "          ENTRENADOR: #" << usuario.getIdUsuario() << endl;
        cout << "   +-------------------------------+" << endl;
        cout << "   |        MENU ENTRENADOR        |" << endl;
        cout << "   +-------------------------------+" << endl;
        cout << "   |   [1]  HORARIOS Y SOCIOS      |" << endl;
        cout << "   |   [2]  RUTINAS Y servEjercicioS   |" << endl;
        cout << "   |   [3]  RECLAMOS               |" << endl;
        cout << "   |   [4]  CAMBIAR CONTRASENIA    |" << endl;
        cout << "   +-------------------------------+" << endl;
        cout << "   |   [0]  SALIR                  |" << endl;
        cout << "   +-------------------------------+" << endl;
        cout << endl;
        cout << " Elegiste: ";
        cin >> opcion;

        system("cls");
        switch(opcion)
        {
        case 1:
            verHorariosYSociosAsignados();
            break;
        case 2:
            crearModificarRutina();
            break;
        case 3:
            verReclamos();
            break;
        case 4:
            servEmpleado.modificarContrasenia(usuario.getIdUsuario());
            break;
        case 0:
            break;
        default:
            cout << "  Pifiaste, volve a probar" << endl;
            break;
        }

    }
    while(opcion != 0);

}

void MenuEntrenador::verHorariosYSociosAsignados()
{
    int opcion;
    ServicioSocio servSocio;

    do
    {
        system("cls");
        cout << "      +-----------------------------------------+" << endl;
        cout << "      |           HORARIOS Y SOCIOS             | " << endl;
        cout << "      +-----------------------------------------+" << endl;
        cout << "      |   [1]  VER HORARIOS ASIGNADOS           |" << endl;
        cout << "      |   [2]  VER SOCIOS ASIGNADOS             |" << endl;
        cout << "      |   [3]  VER SOCIOS SIN RUTINA ASIGNADA   |" << endl;
        cout << "      |   [4]  ASIGNAR UNA RUTINA               |" << endl;
        cout << "      +-----------------------------------------+" << endl;
        cout << "      |   [0]  VOLVER ATRAS                     |" << endl;
        cout << "      +-----------------------------------------+" << endl;
        cout << endl;
        cout << " Elegiste: ";
        cin >> opcion;


        system("cls");
        switch(opcion)
        {
        case 1:
            servEmpleado.verHorariosAsignados(usuario.getIdUsuario());
            break;
        case 2:
            servEmpleado.verSociosAsignados(usuario.getIdUsuario());
            break;
        case 3:
            servSocio.listarSociosSinRutina(usuario.getIdUsuario());
            break;
        case 4:
            servSocio.asignarRutina(usuario.getIdUsuario());
            break;
        case 0:
            break;
        default:
            cout << "  Pifiaste, volve a probar" << endl;
            system("pause");
            break;
        }

    }
    while(opcion != 0);

}

void MenuEntrenador::crearModificarRutina()
{
    
    int opcion;

    do
    {
        system("cls");
        cout << "      +--------------------------------------+" << endl;
        cout << "      |               RUTINAS                |" << endl;
        cout << "      +--------------------------------------+" << endl;
        cout << "      |   [1]  VER MIS RUTINAS               |" << endl;
        cout << "      |   [2]  VER DETALLE DE RUTINAS        |" << endl;
        cout << "      |   [3]  CREAR UNA RUTINA              |" << endl;
        cout << "      |   [4]  BUSCAR UNA RUTINA             |" << endl;
        cout << "      |   [5]  MODIFICAR UNA RUTINA          |" << endl;
        cout << "      |   [6]  VER servEjercicioS                |" << endl;
        cout << "      |   [7]  AGREGAR UN servEjercicio          |" << endl;
        cout << "      |   [8]  MODIFICAR UN servEjercicio        |" << endl;
        cout << "      +--------------------------------------+" << endl;
        cout << "      |   [0]  VOLVER ATRAS                  |" << endl;
        cout << "      +--------------------------------------+" << endl;
        cout << endl;
        cout << " Elegiste: ";
        cin >> opcion;


        system("cls");
        switch(opcion)
        {
        case 1:
            servRutina.verRutinasEntrenador(usuario.getIdUsuario());
            break;
        case 2:
            servRutina.verDetalleRutina();
            break;
        case 3:
            servRutina.crearRutina(usuario.getIdUsuario());
            break;
        case 4:
            servRutina.buscarRutina();
            break;
        case 5:
            servRutina.menuModificarRutina_Detalle(usuario.getIdUsuario());
            break;
        case 6:
            servEjercicio.verEjercicios();
            break;
        case 7:
            servEjercicio.agregarEjercicio();
            break;
        case 8:
            servEjercicio.modificarEjercicio();
            break;
        case 0:
            break;
        default:
            cout << "  Pifiaste rey, volvea probar" << endl;
            system("pause");
            break;
        }
    }
    while(opcion != 0);
}

void MenuEntrenador::verReclamos()
{
    int opcion;
    ServicioReclamo reclamo;

    do
    {
        system("cls");
        cout << "      +-----------------------------------+" << endl;
        cout << "      |              RECLAMOS             |" << endl;
        cout << "      +-----------------------------------+" << endl;
        cout << "      |   [1]  REALIZAR UN RECLAMO        |" << endl;
        cout << "      |   [2]  VER ESTADO DE RECLAMOS     |" << endl;
        cout << "      +-----------------------------------+" << endl;
        cout << "      |   [0]  VOLVER ATRAS               |" << endl;
        cout << "      +-----------------------------------+" << endl;
        cout << endl;
        cout << " Elegiste: ";
        cin >> opcion;


        system("cls");
        switch(opcion)
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
            cout << "  Pifiaste rey, volvea probar" << endl;
            system("pause");
            break;
        }
    }
    while(opcion != 0);
}
