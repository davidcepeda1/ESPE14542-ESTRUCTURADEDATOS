#pragma once

#include "Nodo.h"
#include "Persona.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class ListaEnlazadaDoble {
private:
    NodoDoble<Persona>* cabeza;

    vector<string> leerCorreos() {
        vector<string> correos;
        ifstream archivo("correos.txt");
        string linea;
        while (getline(archivo, linea)) {
            correos.push_back(linea);
        }
        archivo.close();
        return correos;
    }

public:
    ListaEnlazadaDoble() : cabeza(nullptr) {}

    ~ListaEnlazadaDoble() {
        while (cabeza) {
            NodoDoble<Persona>* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }

    bool cedulaExiste(const string& cedula) {
        ifstream archivo("correos.txt");
        string linea;
        while (getline(archivo, linea)) {
            if (linea.find(cedula) != string::npos) {
                return true;
            }
        }
        return false;
    }

    void insertar(const Persona& dato) {
        if (cedulaExiste(dato.getCedula())) {
            std::cout << "Cedula con ese ID ya esta creada" << endl;
            return;
        }

        NodoDoble<Persona>* nuevo = new NodoDoble<Persona>(dato);
        nuevo->siguiente = cabeza;
        if (cabeza) cabeza->anterior = nuevo;
        cabeza = nuevo;
        generarCorreo(dato.generarEmail(), dato.getCedula(), dato);
    }

    void recorrer(function<void(const Persona&)> callback) const {
        NodoDoble<Persona>* temp = cabeza;
        while (temp) {
            callback(temp->dato);
            temp = temp->siguiente;
        }
    }

    void mostrar() const {
        recorrer([](const Persona& dato) {
            cout << dato << endl;
        });
    }

    void guardarEnArchivo() const {
        ofstream archivo("correos.txt");
        if (archivo.is_open()) {
            NodoDoble<Persona>* actual = cabeza;
            while (actual) {
                archivo << actual->dato.generarEmail() << " "
                        << actual->dato.generarSecuenciaNombre() << " "
                        << actual->dato.getCedula() << std::endl;
                actual = actual->siguiente;
            }
            archivo.close();
        } else {
            cout << "No se pudo abrir el archivo para escribir." << endl;
        }
    }

    string generarCorreo(const string& correo, const string& cedula, const Persona& persona) {
        string correoBase = correo.substr(0, correo.find("@"));
        vector<string> correosExistentes = leerCorreos();
        string correoCompleto = correo;
        int contador = 1;
        while (find(correosExistentes.begin(), correosExistentes.end(), correoCompleto) != correosExistentes.end()) {
            correoCompleto = correoBase + to_string(contador) + "@espe.edu.ec";
            contador++;
        }

        guardarCorreo(correoCompleto, persona);
        return correoCompleto;
    }

    void guardarCorreo(const string& correo, const Persona& persona) {
        ofstream archivo("correos.txt", ios::app);
        if (archivo.is_open()) {
            archivo << persona.getNombre1() << " "
                    << persona.getNombre2() << " "
                    << persona.getApellido() << " "
                    << correo << " "
                    << persona.getCedula() << std::endl;
            archivo.close();
        }
    }
};
