//
// Created by Enner on 10/12/2024.
//

#include "../../includes/MatrizDispersa/Activo.h"
#include <iostream>
//Constructor
Activo::Activo(std::string id, std::string descripcion, std::string nombre){
    this->id = id;
    this->descripcion = descripcion;
    this->nombre = nombre;
}

//Getters
std::string Activo::getDescripcion(){
    return this->descripcion;
}
std::string Activo::getNombre(){
    return this->nombre;
}
std::string Activo::getId(){
    return this->id;
}
//Setters
void Activo::setNombre(std::string nombre){
    this->nombre = nombre;
}
void Activo::setId(std::string id){
    this->id = id;
}
void Activo::setDescripcion(std::string descripcion){
    this->descripcion = descripcion;
}

