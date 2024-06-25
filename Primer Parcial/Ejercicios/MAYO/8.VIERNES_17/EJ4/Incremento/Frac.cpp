#include <iostream>
#include "Frac.h"

using namespace std;

void Frac::in(){
    cout<<"Ingrese el numerador: ";
    cin>>a;
    cout<<"Ingrese el denominador ";
    cin>>b;
}

Frac& Frac::operator++(){
    ++a;
    ++b;
    return *this;
}

Frac Frac::operator++(int) {
    Frac temp = *this;
    ++a;
    ++b;
    return temp;
}

void Frac::out(){
    cout<<"La fraccion es: "<<a<<"/"<<b<<endl;

}