#include <iostream>

using namespace std;

template <typename T>
T multiplicar(T a, T b){
    return a * b;
}

int main(){
    
    cout<<"Multiplicacion de enteros: "<<multiplicar(5,2)<<endl;
    cout<<"Multiplicacion de dobles: "<<multiplicar(3.5,2.9)<<endl;

    return 0;
}