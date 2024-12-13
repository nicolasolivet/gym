#include <iostream>
#include <cstring>

#include "ServicioRutina.h"
#include "ServicioEjercicio.h"
#include "Rutina.h"

using namespace std;


ServicioRutina::ServicioRutina()
{
    _archivoRutina = GestionArchivoRutinas("archivoRutinas.dat");
    _archivoDetallesRutina = GestionArchivoDetalleRutinas("archivoDetalleRutinas.dat");
}

void ServicioRutina::verRutinas(int idEntrenador)
{
    system("cls");
    int *vectPos;
    int indice = 1;
    Rutina rutina;

    int cantidad = _archivoRutina.cantidadRegistrosRutinas();
    if(cantidad != -1)
    {
        int tam =  _archivoRutina.cantidadDeRegistrosPorEntrenador(cantidad, idEntrenador);
        vectPos = new int[tam];
        if(vectPos == nullptr)
        {
            return;
        }

        *vectPos = _archivoRutina.leerRegistrosRutinasPorEntrenador(cantidad, vectPos, tam, idEntrenador);

        cout << "+-------------------------------------------------------------------------------------------------------+" << endl;
        cout << "|                                             MIS RUTINAS                                               |" << endl;
        cout << "+-------------------------------------------------------------------------------------------------------+" << endl;

        for(int i=0; i<tam; i++)
        {
            rutina = _archivoRutina.leerRegistroRutina(vectPos[i]);

            cout << " " << indice << ".  Nombre             : " << rutina.getNombreRutina() << endl;
            cout << "     ID                 : #" << rutina.getIdRutina() << endl;
            cout << "     Descripcion        : " << rutina.getDescripcion() << endl;
            cout << "     Frecuencia Semanal : " << rutina.getFrecuenciaSemanal()<< endl;
            cout << "+-------------------------------------------------------------------------------------------------------+" << endl;
            indice++;
        }

        cout << endl;
        delete []vectPos;
    }
    else
    {
        cout << " Sin registros disponibles." << endl;
    }

    system("pause");
}

void ServicioRutina::verDetallesDeRutina()
{
    system("cls");
    int idRutina;

    DetalleRutina detalle;
    ServicioEjercicio ejercicio;

    cout << "+--------------------------------------+" << endl;
    cout << "|          DETALLES DE RUTINA          |" << endl;
    cout << "+--------------------------------------+" << endl;
    cout << endl;

    cout << " Ingrese ID de Rutina: #";
    cin >> idRutina;
    cout << endl;

    int pos = _archivoDetallesRutina.buscarDetalleRutina(idRutina);

    if(pos != -1)
    {
        detalle = _archivoDetallesRutina.leerRegistroDetalleRutina(pos);

        int *idEjercicios = detalle.getIdEjercicios();
        int *repeticiones = detalle.getRepeticiones();
        float *peso = detalle.getPeso();

        for(int i=0; i<10; i++)
        {
            if(idEjercicios[i] != 0)
            {
                ejercicio.verEjercicio(idEjercicios[i]);
                cout << " Repeticiones : " << repeticiones[i] << endl;
                if(peso[i] != 0)
                {
                    cout << " Peso         : " << peso[i] << endl;
                }
                cout << "+--------------------------------------+" << endl;
            }



        }
    }
    else
    {
        cout << "No se encontraron registros con es ID" << endl;
    }

    system("pause");
}

void ServicioRutina::verDetallesDeRutina(int idRutina)
{
    system("cls");

    DetalleRutina detalle;
    ServicioEjercicio ejercicio;

    cout << "+--------------------------------------+" << endl;
    cout << "|          DETALLES DE RUTINA          |" << endl;
    cout << "+--------------------------------------+" << endl;

    int pos = _archivoDetallesRutina.buscarDetalleRutina(idRutina);

    if(pos != -1)
    {
        detalle = _archivoDetallesRutina.leerRegistroDetalleRutina(pos);

        int *idEjercicios = detalle.getIdEjercicios();
        int *repeticiones = detalle.getRepeticiones();
        float *peso = detalle.getPeso();

        for(int i=0; i<10; i++)
        {
            if(idEjercicios[i] != 0)
            {
                ejercicio.verEjercicio(idEjercicios[i]);
                cout << " Repeticiones : " << repeticiones[i] << endl;
                if(peso[i] != 0)
                {
                    cout << " Peso         : " << peso[i] << endl;
                }
                cout << "+--------------------------------------+" << endl;
            }



        }
    }
    else
    {
        cout << " Rutina aun no asignada, comuniquese con su entrenador" << endl;
    }

    system("pause");
}

