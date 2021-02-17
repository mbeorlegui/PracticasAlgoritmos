#include <iostream>

using namespace std;

struct Obra{
    int idObra;
    char titu[100];
    Fecha fEstreno;
    int idTeatro;
};

struct Teatro{
    int idTeatro;
    char nom[50];
    int capacidad;
    int sectores;
};

struct Funcion{
    int idFuncion;
    int diaSemana;
    Hora hora;
};

struct Reserva{
    int idCli;
    int idObra;
    int dia;
    int sector;
    int cant;
};

/** PUNTO 1 **/
struct Nodo{
    Funcion func;
    Nodo *sgte;
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}


/** PUNTO 2 **/
void notificarRechazo(int idCli, bool acept);

void notificarRechazo(int idCli, bool acept){
    int pedido;
    Reserva res;

    if(acept == true){
        res = leerReserva();

        cout<<"Ingrese cantidades de localidades a adquirir: "<<endl;
        cin>>pedido;

        if(pedido < capacidadSector(res.idObra,res.sector)){
            cout<<"Se ha ACEPTADO la reserva de localidades"<<endl;
            acept = true;
        }else{
            cout<<"Se ha RECHAZADO la reserva de localidades ya que no hay lugares disponibles"<<endl;
            acept = false;
        }
    }
}

/** PUNTO 3 **/
void imprimirListado(void){
    Obra obra;
    int capTot;

    for(int i=0;i<1000,i++){
        capTot = 0;
        cout<<"Disponibilidad de obra numero "<<i+1<<": ";
        obra = getObra(i);
        for(int a=0;a<10;a++){
            capTot = capTot + capacidadSector(obra.idTeatro,a);
        }
        cout<<capTot<<endl;
    }
}

/**
    Se pide:

    1)  Codificar la estructura "Nodo", necesaria para implementar
        la lista enlazada de la funcion getFuncionesObra

    2)  Notificar a los clientes sobre la aceptacion o rechazo de
        sus reservas de localidades

    3)  Imprimir un listado que indique la cantidad de localidades
        rechazadas por cada obra, sin discriminar por funcion ni sector

**/
