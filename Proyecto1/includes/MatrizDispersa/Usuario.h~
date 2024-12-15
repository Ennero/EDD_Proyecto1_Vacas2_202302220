//
// Created by Enner on 10/12/2024.
//

#ifndef USUARIO_H
#define USUARIO_H

#include "ArbolAVL.h"
#include "../ListaCircularDoble/Lista.h"
#include <iostream>

class Usuario{
private:
    std::string usuario;
    std::string contrasena;
    std::string nombre;
    std::string departamento;
    std::string empresa;
    Lista *activosRentados;
    ArbolAVL *activos;

public:
    //contructor para los usuarios
    Usuario(std::string usuario,std::string contrasena);
    //constructor para los encabezados
    Usuario(std::string usuario);

    //getters
    Lista getActivosRentados();
    std::string getUsuario();
    std::string getContrasena();
    std::string getNombre();
    std::string getDepartamento();
    std::string getEmpresa();
    ArbolAVL* getActivos();
    //setters
    void setActivosRentados(Lista activosRentados);
    void setUsuario(std::string usuario);
    void setContrasena(std::string contrasena);
    void setNombre(std::string nombre);
    void setDepartamento(std::string departamento);
    void setEmpresa(std::string empresa);
    void setActivos(ArbolAVL* activos);
};





#endif //USUARIO_H