void ServicioRutina::crearRutina(int idEntrenador)
{
    system("cls");
    string nombre, descripcion;
    int frecuencia, idRutina;

    DetalleRutina detalle;

    cout << "+----------------------------------------------+" << endl;
    cout << "|              CREAR NUEVA RUTINA              |" << endl;
    cout << "+----------------------------------------------+" << endl;
    cout << endl;

    cout << " Nombre de la rutina      : ";
    cin.ignore();
    getline(cin, nombre);
    cout <<  " Descripcion de la rutina : ";
    getline(cin, descripcion);
    cout << " Frecuencia semanal       : ";
    cin >> frecuencia;

    idRutina = obtenerUltimoIdRutina();

    Rutina rutina(idRutina, frecuencia, idEntrenador, nombre, descripcion);

    if(_archivoRutina.guardarRutina(rutina))
    {
        system("cls");
        cout << "+----------------------------------------------+" << endl;
        cout << "|              CREAR NUEVA RUTINA              |" << endl;
        cout << "+----------------------------------------------+" << endl;
        cout << endl;
        cout << " Rutina agregada exitosamente, ID #" << idRutina <<endl;
        cout << endl;
        cout << " Inicio de carga de detalles de la rutina..." << endl;
        cout << endl;
        system("pause");

        detalle = crearDetalleRutina(idRutina);

        if(_archivoDetallesRutina.guardarDetalleRutina(detalle))
        {
            cout << endl;
            cout << " Detalles agregados exitosamente" << endl;
        }
        else
        {
            cout << endl;
            cout << "Error de registro..." << endl;
        }

    }
    else
    {
        cout << "Error de registro..." << endl;
    }

    system("pause");
}

DetalleRutina ServicioRutina::crearDetalleRutina(int idRutina)
{
    int opcion = 1, contador = 0;
    int idEjercicio[10]= {}, repeticiones[10]= {};
    float peso[10]= {};

    while(contador < 10 && opcion != 0)
    {
        system("cls");

        cout << "+----------------------------------------------+" << endl;
        cout << "|              DETALLES DE RUTINA              |" << endl;
        cout << "+----------------------------------------------+" << endl;
        cout << endl;
        cout << " - Ejercicios cargados     : " << contador << endl;
        cout << endl;
        cout << " - Ingrese ID de Ejercicio : ";
        cin >> idEjercicio[contador];
        cout << " - Repeticiones            : ";
        cin >> repeticiones[contador];
        cout << " - Peso (0 si no aplica)   : ";
        cin >> peso[contador];
        cout << endl;
        cout << " Agregar otro ejercicio a la rutina? (Maximo 10) " << endl;
        cout << "                    1-SI | 0-NO " << endl;
        cout << endl;
        cout << " Su eleccion: ";
        cin >> opcion;

        contador++;
    }



    return DetalleRutina(idEjercicio, idRutina, repeticiones, peso);
}

void ServicioRutina::mostrarRutinasPorEntrenador(int idEntrenador)
{
    system("cls");
    Rutina rutina;
    int indice = 1;

    int cantidad = _archivoRutina.cantidadRegistrosRutinas();

    cout << "+----------------------------------------------+" << endl;
    cout << "|              RUTINAS DISPONIBLES             |" << endl;
    cout << "+----------------------------------------------+" << endl;
    cout << endl;

    for(int i=0; i<cantidad; i++)
    {
        rutina = _archivoRutina.leerRegistroRutina(i);
        if(rutina.getIdEntrenador() == idEntrenador)
        {
            cout << " -" << indice << ". Nombre             : " << rutina.getNombreRutina() << endl;
            cout << "     ID                 : #" << rutina.getIdRutina() << endl;
            cout << "     Descripcion        : " << rutina.getDescripcion() << endl;
            cout << "     Frecuencia Semanal : " << rutina.getFrecuenciaSemanal()<< endl;
            cout << "+----------------------------------------------+" << endl;
            indice++;
        }
    }
    system("pause");
}

int ServicioRutina::obtenerUltimoIdRutina()
{
    int cantidad = _archivoRutina.cantidadRegistrosRutinas();

    if(cantidad != -1)
    {
        return cantidad+1;
    }
    else
    {
        return 1;
    }
}

