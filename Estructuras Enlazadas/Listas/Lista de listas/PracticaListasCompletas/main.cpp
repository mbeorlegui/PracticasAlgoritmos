#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct nodoListaSecundaria{
    char str[10];
    nodoListaSecundaria *sgte;
};

struct nodoListaPrincipal{
    int dato;
    nodoListaPrincipal *sgte;
    nodoListaSecundaria *sublista;
};

void cargarLista(nodoListaPrincipal*&);
void imprimirDatosLista(nodoListaPrincipal*);
void insertarInicio(nodoListaPrincipal*&, int);
void insertarFinal(nodoListaPrincipal*&, int);
void imprimirDatosListaPrinc(nodoListaPrincipal*&);
void imprimirDatosSublista(nodoListaPrincipal*);
void insertarFinalSublista(nodoListaSecundaria*&, char[]);

using namespace std;

int main(){
    nodoListaPrincipal *lista = NULL;

    cargarLista(lista);
    imprimirDatosLista(lista);

    return 0;
}

void cargarLista(nodoListaPrincipal *&lista){
    insertarInicio(lista,38);
    insertarInicio(lista,55);
    insertarInicio(lista,99);
    insertarFinal(lista,1);
    insertarInicio(lista,23);
    insertarFinalSublista(lista->sublista,"hola");
    insertarFinalSublista(lista->sublista,"Como estas?");
    insertarFinalSublista(lista->sublista,"Bien bien");
}

void imprimirDatosLista(nodoListaPrincipal *lista){
    imprimirDatosListaPrinc(lista);
    imprimirDatosSublista(lista);
    cout<<lista->sgte<<endl;                //Dir de memoria del nodo sgte
}

void imprimirDatosSublista(nodoListaPrincipal *lista){
    nodoListaSecundaria *aux = lista->sublista;
    while(aux){
        cout<<aux->str;
        if(aux->sgte) cout<<" -> ";
        aux = aux->sgte;
    }
    cout<<endl;
    delete aux;
}

void imprimirDatosListaPrinc(nodoListaPrincipal *&lista){
    nodoListaPrincipal *aux = lista;
    while(aux){
        cout<<aux->dato;
        if(aux->sgte) cout<<" -> ";
        aux = aux->sgte;
    }
    cout<<endl;
    delete aux;
}


void insertarInicio(nodoListaPrincipal *&lista, int n){
    nodoListaPrincipal *aux = new nodoListaPrincipal();
    aux->dato = n;
    aux->sgte = NULL;
    if(lista == NULL){
        lista = aux;
    }else{
        aux->sgte = lista;
        lista = aux;
    }
}

void insertarFinal(nodoListaPrincipal *&lista, int n){
    nodoListaPrincipal *tmp = new nodoListaPrincipal();
    tmp->dato = n;
    tmp->sgte = NULL;
    if(lista == NULL){
        lista = tmp;
    }else{
        nodoListaPrincipal *aux = lista;
        while(aux->sgte != NULL){
            aux = aux->sgte;
        }
        aux->sgte = tmp;
    }
}

void insertarFinalSublista(nodoListaSecundaria *&sublista, char str[10]){
    nodoListaSecundaria *tmp = new nodoListaSecundaria();
    strcpy(tmp->str,str);
    tmp->sgte = NULL;
    if(sublista == NULL){
        sublista = tmp;
    }else{
        nodoListaSecundaria *aux = sublista;
        while(aux->sgte != NULL){
            aux = aux->sgte;
        }
        aux->sgte = tmp;
    }
}
