#include "Cesar.h"

std::string Cesar::encriptarTexto(const std::string& texto, int cesarVariable) const {
    std::string resultado;
    for (char c : texto) {
        if (isalpha(c)) {
            char offset = islower(c) ? 'a' : 'A';
            c = (c - offset + cesarVariable) % 26 + offset;
        }
        resultado += c;
    }
    return resultado;
}
