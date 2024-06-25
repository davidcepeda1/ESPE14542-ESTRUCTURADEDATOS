#include <iostream>
#include <string>

using namespace std;

int main(){
    string input;
    cout << "Ingresa un numero entero: ";
    getline(cin, input);

    auto validarParoImpar = [](const string& input) -> string{
        int numero = stoi(input);

        switch (numero % 2)
        {
        case 0:
            cout << "El numero es par" << endl;
            break;
        
        case 1:
            cout << "El numero es impar" << endl;
            break;
        
        default:
            return "Error desconocido";
        }
    };
    string result = validarParoImpar(input);
    cout <<result<<endl;
}