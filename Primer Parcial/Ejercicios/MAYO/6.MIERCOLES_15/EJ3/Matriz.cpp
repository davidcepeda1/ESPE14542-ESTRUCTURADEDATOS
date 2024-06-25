#include <iostream>
#include <stdexcept>
#include "Matriz.h"

using namespace std;

template <typename T>
Matriz<T>::Matriz(int f, int c) : filas(f), columnas(c){
    datos = new T*[filas];
    for (int i = 0; i < filas; ++i){
        datos[i] = new T[columnas];
    }
}

template <typename T>
Matriz<T>::~Matriz(){
    for (int i = 0; i < filas; ++i){
        delete[] datos[i];
    }
    delete[] datos;
}

template <typename T>
void Matriz<T>::ingresarDatos(){
    cout<<"Ingrese los elementos de la matriz ("<<filas<<"x"<<columnas<<"):"<<endl;
    for(int i = 0; i < filas; ++i){
        for(int j = 0; j < columnas; ++j){
            cout<<"Elemento ["<<i<<"]["<<j<<"]: ";
            cin>>datos[i][j];
        }
    }
}

template <typename T>
void Matriz<T>::mostrar(){
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout<<datos[i][j]<<" ";
        }
        cout<<endl;
    }
}

template <typename T>
Matriz<T> Matriz<T>::operator+(const Matriz<T>& otra){
    if (filas != otra.filas || columnas != otra.columnas){
        throw invalid_argument("Las matrices deben tener las mismas dimensiones para sumarse");
    }
    Matriz<T> resultado(filas, columnas);
    for(int i = 0; i < filas; ++i){
        for(int j = 0; j < columnas; ++j){
            resultado.datos[i][j] = datos[i][j] + otra.datos[i][j];
        }
    }
    return resultado;
}

template class Matriz<int>;