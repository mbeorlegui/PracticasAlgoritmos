#include <iostream>
#include <conio.h>

using namespace std;

//Último en entrar es el primero en salir

struct nodo{
    int info;
    nodo *sgte;
};

void push (nodo *&, int);
int pop (nodo *&);

int main(){
    nodo *pila = NULL;  //Inicializo siempre en NULL

    push(pila,5);
    push(pila,9);
    push(pila,6);
    push(pila,29);

    while(pila){
        cout<<pop(pila)<<" ";   // 29 6 9 5 0
    }
}

void push(nodo *&pila, int x){  //Lo paso por referencia (&) porque la pila va a cambiar en el transcurso de la funcion
    nodo *aux = new nodo();
    aux -> info = x;
    aux -> sgte = pila;
    pila = aux;
}

int pop(nodo *&pila){
    nodo *aux = pila;   //Copio la pila en un nodo auxiliar
    int x;
    pila = aux -> sgte;
    x = aux -> info;
    delete aux;
    return x;
}
