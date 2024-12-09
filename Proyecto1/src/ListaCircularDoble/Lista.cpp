//
// Created by Enner on 8/12/2024.
//

#include "../../includes/ListaCircularDoble/Lista.h"
#include "../../includes/Transaccion.h"

//Constructor
Lista::Lista(){
    this->tamano = 0;
    this->inicio = nullptr;
    this->fin = nullptr;

}

//Destructor
Lista::~Lista(){
    delete this;
}

//Función para agregar los nuevos nodos
void Lista::agregarNodo(Transaccion *transaccion){
    NodoTransaccion *nuevo=new NodoTransaccion(transaccion);

    if (this->tamano <= 0){//Si es que no hay nada en la lista circular
        this->inicio=nuevo; //El inicio es igual al nodo nuevo
        this->fin=nuevo; //El final es igual al nodo nuevo
        nuevo->setAnterior(this->inicio); //El anterior del nodo nuevo es él mismo
        nuevo->setSiguiente(this->fin); //El siguiente del nodo nuevo es él mismo
    }else{
        NodoTransaccion* aux=this->inicio; //Creo un nodo auxiliar
        while (aux->getSiguiente()!=this->fin){ //Mientras el siguiente no sea el fin, llegar al fin
            aux=aux->getSiguiente();
        }
        aux->setSiguiente(nuevo); //El siguiente del último nodo es el nuevo
        nuevo->setSiguiente(this->inicio); //El siguiente del nuevo nodo es el primero
        nuevo->setAnterior(aux); //El anterior del nuevo es el auxiliar
        this->fin=nuevo; //El nuevo final es el nuevo
        this->inicio->setAnterior(nuevo); //El anterior del nodo del inicio es el nuevo
    }
    this->tamano++; //Aumento el tamaño del nodo
}

NodoTransaccion Lista::obtenerNodoEnPosicion(int posicion){
    NodoTransaccion* aux=this->inicio;
    int contador=0;
    while (contador<posicion){
        aux=aux->getSiguiente();
        contador++;
    }
    return *aux;
}


void Lista::generarReporte(){

    if (this->ascendente){//Si se quiere ordenado de forma ascendente



    }else{//Si NO está ordenado de forma ascendente


    }



}

