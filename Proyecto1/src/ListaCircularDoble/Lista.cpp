//
// Created by Enner on 8/12/2024.
//

#include "../../includes/ListaCircularDoble/Lista.h"
#include "../../includes/Transaccion.h"
#include <iostream>
#include <fstream>


//Constructor
Lista::Lista(){
    this->tamano = 0;
    this->inicio = nullptr;
    this->fin = nullptr;

}

//Destructor
Lista::~Lista(){
    delete this;
}
//getters y setter
int Lista::getTamano(){
    return this->tamano;
}


//Función para agregar los nuevos nodos
void Lista::agregarNodo(Transaccion *transaccion){
    NodoTransaccion *nuevo=new NodoTransaccion(transaccion);

    if (this->tamano <= 0){//Si es que no hay nada en la lista circular
        this->inicio=nuevo; //El inicio es igual al nodo nuevo
        this->fin=nuevo; //El final es igual al nodo nuevo
        nuevo->setAnterior(this->inicio); //El anterior del nodo nuevo es él mismo
        nuevo->setSiguiente(this->fin); //El siguiente del nodo nuevo es él mismo
    }else{
        this->fin->setSiguiente(nuevo);  // El último nodo apunta al nuevo
        nuevo->setAnterior(this->fin);   // El nuevo nodo apunta al anterior último
        nuevo->setSiguiente(this->inicio);  // El nuevo nodo apunta al inicio
        this->inicio->setAnterior(nuevo);   // El primer nodo apunta al nuevo como anterior
        this->fin = nuevo;  // El nuevo ahora es el final
    }
    this->tamano++; //Aumento el tamaño del nodo
}

NodoTransaccion Lista::obtenerNodoEnPosicion(int posicion){
    if (inicio == nullptr || inicio == fin) return nullptr;
    NodoTransaccion* aux=this->inicio;
    int contador=0;
    while (contador<posicion){
        aux=aux->getSiguiente();
        contador++;
    }
    return *aux;
}
//********************************************************************************************
//Función para odenar la lista de forma ascendente
void Lista::ordenarAscendente() {
    if (inicio == nullptr || inicio == fin) return; // Si está vacia o solo tiene una cosa
    NodoTransaccion* actual = inicio;//El nodo inicial
    while (actual != inicio->getSiguiente()){ //Mientras el actual no sea el siguiente del incio
        NodoTransaccion* min = actual; //El minimo es el actual
        NodoTransaccion* comparar = actual->getSiguiente(); //Y creo un nodo para comparar el siguiente
        // Encontrar el mínimo desde el nodo actual hasta el final
        while (comparar != inicio) {
            if (comparar->getTransaccion()->getIdTransaccion() < min->getTransaccion()->getIdTransaccion()) {
                min = comparar; //Si el que comparar es menor al minimo, entonces el minimo es el comparar
            }//Y se coloca en su posición
            comparar = comparar->getSiguiente(); //Ahora me posicion adelante
        }

        if (min != actual) {//Si el mínimo cambio durante el proceso
            Transaccion* temp = actual->getTransaccion();//Creo una transacción que será la misma que la siguiente del actual
            actual->setTransaccion(min->getTransaccion());//Y coloco en la posición actual el que era menor
            min->setTransaccion(temp);//Y donde estaba con el que se comparó el actual, se coloca el valor que era el actual
        }
        actual = actual->getSiguiente(); //Y continuo con el ciclo
    } ;
}
//Función para odenar la lista de forma ascendente
void Lista::ordenarDescendente() {
    if (inicio == nullptr || inicio == fin) return; // Si está vacia o solo tiene una cosa
    NodoTransaccion* actual = inicio;//El nodo inicial
    while (actual != inicio->getSiguiente()){ //Mientras el actual no sea el siguiente del incio
        NodoTransaccion* max = actual; //El minimo es el actual
        NodoTransaccion* comparar = actual->getSiguiente(); //Y creo un nodo para comparar el siguiente
        // Encontrar el maximo desde el nodo actual hasta el final
        while (comparar != inicio) {
            if (comparar->getTransaccion()->getIdTransaccion() > max->getTransaccion()->getIdTransaccion()) {
                max = comparar; //Si el que comparar es menor al maximo, entonces el minimo es el comparar
            }//Y se coloca en su posición
            comparar = comparar->getSiguiente(); //Ahora me posicion adelante
        }

        if (max != actual) {//Si el maximo cambio durante el proceso
            Transaccion* temp = actual->getTransaccion();//Creo una transacción que será la misma que la siguiente del actual
            actual->setTransaccion(max->getTransaccion());//Y coloco en la posición actual el que era mayor
            max->setTransaccion(temp);//Y donde estaba con el que se comparó el actual, se coloca el valor que era el actual
        }
        actual = actual->getSiguiente(); //Y continuo con el ciclo
    } ;
}
//********************************************************************************************
//Función para graficar la lista circular doblemente enlazada
void Lista::generarReporte(){
    if (inicio == nullptr || fin == nullptr) return; // Si no hay nada en la lista no se genera el reporte
    NodoTransaccion *aux = this->inicio; // Creo un nodo que recorrerá toda la lista
    std::string reporte = "digraph listita {\n";
    reporte += "rankdir=RL;node [shape=record, style=filled, fillcolor=lightblue, margin=0.2];\n";
    reporte += "edge [style=solid, color=blue];\n";
    reporte += "graph [ranksep=1.5, nodesep=1];\n";
    reporte += "graph [label=\"Reporte de Transacciones\", fontsize=20, fontcolor=black];\n";
    // Recorro la lista
    do {
        reporte += "\"" + aux->getTransaccion()->getIdTransaccion() + "\" [label=\"{";
        // Agregar los atributos que quieras mostrar
        reporte += "ID Transacción: " + aux->getTransaccion()->getIdTransaccion() + "\\l";
        reporte += "ID Activo: " + aux->getTransaccion()->getIdActivo() + "\\l";
        reporte += "Usuario: " + aux->getTransaccion()->getUsarioRentador() + "\\l";
        reporte += "Departamento: " + aux->getTransaccion()->getDepartamento() + "\\l";
        reporte += "Empresa: " + aux->getTransaccion()->getEmpresa() + "\\l";
        reporte += "Fecha: " + aux->getTransaccion()->getFecha() + "\\l";
        reporte += "Tiempo: " + aux->getTransaccion()->getTiempo() + "\\l";
        reporte += "}\"];\n";
        //Conecto los nodos
        if (aux->getSiguiente() != this->inicio->getSiguiente()) {
            reporte += "\"" + aux->getTransaccion()->getIdTransaccion() + "\" -> \"" +
                       aux->getSiguiente()->getTransaccion()->getIdTransaccion() + "\"[dir=both];\n";
        }
        aux = aux->getSiguiente();//Continuo con el ciclo
    }while (aux != this->inicio) ;
    reporte += "\"" + aux->getTransaccion()->getIdTransaccion() + "\" -> \"" +
                       aux->getSiguiente()->getTransaccion()->getIdTransaccion() + "\"[dir=both];\n";
    reporte += "}\n";//Cierro ciclos xd
    // Generar el archivo
    std::ofstream archivo("reporteListaCircular.dot");
    archivo << reporte;
    archivo.close();
    system("dot -Tpdf reporteListaCircular.dot -o reporteListaCircular.pdf && start reporteListaCircular.pdf");
}
