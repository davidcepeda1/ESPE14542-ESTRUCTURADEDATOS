#include <iostream>

using namespace std;

template <typename T>
void intercambiar(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

int main(){
    int x = 150;
    int y = 22;

    cout<<"Resultado antes de intercambiar: x = "<<x<<" , y = "<<y<<endl;
    intercambiar(x,y);
    cout<<"Resultado despues de intercambiar: x = "<<x<<" , y = "<<y<<endl;

    return 0;
}