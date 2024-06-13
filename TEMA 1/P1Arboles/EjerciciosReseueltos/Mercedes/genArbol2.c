#include <stdlib.h>
#include <stdio.h>
#include "arbol.h"
#include "pila.h"

int main (void){
    
      Pila * p;
      int i=0;
      char simbolo;
      char exPostfija[]="AB+CDE+**";
    
    // AB+CDE+**
      Arbol a;
    //tipoCelda * b;
    
      pilaCreaVacia(p);
      simbolo = exPostfija[i];
      
      while(simbolo!='\0'){
          
          //printf("Simbolo %c: ", simbolo);
          
          /*b=*p;
          while(b!=NULL){
              printf(" %c ", b->elemento->info);
              b=b->sig;
          }*/
          
            if (simbolo>='A' && simbolo<='Z'){
                  a = creaNodo(simbolo);
                  pilaInserta( p, a);
            }
            if (simbolo=='*' || simbolo=='+' || simbolo=='-'){
                    a = creaNodo(simbolo);
                    a->der = pilaSuprime(p);
                    a->izq = pilaSuprime(p);
                    pilaInserta(p,a);
            }
            //preOrden(a);
              //printf("\n");
              i++;
              simbolo=exPostfija[i];
          }
    
      a=pilaSuprime(p);
    
      printf("Arbol: ");
      preOrden(a);
          
      printf("\n\n");
      return 0;
}
