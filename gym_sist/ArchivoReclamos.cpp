#include <iostream>
#include "ArchivoReclamos.h"


using namespace std;

ArchivoReclamos::ArchivoReclamos() {}

ArchivoReclamos::ArchivoReclamos(string nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
}

bool ArchivoReclamos::guardarReclamo(const Reclamo& r)
{
    FILE* pfile;

    pfile = fopen(_nombreArchivo.c_str(), "ab");
    if (pfile == nullptr)
    {
        return false;
    }

    bool result = fwrite(&r, sizeof(Reclamo), 1, pfile) == 1;
    fclose(pfile);

    return result;
}

Reclamo ArchivoReclamos::leerReclamo(int pos)
{
    Reclamo r;

    FILE* pfile;

    pfile = fopen(_nombreArchivo.c_str(), "rb");
    if (pfile == nullptr)
    {
        return r;
    }

    fseek(pfile, sizeof(Reclamo) * pos, SEEK_SET);

    fread(&r, sizeof(Reclamo), 1, pfile);

    fclose(pfile);

    return r;
}

int ArchivoReclamos::getCantidadReclamos()
{
    int totalBytes, cantReg;
    Reclamo r;
    FILE *pfile;
    pfile = fopen(_nombreArchivo.c_str(), "rb");
    if (pfile == nullptr)
    {
        return 0;
    }

    fseek(pfile, 0, SEEK_END);

    totalBytes = ftell(pfile);

    fclose(pfile);

    return cantReg = totalBytes / sizeof(Reclamo);
}

bool ArchivoReclamos::leerTodosReclamos(Reclamo r[], int cantReclamos)
{
    FILE* pfile;
    pfile = fopen(_nombreArchivo.c_str(), "rb");

    if (pfile == nullptr)
    {
        return false;
    }

    bool result = fread(&r, sizeof(Reclamo), cantReclamos, pfile) == 1;

    fclose(pfile);

    return result;
}

bool ArchivoReclamos::modificarReclamo(Reclamo &r, int pos)
{
    FILE *pfile;
    bool result;

    pfile = fopen(_nombreArchivo.c_str(), "rb+");
    if (pfile == nullptr)
    {
        return false;
    }

    fseek(pfile, sizeof(Reclamo) * pos, SEEK_SET);

    result = fwrite(&r, sizeof(Reclamo), 1, pfile) == 1;

    fclose(pfile);
    return result;
}


///filtros
int ArchivoReclamos::buscarReclamo(int id)
{

    Reclamo r;
    int pos = 0;

    FILE *pfile;

    pfile = fopen(_nombreArchivo.c_str(), "rb");

    if (pfile == nullptr)
    {
        return 0;
    }

    while (fread(&r, sizeof(Reclamo), 1, pfile) == 1)
    {
        if (r.getIdReclamo() == id)
        {
            break;
        }
        pos++;
    }

    fclose(pfile);

    if (r.getIdReclamo() == id)
    {
        return pos;
    }
    else
    {
        return -1;
    }
}

void ArchivoReclamos::leerRegistrosReclamo(int cantidadRegistros, Reclamo *vecReclamo)
{
    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr)
    {
        return;
    }

    for(int i = 0; i < cantidadRegistros; i++)
    {
        fread(&vecReclamo[i], sizeof(Reclamo), 1, pArchivo);
    }

    fclose(pArchivo);
}

int ArchivoReclamos::cantidadDeRegistrosPorUsuario(int cantidadRegistros, int idUsuario)
{
    int cont = 0;
    FILE *pArchivo;

    Reclamo reclamo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr)
    {
        return -1;
    }

    for(int i=0; i<cantidadRegistros; i++)
    {
        fread(&reclamo, sizeof(Reclamo), 1, pArchivo);
        if(reclamo.getIdUsuario() == idUsuario)
        {
            cont++;
        }
    }

    fclose(pArchivo);

    return cont;

}

int ArchivoReclamos::leerRegistrosPorUsuario(int cantidadRegistros, int vectReclamos[], int tam, int idUsuario)
{
    int indice = 0;
    FILE *pArchivo;

    Reclamo reclamo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr)
    {
        return -1;
    }

    for(int i=0; i<cantidadRegistros; i++)
    {
        fread(&reclamo, sizeof(Reclamo), 1, pArchivo);
        if(reclamo.getIdUsuario() == idUsuario)
        {
            vectReclamos[indice] = i;
            indice++;
        }
    }

    fclose(pArchivo);

    return *vectReclamos;
}


