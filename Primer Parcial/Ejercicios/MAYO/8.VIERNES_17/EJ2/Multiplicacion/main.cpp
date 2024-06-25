#include <iostream>
#include "Frac.h"

int main(){
    Frac F1, F2, result;

    system("cls");

    cout<<"Ingresar la primera fraccion: "<<endl;
    F1.in();

    cout<<"Ingresar la segunda fraccion: "<<endl;
    F2.in();

    result = F1 * F2;
    result.out();

    return 0;
}