#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

struct casos{
    int mes;
    char TipoCaso[1];    // H - I - R
};

struct MAX_PAIS{
    char nombre[30];
    long int habitantes;
    casos cas;
}paises[cantPaises];

/**

    Archivo "ParteDiario.Dat" con el nombre del pais,
    el numero de mes, numero de dia, cantidad de casos
    de un tipo, tipo de cantidad (H-I-R). Sin ordenar.

**/


//  Prototipo de funcion Cargar

void Cargar(FILE*, MAX_PAIS[]);

//  Definicion de la funcion Cargar:

void Cargar(FILE* f, MAX_PAIS paises[]){
    f = fopen("ParteDiario.Dat","rb");
    MAX_PAIS a;
    int i = 0;

    if(f){
        while(fread(&a,sizeof(MAX_PAIS),1,f)){
            paises[i] = aux;
            i++;
        }
    }else{
        cout<<"No se pudo abrir/generar el archivo..."<<endl;
    }

    fclose(f);
}

/** Función listar **/
//  Prototipo
tipoLista listar(MAX_PAIS[]);

//Invocacion
tipoLista listar(MAX_PAIS paises[cantPaises]);
