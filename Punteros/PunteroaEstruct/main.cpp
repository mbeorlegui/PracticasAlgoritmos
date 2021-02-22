#include <iostream>
#include <conio.h>

using namespace std;

struct Persona{
    char nombre[30];
    int edad;
}persona, *puntero_persona = &persona; //Pos de memoria de la variable "persona1"

void PedirDatos();
void MostrarDatos(Persona *);

int main(){
    PedirDatos();
    MostrarDatos(puntero_persona);
}

void PedirDatos(){
    cout<<"Ingrese el nombre: ";
    cin.getline(puntero_persona->nombre,30, '\n');
    // Cuando utilizo un struct y tengo que guardar un dato en un "slot", debo usar la flecha siempre
    cout<<"Ingrese edad: ";
    cin>>puntero_persona->edad;
}

void MostrarDatos(Persona *puntero_persona){
    cout<<"\nSu nombre es: "<<puntero_persona->nombre<<endl;
    cout<<"\nSu edad es: "<<puntero_persona->edad<<endl;
}
