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

    //Estos son para los activos rentados
    std::string id;
    std::string descripcion;
    std::string nombre;

public:
    //Constructor
    NodoTransaccion(Transaccion* transaccion);
    //Destructor
    ~NodoTransaccion();

    //Constructor para los activos rentados
    NodoTransaccion(std::string id, std::string descripcion, std::string nombre);

    void mostrarTransaccion();

    //Getters y Setters
    std::string getId();
    std::string getDescripcion();
    std::string getNombre();

    void setId(std::string id);
    void setDescripcion(std::string descripcion);
    void setNombre(std::string nombre);
    Transaccion* getTransaccion();
    void setTransaccion(Transaccion* transaccion);
    NodoTransaccion* getAnterior();
    void setAnterior(NodoTransaccion* anterior);
    NodoTransaccion* getSiguiente();
    void setSiguiente(NodoTransaccion* siguiente);

};

#endif //NODO_H