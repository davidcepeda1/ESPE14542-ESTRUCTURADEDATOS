#include <iostream>
#include <string>

using namespace std;

int main(){
    string input;
    cout<<"Ingresa un numero entero: ";
    cin>>input;

    auto chequearSigno = [](const string& str){
        int num = stoi(str);

        switch (num>0 ? 1 : (num < 0 ? -1 : 0))
        {
        case 1:
            return "El numero es positivo";
        case -1:
            return "El numero es negativo";
        case 0:
            return "El numero es 0";
        default:
            return "Error desconocido";
        }
    };
    string result = chequearSigno(input);
    cout<<result<<endl;
}