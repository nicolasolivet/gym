#include <iostream>
#include <cstring>
#include <iomanip>


#include "ServicioEmpleado.h"
#include "ServicioSocio.h"
#include "ServicioActividad.h"

using namespace std;


ServicioEmpleado::ServicioEmpleado()
{
    _archivoEmpleado = GestionArchivoEmpleados("archivoEmpleados.dat");
}

void ServicioEmpleado::verEmpleados(int idRol)
{
    system("cls");
    Empleado empleado;
    ServicioActividad actividad;
    int contador = 0;

    int cantidad = _archivoEmpleado.cantidadRegistrosEmpleados();

    if(idRol == 0)
    {
        cout << "+----------------------------------+" << endl;
        cout << "|             GERENTES             |" << endl;
        cout << "+----------------------------------+" << endl;
    }
    else
    {
        cout << "+----------------------------------+" << endl;
        cout << "|           ENTRENADORES           |" << endl;
        cout << "+----------------------------------+" << endl;
    }

    for(int i=0; i<cantidad; i++)
    {
        empleado = _archivoEmpleado.leerRegistroEmpleado(i);

        if(empleado.getIdRol() == idRol && empleado.getEstado())
        {

            cout << left << setw(19) << " Nombre: " << empleado.getNombre() << endl;
            cout << setw(19) << " Apellido: " << empleado.getApellido() << endl;
            cout << setw(19) << " Fecha de ingreso: " << empleado.getFechaDeIngreso().toString() << endl;
            cout << setw(19) << " Legajo: " << empleado.getLegajo() << endl;

            if (empleado.getIdActividadPrincipal() == 0)
            {
                cout << setw(18) << " Actividad: " << "Gerente" << endl;
            }
            else
            {
                actividad.buscarActividad(empleado.getIdActividadPrincipal());
            }

            cout << "+----------------------------------+" << endl;
            contador++;
            if(contador%5 == 0)
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


void ServicioEmpleado::agregarEmpleado(int idRol)
{
    string nombre, apellido, pass1, pass2;
    int dni, idUsuario, opcion;
    int dia, mes, anio;
    Fecha fechaIngreso;
    bool estado = true;
    int legajo, idTurno, idActividadPrincipal = 0;
    bool semana[7] = {};

    ServicioActividad actividad;
    ServicioEmpleado servicio;

    system("cls");
    cout << "+----------------------------+" << endl;
    cout << "|  INGRESO DATOS PERSONALES: |" << endl;
    cout << "+----------------------------+" << endl;
    cout << endl;
    cout << " DNI: ";
    cin >> dni;

    if(servicio.comprobarDniEmpleado(dni) != -1)
    {
        cout << endl;
        cout << " DNI ya ingresado, ID #" << servicio.comprobarDniEmpleado(dni) << endl;
        cout << " Compruebe su estado en apartado <BUSCAR> " << endl;
        cout << endl;
        system("pause");
        return;
    }
    cout << " Nombre: ";
    cin.ignore();
    getline(cin, nombre);
    cout << " Apellido: ";
    getline(cin, apellido);

    system("cls");
    cout << "+-----------------------+" << endl;
    cout << "|  FECHA DE NACIMIENTO: |" << endl;
    cout << "+-----------------------+" << endl;
    cout << endl;
    cout << " Dia: ";
    cin >> dia;
    cout << " Mes: ";
    cin >> mes;
    cout << " Anio: ";
    cin >> anio;

    system("cls");
    cout << "+-------------------------+" << endl;
    cout << "|      TURNO LABORAL:     |" << endl;
    cout << "+-------------------------+" << endl;
    cout << endl;
    cout << " 0 - 8hs a 13hs " << endl;
    cout << " 1 - 13hs a 18hs " << endl;
    cout << " 2 - 18hs a 23hs " << endl;
    cout << endl;
    cout << " Su Seleccion: ";
    cin >> idTurno;

    do
    {
        system("cls");
        cout << "+-----------------------+" << endl;
        cout << "|      CONTRASENIA:     |" << endl;
        cout << "+-----------------------+" << endl;
        cout << endl;
        cout << " Ingrese contrasenia: ";
        cin >> pass1;
        cout << " Repita contrasenia: ";
        cin >> pass2;

        if( strcmp(pass1.c_str(), pass2.c_str()) != 0)
        {
            cout << " Contrasenias no coinciden, vuelva a intentar." << endl;
            system("pause");
        }

    }
    while(strcmp(pass1.c_str(), pass2.c_str()) != 0);


    if(idRol == 1)
    {
        system("cls");
        cout << "+---------------------------------+" << endl;
        cout << "|            ACTIVIDAD            |" << endl;
        cout << "+---------------------------------+" << endl;
        cout << endl;
        cout << " 1 - Ver Actividades disponibles " << endl;
        cout << " 2 - Agregar nueva Actividad " << endl;
        cout << endl;
        cout << " Su seleccion: ";
        cin >> opcion;
        if(opcion == 1)
        {
            actividad.listarActividades();
            cout << endl;
            cout << " Ingrese ID Actividad principal: ";
            cin >> idActividadPrincipal;
        }
        else
        {
            idActividadPrincipal = actividad.agregarActividad();
        }
    }

    Fecha fechaNacimiento(dia, mes, anio);
    idUsuario = servicio.obternerUltimoId();
    legajo = servicio.obternerUltimoLegajo();

    Empleado empleado(nombre, apellido, dni, idUsuario, fechaNacimiento, fechaIngreso, pass1, estado, idRol, legajo, idTurno, idActividadPrincipal, semana);


    system("cls");
    if(_archivoEmpleado.guardarEmpleado(empleado))
    {
        cout << " Nombre: " << nombre << ", apellido: " << apellido << endl;
        cout << " Fecha de nacimiento: " << fechaNacimiento.toString() << endl;
        cout << " ID# " << idUsuario << ", legajo " << legajo << " agregado exitosamente." << endl;
    }
    else
    {
        cout << "Error de ingreso" << endl;
    }

    system("pause");

}

void ServicioEmpleado::restaurarUnEmpleado(int idRol)
{
    int idEmpleado;
    bool opcion;
    Empleado empleado;

    system("cls");
    cout << "Ingrese ID     : #";
    cin >> idEmpleado;

    int pos = _archivoEmpleado.buscarEmpleado(idEmpleado);

    if(pos != -1)
    {
        empleado = _archivoEmpleado.leerRegistroEmpleado(pos);

        if(empleado.getIdRol() == idRol)
        {
            if(!empleado.getEstado())
            {
                cout << " Nombre        : " << empleado.getNombre() << endl;
                cout << " Apellido      : " << empleado.getApellido() << endl;
                cout << " DNI           : " << empleado.getDni() << endl;
                cout << " Fecha Ingreso : " << empleado.getFechaDeIngreso().toString() << endl;
                cout << endl;
                cout << " Desea volver a activar al empleado? 1 - SI | 0 - NO " << endl;
                cout << " Su seleccion: ";
                cin >> opcion;

                empleado.setEstado(opcion);

                if(_archivoEmpleado.guardarEmpleado(empleado, pos))
                {
                    system("cls");
                    cout << " ID # " << idEmpleado << endl;
                    cout << " Estado Actualizado a ACTIVO " << endl;
                }
            }
            else
            {
                cout << " El estado es ACTIVO." << endl;
            }
        }
        else
        {
            system("cls");
            if(idRol == 0)
            {
                cout << " ID corresponde a un Entrenador, dirijase al gestor correspondiente...." << endl;
            }
            else
            {
                cout << " ID corresponde a un Gerente, dirijase al gestor correspondiente...." << endl;
            }
        }
    }
    system("pause");

}


void ServicioEmpleado::modificarEmpleado(int idRol)
{
    string nombre, apellido;
    int dia, mes, anio;
    bool estado = true;
    Fecha fechaNacimiento;

    int idEmpleado, opcion, eliminar;
    Empleado empleado;

    system("cls");
    cout << " Ingrese ID: ";
    cin >> idEmpleado;

    int pos = _archivoEmpleado.buscarEmpleado(idEmpleado);

    if(pos != -1)
    {
        empleado = _archivoEmpleado.leerRegistroEmpleado(pos);

        if(empleado.getIdRol() == idRol)
        {
            system("cls");
            cout << "+------------------------------------+" << endl;
            cout << "| 1 - Modificar Datos Personales     |" << endl;
            cout << "+------------------------------------+" << endl;
            cout << "| 2 - Modificar Fecha de Nacimiento  |" << endl;
            cout << "+------------------------------------+" << endl;
            cout << "| 3 - Modificar Estado/Eliminar      |" << endl;
            cout << "+------------------------------------+" << endl;
            cout << endl;
            cout << " Su seleccion: ";
            cin >> opcion;

            system("cls");
            switch(opcion)
            {
            case 1:
                cout << " Nombre: " << empleado.getNombre() << ", Apellido: " << empleado.getApellido()<< endl;
                cout << endl;
                cout << " Ingrese Nombre: ";
                cin.ignore();
                getline(cin, nombre);
                cout << " Ingrese Apellido: ";
                getline(cin, apellido);

                empleado.setNombre(nombre);
                empleado.setApellido(apellido);

                break;
            case 2:
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
            case 3:

                if(empleado.getEstado())
                {
                    cout << " Estado Actual: ACTIVO" << endl;
                    cout << endl;
                    cout << " Desea eliminar empleado: 1 - Si | 0 - NO" << endl;
                    cout << " Su seleccion: ";
                    cin >> eliminar;
                    if(eliminar == 1)
                    {
                        estado = false;
                        empleado.setEstado(estado);
                    }
                }

                break;
            default:
                cout << " Opcion Incorrecta..." << endl;
                break;
            }

            cout << " Confirmar Cambios?: 1 - Si | 0 - NO" << endl;
            cin >> opcion;

            if(opcion == 1 && _archivoEmpleado.guardarEmpleado(empleado, pos))
            {
                cout << " Datos Actualizados correctamente" << endl;
            }

        }
        else
        {
            system("cls");
            if(idRol == 0)
            {
                cout << " ID corresponde a un Entrenador, dirijase al gestor correspondiente..." << endl;
            }
            else
            {
                cout << " ID corresponde a un Gerente, dirijase al gestor correspondiente..." << endl;
            }
        }
    }

    system("pause");
}

void ServicioEmpleado::asignarHorarios()
{
    Empleado empleado;
    int idUsuario, opcion;
    bool diaSemana[7] = {}, agregar;
    string horarios;


    system("cls");
    cout << "+------------------------------------------+" << endl;
    cout << "|            ASIGNAR HORARIOS              |" << endl;
    cout << "+------------------------------------------+" << endl;
    cout << endl;
    cout << " Ingrese ID del entrenador: ";
    cin >> idUsuario;

    int pos = _archivoEmpleado.buscarEmpleado(idUsuario);

    if(pos != -1)
    {
        empleado = _archivoEmpleado.leerRegistroEmpleado(pos);
    }
    else
    {
        cout << " ID incorrecto..." << endl;
        system("pause");
        return;
    }

    switch(empleado.getIdTurno())
    {
    case 0:
        horarios = "08hs a 13hs";
        break;
    case 1:
        horarios = "13hs a 18hs";
        break;
    case 2:
        horarios = "18hs a 23hs";
        break;
    }

    system("cls");
    cout << "+------------------------------------------+" << endl;
    cout << "|            ASIGNAR HORARIOS              |" << endl;
    cout << "+------------------------------------------+" << endl;
    cout << endl;

    for(int i=0; i<7; i++)
    {
        if(!diaSemana[i])
        {
            switch(i)
            {
            case 0:
                cout << " Lunes de " << horarios << endl;
                break;
            case 1:
                cout << " Martes de " << horarios << endl;
                break;
            case 2:
                cout << " Miercoles de " << horarios << endl;
                break;
            case 3:
                cout << " Jueves de " << horarios << endl;
                break;
            case 4:
                cout << " Viernes de " << horarios << endl;
                break;
            case 5:
                cout << " Sabado de " << horarios << endl;
                break;
            case 6:
                cout << " Domingo de " << horarios << endl;
                break;
            }

            cout << " Agregar? 1 - SI || 0 - NO: ";
            cin >> agregar;
            cout << "+------------------------------------------+" << endl;
            diaSemana[i] = agregar;
        }
    }

    cout << endl;
    cout << " Confirmar Asignacion 1 - SI | 0 - NO: ";
    cin >> opcion;

    if(opcion == 1)
    {
        empleado.setDiaSem(diaSemana);
        if(_archivoEmpleado.guardarEmpleado(empleado, pos))
        {
            system("cls");
            cout << " Cambios realizados con exito" << endl;
        }
    }

    system("pause");

}

void ServicioEmpleado::verHorariosAsignados(int idUsuario)
{
    Empleado empleado;
    bool *diaSemana;
    string horarios;

    int pos = _archivoEmpleado.buscarEmpleado(idUsuario);

    if(pos != -1)
    {
        empleado = _archivoEmpleado.leerRegistroEmpleado(pos);

        switch(empleado.getIdTurno())
        {
        case 0:
            horarios = "08hs a 13hs";
            break;
        case 1:
            horarios = "13hs a 18hs";
            break;
        case 2:
            horarios = "18hs a 23hs";
            break;
        }

        system("cls");
        cout << "+-------------------------------+" << endl;
        cout << "|     HORARIOS DE LA SEMANA     |" << endl;
        cout << "+-------------------------------+" << endl;
        for(int i=0; i<7; i++)
        {
            diaSemana = empleado.getDiaSem();
            if(diaSemana[i])
            {
                switch(i)
                {
                case 0:
                    cout << " Lunes     : " << horarios << endl;
                    break;
                case 1:
                    cout << " Martes    : " << horarios << endl;
                    break;
                case 2:
                    cout << " Miercoles : " << horarios << endl;
                    break;
                case 3:
                    cout << " Jueves    : " << horarios << endl;
                    break;
                case 4:
                    cout << " Viernes   : " << horarios << endl;
                    break;
                case 5:
                    cout << " Sabado    : " << horarios << endl;
                    break;
                case 6:
                    cout << " Domingo   : " << horarios << endl;
                    break;
                }
                cout << "+-------------------------------+" << endl;
            }
        }
        cout << "+-------------------------------+" << endl;
        cout << "|            FRANCO/S            |" << endl;
        cout << "+-------------------------------+" << endl;

        for(int j=0; j<7; j++)
        {
            diaSemana = empleado.getDiaSem();
            if(!diaSemana[j])
            {
                switch(j)
                {
                case 0:
                    cout << "           Lunes  " << endl;
                    break;
                case 1:
                    cout << "           Martes  " << endl;
                    break;
                case 2:
                    cout << "           Miercoles " << endl;
                    break;
                case 3:
                    cout << "           Jueves " << endl;
                    break;
                case 4:
                    cout << "           Viernes " << endl;
                    break;
                case 5:
                    cout << "           Sabado " << endl;
                    break;
                case 6:
                    cout << "           Domingo " << endl;
                    break;
                }
                cout << "+-------------------------------+" << endl;
            }
        }

    }
    system("pause");

}

int ServicioEmpleado::obternerUltimoIdEmpleado()
{
    Empleado empleado;

    int cantidad = _archivoEmpleado.cantidadRegistrosEmpleados();

    if(cantidad > 0)
    {
        empleado = _archivoEmpleado.leerRegistroEmpleado(cantidad - 1);
        return empleado.getIdUsuario();
    }

    return -1;
}

int ServicioEmpleado::obternerUltimoId()
{
    ServicioSocio socio;

    return socio.autoGenerarId();
}

int ServicioEmpleado::obternerUltimoLegajo()
{
    Empleado empleado;

    int cantidad = _archivoEmpleado.cantidadRegistrosEmpleados();

    if(cantidad > 0)
    {
        empleado = _archivoEmpleado.leerRegistroEmpleado(cantidad - 1);
        return empleado.getLegajo()+1;
    }

    return -1;
}


void ServicioEmpleado::modificarContrasenia(int idEmpleado)
{
    system("cls");
    string pass, pass2;
    Empleado empleado;
    int intentos = 0;


    int posicion = _archivoEmpleado.buscarEmpleado(idEmpleado);

    empleado = _archivoEmpleado.leerRegistroEmpleado(posicion);

    cout << "+---------------------------------+" << endl;
    cout << "|      MODIFICAR CONTRASENIA      |" << endl;
    cout << "+---------------------------------+" << endl;
    cout << endl;
    cout << " Ingrese contrasenia actual: ";
    cin.ignore();
    getline(cin, pass);

    if(!strcmp(empleado.getContrasenia().c_str(), pass.c_str()))
    {
        do
        {
            system("cls");
            cout << endl;
            cout << " Ingrese la nueva contrasenia: " ;
            getline(cin, pass2);
            cout << " Repita la nueva contrasenia: ";
            getline(cin, pass);

            if(!strcmp(pass.c_str(), pass2.c_str()))
            {
                empleado.setContrasenia(pass);
                if(_archivoEmpleado.guardarEmpleado(empleado, posicion))
                {
                    cout << endl;
                    cout << " Cambio realizado con exito" << endl;
                    system("pause");
                    return;
                }
            }
            else
            {
                cout << endl;
                cout << " Las contrasenias no coinciden, intente nuevamente" << endl;
                intentos++;
                system("pause");
            }

        }
        while(intentos < 3);

    }
    else
    {
        cout << endl;
        cout << " Contrasenia ingresada es incorrecta" << endl;
        system("pause");
        return;
    }

}

void ServicioEmpleado::buscarUnEmpleado(int idRol)
{
    int idUsuario;
    Empleado empleado;
    ServicioActividad actividad;

    system("cls");
    cout << " Ingrese ID: #";
    cin >> idUsuario;

    int pos = _archivoEmpleado.buscarEmpleado(idUsuario);

    if(pos != -1)
    {
        empleado = _archivoEmpleado.leerRegistroEmpleado(pos);

        if(empleado.getIdRol() == idRol)
        {
            cout << "+----------------------------------------------------+" << endl;
            cout << "|                 BUSCAR UN EMPLEADO                 |" << endl;
            cout << "+----------------------------------------------------+" << endl;
            cout << endl;
            cout << " Nombre          : " << empleado.getNombre() << endl;
            cout << " Apellido        : " << empleado.getApellido() << endl;
            cout << " Fecha Ingreso   : " << empleado.getFechaDeIngreso().toString() << endl;
            cout << " Legajo          : " << empleado.getLegajo() << endl;
            if(empleado.getIdRol() == 0)
            {
                cout << " Actividad       : Gerente" << endl;
            }
            else
            {
                actividad.buscarActividad(empleado.getIdActividadPrincipal());
            }

            cout << " Estado          : ";
            if(empleado.getEstado())
            {
                cout << " ACTIVO " << endl;
            }
            else
            {
                cout << " DADO DE BAJA " << endl;
            }
        }
        else
        {
            if(idRol == 0)
            {
                cout << " Id ingresado corresponde a un Entrenador..." << endl;
            }
            else
            {
                cout << " Id ingresado corresponde a un Gerente..." << endl;
            }
        }
        cout << "+----------------------------------------------------+" << endl;

    }
    else
    {
        cout << " ID no encontrado..." << endl;
    }

    system("pause");
}

int ServicioEmpleado::elegirEntrenador()
{
    int *vectPosiciones;
    int *vectorID;
    int opcion;
    Empleado entrenador;
    ServicioActividad actividad;

    int cantidad = _archivoEmpleado.cantidadRegistrosEmpleados();
    int cantEntrenadores = _archivoEmpleado.cantidadRegistrosEmpleadosPorEstado(cantidad, true, 1);

    vectPosiciones = new int[cantEntrenadores];
    vectorID = new int[cantEntrenadores];

    if(vectPosiciones == nullptr || vectorID == nullptr)
    {
        return -1;
    }

    *vectPosiciones = _archivoEmpleado.leerRegistrosEmpleadosActivos(cantidad, vectPosiciones, cantEntrenadores, 1);

    cout << "+--------------------------------+" << endl;
    cout << "|          ENTRENADORES          |"  << endl;
    cout << "+--------------------------------+" << endl;

    for(int i=0; i<cantEntrenadores; i++)
    {
        entrenador = _archivoEmpleado.leerRegistroEmpleado(vectPosiciones[i]);


        cout << " " << i+1 << ". Nombre: " << entrenador.getNombre() << endl;
        cout << "    Apellido: " << entrenador.getApellido() << endl;
        actividad.buscarActividad(entrenador.getIdActividadPrincipal());

        vectorID[i] = entrenador.getIdUsuario();
        cout << "+--------------------------------+" << endl;
    }

    cout << endl;
    cout << " Seleccione un entrenador: (1 a " << cantEntrenadores << "): ";
    cin >> opcion;

    int idSeleccionado = vectorID[opcion-1];

    delete []vectPosiciones;
    delete []vectorID;

    return idSeleccionado;

}

int ServicioEmpleado::comprobarDniEmpleado(int dni)
{
    int cantidad = _archivoEmpleado.cantidadRegistrosEmpleados();
    Empleado empleado;

    if(cantidad != -1)
    {
        for(int i=0; i<cantidad; i++)
        {
            empleado = _archivoEmpleado.leerRegistroEmpleado(i);
            if(empleado.getDni() == dni)
            {
                return empleado.getIdUsuario();
            }
        }
    }

    return -1;
}

void ServicioEmpleado::verSociosAsignados(int idEntrenador)
{
    system("cls");
    string horarios;
    ServicioSocio socio;
    Empleado entrenador;

    int pos = _archivoEmpleado.buscarEmpleado(idEntrenador);
    entrenador = _archivoEmpleado.leerRegistroEmpleado(pos);

    switch(entrenador.getIdTurno())
    {
    case 0:
        horarios = "08hs a 13hs";
        break;
    case 1:
        horarios = "13hs a 18hs";
        break;
    case 2:
        horarios = "18hs a 23hs";
        break;
    }

    cout << "+-----------------------------------------------------------------------------+" << endl;
    cout << "|                        ENTRENADOR: " << entrenador.getNombre() << " " << entrenador.getApellido() << endl;
    cout << "+-----------------------------------------------------------------------------+" << endl;
    cout << "|                        HORARIO: " << horarios << "                                 |" << endl;
    cout << "+-----------------------------------------------------------------------------+" << endl;
    socio.mostrarSociosPorEntrenador(idEntrenador);
    cout << "+-----------------------------------------------------------------------------+" << endl;

    system("pause");
}

void ServicioEmpleado::mostrarHorariosDeEntrenadores()
{
    system("cls");
    int indice = 1, espacios = 25;
    string horarios;
    char nombreCompleto[30];
    Empleado entrenador;
    ServicioActividad actividad;

    int cantidad = _archivoEmpleado.cantidadRegistrosEmpleados();

    cout << "+----------------------------------------------------------------------------+" << endl;
    cout << "|                           HORARIOS DE ENTREENADORES                        |" << endl;
    cout << "+----------------------------------------------------------------------------+" << endl;

    for(int i=0; i<cantidad; i++)
    {
        entrenador = _archivoEmpleado.leerRegistroEmpleado(i);
        if(entrenador.getIdRol() == 1 && entrenador.getEstado())
        {
            switch(entrenador.getIdTurno())
            {
            case 0:
                horarios = "08hs a 13hs";
                break;
            case 1:
                horarios = "13hs a 18hs";
                break;
            case 2:
                horarios = "18hs a 23hs";
                break;
            }

            strcpy(nombreCompleto, entrenador.getNombre().c_str());
            ///strcat dentro de la libreria cstring añade el contenido de una cadena a otra.
            strcat(nombreCompleto, " ");
            strcat(nombreCompleto, entrenador.getApellido().c_str());

            ///strlen dentro de la libreria cstring devuelve la cantidad de caracteres de una cadena.
            espacios = 25 - strlen(nombreCompleto);

            if (espacios < 0)
            {
                espacios = 0;
            }

            cout << " " << indice << ". " << nombreCompleto;

            for (int i = 0; i<espacios; i++)
            {
                cout << " ";
            }

            cout << "| Horario: " << horarios << " | ";
            actividad.buscarActividad(entrenador.getIdActividadPrincipal());

            indice++;
        }
    }
    cout << "+----------------------------------------------------------------------------+" << endl;
    cout << endl;
    system("pause");
}

void ServicioEmpleado::listarEmpleadoOrdenados(int idRol, int lista)
{
    system("cls");
    Empleado *empleado;
    int *posEmpleado;
    int indice = 1;

    int cantidad = _archivoEmpleado.cantidadRegistrosEmpleados();
    int cantActivos = _archivoEmpleado.cantidadRegistrosEmpleadosPorEstado(cantidad, true, idRol);

    empleado = new Empleado[cantActivos];
    posEmpleado = new int[cantActivos];

    if(empleado == nullptr || posEmpleado == nullptr)
    {
        return;
    }

    *posEmpleado = _archivoEmpleado.leerRegistrosEmpleadosActivos(cantidad, posEmpleado, cantActivos, idRol);

    for(int i=0; i<cantActivos; i++)
    {
        empleado[i] = _archivoEmpleado.leerRegistroEmpleado(posEmpleado[i]);
    }

    if(lista == 0)
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




    for(int i=0; i<cantActivos; i++)
    {
        cout << " " << indice << ". DNI: " << empleado[i].getDni() << ", " << empleado[i].getApellido() << ", " << empleado[i].getNombre() << "   ID #" << empleado[i].getIdUsuario() << endl;
        cout << "+------------------------------------------------------+" << endl;
        indice++;
    }

    cout << endl;

    delete []empleado;
    delete []posEmpleado;

    system("pause");
}

void ServicioEmpleado::ordenarPorApellido(Empleado empleado[], int tam)
{
    Empleado aux;

    ///Ordenamiento por intercambio o SWAP, similar al burbujeo, sacado del libro pag 428
    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(strcmp(empleado[i].getApellido().c_str(), empleado[j].getApellido().c_str()) > 0)
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

    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(empleado[i].getDni() > empleado[j].getDni())
            {
                aux = empleado[i];
                empleado[i] = empleado[j];
                empleado[j] = aux;
            }
        }
    }
}
