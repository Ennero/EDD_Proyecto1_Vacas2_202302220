cmake_minimum_required(VERSION 3.30)
project(Proyecto1)

set(CMAKE_CXX_STANDARD 23)

add_executable(Proyecto1 main.cpp
        includes/Transaccion.h
        src/Transaccion.cpp
        includes/MatrizDispersa/Matriz.h
        src/MatrizDispersa/Matriz.cpp
        includes/MatrizDispersa/NodoMatriz.h
        src/MatrizDispersa/NodoMatriz.cpp
        includes/ListaCircularDoble/Lista.h
        src/ListaCircularDoble/Lista.cpp
        src/ListaCircularDoble/NodoTransaccion.cpp
        includes/ListaCircularDoble/NodoTransaccion.h
        includes/MatrizDispersa/Usuario.h
        src/MatrizDispersa/Usuario.cpp
        includes/MatrizDispersa/Activo.h
        src/MatrizDispersa/Activo.cpp)
