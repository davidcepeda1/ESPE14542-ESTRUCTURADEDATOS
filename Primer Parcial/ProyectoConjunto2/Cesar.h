#pragma once

#include <string>

using namespace std;

bool esEntero(const string& str);
string ingresar(const string& mensaje, bool soloNumeros);
string generarPassword(const string& nombre1, const string& nombre2, const string& apellido);
string cifrarCesar(const string& texto, int desplazamiento);
string descifrarCesar(const string& texto, int desplazamiento);
