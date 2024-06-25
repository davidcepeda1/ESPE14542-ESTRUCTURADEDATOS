#pragma once
#include <iostream>
#include "Persona.h"

using namespace std;

class Encriptacion{
public:
    virtual string generarSecuenciaContrasena() = 0;
    virtual string cifrarCesar(const string& secuencia) = 0;
};