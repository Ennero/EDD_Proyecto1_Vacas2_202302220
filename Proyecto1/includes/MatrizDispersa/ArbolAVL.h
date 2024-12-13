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


    public:
        //Constructor
        ArbolAVL();
        //Para generar el reporte
        std::string generarContenidoDot(AVL *nodo);
        std::string generarStringDot(AVL *raiz);
        void generarDotGrafica();

        void insertar(std::string valor);//Función para insertar nada más
        //Función para obtener la altura máxima
        int alturaMaxima();
        //getter
        AVL *getRaiz();
        std::string getValor();

        //Setter
        void setRaiz(AVL *avl);


    };

    #endif //ARBOLAVL_H
