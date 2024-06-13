#include <stdlib.h>
#include <stdio.h>
#include "arbol.h"
#include "pila.h"

/*Arbol genArbol(char *exPostfija){

	Arbol a;
	Pila p;
	int i;
	char simbolo;
	
	pilaCreaVacia(&p);
	simbolo=exPostfija[0];
	i=0;
	
	while(simbolo!='\0'){
		switch(simbolo){
			case '+': a=creaNodo(simbolo); pilaInserta(&p,a); break;
			case '*': a=creaNodo(simbolo); pilaInserta(&p,a); break;
			default:
				a->der=pilaSuprime(&p);
				a->izq=pilaSuprime(&p);
				pilaInserta(&p,a);
		}
		i++;
		simbolo=exPostfija[i];
	}
	
	a=pilaSuprime(&p);
	
	return a;
}*/
int esOperador(char simbolo){ 
	if ((simbolo=='+') || (simbolo=='-') || (simbolo=='*') || (simbolo=='/'))
		return 1;
  	else  if ((simbolo>= 'A' && simbolo<= 'Z')||(simbolo>= 'a' && simbolo<= 'z') ||(simbolo>= '0' && simbolo<= '9'))
  		return 0;
  	else return -1;
}
Arbol genArbol(char *exPostfija){ 

	Pila p=NULL;
  	Arbol a=NULL;
  	int i=0;
  	char simbolo;
  	tipoInfo info;
  	simbolo = exPostfija[i];
  	while (simbolo != '\0'){ 
  		switch(esOperador(simbolo)){ 
  			case 0: a = creaNodo(simbolo);
 	      			pilaInserta(&p,a);
	      			break;
      			case 1: a = creaNodo(simbolo);
  	      			a->der = (Arbol) pilaSuprime(&p);
  	      			a->izq = (Arbol) pilaSuprime(&p);
  	      			pilaInserta(&p,a);
      	      			break;
      			default: printf("\n\n¡¡Expresión incorrecta !!\n\n");
      				// anula(a); 
      				while (!pilaVacia(&p)) pilaSuprime(&p);
      	       			return NULL;		
    		}
    		i++;
    		simbolo=exPostfija[i];
  	}
  	return pilaSuprime(&p);
}



int evaluar(Arbol a){
	
	if(a==NULL) return -99999;
	if(a->info=='+')
		return (evaluar(a->izq)+evaluar(a->der));

	if(a->info=='-')
		return (evaluar(a->izq)-evaluar(a->der));
	
	if(a->info=='*')
		return (evaluar(a->izq)*evaluar(a->der));

	return (a->info-48);
}
