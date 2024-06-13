#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"




int main(void){

    Arbol A;



/* Creación arbol ejemplo de las transparencias de recorridos */
  A = creaNodo('*');
  A->izq=creaNodo('+');
  A->der = creaNodo('*');
  A->izq->izq=creaNodo('2');
  A->izq->der=creaNodo('3');
  A->der->izq=creaNodo('7');
  A->der->der=creaNodo('+');
  A->der->der->izq=creaNodo('1');
  A->der->der->der=creaNodo('3');

  

/* Aplicación de recorridos al arbol ejemplo */

  
  printf("Recorrido en PRE_ORDEN: ");
  preOrden(A);
  printf("\n");
  printf("Recorrido en ORDEN: ");
  enOrden(A);
  printf("\n");
  printf("Recorrido en POST_ORDEN: ");
  postOrden(A);
  printf("\n");


  if(evaluar2(A)==-99999) 
	printf("ERROR: arbol algebraico INCORRECTO\n");
  else printf("%d",evaluar(A));

  

  return 1;
}

