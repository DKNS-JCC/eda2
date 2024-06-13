#include <stdlib.h>
#include <stdio.h>
#include "arbol.h"
#include "pila.h"

Arbol genArbol(char *exPostfija){

	Arbol a;
	Pila p;
	int i;
	char simbolo;
	
	pilaCreaVacia(&p);
	simbolo=exPostfija[0];
	i=0;
	
	while(simbolo!='\0'){
		switch(simbolo){
			case '+': a=creaNodo(simbolo); break;
			case '*': a=creaNodo(simbolo); break;
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
}
