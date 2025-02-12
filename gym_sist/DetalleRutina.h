#pragma once
#include <string>

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
        int idEjercicio[10];
        int idRutina;
        int repeticiones[10];
        float peso[10];
};
