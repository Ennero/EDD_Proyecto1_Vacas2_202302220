//
// Created by Enner on 10/12/2024.
//

#include "../../includes/MatrizDispersa/Usuario.h"

//Constructor para los usuarios
Usuario::Usuario(std::string usuario, std::string contrasena){
    this->usuario = usuario;
    this->contrasena = contrasena;
}
//Constructor para los encabezados
Usuario::Usuario(std::string usuario){
    this->usuario = usuario;
    this->contrasena = "";
}



//getters
std::string Usuario::getUsuario(){
    return this->usuario;
}
std::string Usuario::getContrasena(){
    return this->contrasena;
}
//setters
void Usuario::setUsuario(std::string usuario){
    this->usuario = usuario;
}
void Usuario::setContrasena(std::string contrasena){
    this->contrasena = contrasena;
}
