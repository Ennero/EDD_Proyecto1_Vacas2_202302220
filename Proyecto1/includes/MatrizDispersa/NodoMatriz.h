// NodoMatriz.h
#ifndef NODO_MATRIZ_H
#define NODO_MATRIZ_H

class NodoMatriz {

public:
    int elian;

    NodoMatriz *siguiente;
    NodoMatriz *anterior;
    NodoMatriz *arriba;
    NodoMatriz *abajo;
    NodoMatriz *adelante;
    NodoMatriz *atras;

    // Constructor
    NodoMatriz(int elian);
};

#endif // NODO_MATRIZ_H
