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

#endif