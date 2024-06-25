#include "Racional.h"
#include <iostream>
#include "operaciones.h"

using namespace std;

int mcd(int a, int b) {
    if (b == 0)
        return a;
    return mcd(b, a % b);
}

int main()
{
    int a, b, c, d;
    cout<<"Operaciones Numeros Racionales";
    cout<<"Numerador de la primera fraccion: ";
    cin>>a;
    cout<<"Denominador de la primera fraccion: ";
    cin>>b;
    cout<<"Numerador de la segunda fraccion: ";
    cin>>c;
    cout<<"Denominador de la segunda fraccion: ";
    cin>>d;

    Racional obj1 = Racional(a,b);
    Racional obj2 = Racional(c,d);


    Racional suma = calculoSuma(obj1, obj2);

    int divisor_suma = mcd(suma.getNumerador(), suma.getDenominador());
    int numerador_simplificado_suma = suma.getNumerador() / divisor_suma;
    int denominador_simplificado_suma = suma.getDenominador() / divisor_suma;

    Racional resta = calculoResta(obj1,obj2);
    int divisor_resta = mcd(resta.getNumerador(), resta.getDenominador());
    int numerador_simplificado_resta = resta.getNumerador() / divisor_resta;
    int denominador_simplificado_resta = resta.getDenominador() / divisor_resta;

    Racional multiplicacion = calculoMultiplicacion(obj1,obj2);
    int divisor_multiplicacion = mcd(multiplicacion.getNumerador(), multiplicacion.getDenominador());
    int numerador_simplificado_multiplicacion = multiplicacion.getNumerador() / divisor_multiplicacion;
    int denominador_simplificado_multiplicacion = multiplicacion.getDenominador() / divisor_multiplicacion;

    Racional division = calculoDivision(obj1,obj2);
    int divisor_division = mcd(division.getNumerador(), division.getDenominador());
    int numerador_simplificado_division = division.getNumerador() / divisor_division;
    int denominador_simplificado_division = division.getDenominador() / divisor_division;


    cout<<"Suma: "<<numerador_simplificado_suma<<"/"<<denominador_simplificado_suma<< endl;
    cout<<"Resta: "<<numerador_simplificado_resta<<"/"<<denominador_simplificado_resta<<endl;
    cout<<"Multiplicacion: "<<numerador_simplificado_multiplicacion<<"/"<<denominador_simplificado_multiplicacion<<endl;
    cout<<"Division: "<<numerador_simplificado_division<<"/"<<denominador_simplificado_division<<endl;

    system("pause");
    return 0;
}
