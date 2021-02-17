#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

// Estructura FIFO: First In, First Out
// El primero en entrar es el primero en salir

struct Nodo{
	int info;
	Nodo *sgte;
};

//Prototipos de funcion
void agregarr(Nodo*&,Nodo*&,int);
int suprimirr(Nodo*&,Nodo*&,int);

int main(){
    Nodo *frente = NULL;
    Nodo *fin = NULL;
    int dato;

    agregarr(frente,fin,6);
    agregarr(frente,fin,8);
    agregarr(frente,fin,11);
    agregarr(frente,fin,15);

    while(frente){
        cout<<suprimirr(frente,fin,dato)<<endl; // 6 8 11 15
    }
    for(int i=0;i<1000000000000000;i++){
        agregarr(frente, fin, 6);
    }
}

void agregarr (Nodo *&p, Nodo *&q, int v){
    Nodo* nuevo = new Nodo();
    nuevo->info = v;
    nuevo->sgte = NULL;
    if(p == NULL){
        p = nuevo;
    }
    else{
        q->sgte = nuevo;
    }
    q = nuevo;
}

int suprimirr (Nodo* &p, Nodo* &q, int v){
    Nodo* aux = p;
    v = aux->info;
    p = aux->sgte;
    if (p==NULL){
        q=NULL;
    }
    delete aux;
    return v;
}
