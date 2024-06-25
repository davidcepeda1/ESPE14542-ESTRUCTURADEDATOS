/***********************************************************************
 * Universidad de las Fuerzas Armadas ESPE
 * Problema:  Implementation of the class Racional
 * Autor:  David Cepeda
 * Fecha de Creacion: Miercoles, 8 de mayo de 2024
 * Fecha de Modificacion:
 ***********************************************************************/


#include "Racional.h"
#include <iostream>

using namespace std;

////////////////////////////////////////////////////////////////////////
// Name:       Racional::Racional(int num, int den)
// Purpose:    Implementation of Racional::Racional()
// Parameters:
// - num
// - den
// Return:     Racional
////////////////////////////////////////////////////////////////////////

Racional::Racional(int num, int den)
{
   numerador = num;
   denominador = den;
   
}

////////////////////////////////////////////////////////////////////////
// Name:       Racional::getNumerador()
// Purpose:    Implementation of Racional::getNumerador()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Racional::getNumerador()
{
   return numerador;
}

////////////////////////////////////////////////////////////////////////
// Name:       Racional::setNumerador(int newNumerador)
// Purpose:    Implementation of Racional::setNumerador()
// Parameters:
// - newNumerador
// Return:     void
////////////////////////////////////////////////////////////////////////

void Racional::setNumerador(int newNumerador)
{
   numerador = newNumerador;
}

////////////////////////////////////////////////////////////////////////
// Name:       Racional::getDenominador()
// Purpose:    Implementation of Racional::getDenominador()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Racional::getDenominador()
{
   return denominador;
}

////////////////////////////////////////////////////////////////////////
// Name:       Racional::setDenominador(int newDenominador)
// Purpose:    Implementation of Racional::setDenominador()
// Parameters:
// - newDenominador
// Return:     void
////////////////////////////////////////////////////////////////////////

void Racional::setDenominador(int newDenominador)
{
   denominador = newDenominador;
}


////////////////////////////////////////////////////////////////////////
// Name:       Racional::Racional()
// Purpose:    Implementation of Racional::Racional()
// Return:     
////////////////////////////////////////////////////////////////////////
Racional::~Racional()
{
   
}