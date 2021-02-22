#include <iostream>
#include <conio.h>

using namespace std;

struct Tipo1{
    char dato1[3];
};

struct Tipo2{
    char dato2[3];
    char dato1[3];
};

struct NodoListaTipo2{
    Tipo2 info;
    NodoListaTipo2 *sgte;
    NodoListaTipo2 *ant;
};

struct NodoListaTipo1{
    Tipo1 info;
    NodoListaTipo1 *sgte;
    NodoListaTipo2 *sublista;
};

struct NodoLista{
    int id;
    NodoLista *sgte;
};

void ImprimirLista(NodoLista *);
void BorrarNodo(NodoLista *, int);

int main(){
    NodoLista *listaQ = NULL;
    listaQ = new NodoLista();

    listaQ->id = 1;
    listaQ->sgte = new NodoLista();
    listaQ->sgte->id = 2;
    listaQ->sgte->sgte = new NodoLista();
    listaQ->sgte->sgte->id = 3;
    listaQ->sgte->sgte->sgte = new NodoLista();
    listaQ->sgte->sgte->sgte->id = 4;

    ImprimirLista(listaQ);
    BorrarNodo(listaQ, 2);
    ImprimirLista(listaQ);
}

void ImprimirLista(NodoLista* lista){
    NodoLista *paux = lista;
    cout<<"Lista actual: ";
    while(paux){
        cout<<paux->id<<" ";
        paux = paux->sgte;
    }
    cout<<endl;
}

void BorrarNodo(NodoLista* lista, int n){
    NodoLista* aux = lista;
    NodoLista* aux2 = new NodoLista();

    while(aux) {
        if(aux->id == n){
            aux2 = aux->sgte->sgte;
            delete aux->sgte;
            aux->sgte = aux2;
        }
        aux = aux->sgte;
    }
    //------------------------------------
    while(aux) {
        if(aux->id == n){
            aux2 = aux->sgte;
            delete aux;
            aux->sgte = aux2;
        }
        aux = aux->sgte;
    }
    delete aux2;
    delete aux;
    cout<<"Borro nodo"<<endl;
}


