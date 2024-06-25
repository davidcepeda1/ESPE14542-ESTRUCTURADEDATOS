#pragma once
#include <string>

class Cedula {
private:
    std::string numero;

public:
    Cedula();
    bool validarCedula(const std::string& cedula);
    void setNumero(const std::string& num);
    std::string getNumero() const;
};
