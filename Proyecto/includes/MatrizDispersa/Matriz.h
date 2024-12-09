//
// Created by Enner on 6/12/2024.
//

#ifndef MATRIZDISPERSA_H
#define MATRIZDISPERSA_H

#include "NodoMatriz.h"

class Matriz {
public:

    //Cabecera horizontal (el noditos)
    NodoMatriz *cabeceraHorizontal;
    //Cabecera vertical (el noditos)
    NodoMatriz *cabeceraVertical;

    //Constructor
    Matriz();

    //Método de la matriz
    bool isVacia();

    //Las funciones para insertar los nodos
    NodoMatriz *cabeceraH(int elian);
    NodoMatriz *cabeceraV(int elian);

    //Función para insertar un Valor
    void insertarValor(int elian, int cabeH, int cabeV);

    //Funciones para insertar nodos en las cabeceras
    NodoMatriz *insertarCabeceraHorizontal(int elian);
    NodoMatriz *insertarCabeceraVertical(int elian);

    //Función para insertar un nodo al final
    void insertarAlFinal(int elian, NodoMatriz *cabeH, NodoMatriz *cabeV);

    void insertarAlFinalHorizontal( int elian, NodoMatriz *cabeH);
    void insertarAlMediaVertical(int elian, NodoMatriz *cabeV);

    NodoMatriz *presenteEnCabeceraHorizontal(NodoMatriz *nodo);
    NodoMatriz *presenteEnCabeceraVertical(NodoMatriz *nodo);

};



#endif //MATRIZDISPERSA_H
