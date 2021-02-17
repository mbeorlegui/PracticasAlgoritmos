#include <iostream>
#include <conio.h>

using namespace std;

struct TipoInfo{
    int id;
    char nombre[30];
};

struct Nodo{
    int info;   //Por lo general se usa un tipo de dato struct dentro de "info"
    Nodo *sgte;
};


int main(){
    Nodo *inicio = NULL;    //Inicio es un puntero de tipo Nodo inicializado en NULL (HACER SIEMPRE)
    inicio = new Nodo();    //Reserva espacio en memoria para un registro de tipo Nodo
    //New devuelve la dirección de memoria donde se reserva el espacio
    //Inicio va a dejar de apuntar a NULL y va a apuntar a un Nodo
    inicio->info = 5;       //(*inicio).info = 5;
    inicio->sgte = NULL;
    cout << "Cada nodo ocupa: " << sizeof(Nodo) << " bytes" << endl;
    cout << "La info de inicio es: " << inicio->info << endl;
    inicio->sgte = new Nodo(); //Creo un segundo nodo en "siguiente"
    inicio->sgte->info = 27;
    inicio->sgte->sgte = NULL;

    //Creo un tercer nodo con un puntero auxiliar
    Nodo *paux;
    paux = inicio->sgte;
    paux->sgte = new Nodo();
    paux = paux->sgte;
    paux->info = 32;
    paux->sgte = NULL;
    /** Muestro el contenido de la lista  */
    cout << "--------------------------"<<endl;
    cout << "Contenido de toda la lista: "<<endl<<endl;
    paux = inicio;

    while (paux){ // Lo mismo que while(paux != NULL)
        cout<<"Direccion del nodo: "<<paux<<endl;
        cout<<"Info: "<<paux->info<<endl;
        cout<<"Siguiente en: "<<paux->sgte<<endl;
        cout<<"-------------------"<<endl;
        paux = paux->sgte;
    }
}

