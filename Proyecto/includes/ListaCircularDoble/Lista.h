//
// Created by Enner on 8/12/2024.
//

#ifndef LISTA_H
#define LISTA_H

#include "NodoTransaccion.h"

class Lista{
private:
    NodoTransaccion* inicio;
    NodoTransaccion* fin;
    int tamano;
    bool ascendente=true;

public:
    //Constructor
    Lista();
    //Destructor
    ~Lista();

    void agregarNodo(Transaccion *transaccion);
    NodoTransaccion obtenerNodoEnPosicion(int posicion);

    int getTamano();
    void incrementarTamano();

    void generarReporte();

    //getters y setters
    NodoTransaccion* getInicio();
    void setInicio(NodoTransaccion*);
    NodoTransaccion* getFin();
    void setFin(NodoTransaccion*);
};


#endif //LISTA_H
