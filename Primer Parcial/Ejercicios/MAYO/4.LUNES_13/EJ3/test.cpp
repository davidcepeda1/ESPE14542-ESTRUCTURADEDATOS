#include <iostream>
#include <functional>

using namespace std;

void ejecutar(function<int(int,int)>operacion){
    cout<<"Resultado de la operacion: "<<operacion(5,3)<<endl;
};

int main(){
    auto multiplicacion = [](int a, int b){return a * b;};
    ejecutar(multiplicacion);

    return 0;
}