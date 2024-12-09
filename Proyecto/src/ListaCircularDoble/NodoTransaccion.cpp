//
// Created by Enner on 8/12/2024.
//

#include "../../includes/ListaCircularDoble/NodoTransaccion.h"

//Constructor
NodoTransaccion::NodoTransaccion(Transaccion* transaccion){
    this->transaccion = transaccion;
    this->siguiente = nullptr;
    this->anterior = nullptr;
}
//Destructor
NodoTransaccion::~NodoTransaccion(){
    transaccion = nullptr;
    siguiente = nullptr;
    anterior = nullptr;
}




//Getteres y Setters
Transaccion* NodoTransaccion::getTransaccion(){
    return this->transaccion;
}
void NodoTransaccion::setTransaccion(Transaccion* transaccion){
    this->transaccion = transaccion;
}
void NodoTransaccion::setSiguiente(NodoTransaccion* siguiente){
    this->siguiente = siguiente;
}
NodoTransaccion* NodoTransaccion::getSiguiente(){
    return this->siguiente;
}
void NodoTransaccion::setAnterior(NodoTransaccion* anterior){
    this->anterior = anterior;
}
NodoTransaccion* NodoTransaccion::getAnterior(){
    return this->anterior;
}


