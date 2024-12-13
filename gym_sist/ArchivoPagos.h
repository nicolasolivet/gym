#pragma once
#include "Pago.h"

class ArchivoPagos
{
    private:
        std::string _nombreArchivo;

    public:
        ArchivoPagos();
        ArchivoPagos(std::string nombreArchivo);
        bool guardarPago(const Pago &p);
        Pago leerPago(int pos);
        bool modificarPago(Pago &p, int pos);
        void leerTodosPagos(Pago *p, int);
        int getCantidadPagos();
        int buscarPago(int idUsuario);

        /// filtros por socio
        int cantidadPagosXSocio(int cantidadRegistros, int idUsuario);
        int leerPagosXSocio(int cantidadRegistros, int vectPagos[], int tam, int idUsuario);
        int ultimoPagoSocio(int cantidadRegistros, int idUsuario);
};
