#ifndef POTENCIA_H
#define POTENCIA_H

class Potencia {
public:
    Potencia();
    ~Potencia();
    double calcular(double base, int exponente);

private:
    double* resultado;
};

#endif // POTENCIA_H
