#include <iostream>

using namespace std;

struct disponib{
    int id;
    int hab;
    int dias;
};

struct info{
    int id;
    int dias;
};

struct nodo{
    nodo* sgte;
    info dato;
};

void actualizar(disponib [],nodo*);
void ImprimirLista(nodo*&);
void push(nodo*&,info);

int main(){
    disponib vect[100] = {{1,15,87}};
    nodo *lista = NULL;

    cout<<vect[0].id<<endl;
    cout<<vect[0].hab<<endl;
    cout<<vect[0].dias<<endl;

    ImprimirLista(lista);

}

void ImprimirLista(nodo*&lista){
    nodo* aux = lista;
    while(aux){
        cout<<aux->dato.id<<"-"<<aux->dato.dias<<"-"<<endl;
        if(aux->sgte) cout<<" -> ";
        aux = aux->sgte;
    }
    cout<<endl;
    delete aux;
}

void push(nodo *&pila, info x){
    nodo *aux = new nodo();
    aux->dato = x;
    aux->sgte = pila;
    pila = aux;
}


void actualizar(disponib vect[], nodo *lista){
    while(lista){
        for(int i=0;i<100;i++){
            if(lista->dato.id == vect[i].id){
                vect[i].dias = vect[i].dias - lista->dato.dias;
            }
        }
        lista=lista->sgte;
    }
}

/**

    Ejercicio 2:

    Se tiene un vector de Reservas de los hoteles de la costa �HotelAr� para el verano 2021, que contiene
    la disponibilidad de un hotel con los siguientes campos:

    -	C�digo del Hotel
    -	Cantidad de Habitaciones
    -	Cantidad de d�as disponibles en la temporada.

    Adem�s, se cuenta con una lista ordenada que contiene las �ltimas reservas realizadas, cada nodo de la lista contiene:

    -	C�digo de Hotel
    -	Cantidad de d�as.

    Se pide, actualizar el vector Reservas con la informaci�n que hay en la lista. Ej: Si en la lista
    el hotel 1023 tiene 2 d�as reservados, esos 2 d�as se deben restar en el campo de Cantidad de d�as del Vector.

    Se sabe que c�mo M�ximo hay 100 Hoteles.

**/
