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
    std::string usuarioRentador;
    int tiempoRenta;
public:
    Activo(std::string id,std::string nombre, std::string descripcion);


    //Getters
    int getTiempoRenta();
    std::string getId();
    std::string getDescripcion();
    std::string getNombre();
    std::string getUsuarioRentador();
    //Setters
    void setDescripcion(std::string descripcion);
    void setNombre(std::string nombre);
    void setId(std::string id);
    void setTiempoRenta(int tiempoRenta);
    void setUsuarioRentador(std::string usuarioRentador);

    //Función que retornará el contenido para graficar un
    std::string generarDotContenidoActivos();
};

#endif //ACTIVO_H
