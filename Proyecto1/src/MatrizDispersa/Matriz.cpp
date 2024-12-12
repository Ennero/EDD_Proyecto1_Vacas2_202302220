//
// Created by Enner on 6/12/2024.
//
#include "../../includes/MatrizDispersa/Matriz.h"

#include "../../includes/ListaCircularDoble/NodoTransaccion.h"
#include <fstream>
#include <sstream>

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
    usuarioNuevo->getUsuario()->setContrasena(contra);
    usuarioNuevo->getUsuario()->setDepartamento(cabeH);
    usuarioNuevo->getUsuario()->setEmpresa(cabeV);
    std::string nombrecito;
    std::cout<<"Ingrese el nombre: "<<std::endl;
    std::cin>>nombrecito;
    usuarioNuevo->getUsuario()->setNombre(nombrecito);
    //Aquí sigo finalizo la inicialización del usuario

    //Verifico si el usuario ya existe en la matriz------------------------------------------------------------------------
    NodoMatriz* usuarioExistente = encontrarUsuario(contra, elian);
    if (usuarioExistente != nullptr) {
        std::cout << "El usuario ya existe en la matriz." << std::endl;
        return; // No continuar con la inserción
    }
    //Verifico si el usuario ya existe en la matriz------------------------------------------------------------------------

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
    NodoMatriz *nodoExistente = obtenerNodo(cabeH, cabeV); // Implementa esta función para buscar un nodo existente
    if (nodoExistente != nullptr){
        std::cout << "Escoja una opción: " << std::endl;
        std::cout<<"1. Insertar Adelante"<<std::endl;
        std::cout<<"2. Insertar Atras"<<std::endl;
        int opcion;
        std::cin >> opcion;
        if (opcion == 1) {
            nodoExistente->insertarAdelante(usuarioNuevo); // Insertar al frente
        } else if (opcion == 2) {
            nodoExistente->insertarAtras(usuarioNuevo); // Insertar atrás
        } else {
            std::cout << "Opción inválida. No se realizó ninguna acción." << std::endl;
        }
        return; // Finalizamos porque ya insertamos
    }

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

