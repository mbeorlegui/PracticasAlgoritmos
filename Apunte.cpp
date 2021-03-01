/*		Apuntes varios		*/

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
	
/*		Funciones utiles	*/

//De la catedra

void InsertarOrdenado(nodo *&lista,int n){
    nodo *nuevo = new nodo();
    nuevo->dato = n;

    nodo *aux1 = lista;
    nodo *aux2;

    while(aux1 && aux1->dato<n){
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

nodo* BuscarEnLista(nodo *&lista, int n){
    nodo* aux = lista;
    while(aux){
        if(aux->dato == n){
            return aux;
        }
        aux = aux->sgte;
    }
    return NULL;
}

void EliminarNodo(nodo *&lista, int n){
    nodo *aux = lista;
    nodo *anterior = NULL;

    while(aux && aux->dato != n){
        anterior = aux;
        aux = aux->sgte;
    }
    if(aux == NULL){
        cout<<"No existe el elemento"<<endl;
    }else if(anterior == NULL){
        lista = lista->sgte;
        delete aux;
    }else{
        anterior->sgte = aux->sgte;
        delete aux;
    }
}

//Mias
void insertarFinal(nodo *&lista, int n){
    nodo *tmp = new nodo();
    tmp->dato = n;
    tmp->sgte = NULL;
    if(!lista){
        lista = tmp;
    }else{
        nodo *aux = lista;
        while(aux->sgte != NULL){
            aux = aux->sgte;
        }
        aux->sgte = tmp;
    }
}

void insertarInicio(nodo *&lista, int n){
    nodo *aux = new nodo();
    aux->dato = n;
    aux->sgte = NULL;
    if(!lista){
        lista = aux;
    }else{
        aux->sgte = lista;
        lista = aux;
    }
}

void ImprimirLista(nodo*&lista){
    nodo* aux = lista;
    while(aux){
        cout<<aux->dato;
        if(aux->sgte) cout<<" -> ";
        aux = aux->sgte;
    }
    cout<<endl;
    delete aux;
}

int largoLista(nodo *lista){
    int i=0;
    while(lista){
        i++;
        lista=lista->sgte;
    }
    return i;
}


//Listas doblemente enlazadas

void insertarDatoPosicion(nodo *&lista, info n, int pos){
    nodo *tmp = new nodo();
    int i=0;
    tmp->dato = n;

    if(largoLista(lista) >= pos){
        if(pos == 0){
            insertarDatoInicio(lista,n);
        }else if(pos == largoLista(lista)){
            insertarDatoFinal(lista,n);
        }else{
            nodo *aux = lista;
            for(i=0;i<pos-1;i++){
                aux = aux->sgte;
            }
            nodo *aux2 = aux->sgte;
            aux->sgte = tmp;
            tmp->sgte = aux2;
            aux2->ant = tmp;
            tmp->ant = aux;
        }
    }else{
        cout<<endl<<"La lista no cuenta con suficientes elementos"<<endl;
    }
}

nodo* listaDEObtenerUltimo(nodo *lista){
    nodo *aux = lista;
    nodo *fin = NULL;
    int i=0;
    while(aux){
        if(aux->sgte == NULL){
            return aux;
        }
        aux = aux->sgte;
        i++;
    }
}
