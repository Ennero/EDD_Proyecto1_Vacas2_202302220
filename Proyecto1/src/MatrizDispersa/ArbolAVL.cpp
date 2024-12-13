//
// Created by Enner on 12/12/2024.
//

#include "../../includes/MatrizDispersa/ArbolAVL.h"
#include <iostream>
#include <ostream>
#include <fstream>

ArbolAVL::ArbolAVL(){
    this->raiz=nullptr;
}
//Funcion para insertar nodos
void ArbolAVL::insertar(std::string valor){
    AVL *nodo=new AVL(valor);
    insertar(&*nodo,this->raiz);
}
void ArbolAVL::insertar(AVL *valor,AVL *&raiz){
    //Cuando inserto cuando no hay nada
    if (raiz==nullptr){
        raiz=valor;
        raiz->setFactorEquilibrio(0);//Le asigno el factor de equilibrio
        return;
    }
    if (valor->getId() < raiz->getId()){//Inserto el valor en la izquierda
        insertar(valor,raiz->getIzquierda());
    }else{
        insertar(valor,raiz->getDerecha()); //Inserto el valor en la derecha
    }
    //**********************************************************************************************************
    raiz->setFactorEquilibrio(factorEquilibrio(raiz));
    //Balanceo del arbol
    if (raiz->getFactorEquilibrio() < -1) {//Si el factor de equilibrio es menor a -1
        if (raiz->getIzquierda() && raiz->getIzquierda()->getFactorEquilibrio() > 0) {//Si el nodo izquierdo tiene un factor de equilibrio positivo
            rotacionDerechaIzquierda(raiz);//Rotación para la derecha y luego para la izquierda
        } else {//Si el nodo izquierdo no tiene un factor de equilibrio positivo
            rotacionIzquierda(raiz);//Rotación para la izquierda
        }
    } else if (raiz->getFactorEquilibrio() > 1) {//Si el factor de equilibrio es menor a -1
        if (raiz->getDerecha() && raiz->getDerecha()->getFactorEquilibrio() < 0) { //Si el nodo derecho tiene un factor de equilibrio negativo
            rotacionIzquierdaDerecha(raiz);//Rotación para la izquierda y luego para la derecha
        } else {
            rotacionDerecha(raiz);//Rotación para la derecha
        }
    }
}
//*************************************************************************************************************************************
//Rotación para la izquierda y luego para la izquierda
void ArbolAVL::rotacionDerechaIzquierda(AVL*& nodo){
    rotacionDerecha(nodo->getIzquierda());
    rotacionIzquierda(nodo);
}
//Rotación para la derecha y luego para la derecha
void ArbolAVL::rotacionIzquierdaDerecha(AVL*& nodo){
    rotacionIzquierda(nodo->getDerecha());
    rotacionDerecha(nodo);
}
//*************************************************************************************************************************************
void ArbolAVL::rotacionDerecha(AVL*& nodo){
    //Aquí creo un auxiliar
    AVL *aux=nodo->getDerecha();
    nodo->setDerecha(aux->getIzquierda());
    //El izquierdo será el auxiliar del derecho
    aux->setIzquierda(nodo);
    nodo=aux;
    //Reasigno los factores de equilibirio de los nodos
    if (nodo->getIzquierda() != nullptr) {//Si no hay nada nulo, coloca el factor de equilibrio
        nodo->getIzquierda()->setFactorEquilibrio(factorEquilibrio(nodo->getIzquierda()));
    }
    if (nodo->getDerecha() != nullptr) {//Si no hay nada nulo, coloca el factor de equilibrio
        nodo->getDerecha()->setFactorEquilibrio(factorEquilibrio(nodo->getDerecha()));
    }
    /*
    nodo->setFactorEquilibrio(factorEquilibrio(nodo));
    nodo->getIzquierda()->setFactorEquilibrio(factorEquilibrio(nodo->getIzquierda()));//Reasigno el factor de equilibrio al izquierdo
    if (nodo->getDerecha()==nullptr) return;//Si el nodo derecho no tiene nada entonces no regreso nada
    nodo->getDerecha()->setFactorEquilibrio(factorEquilibrio(nodo->getDerecha()));//Reasigno el factor de equilibrio al derecho
    */
}
//Rotación cuando está acumulado a la izquierda
void ArbolAVL::rotacionIzquierda(AVL *&nodo){
    //Aquí creo un auxiliar
    AVL *aux=nodo->getIzquierda();
    nodo->setIzquierda(aux->getDerecha());//El nuevo izquierdo es el derecho
    //El izquierdo será el auxiliar del derecho
    aux->setDerecha(nodo);
    nodo=aux;
    //Reasigno los factores de equilibirio de los nodos
    nodo->setFactorEquilibrio(factorEquilibrio(nodo));
    if (nodo->getDerecha() != nullptr) {
        nodo->getDerecha()->setFactorEquilibrio(factorEquilibrio(nodo->getDerecha()));
    }
    if (nodo->getIzquierda() != nullptr) {
        nodo->getIzquierda()->setFactorEquilibrio(factorEquilibrio(nodo->getIzquierda()));
    }
    /*
    nodo->setFactorEquilibrio(factorEquilibrio(nodo));
    nodo->getDerecha()->setFactorEquilibrio(factorEquilibrio(nodo->getDerecha()));
    if (nodo->getIzquierda()==nullptr) return;//Si el nodo izquierdo no tiene nada entonces no regreso nada
    nodo->getIzquierda()->setFactorEquilibrio(factorEquilibrio(nodo->getIzquierda()));*/
}
//*************************************************************************************************************************************
int ArbolAVL::alturaMaxima(AVL* nodo){//Función para obtener la altura maxima
    if (nodo==nullptr){//Si no tiene nada
        return 0;//La altura es 0
    }
    //Busco la altura del lado derecho
    int hIzquierda=alturaMaxima(nodo->getIzquierda());
    //Busco la altura del lado izquierdo
    int hDerecha=alturaMaxima(nodo->getDerecha());
    //Retorno alguno de los dos
    return hIzquierda>hDerecha ? hIzquierda +1 : hDerecha + 1;
}
int ArbolAVL::factorEquilibrio(AVL *nodo){//Función para obtener el factor de equilibrio (lo derecho menos lo izquierdo)

    if (nodo==nullptr) return 0;
    int alturaDerecha = alturaMaxima(nodo->getDerecha());
    int alturaIzquierda = alturaMaxima(nodo->getIzquierda());
    return alturaDerecha - alturaIzquierda;
}
//Getterss y setters
AVL* ArbolAVL::getRaiz(){
    return raiz;
}
void ArbolAVL::setRaiz(AVL* avl){
    raiz = avl;
}

