#include <iostream>
#include <functional>

using namespace std;

void ejecutarOperacion(function<int(int,int)> operacion){
    cout << "Resultado de la operacion: "<< operacion(4,3)<<endl;
}

int main(){
    auto multiplicacion = [](int a,int b){return a * b; };
    ejecutarOperacion(multiplicacion);
    return 0;
}