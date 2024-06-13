#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"

int main(void)
{ Arbol varArbol;

/* Creación arbol ejemplo de las transparencias de recorridos */
  varArbol = creaNodo('A');
  varArbol->izq=creaNodo('B');
  varArbol->der = creaNodo('C');
  varArbol->izq->izq=creaNodo('D');
  varArbol->izq->der=creaNodo('E');
  varArbol->der->izq=creaNodo('F');
  varArbol->der->der=creaNodo('G');

/* Aplicación de recorridos al arbol ejemplo */

  printf("Recorrido en PRE_ORDEN: ");
  preOrden(varArbol);
  printf("\n");
  printf("Recorrido en ORDEN: ");
  enOrden(varArbol);
  printf("\n");
  printf("Recorrido en POST_ORDEN: ");
  postOrden(varArbol);
  printf("\n");
  printf("Recorrido en AMPLITUD: ");
  amplitud(varArbol);
  printf("\n");

/* Comenzar a implementar y probar las funciones del ejercicio 2 ... y segunda parte del ejercicio 3 */

  printf("ALTURA del arbol: ");
  printf("%d", altura(varArbol));
  printf("\n");

  printf("Numero de NODOS: ");
  printf("%d", numNodos(varArbol));
  printf("\n");

  printf("Numero de NODOS HOJA: ");
  printf("%d", numNodosHoja(varArbol));
  printf("\n");

  printf("Ejecucion de la funcion ANULA!");
  printf("\n");
  anula(varArbol);

  printf("Comprobacion de borrado (RECORRIDO): ");
  preOrden(varArbol);
  printf("\n");

  printf("Comprobacion de borrado (ALTURA): ");
  printf("%d", altura(varArbol));
  printf("\n");

  printf("Comprobacion de borrado (NODOS): ");
  printf("%d", numNodos(varArbol));
  printf("\n");

  return 1;
}

