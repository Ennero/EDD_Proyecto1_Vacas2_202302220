//
// Created by Enner on 6/12/2024.
//

#ifndef NODO_H
#define NODO_H



class Nodo {
int elian;

private:
    Nodo *siguiente;
    Nodo *anterior;
    Nodo *arriba;
    Nodo *abajo;
    Nodo *adelante;
    Nodo *atras;
public:
    //Constructor
    Nodo(int elian);

    //Destructor
    ~Nodo();

    //getters
    int getElian() const;

    Nodo* getSiguiente() const;
    Nodo* getAnterior() const;
    Nodo* getArriba() const;
    Nodo* getAbajo() const;
    Nodo* getAdelante() const;
    Nodo* getAtras() const;

    // Setters
    void setSiguiente(Nodo* nodo);
    void setAnterior(Nodo* nodo);
    void setArriba(Nodo* nodo);
    void setAbajo(Nodo* nodo);
    void setAdelante(Nodo* nodo);
    void setAtras(Nodo* nodo);


};



#endif //NODO_H