//*************************************************************************************************************************************
//Funciones para generar la gráfica
    void ArbolAVL::generarDotGrafica() {
        std::string graficaAVL="digraph AVLTree {\n";
        graficaAVL+= "    node [shape=circle,style=filled, fillcolor=lightblue, margin=0.2];\nedge [style=solid, color=blue];\n graph [ranksep=1.5, nodesep=1];graph [label=\"Reporte de Activos\", fontsize=20, fontcolor=black];\n"; // Los nodos serán circulitos
        graficaAVL += generarContenidoDot(this->raiz);//mando la raiz
        graficaAVL += "}\n";

        // Genero el archivo
        std::ofstream archivo("reporteArbolAVL.dot");
        archivo<<graficaAVL;
        archivo.close();
        //Creo un comando para ejecutar el graphviz y crear el pdf
        system("dot -Tpdf reporteArbolAVL.dot -o reporteArbolAVL.pdf && start reporteArbolAVL.pdf");
    }
    //Función para generar el string .dot
// Nueva función para generar el contenido del dot
std::string ArbolAVL::generarContenidoDot(AVL* nodo) {
    if (nodo == nullptr) return "";

    std::string contenido;//Contenido del dot

    // Agrego el nodo actual
    contenido += "    \"" + nodo->getActivo().getId() + "\" [label=\"" + nodo->getActivo().getId() + "\"];\n";

    // Verifico el hijo izquierdo
    if (nodo->getIzquierda() != nullptr) {
        // Creo la conexión del anterior con el actual
        contenido += "    \"" + nodo->getActivo().getId() + "\" -> \"" + nodo->getIzquierda()->getActivo().getId() + "\";\n";
        contenido += generarContenidoDot(nodo->getIzquierda());// Proceso el subárbol izquierdo con recursividad
    }

    // Verifico el hijo izquierdo
    if (nodo->getDerecha() != nullptr) {
        // Creo la conexión del anterior con el actual
        contenido += "    \"" + nodo->getActivo().getId() + "\" -> \"" + nodo->getDerecha()->getActivo().getId() + "\";\n";
        contenido += generarContenidoDot(nodo->getDerecha());//Proceso el subárbol izquierdo con recursividad
    }
    return contenido;//retorno el contenido
}


