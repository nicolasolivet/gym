#pragma once

#include "ArchivoPagos.h"

class ServicioPago
{
private:
    ArchivoPagos _archivoPago;

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
};

