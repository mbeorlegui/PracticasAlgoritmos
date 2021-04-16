#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct registro{
    char nombre[34];
    int legajo;
    int division;
};

struct nodo{
    nodo* sgte;
    registro dato;
};

void ImprimirLista(nodo*&);
void InsertarOrdenadoLegajo(nodo*&,registro);

int main(){
    nodo *lista = NULL;
    FILE *f = fopen("ARCHA.bin","rb+");
    registro a={"Matias",100,103},b={"Nicolas",3,103},c={"Jose",2,103};
    registro d={"Ricardo",5,103},e={"Anastasia",6,103};

    if(f == NULL){
        cout<<"No se pudo abrir/generar el archivo..."<<endl;
    }

    if(f){
        while(fread(&a,sizeof(registro),1,f)){
            InsertarOrdenadoLegajo(lista,a);
        }
        fclose(f);
    }

    ImprimirLista(lista);

    return 0;
}

void InsertarOrdenadoLegajo(nodo *&lista, registro n){
    nodo *nuevo = new nodo();
    nuevo->dato = n;

    nodo *aux1 = lista;
    nodo *aux2;

    while(aux1 && aux1->dato.legajo<n.legajo){
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
void InsertarOrdenadoVentas(nodo *&lista, registro n){
    
	if(strcmp(lista->dato.sector,”C”){
		nodo *nuevo = new nodo();
		nuevo->dato = n;

		nodo *aux1 = lista;
		nodo *aux2;

		while(aux1 && aux1->dato.ventas<n.ventas){
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
}

void ImprimirLista(nodo*&lista){
    nodo* aux = lista;
    cout<<endl;
    while(aux){
        cout<<aux->dato.legajo<<"/"<<aux->dato.division<<"/"<<aux->dato.nombre;
        if(aux->sgte) cout<<" -> ";
        aux = aux->sgte;
    }
    cout<<endl;
    delete aux;
}


/**

Dado un archivo de registros de alumnos ARCHA sin ningun orden, donde cada registro contiene:
    a) Apellido y Nombre del alumno (34 caracteres)
    b) Numero de legajo (6 digitos)
    c) Division asignada (1 a 100)
-   Se debe desarrollar el algoritmo y codificacion del programa que genere un archivo ARCHL
    igual al anterior pero ordenado por numero de legajo.

Se tiene un archivo de ventas anuales de los empleados de una empresa multinacional Ventas.dat (sin Orden), 
con el siguiente registro:

ID de Empleado: 999999
Ventas Anuales: 99999,99
Sector: ‘C’, ‘P’ ó ‘S’ (Consultoría, Productos o Soporte)

Se pide:
Armar y mostrar una lista ordenada por Ventas Anuales sólo para el caso que el 
empleado pertenece al sector de consultoría.

**/
