#include <iostream>
#include <cstring>
#include "Autenticador.h"
#include "Usuario.h"
#include "ArchivoEmpleados.h"
#include "ArchivoSocios.h"

using namespace std;

UsuarioAutenticado Autenticador::autenticar()
{
    Usuario usuario;
    int idUsuario;
    string passs;
    char pass[50];
    int contador = 0;

    do
    {
        system("cls");

        cout << "   +  ---------------------------------------------------------------------  +" << endl;
        cout << "   |                     Bienvenido al 'GIMNASIO DEL D1EG0'                  |" << endl;
        cout << "   +  ---------------------------------------------------------------------  +" << endl;
        cout << endl;

        cout << " INGRESE ID: ";
        cin >> idUsuario;

        cout << " INGRESE PASS: ";
        cin >> passs;

        strcpy(pass, passs.c_str());

        usuario = comprobarUsuario(idUsuario, pass);
        contador++;
    
    }while(contador < 3 && usuario.getIdUsuario() != idUsuario);

    if(contador == 3)
    {
        system("cls");
        cout << "   + ----------------------------------------------------------------------------------------- +" << endl;
        cout << "   |                         Alcanzaste el limite de intentos, flaquito                        |" << endl;
        cout << "   |                 CUENTA BLOQUEADA. Nah mentira, intenta de nuevo en un rato                |" << endl;
        cout << "   + ----------------------------------------------------------------------------------------- +" << endl;
    }

    UsuarioAutenticado autenticado
    (
        usuario.getIdUsuario(),
        usuario.getNombre(),
        usuario.getApellido(),
        usuario.getDni(),
        usuario.getFechaNacimiento(),
        usuario.getFechaIngreso(),
        usuario.getIdRol(),
        usuario.getEstado()
    );
    return autenticado;
}

Usuario Autenticador::comprobarUsuario(const int idUsuario, const char* pass)
{
    // abrir archivo empleados leer / buscar / si existe devolver
    // abrir archivo socio leer / buscar / si existe devolver

    ArchivoEmpleados empleados("archivoEmpleados.dat");
    int posEmp = empleados.buscarReg(idUsuario);
    if (posEmp != -1)
    {
        Empleado emp = empleados.leerReg(posEmp);
        // strcmp // si 0 es igual / si < 0 str1 < str2 / si > 0 str1 > str2
        if (strcmp(emp.getContrasenia().c_str(), pass) == 0)
        {
            return emp;
        }
    }

    ArchivoSocios socios("archivoSocios.dat");
    int posSocio = socios.buscarReg(idUsuario);
    if (posSocio != -1)
    {
        Socio soc = socios.leerReg(posSocio);
        // strcmp // si 0 es igual / si < 0 str1 < str2 / si > 0 str1 > str2
        if (strcmp(soc.getContrasenia().c_str(), pass) == 0)
        {
            return soc;
        }
    }

    system("cls");
    cout << "           +--------------------------------------+" << endl;
    cout << "           |   Contrasenia o usuario incorrecto   |" << endl;
    cout << "           |          Volve a intentar            |" << endl;
    cout << "           +--------------------------------------+" << endl;
    system("pause");

    return Usuario();
}
