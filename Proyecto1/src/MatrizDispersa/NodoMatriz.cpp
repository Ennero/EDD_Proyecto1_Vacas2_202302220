//
// Created by Enner on 6/12/2024.
//
#include "../../includes/MatrizDispersa/NodoMatriz.h"


NodoMatriz::NodoMatriz(int elian){
    this->elian = elian;
    this->siguiente=nullptr;
    this->anterior=nullptr;
    this->adelante=nullptr;
    this->atras=nullptr;
    this->arriba=nullptr;
    this->abajo=nullptr;

}
