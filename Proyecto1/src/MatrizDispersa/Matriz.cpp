//
// Created by Enner on 6/12/2024.
//
#include "../../includes/MatrizDispersa/Matriz.h"

//Es solo el constructor de la matriz
Matriz::Matriz(){
    //Inicializando el contructor
    this->cabeceraHorizontal=nullptr;
    this->cabeceraVertical=nullptr;
}

//Función para moverme entre la cabecera horizontal
NodoMatriz *Matriz::cabeceraH(int elian){

    if (isVacia()){ //Si está vacia retorna algo vacío
        return nullptr;
    }

    //Creo el nodo auxiliar con el mismo valor del inicio de la cabecera
    NodoMatriz *aux = cabeceraHorizontal;

    //Si el siguiente no es nulo
    while (aux != nullptr ){
        if (aux->elian == elian){ //Y si el siguente tiene un valor
            return aux;//Retorno el valor encontrado
        }
        aux = aux->siguiente; //si no, busco en el siguiente nodo
    }
    return nullptr; //Si nada de nada entonces no retorno nada xd
}

//Función para moverme por la matriz vertical
NodoMatriz *Matriz::cabeceraV(int elian){

    //Si es que está vacía
    if (isVacia()){
        return nullptr;
    }

    //Se crea el auxiliar
    NodoMatriz *aux = cabeceraVertical;

    //Recorre los nodos verticales
    while (aux != nullptr ){
        if (aux->elian == elian){
            return aux; //Su encontró el dato que se busca, se retorna
        }
        aux = aux->abajo; //continua para abajo
    }//Si no hay nada entonces no manda nada xd
    return nullptr;
}

//Función para insertar una cabecera horizontal
NodoMatriz *Matriz::insertarCabeceraHorizontal(int elian){

    //Creo el nodo nuebo con el nuevo valor
    NodoMatriz *cabeceraNueva=new NodoMatriz(elian);

    //Si la cabecera no tiene nada, se coloca el inicio
    if (this->cabeceraHorizontal==nullptr){
        this->cabeceraHorizontal = cabeceraNueva; //Igualo la cabecera horizontal a la nueva
        return cabeceraNueva; //Retorno la nueva cabecera
    }
    NodoMatriz *aux=cabeceraHorizontal; //Si nada de lo anterior, creo el nodo auxiliar

    while (aux->siguiente != nullptr ){ //Me muevo hasta llegar al final
        aux=aux->siguiente;
    }
    aux->siguiente=cabeceraNueva; //Agrego la nueva cabecera al final
    cabeceraNueva->anterior=aux;//Conecto la cabecera nueva al anterior
    return cabeceraNueva;//Retorno la cabecera
}

//Función para insertar una cabecera vertical
NodoMatriz *Matriz::insertarCabeceraVertical(int elian){

    NodoMatriz *cabeceraNueva=new NodoMatriz(elian); //Crea un nodo nuevo

    if (this->cabeceraVertical==nullptr){ //Si no hay nada, la creo
        this->cabeceraVertical = cabeceraNueva;
        return cabeceraNueva;
    }
    NodoMatriz *aux=cabeceraVertical;//Si nada de lo anterior, creo una vertical

    while (aux->abajo != nullptr ){//Me muevo hasta la posición final
        aux=aux->abajo;
    }
    aux->abajo=cabeceraNueva; //Coloco la cabecera al final
    cabeceraNueva->arriba=aux; //Conecto la nueva cabecera
    return cabeceraNueva; //Retorno el nuevo nodo de la cabecera

}

void Matriz::insertarAlFinalHorizontal(int elian, NodoMatriz *cabeH){



}

void Matriz::insertarAlMediaVertical(int elian, NodoMatriz *cabeV){


}


//Función para insertar un nuevo valor
void Matriz::insertarValor(int elian, int cabeH, int cabeV){

    NodoMatriz *cabH=nullptr;
    NodoMatriz *cabV=nullptr;

    if (isVacia()){ //Si no hay nada en la matriz
        cabH=insertarCabeceraHorizontal(cabeH);//Se inserta una cabecera horizontal
        cabV=insertarCabeceraVertical(cabeV);//Se inserta una cabecera vertical

        insertarAlFinal(elian,cabH,cabV); //Se coloca todo al final
    }
    //Aquí solicito las cabeceras
    cabH=cabeceraH(cabeH);
    cabV=cabeceraV(cabeV);

    //Si no hay cabecera horizontal
    if (cabH==nullptr){
        //La inserto
        cabH=insertarCabeceraHorizontal(cabeH);
        insertarAlFinal(elian,cabH,cabV);
    }
    //Si no hay cabecera vertical
    if (cabV==nullptr){
        //La inserto
        cabV=insertarCabeceraVertical(cabeV);
        insertarAlFinal(elian,cabH,cabV);

    }

}

void Matriz::insertarAlFinal(int elian, NodoMatriz* cabeH, NodoMatriz* cabeV){

    NodoMatriz *usuarioNuevo= new NodoMatriz(elian); //Creo el nuevo Nodo

    //Creo los dos auxiliares de las cabeceras
    NodoMatriz *auxH= cabeH;
    NodoMatriz *auxV= cabeV;

    //Llego hasta el último nodo de la cabecera horizontal
    while (auxH->abajo != nullptr){
        auxH=auxH->abajo;
    }
    //Contecto la cabecera con el nuevo usuario
    auxH->abajo=usuarioNuevo;
    usuarioNuevo->arriba=auxH;

    //Lo muevo al final
    while (auxV->siguiente!=nullptr){
        auxV=auxV->siguiente;
    }

    //Conecto :)
    auxV->siguiente=usuarioNuevo;
    usuarioNuevo->anterior=auxV;
}

//Funciones para saber si están presentes en sus respectivas cabeceras
NodoMatriz *Matriz::presenteEnCabeceraHorizontal(NodoMatriz *nodo){

    //El auxiliar es el nodo que se manda
    NodoMatriz *aux=nodo;
    while (aux->arriba!=nullptr){
        aux=aux->arriba;
    }
    //Retorno la cabecera
    return aux;
}
NodoMatriz *Matriz::presenteEnCabeceraVertical(NodoMatriz *nodo){

    //El auxiliar para recorrer todo
    NodoMatriz *aux=nodo;
    //Me muevo
    while (aux->anterior!=nullptr){
        aux=aux->anterior;
    }
    //Y retorno la cabecera
    return aux;
}


//Si esta vacia
bool Matriz::isVacia(){
    return this->cabeceraHorizontal==nullptr && this->cabeceraVertical==nullptr;
}

