//
// Created by Enner on 6/12/2024.
//
#include "../../includes/MatrizDispersa/Matriz.h"

#include "../../includes/ListaCircularDoble/NodoTransaccion.h"

//Constructor de la matriz
Matriz::Matriz(){
    this->cabeceraHorizontal=nullptr;
    this->cabeceraVertical=nullptr;
}
//--------------------------------------------------------------------------------------------------------------------------------------
//Función para insertar un nuevo valor (sería como la principal)
void Matriz::insertarValor(std::string elian, std::string cabeH, std::string cabeV){

    NodoMatriz *cabH=nullptr;//Cabecera Horizontal
    NodoMatriz *cabV=nullptr;//Cabecera Vertical
    NodoMatriz *usuarioNuevo= new NodoMatriz(elian); //Creo el nuevo Nodo

    //Aquí voy a agregar la contraseña y demás datos iniciales
    std::string contra;
    std::cout<<"Ingrese la contrasena: "<<std::endl;
    std::cin>>contra;

    if (isVacia()){ //Si no hay nada en la matriz
        cabH=insertarCabeceraHorizontal(cabeH);//Se inserta una cabecera horizontal
        cabV=insertarCabeceraVertical(cabeV);//Se inserta una cabecera vertical

        insertarAlFinal(usuarioNuevo,cabH,cabV); //Se coloca todo al final
        return;
    }

    //Aquí solicito las cabeceras que ya tenemos
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


    //Manejo de la colocación de los usuarios ---------------------------------------------------------------------------------------



    /*
    while (auxH != nullptr) { //Mientras no sea nulo
        if (auxH->getNombre() == cabeV) { // Si el nodo ya existe en la posición
            //opción de escoger donde colocarlo
            int opt=0;
            while (opt==0){
                std::cout << "Seleccione una opción:" << std::endl;
                std::cout<<"1.Insertar enfrente"<<std::endl;
                std::cout<<"2.Insertar atras"<<std::endl;
                std::cin >> opt;
                if (opt==1) {//Si se quiere insertar al frente
                    insertarAlMediaHorizontal(usuarioNuevo, auxH);
                    insertarAlMediaVertical(usuarioNuevo, auxH);
                    std::cout << "Nodo insertado enfrente" << std::endl;
                } else if (opt==2) {
                    insertarAlMediaHorizontal(usuarioNuevo, auxH->getAbajo());
                    insertarAlMediaVertical(usuarioNuevo, auxH->getSiguiente());
                    std::cout << "Nodo insertado atras." << std::endl;
                } else {
                    std::cout << "Opción inválida" << std::endl;
                }
                return;
            }
        }
        //
        auxH = auxH->getAbajo();
    }*/
    //Manejo de la colocación de los usuarios ---------------------------------------------------------------------------------------


    NodoMatriz *auxH = cabH->getAbajo();//Nodo auxiliar para ir recorriendo para abajo desde la cabecera horizontal
    NodoMatriz *usuarioCabeceraVertical;//Creo otro nodo auxiliar que no sería tan auxiliar
    bool abajo=false; //Bandera para saber si es hay más abajo

    NodoMatriz *auxV=cabV->getSiguiente();//Creo un auxiliar para recorrer verticalemente
    NodoMatriz *usuarioCabeceraHorizontal; //Creo otro auxiliar para colocar el usuario
    bool siguiente=false; //Bandera para saber si hay más a la derecha
    //--------------------------------------------------------------------------------------------------------------------------------



    while (auxH!=nullptr){//Mientras el auxiliar de horizontal no sea nulo
        usuarioCabeceraVertical=presenteEnCabeceraVertical(auxH);//El otro auxiliar será indicará si tiene cabecera vertical
        abajo=masAbajo(usuarioCabeceraVertical,cabeV); //Si hay más abajo entonces abajo se vuelve verdadero

        if (!abajo) break; //Si ya no hay más abajo, lo detengo todo

        auxH=auxH->getAbajo(); //Y se corre el auxiliar de verdad (no el falso que sería de la cabecera vertical
    }
    //Fin de recorrer hacia abajo
    if (abajo){//Si está debajo de la cabecera
        insertarAlFinalHorizontal(usuarioNuevo,cabH); //inserto en la cabecera cabh
    }else{
        insertarAlMediaHorizontal(usuarioNuevo,auxH); //Si esetá debajo de un nodo abajo de la cabecera, auxH
    }


    while (auxV!=nullptr){
        usuarioCabeceraHorizontal=presenteEnCabeceraHorizontal(auxV);
        siguiente=masDerecha(usuarioCabeceraHorizontal,cabeH);

        if (!siguiente) break;

        auxV=auxV->getSiguiente();
    }
    //fin de ir recorriendo hacia la derecha

    if (siguiente){
        insertarAlFinalVertical(usuarioNuevo,cabV);
    }else{
        insertarAlMediaVertical(usuarioNuevo,auxV);
    }

}

