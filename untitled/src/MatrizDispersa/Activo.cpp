//
// Created by Enner on 10/12/2024.
//

#include "../../includes/MatrizDispersa/Activo.h"
#include <iostream>
//Constructor
Activo::Activo(std::string id,std::string nombre,std::string descripcion){
    this->id = id;
    this->descripcion = descripcion;
    this->nombre = nombre;
    this->tiempoRenta = 0;
    this->usuarioRentador="";
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
std::string Activo::getUsuarioRentador(){
    return this->usuarioRentador;
}
//Setters
void Activo::setNombre(std::string nombre){
    this->nombre = nombre;
}
void Activo::setUsuarioRentador(std::string usuarioRentador){
    this->usuarioRentador=usuarioRentador;
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


