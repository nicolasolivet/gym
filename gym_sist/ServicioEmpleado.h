#pragma once
#include "ArchivoEmpleados.h"
#include "Empleado.h"

class ServicioEmpleado
{
    public:
        ServicioEmpleado();

        /// acceso gerente 
        int chequearExistenciaEmpleado(int dni);
        int generarIdEmpleado();
        void agregarEmpleado(int idRol);
        void verEmpleados(int idRol);
        void modificarEmpleado(int idRol);
        void buscarEmpleado(int idRol);
        void restaurarEmpleado(int idRol);
        void asignarHorarios();
        
        /// acceso entrenador
        void verHorariosAsignados(int idUsuario);
        void verSociosAsignados(int idEntrenador);
        void modificarContrasenia(int idEmpleado);
        
        int obtenerUltimoId();
        int elegirEntrenador();
        void mostrarHorariosEntrenadores();

        void listarEmpleadoOrdenados(int idRol, int lista);
        void ordenarPorApellido(Empleado empleado[], int tam);
        void ordenarPorDni(Empleado empleado[], int tam);

    private:

        ArchivoEmpleados archivoEmpleado;
};

