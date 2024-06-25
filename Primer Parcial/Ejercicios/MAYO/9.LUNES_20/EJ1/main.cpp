#include <iostream>
#include "CalculoTemplate.cpp"

using namespace std;

int main(){
    
    int a, b;

    std::cout << "Ingrese el primer valor: ";
    std::cin >> a;

    std::cout << "Ingrese el segundo valor: ";
    std::cin >> b;

    Operaciones<double> intCalculo(a, b);
    intCalculo.calculo();
}