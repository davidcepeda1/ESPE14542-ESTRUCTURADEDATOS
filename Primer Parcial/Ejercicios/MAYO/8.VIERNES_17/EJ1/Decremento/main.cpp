#include <iostream>
#include "Frac.h"

int main(){
    Frac F1;

    system("cls");

    cout<<"La fraccion inicial: "<<endl;
    F1.in();

    cout<<"Aplicando decremento prefijo (--): " << endl;
    --F1;
    F1.out();

    cout<<"Aplicando decremento postfijo (--): " << endl;
    F1--;
    F1.out();

    return 0;
}