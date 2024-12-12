//
// Created by Enner on 6/12/2024.
//

#ifndef MATRIZDISPERSA_H
#define MATRIZDISPERSA_H

#include "NodoMatriz.h"
#include <iostream>

class Matriz {
private:
    //Cabecera horizontal (el noditos)
    NodoMatriz *cabeceraHorizontal;
    //Cabecera vertical (el noditos)
    NodoMatriz *cabeceraVertical;

public:
    //Constructor
    Matriz();

    //Procedimiento para saber si la matriz está vacia
    bool isVacia();

    //Las funciones para insertar los nodos
    NodoMatriz *cabeceraH(std::string elian);
    NodoMatriz *cabeceraV(std::string elian);

    //Funciones para insertar nodos en las cabeceras
    NodoMatriz *insertarCabeceraHorizontal(std::string elian);
    NodoMatriz *insertarCabeceraVertical(std::string elian);

    //Función para insertar un Valor
    void insertarValor(std::string elian, std::string cabeH, std::string cabeV);
    //Función para insertar un nodo al final
    void insertarAlFinal(NodoMatriz *valor, NodoMatriz *cabeH, NodoMatriz *cabeV);
    void insertarAlFinalHorizontal(NodoMatriz *valor, NodoMatriz *cabeH);
    void insertarAlMediaVertical(NodoMatriz *valor, NodoMatriz *vertical);
    void insertarAlMediaHorizontal(NodoMatriz *valor, NodoMatriz *horizontal);
    void insertarAlFinalVertical(NodoMatriz *valor, NodoMatriz *cabeH);

    //Funciones para saber si está presentes en las
    NodoMatriz *presenteEnCabeceraHorizontal(NodoMatriz *nodo);
    NodoMatriz *presenteEnCabeceraVertical(NodoMatriz *nodo);

    //Funciones para graficar la matriz
    std::string generarDotGrafica();
    void generarReporteMatriz();

    //Función para encontrar un usurio
    NodoMatriz *encontrarUsuarioPorEmpresaDepartamento(std::string empresa, std::string departamento, std::string user, std::string contrasena);

    //Funciones para saber si está más abajo o más a la derecha
    bool masAbajo(NodoMatriz *cabeV, std::string cabH);
    bool masDerecha(NodoMatriz *cabeH, std::string cabV);

    //Funcion para buscar un nodo
    NodoMatriz* encontrarUsuario(std::string constrasena,std::string user);
    NodoMatriz* buscarNodoEnPosicion(NodoMatriz* cabeH,NodoMatriz* cabeV);
    NodoMatriz* obtenerNodo(std::string cabeH,std::string cabeV);

    //getters
    NodoMatriz* getCabeceraHorizontal();
    NodoMatriz* getCabeceraVertical();

    //setters
    void setCabeceraHorizontal(NodoMatriz *nodo);
    void setCabeceraVertical(NodoMatriz *nodo);


};

#endif //MATRIZDISPERSA_H
