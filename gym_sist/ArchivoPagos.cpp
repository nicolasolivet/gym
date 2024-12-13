#include <iostream>
#include "ArchivoPagos.h"

using namespace std;

ArchivoPagos::ArchivoPagos() {}

ArchivoPagos::ArchivoPagos(std::string nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
}

bool ArchivoPagos::guardarPago(const Pago& pago)
{

    FILE* pfile;
    pfile = fopen(_nombreArchivo.c_str(), "ab");
    if (pfile == nullptr)
    {
        return false;
    }

    bool result = fwrite(&pago, sizeof(Pago), 1, pfile) == 1;

    fclose(pfile);

    return result;
}

bool ArchivoPagos::modificarPago(Pago& pago, int pos)
{

    FILE* pfile;
    bool result;

    pfile = fopen(_nombreArchivo.c_str(), "rb+");
    if (pfile == nullptr)
    {
        return false;
    }

    fseek(pfile, sizeof(Pago) * pos, SEEK_SET);

    result = fwrite(&pago, sizeof(Pago), 1, pfile) == 1;

    fclose(pfile);
    return result;
}

Pago ArchivoPagos::leerPago(int pos)
{

    Pago rp;
    FILE* pfile;
    pfile = fopen(_nombreArchivo.c_str(), "rb");
    if (pfile == nullptr)
    {
        return rp;
    }

    fseek(pfile, sizeof(Pago) * pos, SEEK_SET);

    fread(&rp, sizeof(Pago), 1, pfile);

    fclose(pfile);

    return rp;
}

int ArchivoPagos::getCantidadPagos()
{

    int totalBytes, cantReg;
    Pago rp;
    FILE* pfile;
    pfile = fopen(_nombreArchivo.c_str(), "rb");
    if (pfile == nullptr)
    {
        return 0;
    }

    fseek(pfile, 0, SEEK_END);

    totalBytes = ftell(pfile);

    fclose(pfile);

    return cantReg = totalBytes / sizeof(Pago);
}

void ArchivoPagos::leerTodosPagos(Pago* vPagos, int cantPagos)
{

    FILE* pfile;
    pfile = fopen(_nombreArchivo.c_str(), "rb");

    if (pfile == nullptr)
    {
        return;
    }

    for (int i = 0; i < cantPagos; i++)
    {
        fread(&vPagos[i], sizeof(Pago), cantPagos, pfile);
    }

    fclose(pfile);
}

///filtros
int ArchivoPagos::buscarPago(int id)
{

    Pago pago;
    int pos = 0;

    FILE* pfile;
    pfile = fopen(_nombreArchivo.c_str(), "rb");
    if (pfile == nullptr)
    {
        return 0;
    }

    while (fread(&pago, sizeof(Pago), 1, pfile) == 1)
    {
        if (pago.getIdUsuario() == id)
        {
            break;
        }
        pos++;
    }

    fclose(pfile);

    if (pago.getIdUsuario() == id)
    {
        return pos;
    }
    else
    {
        return -1;
    }
}

int ArchivoPagos::cantidadPagosXSocio(int cantPagos, int idUsuario)
{

    Pago pago;
    int cont = 0;

    FILE* pfile;
    pfile = fopen(_nombreArchivo.c_str(), "rb");

    if (pfile == nullptr)
    {
        return -1;
    }

    for (int i = 0; i < cantPagos; i++)
    {
        fread(&pago, sizeof(Pago), 1, pfile);
        if (pago.getIdUsuario() == idUsuario)
        {
            cont++;
        }
    }

    fclose(pfile);
    return cont;
}

int ArchivoPagos::leerPagosXSocio(int cantPagos, int vPagos[], int tam, int idUsuario)
{

    Pago pago;
    int index = 0;

    FILE* pfile;
    pfile = fopen(_nombreArchivo.c_str(), "rb");

    if (pfile == nullptr)
    {
        return -1;
    }

    for (int i = 0; i < cantPagos; i++)
    {
        fread(&pago, sizeof(Pago), 1, pfile);
        if (pago.getIdUsuario() == idUsuario)
        {
            vPagos[index] = i;
            index++;
        }
    }

    fclose(pfile);
    return *vPagos;
}

int ArchivoPagos::ultimoPagoSocio(int cantPagos, int idUsuario)
{
    Pago pago;

    int pos = -1;
    FILE *pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if (pArchivo == nullptr)
    {
        return -1;
    }

    for(int i = 0; i < cantPagos; i++)
    {
        fread(&pago, sizeof(Pago), 1, pArchivo);
        if(pago.getIdUsuario() == idUsuario)
        {
            pos = i;
        }
    }

    fclose(pArchivo);

    return pos;
}
