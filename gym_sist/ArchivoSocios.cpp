#include <iostream>
#include "ArchivoSocios.h"

using namespace std;

ArchivoSocios::ArchivoSocios() {}

ArchivoSocios::ArchivoSocios(string nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
}

bool ArchivoSocios::guardarReg(Socio socio)
{
    bool guardado;
    FILE *pfile;
    pfile = fopen(_nombreArchivo.c_str(), "ab");
    if (pfile == nullptr) { return false; }

    guardado = fwrite(&socio, sizeof(Socio), 1, pfile);

    fclose(pfile);
    return guardado;
}

Socio ArchivoSocios::leerReg(int posicion)
{
    Socio reg;
    FILE* pfile;
    pfile = fopen(_nombreArchivo.c_str(), "rb");
    if (pfile == nullptr) { return reg; }

    fseek(pfile, sizeof(Socio) * posicion, SEEK_SET);
    fread(&reg, sizeof(Socio), 1, pfile);
    fclose(pfile);

    return reg;
}

bool ArchivoSocios::modificarReg(Socio socio, int posicion)
{
    bool modificado;
    FILE* pfile;
    pfile = fopen(_nombreArchivo.c_str(), "rb+");
    if (pfile == nullptr) { return false; }

    fseek(pfile, sizeof(Socio) * posicion, SEEK_SET);
    modificado = fwrite(&socio, sizeof(Socio), 1, pfile);

    fclose(pfile);
    return modificado;
}

int ArchivoSocios::buscarReg(int idSocio) 
{
    Socio socio;
    int posicion = 0;
    FILE* pfile;
    pfile = fopen(_nombreArchivo.c_str(), "rb");
    if (pfile == nullptr) { return -1; }

    while (fread(&socio, sizeof(Socio), 1, pfile))
    {
        if (socio.getIdUsuario() == idSocio) 
        {
            fclose(pfile);
            return posicion;
        }
        posicion++;
    }
    
    fclose(pfile);
    return -2;
}

int ArchivoSocios::cantidadRegistros()
{
    int cantidad;
    FILE* pfile;
    pfile = fopen(_nombreArchivo.c_str(), "rb");
    if (pfile == nullptr) { return false; }

    fseek(pfile, 0, SEEK_END);
    cantidad = ftell(pfile) / sizeof(Socio);

    fclose(pfile);
    return cantidad;
}

void ArchivoSocios::leerRegistros(int cantReg, Socio *socios)
{
    FILE* pfile;
    pfile = fopen(_nombreArchivo.c_str(), "rb");
    if (pfile == nullptr) { return; }

    for (int i = 0; i < cantReg; i++)
    {
        fread(&socios[i], sizeof(Socio), 1, pfile);
    }

    fclose(pfile);
}



