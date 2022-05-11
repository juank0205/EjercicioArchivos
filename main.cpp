#include <iostream>
#include <stdio.h>
#include "Estudiante.h"
using namespace std;



void menu(Estudiante& estudiante, Estudiante& lectura, int& cantidadEstudiantes){
    int op;
    do{
        cout << "MENU ARCHIVOS" << endl;
        cout << "1. Crear carchivo\n2. Agregar estudiante\n3. Mostrar estudiantes\n4. Buscar estudiante\n5. Buscar por edad\n6. Eliminar registro\n";
        cout << "Ingrese la opcion: ";
        cin >> op;
        system("cls");
        switch (op)
        {
        case 1:
            crearArchivo();
            cout << "Archivo creado" << endl;
            break;
        case 2:
            cantidadEstudiantes++;
            crearEstudiante(estudiante);
            break;
        case 3:
            mostrarRegistros(lectura, cantidadEstudiantes);
            break;
        case 4:
            buscarMatricula(lectura, cantidadEstudiantes);
            break;
        case 5:
            buscarEdad(lectura, cantidadEstudiantes);
            break;
        case 6:
            eliminarRegistro(lectura, cantidadEstudiantes);
            break;
        case 0:
            cout << "Adios" << endl;
            break;
        default:
            cout << "Ingrese una opcion valida" << endl;
            break;
        }

    } while (op!=0);
}
int main()
{
    Estudiante estudiante;
    Estudiante lectura;
    int cantidadEstudiantes=0;
    menu(estudiante, lectura, cantidadEstudiantes);

    system("pause");
    return 0;
}
