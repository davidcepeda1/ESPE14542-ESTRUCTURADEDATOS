#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include "Persona.h"
#include "Cedula.h"
#include "Cesar.h"
#include "ListaEnlazada.h" // Asegúrate de que ListaEnlazada y Nodo estén disponibles aquí

using namespace std;

// Función para cargar datos desde el archivo datos.txt a una ListaEnlazada
void cargarDatos(ListaEnlazada<Persona>& listaPersonas) {
    ifstream archivo("datos.txt");
    if (archivo.is_open()) {
        string linea, nombre1, nombre2, apellido, cedula, passwordGenerado, passwordEncriptado, correo;
        while (getline(archivo, linea)) {
            if (linea.find("Nombre 1:") != string::npos) {
                nombre1 = linea.substr(linea.find(":") + 2);
                getline(archivo, linea);
                nombre2 = linea.substr(linea.find(":") + 2);
                getline(archivo, linea);
                apellido = linea.substr(linea.find(":") + 2);
                getline(archivo, linea);
                cedula = linea.substr(linea.find(":") + 2);
                getline(archivo, linea);
                passwordGenerado = linea.substr(linea.find(":") + 2);
                getline(archivo, linea);
                passwordEncriptado = linea.substr(linea.find(":") + 2);
                getline(archivo, linea);
                correo = linea.substr(linea.find(":") + 2);

                Persona persona;
                persona.setNombre1(nombre1);
                persona.setNombre2(nombre2);
                persona.setApellido(apellido);
                persona.setCorreo(correo);
                persona.setCedula(cedula);

                listaPersonas.insertar(persona);
            }
        }
        archivo.close();
    }
}

// Función para verificar si una cédula ya existe en la lista de personas
bool cedulaYaExiste(const ListaEnlazada<Persona>& listaPersonas, const string& cedula) {
    Nodo<Persona>* actual = listaPersonas.getCabeza();
    while (actual != nullptr) {
        if (actual->getDato().getCedula() == cedula) {
            return true;
        }
        actual = actual->getSiguiente();
    }
    return false;
}

// Función para generar un correo único para la persona
string generarCorreo(const ListaEnlazada<Persona>& listaPersonas, const string& nombre1, const string& nombre2, const string& apellido) {
    string correoBase = string(1, tolower(nombre1.front())) + string(1, tolower(nombre2.front())) + apellido + "@espe.edu.ec";
    string correo = correoBase;
    int contador = 1;

    Nodo<Persona>* actual = listaPersonas.getCabeza();
    while (actual != nullptr) {
        if (actual->getDato().getCorreo() == correo) {
            correo = correoBase + to_string(contador);
            contador++;
        }
        actual = actual->getSiguiente();
    }

    return correo;
}

// Función para guardar los datos de la persona en el archivo datos.txt
void guardarDatos(const Persona& persona, const string& passwordEncriptado) {
    ofstream archivo("datos.txt", ios_base::app);
    if (archivo.is_open()) {
        archivo << persona.getNombre1() << "," << persona.getNombre2() << "," <<persona.getApellido() << ","<< persona.getCedula() << "," << persona.getCorreo() << "," << persona.generarPassword() << "," << passwordEncriptado <<"\n";
        archivo.close();
        cout << "Datos guardados correctamente en datos.txt.\n";
    } else {
        cerr << "No se pudo abrir el archivo para guardar los datos.\n";
    }
}

int main() {
    ListaEnlazada<Persona> listaPersonas;
    cargarDatos(listaPersonas);

    Persona persona;
    Cedula cedula;
    string nombre1, nombre2, apellido, cedulaNumero;
    int cesarVariable;

    try {
        cout << "Ingrese primer nombre: ";
        cin >> nombre1;
        persona.setNombre1(nombre1);

        cout << "Ingrese segundo nombre: ";
        cin >> nombre2;
        persona.setNombre2(nombre2);

        cout << "Ingrese apellido: ";
        cin >> apellido;
        persona.setApellido(apellido);

        // Validación y entrada de la cédula
        do {
            try {
                cedula.setNumero();
                if (!cedula.validarCedula()) {
                    std::cout << "La cédula ingresada no es válida. Intente de nuevo." << std::endl;
                } else if (cedulaYaExiste(listaPersonas, cedula.getNumero())) {
                    std::cout << "La cédula ingresada ya existe. Intente con otra." << std::endl;
                }
            } catch (const std::invalid_argument& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        } while (!cedula.validarCedula() || cedulaYaExiste(listaPersonas, cedula.getNumero()));

        std::cout << "Cédula válida: " << cedula.getNumero() << std::endl;

        cout << "Ingrese la variable Cesar: ";
        cin >> cesarVariable;

        string correo = generarCorreo(listaPersonas, nombre1, nombre2, apellido);
        persona.setCorreo(correo);

        string passwordGenerado = persona.generarPassword();
        string passwordEncriptado = persona.encriptarTexto(passwordGenerado, cesarVariable);

        guardarDatos(persona, passwordEncriptado);

        cout << "Password generado: " << passwordGenerado << "\n";
        cout << "Password encriptado: " << passwordEncriptado << "\n";
        cout << "Correo: " << correo << "\n";

        listaPersonas.insertar(persona);
    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
