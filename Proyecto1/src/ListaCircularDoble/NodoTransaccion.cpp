//
// Created by Enner on 8/12/2024.
//

#include "../../includes/ListaCircularDoble/NodoTransaccion.h"

//Constructor
NodoTransaccion::NodoTransaccion(Transaccion* transaccion){
    this->transaccion = transaccion;
    this->siguiente = nullptr;
    this->anterior = nullptr;
    this->descripcion="";
    this->id="";
    this->nombre="";
}

//Constructor para los activos
NodoTransaccion::NodoTransaccion(std::string descripcion, std::string id,std::string nombre){
    this->descripcion=descripcion;
    this->id=id;
    this->nombre=nombre;
    this->transaccion = nullptr;
    this->siguiente = nullptr;
    this->anterior = nullptr;
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

//Aquí irán las funciones destinadas a almacenar los activos*********************************************************************************************

std::string NodoTransaccion::getDescripcion(){
    return this->descripcion;
}

std::string NodoTransaccion::getId(){
    return this->id;
}

std::string NodoTransaccion::getNombre(){
    return this->nombre;
}

void NodoTransaccion::setDescripcion(std::string descripcion){
    this->descripcion = descripcion;
}
void NodoTransaccion::setId(std::string id){
    this->id = id;
}
void NodoTransaccion::setNombre(std::string nombre){
    this->nombre = nombre;
}


