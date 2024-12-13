//
// Created by Enner on 8/12/2024.
//

#ifndef LISTA_H
#define LISTA_H

//para que el sucio compilador lo entienda :<
class NodoTransaccion;
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
    //Función para generar el reporte de la lista circular doblemente enlazada
    void generarReporte();
    //Función para ordenar de forma ascendente la lista circular doblemente enlazada
    void ordenarAscendente();
    //Función para ordenar de forma descendente la lista circular doblemente enlazada
    void ordenarDescendente();
    //getters y setters
    NodoTransaccion* getInicio();
    void setInicio(NodoTransaccion*);
    NodoTransaccion* getFin();
    void setFin(NodoTransaccion*);
};


#endif //LISTA_H