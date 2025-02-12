#pragma once
#include "ArchivoSocios.h"
#include "ArchivoEmpleados.h"

class ServicioSocio
{
    public:
        ServicioSocio();

        int generarId();
        void agregarSocio();
        void verSociosPorId();
        void verSociosPorApellido();
        void verSociosPorDni();
        void listarSocios(Socio socios[], int cantReg);
        
        Socio buscarSocio(int idUsuario);
        void buscarSocioPorId();
        bool buscarSocioPorDni(int dni);
        
        void modificarSocio();

        void mostrarTurno(int idTurno); 
        void listarSociosPorEntrenador(int idEntrenador);
        void listarSociosSinEntrenador();

        std::string paseToStr(int idMemb);
        int seleccionarPase();
        
        void actualizarEstadoDelSocio(int idSocio, bool estado); 
        
        void listarSociosSinRutina(int idEntrenador); 
        void asignarRutina(int idEntrenador);

        void mostrarFechaVencimiento(Fecha fechaIngreso, int idSocio);
        bool consultarEstadoDeSocio(int idSocio);

        //void generarCSV(Socio socios[], int cantReg);

        // acceso para el socio
        void modificarContrasenia(int idSocio);
        void verEntrenadorAsignado(int idSocio);
        void verHorarios();
        void verPase(int idSocio);

    private:
        ArchivoSocios archivoSocio;
        ArchivoEmpleados archivoEmpleado;
};

