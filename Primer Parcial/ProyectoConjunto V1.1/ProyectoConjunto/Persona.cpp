#include <string.h>
#include "Persona.h"
#include <vector>

using namespace std;

Persona::Persona(const string& nombre1, const string& nombre2, const string& apellido, const string& cedula)
    : nombre1(nombre1), nombre2(nombre2), apellido(apellido), cedula(cedula) {}

string Persona::generarSecuenciaNombre() const {
    return nombre1.substr(0, 1) + nombre2.substr(0, 1) + apellido;
}

string Persona::generarEmail() const {
    string emailBase = nombre1.substr(0, 1) + nombre2.substr(0, 1) + apellido + "@espe.edu.ec";
    transform(emailBase.begin(), emailBase.end(), emailBase.begin(), ::tolower);
    return emailBase;
}

string Persona::getCedula() const {
    return cedula;
}

string Persona::getNombre1() const {
    return nombre1;
}

std::string Persona::getNombre2() const {
    return nombre2;
}

std::string Persona::getApellido() const {
    return apellido;
}

std::ostream& operator<<(std::ostream& os, const Persona& persona) {
    os << "Nombre: " << persona.nombre1 << " " << persona.nombre2 << " " << persona.apellido;
    os << ", Email: " << persona.generarEmail();
    os << ", Cedula: " << persona.cedula;
    return os;
}
