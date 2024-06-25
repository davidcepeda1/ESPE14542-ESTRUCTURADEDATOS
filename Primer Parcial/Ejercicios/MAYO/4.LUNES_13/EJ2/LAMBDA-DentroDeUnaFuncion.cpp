#include <iostream>
#include <functional>

using namespace std;

void ejecutarOperacion(function<int(int, int)> operacion){
    cout<<"Resultado de la operacion: "<<operacion(7,9)<<endl;
    };
    
int main(){
    auto suma = [](int a, int b) {return a + b;};
    ejecutarOperacion(suma);
    return 0;
}