//
// Created by Enner on 6/12/2024.
//

#ifndef NODO_H
#define NODO_H



class NodoMatriz {

public:
    int elian;

    NodoMatriz *siguiente;
    NodoMatriz *anterior;
    NodoMatriz *arriba;
    NodoMatriz *abajo;
    NodoMatriz *adelante;
    NodoMatriz *atras;
    //Constructor
    NodoMatriz(int elian);

};

#endif //NODO_H
