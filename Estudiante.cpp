#include <iostream>
#include "Estudiante.h"
using namespace std;

const char* FORMATO_ESTUDIANTE_IN = "{\n\t\"nombre:\": \"%s\",\n\t\"matricula\": %d,\n\t\"edad\": %d\n}\n";
const char* FORMATO_ESTUDIANTE_OUT = "{\n\t\"nombre:\": \"%[^\"]\",\n\t\"matricula\": %d,\n\t\"edad\": %d\n}\n";
FILE *file;

void crearArchivo(){
    fopen_s(&file, "estudiantes.txt", "w+");
}
void crearEstudiante(Estudiante& estudiante){
    cout << "Ingrese el nombre del estudiante: ";
    fflush(stdin);
    gets(estudiante.nombre);
    cout << "Ingrese la matricula: ";
    cin >> estudiante.matricula;
    cout << "Ingrese la edad: ";
    cin >> estudiante.edad;

    escribirEstudiante(estudiante);
}
void escribirEstudiante(Estudiante estudiante){
   fseek(file, 0, SEEK_END);
   fprintf(file, FORMATO_ESTUDIANTE_IN, estudiante.nombre, estudiante.matricula, estudiante.edad);
   fseek(file, 0, SEEK_SET);
}
void mostrarRegistros(Estudiante& lectura, int cantidadEstudiantes){
    fseek(file, 0, SEEK_SET);
    for (int i=0; i<cantidadEstudiantes; i++)
    {
        fscanf_s(file, FORMATO_ESTUDIANTE_OUT, lectura.nombre, 30, &lectura.matricula, &lectura.edad);
        printf("Estudiante %d: %s, Matricula: %d, Edad: %d\n", i+1, lectura.nombre, lectura.matricula, lectura.edad);
    }
    fseek(file, 0, SEEK_SET);
}
void buscarMatricula(Estudiante &lectura, int cantidadEstudiantes){
    int matricula;
    fseek(file, 0, SEEK_SET);
    cout << "Ingrese la matricula: ";
    cin >> matricula;
    for (int i=0; i<cantidadEstudiantes; i++)
    {
        fscanf_s(file, FORMATO_ESTUDIANTE_OUT, lectura.nombre, 30, &lectura.matricula, &lectura.edad);
        if (lectura.matricula == matricula){
            printf("Estudiante %d: %s, Matricula: %d, Edad: %d\n", i+1, lectura.nombre, lectura.matricula, lectura.edad);
        }
    }
        fseek(file, 0, SEEK_SET);
}
void buscarEdad(Estudiante &lectura, int cantidadEstudiantes){
    int edadMenor, edadMayor;
    cout << "Ingrese el rango de edades: ";
    cin >> edadMenor >> edadMayor;
    fseek(file, 0, SEEK_SET);
    for (int i=0; i<cantidadEstudiantes; i++)
    {
        fscanf_s(file, FORMATO_ESTUDIANTE_OUT, lectura.nombre, 30, &lectura.matricula, &lectura.edad);
        if (lectura.edad < edadMayor && lectura.edad > edadMenor){
            printf("Estudiante %d: %s, Matricula: %d, Edad: %d\n", i+1, lectura.nombre, lectura.matricula, lectura.edad);
        }
    }
        fseek(file, 0, SEEK_SET);
}
void eliminarRegistro(Estudiante &lectura, int& cantidadEstudiantes){
    mostrarRegistros(lectura, cantidadEstudiantes);
    int matricula;
    cout << "Ingrese la matricula a eliminar: ";
    cin >> matricula;

    FILE *file2;
    fopen_s(&file2, "estudiantes2.txt", "w+");
    for (int i=0; i<cantidadEstudiantes; i++){
        fscanf_s(file, FORMATO_ESTUDIANTE_OUT, lectura.nombre, 30, &lectura.matricula, &lectura.edad);
        if (lectura.matricula != matricula){
            fprintf_s(file2, FORMATO_ESTUDIANTE_IN, lectura.nombre, lectura.matricula, lectura.edad);
        }
    }
    
    fclose(file);
    cantidadEstudiantes--;
    remove("estudiantes.txt");
    fopen_s(&file, "estudiantes.txt", "w+");
    fseek(file2, 0, SEEK_SET);

    for (int i=0; i<cantidadEstudiantes; i++){
        fscanf_s(file2, FORMATO_ESTUDIANTE_OUT, lectura.nombre, 30, &lectura.matricula, &lectura.edad);
        fprintf_s(file, FORMATO_ESTUDIANTE_IN, lectura.nombre, lectura.matricula, lectura.edad);
    }
    fclose(file2);
    remove("estudiantes2.txt");

    mostrarRegistros(lectura, cantidadEstudiantes);
}