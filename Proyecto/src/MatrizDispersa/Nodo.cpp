//
// Created by Enner on 6/12/2024.
//
#include "../../includes/MatrizDispersa/Nodo.h"


Nodo::Nodo(int elian){
    this->elian = elian;
    this->siguiente=nullptr;
    this->anterior=nullptr;
    this->adelante=nullptr;
    this->atras=nullptr;
    this->arriba=nullptr;
    this->abajo=nullptr;

}


// Getters
int Nodo::getElian() const {
    return elian;
}
Nodo* Nodo::getSiguiente() const {
    return siguiente;
}
Nodo* Nodo::getAnterior() const {
    return anterior;
}
Nodo* Nodo::getArriba() const {
    return arriba;
}
Nodo* Nodo::getAbajo() const {
    return abajo;
}
Nodo* Nodo::getAdelante() const {
    return adelante;
}
Nodo* Nodo::getAtras() const {
    return atras;
}

// Setters
void Nodo::setSiguiente(Nodo* nodo) {
    siguiente = nodo;
}
void Nodo::setAnterior(Nodo* nodo) {
    anterior = nodo;
}
void Nodo::setArriba(Nodo* nodo) {
    arriba = nodo;
}
void Nodo::setAbajo(Nodo* nodo) {
    abajo = nodo;
}
void Nodo::setAdelante(Nodo* nodo) {
    adelante = nodo;
}
void Nodo::setAtras(Nodo* nodo) {
    atras = nodo;
}

