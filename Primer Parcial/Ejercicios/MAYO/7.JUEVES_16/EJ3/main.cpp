#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    cout << "Ingresa el numero del mes (1-12): ";
    cin >> input;

    auto identifySeason = [](const string& str) {
        int month = stoi(str);
        
        switch (month) {
            case 12: case 1: case 2:
                return "Es invierno.";
            case 3: case 4: case 5:
                return "Es primavera.";
            case 6: case 7: case 8:
                return "Es verano.";
            case 9: case 10: case 11:
                return "Es otono.";
            default:
                return "Mes invalido.";
        }
    };

    string result = identifySeason(input);
    cout << result << endl;

    return 0;
}
