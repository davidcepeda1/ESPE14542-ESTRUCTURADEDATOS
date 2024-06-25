#pragma once

#include <string>

using namespace std;

class Cedula {
public:
    Cedula(const string& numero);
    bool esValida() const;

private:
    string numero;
};
