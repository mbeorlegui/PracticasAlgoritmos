1. Realice la declaración de la lista principal listaQ e inicialícela como una lista vacía. (1 pto)

NodoListaTipo1 *listaQ = NULL;

-------------------------------------------

2. 	Utilizando solamente punteros y declarando adecuadamente las variables auxiliares que requiera,
	realice los siguientes cambios (Aclaración: no es necesario usar ni desarrollar subprogramas de
	primitivas, directamente hacer los cambios solicitados sobre la estructura de datos):
		2.a. Agrege un nodo con dato1=”N1” dato2=”S8” entre los nodos que tienen el valor “S2” y “S3”.(3 ptos)
		2.b. Elimine el nodo con dato1= “N3” de la lista principal. (3 ptos)

2.a

NodoListaTipo1* aux = listaQ;

NodoListaTipo2* aux2 = new NodoListaTipo2();
aux2->info.dato1 = "N1";
aux2->info.dato2 = "S8";

NodoListaTipo2* aux3 = new NodoListaTipo2();

while (aux){
	if (strcmp(aux->info.dato1, “N1”)) {
		while(aux->sublista){
			if(strcmp(aux->sublista->info.dato2,"S2")){
				aux3 = aux->sublista->sgte;
				aux2->ant = aux->sublista;
				aux2->sgte = aux3;
			}
			aux->sublista = aux->sublista->sgte;
		}
	}
	aux = aux->sgte;
}

-------------------------------------------

2.b

NodoListaTipo1* aux = listaQ;
NodoListaTipo1* aux2 = new NodoListaTipo1();

while(aux) {
	if (strcmp(aux->info.dato1, “N2”)) {
		aux2 = aux->sgte->sgte;
		delete aux->sgte;
		aux->sgte = aux2;
	}
	aux = aux->sgte;
}

-------------------------------------------


3. 	Desarrolle un subprograma que reciba por parámetros la lista principal, una cadena de caracteres y
	busque el nodo de la lista principal cuyo valor de dato1 coincida con la cadena parámetro.
	Finalmente, que liste por pantalla los valores de dato2 de todos los nodos de la sublista
	correspondiente al nodo encontrado. (3 ptos)

void buscar(NodoListaTipo1 *lista, char cadena[3]){
	NodoListaTipo1 *aux = lista;
	
	while(aux){
		if(strcmp(aux->info.dato1, cadena)){
			//Me fijo cuales nodos de la LISTA PRINCIPAL coinciden con la cadena ingresada
			while(aux->sublista){
				int i=1;
				cout<<"Nodo "<<i<<": "<< aux->sublista->info.dato2<<endl;
				//Recorro toda la sublista y muestro dato2
				aux->sublista = aux->sublista->sgte 
			}
		}
		aux = aux->sgte;
	}
}






