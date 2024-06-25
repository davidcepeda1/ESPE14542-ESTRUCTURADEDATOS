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
    int a, b, c, d, exponente;
    cout<<"Operaciones Numeros Racionales";
    cout<<"\n";
    cout<<"Numerador de la primera fraccion: ";
    cin>>a;
    cout<<"Denominador de la primera fraccion: ";
    cin>>b;
    cout<<"Numerador de la segunda fraccion: ";
    cin>>c;
    cout<<"Denominador de la segunda fraccion: ";
    cin>>d;
    cout << "Ingrese el exponente para calcular la potencia: ";
    cin >> exponente;

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

    Racional potencia = calculoPotencia(obj1,exponente);
    int divisor_potencia = mcd(potencia.getNumerador(), potencia.getDenominador());
    int numerador_simplificado_potencia = potencia.getNumerador() / divisor_potencia;
    int denominador_simplificado_potencia = potencia.getDenominador() / divisor_potencia;

    Racional raizCuadrada = calculoRaizCuadrada(obj1);
    int divisor_raiz_cuadrada = mcd(raizCuadrada.getNumerador(), raizCuadrada.getDenominador());
    int numerador_simplificado_raiz_cuadrada = raizCuadrada.getNumerador() / divisor_raiz_cuadrada;
    int denominador_simplificado_raiz_cuadrada = raizCuadrada.getDenominador() / divisor_raiz_cuadrada;

    bool igualdad = compararRacionales(obj1, obj2);
    if(igualdad)
        cout<<"Los racionales son iguales"<<endl;
        else
        cout<<"Los racionales son diferentes"<<endl;

    Racional racionalSimplificado = simplificarRacional(obj1);


    cout<<"Suma: "<<numerador_simplificado_suma<<"/"<<denominador_simplificado_suma<< endl;
    cout<<"Resta: "<<numerador_simplificado_resta<<"/"<<denominador_simplificado_resta<<endl;
    cout<<"Multiplicacion: "<<numerador_simplificado_multiplicacion<<"/"<<denominador_simplificado_multiplicacion<<endl;
    cout<<"Division: "<<numerador_simplificado_division<<"/"<<denominador_simplificado_division<<endl;
    cout << "Potencia: " << numerador_simplificado_potencia << "/" << denominador_simplificado_potencia << endl;
    cout << "Raiz Cuadrada de la primera fraccion: " << numerador_simplificado_raiz_cuadrada << "/" << denominador_simplificado_raiz_cuadrada << endl;
    cout << "Fraccion simplificada: " << racionalSimplificado.getNumerador() << "/" << racionalSimplificado.getDenominador() << endl;

    system("pause");
    return 0;
}
