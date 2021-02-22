#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

struct info{
    int dato1;
    int dato2;
};

struct nodo{
    info dato;
    nodo *sgte = NULL;
    nodo *ant = NULL;
};

nodo* listaDEObtenerUltimo(nodo *lista){
    nodo *aux = lista;
    nodo *fin = NULL;
    int i=0;
    while(aux){
        if(aux->sgte == NULL){
            return aux;
        }
        aux = aux->sgte;
        i++;
    }
}

void insertarDatoFinal(nodo *&lista, info n){
    nodo *tmp = new nodo();
    tmp->dato = n;
    if(!lista){ // == NULL
        lista = tmp;
    }else{
        nodo *aux = listaDEObtenerUltimo(lista);
        tmp->ant = aux;
        aux->sgte = tmp;
    }
}

void insertarDatoInicio(nodo *&lista, info n){
    nodo *aux = new nodo();
    aux->dato = n;
    if(!lista){ // == NULL
        lista = aux;
    }else{
        aux->sgte = lista;
        lista->ant = aux;
        lista = aux;
    }
}

int largoLista(nodo *lista){
    int i=0;
    while(lista){
        i++;
        lista=lista->sgte;
    }
    return i;
}

void insertarDatoPosicion(nodo *&lista, info n, int pos){
    nodo *tmp = new nodo();
    int i=0;
    tmp->dato = n;

    if(largoLista(lista) >= pos){
        if(pos == 0){
            insertarDatoInicio(lista,n);
        }else if(pos == largoLista(lista)){
            insertarDatoFinal(lista,n);
        }else{
            nodo *aux = lista;
            for(i=0;i<pos-1;i++){
                aux = aux->sgte;
            }
            nodo *aux2 = aux->sgte;
            aux->sgte = tmp;
            tmp->sgte = aux2;
            aux2->ant = tmp;
            tmp->ant = aux;
        }
    }else{
        cout<<endl<<"La lista no cuenta con suficientes elementos"<<endl;
    }
}

void imprimirDatosLista(nodo*&lista){
    nodo *aux = lista;
    cout<<endl;
    while(aux){
        cout<<aux->dato.dato1<<"/"<<aux->dato.dato2;
        if(aux->sgte) cout<<" -> ";
        aux = aux->sgte;
    }
    cout<<endl;
}

void imprimirDatosListaReverse(nodo *lista){
    nodo *aux = listaDEObtenerUltimo(lista);
    cout<<endl;
    cout<<"Imprimo lista al reves: "<<endl;
    while(aux){
        cout<<aux->dato.dato1<<"/"<<aux->dato.dato2;
        if(aux->ant) cout<<" -> ";
        aux = aux->ant;
    }
    cout<<endl;
    delete aux;
}

int main(){
    nodo *lista = NULL;
    info a = {55,82}, b = {69,96}, c = {100,100}, d = {999,999};
    info f = {1,1};

    insertarDatoInicio(lista,b);
    insertarDatoFinal(lista,a);
    insertarDatoFinal(lista,a);
    insertarDatoFinal(lista,a);
    insertarDatoFinal(lista,b);
    insertarDatoPosicion(lista,c,0);
    insertarDatoInicio(lista,b);        //Verificar
    insertarDatoPosicion(lista,d,5);
    insertarDatoFinal(lista,f); //verificar
    imprimirDatosLista(lista);
    imprimirDatosListaReverse(lista);

    cout<<endl<<"El largo de la lista es de "<<largoLista(lista)<<" nodos"<<endl;

    return 0;
}
