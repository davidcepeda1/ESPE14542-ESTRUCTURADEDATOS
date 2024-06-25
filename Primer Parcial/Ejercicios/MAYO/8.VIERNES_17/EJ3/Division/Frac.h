#include <iostream>

class Frac {
private:
    int a; // numerador
    int b; // denominador
public:
    Frac() : a(0), b(0) {}
    void in();
    Frac operator*(const Frac &obj);
    Frac operator/(const Frac &obj); // Sobrecarga del operador /
    void out();
};
