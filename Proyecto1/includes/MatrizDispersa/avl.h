//
// Created by Enner on 12/12/2024.
//

#ifndef AVL_H
#define AVL_H

#include "../MatrizDispersa/Activo.h"
#include <iostream>
class AVL{
private:
    Activo activo;
    std::string id;
    int factorEquilibrio;
    AVL *derecha;
    AVL *izquierda;
public:
    AVL(std::string id);

    //getters
    std::string getId();
    Activo getActivo();
    int getFactorEquilibrio();
    AVL*& getDerecha();
    AVL*& getIzquierda();
    //setters
    void setId(std::string id);
    void setActivo(Activo activo);
    void setFactorEquilibrio(int factorEquilibrio);
    void setIzquierda(AVL *izquierda);
    void setDerecha(AVL *derecha);
};





#endif //AVL_H
