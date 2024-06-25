#include <iostream>

using namespace std;

template <typename T>
T minimo(T a, T b){
    return (a < b) ? a : b;
}

int main(){
    cout<<"Minimo entre 3 y 7: "<<minimo(3,7)<<endl;
    cout<<"Minimo entre 4 y 10: "<<minimo(4,10)<<endl;

    return 0;
}