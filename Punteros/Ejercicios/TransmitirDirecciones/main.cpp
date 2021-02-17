#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

void intercambio(float *, float *);

int main(){
    float n1=1.1, n2=2.2;

    cout<<"Numero 1: "<<n1<<endl;
    cout<<"Numero 2: "<<n2<<endl;

    intercambio(&n1,&n2);

    cout<<"Numero 1: "<<n1<<endl;
    cout<<"Numero 2: "<<n2<<endl;
}

void intercambio(float *dir1,float *dir2){
    float aux;

    //Intercambiar valores de variables
    aux = *dir1;
    *dir1 = *dir2;
    *dir2 = aux;
}
