#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename Container>
typename Container::value_type encontrarMaximo(const Container& contenedor){
    return *max_element(contenedor.begin(), contenedor.end());
}

int main(){
    vector<int> numeros = {5,3,9,7,1};
    cout<<"Maximo elemento del vector: "<<encontrarMaximo(numeros)<<endl;

    vector<double> valores = {3.5,1.2,7.8,-1.5,2.6};
    cout<<"Maximo elemento del vector: "<<encontrarMaximo(valores)<<endl;

    return 0;
}