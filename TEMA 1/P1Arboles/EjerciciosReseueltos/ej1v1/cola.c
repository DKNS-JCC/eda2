  
#include <stdlib.h>
#include <stdio.h>
#include "cola.h"

 
int
colaCreaVacia(Cola *c)
{
	if (c == NULL) return -1;

	c->frente = NULL;
	c->fondo = NULL;
	return 0;
}


int
colaVacia(Cola *c)
{
	if (c == NULL) return -1;
	if(c->frente == NULL)
		return 0;
	else
		return 1;
}



int
colaInserta ( Cola *c , tipoElemento x ){
	tipoCelda * nuevo ;
	if ( c == NULL ) {
		printf("Cola inexistente\n");
		return -1;
	}
	else if ( NULL == ( nuevo = ( tipoCelda *) malloc ( sizeof ( tipoCelda ) ) ) ) {
		printf("Memoria NO reservada\n");
		return -2;
	}
	else {
		nuevo->elemento = x ;
		nuevo->sig = NULL ;
		if (c->frente == NULL ) {
			c-> frente = nuevo ;
		}
		else {
			c->fondo->sig = nuevo ;
		}
	c->fondo=nuevo ;
	return 0;
	}
						
}

tipoElemento
colaSuprime(Cola *c){
	tipoCelda * aBorrar ;
	tipoElemento aDevolver ;

	if ( c == NULL ) {
		printf("Cola inexistente\n");
		return -1;
	}
	else if (c->frente == NULL ) { //if (vacia(c)) también vale
		printf("Cola vacía\n");
		return -2;
	}
	else {
		aBorrar = c->frente ;
		aDevolver = aBorrar->elemento ;
		if ( aBorrar->sig == NULL ) { //es el último elemento que quedaba en la cola
			c->fondo = c->frente = NULL ; // la cola queda vacía
		}
		else {
			c->frente = aBorrar->sig ; //o c->frente = c->frente->sig;
		}
		free ( aBorrar ) ;
		return aDevolver ;
	}
}

int colaImprime(Cola *c){

	tipoCelda *posicion;

	if (c==NULL){
	        printf("Cola NO existente\n");
		return -1;
	}
	
	if(c->frente==NULL)
		return -2;	

	posicion=c->frente;

	while(posicion->sig!=NULL){
		printf("%d ",posicion->sig->elemento);
		posicion=posicion->sig;
	}
	printf("\n");
	
	return 0;
}

