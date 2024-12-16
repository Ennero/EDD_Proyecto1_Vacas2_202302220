    //
    // Created by Enner on 12/12/2024.
    //

    #ifndef ARBOLAVL_H
    #define ARBOLAVL_H

#include <string>

    #include "avl.h"

    class ArbolAVL{
    private:
        AVL *raiz;

        void insertar(AVL *valor, AVL *&raiz);

        //atributos
        int alturaMaxima(AVL *nodo);//Función que devuleve la altura máxima del nodo
        int factorEquilibrio(AVL *nodo); //Para calcular el factor de equilibrio

        //Rotaciones
        void rotacionIzquierda(AVL *&nodo);
        void rotacionDerecha(AVL *&nodo);
        void rotacionIzquierdaDerecha(AVL *&nodo);
        void rotacionDerechaIzquierda(AVL *&nodo);

        void eliminar(std::string valor, AVL *&nodo);
        AVL* masALaDerecha(AVL* nodo);

        //Funciónk para imprimir los activos en recursivo
        void imprimirRevursivo(AVL* nodo);
        //Función para imprimir los activos disponibles en recursivo
        void imprimirActivosDisponiblesRecursivo(AVL* nodo);

        //Función para imprimir los activos rentados en recursivo
        void imprimirActivosRentadosRecursivo(AVL* nodo);

    public:
        //Constructor
        ArbolAVL();
        //Para generar el reporte
        std::string generarContenidoDot(AVL *nodo);
        std::string generarStringDot(AVL *raiz);
        void generarDotGrafica();

        //Función para balancear
        void balancear(AVL *nodo);

        //Funciones para eliminar para eliminar
        void eliminar(std::string valor);

        //Función para saber si es hoja
        bool esHoja(AVL *nodo);

        void insertar(std::string id,std::string nombre,std::string descripcion);//Función para insertar nada más
        //Función para obtener la altura máxima
        int alturaMaxima();
        //getter
        AVL *getRaiz();
        std::string getValor();
        //Setter
        void setRaiz(AVL *avl);

        //Funciones para encontrar los nodos de los arboles
        AVL *buscar(std::string valor);
        AVL *buscar(std::string valor, AVL *nodo);

        //Funcion para los reporte de las transacciones sin correrlos
        std::string generarDotContenidoActivos();

        //Función para imprimir los activos que están disponibles
        void imprimirActivosDisponibles();

        //Función para imprimir los activos
        void imprimirActivos();

        //Función para modificar un activo
        void modificar(std::string id,std::string nuevoNombre,std::string Nuevadescripcion);

        //Función par mostrar unicamente los activos rentados
        void mostrarActivosRentados();

        //Función para imprimir los activos rentados
        bool hayActivosRentados();
        bool hayActivosRentadosRecursivo(AVL *nodo);
        //Función para saber si hay activos rentados

        //Funciones para poder imprimir las que no están ocupadas
        void imprimirActivosNoDisponibles();
        void imprimirActivosNoDisponiblesRecursivo(AVL *nodo);

    };

    #endif //ARBOLAVL_H
