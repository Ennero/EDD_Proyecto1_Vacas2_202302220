//
// Created by Enner on 8/12/2024.
//

#include "../../includes/MatrizDispersa/Lista.h"
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
//La verdad este es inútil xd
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

void Lista::imprimirNodos() {
    if (inicio == nullptr || fin == nullptr) {
        std::cout << "No tiene activos rentados" << std::endl;
        return;
    }
    int contador = 1;
    NodoTransaccion* actual = inicio; // Nodo que recorrerá la lista
    do {
        // Imprime la información relevante
        std::cout<<"-----------------------------------------------------------" << std::endl;
        std::cout<<std::to_string(contador) << actual->getId()<< "-"<<actual->getNombre()<<"-"<<actual->getDescripcion()<<std::endl;
        actual = actual->getSiguiente(); // Avanzar al siguiente nodo
    } while (actual != inicio); // Continuar hasta regresar al inicio

    std::cout << "-----------------------------------------------------------" << std::endl;
}



//********************************************************************************************
//Función para odenar la lista de forma ascendente
void Lista::ordenarAscendente() {
    // Verificar si la lista está vacía o tiene un solo elemento
    if (inicio == nullptr || inicio == fin) return; //Si no hay nada entones no hago nada
    bool cambio;//Bandera
    NodoTransaccion* actual;//El nodo actual que se estará moviendo
    NodoTransaccion* ultimo = nullptr; //El ultimo nodo revisado
    do {//Mientras no haya cambios (se ejecuta al primero)
        cambio = false;//El cambio se vuelve false
        actual = inicio;//El actual es el inicio
        do {//Ciclo que funciona hasta que se termine la lista
            NodoTransaccion* siguiente = actual->getSiguiente();//Creo un nodo para comparar el actual

            // Comparación de los ID de transacciones
            if (actual->getTransaccion()->getIdTransaccion() > siguiente->getTransaccion()->getIdTransaccion()) {
                Transaccion* temp = actual->getTransaccion();// Intercambio de transacciones
                actual->setTransaccion(siguiente->getTransaccion());
                siguiente->setTransaccion(temp);
                cambio = true;//Hubo cambio así que se vuelve tru
            }
            actual = siguiente;// Me muevo
        } while (actual != ultimo && actual->getSiguiente() != inicio);
        ultimo = actual;// Actualizo el último nodo
    } while (cambio);
}
//Función para odenar la lista de forma ascendente
void Lista::ordenarDescendente(){
    // Verificar si la lista está vacía o tiene un solo elemento
    if (inicio == nullptr || inicio == fin) return; //Si no hay nada entones no hago nada
    bool cambio;//Bandera
    NodoTransaccion* actual;//El nodo actual que se estará moviendo
    NodoTransaccion* ultimo = nullptr; //El ultimo nodo revisado
    do {//Mientras no haya cambios (se ejecuta al primero)
        cambio = false;//El cambio se vuelve false
        actual = inicio;//El actual es el inicio
        do {//Ciclo que funciona hasta que se termine la lista
            NodoTransaccion* siguiente = actual->getSiguiente();//Creo un nodo para comparar el actual

            // Comparación de los ID de transacciones
            if (actual->getTransaccion()->getIdTransaccion() < siguiente->getTransaccion()->getIdTransaccion()) {
                Transaccion* temp = actual->getTransaccion();// Intercambio de transacciones
                actual->setTransaccion(siguiente->getTransaccion());
                siguiente->setTransaccion(temp);
                cambio = true;//Hubo cambio así que se vuelve tru
            }
            actual = siguiente;// Me muevo
        } while (actual != ultimo && actual->getSiguiente() != inicio);
        ultimo = actual;// Actualizo el último nodo
    } while (cambio);
}

//********************************************************************************************
//Función para graficar la lista circular doblemente enlazada
void Lista::generarReporte(){
    if (inicio == nullptr || fin == nullptr) return; // Si no hay nada en la lista no se genera el reporte
    NodoTransaccion *aux = this->inicio; // Creo un nodo que recorrerá toda la lista
    std::string reporte = "digraph listita {\n";
    reporte += "rankdir=LR;node [shape=record, style=filled, fillcolor=lightblue, margin=0.2];\n";
    reporte += "edge [style=solid, color=blue];\n";
    reporte += "graph [ranksep=1.5, nodesep=1];\n";
    reporte += "graph [label=\"Reporte de Transacciones\", fontsize=20, fontcolor=black];\n";
    // Recorro la lista
    bool banderita=true;
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
        }else if (banderita){
            reporte += "\"" + aux->getTransaccion()->getIdTransaccion() + "\" -> \"" +
                       aux->getSiguiente()->getTransaccion()->getIdTransaccion() + "\"[dir=both];\n";
        }
        banderita=false;
        aux = aux->getSiguiente();//Continuo con el ciclo
    }while (aux != this->inicio) ;

    reporte += "}\n";//Cierro ciclos xd
    // Generar el archivo
    std::ofstream archivo("reporteListaCircular.dot");
    archivo << reporte;
    archivo.close();
    system("dot -Tpdf reporteListaCircular.dot -o reporteListaCircular.pdf && start reporteListaCircular.pdf");
}



//************************************************************************
//Función para agregar los nuevos nodos
void Lista::agregarNodoActivo(std::string id,std::string descripcion,std::string nombre){
    NodoTransaccion *nuevo = new NodoTransaccion(descripcion,id,nombre);
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