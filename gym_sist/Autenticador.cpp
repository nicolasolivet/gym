//#include <iostream>
//#include <cstring>
//#include "Autenticador.h"
//#include "Usuario.h"
//#include "ArchivoEmpleados.h"
//#include "ArchivoSocios.h"
//
//using namespace std;
//
//UsuarioAutenticado Autenticador::autenticar()
//{
//    Usuario usuario;
//    int idUsuario;
//    string pass;
//    char _pass[50];
//    int contador = 0;
//
//    do
//    {
//        system("cls");
//
//        cout << "+--------------------------------------+" << endl;
//        cout << "|         Bienvenido a MetalGYM        |" << endl;
//        cout << "|      El Camino a tu mejor version    |" << endl;
//        cout << "+--------------------------------------+" << endl;
//        cout << endl;
//
//        cout << "       Ingrese sus datos de acceso     " << endl;
//        cout << endl;
//
//        cout << " INGRESE ID: ";
//        cin >> idUsuario;
//
//        cout << " INGRESE PASS: ";
//        cin >> pass;
//
//        cout << endl;
//        cout << "+--------------------------------------+" << endl;
//        cout << "|        Ingresando al sistema...      |" << endl;
//        cout << "+--------------------------------------+" << endl;
//        system("pause");
//
//        strcpy(_pass, pass.c_str());
//
//        usuario = comprobarUsuario(idUsuario, _pass);
//        contador++;
//    }
//    while(contador < 3 && usuario.getIdUsuario() != idUsuario);
//
//    if(contador == 3)
//    {
//        system("cls");
//        cout << "+--------------------------------------+" << endl;
//        cout << "|    Limites de intentos alcanzado     |" << endl;
//        cout << "|  Intente nuevamente en unos minutos  |" << endl;
//        cout << "+--------------------------------------+" << endl;
//    }
//
//    UsuarioAutenticado authUs(
//        usuario.getIdUsuario(),
//        usuario.getNombre(),
//        usuario.getApellido(),
//        usuario.getDni(),
//        usuario.getFechaNacimiento(),
//        usuario.getFechaIngreso(),
//        usuario.getIdRol(),
//        usuario.getEstado()
//    );
//    return authUs;
//}
//
//Usuario Autenticador::comprobarUsuario(const int idUsuario, const char* pass)
//{
//
//    // abrir archivo empleados leer / buscar / si existe devolver
//    // abrir archivo soccio leer / buscar / si existe devolver
//
//    ArchivoEmpleados empleados("archivoEmpleados.dat");
//    int posEmpleado = empleados.buscarEmpleado(idUsuario);
//    if (posEmpleado != -1)
//    {
//        Empleado emp = empleados.leerRegistroEmpleado(posEmpleado);
//        // strcmp // si 0 es igual / si < 0 str1 < str2 / si > 0 str1 > str2
//        if (strcmp(emp.getContrasenia().c_str(), pass) == 0)
//        {
//            return emp;
//        }
//    }
//
//    ArchivoSocios socios("archivoSocios.dat");
//    int posSocio = socios.buscarReg(idUsuario);
//    if (posSocio != -1)
//    {
//        Socio soc = socios.leerReg(posSocio);
//        // strcmp // si 0 es igual / si < 0 str1 < str2 / si > 0 str1 > str2
//        if (strcmp(soc.getContrasenia().c_str(), pass) == 0)
//        {
//            return soc;
//        }
//    }
//
//    system("cls");
//    cout << "+--------------------------------------+" << endl;
//    cout << "|   Contrasenia o usuario incorrectos  |" << endl;
//    cout << "|          Pruebe nuevamente           |" << endl;
//    cout << "+--------------------------------------+" << endl;
//    system("pause");
//
//    return Usuario();
//}