//--------------------------------------------------------------------------------------------------------------------------------------
//Funciones para moverme por la matriz vertical y horizontal
NodoMatriz *Matriz::cabeceraV(std::string elian){

    //Si es que está vacía
    if (isVacia()){
        return nullptr;
    }

    //Se crea el auxiliar
    NodoMatriz *aux = cabeceraVertical;

    //Recorre los nodos verticales
    while (aux != nullptr ){
        if (aux->getNombre() == elian){
            return aux; //Su encontró el dato que se busca, se retorna
        }
        aux = aux->getAbajo(); //continua para abajo
    }//Si no hay nada entonces no manda nada xd
    return nullptr;
}
NodoMatriz *Matriz::cabeceraH(std::string elian){

    if (isVacia()){ //Si está vacia retorna algo vacío
        return nullptr;
    }

    //Creo el nodo auxiliar con el mismo valor del inicio de la cabecera
    NodoMatriz *aux = cabeceraHorizontal;

    //Si el siguiente no es nulo
    while (aux != nullptr ){
        if (aux->getNombre() == elian){ //Y si el siguente tiene un valor
            return aux;//Retorno el valor encontrado
        }
        aux = aux->getSiguiente(); //si no, busco en el siguiente nodo
    }
    return nullptr; //Si nada de nada entonces no retorno nada xd
}

//Funciones para saber si están presentes en sus respectivas cabeceras
NodoMatriz *Matriz::presenteEnCabeceraHorizontal(NodoMatriz *nodo){

    //El auxiliar es el nodo que se manda
    NodoMatriz *aux=nodo;
    while (aux->getArriba()!=nullptr){
        aux=aux->getArriba();
    }
    //Retorno la cabecera
    return aux;
}
NodoMatriz *Matriz::presenteEnCabeceraVertical(NodoMatriz *nodo){

    //El auxiliar para recorrer indicar si hay más
    NodoMatriz *aux=nodo;
    //Me muevo
    while (aux->getAnterior()!=nullptr){
        aux=aux->getAnterior();
    }
    //Y retorno la cabecera
    return aux;
}

