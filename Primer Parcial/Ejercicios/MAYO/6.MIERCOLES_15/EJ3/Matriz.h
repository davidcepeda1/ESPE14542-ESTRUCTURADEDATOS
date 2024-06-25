#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>

using namespace std;

template <typename T>

class Matriz{
    private:
        int filas;
        int columnas;
        T** datos;
    public:
        Matriz(int f, int c);
        ~Matriz();
        
        void ingresarDatos();
        void mostrar();
        Matriz<T> operator+(const Matriz<T>& otra);
};

#endif