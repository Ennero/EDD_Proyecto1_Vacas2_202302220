//
// Created by Enner on 6/12/2024.
//

#include "../includes/Transaccion.h"

//<tipo> <nombre_clase>::<metodo>

//Constructor :)
Transaccion::Transaccion(std::string IdTransaccion,std::string idActivo,std::string usuarioRentador,std::string departamento, std::string departamentoRentador,std::string empresa,std::string fecha, std::string tiempo){
    this->idTransaccion = IdTransaccion;
    this->idActivo = idActivo;
    this->usuarioRentador = usuarioRentador;
    this->departamento = departamento;
    this->empresa = empresa;
    this->fecha = fecha;
    this->tiempo = tiempo;
}

//Destructor
Transaccion::~Transaccion(){
    delete this;
}


//getters
std::string Transaccion::getDepartamento(){
    return departamento;
}
std::string Transaccion::getEmpresa(){
    return empresa;
}
std::string Transaccion::getFecha(){
    return fecha;
}
std::string Transaccion::getTiempo(){
    return tiempo;
}
std::string Transaccion::getIdActivo(){
    return idActivo;
}
std::string Transaccion::getIdTransaccion(){
    return idTransaccion;
}
std::string Transaccion::getUsarioRentador(){
    return usarioRentador;
}

//setters
void Transaccion::setDepartamento(std::string departamento){
    this->departamento = departamento;
}
void Transaccion::setEmpresa(std::string empresa){
    this->empresa = empresa;
}
void Transaccion::setFecha(std::string fecha){
    this->fecha = fecha;
}
void Transaccion::setTiempo(std::string tiempo){
    this->tiempo = tiempo;
}
void Transaccion::setIdActivo(std::string idActivo){
    this->idActivo = idActivo;
}
void Transaccion::setIdTransaccion(std::string idTransaccion){
    this->idTransaccion = idTransaccion;
}
void Transaccion::setUsarioRentador(std::string usarioRentador){
    this->usarioRentador = usarioRentador;
}




