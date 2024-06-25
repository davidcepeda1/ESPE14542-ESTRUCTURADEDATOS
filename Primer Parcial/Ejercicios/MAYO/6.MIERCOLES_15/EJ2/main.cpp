#include <iostream>

using namespace std;

template <typename T>
T dividir(T a, T b){
    return a / b;
}

int main(){

    cout<<"Division de enteros: "<<dividir(15,3)<<endl;
    cout<<"Division de dobles: "<<dividir(4.5,2.9)<<endl;

    return 0;
}