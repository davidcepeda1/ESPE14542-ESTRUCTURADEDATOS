#include "Persona.h"
#include <algorithm>

using namespace std;

Persona::Persona(string nombre1, string nombre2, string apellido, string cedula)
    : nombre1(nombre1), nombre2(nombre2), apellido(apellido), cedula(cedula) {}

string Persona::generarSecuenciaNombre() const {
    string secuencia = nombre1.substr(0, 1) + nombre2.substr(0, 1) + apellido;
    transform(secuencia.begin(), secuencia.end(), secuencia.begin(), ::tolower);
    return secuencia;
}

string Persona::generarEmail() const {
    return generarSecuenciaNombre() + "@espe.edu.ec";
}

void Persona::setCorreo(const string& correo) {
    this->correo = correo;
}

void Persona::setPassword(const string& password) {
    this->password = password;
}

void Persona::setOriginalPassword(const string& password) { // Add this method
    this->originalPassword = password;
}

string Persona::getCedula() const {
    return cedula;
}

string Persona::getNombre1() const {
    return nombre1;
}

string Persona::getNombre2() const {
    return nombre2;
}

string Persona::getApellido() const {
    return apellido;
}

string Persona::getCorreo() const {
    return correo;
}

string Persona::getPassword() const {
    return password;
}

string Persona::getOriginalPassword() const { // Add this method
    return originalPassword;
}

ostream& operator<<(ostream& os, const Persona& persona) {
    os << persona.nombre1 << " " << persona.nombre2 << " " << persona.apellido << " " << persona.correo << " " << persona.cedula;
    return os;
}
