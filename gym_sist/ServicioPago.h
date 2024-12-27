#pragma once

#include "ArchivoPagos.h"

class ServicioPago
{
    public:
        ServicioPago();

        bool verificarUltimoPago(int idSocio);
        bool registrarPago(int idSocio, int idMembresia, Fecha periodo);
        void verPagosPorSocio(int idSocio);
        //void listarTotalPagos();
        void verPagosPorMes();
        void verPagosPorAnio();
        void verIngresosAnuales();
        void verIngresosMensuales();
        void verIngresosAnualesPorSocio();

        void mostrarListaDePagosPorTipoDePase();
        int cantidadDeDiasDelUltimoPago(int idSocio);

    private:
        ArchivoPagos _archivoPago;
};

