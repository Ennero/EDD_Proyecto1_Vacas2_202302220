//
// Created by Enner on 6/12/2024.
//

#ifndef MATRIZDISPERSA_H
#define MATRIZDISPERSA_H

#include "NodoMatriz.h"
#include "Activo.h"
#include "avl.h"
#include <iostream>

class Matriz {
private:
    //Cabecera horizontal (el noditos)
    NodoMatriz *cabeceraHorizontal;
    //Cabecera vertical (el noditos)
    NodoMatriz *cabeceraVertical;

public:
    //Constructor
    Matriz();

    //Procedimiento para saber si la matriz está vacia
    bool isVacia();

    //Las funciones para insertar los nodos
    NodoMatriz *cabeceraH(std::string elian);
    NodoMatriz *cabeceraV(std::string elian);

    //Funciones para insertar nodos en las cabeceras
    NodoMatriz *insertarCabeceraHorizontal(std::string elian);
    NodoMatriz *insertarCabeceraVertical(std::string elian);

    //Función para insertar un Valor
    void insertarValor(std::string elian, std::string cabeH, std::string cabeV,std::string contrasena,std::string nombreCompleto);
    //Función para insertar un nodo al final
    void insertarAlFinal(NodoMatriz *valor, NodoMatriz *cabeH, NodoMatriz *cabeV);
    void insertarAlFinalHorizontal(NodoMatriz *valor, NodoMatriz *cabeH);
    void insertarAlMediaVertical(NodoMatriz *valor, NodoMatriz *vertical);
    void insertarAlMediaHorizontal(NodoMatriz *valor, NodoMatriz *horizontal);
    void insertarAlFinalVertical(NodoMatriz *valor, NodoMatriz *cabeH);

    //Funciones para saber si está presentes en las
    NodoMatriz *presenteEnCabeceraHorizontal(NodoMatriz *nodo);
    NodoMatriz *presenteEnCabeceraVertical(NodoMatriz *nodo);

    //Funciones para graficar la matriz
    std::string generarDotGrafica();
    void generarReporteMatriz();

    //Función para encontrar un usurio
    NodoMatriz *encontrarUsuarioPorEmpresaDepartamento(std::string empresa, std::string departamento, std::string user, std::string contrasena);

    //Funciones para saber si está más abajo o más a la derecha
    bool masAbajo(NodoMatriz *cabeV, std::string cabH);
    bool masDerecha(NodoMatriz *cabeH, std::string cabV);

    //Funcion para buscar un nodo
    NodoMatriz* encontrarUsuario(std::string constrasena,std::string user);
    NodoMatriz* buscarNodoEnPosicion(NodoMatriz* cabeH,NodoMatriz* cabeV);
    NodoMatriz* obtenerNodo(std::string cabeH,std::string cabeV);

    //getters
    NodoMatriz* getCabeceraHorizontal();
    NodoMatriz* getCabeceraVertical();

    //setters
    void setCabeceraHorizontal(NodoMatriz *nodo);
    void setCabeceraVertical(NodoMatriz *nodo);

    //Funciones para Generar el reporte de los activos de las empresas
    void generarReporteActivosEmpresa(std::string empresa);
    std::string generarDotGraficaActivosEmpresa(std::string empresa);
    std::string concatenarStringPorFila(NodoMatriz *cab);

    //Funciones para Generar el reporte de los activos del departamento
    void generarReporteActivosDepartamento(std::string departamento);
    std::string concatenarStringPorColumna(NodoMatriz *cab);

    //Funciones para mostrar los activos del usuario
    void mostrarActivosUsuario(std::string user, std::string contrasena);

    //Funciones para mostrar los activos rentados por el usuario
    void mostrarActivosRentados(std::string user, std::string contrasena);

    //Función para mostrar los activos disponibles
    void mostrarActivosDisponibles();

    //Funciones para buscarActivo por ID (retorna el nodo)
    AVL* encontrarActivo(std::string id);

    //Función para retar un activo
    void rentarActivo(std::string id,int dias,std::string user, std::string contrasena);

    //Función para retornar los activos que están en renta de un usuario
    void activosEnRentaDEUsuario(std::string user, std::string contrasena);
};

#endif //MATRIZDISPERSA_H
