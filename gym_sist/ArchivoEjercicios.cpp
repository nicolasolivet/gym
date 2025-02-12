#include <iostream>
#include "ArchivoEjercicios.h"

using namespace std;

ArchivoEjercicios::ArchivoEjercicios(){}

ArchivoEjercicios::ArchivoEjercicios(string nombreArchivo)
{
    archivoEjercicios = nombreArchivo;
}

bool ArchivoEjercicios::guardarReg(Ejercicio ejercicio)
{
    FILE *pfile;
    pfile = fopen(archivoEjercicios.c_str(), "ab");
    if (pfile == nullptr) { return false; }
    
    bool guardado = fwrite(&ejercicio, sizeof(Ejercicio), 1, pfile);
    fclose(pfile);

    return guardado;
}

bool ArchivoEjercicios::modificarReg(Ejercicio ejercicio, int posicion)
{
    FILE *pfile;
    pfile = fopen(archivoEjercicios.c_str(), "rb+");
    if (pfile == nullptr) { return false; }

    fseek(pfile, sizeof(Ejercicio) * posicion, SEEK_SET);
    bool modificado = fwrite(&ejercicio, sizeof(Ejercicio), 1, pfile);
    fclose(pfile);

    return modificado;
}

int ArchivoEjercicios::buscarReg(int idEjercicio)
{
    int posicion = 0;
    Ejercicio ejercicio;

    FILE *pfile;
    pfile = fopen(archivoEjercicios.c_str(), "rb");
    if (pfile == nullptr) { return -2; }

    while(fread(&ejercicio, sizeof(Ejercicio), 1, pfile))
    {
        if(ejercicio.getIdEjercicio() == idEjercicio)
        {
            fclose(pfile);
            return posicion;
        }
        posicion++;
    }
    fclose(pfile);

    return -1;
}

Ejercicio ArchivoEjercicios::leerReg(int posicion)
{
    Ejercicio ejercicio;

    FILE *pfile;
    pfile = fopen(archivoEjercicios.c_str(), "rb");
    if (pfile == nullptr) { return Ejercicio(); }

    fseek(pfile, sizeof(Ejercicio) * posicion, SEEK_SET);
    fread(&ejercicio, sizeof(Ejercicio), 1, pfile);
    fclose(pfile);

    return ejercicio;
}

int ArchivoEjercicios::cantidadRegistros()
{
    int cantidad;

    FILE *pfile;
    pfile = fopen(archivoEjercicios.c_str(), "rb");
    if (pfile == nullptr) { return -1; }

    fseek(pfile, 0, SEEK_END);
    cantidad = ftell(pfile) / sizeof(Ejercicio);
    fclose(pfile);

    return cantidad;
}

void ArchivoEjercicios::leerRegistros(int cantidadRegistros, Ejercicio *ejercicios)
{
    FILE *pfile;
    pfile = fopen(archivoEjercicios.c_str(), "rb");
    if (pfile == nullptr) { return; }

    for(int i = 0; i < cantidadRegistros; i++)
    {
        fread(&ejercicios[i], sizeof(Ejercicio), 1, pfile);
    }

    fclose(pfile);
}
