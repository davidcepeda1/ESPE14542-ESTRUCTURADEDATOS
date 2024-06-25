#include <iostream>
#include <functional>

using namespace std;

class Operacion{
    public:
    Operacion(function<int(int,int)>f) : funcion(f){}

    int ejecutar(int x, int y){
        return funcion(x,y);
    }

private:
    function<int(int,int)>funcion;
};

int main(){
    auto resta = [](int a, int b) {return a - b;};
    Operacion operacionResta(resta);
    cout<<"Resultado de la resta: "<< operacionResta.ejecutar(6,2)<<endl;

    return 0;
}
