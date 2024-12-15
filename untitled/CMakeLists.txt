cmake_minimum_required(VERSION 3.30)
project(untitled)

set(CMAKE_CXX_STANDARD 23)

add_executable(untitled main.cpp
        src/MatrizDispersa/ArbolAVL.cpp
        includes/MatrizDispersa/ArbolAVL.h
        includes/MatrizDispersa/avl.h
        src/MatrizDispersa/avl.cpp
        includes/MatrizDispersa/Activo.h
        src/MatrizDispersa/Activo.cpp
        src/MatrizDispersa/Usuario.cpp
        includes/MatrizDispersa/Usuario.h
        includes/MatrizDispersa/Lista.h
        includes/MatrizDispersa/NodoTransaccion.h
        includes/MatrizDispersa/Transaccion.h
        src/MatrizDispersa/Lista.cpp
        src/MatrizDispersa/Transaccion.cpp
        src/MatrizDispersa/NodoTransaccion.cpp
        src/MatrizDispersa/NodoMatriz.cpp
        includes/MatrizDispersa/NodoMatriz.h
        src/MatrizDispersa/Matriz.cpp
        includes/MatrizDispersa/Matriz.h)
