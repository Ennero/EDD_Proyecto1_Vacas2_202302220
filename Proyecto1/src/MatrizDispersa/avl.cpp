//
// Created by Enner on 12/12/2024.
//
#include "../../includes/MatrizDispersa/avl.h"
#include <iostream>

//Constructor que no sé por qué tiene que ir así :(
AVL::AVL(std::string id, std::string nombre, std::string descripcion){
    this->activo = new Activo(id, nombre, descripcion);
    this->izquierda = nullptr;
    this->derecha = nullptr;
    this->factorEquilibrio = 0;
}


//getters
Activo* AVL::getActivo() {
    return this->activo;
}
int AVL::getFactorEquilibrio() {
    return this->factorEquilibrio;
}

AVL*& AVL::getDerecha() {
    return this->derecha;
}

AVL*& AVL::getIzquierda() {
    return this->izquierda;
}

//setters
void AVL::setActivo(Activo* activo) {
    this->activo = activo;
}
void AVL::setFactorEquilibrio(int factorEquilibrio) {
    this->factorEquilibrio = factorEquilibrio;
}
void AVL::setIzquierda(AVL *izquierda) {
    this->izquierda = izquierda;
}
void AVL::setDerecha(AVL *derecha) {
    this->derecha = derecha;
}
