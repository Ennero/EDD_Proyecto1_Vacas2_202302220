//
// Created by Enner on 10/12/2024.
//

#include "../../includes/MatrizDispersa/Usuario.h"
//Constructor para los encabezados
Usuario::Usuario(std::string usuario){
    this->usuario = usuario;
    this->contrasena = "";
    this->activos=new ArbolAVL();
    this->activosRentados=new Lista();
    this->departamento="";
    this->empresa = "";
    this->nombre = "";
}

//getters
Lista* Usuario::getActivosRentados(){
    return this->activosRentados;
}
std::string Usuario::getUsuario(){
    return this->usuario;
}
ArbolAVL* Usuario::getActivos(){
    return this->activos;
}
std::string Usuario::getContrasena(){
    return this->contrasena;
}
std::string Usuario::getEmpresa(){
    return this->empresa;
}
std::string Usuario::getDepartamento(){
    return this->departamento;
}
std::string Usuario::getNombre(){
    return this->nombre;
}

//setters
void Usuario::setUsuario(std::string usuario){
    this->usuario = usuario;
}
void Usuario::setActivos(ArbolAVL* activos){
    this->activos=activos;
}
void Usuario::setContrasena(std::string contrasena){
    this->contrasena = contrasena;
}
void Usuario::setEmpresa(std::string empresa){
    this->empresa = empresa;
}
void Usuario::setDepartamento(std::string departamento){
    this->departamento = departamento;
}
void Usuario::setNombre(std::string nombre){
    this->nombre = nombre;
}
