//
// Created by Enner on 12/12/2024.
//
#include "../../includes/MatrizDispersa/avl.h"
#include <iostream>
#include "../../includes/MatrizDispersa/Activo.h"

//Constructor que no sé por qué tiene que ir así :(
AVL::AVL(std::string id) : activo(id), factorEquilibrio(0), derecha(nullptr), izquierda(nullptr) {}

//getters
std::string AVL::getId(){
    return this->id;
}
Activo AVL::getActivo() {
    return this->activo;
}
int AVL::getFactorEquilibrio() {
    return this->factorEquilibrio;
}
AVL* &AVL::getDerecha() {
    return this->derecha;
}
AVL* &AVL::getIzquierda() {
    return this->izquierda;
}
//setters
void AVL::setId(std::string id) {
    this->id = id;
}
void AVL::setActivo(Activo activo) {
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
