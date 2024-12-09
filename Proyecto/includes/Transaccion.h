//
// Created by Enner on 6/12/2024.
//

#ifndef TRANSACCION_H
#define TRANSACCION_H

#include <iostream>

class Transaccion {
private:
    //atributos
    std::string idTransaccion;
    std::string idActivo;
    std::string usuarioRentador;
    std::string departamento;
    std::string empresa;
    std::string fecha;
    std::string tiempo;

public:
    //constructor
    Transaccion(std::string transaccion, std::string activo, std::string usuarioRentador, std::string departamento,
                std::string empresa, std::string fecha, std::string tiempo);
    ~Transaccion(); //destructor

    //Getters y Setters
    std::string getIdTransaccion();
    std::string getIdActivo();
    std::string getUsarioRentador();
    std::string getDepartamento();
    std::string getEmpresa();
    std::string getFecha();
    std::string getTiempo();

    void setIdTransaccion(std::string idTransaccion);
    void setIdActivo(std::string idActivo);
    void setUsarioRentador(std::string usuarioRentador);
    void setDepartamento(std::string departamento);
    void setEmpresa(std::string empresa);
    void setFecha(std::string fecha);
    void setTiempo(std::string tiempo);
};

#endif //TRANSACCION_H