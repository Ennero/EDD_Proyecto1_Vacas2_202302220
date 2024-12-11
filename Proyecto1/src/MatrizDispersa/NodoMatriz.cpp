//
// Created by Enner on 6/12/2024.
//
#include "../../includes/MatrizDispersa/NodoMatriz.h"
#include "../../includes/MatrizDispersa/Usuario.h"

#include <iostream>
//Constructor para el encabezado
NodoMatriz::NodoMatriz(std::string user){
    Usuario *cabecera=new Usuario(user);
    this->usuario=cabecera;
    this->siguiente=nullptr;
    this->anterior=nullptr;
    this->adelante=nullptr;
    this->atras=nullptr;
    this->arriba=nullptr;
    this->abajo=nullptr;
    this->nombre=user;
}
//Constructor para el usuario
NodoMatriz::NodoMatriz(Usuario* usuario, std::string nombre){
    this->siguiente=nullptr;
    this->anterior=nullptr;
    this->adelante=nullptr;
    this->atras=nullptr;
    this->arriba=nullptr;
    this->abajo=nullptr;
    this->usuario=usuario;
    this->nombre=nombre;

}

//getters
NodoMatriz* NodoMatriz::getAbajo(){
    return this->abajo;
}
NodoMatriz* NodoMatriz::getAnterior(){
    return this->anterior;
}
NodoMatriz* NodoMatriz::getAdelante(){
    return this->adelante;
}
NodoMatriz* NodoMatriz::getSiguiente(){
    return this->siguiente;
}
NodoMatriz* NodoMatriz::getArriba(){
    return this->arriba;
}
NodoMatriz* NodoMatriz::getAtras(){
    return this->atras;
}
Usuario* NodoMatriz::getUsuario(){
    return this->usuario;
}
std::string NodoMatriz::getNombre(){
    return this->nombre;
}
//setters
void NodoMatriz::setNombre(std::string nombre){
    this->nombre=nombre;
}
void NodoMatriz::setUsuario(Usuario *usuario){
    this->usuario=usuario;
}
void NodoMatriz::setAnterior(NodoMatriz* anterior){
    this->anterior=anterior;
}
void NodoMatriz::setAbajo(NodoMatriz* abajo){
    this->abajo=abajo;
}
void NodoMatriz::setAdelante(NodoMatriz* adelante){
    this->adelante=adelante;
}
void NodoMatriz::setArriba(NodoMatriz* arriba){
    this->arriba=arriba;
}
void NodoMatriz::setAtras(NodoMatriz* atras){
    this->atras=atras;
}
void NodoMatriz::setSiguiente(NodoMatriz* siguiente){
    this->siguiente=siguiente;
}


