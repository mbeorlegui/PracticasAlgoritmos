#include <iostream>
#include <conio.h>
using namespace std;

void valNuevo(int&, int&);
/*
    Paso el valor por referencia, o sea indico en qué espacio
    en memoria se encuentra dicha variable para que podamos imprimir
    o cambiar el valor de esa variable
*/

void calcular(int, int, int&, int&);
/*
    El este ejemplo se muestra cómo devolver 2 valores
    en una función utilizando el paso de valor por referencia
*/

int main(){
    int num1=2, num2=3, producto, suma;

    calcular(num1, num2, producto, suma);

    cout << "El producto es: "<< producto<< endl;
    cout << "La suma es: "<< suma<< endl;

    valNuevo(num1, num2);

    cout<< "El nuevo valor del primer numero es: "<<num1<< endl;
    cout<< "El nuevo valor del segundo numero es: "<<num2<< endl;

    /*
    Como vemos, al pasar la variable por referencia podemos modificar su valor
    dentro de la función
    */

    return 0;
}

void valNuevo(int& x, int& y){  //Paso la dirección de memoria
    cout<< "El valor del primer numero es: "<<x<<endl;
    cout<< "El valor del segundo numero es: "<<y<<endl;

    x=100;      //Sobreescribo la información en dicha dirección de memoria
    y=100;

}

void calcular(int num1, int num2, int& prod, int& sum){
    prod = num1 * num2;
    sum = num1 + num2;
}
