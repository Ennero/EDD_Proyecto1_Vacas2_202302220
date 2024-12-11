//
// Created by Enner on 10/12/2024.
//

#ifndef ACTIVO_H
#define ACTIVO_H

#include <iostream>

class Activo{

private:
    std::string id;
    std::string descripcion;
    std::string nombre;
public:
    Activo(std::string id, std::string descripcion, std::string nombre);

    //Getters
    std::string getId();
    std::string getDescripcion();
    std::string getNombre();
    //Setters
    void setDescripcion(std::string descripcion);
    void setNombre(std::string nombre);
    void setId(std::string id);


};

#endif //ACTIVO_H
