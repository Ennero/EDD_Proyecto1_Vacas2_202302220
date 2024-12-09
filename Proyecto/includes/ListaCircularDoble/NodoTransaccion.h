//
// Created by Enner on 8/12/2024.
//


#ifndef NODO_H
#define NODO_H

#include "../Transaccion.h"

class NodoTransaccion{
private:
    NodoTransaccion* siguiente;
    NodoTransaccion* anterior;
    Transaccion* transaccion;
public:
    //Constructor
    NodoTransaccion(Transaccion* transaccion);
    //Destructor
    ~NodoTransaccion();

    void *mostrarTransaccion();

    //Getters y Setters
    Transaccion* getTransaccion();
    void setTransaccion(Transaccion* transaccion);
    NodoTransaccion* getAnterior();
    void setAnterior(NodoTransaccion* anterior);
    NodoTransaccion* getSiguiente();
    void setSiguiente(NodoTransaccion* siguiente);
};

#endif //NODO_H