void ServicioRutina::verRutinaAsignada(int idRutina)
{
    system("cls");
    Rutina rutina;

    int pos = _archivoRutina.buscarRutina(idRutina);
    rutina = _archivoRutina.leerRegistroRutina(pos);


    cout << "+-------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|                                           RUTINA ASIGNADA                                             |" << endl;
    cout << "+-------------------------------------------------------------------------------------------------------+" << endl;

    if(pos != -1)
    {
        rutina = _archivoRutina.leerRegistroRutina(pos);

        cout << " Nombre             : " << rutina.getNombreRutina() << endl;
        cout << " ID                 : #" << rutina.getIdRutina() << endl;
        cout << " Descripcion        : " << rutina.getDescripcion() << endl;
        cout << " Frecuencia Semanal : " << rutina.getFrecuenciaSemanal()<< endl;
        cout << "+-------------------------------------------------------------------------------------------------------+" << endl;
    }
    else
    {
        cout << " Rutina no asignada, comuniquese con su entrenador..." << endl;
    }

    cout << endl;
    system("pause");
}

void ServicioRutina::buscarRutina()
{
    int idRutina;
    Rutina rutina;

    system("cls");
    cout << "+-------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|                                            BUSCAR RUTINA                                              |" << endl;
    cout << "+-------------------------------------------------------------------------------------------------------+" << endl;
    cout << endl;
    cout << " Ingrese ID de rutina: ";
    cin >> idRutina;

    int pos = _archivoRutina.buscarRutina(idRutina);

    if(pos != -1)
    {
        rutina = _archivoRutina.leerRegistroRutina(pos);

        cout << " Nombre             : " << rutina.getNombreRutina() << endl;
        cout << " ID                 : #" << rutina.getIdRutina() << endl;
        cout << " Descripcion        : " << rutina.getDescripcion() << endl;
        cout << " Frecuencia Semanal : " << rutina.getFrecuenciaSemanal()<< endl;
        cout << "+-------------------------------------------------------------------------------------------------------+" << endl;
    }
    else
    {
        cout << endl;
        cout << " ID no econtrado" << endl;
    }

    system("pause");
}

int ServicioRutina::elegirRutina(int idEntrenador)
{
    system("cls");
    int indice = 1, opcion;
    int *vectRutinas;
    Rutina rutina;

    int cantidad = _archivoRutina.cantidadRegistrosRutinas();

    if(cantidad == -1)
    {
        cout << "No se encunetran registros de Rutina, comuniquese con soporte" << endl;

        system("pause");
        return -1;
    }

    int cantRutina = _archivoRutina.cantidadDeRegistrosPorEntrenador(cantidad, idEntrenador);

    vectRutinas = new int[cantRutina];
    if(vectRutinas == nullptr)
    {
        cout << "Error inesperado, comuniquese con soporte" << endl;

        system("pause");
        return -1;
    }

    *vectRutinas = _archivoRutina.leerRegistrosRutinasPorEntrenador(cantidad, vectRutinas, cantRutina, idEntrenador);

    cout << "+-------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|                                            ELEGIR RUTINA                                              |" << endl;
    cout << "+-------------------------------------------------------------------------------------------------------+" << endl;

    for(int i=0; i<cantRutina; i++)
    {
        rutina = _archivoRutina.leerRegistroRutina(vectRutinas[i]);

        cout << " -" << indice << ". Nombre             : " << rutina.getNombreRutina() << endl;
        cout << "     Descripcion        : " << rutina.getDescripcion() << endl;
        cout << "     Frecuencia Semanal : " << rutina.getFrecuenciaSemanal()<< endl;
        cout << "+-------------------------------------------------------------------------------------------------------+" << endl;
        indice++;
    }

    cout << endl;
    cout << " Seleccione su rutina (1 a " << cantRutina << "): ";
    cin >> opcion;

    rutina = _archivoRutina.leerRegistroRutina(vectRutinas[opcion-1]);

    int idRutina = rutina.getIdRutina();

    delete []vectRutinas;

    return idRutina;
}