//Funcion para encontrar usuario a partir de nombre y contraseña
NodoMatriz* Matriz::encontrarUsuario(std::string contrasena, std::string user){
    NodoMatriz* auxH = cabeceraHorizontal; // Comienza desde la cabecera horizontal

    while (auxH != nullptr) { //Recorro las cabeceras horizontales
        NodoMatriz* actual = auxH->getAbajo(); //Empieza desde el primer nodo de cada cabecera horizontal
        while (actual != nullptr) { //Recorro los nodos verticales de la fila actual
            Usuario* usuarioActual = actual->getUsuario(); //Creo una copia de un usuario
            //Si el nombre del usuario actual
            if (usuarioActual->getUsuario() == user && usuarioActual->getContrasena() == contrasena) {
                return actual; // Retorna el nodo si coincide el usuario
            }
            //Verifico si existe algo hacia adelante
            NodoMatriz* auxAdelante = actual->getSiguiente(); //Creo aux de adelante
            while (auxAdelante != nullptr) {
                Usuario* usuarioAdelante = auxAdelante->getUsuario(); //Obtengo ese usuario
                if (usuarioAdelante->getUsuario() == user && usuarioAdelante->getContrasena() == contrasena) {
                    return auxAdelante; // Retorna si encuentra el usuario
                }
                auxAdelante = auxAdelante->getAdelante(); //Si no pa' delante
            }
            // Verificar si existe algo hacia atras
            NodoMatriz* nodoAtras = actual->getAtras(); //Lo mismo que el de adelante xd
            while (nodoAtras != nullptr) {
                Usuario* usuarioAtras = nodoAtras->getUsuario();
                if (usuarioAtras->getUsuario() == user && usuarioAtras->getContrasena() == contrasena) {
                    return nodoAtras; // Retorna si encuentra el usuario atrás
                }
                nodoAtras = nodoAtras->getAtras();
            }
            actual = actual->getAbajo(); // Baja al siguiente nodo
        }
        auxH = auxH->getSiguiente(); // Pasa a la siguiente cabecera horizontal (a la derecha)
    }
    return nullptr; //Si no encuentra nada, retorna nada
}
//Funciones para insertar adelante y atras ---------------------------------------------------------------------------------------------------
//Función para obtener el nodo en cierta posición
NodoMatriz* Matriz::obtenerNodo(std::string cabeH, std::string cabeV) {
    NodoMatriz *cabH = cabeceraH(cabeH);//Creo una copia de la cabceraH que deseo
    if (cabH == nullptr) return nullptr;//Si no está entonces no

    NodoMatriz *actual = cabH->getAbajo();//me muevo para abajo
    while (actual != nullptr) {//mientras tenga algo
        if (actual->getUsuario()->getEmpresa() == cabeV) {//si encuentra al usuario que tenga la empresa
            return actual; // Retorna el nodo
        }
        actual = actual->getAbajo();//Sino, sigue bajando
    }
    return nullptr; // No se encontró el nodo
}
//--------------------------------------------------------------------------------------------------------------------------------------
//Funciones para encontrar las cabeceras
NodoMatriz *Matriz::cabeceraV(std::string elian){

    //Si es que está vacía
    if (isVacia()){
        return nullptr;//Si no hay cabecera retorna nula
    }
    //Se crea el auxiliar
    NodoMatriz *aux = cabeceraVertical;

    while (aux != nullptr ){//Recorre los nodos verticales
        if (aux->getNombre() == elian){//Si coincide con la caecera que se desea
            return aux; //Su encontró el dato que se busca, se retorna
        }
        aux = aux->getAbajo(); //continua para abajo
    }//Si no hay nada entonces no manda nada xd
    return nullptr;
}
NodoMatriz *Matriz::cabeceraH(std::string elian){

    if (isVacia()){ //Si está vacia retorna algo vacío
        return nullptr;//Si no hay cabecera retorna nulo
    }

    //Creo el nodo auxiliar con el mismo valor del inicio de la cabecera
    NodoMatriz *aux = cabeceraHorizontal;

    //Recorro todas las cabeceras horizontales
    while (aux != nullptr ){
        if (aux->getNombre() == elian){ //Si coincide con la cabecera que se desea
            return aux;//Retorno esa cabecera
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
//****************************************************************************************************************************************

/*
//Función para encontrar un usuario haciendo login
NodoMatriz* Matriz::encontrarUsuarioPorEmpresaDepartamento(std::string empresa, std::string departamento,std::string user,std::string contrasena) {
    // Encuentra la cabecera vertical correspondiente a la empresa
    NodoMatriz* cabeceraVertical = this->cabeceraVertical;
    while (cabeceraVertical != nullptr && cabeceraVertical->getNombre() != empresa) {
        cabeceraVertical = cabeceraVertical->getSiguiente();
    }

    if (cabeceraVertical == nullptr) {
        // No se encontró la empresa
        return nullptr;
    }

    // Encuentra la cabecera horizontal correspondiente al departamento
    NodoMatriz* cabeceraHorizontal = cabeceraVertical->getDerecha();
    while (cabeceraHorizontal != nullptr && cabeceraHorizontal->getNombre() != departamento) {
        cabeceraHorizontal = cabeceraHorizontal->getSiguiente();
    }

    if (cabeceraHorizontal == nullptr) {
        // No se encontró el departamento
        return nullptr;
    }

    // Recorre los nodos de la intersección entre la empresa y el departamento
    NodoMatriz* actual = cabeceraHorizontal->getAbajo();
    while (actual != nullptr) {
        Usuario* usuarioActual = actual->getUsuario();

        if (usuarioActual != nullptr &&
            usuarioActual->getUsuario() == user &&
            usuarioActual->getContrasena() == contrasena) {
            return actual; // Retorna el nodo encontrado
            }

        actual = actual->getAbajo(); // Sigue recorriendo hacia abajo en la columna
    }

    return nullptr; // No se encontró el usuario
}
*/

//Funciones para generar el reporte de la matriz
void Matriz::generarReporteMatriz(){
    //Genero el archivo
    std::string matriz=generarDotGrafica();
    std::ofstream archivo("reporteMatriz.dot");
    archivo<<matriz;
    archivo.close();
    //Creo un comando para ejecutar el graphviz y crear el pdf
    system("dot -Tpdf reporteMatriz.dot -o reporteMatriz.pdf && start reporteMatriz.pdf");
}

std::string Matriz::generarDotGrafica() {
    std::string grafico;
    //Inicio el grafico
    grafico += "digraph G {\n rankdir=TB;\n node [shape=box, style=filled, fillcolor=lightblue, margin=0.2];\n";
    grafico += "edge [style=solid, color=blue];\n graph [ranksep=1.5, nodesep=1];\n";
    grafico += "graph [label=\"Reporte de Matriz\", fontsize=20, fontcolor=black];\n";
    if (isVacia()){ //Si no tiene nada entonces no haré nada :)
        grafico += "}";
        return grafico;
    }

    //Tomo la cabecera
    NodoMatriz *cabH = cabeceraHorizontal;
//**********************************************************************************
        NodoMatriz *aux=cabeceraVertical;
    grafico += "    invisible_[label=\"invisible\"style=invis];\n";
    grafico += "    invisible_-> nodo_" + std::to_string(reinterpret_cast<uintptr_t>(aux)) + " [style=invis];\n";
        while (aux!=nullptr){
            std::string nodo = "nodo_" + std::to_string(reinterpret_cast<uintptr_t>(aux));
            grafico += "    " + nodo + " [label=\"" + aux->getNombre()+ "\"style=filled, fillcolor=lightblue];\n";
            if (aux->getAbajo() != nullptr) {//Si hay algo a la izquierda
                std::string nodoAbajo = "nodo_" + std::to_string(reinterpret_cast<uintptr_t>(aux->getAbajo()));
                grafico += "    " + nodo + " -> " + nodoAbajo + " [dir=both];\n"; //Conecto
            }
            if (aux->getSiguiente() != nullptr) { //Si hay algo a la derecha
                std::string nodoDerecha = "nodo_" + std::to_string(reinterpret_cast<uintptr_t>(aux->getSiguiente()));
                grafico += "    " + nodo + " -> " + nodoDerecha + " [dir=both,constraint=false];\n";//Conecto
            }
            aux=aux->getAbajo();
        }
    //**********************************************************************************
    while (cabH != nullptr) { // Recorro de derecha->izquierda
        NodoMatriz *nodoActual = cabH;//Nodito que irá bajando
        while (nodoActual != nullptr) { // Recorro de arriba->abajo
            std::string nodo = "nodo_" + std::to_string(reinterpret_cast<uintptr_t>(nodoActual));
            grafico += "    " + nodo + " [label=\"" + nodoActual->getNombre()+ "\"style=filled, fillcolor=lightblue];\n";

            if (nodoActual->getAbajo() != nullptr) {//Si hay algo a la izquierda
                std::string nodoAbajo = "nodo_" + std::to_string(reinterpret_cast<uintptr_t>(nodoActual->getAbajo()));
                grafico += "    " + nodo + " -> " + nodoAbajo + " [dir=both];\n"; //Conecto
            }
            if (nodoActual->getSiguiente() != nullptr) { //Si hay algo a la derecha
                std::string nodoDerecha = "nodo_" + std::to_string(reinterpret_cast<uintptr_t>(nodoActual->getSiguiente()));
                grafico += "    " + nodo + " -> " + nodoDerecha + " [dir=both,constraint=false];\n";//Conecto
            }
            nodoActual = nodoActual->getAbajo(); //Bajo
        }
        cabH = cabH->getSiguiente(); //me voy al lado derecho
    }
    grafico += "}"; //Termino el string
    return grafico;//lo retorno
}
