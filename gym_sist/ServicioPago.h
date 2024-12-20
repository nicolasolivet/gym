#pragma once

#include "ArchivoPagos.h"

class ServicioPago
{
    public:
        ServicioPago();

        bool verificarUltimoPago(int idSocio);
        bool registrarPago(int idSocio, int idMembresia, Fecha periodo);
        void verPago(int idSocio);
        void listarTotalPagos();
        void verPagosPorMes();
        void verPagosPorAnio();
        void verIngresosAnuales();
        void verIngresosMensuales();

        int cantidadDeDiasDelUltimoPago(int idSocio);
        void mostrarListaDePagosPorTipoDePase();
        void verIngresosAnualesPorSocios();

    private:
        ArchivoPagos _archivoPago;
};

