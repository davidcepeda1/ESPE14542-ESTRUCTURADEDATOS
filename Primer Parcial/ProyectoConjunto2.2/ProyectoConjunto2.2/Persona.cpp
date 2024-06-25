#include "Persona.h"
#include "Cesar.h"
#include <algorithm> // Para std::reverse
#include <cctype>    // Para funciones de caracteres
#include <stdexcept> // Para std::invalid_argument

Persona::Persona() : nombre1(""), nombre2(""), apellido(""), correo(""), cedula("") {}

void Persona::setNombre1(const std::string& nombre) {
    for (char c : nombre) {
        if (!isalpha(c)) {
            throw std::invalid_argument("El nombre solo debe contener letras.");
        }
    }
    nombre1 = nombre;
}

void Persona::setNombre2(const std::string& nombre) {
    for (char c : nombre) {
        if (!isalpha(c)) {
            throw std::invalid_argument("El segundo nombre solo debe contener letras.");
        }
    }
    nombre2 = nombre;
}

void Persona::setApellido(const std::string& ape) {
    for (char c : ape) {
        if (!isalpha(c)) {
            throw std::invalid_argument("El apellido solo debe contener letras.");
        }
    }
    apellido = ape;
}

void Persona::setCorreo(const std::string& email) {
    size_t found = email.find("@espe.edu.ec");
    if (found != std::string::npos) {
        correo = email;
    } else {
        throw std::invalid_argument("El correo debe tener el dominio @espe.edu.ec");
    }
}

void Persona::setCedula(const std::string& ced) {
    cedula = ced;
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

std::string Persona::getCorreo() const {
    return correo;
}

std::string Persona::getCedula() const {
    return cedula;
}

std::string Persona::generarPassword() const {
    std::string password;
    password += std::tolower(apellido.back());
    password += std::tolower(nombre1.front());
    if (!nombre2.empty()) {
        password += std::tolower(nombre2.back());
    }
    std::string apellidoReverso = apellido.substr(0, apellido.size() - 1);
    std::reverse(apellidoReverso.begin(), apellidoReverso.end());
    for (char& c : apellidoReverso) {
        c = std::tolower(c);
    }
    password += apellidoReverso;

    return password;
}

std::string Persona::encriptarTexto(const std::string& texto, int cesarVariable) const {
    Cesar cesar;
    std::string textoMinusculas = texto;
    std::transform(texto.begin(), texto.end(), textoMinusculas.begin(), ::tolower);
    return cesar.encriptarTexto(textoMinusculas, cesarVariable);
}
