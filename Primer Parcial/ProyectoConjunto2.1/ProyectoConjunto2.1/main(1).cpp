#include <iostream>
#include <fstream>   // Para manejo de archivos
#include <stdexcept> // Para std::invalid_argument
#include "Persona.h"
#include "Cedula.h"
#include "Cesar.h"

void guardarDatos(const Persona& persona, const Cedula& cedula, const std::string& passwordEncriptado) {
    std::ofstream archivo("datos.txt");
    if (archivo.is_open()) {
        archivo << "Nombre 1: " << persona.getNombre1() << "\n";
        archivo << "Nombre 2: " << persona.getNombre2() << "\n";
        archivo << "Apellido: " << persona.getApellido() << "\n";
        archivo << "Cedula: " << cedula.getNumero() << "\n";
        archivo << "Password generado: " << persona.generarPassword(0) << "\n"; // Generar password sin encriptar
        archivo << "Password encriptado: " << passwordEncriptado << "\n"; // Mostrar el password encriptado
        archivo.close();
        std::cout << "Datos guardados correctamente en datos.txt.\n";
    } else {
        std::cerr << "No se pudo abrir el archivo para guardar los datos.\n";
    }
}

int main() {
    Persona persona;
    Cedula cedula;

    std::string nombre1, nombre2, apellido, cedulaNumero;
    int cesarVariable;

    try {
        std::cout << "Ingrese primer nombre: ";
        std::cin >> nombre1;
        persona.setNombre1(nombre1);

        std::cout << "Ingrese segundo nombre: ";
        std::cin >> nombre2;
        persona.setNombre2(nombre2);

        std::cout << "Ingrese apellido: ";
        std::cin >> apellido;
        persona.setApellido(apellido);

        std::cout << "Ingrese cedula ecuatoriana (10 digitos): ";
        std::cin >> cedulaNumero;
        if (!cedula.validarCedula(cedulaNumero)) {
            throw std::invalid_argument("La cedula ingresada no es valida.");
        }
        cedula.setNumero(cedulaNumero);

        std::cout << "Ingrese la variable Cesar: ";
        std::cin >> cesarVariable;

        std::string password = persona.generarPassword(0); // Generar password sin encriptar
        std::cout << "Password generado: " << password << "\n";

        std::string passwordEncriptado = persona.encriptarTexto(password, cesarVariable);
        std::cout << "Password encriptado = " << passwordEncriptado << "\n";

        guardarDatos(persona, cedula, passwordEncriptado);

    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
