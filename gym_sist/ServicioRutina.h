#pragma once
#include "ArchivoDetalleRutina.h"
#include "ArchivoRutinas.h"
#include "DetalleRutina.h"

class ServicioRutina
{
    public:
        ServicioRutina();

        int generarIdRutina();
        void crearRutina(int idEntrenador);
        DetalleRutina crearDetalleRutina(int idRutina);
        
        void verDetalleRutina();
        void verRutinasEntrenador(int idEntrenador);
        void verDetalleRutinaSocio(int idRutina);
        void verRutinaAsignadaSocio(int idRutina);

        Rutina modificarRutina(Rutina rutina);
        DetalleRutina modificarDetalleRutina(DetalleRutina detalle);
        void buscarRutina();
        int elegirRutina(int idEntrenador);

        void menuModificarRutina_Detalle(int idEntrenador);
        
        void ordenarRutinasPorNombre(Rutina vectRutina[], int tam);
        void mostrarRutinasPorNombre();
        void mostrarRutinasPorEntrenador(int idEntrenador);
        
    private:
        ArchivoDetalleRutina archivoDetalleRutina;
        ArchivoRutinas archivoRutinas;
};

