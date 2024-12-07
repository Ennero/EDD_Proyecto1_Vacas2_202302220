cmake_minimum_required(VERSION 3.30)
project(Proyecto)

set(CMAKE_CXX_STANDARD 23)

add_executable(Proyecto main.cpp
        includes/Transaccion.h
        src/Transaccion.cpp
        includes/MatrizDispersa/Matriz.h
        src/MatrizDispersa/Matriz.cpp
        includes/MatrizDispersa/Nodo.h
        src/MatrizDispersa/Nodo.cpp
)
