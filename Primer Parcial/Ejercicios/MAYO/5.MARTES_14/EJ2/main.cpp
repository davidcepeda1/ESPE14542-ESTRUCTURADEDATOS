#include <iostream>

using namespace std;

template<typename T1, typename T2>
class Pareja{
    private:
        T1 primero;
        T2 segundo;
    public:
        Pareja(T1 p, T2 s) : primero(p), segundo(s) {}
        void mostrar(){
            cout<<"Primero: "<<primero<<" , Segundo: "<<segundo<<endl;
        }
};

int main(){
    Pareja<int, double> p1(1, 1.1);
    p1.mostrar();

    Pareja<string, int> p2("Edad", 30);
    p2.mostrar();

    return 0;
}