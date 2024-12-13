//
// Created by Enner on 10/12/2024.
//

#include "../../includes/MatrizDispersa/Activo.h"
#include <iostream>
//Constructor
Activo::Activo(std::string id){
    this->id = id;
    this->descripcion = "";
    this->nombre = "";
    this->tiempoRenta = 0;
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
int Activo::getTiempoRenta(){
    return this->tiempoRenta;
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
void Activo::setTiempoRenta(int tiempoRenta){
    this->tiempoRenta = tiempoRenta;
}

