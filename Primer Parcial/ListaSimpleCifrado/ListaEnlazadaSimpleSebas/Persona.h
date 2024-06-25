#pragma once
#include <iostream>
#include "Interfaz.h"

using namespace std;

class Persona: public Encriptacion
{
private:
    string nombre;
    string nombre2;
    string apellido;
    string cedula;
    string correo;
public:
    Persona();
    Persona(string,string,string,string,string);
    void setPersona(string);
    string getPersona();
    void setNombre2(string);
    string getNombre2();
    void setApellido(string);
    string getApellido();
    void setCedula(string);
    string getCedula();
    void setCorreo(string);
    string getCorreo();
    string generarSecuenciaContrasena()override;
    string cifrarCesar(const string& secuencia)override;
    string generarContrasenacifrada();
    bool operator==(const Persona& otra) const;
    bool operator!=(const Persona& otra) const;
    friend std::ostream& operator<<(std::ostream& os, const Persona& persona);
};

