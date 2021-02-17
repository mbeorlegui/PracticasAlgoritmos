#include <iostream>
#include <conio.h>
using namespace std;

void valNuevo(int&, int&);
/*
    Paso el valor por referencia, o sea indico en qu� espacio
    en memoria se encuentra dicha variable para que podamos imprimir
    o cambiar el valor de esa variable
*/

void calcular(int, int, int&, int&);
/*
    El este ejemplo se muestra c�mo devolver 2 valores
    en una funci�n utilizando el paso de valor por referencia
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
    dentro de la funci�n
    */

    return 0;
}

void valNuevo(int& x, int& y){  //Paso la direcci�n de memoria
    cout<< "El valor del primer numero es: "<<x<<endl;
    cout<< "El valor del segundo numero es: "<<y<<endl;

    x=100;      //Sobreescribo la informaci�n en dicha direcci�n de memoria
    y=100;

}

void calcular(int num1, int num2, int& prod, int& sum){
    prod = num1 * num2;
    sum = num1 + num2;
}
