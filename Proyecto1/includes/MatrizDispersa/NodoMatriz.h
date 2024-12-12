// NodoMatriz.h
#ifndef NODO_MATRIZ_H
#define NODO_MATRIZ_H

#include<iostream>
#include "../../includes/MatrizDispersa/Usuario.h"

class NodoMatriz {

private:
    std::string nombre;
    Usuario *usuario;
    NodoMatriz *siguiente;
    NodoMatriz *anterior;
    NodoMatriz *arriba;
    NodoMatriz *abajo;
    NodoMatriz *adelante;
    NodoMatriz *atras;

public:
    // Constructor para las cabeceras
    NodoMatriz(std::string nombre);
    // Constructor para los usuarios
    NodoMatriz(Usuario *usuario,std::string nombre);

    //funciones para colocar adelante o atras
    void insertarAdelante(NodoMatriz* nodo);
    void insertarAtras(NodoMatriz* nuevo);
    //getters
    Usuario* getUsuario();
    NodoMatriz* getSiguiente();
    NodoMatriz* getAnterior();
    NodoMatriz* getArriba();
    NodoMatriz* getAbajo();
    NodoMatriz* getAdelante();
    NodoMatriz* getAtras();
    std::string getNombre();
    //setters
    void setNombre(std::string nombre);
    void setUsuario(Usuario* usuario);
    void setSiguiente(NodoMatriz* siguiente);
    void setAnterior(NodoMatriz* anterior);
    void setArriba(NodoMatriz* arriba);
    void setAbajo(NodoMatriz* abajo);
    void setAdelante(NodoMatriz* adelante);
    void setAtras(NodoMatriz* atras);


};

#endif // NODO_MATRIZ_H
