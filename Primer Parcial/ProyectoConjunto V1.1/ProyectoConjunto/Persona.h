#pragma once

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Persona {
public:
    Persona(const string& nombre1, const string& nombre2, const string& apellido, const string& cedula);
    string generarSecuenciaNombre() const;
    string generarEmail() const;
    string getCedula() const;
    string getNombre1() const;
    string getNombre2() const;
    string getApellido() const;
    friend ostream& operator<<(ostream& os, const Persona& persona);

private:
    string nombre1;
    string nombre2;
    string apellido;
    string cedula;
};
