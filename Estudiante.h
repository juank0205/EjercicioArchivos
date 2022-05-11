#pragma once

struct Estudiante
{
    char nombre[30];
    int matricula;
    int edad;
};

void crearArchivo();
void crearEstudiante(Estudiante& estudiante);
void escribirEstudiante(Estudiante estudiante);
void mostrarRegistros(Estudiante& lectura, int cantidadEstudiantes);
void buscarMatricula(Estudiante &lectura, int cantidadEstudiantes);
void buscarEdad(Estudiante &lectura, int cantidadEstudiantes);
void eliminarRegistro(Estudiante &lectura, int& cantidadEstudiantes);