1)
	Desarrolle los siguientes Subprogramas: 
	a- Una función que retorne una lista ordenada a partir de la Unión de una pila y una cola.
	b- Un procedimiento que genere una lista ordenada a partir de la INTERSECCION de 1 Lista y un vector de 50 posiciones. 
	 
	Defina usted las estructuras de los nodos de la manera que considere más conveniente y detallar.

a-

-
//Declaracion de datos
struct nodo{
	int dato;
	nodo* sgte;
}
nodo* lista = NULL;
nodo* cola = NULL;

//Funcion:
nodo* union_EE(nodo* lista, nodo* cola){
	nodo *lista_union = NULL;
	int aux;
	while(lista){
		aux = pop(lista);
		InsertarOrdenado(lista_union, aux);
	}
	while(cola){
		aux = pop(lista);
		InsertarOrdenado(lista_union,aux);
	}
	return lista_union;
}


b-

//Declaracion:
struct nodo{
	int dato;
	nodo* sgte;
}
int vec[50];
nodo* lista_intersec = NULL;

//Funcion
void intersec_lista_vect (nodo* lista, int vec[], nodo*&lista_intersec){
	while(lista){
		for(int i=0; i<50; i++){
			if(vec[i] == lista.dato){
				InsertarOrdenado(lista_out,lista.dato);
			}
		}
	}
}

2)
	Se tiene un archivo de ventas anuales de los empleados de una empresa multinacional Ventas.dat (sin Orden), con el siguiente registro:

	ID de Empleado: 999999
	Ventas Anuales: 99999,99
	Sector: ‘C’, ‘P’ ó ‘S’ (Consultoría, Productos o Soporte)

	Se pide:
	Armar y mostrar una lista ordenada por Ventas Anuales sólo para el caso que el empleado pertenece al sector de consultoría.

	Nota: Sólo puede leer 1 vez el archivo.
	
struct registro{
	long int id;
	float ventas;
	char sector[1];
}

struct nodo{
	registro dato;
	nodo* sgte;
}

int main(){
	nodo *lista = NULL;
	registro = a;
	FILE *f = fopen(“ventas.dat”,”rb”);
	if(f == NULL){
       		 cout<<"No se pudo abrir el archivo..."<<endl;
    	}else{
       	 	while(fread(&a,sizeof(registro),1,f)){
				if(strcmp(lista->dato.sector,”C”){
					InsertarOrdenado(lista,a);
				}
        	}
    fclose(f);
    }
}

//Funcion InsertarOrdenadoVentas
void InsertarOrdenadoVentas(nodo *&lista, registro n){
	nodo *nuevo = new nodo();
	nuevo->dato = n;
	nodo *aux1 = lista;
	nodo *aux2;
	while(aux1 && aux1->dato.ventas<n.ventas){
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






