/*
 * pruebaSintaxis.c	Ejemplo de utilización del TAD Pila en la comprobación de la sintaxix de una expresión
 *			
 *  Created on: 15/12/2014
 *      Author: M J Polo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"


int sintaxis(char * expresion);

int main(void)
{
    char expresion[20] = "{{{{((())";
    strcpy(expresion, "{()}");
    // Modificar adecuadamente la función sintaxis para que pueda comprobar que una expresión aritmetica es correcta!!
    strcpy(expresion, "[a+(b-c)*3+5]");

    


  if (sintaxis(expresion))
     printf("Expresion %s OK\n", expresion);
  else
       printf("Expresion %s incorrecta\n",expresion);

}
int sintaxis(char * expresion)
{ Pila miPila;
  char c1,cIni,finExp='\0';
  int i=0;

  pilaCreaVacia(&miPila);
  c1=expresion[i];

  while (c1!=finExp)
  { if (c1 =='{' ||c1 =='[' ||c1 =='(' )
       pilaInserta(&miPila,c1);
    else { if (pilaVacia(&miPila)) return 0;
           else { cIni = pilaSuprime(&miPila);
		switch (cIni) {
			case '{': if (c1 != '}') return 0;
				  break;
			case '(':if (c1 != ')') return 0;
				  break;
                	case '[':if (c1 != ']') return 0;
				  break;
                	default:break;
	  	}
		}
         }
      i++;
    c1=expresion[i];
  }
  if (!pilaVacia(&miPila)) // Ojo que dependiendo de la representación puede quedar memoria sin liberar!!!!
      return 0;
  else return 1;
}

