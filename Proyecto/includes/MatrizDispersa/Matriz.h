//
// Created by Enner on 6/12/2024.
//

#ifndef MATRIZDISPERSA_H
#define MATRIZDISPERSA_H

#include "Nodo.h"

class Matriz {
public:

    //Cabecera horizontal (el noditos)
    Nodo *cabeceraHorizontal;


    //Cabecera vertical (el noditos)
    Nodo *cabeceraVertical;

    //Constructor
    Matriz();

    //Método de la matriz
    bool isVacia();

    //Las funciones para insertar los nodos
    Nodo *cabeceraH(int elian);
    Nodo *cabeceraV(int elian);

    //Función para insertar un Valor
    void insertarValor(int elian, int cabeH, int cabeV);

    //Funciones para insertar nodos en las cabeceras
    Nodo *insertarCabeceraHorizontal(int elian);
    Nodo *insertarCabeceraVertical(int elian);

    //Función para insertar un nodo al final
    void insertarAlFinal(int elian, Nodo *cabeH, Nodo *cabeV);

    void insertarAlFinalHorizontal( int elian, Nodo *cabeH);
    void insertarAlMediaVertical(int elian, Nodo *cabeV);

    Nodo *presenteEnCabeceraHorizontal(Nodo *nodo);
    Nodo *presenteEnCabeceraVertical(Nodo *nodo);

};



#endif //MATRIZDISPERSA_H
