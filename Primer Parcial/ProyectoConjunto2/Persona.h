#pragma once

#include <string>
#include <iostream>

using namespace std;

class Persona {
public:
    Persona(string nombre1 = "", string nombre2 = "", string apellido = "", string cedula = "");
    string generarSecuenciaNombre() const;
    string generarEmail() const;
    void setCorreo(const string& correo);
    void setPassword(const string& password); // Declaración de setPassword
    void setOriginalPassword(const string& password); // Declaración de setOriginalPassword
    string getCedula() const;
    string getNombre1() const;
    string getNombre2() const;
    string getApellido() const;
    string getCorreo() const;
    string getPassword() const; // Declaración de getPassword
    string getOriginalPassword() const; // Declaración de getOriginalPassword
    friend ostream& operator<<(ostream& os, const Persona& persona);

private:
    string nombre1;
    string nombre2;
    string apellido;
    string cedula;
    string correo;
    string password;
    string originalPassword; // Original password before encryption
};
