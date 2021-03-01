#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

struct nodo{
    int dato;
    nodo *sgte;
};

nodo* union_listas(nodo*,nodo*);
void ImprimirLista(nodo*&);
void push(nodo*&, int);
void InsertarOrdenado(nodo*&,int );
nodo* interseccion_listas(nodo*,nodo*);
void insertarFinal(nodo*&,int);
nodo* BuscarEnLista(nodo*&,int);

int main(){
    nodo *lista = NULL;
    nodo *pila = NULL;
    nodo *list_union = NULL;
    nodo *list_intersec = NULL;

    push(pila,5);
    push(pila,9);
    push(pila,6);
    push(pila,29);
    push(lista,5);
    push(lista,99);
    push(lista,29);
    push(lista,104);

    cout<<endl<<"Lista: \t\t\t";
    ImprimirLista(lista);
    cout<<endl<<"Pila: \t\t\t";
    ImprimirLista(pila);

    list_union = union_listas(lista,pila);
    cout<<endl<<"Union de listas: \t";
    ImprimirLista(list_union);

    cout<<endl<<"Lista: \t\t\t";
    ImprimirLista(lista);
    cout<<endl<<"Pila: \t\t\t";
    ImprimirLista(pila);

    list_intersec = interseccion_listas(lista,pila);
    cout<<endl<<"Interseccion de listas: ";
    ImprimirLista(list_intersec);
}

nodo* union_listas(nodo* lista1, nodo* lista2){ //Al final de la primera lista ingresada, se inserta la segunda
    nodo *aux = NULL;

    while(lista1){
        push(aux,lista1->dato);
        lista1 = lista1->sgte;
    }while(lista2){
        push(aux,lista2->dato);
        lista2 = lista2->sgte;
    }
    return aux;
}

void insertarFinal(nodo *&lista, int n){
    nodo *tmp = new nodo();
    tmp->dato = n;
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

nodo* interseccion_listas(nodo *lista1, nodo* lista2){
    nodo *intersec = NULL;

    while(lista1){
        if(BuscarEnLista(intersec,lista1->dato) == NULL)
            InsertarOrdenado(intersec,lista1->dato);
        lista1=lista1->sgte;
    }

    while(lista2){
        if(BuscarEnLista(intersec,lista2->dato) == NULL)
            InsertarOrdenado(intersec,lista2->dato);
        lista2=lista2->sgte;
    }

    return intersec;
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

void push(nodo *&pila, int x){
    nodo *aux = new nodo();
    aux -> dato = x;
    aux -> sgte = pila;
    pila = aux;
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

/**
    Ejercicio 1:

    Desarrolle los siguientes Subprogramas:
    a-	Una función que retorne una lista sin orden a partir de la Unión de una pila y una lista.
    b-	Un procedimiento que genere una lista ordenada a partir de la INTERSECCION de 2 listas.

    Defina usted las estructuras de los nodos de la manera que considere más conveniente y detallar.

**/


1)
nodo* union_listas(nodo *lista, nodo* cola){
    nodo *intersec = NULL;
	int aux;

    while(lista){
		aux = pop(lista);
		InsertarOrdenado(intersec,aux);
    }

    while(cola){
		aux = pop(cola);
		InsertarOrdenado(intersec,aux);
    }
    return union;
}

2)

void intersec_lista_vect (nodo* lista, int vec[], nodo*&lista_intersec){
	while(lista){
		for(int i=0; i<50; i++){
			if(vec[i] == lista.dato){
				InsertarOrdenado(lista_out,lista.dato);
			}
		}
	}
}