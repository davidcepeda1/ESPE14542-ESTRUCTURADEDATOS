/***********************************************************************
 * Universidad de las Fuerzas Armadas ESPE
 * Problema:  Implementation of the class Racional
 * Autor:  David Cepeda
 * Fecha de Creacion: Miercoles, 8 de mayo de 2024
 * Fecha de Modificacion:
 ***********************************************************************/

#if !defined(__UML_Class_Diagram_1_Racional_h)
#define __UML_Class_Diagram_1_Racional_h

class Racional
{
public:
   Racional(int num, int den);
   int getNumerador(void);
   void setNumerador(int newNumerador);
   int getDenominador(void);
   void setDenominador(int newDenominador);
   ~Racional();

protected:
private:
   int numerador;
   int denominador;


};

#endif
