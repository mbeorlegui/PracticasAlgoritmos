#include <iostream>

using namespace std;

struct nodo{
    nodo* sgte;
    int arribo;
};

nodo* apareo_colas(nodo*,nodo*);
void InsertarOrdenado(nodo*&,int);
void ImprimirLista(nodo*&);
void insertarFinal(nodo*&,int);

int main(){
    nodo* colA=NULL;
    nodo* colB=NULL;
    nodo* colAB=NULL;

    InsertarOrdenado(colA,1);
    InsertarOrdenado(colB,2);
    InsertarOrdenado(colA,3);
    InsertarOrdenado(colB,4);
    InsertarOrdenado(colA,5);
    InsertarOrdenado(colB,6);
    InsertarOrdenado(colA,7);
    ImprimirLista(colA);
    ImprimirLista(colB);
    colAB = apareo_colas(colA,colB);
    ImprimirLista(colAB);


}

void InsertarOrdenado(nodo *&lista,int n){
    nodo *nuevo = new nodo();
    nuevo->arribo = n;

    nodo *aux1 = lista;
    nodo *aux2;

    while(aux1 && aux1->arribo<n){
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

nodo* apareo_colas(nodo* colA, nodo* colB){
    nodo* colAB = NULL;

    while(colA && colB){
        if(colA->arribo <= colB->arribo){
            insertarFinal(colAB,colA->arribo);
            colA = colA->sgte;
        }else{
            insertarFinal(colAB,colB->arribo);
            colB = colB->sgte;
        }
    }
    return colAB;
}

void insertarFinal(nodo *&lista, int n){
    nodo *tmp = new nodo();
    tmp->arribo = n;
    tmp->sgte = NULL;
    if(lista == NULL){
        lista = tmp;
    }else{
        nodo *aux = lista;
        while(aux->sgte != NULL){
            aux = aux->sgte;
        }
        aux->sgte = tmp;
    }
}

/*
nodo* apareo_colas(nodo* colA, nodo* colB){
    nodo* colAB = NULL;
    while(colA){
        InsertarOrdenado(colAB,colA->arribo);
        colA=colA->sgte;
    }
    while(colB){
        InsertarOrdenado(colAB,colB->arribo);
        colB=colB->sgte;
    }

    return colAB;
}
*/

void ImprimirLista(nodo*&lista){
    nodo* aux = lista;
    while(aux){
        cout<<aux->arribo;
        if(aux->sgte) cout<<" -> ";
        aux = aux->sgte;
    }
    cout<<endl;
    delete aux;
}
