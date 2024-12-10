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

    //Funciones para insertar nodos en las cabeceras
    NodoMatriz *insertarCabeceraHorizontal(int elian);
    NodoMatriz *insertarCabeceraVertical(int elian);

    //Función para insertar un Valor
    void insertarValor(int elian, int cabeH, int cabeV);
    //Función para insertar un nodo al final
    void insertarAlFinal(NodoMatriz *valor, NodoMatriz *cabeH, NodoMatriz *cabeV);
    void insertarAlFinalHorizontal(NodoMatriz *valor, NodoMatriz *cabeH);
    void insertarAlMediaVertical(NodoMatriz *valor, NodoMatriz *vertical);
    void insertarAlMediaHorizontal(NodoMatriz *valor, NodoMatriz *horizontal);

    void insertarAlFinalVertical(NodoMatriz *valor, NodoMatriz *cabeH);

    NodoMatriz *presenteEnCabeceraHorizontal(NodoMatriz *nodo);
    NodoMatriz *presenteEnCabeceraVertical(NodoMatriz *nodo);

    //Funciones para saber si está más abajo o más a la derecha
    bool masAbajo(NodoMatriz *cabeV, int cabH);
    bool masDerecha(NodoMatriz *cabeH, int cabV);

};



#endif //MATRIZDISPERSA_H
