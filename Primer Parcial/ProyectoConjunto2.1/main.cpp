#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include "Persona.h"
#include "Cedula.h"
#include "Cesar.h"

// Función para cargar los datos existentes desde el archivo datos.txt
void cargarDatos(std::vector<std::string>& datosGuardados) {
    std::ifstream archivo("datos.txt");
    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            datosGuardados.push_back(linea);
        }
        archivo.close();
    }
}

// Función para verificar si una cédula ya existe en los datos cargados
bool cedulaYaExiste(const std::vector<std::string>& datosGuardados, const std::string& cedula) {
    for (const std::string& linea : datosGuardados) {
        std::istringstream iss(linea);
        std::string palabra;
        while (iss >> palabra) {
            if (palabra == "Cedula:" && iss >> palabra && palabra == cedula) {
                return true; // La cédula ya existe
            }
        }
    }
    return false; // La cédula no existe
}

// Función para guardar los datos en el archivo datos.txt
void guardarDatos(const Persona& persona, const Cedula& cedula, const std::string& passwordEncriptado) {
    std::ofstream archivo("datos.txt", std::ios_base::app); // Modo de apertura para agregar al final
    if (archivo.is_open()) {
        archivo << "Nombre 1: " << persona.getNombre1() << "\n";
        archivo << "Nombre 2: " << persona.getNombre2() << "\n";
        archivo << "Apellido: " << persona.getApellido() << "\n";
        archivo << "Cedula: " << cedula.getNumero() << "\n";
        archivo << "Password generado: " << persona.generarPassword(0) << "\n"; // Generar password sin encriptar
        archivo << "Password encriptado: " << passwordEncriptado << "\n";
        archivo << "Correo: " << persona.getCorreo() << "\n\n"; // Guardar el correo electrónico
        archivo.close();
        std::cout << "Datos guardados correctamente en datos.txt.\n";
    } else {
        std::cerr << "No se pudo abrir el archivo para guardar los datos.\n";
    }
}

int main() {
    Persona persona;
    Cedula cedula;
    std::vector<std::string> datosGuardados;

    // Cargar datos existentes desde el archivo datos.txt
    cargarDatos(datosGuardados);

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
        
        // Verificar cédula ingresada
        bool cedulaExistente = cedulaYaExiste(datosGuardados, cedulaNumero);
        while (cedulaExistente) {
            std::cout << "La cedula ingresada ya existe. Intente con otra.\n";
            std::cout << "Ingrese cedula ecuatoriana (10 digitos): ";
            std::cin >> cedulaNumero;
            cedulaExistente = cedulaYaExiste(datosGuardados, cedulaNumero);
        }
        cedula.setNumero(cedulaNumero);

        std::cout << "Ingrese la variable Cesar: ";
        std::cin >> cesarVariable;

        std::string password = persona.generarPassword(0); // Generar password sin encriptar
        std::cout << "Password generado: " << password << "\n";

        std::string passwordEncriptado = persona.encriptarTexto(password, cesarVariable);
        std::cout << "Password encriptado = " << passwordEncriptado << "\n";

        // Crear correo con el formato deseado
        std::string correoGenerado = "";
        correoGenerado += std::tolower(nombre1.front()); // Primera inicial del primer nombre en minúscula
        if (!nombre2.empty()) {
            correoGenerado += std::tolower(nombre2.front()); // Primera inicial del segundo nombre en minúscula si existe
        }
        std::string apellidoMinusculas = apellido;
        std::transform(apellidoMinusculas.begin(), apellidoMinusculas.end(), apellidoMinusculas.begin(), ::tolower);
        correoGenerado += apellidoMinusculas; // Apellido completo en minúscula

        // Generar correo con secuencia si es necesario
        int secuencia = 0;
        for (const std::string& linea : datosGuardados) {
            if (linea.find("Correo: " + correoGenerado + "@espe.edu.ec") != std::string::npos) {
                secuencia++;
            }
        }
        if (secuencia > 0) {
            correoGenerado += std::to_string(secuencia);
        }
        correoGenerado += "@espe.edu.ec"; // Añadir el dominio
        persona.setCorreo(correoGenerado); // Establecer el correo en la persona

        std::cout << "Correo = " << persona.getCorreo() << "\n";

        // Guardar los datos ingresados junto con los datos existentes
        guardarDatos(persona, cedula, passwordEncriptado);

    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
