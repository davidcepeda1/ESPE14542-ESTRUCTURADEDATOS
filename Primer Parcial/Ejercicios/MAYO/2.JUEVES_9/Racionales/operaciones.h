/***********************************************************************
 * Universidad de las Fuerzas Armadas ESPE
 * Problema:  Implementation of the class Racional
 * Autor:  David Cepeda
 * Fecha de Creacion: Miercoles, 8 de mayo de 2024
 * Fecha de Modificacion:
 ***********************************************************************/

#if !defined(__UML_Class_Diagram_1_operaciones_h)
#define __UML_Class_Diagram_1_operaciones_h

#include "Racional.h"
#include <cmath>

using namespace std;

int mcd(int a, int b) {
    if (b == 0)
        return a;
    return mcd(b, a % b);
}

Racional calculoSuma(Racional& obj1, Racional& obj2)
{
    int sum_num = (obj1.getNumerador()*obj2.getDenominador()) + (obj2.getNumerador()*obj1.getDenominador());
    int sum_den = obj1.getDenominador() * obj2.getDenominador();

    return Racional(sum_num, sum_den);
}

Racional calculoResta(Racional& obj1, Racional& obj2)
{
    int res_num = (obj1.getNumerador()*obj2.getDenominador()) - (obj2.getNumerador()*obj1.getDenominador());
    int res_den = obj1.getDenominador() * obj2.getDenominador();

    return Racional(res_num, res_den);
}

Racional calculoMultiplicacion(Racional& obj1, Racional& obj2)
{
    int mul_num = obj1.getNumerador()*obj2.getNumerador();
    int mul_den = obj1.getDenominador() * obj2.getDenominador();

    return Racional(mul_num, mul_den);
}

Racional calculoDivision(Racional& obj1, Racional& obj2)
{
    int div_num = obj1.getNumerador()*obj2.getDenominador();
    int div_den = obj1.getDenominador() * obj2.getNumerador();

    return Racional(div_num, div_den);
}

Racional calculoPotencia(Racional& obj, int exponente)
{
    int num = pow(obj.getNumerador(), exponente);
    int den = pow(obj.getDenominador(), exponente);

    return Racional(num, den);    
}

Racional calculoRaizCuadrada(Racional& obj)
{
    double num_raiz = sqrt(obj.getNumerador());
    double den_raiz = sqrt(obj.getDenominador());

    return Racional(static_cast<int>(num_raiz), static_cast<int>(den_raiz));
}

bool compararRacionales(Racional& obj1, Racional& obj2)
{
    return (obj1.getNumerador() == obj2.getNumerador()) && (obj1.getDenominador() == obj2.getDenominador());
}

Racional simplificarRacional(Racional& obj)
{
    int mcd_num_den = mcd(obj.getNumerador(), obj.getDenominador());
    int num_simplificado = obj.getNumerador() / mcd_num_den;
    int den_simplificado = obj.getDenominador() / mcd_num_den;

    return Racional(num_simplificado, den_simplificado);
}
#endif