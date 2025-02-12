#pragma once


class Rutina
{
    public:
        Rutina();
        Rutina(int idRutina, int frecuenciaSemanal, int idEntrenador, std::string nombreRutina, std::string descripcion);

        void setIdRutina(int idRutina);
        void setFrecuenciaSemanal(int frecuenciaSemanal);
        void setIdEntrenador(int idEntrenador);
        void setNombreRutina(std::string nombreRutina);
        void setDescripcion(std::string descripcion);

        int getIdRutina();
        int getFrecuenciaSemanal();
        int getIdEntrenador();
        std::string getNombreRutina();
        std::string getDescripcion();

    private:
        int idRutina;
        int frecuenciaSemanal;
        int idEntrenador;
        char nombreRutina[30];
        char descripcion[100];
};
