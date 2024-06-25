#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include "Persona.h"
#include "Cedula.h"
#include "Cesar.h"
#include "ListaEnlazada.h"

using namespace std;

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

void guardarDatos(const ListaEnlazada<Persona>& listaPersonas) {
    ofstream archivo("datos.txt");
    Nodo<Persona>* actual = listaPersonas.getCabeza();
    while (actual != nullptr) {
        const Persona& persona = actual->getDato();
        archivo << "Nombre 1: " << persona.getNombre1() << endl;
        archivo << "Nombre 2: " << persona.getNombre2() << endl;
        archivo << "Apellido: " << persona.getApellido() << endl;
        archivo << "Cedula: " << persona.getCedula() << endl;
        archivo << "Password generado: " << persona.generarPassword() << endl;
        archivo << "Password encriptado: " << persona.encriptarTexto(persona.generarPassword(), 3) << endl;
        archivo << "Correo: " << persona.getCorreo() << endl;
        archivo << endl;
        actual = actual->getSiguiente();
    }
}

int main() {
    ListaEnlazada<Persona> listaPersonas;
    cargarDatos(listaPersonas);

    Persona nuevaPersona;
    Cedula cedula;

    string nombre1, nombre2, apellido, correo;
    int cesarVariable;

    try {
        cout << "Ingrese primer nombre: ";
        cin >> nombre1;
        nuevaPersona.setNombre1(nombre1);

        cout << "Ingrese segundo nombre: ";
        cin >> nombre2;
        nuevaPersona.setNombre2(nombre2);

        cout << "Ingrese apellido: ";
        cin >> apellido;
        nuevaPersona.setApellido(apellido);

        while (true) {
            cedula.ingresarCedula();
            if (cedulaYaExiste(listaPersonas, cedula.getNumero())) {
                cout << "La cedula ingresada ya existe. Intente con otra." << endl;
            } else {
                nuevaPersona.setCedula(cedula.getNumero());
                break;
            }
        }

        cout << "Ingrese la variable Cesar: ";
        cin >> cesarVariable;

        string passwordGenerado = nuevaPersona.generarPassword();
        string passwordEncriptado = nuevaPersona.encriptarTexto(passwordGenerado, cesarVariable);

        correo = generarCorreo(listaPersonas, nombre1, nombre2, apellido);
        nuevaPersona.setCorreo(correo);

        listaPersonas.insertar(nuevaPersona);

        cout << "Password generado: " << passwordGenerado << endl;
        cout << "Password encriptado: " << passwordEncriptado << endl;
        cout << "Correo: " << correo << endl;

        guardarDatos(listaPersonas);
        cout << "Datos guardados correctamente en datos.txt." << endl;
    }
    catch (const std::invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
