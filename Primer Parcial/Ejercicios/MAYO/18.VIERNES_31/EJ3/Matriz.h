#ifndef MULTIPLICACION_MATRICES_H
#define MULTIPLICACION_MATRICES_H

class MultiplicacionMatrices {
public:
    MultiplicacionMatrices(int filasA, int colsA, int filasB, int colsB);
    ~MultiplicacionMatrices();
    void inicializarMatrizA(int** matriz);
    void inicializarMatrizB(int** matriz);
    int** multiplicar();
    void imprimirResultado();

private:
    int** matrizA;
    int** matrizB;
    int** resultado;
    int filasA;
    int colsA;
    int filasB;
    int colsB;
    void multiplicarRecursivo(int i, int j, int k);
};

#endif // MULTIPLICACION_MATRICES_H
