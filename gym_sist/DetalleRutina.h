#pragma once


class DetalleRutina
{
public:
        DetalleRutina();
        DetalleRutina(int *idEjercicio, int idRutina, int *repeticiones, float *peso);

        void setIdEjercicio(int *idEjercicios);
        void setIdRutina(int idRutina);
        void setRepeticiones(int *repeticiones);
        void setPeso(float *peso);

        int* getIdEjercicio();
        int getIdRutina();
        int* getRepeticiones();
        float* getPeso();

    private:
        int _idEjercicio[10];
        int _idRutina;
        int _repeticiones[10];
        float _peso[10];
};
