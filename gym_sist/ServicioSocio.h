#pragma once
#include "ArchivoSocios.h"
//#include "ArchivoEmpleados.h"

class ServicioSocio
{
    public:
        ServicioSocio();

        int autoGenerarId();
        void agregarSocio();
        void verSociosPorId();
        void verSociosPorApellido();
        void verSociosPorDni();
        void listarSocios(Socio socios[], int cantReg);
        
        Socio buscarSocio(int idUsuario);
        void buscarSocioPorId();
        bool buscarSocioPorDni(int dni);
        
        void modificarSocio();

        //void mostrarTurno(int idTurno);
        //void mostrarSociosPorEntrenador(int idEntrenador);

        std::string membresiaToStr(int idMemb);
        int seleccionarMembresia();
        
        //void mostrarFechaVencimiento(Fecha fechaIngreso, int idSocio);
        //bool consultarEstadoDeSocio(int idSocio);
        //void actualizarEstadoDelSocio(int idSocio, bool estado);
        
        //void verListaDeSociosSinEntrenador();
        //void verListaDeSociosSinRutina(int idEntrenador);
        //void asignarUnaRutina(int idEntrenador);

        //void generarCSV(Socio socios[], int cantReg);

        // acceso para el socio
        void modificarContrasenia(int idSocio);
        void verEntrenadorAsignado(int idSocio);
        void verHorarios();
        void verMembresia(int idSocio);

    private:
        ArchivoSocios _archivoSocio;
        //ArchivoEmpleados _archivoEmpleado;
};

