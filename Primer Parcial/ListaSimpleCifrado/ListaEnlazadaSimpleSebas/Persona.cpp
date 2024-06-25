#include <iostream>
#include "Persona.h"
#include <string.h>

Persona::Persona(): 
nombre(""), nombre2(""),apellido(""),cedula(""), correo("")
{
}

Persona::Persona(std::string nombre,std::string nombre2,std::string apellido,std::string cedula,std::string correo): 
nombre(nombre), nombre2(nombre2),apellido(apellido),cedula(cedula), correo(correo)
{
}

void Persona::setPersona(std::string nombre){
    this->nombre = nombre;
}

void Persona::setNombre2(std::string nombre2){
    this->nombre2 = nombre2;
}

void Persona::setApellido(std::string apellido){
    this->apellido = apellido;
}

void Persona::setCedula(std::string cedula){
    this->cedula = cedula;
}

void Persona::setCorreo(std::string correo){
    this->correo = correo;
}

std::string Persona::getCorreo(){
    return correo;
}

std::string Persona::getCedula(){
    return cedula;
}

std::string Persona::getApellido(){
    return apellido;
}

std::string Persona::getNombre2(){
    return nombre2;
}

std::string Persona::getPersona(){
    return nombre;
}

std::string Persona::generarSecuenciaContrasena()
{
    /*string sec = "";
    sec += tolower(apellido.at(apellido.size() - 1));
    sec += tolower(nombre.at(0));
    if (nombre2.length() != 0) {
        sec += tolower(nombre2.at(nombre2.size()-1));
    }
    else
    {
        sec += tolower(nombre.at(nombre.size() - 1));
    }
 
    string secfin = apellido.substr(0, apellido.length()-1);
    reverse(secfin.begin(), secfin.end());
   
    sec.append(secfin);
    return sec;*/
    string sec = "";

    if (!apellido.empty()) {
        sec += tolower(apellido.at(apellido.size() - 1));
    }

    if (!nombre.empty()) {
        sec += tolower(nombre.at(0));
    }

    if (!nombre2.empty()) {
        sec += tolower(nombre2.at(nombre2.size() - 1));
    } else {
        sec += tolower(nombre.at(nombre.size() - 1));
    }

    string secfin = apellido.substr(0, apellido.length() - 1);
    reverse(secfin.begin(), secfin.end());

    sec.append(secfin);
    return sec;
}

std::string Persona::cifrarCesar(const string& secuencia)  {
   
    std::string scifrado;
    auto limitar = [](char c) -> char {
        if (c > 'z') return c - 26;
        if (c < 'a') return c + 26;
        return c;
        };
    int desplazamiento = 2;

    for (int i = 0; i < secuencia.length(); i++) {
        scifrado += limitar(tolower(secuencia.at(i)) + desplazamiento);
    }

    return scifrado;
}

string Persona::generarContrasenacifrada() {
    string secuencia = generarSecuenciaContrasena();
    return cifrarCesar(secuencia);
}

bool Persona::operator==(const Persona& otra) const{
    return nombre == otra.nombre, nombre2 == otra.nombre2, apellido == otra.apellido, cedula == otra.cedula, correo == otra.correo;
}
std::ostream& operator<<(std::ostream& os, const Persona& persona){
    os << persona.nombre << persona.nombre2 << persona.apellido << persona.cedula << persona.correo;
    return os;
}

bool Persona::operator!=(const Persona& otra) const {
    return !(*this == otra);
}