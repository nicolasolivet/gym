#pragma once

#include "ArchivoEmpleados.h"
#include "Empleado.h"

class ServicioEmpleado
{
    public:
        ServicioEmpleado();

        void agregarEmpleado(int idRol);
        void verEmpleados(int idRol);
        void restaurarUnEmpleado(int idRol);
        void modificarEmpleado(int idRol);
        void verSociosAsignados(int idEntrenador);
        void asignarHorarios();
        void verHorariosAsignados(int idUsuario);
        void modificarContrasenia(int idEmpleado);
        int obternerUltimoIdEmpleado();
        int obternerUltimoId();
        int obternerUltimoLegajo();
        void buscarUnEmpleado(int idRol);
        int elegirEntrenador();
        int comprobarDniEmpleado(int dni);
        void mostrarHorariosDeEntrenadores();

        void listarEmpleadoOrdenados(int idRol, int lista);
        void ordenarPorApellido(Empleado empleado[], int tam);
        void ordenarPorDni(Empleado empleado[], int tam);

    private:

        ArchivoEmpleados _archivoEmpleado;
};

