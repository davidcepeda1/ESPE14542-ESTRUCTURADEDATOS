#include <iostream>

using namespace std;

template <typename T>
T maximo(T a, T b){
    return (a > b) ? a : b;
}

int main(){
    cout<<"Maximo entre 3 y 7: "<<maximo(3,7)<<endl;
    cout<<"Maximo entre 4 y 10: "<<maximo(4,10)<<endl;

    return 0;
}