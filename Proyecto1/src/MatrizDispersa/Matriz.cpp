//
// Created by Enner on 6/12/2024.
//
#include "../../includes/MatrizDispersa/Matriz.h"

#include "../../includes/ListaCircularDoble/NodoTransaccion.h"

//Es solo el constructor de la matriz
Matriz::Matriz(){
    //Inicializando el contructor
    this->cabeceraHorizontal=nullptr;
    this->cabeceraVertical=nullptr;
}

//Función para insertar un nuevo valor
void Matriz::insertarValor(int elian, int cabeH, int cabeV){

    NodoMatriz *cabH=nullptr;//Cabecera Horizontal
    NodoMatriz *cabV=nullptr;//Cabecera Vertical
    NodoMatriz *usuarioNuevo= new NodoMatriz(elian); //Creo el nuevo Nodo


    if (isVacia()){ //Si no hay nada en la matriz
        cabH=insertarCabeceraHorizontal(cabeH);//Se inserta una cabecera horizontal
        cabV=insertarCabeceraVertical(cabeV);//Se inserta una cabecera vertical

        insertarAlFinal(usuarioNuevo,cabH,cabV); //Se coloca todo al final
        return;
    }

    //Aquí solicito las cabeceras
    cabH=cabeceraH(cabeH);
    cabV=cabeceraV(cabeV);

    //Si no existe ninguna de las dos cabeceras nueva a agregar
    if (cabH==nullptr && cabV==nullptr){
        cabH=insertarCabeceraHorizontal(cabeH);
        cabV=insertarCabeceraVertical(cabeV);
        //Aquí inserto el usuarioNuevo(nodo) al final
        insertarAlFinal(usuarioNuevo,cabH,cabV);
        return;
    }

    //Si no hay cabecera horizontal
    if (cabH==nullptr){
        //La inserto
        cabH=insertarCabeceraHorizontal(cabeH);
        insertarAlFinal(usuarioNuevo,cabH,cabV);
        return;
    }
    //Si no hay cabecera vertical
    if (cabV==nullptr){
        //La inserto
        cabV=insertarCabeceraVertical(cabeV);
        insertarAlFinal(usuarioNuevo,cabH,cabV);
        return;
    }
    //Creo nodos auxiliares para la cabecera vertical
    NodoMatriz *auxH=cabH->abajo;
    NodoMatriz *usuarioCabeceraVertical;//Creo otro nodo auxiliar que no sería tan auxiliar
    bool abajo=false; //Bandera para saber si es hay más abajo

    while (auxH!=nullptr){//Mientras el auxiliar de horizontal no sea nulo
        usuarioCabeceraVertical=presenteEnCabeceraVertical(auxH);//El otro auxiliar será el usuario presente bajo esa cabecera (o nodo)
        abajo=masAbajo(usuarioCabeceraVertical,cabeH); //Si hay más abajo entonces abajo se vuelve verdadero

        if (!abajo) break; //Si ya no hay más abajo, lo detengo todo

        auxH=auxH->abajo; //Y se corre el auxiliar de verdad (no el falso que sería de la cabecera vertical
    }
    if (abajo){//Si está debajo de la cabecera
        insertarAlFinalHorizontal(usuarioNuevo,cabH); //inserto en la cabecera cabh
    }else{
        insertarAlMediaHorizontal(usuarioNuevo,auxH); //Si esetá debajo de un nodo abajo de la cabecera, auxH
    }
    //Creo un auxiliar para recorrer verticalemente
    NodoMatriz *auxV=cabV->siguiente;
    NodoMatriz *usuarioCabeceraHorizontal; //Creo otro auxiliar para colocar el usuario
    bool siguiente=false; //

    while (auxV!=nullptr){
        usuarioCabeceraHorizontal=presenteEnCabeceraHorizontal(auxV);
        siguiente=masDerecha(usuarioCabeceraHorizontal,cabeH);

        if (!siguiente) break;

        auxV=auxV->siguiente;
    }

    if (siguiente){
        insertarAlFinalVertical(usuarioNuevo,cabV);
    }else{
        insertarAlMediaVertical(usuarioNuevo,auxV);
    }


}

void Matriz::insertarAlFinal(NodoMatriz *elian, NodoMatriz* cabeH, NodoMatriz* cabeV){
    insertarAlFinalHorizontal(elian,cabeH);//Inserto la cabecera al final de la horizontal
    insertarAlFinalVertical(elian,cabeV);//Inserto la cabecer al final de la vertical
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

void Matriz::insertarAlFinalHorizontal(NodoMatriz *elian, NodoMatriz *cabeH) {
    NodoMatriz *aux = cabeH;  // Uso del parámetro local

    while (aux->abajo != nullptr) {
        aux = aux->abajo;
    }
    aux->abajo = elian;
    elian->arriba = aux;
}

void Matriz::insertarAlFinalVertical(NodoMatriz *elian, NodoMatriz *cabeV) {
    NodoMatriz *aux = cabeV;  // Uso del parámetro local

    while (aux->siguiente != nullptr) {
        aux = aux->siguiente;
    }
    aux->siguiente = elian;
    elian->anterior = aux;
}

//contecta el nodo en medio de la matriz dispersa
void Matriz::insertarAlMediaHorizontal(NodoMatriz* valor, NodoMatriz* horizontal){

    horizontal->arriba->abajo = valor;
    valor->abajo = horizontal;
    valor->arriba = horizontal->arriba;
    horizontal->arriba=valor;
    return;
}

//conecta el nuevo nodo en medio de la matriz dispersa
void Matriz::insertarAlMediaVertical(NodoMatriz* valor, NodoMatriz* vertical){

    vertical->anterior->siguiente=valor;
    valor->siguiente=vertical;

    valor->anterior=vertical->anterior;
    vertical->anterior=valor;
    return;
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


//Devuelve true si hay más abajo, sino false
bool Matriz::masAbajo(NodoMatriz* cabeV, int cabV){
    NodoMatriz *aux=cabeV;
    while (aux!=nullptr){//Si no es nulo
        if (aux->elian==cabV){//Y es igual a la cabecera actual
            return true;//true
        }
        aux=aux->abajo;//sino siguiente
    }
    return false;//sino no
}

//Devuelve true si hay más a la derecha, sino false
bool Matriz::masDerecha(NodoMatriz* cabeH, int cabH){

    NodoMatriz *aux=cabeH;

    while (aux!=nullptr){//Si no es nulo
        if (aux->elian==cabH){//Y es igual a la cabecera presente
            return true; //true
        }
        aux=aux->siguiente;//sino siguiente
    }
    return false;//Sino pos no xd
}


//Si esta vacia
bool Matriz::isVacia(){
    return this->cabeceraHorizontal==nullptr && this->cabeceraVertical==nullptr;
}

