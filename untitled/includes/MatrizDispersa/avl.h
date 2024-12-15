//
// Created by Enner on 12/12/2024.
//

#ifndef AVL_H
#define AVL_H

#include <iostream>
#include "Activo.h"
class AVL{
private:
    Activo* activo;
    int factorEquilibrio;
    AVL *derecha;
    AVL *izquierda;
public:
    AVL(std::string id, std::string nombre, std::string descripcion);

    //getters
    Activo *getActivo();
    int getFactorEquilibrio();
    AVL*& getDerecha();
    AVL*& getIzquierda();
    //setters
    void setActivo(Activo* activo);
    void setFactorEquilibrio(int factorEquilibrio);
    void setIzquierda(AVL *izquierda);
    void setDerecha(AVL *derecha);


};

#endif //AVL_H
