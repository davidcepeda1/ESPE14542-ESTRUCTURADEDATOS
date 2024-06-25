#pragma once
#include <string>

class Persona {
private:
    std::string nombre1;
    std::string nombre2;
    std::string apellido;

public:
    Persona();
    void setNombre1(const std::string& nombre);
    void setNombre2(const std::string& nombre);
    void setApellido(const std::string& apellido);
    std::string getNombre1() const;
    std::string getNombre2() const;
    std::string getApellido() const;
    std::string generarPassword(int cesarVariable) const;
    std::string encriptarTexto(const std::string& texto, int cesarVariable) const;
};
