//
// Created by Enner on 10/12/2024.
//

#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>

class Usuario{
private:
    std::string usuario;
    std::string contrasena;

public:
    //contructor para los usuarios
    Usuario(std::string usuario,std::string contrasena);
    //constructor para los encabezados
    Usuario(std::string usuario);

    //getters
    std::string getUsuario();
    std::string getContrasena();
    //setters
    void setUsuario(std::string usuario);
    void setContrasena(std::string contrasena);

};





#endif //USUARIO_H
