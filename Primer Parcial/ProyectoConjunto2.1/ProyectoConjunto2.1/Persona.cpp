#include "Persona.h"
#include "Cesar.h"
#include <algorithm> // Para std::reverse
#include <cctype>    // Para funciones de caracteres
#include <stdexcept> // Para std::invalid_argument

Persona::Persona() : nombre1(""), nombre2(""), apellido("") {}

void Persona::setNombre1(const std::string& nombre) {
    // Validar que solo tenga letras
    for (char c : nombre) {
        if (!isalpha(c)) {
            throw std::invalid_argument("El nombre solo debe contener letras.");
        }
    }
    nombre1 = nombre;
}

void Persona::setNombre2(const std::string& nombre) {
    // Validar que solo tenga letras
    for (char c : nombre) {
        if (!isalpha(c)) {
            throw std::invalid_argument("El segundo nombre solo debe contener letras.");
        }
    }
    nombre2 = nombre;
}

void Persona::setApellido(const std::string& ape) {
    // Validar que solo tenga letras
    for (char c : ape) {
        if (!isalpha(c)) {
            throw std::invalid_argument("El apellido solo debe contener letras.");
        }
    }
    apellido = ape;
}

std::string Persona::getNombre1() const {
    return nombre1;
}

std::string Persona::getNombre2() const {
    return nombre2;
}

std::string Persona::getApellido() const {
    return apellido;
}

std::string Persona::generarPassword(int cesarVariable) const {
    // Generar password según método César
    std::string password;
    password += apellido.back(); // Última inicial del apellido
    password += nombre1.front(); // Primera inicial del primer nombre
    if (!nombre2.empty()) {
        password += nombre2.back(); // Última inicial del segundo nombre si existe
    }
    std::string apellidoReverso = apellido.substr(0, apellido.size() - 1); // Apellido sin la última letra
    std::reverse(apellidoReverso.begin(), apellidoReverso.end());
    password += apellidoReverso;

    return password;
}

std::string Persona::encriptarTexto(const std::string& texto, int cesarVariable) const {
    // Utilizar clase Cesar para encriptar texto
    Cesar cesar;
    return cesar.encriptarTexto(texto, cesarVariable);
}