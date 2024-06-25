#pragma once
#include <iostream>
#include <string>

class Persona {
private:
    std::string nombre1;
    std::string nombre2;
    std::string apellido;
    std::string correo;
    std::string cedula;

public:
    Persona();

    void setNombre1(const std::string& nombre);
    void setNombre2(const std::string& nombre);
    void setApellido(const std::string& ape);
    void setCorreo(const std::string& email);
    void setCedula(const std::string& ced);

    std::string getNombre1() const;
    std::string getNombre2() const;
    std::string getApellido() const;
    std::string getCorreo() const;
    std::string getCedula() const;

    std::string generarPassword() const;
    std::string encriptarTexto(const std::string& texto, int cesarVariable) const;
};
