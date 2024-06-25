#pragma once

#include "Nodo.h"
#include "Persona.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

template <class T>
class ListaSimple {
private:
    Nodo<T>* head;
    int size;

public:
    ListaSimple() : head(nullptr), size(0) {}

    ~ListaSimple() {
        while (head) {
            Nodo<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insertarAlInicio(T data) {
        Nodo<T>* newNode = new Nodo<T>(data);
        newNode->next = head;
        head = newNode;
        size++;
    }

    void eliminarAlInicio() {
        if (head == nullptr) return;

        Nodo<T>* temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    void mostrar() const {
        Nodo<T>* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    int getSize() const {
        return size;
    }

    bool cedulaExiste(const string& cedula) const {
        Nodo<T>* current = head;
        while (current != nullptr) {
            if (current->data.getCedula() == cedula) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    string generarCorreo(const string& correoBase) const {
        vector<string> correosExistentes = leerCorreos();
        string correoCompleto = correoBase;
        size_t pos = correoBase.find("@");
        string base = correoBase.substr(0, pos);
        string dominio = correoBase.substr(pos);
        int contador = 1;

        while (find(correosExistentes.begin(), correosExistentes.end(), correoCompleto) != correosExistentes.end()) {
            correoCompleto = base + to_string(contador) + dominio;
            contador++;
        }

        return correoCompleto;
    }

    void guardarEnArchivo(const string& filename) const {
        ofstream archivo(filename);
        if (archivo.is_open()) {
            Nodo<T>* actual = head;
            while (actual) {
                archivo << actual->data << endl;
                actual = actual->next;
            }
            archivo.close();
        } else {
            cout << "No se pudo abrir el archivo para escribir." << endl;
        }
    }

    void mostrarContrasenas() const {
        Nodo<T>* current = head;
        while (current != nullptr) {
            cout << "Contraseña de " << current->data.getNombre1() << " " << current->data.getApellido() << ": " << current->data.getPassword() << endl;
            current = current->next;
        }
    }

private:
    vector<string> leerCorreos() const {
        vector<string> correos;
        ifstream archivo("correos.txt");
        string linea;
        while (getline(archivo, linea)) {
            size_t pos = linea.find_last_of(" ");
            if (pos != string::npos) {
                correos.push_back(linea.substr(pos + 1));
            }
        }
        archivo.close();
        return correos;
    }
};
