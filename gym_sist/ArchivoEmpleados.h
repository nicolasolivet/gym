#pragma once
#include "Empleado.h"

class ArchivoEmpleados
{
    public:
        ArchivoEmpleados();
        ArchivoEmpleados(std::string nombreArchivo);

        bool guardarReg(Empleado emp);
        bool modificarReg(Empleado emp, int posicion);
        Empleado leerReg(int posicion);
        int cantidadRegistros();
        void leerRegistros(int cantidadRegistros, Empleado *empleados);
        int buscarReg(int idEmpleado);

        //Empleado buscarEmpleadoPorIdSocio(int id);

        int cantidadEmpleadosPorEstado(int cantidadRegistros, bool estado, int idRol);
        int empleadosActivos(int cantidadRegistros, int vectEmpleados[], int idRol);

    private:
        std::string archivoEmpleados;
};


