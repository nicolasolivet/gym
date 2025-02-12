#pragma once
#include "Pago.h"

class ArchivoPagos
{
    public:
        ArchivoPagos();
        ArchivoPagos(std::string nombreArchivo);

        bool guardarReg(Pago &p);
        bool modificarReg(Pago &p, int pos);
        Pago leerReg(int pos);
        int cantidadRegistros();
        void leerRegistros(int cantReg, Pago *pagos); //de la manera en que lo pensamos este metodo no lo terminamos usando.
        int buscarReg(int idUsuario);

        /// filtros por socio
        int cantidadPagosPorSocio(int cantReg, int idUsuario);
        int leerPagosPorSocio(int cantReg, int pagosPorSocio[], int idUsuario);
        int ultimoPagoSocio(int cantReg, int idUsuario);

        /// metodos de prueba, descartar
        void crearPago();
        void mostrarPago(Pago p);
        void mostrarPago();
        void mostrarTodos();
        void pagosDelSocio();

    private:
        std::string _archivoPagos;
};
