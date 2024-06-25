/***********************************************************************
 * Module:  CalculoTemplate.h
 * Author:  David
 * Modified: lunes, 20 de mayo de 2024 8:35:48
 * Purpose: Declaration of the class CalculoTemplate
 ***********************************************************************/

#if !defined(__Calculo_CalculoTemplate_h)
#define __Calculo_CalculoTemplate_h

#include <stdexcept> // Necesario para std::invalid_argument

template <typename T>
class Operaciones
{
public:
   T suma(T valor1, T valor2);
   T resta(T valor1, T valor2);
   T multiplicacion(T valor1, T valor2);
   T division(T valor1, T valor2);
   Operaciones(T v1, T v2);
   ~Operaciones();
   void calculo();

protected:
private:
   T valor1;
   T valor2;


};

#endif