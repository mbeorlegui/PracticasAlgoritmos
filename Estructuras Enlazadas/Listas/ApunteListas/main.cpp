#include <iostream>
#include <conio.h>

using namespace std;

struct nodo{
    nodo* sgte;
    int dato;
};

void InsertarOrdenado(nodo*&,int);
void ImprimirLista(nodo*&);
nodo* BuscarEnLista(nodo*&, int);
void EliminarNodo(nodo*&, int);
void BorrarLista(nodo*&, int);

int main(){
    nodo *lista = NULL;
    int elim = 3;

    InsertarOrdenado(lista,5);
    InsertarOrdenado(lista,7);
    InsertarOrdenado(lista,3);
    ImprimirLista(lista);

    cout<<"Direccion de memoria del 3: "<<BuscarEnLista(lista,3)<<endl;
    cout<<"Direccion de memoria del 5: "<<BuscarEnLista(lista,5)<<endl;
    cout<<"Direccion de memoria del 7: "<<BuscarEnLista(lista,7)<<endl;
    cout<<"Direccion de memoria del 8: "<<BuscarEnLista(lista,8)<<endl;     /// Da 0 porque es NULL
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"Elimino el "<<elim<<endl;

    EliminarNodo(lista,elim);
    ImprimirLista(lista);


}

void InsertarOrdenado(nodo *&lista,int n){
    nodo *nuevo = new nodo();
    nuevo->dato = n;

    nodo *aux1 = lista;
    nodo *aux2;

    while(aux1 && aux1->dato<n){
        aux2 = aux1;
        aux1 = aux1->sgte;
    }
    if(lista==aux1){
        lista = nuevo;
    }
    else{
        aux2->sgte = nuevo;
    }
    nuevo->sgte = aux1;
}

void ImprimirLista(nodo*&lista){
    nodo* aux = lista;
    while(aux){
        cout<<aux->dato;
        if(aux->sgte) cout<<" -> ";
        aux = aux->sgte;
    }
    cout<<endl;
    delete aux;
}

nodo* BuscarEnLista(nodo *&lista, int n){
    nodo* aux = lista;
    while(aux){
        if(aux->dato == n){
            return aux;
        }
        aux = aux->sgte;
    }
    return NULL;
}
// Retorna la dirección de memoria que contiene el valor buscado o NULL en caso de no encontrarlo

void EliminarNodo(nodo *&lista, int n){
    nodo *aux = lista;
    nodo *anterior = NULL;

    while(aux && aux->dato != n){
        anterior = aux;
        aux = aux->sgte;
    }
    if(aux == NULL){
        cout<<"No existe el elemento"<<endl;
    }else if(anterior == NULL){
        lista = lista->sgte;
        delete aux;
    }else{
        anterior->sgte = aux->sgte;
        delete aux;
    }
}

void BorrarLista(nodo *&lista, int n){
    while(lista){
        nodo *aux = lista;
        n = aux->dato;
        lista = lista->sgte;
        delete aux;
    }
}