void ServicioRutina::mostrarOpcionesModificarRutina(int idEntrenador)
{
    system("cls");

    int idRutina, opcion;
    Rutina rutina;
    DetalleRutina detalle;

    cout << "Ingrese ID rutina: ";
    cin >> idRutina;

    int pos = _archivoRutina.buscarRutina(idRutina);

    system("cls");
    if(pos != -1)
    {
        rutina = _archivoRutina.leerRegistroRutina(pos);
        detalle = _archivoDetallesRutina.leerRegistroDetalleRutina(pos);

        cout << "+----------------------------------------------+" << endl;
        cout << "|               MODIFICAR RUTINA               |" << endl;
        cout << "+----------------------------------------------+" << endl;
        cout << endl;

        if(rutina.getIdEntrenador() == idEntrenador)
        {
            cout << " Rutina: " << rutina.getNombreRutina() << endl;
            cout << endl;
            cout << " 1 - Cambiar Datos de la Rutina " << endl;
            cout << " 2 - Cambiar Detalles de la Rutina " << endl;
            cout << " 3 - Salir " << endl;
            cout << endl;
            cout << " Su seleccion: ";
            cin >> opcion;

            switch(opcion)
            {
            case 1:
                rutina = modificarRutina(rutina);
                break;
            case 2:
                detalle = modificarDetalleRutina(detalle);
                break;
            case 3:
                return;
                system("pause");
                break;
            default:
                cout << " Opcion incorrecta" << endl;
                return;
                system("pause");
                break;
            }

            cout << endl;
            cout << " Confirmar cambios: 1 - SI | 2 - NO " << endl;
            cout << " Su eleccion: ";
            cin >> opcion;

            if(opcion == 1)
            {
                if(_archivoRutina.guardarRutina(rutina, pos) && _archivoDetallesRutina.guardarDetalleRutina(detalle, pos))
                {
                    system("cls");
                    cout << " Cambios realizados con exito" << endl;
                }
                else
                {
                    cout << " Error inesaperado, consulte con soporte" << endl;
                }
            }

        }
        else
        {
            cout << "La Rutina no puede ser modificada, rutina creada por otro entrenador." << endl;
        }
    }
    else
    {
        cout << "Error, ID no encontrado" << endl;
    }


    system("pause");
}

Rutina ServicioRutina::modificarRutina(Rutina rutina)
{
    string nombre, descripcion;
    int frecuencia;

    cout << endl;
    cout << " Nombre de la rutina      : ";
    cin.ignore();
    getline(cin, nombre);
    cout <<  " Descripcion de la rutina : ";
    getline(cin, descripcion);
    cout << " Frecuencia semanal       : ";
    cin >> frecuencia;

    rutina.setNombreRutina(nombre);
    rutina.setDescripcion(descripcion);
    rutina.setFrecuenciaSemanal(frecuencia);

    return rutina;
}

DetalleRutina ServicioRutina::modificarDetalleRutina(DetalleRutina detalle)
{
    int opcion = 1, contador = 0;
    int idEjercicio[10]= {}, repeticiones[10]= {};
    float peso[10]= {};

    while(contador < 10 && opcion != 0)
    {
        cout << " - Ejercicios cargados     : " << contador << endl;
        cout << endl;
        cout << " - Ingrese ID de Ejercicio : ";
        cin >> idEjercicio[contador];
        cout << " - Repeticiones            : ";
        cin >> repeticiones[contador];
        cout << " - Peso (0 si no aplica)   : ";
        cin >> peso[contador];
        cout << endl;
        cout << " Agregar otro ejercicio a la rutina? (Maximo 10) " << endl;
        cout << "                    1-SI | 0-NO " << endl;
        cout << endl;
        cout << " Su eleccion: ";
        cin >> opcion;

        contador++;
    }

    detalle.setIdEjercicios(idEjercicio);
    detalle.setRepeticiones(repeticiones);
    detalle.setPeso(peso);

    return detalle;
}

void ServicioRutina::mostrarRutinaPorNombre()
{
    system("cls");

    Rutina *vecRutina;
    int indice = 1;

    int cantidad = _archivoRutina.cantidadRegistrosRutinas();

    vecRutina = new Rutina[cantidad];

    if(vecRutina == nullptr)
    {
        return;
    }
    for(int j=0; j<cantidad; j++)
    {
        vecRutina[j] = _archivoRutina.leerRegistroRutina(j);
    }

    ordenarRutinaPorNombre(vecRutina, cantidad);
    cout << "+-------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|                                          RUTINAS ORDENADAS                                            |" << endl;
    cout << "+-------------------------------------------------------------------------------------------------------+" << endl;
    cout << endl;

    for(int i=0; i<cantidad; i++)
    {
        cout << "  " << indice << ". Nombre             : " << vecRutina[i].getNombreRutina() << endl;
            cout << "     ID                 : #" << vecRutina[i].getIdRutina() << endl;
            cout << "     Descripcion        : " << vecRutina[i].getDescripcion() << endl;
            cout << "     Frecuencia Semanal : " << vecRutina[i].getFrecuenciaSemanal()<< endl;
            cout << "+-------------------------------------------------------------------------------------------------------+" << endl;;
            indice++;
    }

    delete []vecRutina;

    system("pause");
}

void ServicioRutina::ordenarRutinaPorNombre(Rutina vectRutina[], int tam)
{
    Rutina aux;

    ///Ordenamiento por intercambio o SWAP, similar al burbujeo, sacado del libro pag 428
    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(strcmp(vectRutina[i].getNombreRutina().c_str(), vectRutina[j].getNombreRutina().c_str()) > 0)
            {
                aux = vectRutina[i];
                vectRutina[i] = vectRutina[j];
                vectRutina[j] = aux;
            }
        }
    }

}
