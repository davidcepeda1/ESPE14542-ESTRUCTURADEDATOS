#include <iostream>
#include "Matriz.h"

using namespace std;

int main(){
    int filas;
    int columnas;

    cout<<"Ingrese el número de filas de las matrices: "<<endl;
    cin>>filas;
    cout<<"Ingrese el número de columnas de las matrices: "<<endl;
    cin>>columnas;

    Matriz<int> matriz1(filas, columnas);
    Matriz<int> matriz2(filas, columnas);

    cout<<"Ingrese los datos para la primera matriz: "<<endl;
    matriz1.ingresarDatos();
    cout<<"Ingrese los datos para la segunda matriz: "<<endl;
    matriz2.ingresarDatos();

    try{
        Matriz<int> resultado = matriz1 + matriz2;

        cout<<"Resultado de la suma de matrices: "<<endl;
        resultado.mostrar();
    }catch (const invalid_argument& e){
        cerr<<e.what()<<endl;
    }
    return 0;
}
