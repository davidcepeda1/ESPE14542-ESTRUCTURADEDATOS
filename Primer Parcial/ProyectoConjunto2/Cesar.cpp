#include "Cesar.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>

using namespace std;

string cifrarCesar(const string& texto, int desplazamiento) {
    string resultado = texto;
    for (char& c : resultado) {
        if (isalpha(c)) {
            char limite = isupper(c) ? 'A' : 'a';
            c = limite + (c - limite + desplazamiento) % 26;
        }
    }
    return resultado;
}

string descifrarCesar(const string& texto, int desplazamiento) {
    return cifrarCesar(texto, 26 - desplazamiento);
}

bool esEntero(const string& str) {
    for (char const &c : str) {
        if (!isdigit(c)) return false;
    }
    return true;
}

string ingresar(const string& mensaje, bool soloNumeros) {
    string entrada;
    while (true) {
        cout << mensaje << ": ";
        getline(cin, entrada);

        if (soloNumeros && !esEntero(entrada)) {
            cout << "Entrada invalida. Debe ingresar solo numeros." << endl;
        } else {
            break;
        }
    }
    return entrada;
}

string generarPassword(const string& nombre1, const string& nombre2, const string& apellido) {
    char ultimaInicialApellido = apellido.back();
    char primeraInicialNombre = nombre1.front();
    char ultimaInicialNombre2 = nombre2.back();
    string apellidoReves = apellido.substr(0, apellido.size() - 1);
    reverse(apellidoReves.begin(), apellidoReves.end());

    return string(1, ultimaInicialApellido) + primeraInicialNombre + ultimaInicialNombre2 + apellidoReves;
}
