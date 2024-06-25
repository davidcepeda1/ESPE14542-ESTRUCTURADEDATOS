#pragma once

#include <string>

class Cedula {
public:
    Cedula(const std::string& numero);
    bool esValida() const;

private:
    std::string numero;
};
