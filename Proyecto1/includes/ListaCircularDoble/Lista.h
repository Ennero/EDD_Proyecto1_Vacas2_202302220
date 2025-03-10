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
    //Función para agregar una transaccion
    void agregarNodo(Transaccion *transaccion);
    //Función para agregar un activo
    void agregarNodoActivo(std::string id, std::string descripcion, std::string nombre);
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

    //Función para imprimir los activos de alguien
    void imprimirNodos();

    //Función para eliminar un nodo por su ID
    void eliminarNodoPorId(std::string id);

    //Función para crear un reporte de los activos rentados por un usuario
    void generarReporteActivosRentados(std::string user);


};


#endif //LISTA_H