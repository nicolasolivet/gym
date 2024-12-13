#pragma once
#include "Empleado.h"

class ArchivoEmpleados
{
    public:
        ArchivoEmpleados();
        ArchivoEmpleados(std::string nombreArchivo);

        bool guardarEmpleado(Empleado emp);
        bool guardarEmpleado(Empleado emp, int posicion);
        int buscarEmpleado(int idEmpleado);
        Empleado leerRegistroEmpleado(int posicion);
        int cantidadRegistrosEmpleados();
        void leerRegistrosEmpleados(int cantidadRegistros, Empleado *vectEmpleado);

        Empleado buscarEmpleadoPorIdSocio(int id);

        int cantidadRegistrosEmpleadosPorEstado(int cantidadRegistros, bool estado, int idRol);
        int leerRegistrosEmpleadosActivos(int cantidadRegistros, int vectEmpleados[], int tam, int idRol);

    private:
        std::string _nombreArchivo;
};


