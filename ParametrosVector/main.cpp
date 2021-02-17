#include <iostream>
#include <conio.h>

using namespace std;

void cuadrado(int vec[], int);  //Pongo corchetes vacios para indicar que es un vector
void muestra(int vec[], int);
void OrdenarVector(int *numeros, int);
void ImprimirVector(int *numeros, int);

int main(){
    const int TAM = 5;
    int vect[TAM] = {1,2,3,4,5};
    int num[TAM] = {0,3,2,1,4};

    cuadrado(vect, TAM);
    muestra(vect, TAM);
    OrdenarVector(num, TAM);
    ImprimirVector(num, TAM);

    return 0;
}

void cuadrado (int vec[], int tam){
    for(int i=0; i<tam ; i++){
        vec[i]*= vec[i];
    }
}
void muestra(int vec[], int tam){
    for(int i=0; i<tam ; i++){
        cout << vec[i]<<" ";
    }
}

void OrdenarVector(int *numeros, int TAM){  //Metodo Burbuja
    for(int i=0;i<TAM;i++){
        for(int j=0;j<TAM;j++){
            if(numeros[j] > numeros[j+i]){
                int aux = numeros[j];
                numeros[j] = numeros[j+1];
                numeros[j+1] = aux;
            }
        }
    }
}

void ImprimirVector(int *numeros, int TAM){
    cout << endl;
    for(int i=0;i<TAM;i++){
        cout << numeros[i]<<" ";
    }
}
