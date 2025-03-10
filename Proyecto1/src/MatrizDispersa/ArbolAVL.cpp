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
void ArbolAVL::insertar(std::string id,std::string nombre,std::string descripcion){
    AVL *nodo=new AVL(id,nombre,descripcion);

    insertar(nodo,this->raiz);
}
void ArbolAVL::insertar(AVL *valor,AVL *&raiz){
    //Cuando inserto cuando no hay nada
    if (raiz==nullptr){
        raiz=valor;
        raiz->setFactorEquilibrio(0);//Le asigno el factor de equilibrio
        return;
    }
    if (valor->getActivo()->getId() < raiz->getActivo()->getId()){//Inserto el valor en la izquierda
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
//Funciones para generar la gráfica de un solo usuario
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
    }//Función para generar el string .dot
// Nueva función para generar el contenido del dot
std::string ArbolAVL::generarContenidoDot(AVL* nodo) {
    if (nodo == nullptr) return "";

    std::string contenido;//Contenido del dot

    // Agrego el nodo actual
    contenido += "    \"" + nodo->getActivo()->getId() + "\" [label=\""+ "ID:" +nodo->getActivo()->getId() + "\nActivo:" + nodo->getActivo()->getNombre()+"\"";
    if (nodo->getActivo()->getTiempoRenta() >0){
        contenido += "  , style=filled, fillcolor=red";
    }
    contenido+=  "];\n";

    // Verifico el hijo izquierdo
    if (nodo->getIzquierda() != nullptr) {
        // Creo la conexión del anterior con el actual
        contenido += "    \"" + nodo->getActivo()->getId() + "\" -> \"" + nodo->getIzquierda()->getActivo()->getId() + "\";\n";
        contenido += generarContenidoDot(nodo->getIzquierda());// Proceso el subárbol izquierdo con recursividad
    }

    // Verifico el hijo izquierdo
    if (nodo->getDerecha() != nullptr) {
        // Creo la conexión del anterior con el actual
        contenido += "    \"" + nodo->getActivo()->getId() + "\" -> \"" + nodo->getDerecha()->getActivo()->getId() + "\";\n";
        contenido += generarContenidoDot(nodo->getDerecha());//Proceso el subárbol izquierdo con recursividad
    }
    return contenido;//retorno el contenido
}

//*************************************************************************************************************************************
//Función para generar el string .dot para la grafica de todos
std::string ArbolAVL::generarDotContenidoActivos(){
    std::string graficaAVL="";
    graficaAVL += generarContenidoDot(this->raiz);//mando la raiz
    return graficaAVL;
}

//*********************************************************************************************************************************************
//Función para eliminar pública
void ArbolAVL::eliminar(std::string valor){
    eliminar(valor,this->raiz);
}
//Función que se iría llamando a sí misma
void ArbolAVL::eliminar(std::string valor, AVL *&nodo) {
    if (nodo == nullptr) return; // Caso en el que el nodo no tiene nada

    if (valor < nodo->getActivo()->getId()) {//Si el valor es menor, va al lado izquierdo
        eliminar(valor, nodo->getIzquierda());//Busco en el lado izquierdo el eliminarlo
    } else if (valor > nodo->getActivo()->getId()) {//Si el valor es mayor, va al lado derecho
        eliminar(valor, nodo->getDerecha());//Busco en el lado derecho el eliminarlo
    } else {
        //Aquí es por si encuenta el activo a eliminar
        if (nodo->getActivo()->getTiempoRenta() >0){
            std::cout<<"No se puede eliminar un activo en renta"<<std::endl;
            return;
        }
        std::cout<<"Eliminando activo con id: "<<nodo->getActivo()->getId()<<std::endl;
        // Con el nodo ya encontrado, comienzo con el proceso de eliminación.
        if (esHoja(nodo)) {
            // Caso 1: si es hoja
            delete nodo;//Solo por liberar memoria la verdad xd
            nodo = nullptr;
        } else if (nodo->getIzquierda() == nullptr) {
            // Caso 2: Solo tiene un hijo derecho
            AVL *temp = nodo;
            nodo = nodo->getDerecha();
            delete temp; //leí que es bueno eliminar para liberar espacio xd
        } else if (nodo->getDerecha() == nullptr) {
            // Caso 3: Solo tiene un hijo izquierdo
            AVL *temp = nodo;
            nodo = nodo->getIzquierda();
            delete temp;
        } else {
            // Caso 4: Tiene dos hijos nodos
            AVL* nodoMasDerecho = masALaDerecha(nodo->getIzquierda());//Busco el nodo más a la dercha
            //nodo->setActivo(nodoMasDerecho->getActivo()); //El nodo que se queire eliminar se reemplaza con el nodo mas a la derecha

            //probando mover solo los activos para no mover los nodos
            //Activo* activoTemp=nodo->getActivo();
            nodo->setActivo(nodoMasDerecho->getActivo());
            //nodoMasDerecho->setActivo(activoTemp);
            eliminar(nodoMasDerecho->getActivo()->getId(),nodo->getIzquierda());
            /*
            if (nodo->getActivo()->getTiempoRenta() >0){
                std::cout<<"El activo no puede ser eliminado, ya que se encuentra en renta"<<std::endl;
                return;
            }
            eliminar(nodoMasDerecho->getActivo()->getId(), nodo->getIzquierda()); //Elimino el nodo más a la derecha
            std::cout<<"Activo eliminado con exito"<<std::endl;*/

        }
        std::cout<<"Activo eliminado con exito"<<std::endl;
    }
    //mejor creé una función para balancear
    if (nodo != nullptr) {
        balancear(nodo);
    }

}
//Función para balancear
void ArbolAVL::balancear(AVL *nodo) {
    nodo->setFactorEquilibrio(factorEquilibrio(nodo));//Calculo el factor de equilibrio
    // Verifico si el nodo está desbalanceado.
    if (nodo->getFactorEquilibrio() < -1) {//Si el factor de equilibrio es mayor a 1
        if (nodo->getIzquierda()->getFactorEquilibrio() > 0) {//Si el subárbol izquierdo es más pesado
            rotacionDerechaIzquierda(nodo);//Roto la izquierda y luego la derecha
        } else {//Sino
            rotacionIzquierda(nodo);//Solo roto la derecha
        }
    } else if (nodo->getFactorEquilibrio() > 1) {//Si el factor de equilibrio es mayor a 1
        // Subárbol derecho es más pesado.
        if (nodo->getDerecha()->getFactorEquilibrio() < 0) {//Si el subárbol izquierdo es más pesado
            rotacionIzquierdaDerecha(nodo);//Roto la izquierda y luego la derecha
        } else {//Sino
            rotacionDerecha(nodo);//Solo roto la derecha
        }
    }
}

AVL* ArbolAVL::masALaDerecha(AVL* nodo) {
    // Encuentra el nodo más a la derecha.
    if (nodo->getDerecha() == nullptr) return nodo;
    return masALaDerecha(nodo->getDerecha());
}
//Función para saber si el último nodo
bool ArbolAVL::esHoja(AVL* nodo) {
    return nodo->getIzquierda() == nullptr && nodo->getDerecha() == nullptr;
}
//Función para buscar pública
AVL* ArbolAVL::buscar(std::string id) {
    return buscar(id, this->raiz); // Llama a la función principal
}
//Función para buscar un nodo
AVL* ArbolAVL::buscar(std::string id, AVL* nodo) {
    if (nodo == nullptr) return nullptr;//Si no hay nada no hago nada xd

    if (id == nodo->getActivo()->getId()) {// Si el nodo actual coincide con el id buscado
        return nodo;
    } else if (id < nodo->getActivo()->getId()) {// Ahora paso al lado izquierdo y lo vuelvo a llamar
        return buscar(id, nodo->getIzquierda());
    } else {
        return buscar(id, nodo->getDerecha());// Sino me paso al lado derecho y lo vuelvo a llamar
    }
}

//***************************************************************************************************
//Funciones para imprimir activos
void ArbolAVL::imprimirActivos() {
    imprimirRevursivo(this->raiz);
}
//La función recursiva
void ArbolAVL::imprimirRevursivo(AVL* nodo) {
    if (nodo == nullptr) return;//Si no tiene nada no imprimo nada xd
    //Primero me voy por le lado izquierdo
    imprimirRevursivo(nodo->getIzquierda());

    // Imprimo la información del nodo
    std::cout << "ID: " << nodo->getActivo()->getId()<< ", Nombre: " << nodo->getActivo()->getNombre()
              << ", Descripcion: " << nodo->getActivo()->getDescripcion();
    if (nodo->getActivo()->getTiempoRenta() >0){
        std::cout << " (en renta por " << nodo->getActivo()->getTiempoRenta() << " dias)";
    }
    std::cout<<std::endl;
    // Por último me voy al lado derecho
    imprimirRevursivo(nodo->getDerecha());
}


//*************************************************************************************************************
//Función para modificar nodo
void ArbolAVL::modificar(std::string id, std::string nuevoNombre,std::string nuevaDescripcion){
    AVL* nodoModificado = buscar(id);
    if (nodoModificado != nullptr) {
        if (nodoModificado->getActivo()->getTiempoRenta() >0){
            std::cout << "No se puede modificar un activo en renta\n";
        }else{
            nodoModificado->getActivo()->setNombre(nuevoNombre);
            nodoModificado->getActivo()->setDescripcion(nuevaDescripcion);
        }
    } else {
        std::cout << "Nodo con ID " << id << " no encontrado\n";
    }
}
//**************************************************************************************************************
void ArbolAVL::imprimirActivosDisponibles(){
    imprimirActivosDisponiblesRecursivo(this->raiz);
}
void ArbolAVL::imprimirActivosDisponiblesRecursivo(AVL* nodo){
    if (nodo == nullptr) return;//Si no tiene nada no imprimo nada xd
    //Primero me voy por el lado izquierdo
    imprimirActivosDisponiblesRecursivo(nodo->getIzquierda());

    // Imprimo la información del nodo
    if (nodo->getActivo()->getTiempoRenta() <=0){
        std::cout << "ID: " << nodo->getActivo()->getId()<< ", Nombre: " << nodo->getActivo()->getNombre()
              << ", Descripcion: " << nodo->getActivo()->getDescripcion() << std::endl;

    // Por último me voy al lado derecho
    }
    imprimirActivosDisponiblesRecursivo(nodo->getDerecha());
}
//**************************************************************************************************
void ArbolAVL::imprimirActivosNoDisponibles(){
    imprimirActivosNoDisponiblesRecursivo(this->raiz);
}
void ArbolAVL::imprimirActivosNoDisponiblesRecursivo(AVL* nodo){
    if (nodo == nullptr) return;//Si no tiene nada no imprimo nada xd
    //Primero me voy por el lado izquierdo
    imprimirActivosNoDisponiblesRecursivo(nodo->getIzquierda());

    // Imprimo la información del nodo
    if (nodo->getActivo()->getTiempoRenta() >0){
        std::cout << "ID: " << nodo->getActivo()->getId()<< ", Nombre: " << nodo->getActivo()->getNombre()
              << ", Descripcion: " << nodo->getActivo()->getDescripcion() <<", Tiempo de renta: " <<nodo->getActivo()->getTiempoRenta()<<" dias"<<std::endl;

        // Por último me voy al lado derecho
    }
    imprimirActivosNoDisponiblesRecursivo(nodo->getDerecha());
}

//***************************************************************************************************

void ArbolAVL::mostrarActivosRentados(){
    imprimirActivosDisponiblesRecursivo(this->raiz);
}
void ArbolAVL::imprimirActivosRentadosRecursivo(AVL* nodo){
    if (nodo == nullptr) return;//Si no tiene nada no imprimo nada xd
    //Primero me voy por el lado izquierdo
    imprimirActivosDisponiblesRecursivo(nodo->getIzquierda());

    // Imprimo la información del nodo
    if (nodo->getActivo()->getTiempoRenta() >0){
        std::cout << "ID: " << nodo->getActivo()->getId()<< ", Nombre: " << nodo->getActivo()->getNombre()
              << ", Descripción: " << nodo->getActivo()->getDescripcion() << std::endl;

        // Por último me voy al lado derecho
    }
    imprimirActivosDisponiblesRecursivo(nodo->getDerecha());
}

//*******************************************************************************
//Funciones para saber si hay activos que están siendo rentados
bool ArbolAVL::hayActivosRentados(){
    return hayActivosRentadosRecursivo(this->raiz);
}
bool ArbolAVL::hayActivosRentadosRecursivo(AVL* nodo){
    if (nodo==nullptr) return false;//Si no tiene nada no hago nada xd
    if (nodo->getActivo()->getTiempoRenta() >0) return true;//Si no tiene nada no imprimo nada xd
    //Primero me voy por el lado izquierdo
    bool activoIzquierdo = hayActivosRentadosRecursivo(nodo->getIzquierda());
    if (activoIzquierdo) return true;
    // Por último me voy al lado derecho
    bool activoDerecho =hayActivosRentadosRecursivo(nodo->getDerecha());
    if (activoDerecho) return true;
    return false;
}