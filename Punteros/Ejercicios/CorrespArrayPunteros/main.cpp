#include <iostream>
#include <conio.h>

using namespace std;

int main(){
    int numeros[] = {1,2,3,4,5};
    int *dir_numeros;

    dir_numeros = &numeros[0];
    dir_numeros = numeros;      //Es lo mismo que lo de arriba

    for(int i=0;i<5;i++){
        cout<<"Elemento del vector ["<<i<<"]: "<<*dir_numeros++<<endl;
        cout<<"Direccion de memoria: "<<dir_numeros<<endl<<endl;
    }
}
