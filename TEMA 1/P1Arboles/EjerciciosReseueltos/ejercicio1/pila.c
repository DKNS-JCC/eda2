#include <stdio.h>
#include <stdlib.h>
#include "pila.h"


int
pilaCreaVacia(Pila * p)
{
	if (p == NULL) return -1;
	else *p = NULL;
	return 0;
}


int
pilaVacia(Pila *p)
{
	if (p == NULL) 
		return -1;
	if (*p == NULL)
		return 0;
	else
		return 1;
}


int
pilaInserta(Pila *p, tipoElemento elemento)
{
	tipoCelda * c;
	
	if (p == NULL) return -1;
	
	c = malloc(sizeof(tipoCelda));
	if (c == NULL) return -1;
	else
	{
		c->elemento = elemento;
		c->sig = NULL; 
		if (pilaVacia(p)) *p = c;
		else
		{
			c->sig = *p;
			*p = c;
		}
		return 0;
	}

}


tipoElemento
pilaSuprime(Pila *p)
{
	tipoElemento x;
	tipoCelda * aux;
	if (pilaVacia(p)) 
		return -1;
	else 
	{
		x = (*p)->elemento;
		aux = *p;
		*p = (*p)->sig;
		free(aux);
		return x;
	}
}

int pilaImprime(Pila p){

	tipoCelda *posicion;
	posicion=p;

	if(p==NULL){
		printf("Pila NO existe\n");
		return -1;
	}
	
	if(pilaVacia(&p)==0){
		printf("pila VACÍA\n");
		return -2;
	}

	while(posicion->sig!=NULL){
		printf("%d ",posicion->sig->elemento);
		posicion=posicion->sig;
	}
	printf("\n");
	
	return 0;
}

