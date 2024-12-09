cmake_minimum_required(VERSION 3.30)
project(Proyecto)

set(CMAKE_CXX_STANDARD 23)

add_executable(Proyecto main.cpp
        includes/Transaccion.h
        src/Transaccion.cpp
        includes/MatrizDispersa/Matriz.h
        src/MatrizDispersa/Matriz.cpp
        includes/MatrizDispersa/NodoMatriz.h
        src/MatrizDispersa/NodoMatriz.cpp
        includes/ListaCircularDoble/Lista.h
        includes/ListaCircularDoble/NodoMatriz.h
        src/ListaCircularDoble/Lista.cpp
        src/ListaCircularDoble/NodoMatriz.cpp
        includes/Activo.h
        src/Activo.cpp
        includes/ListaCircularDoble/NodoTransaccion.h
        src/ListaCircularDoble/NodoTransaccion.cpp
)
