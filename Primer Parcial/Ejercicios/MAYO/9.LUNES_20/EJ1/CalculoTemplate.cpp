/***********************************************************************
 * Module:  CalculoTemplate.cpp
 * Author:  David
 * Modified: lunes, 20 de mayo de 2024 8:35:48
 * Purpose: Implementation of the class CalculoTemplate
 ***********************************************************************/

#include "CalculoTemplate.h"
#include <iostream>

////////////////////////////////////////////////////////////////////////
// Name:       Operaciones::suma()
// Purpose:    Implementation of Operaciones::suma()
// Return:     T
////////////////////////////////////////////////////////////////////////

template <typename T>
T Operaciones<T>::suma(T valor1, T valor2)
{
   return valor1 + valor2;
}

////////////////////////////////////////////////////////////////////////
// Name:       Operaciones::resta()
// Purpose:    Implementation of Operaciones::resta()
// Return:     T
////////////////////////////////////////////////////////////////////////

template <typename T>
T Operaciones<T>::resta(T valor1, T valor2)
{
   return valor1 - valor2;
}

////////////////////////////////////////////////////////////////////////
// Name:       Operaciones::multiplicacion()
// Purpose:    Implementation of Operaciones::multiplicacion()
// Return:     T
////////////////////////////////////////////////////////////////////////

template <typename T>
T Operaciones<T>::multiplicacion(T valor1, T valor2)
{
   return valor1 * valor2;
}

////////////////////////////////////////////////////////////////////////
// Name:       Operaciones::division()
// Purpose:    Implementation of Operaciones::division()
// Return:     T
////////////////////////////////////////////////////////////////////////

template <typename T>
T Operaciones<T>::division(T valor1, T valor2)
{
   return valor1 / valor2;
}

////////////////////////////////////////////////////////////////////////
// Name:       Operaciones::Operaciones(T v1, T v2)
// Purpose:    Implementation of Operaciones::Operaciones()
// Parameters:
// - v1
// - v2
// Return:     
////////////////////////////////////////////////////////////////////////

template <typename T>
Operaciones<T>::Operaciones(T v1, T v2) : valor1(v1), valor2(v2)
{
   
}

////////////////////////////////////////////////////////////////////////
// Name:       Operaciones::~Operaciones()
// Purpose:    Implementation of Operaciones::~Operaciones()
// Return:     
////////////////////////////////////////////////////////////////////////

template <typename T>
Operaciones<T>::~Operaciones()
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Operaciones::calculo()
// Purpose:    Implementation of Operaciones::calculo()
// Return:     void
////////////////////////////////////////////////////////////////////////

template <typename T>
void Operaciones<T>::calculo()
{
    std::cout<<valor1<<" + "<<valor2<<": "<<suma(valor1, valor2)<<std::endl;
    std::cout<<valor1<<" - "<<valor2<<": "<<resta(valor1, valor2)<<std::endl;
    std::cout<<valor1<<" * "<<valor2<<": "<<multiplicacion(valor1, valor2)<<std::endl;
    std::cout<<valor1<<" / "<<valor2<<": "<<division(valor1, valor2)<<std::endl;
}