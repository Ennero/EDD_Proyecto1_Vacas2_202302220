//
// Created by Enner on 8/12/2024.
//

#include "../includes/Activo.h"

//Constructor
Activo::Activo(std::string nombre, std::string descripcion, std::string id){
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->id = id;
}

//Getters y Setters
std::string Activo::getNombre(){
    return nombre;
}
std::string Activo::getDescripcion(){
    return descripcion;
}
std::string Activo::getId(){
    return id;
}
void Activo::setNombre(std::string nombre){
    this->nombre = nombre;
}
void Activo::setDescripcion(std::string descripcion){
    this->descripcion = descripcion;
}
void Activo::setId(std::string id){
    this->id = id;
}
