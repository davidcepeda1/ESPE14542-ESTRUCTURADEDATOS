#include <iostream>
#include <string>

void decimalToBinario(int numero, std::string& binario) {
    if (numero == 0) return;
    
    decimalToBinario(numero / 2, binario);
    binario += std::to_string(numero % 2);
}

int main() {
    int numero = 25;
    std::string binario = "";
    
    decimalToBinario(numero, binario);
    
    std::cout << "El numero binario de " << numero << " es: " << binario << std::endl;

    return 0;
}

