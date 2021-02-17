/*
    Puntero: variable que almacena la dirección de memoria de otra variable

    Declaración de punteros:
    &v = Dirección de memoria de la variable "v"
    *d = Variable cuya dirección está almacenada en "d"
*/
#include <iostream>
#include <conio.h>

using namespace std;

void analizParidad(int *);  //Tengo que indicar que lo que paso es una variable puntero de tipo int

int main(){
    int num, *dir_num; //Importante destacar que si la variable es entera, el puntero también debe serlo

    num = 26;
    dir_num = &num;
    //A la variable de tipo puntero (dir_num), le almaceno la dirección de la variable "num"

    cout<<"Numero: "<< num<< ", o tambien: "<< *dir_num<< endl;
    //Con el * le digo que me imprima lo que encuentre en la dirección de memoria que le pasé (dir_num)

    cout<<"Direccion de memoria: "<< &num<<", o tambien: "<< dir_num<<endl;
    //Puedo usar la dirección de memoria con el & o con un puntero

    analizParidad(dir_num);
}

void analizParidad(int *dir){
    if (*dir%2 == 0){
        cout<<endl<<"El numero "<<*dir<<" es par"<<endl;
        cout<<"La posicion de memoria es: "<<dir<<endl<<endl;
    }else{
        cout<<endl<<"El numero "<<*dir<<" es impar"<<endl;
        cout<<"La posicion de memoria es: "<<dir<<endl<<endl;
    }
}
