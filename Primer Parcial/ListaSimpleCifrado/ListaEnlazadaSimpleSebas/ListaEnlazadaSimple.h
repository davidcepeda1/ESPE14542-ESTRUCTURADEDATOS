#pragma once
#include "Nodo.h"
#include "Persona.h"
#include <functional>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>   
#include <cstring> 

using namespace std;

class ListaEnlazadaSimple
{
private:
    Nodo<Persona>* cabeza;
    /*std::vector<std::string>leerCorreos() {
        std::vector<std::string> correos;
        std::ifstream archivo("Datos.txt");
        std::string linea;
        while (std::getline(archivo, linea)) {
            correos.push_back(linea);
        }
        archivo.close();
        return correos;
    }*/
public:


ListaEnlazadaSimple() {
    cabeza = nullptr;
}

~ListaEnlazadaSimple() {
    Nodo<Persona>* actual = cabeza;
    Nodo<Persona>* siguiente;
    while (actual != nullptr) {
        siguiente = actual->getSiguiente();
        delete actual;
        actual = siguiente;
    }
    cabeza = nullptr;
}

void insertar(Persona& dato) {
    std::string correo = generarCorreo(dato.getPersona(), dato.getNombre2(), dato.getApellido());
    dato.setCorreo(correo);
    //SIGUE LA INSERCION
    Nodo<Persona>* nuevoNodo = new Nodo<Persona>(dato);
    if (cabeza == nullptr) {
        cabeza = nuevoNodo;
    } else {
        Nodo<Persona>* temp = cabeza;
        while (temp->getSiguiente() != nullptr) {
            temp = temp->getSiguiente();
        }
        temp->setSiguiente(nuevoNodo);
    }

    
    //Se guardan los datos
    cout<<"\n";
    guardarDatos(dato);
}

    std::string generarCorreo(const std::string& nombre, const std::string& nombre2, const std::string& apellido) {
        /*std::string correoBase;
        correoBase += tolower(nombre[0]);
        correoBase += tolower(nombre2[0]);
        correoBase += apellido;

        std::string correoCompleto = correoBase + "@espe.edu.ec";
        std::vector<std::string> correosExistentes = leerCorreos();
        std::string correoFinal = correoCompleto;
        while (std::find(correosExistentes.begin(), correosExistentes.end(), correoFinal) != correosExistentes.end()) {
            correoFinal = correoCompleto + std::to_string(cont);
            cont++;
        }

        return correoFinal;*/
        string correoBase = string(1, tolower(nombre.front())) + string(1, tolower(nombre2.front())) + apellido;
    string correoCompleto = correoBase + "@espe.edu.ec";
    int contador = 1;

    Nodo<Persona>* actual = cabeza;
    while (actual != nullptr) {
        if (actual->getPer().getCorreo() == correoCompleto) {
            correoCompleto = correoBase + to_string(contador) + "@espe.edu.ec";
            contador++;
        }
        actual = actual->getSiguiente();
    }

    return correoCompleto;
    }

    void guardarDatos(Persona& persona){
    ofstream archivo("Datos.txt", ios_base::app);
    if (archivo.is_open()) {
        archivo << persona.getPersona() << "," << persona.getNombre2() << "," <<persona.getApellido() << ","<< persona.getCedula() << "," << persona.getCorreo() <<"\n";
        cout << "Datos guardados correctamente en datos.txt.\n";
    } else {
        cerr << "No se pudo abrir el archivo para guardar los datos.\n";
    }
    }
   

/*
std::string generatePassword(Persona per) {
    int variable = 2;
    std::string password = "";
    
    char ultimaLetraApellido = per.getApellido().back();

    char primeraLetraNombre1 = per.getPersona().front();

    char ultimaLetraNombre2 = per.getNombre2().back();

    password += ultimaLetraApellido;
    password += primeraLetraNombre1;
    password += ultimaLetraNombre2;

    for (int i = per.getApellido().size() - 2; i >= 0; --i) {
        password += per.getApellido()[i];
    }
    cout<<"Sin encriptar: "<<password<<endl;

    for (size_t i = 0; i < password.size(); ++i) {
        password[i] = std::toupper(password[i]);
    }

    std::string r = "";
    for(auto c: password){
        if(isalpha(c)){
            c+=variable;

            if(c > 'Z') c-= 26;
            if(c < 'A') c+= 26;
        }
        r += c;
    }

    return r;
}*/



void mostrar() const{
    Nodo<Persona>* temp = cabeza;
    while (temp != nullptr) {
        std::cout << temp->getPer() << " -> ";
        temp = temp->getSiguiente();
    }
    std::cout << "NULL" << std::endl;
}
};