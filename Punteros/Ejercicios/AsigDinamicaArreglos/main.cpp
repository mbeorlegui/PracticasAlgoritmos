/**
    Asignación dinámica de arreglos

    new: Reserva el número de bytes solicitado por la declaración
    delete: Libera un bloque de bytes reservado con anterioridad

    Ejemplo: Pedir al usuario n calificaciones y almacenarlas en un arreglo
*/

#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

//Prototipo de funcion
void PedirNotas();
void MostrarNotas();

int numCalif, *calif;

int main(){
    PedirNotas();
    MostrarNotas();

    delete[] calif;
}

void PedirNotas(){
    cout<<"Ingrese numero de calificaciones: ";
    cin>>numCalif;

    calif = new int[numCalif]; //Creo el arreglo dinamico

    for (int i=0;i<numCalif;i++){
        cout<<"Ingrese la nota numero "<<i+1<<": ";
        cin>>calif[i];
    }
}

void MostrarNotas(){
    cout<<endl<<"Mostrando notas: "<<endl;
    for (int i=0;i<numCalif;i++){
        cout<<calif[i]<<endl;
    }
}
