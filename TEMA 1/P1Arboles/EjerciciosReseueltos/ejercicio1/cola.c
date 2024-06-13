#include <stdlib.h>
#include <stdio.h>
#include "cola.h"


int colaCreaVacia(Cola *c){

	if ( c == NULL ) {
		fprintf ( stderr , " Fallo precondicion cola no existente !\ n " ) ;
		return -1;
	}    
    	c->frente=NULL;
    	c->fondo=NULL;   
	return 0;
}



int colaVacia(Cola *c){
	
	if(c->frente==c->fondo)
		return 1;
	else
		return 0;
}




int
colaInserta ( Cola *c , tipoElemento x){
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













tipoElemento colaSuprime(Cola *c){
	tipoCelda * aBorrar ;
	tipoElemento aDevolver ;

	if ( c == NULL ) {
		fprintf ( stderr , " ERROR : tipo no valido !\ n " ) ;
		return -1;
	}
	else if ( NULL == c - > frente ) {
		fprintf ( stderr , " ERROR : cola vacia !\ n " ) ;
		return -1;
	}
	else {
		aBorrar = c - > frente ;
		c - > frente = aBorrar - > sig ; // actualiza frente
		aDevolver = aBorrar - > elemento ;
		if ( aBorrar - > sig == NULL ) { //if (c->frente == NULL)
			c - > fondo = NULL ; // la cola queda vacia se actualiza también fondo, frente ya estaría a NULL
		}
	free ( aBorrar ) ;
	return aDevolver ;    
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

