#pragma once
#include <string>

class Fecha
{
    public:
        Fecha();
        Fecha(int dia, int mes, int anio);

        void setDia(int dia);
        void setMes(int mes);
        void setAnio(int anio);

        int getDia() const;
        int getMes() const;
        int getAnio() const;

        void setFechaDefecto();
        void establecerFechaActual();
        bool validarDia();
        bool validarMes();
        bool validarAnio();
        void validarFecha();
        bool esBisiesto(int anio);
        bool compararSiFechasSonIguales(Fecha fecha);

        int diasPorMes(int mes, int anio);


        Fecha calcularDiasParaVencimiento(Fecha fechaVencimiento);

        std::string toString();

        static Fecha crearFecha();

    private:
        int _dia;
        int _mes;
        int _anio;

};
