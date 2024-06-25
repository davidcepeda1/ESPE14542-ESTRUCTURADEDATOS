#pragma once
#include <iostream>
#include <string>

class Cedula {
private:
    std::string numero;

public:
    Cedula();

    void setNumero();
    std::string getNumero() const;

    bool validarCedula() const; // Método para validar la cédula asociada a este objeto

    // Método estático para ingresar números
    static std::string ingresar(const std::string& msj);
};
