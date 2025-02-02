#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"




int main(void){

    Arbol A, A2;
    tipoNodo *POS;


/* Creaci�n arbol ejemplo de las transparencias de recorridos */
  A = creaNodo('A');
  A->izq=creaNodo('B');
  A->der = creaNodo('C');
  A->izq->izq=creaNodo('D');
  A->izq->der=creaNodo('E');
  A->der->izq=creaNodo('F');
  A->der->der=creaNodo('G');

  /*Creaci�n de un segundo �rbol para poder comparar*/
  A2 = creaNodo('A');
  A2->izq=creaNodo('a');
  A2->der = creaNodo('C');
  A2->izq->izq=creaNodo('D');
  A2->izq->der=creaNodo('E');
  A2->der->izq=creaNodo('F');
  A2->der->der=creaNodo('G');
  A2->der->der->der=creaNodo('A');
  printf("N�= %d\n",numX(A,'A'));

/* Aplicaci�n de recorridos al arbol ejemplo */

  printf("Recorrido en AMPLITUD: ");
  amplitud(A);
  printf("\n");
  printf("Recorrido en PRE_ORDEN: ");
  preOrden(A);
  printf("\n");
  printf("Recorrido en ORDEN: ");
  enOrden(A);
  printf("\n");
  printf("Recorrido en POST_ORDEN: ");
  postOrden(A);
  printf("\n");


  /*Cuenta distintos n�meros de nodos*/
  printf("ALTURA=%d\n", altura(A));
  printf("N=%d\n",numNodos(A));
  printf("N_Hoja=%d\n",numNodosHoja(A));
  printf("N_Interno=%d\n",numNodosInternos(A)-1);
  printf("N_Hijo_U=%d\n",numHijoUnico(A));

  /*Sustituci�n de elementos*/
 
  printf("\nN_S=%d\n",sustituye(A,'A','Z'));
  amplitud(A);

  /*Valores m�ximo y m�nimo*/
  POS=buscarMax(A);
  printf("VALOR MAX= %c\n",POS->info);
  //POS=buscarMin(A);
  printf("VALOR min= %c\n",POS->info);


  /*�rboles similares, equivalentes y especular*/
  if(similares(A,A2))
    printf("\nLos �rboles son SIMILARES\n");
  else  printf("\nLos �rboles NO son similares\n");

   if(equivalentes(A,A2))
    printf("\nLos �rboles son EQUIVALENTES\n");
  else  printf("\nLos �rboles NO son EQUIVALENTES\n");

  A2=especular(A);
  preOrden(A2);

  return 1;
}

