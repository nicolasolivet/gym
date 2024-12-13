#include <iostream>
#include <cstring>
#include "ServicioAsistencia.h"
#include "Fecha.h"
#include "Asistencia.h"

using namespace std;

ServicioAsistencia::ServicioAsistencia()
{
    _archivoAsistencia = ArchivoAsistencia("archivoAsistencia.dat");
}

void ServicioAsistencia::registrarAsistencia(int idSocio)
{
    Fecha hoy = Fecha();
    if(validarRegistroDeAsistencia(idSocio, hoy)){
        Asistencia reg = Asistencia(idSocio, hoy);
        _archivoAsistencia.guardarAsistencia(reg);

        cout << "+--------------------------------------+" << endl;
        cout << "| Asistencia registrada correctamente! |"<< endl;
        cout << "+--------------------------------------+" << endl;

    } else {
        cout << "+----------------------------------------------------------+" << endl;
        cout << "| Usted ya registro su asistencia para el dia de la fecha  |" << endl;
        cout << "+----------------------------------------------------------+" << endl;
    }

}

bool ServicioAsistencia::validarRegistroDeAsistencia(int idSocio, Fecha fechaActual)
{
    system("cls");
    Asistencia reg;
    int cant = _archivoAsistencia.cantidadRegistrosAsistencias();
    for(int i =0; i< cant; i++){
        reg = _archivoAsistencia.leerRegistroAsistencia(i);
        if(fechaActual.compararSiFechasSonIguales(reg.getFecha()) && idSocio == reg.getIdSocio()){
            return false;
        }
    }
    return true;
}

void ServicioAsistencia::verAsistenciaPorSocio(int idSocio)
{
    system("cls");
    Asistencia reg;
    int cant = _archivoAsistencia.cantidadRegistrosAsistencias();
    cout << "Fecha " << endl;
    cout << string(78, '-') << endl;
    for(int i =0; i< cant; i++){
        reg = _archivoAsistencia.leerRegistroAsistencia(i);
        if(idSocio == reg.getIdSocio()){
            cout << reg.getFecha().toString() << endl;
        }
    }
}

void ServicioAsistencia::verTodasLasAsistencia(){
    system("cls");
    Asistencia reg;
    int cant = _archivoAsistencia.cantidadRegistrosAsistencias();
    cout << string(30, '-') << endl;
    cout << "| Fecha \t|Socio ID \t|" << endl;
    cout << string(30, '-') << endl;
    for(int i =0; i< cant; i++){
        reg = _archivoAsistencia.leerRegistroAsistencia(i);
        cout << reg.getFecha().toString() << "\t" << reg.getIdSocio() << " \t|"<<endl;
    }
}
void ServicioAsistencia::verAsistenciasEnPeriodo(int mes, int anio){
    system("cls");
    Asistencia reg;
    int cant = _archivoAsistencia.cantidadRegistrosAsistencias();
    cout << string(30, '-') << endl;
    cout << "| Fecha \t|Socio ID \t|" << endl;
    cout << string(30, '-') << endl;
    for(int i =0; i< cant; i++){
        reg = _archivoAsistencia.leerRegistroAsistencia(i);
        if(reg.getFecha().getMes()==mes && reg.getFecha().getAnio()==anio)
        cout << reg.getFecha().toString() << "\t" << reg.getIdSocio() << " \t|"<<endl;
    }
}
void ServicioAsistencia::verAsistenciasEnAnio(int anio){
    system("cls");
    Asistencia reg;
    int cant = _archivoAsistencia.cantidadRegistrosAsistencias();
    cout << string(30, '-') << endl;
    cout << "| Fecha \t|Socio ID \t|" << endl;
    cout << string(30, '-') << endl;
    for(int i =0; i< cant; i++){
        reg = _archivoAsistencia.leerAsistencia(i);
        if(reg.getFecha().getAnio()==anio)
        cout << reg.getFecha().toString() << "\t" << reg.getIdSocio() << " \t|"<<endl;
    }
}


