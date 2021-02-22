#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

int main(){
    // "a" es una variable tipo FILE*, tipo archivo (es un handler)
    // Establece el canal entre el programa y el archivo (estable el canal del flujo de bytes)
    FILE *f = fopen ("nombre.extension","rb+"); //rb+ quiere decir que es un arhivo binario para lectura y escritura
    // Abre el archivo o lo crea si no est� creado
    // Veremos archivos homog�neos, esto es que el archivo tiene un s�lo tipo de dato

    if(f == NULL){
        cout<<"No se pudo abrir/generar el archivo..."<<endl;   //Para verificar si el archivo se abrio
        return 1;
    }

    int a = 88;
    fwrite(&a,sizeof(a),1,f);
    fwrite(&a,sizeof(a),1,f);
    fwrite(&a,sizeof(a),1,f);
    cout<<"Se ha escrito el archivo correctamente"<<endl;
    fclose(f);

    f = fopen("nombre.extension", "rb"); // Abro para leer lo antes escrito
    int i = 0;
    if(f){
        while(fread(&a,sizeof(int),1,f)){
            cout <<"Byte numero "<< i*sizeof(int) <<" = "<<a<<endl;
            i++;
        }
        fclose(f);
    }

    f = fopen("nombre.extension", "rb+");
    // Abro para escribir los numeros del 1 al 10 en el archivo desde el inicio


    for(int i=0;i<10;i++){
        fwrite(&i,sizeof(a),1,f);
    }
    fclose(f);

    cout<<endl<<"Leo nuevamente el archivo"<<endl;
    f = fopen("nombre.extension", "rb"); // Abro para leer lo antes escrito
    i = 0;
    if(f){
        while(fread(&a,sizeof(int),1,f)){
            cout <<"Byte numero "<< i*sizeof(int) <<" = "<<a<<endl;
            i++;
        }
        fclose(f);
    }


    //Cargar array con los primeros 10 valores de un archivo
    f = fopen("nombre.extension", "rb"); // Abro para leer lo antes escrito
    int j[10];
    if(f){
        fread(j,sizeof(int),10,f);
        fclose(f);
    }
    for(a=0;a<10;a++){
        cout<<endl<<"j["<<a<<"] = "<<j[a];
    }
    cout<<endl;

    //Que pasa si no se cuantos elementos tiene el archivo?
    int b[15];
    f = fopen("nombre.extension", "rb");
    i = 0;
    int aux;
    if(f){
        while(fread(&aux,sizeof(int),1,f)){
            b[i] = aux;
            cout<<endl<<"Pos ["<<i<<"] = "<<aux;
            i++;
        }
        fclose(f);
    }
    for(a=0;a<15;a++){
        cout<<endl<<"b["<<a<<"] = "<<b[a];
    }

    return 0;
}

/**

    El uso de archivos consta de 4 pasos:

    1)  Crear una variable para manejar el stream (de tipo FILE*)

    2)  Abrir el archivo utilizando la funcion fopen() y asignandole
        el resultado de la llamada a la variable creada en el punto 1

    3)  Hacer las diversas operaciones (leer, escribir, etc.)
        fwrite - fread - fseek

    4)  Cerrar el archivo utilizando fclose(f)

    -------------------------------------------------------------------------------

    fwrite(buffer, tama�o, # de registros, archivo);
    fread(buffer, tama�o, # de registros, archivo);

    buffer debe ir con un ampersand adelante (&) ->  Es una direccion de memoria
    Si es un array no es necesario, ya que el & esta implicito

    -------------------------------------------------------------------------------

    fseek: permite desplazarnos por el archivo

    int fseek(archivo, bytes_de_desplazamiento, origen);

    Tipos de origen:
        - SEEK_SET: desde el comienzo
        - SEEK_CUR: desde la posicion actual
        - SEEK_END: desde el final del archivo (requiere desplazamiento negativo)

    Devuelve:
        - 0: Si se pudo hacer el fseek
        - != 0: si hubo un error

    Ejemplo:
        fseek(f,3*sizeof(int),SEEK_SET); -> Se mueve 3 posiciones desde el origen, o sea que lee desde el 4to dato en adelante

    Luego de posicionarme en el archivo con fseek, puedo escribir encima de los registros siguientes

**/
