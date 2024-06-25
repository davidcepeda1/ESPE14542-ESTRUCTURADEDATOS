#include "Cesar.h"

std::string Cesar::encriptarTexto(const std::string& texto, int cesarVariable) const {
    // Implementación del cifrado César
    std::string resultado = texto;
    for (char& c : resultado) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = (c - base + cesarVariable) % 26 + base;
        }
    }
    return resultado;
}
