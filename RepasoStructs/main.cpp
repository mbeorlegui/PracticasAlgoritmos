#include <iostream>
#include <conio.h>

using namespace std;

/* Un struct es una colección de uno o más tipos de elementos,
en el que cada uno puede ser de un tipo diferente */

// Declaracion de la estructura
struct persona {
    char nombre[20];
    int edad;
}
persona1 = {"Alejandro", 20},
persona2 = {"Ruperto", 15};            //Declaracion de variable (1)

//Estructura anidada

struct empleado{
    char puesto[20];
    persona pers;       // Para identificar una persona anido sus datos
}
empleado1 = {"Maquinista", {"Roberto", 40}},
empleado2 = {"Contador", {"Javier", 60}},
empleados[2]; //Array de structs

int main(){
    persona persona3 = {"Nicolas", 20};
    persona persona4 = {"Matias", 21};  // Declaracion de variable (2)
    // empleado empleados[2]; Tambien se puede declarar así

    cout<<"1) Nombre: "<< persona1.nombre <<" Edad: "<< persona1.edad << endl;
    cout<<"2) Nombre: "<< persona2.nombre <<" Edad: "<< persona2.edad << endl;
    cout<<"3) Nombre: "<< persona3.nombre <<" Edad: "<< persona3.edad << endl;
    cout<<"4) Nombre: "<< persona4.nombre <<" Edad: "<< persona4.edad << endl;

    cout<<"------------------------------------------------------------"<<endl;
    cout<<"Empleado 1) Nombre: "<<empleado1.pers.nombre<<" Edad: "<<empleado1.pers.edad<< " Puesto: " << empleado1.puesto<<endl;
    cout<<"Empleado 2) Nombre: "<<empleado2.pers.nombre<<" Edad: "<<empleado2.pers.edad<< " Puesto: " << empleado2.puesto<<endl;
    cout<<"------------------------------------------------------------"<<endl;

    for(int i=0; i<2; i++){
        cout<<"Ingrese el nombre del empleado numero "<< i+1 <<": ";
        cin >> empleados[i].pers.nombre;
        cout<<"Ingrese la edad del empleado numero "<< i+1 <<": ";
        cin >> empleados[i].pers.edad;
        cout<<"Ingrese el puesto del empleado numero "<< i+1 <<": ";
        cin >> empleados[i].puesto;
        cout<<"------------------------------------------------------------"<<endl;
    }
    cout<<"------------------------------------------------------------"<<endl;

    for(int i=0; i<2; i++){
        cout<<"Empleado numero 1: "<< endl;
        cout<<"Nombre: " << empleados[i].pers.nombre<< endl;
        cout<<"Edad: " << empleados[i].pers.edad<< endl;
        cout<<"Puesto: "<< empleados[i].puesto<< endl;
        cout<<"------------------------------------------------------------"<<endl;
    }

    return 0;
}