//--------------------------------------------------------------------------------------------------------------------------------------
//Función para insertar una cabecera horizontal y/o vertical
NodoMatriz *Matriz::insertarCabeceraHorizontal(std::string elian){

    //Creo el nodo nuebo con el nuevo valor
    NodoMatriz *cabeceraNueva=new NodoMatriz(elian);

    //Si la cabecera no tiene nada, se coloca el inicio
    if (this->cabeceraHorizontal==nullptr){
        this->cabeceraHorizontal = cabeceraNueva; //Igualo la cabecera horizontal a la nueva
        return cabeceraNueva; //Retorno la nueva cabecera
    }
    NodoMatriz *aux=cabeceraHorizontal; //Si nada de lo anterior, creo el nodo auxiliar

    while (aux->getSiguiente() != nullptr ){ //Me muevo hasta llegar al final
        aux=aux->getSiguiente();
    }
    aux->setSiguiente(cabeceraNueva); //Agrego la nueva cabecera al final
    cabeceraNueva->setAnterior(aux);//Conecto la cabecera nueva al anterior
    return cabeceraNueva;//Retorno la cabecera
}
NodoMatriz *Matriz::insertarCabeceraVertical(std::string elian){

    NodoMatriz *cabeceraNueva=new NodoMatriz(elian); //Crea un nodo nuevo

    if (this->cabeceraVertical==nullptr){ //Si no hay nada, la creo
        this->cabeceraVertical = cabeceraNueva;
        return cabeceraNueva;
    }
    NodoMatriz *aux=cabeceraVertical;//Si nada de lo anterior, creo una vertical

    while (aux->getAbajo() != nullptr ){//Me muevo hasta la posición final
        aux=aux->getAbajo();
    }
    aux->setAbajo(cabeceraNueva); //Coloco la cabecera al final
    cabeceraNueva->setArriba(aux); //Conecto la nueva cabecera
    return cabeceraNueva; //Retorno el nuevo nodo de la cabecera
}
//--------------------------------------------------------------------------------------------------------------------------------------
//Funciones para insertar al usuario al final
void Matriz::insertarAlFinalHorizontal(NodoMatriz *elian, NodoMatriz *cabeH) {
    NodoMatriz *aux = cabeH;  // Uso del parámetro local

    while (aux->getAbajo() != nullptr) {
        aux = aux->getAbajo();
    }
    aux->setAbajo(elian);
    elian->setArriba(aux);
}
void Matriz::insertarAlFinalVertical(NodoMatriz *elian, NodoMatriz *cabeV) {
    NodoMatriz *aux = cabeV;  // Uso del parámetro local

    while (aux->getSiguiente() != nullptr) {
        aux = aux->getSiguiente();
    }
    aux->setSiguiente(elian);
    elian->setAnterior(aux);
}

//Funciones para insertar al la mitad de la final y la horizontal
void Matriz::insertarAlMediaHorizontal(NodoMatriz* valor, NodoMatriz* horizontal){
    // Conexión hacia el nodo superior (si existe)
    if (horizontal->getArriba() != nullptr) {
        horizontal->getArriba()->setAbajo(valor);
        valor->setArriba(horizontal->getArriba());
    }

    // Conexión hacia el nodo actual
    valor->setAbajo(horizontal);
    horizontal->setArriba(valor);
}
void Matriz::insertarAlMediaVertical(NodoMatriz* valor, NodoMatriz* vertical){
    // Conexión hacia el nodo a la izquierda (si existe)
    if (vertical->getAnterior() != nullptr) {
        vertical->getAnterior()->setSiguiente(valor);
        valor->setAnterior(vertical->getAnterior());
    }

    // Conexión hacia el nodo actual
    valor->setSiguiente(vertical);
    vertical->setAnterior(valor);
}

//Función para insertar al usuario al final
void Matriz::insertarAlFinal(NodoMatriz *elian, NodoMatriz* cabeH, NodoMatriz* cabeV){
    insertarAlFinalHorizontal(elian,cabeH);//Inserto la cabecera al final de la horizontal
    insertarAlFinalVertical(elian,cabeV);//Inserto la cabecer al final de la vertical
}
//--------------------------------------------------------------------------------------------------------------------------------------
//Devuelve true si hay más abajo o a la derecha
bool Matriz::masAbajo(NodoMatriz* cabeV, std::string cabV){
    NodoMatriz *aux=cabeV;
    while (aux!=nullptr){//Si no es nulo
        if (aux->getNombre()==cabV){//Y es igual a la cabecera actual
            return true;//true
        }
        aux=aux->getAbajo();//sino siguiente
    }
    return false;//sino no
}
bool Matriz::masDerecha(NodoMatriz* cabeH, std::string cabH){

    NodoMatriz *aux=cabeH;

    while (aux!=nullptr){//Si no es nulo
        if (aux->getNombre()==cabH){//Y es igual a la cabecera presente
            return true; //true
        }
        aux=aux->getSiguiente() ;//sino siguiente
    }
    return false;//Sino pos no xd
}

//Si esta vacia
bool Matriz::isVacia(){
    return this->cabeceraHorizontal==nullptr && this->cabeceraVertical==nullptr;
}

