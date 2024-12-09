//
// Created by Enner on 8/12/2024.
//

#ifndef ACTIVO_H
#define ACTIVO_H

#include  <iostream>

class Activo{
    private:
    std::string nombre;
    std::string descripcion;
    std::string id;

    public:

    //Constructor
    Activo(std::string nombre, std::string descripcion, std::string id);

    //Getters y Setters
    std::string getNombre();
    std::string getDescripcion();
    std::string getId();
    void setNombre(std::string nombre);
    void setDescripcion(std::string descripcion);
    void setId(std::string id);

};


#endif //ACTIVO_H
