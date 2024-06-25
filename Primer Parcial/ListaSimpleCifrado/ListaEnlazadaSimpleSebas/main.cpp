#include "ListaEnlazadaSimple.h"
#include "Persona.cpp"
#include "Persona.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

bool esEntero(string);
bool validarCedula(string);
void entradaDecAString(string);

int main() {
    ListaEnlazadaSimple* lista = new ListaEnlazadaSimple();
    int opcion;
    string linea, i, b, e, m, s;
    bool rep = true;
    bool repite = true;
    bool repetir = true;
    string nombre,nombre2,apellido,cedula;
    bool validado = false;
    string contraseña;
    Persona person;
    do {

        //system("cls");
        cout << "\n***********Listas Simples***********" << endl;
        cout << "1. Insertar" << endl;
        cout << "2. Mostrar" << endl;
        cout << "3. Salir" << endl;
        cout << "Opcion: ";
        do {

            getline(cin, linea);

            if (esEntero(linea)) {
                repite = false;
                opcion = atoi(linea.c_str());
                if (opcion > 5 || opcion < 1) {
                    repetir = true;
                }
            }
            else {
                cout << "No has ingresado un valor entero. Intentalo nuevamente" << endl;
            }
        } while (repite);
        opcion = atoi(linea.c_str());
        switch (opcion) {
        case 1:
            cout<<"Ingrese el nombre1: "<<endl;
            getline(cin,nombre);
            person.setPersona(nombre);
            cout<<"Ingrese el nombre2: "<<endl;
            getline(cin,nombre2);
            person.setNombre2(nombre2);
            cout<<"Digite el apellido: "<<endl;
            getline(cin,apellido);
            person.setApellido(apellido);
            do{
                cout<<"\nIngrese la cedula: "<<endl;
                cin>>cedula;
                
            
                if(validarCedula(cedula)){
                    validado = true;
                    person.setCedula(cedula);
                }else {  
                    validado = false;
                }
                
            }while(!validado);
            cout<<"\n";
            //contraseña = lista->cifrarCesar(Persona(nombre,nombre2,apellido,cedula,""),variabledes);
            contraseña = person.generarContrasenacifrada();
            cout<<"\n";
            cout<<"El password es: "<<contraseña;
            lista->insertar(person);
            break;

        case 2:
        lista->mostrar();
            break; 
        }
        //system("pause");
    } while (opcion != 3);
    delete lista;
    return 0;
}
bool validarCedula(string cedula) {
    if (cedula.length() != 10) {
        cout<<"Cedula rechazada";
        return false;
    }

    for (char c : cedula) {
        if (!isdigit(c)) {
            cout<<"Cedula rechazada";
            return false;
        }
    }

    int provincia = stoi(cedula.substr(0, 2));
    if (provincia < 1 || provincia > 24) {
        cout<<"Cedula rechazada";
        return false;
    }

    int verificador = cedula[9] - '0';
    int suma = 0;
    for (int i = 0; i < 9; ++i) {
        int digito = cedula[i] - '0';
        if (i % 2 == 0) {
            digito *= 2;
            if (digito > 9) {
                digito -= 9;
            }
        }
        suma += digito;
    }

    int TOTAL = ((suma / 10) + 1) * 10;
    if ((TOTAL - suma == verificador) || (verificador == 0 && TOTAL - suma == 10)) {
        cout<<"Cedula aceptada";
        return true;
    }

    return false;
    cout<<"Cedula rechazada";
}
//Fucion para validar
bool esEntero(string linea) {
    bool esEntero = true;
    int longitud = linea.size();

    if (longitud == 0) {
        esEntero = false;
    }
    else if (longitud == 1 && !isdigit(linea[0])) {
        esEntero = false;
    }
    else {
        int indice = 0;
        if (linea[0] == '+' || linea[0] == '-') {
            indice = 1;
        }
        else {
            indice = 0;
        }

        while (indice < longitud) {
            if (!isdigit(linea[indice])) {
                esEntero = false;
                break;
            }
            indice++;
        }
    }


    return esEntero;
}

//Funcion para validar decimales
void entradaDecAString(std::string& saveStr)
{
    char c;
    saveStr = "";
    bool tieneComa = false;

    do
    {
        c = cin.get();        

        if ( (',' == c || '.' == c) && !tieneComa)
        {
            putchar(c);
            saveStr.push_back(c);
            tieneComa = true;
        }

        if ('0' <= c && c <= '9')
        {
            putchar(c); // 1
            saveStr.push_back(c);
        }

    } while (c != '\r'); // 2

}