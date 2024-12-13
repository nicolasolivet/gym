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
        int _idRutina;
        int _frecuenciaSemanal;
        int _idEntrenador;
        char _nombreRutina[30];
        char _descripcion[100];
};
