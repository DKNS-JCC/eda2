#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "cola.h"


int creaVacia(Cola *c){
    
	tipoCelda *ficticio;	

	
	if (c==NULL){
	        printf(MSG_ERROR_COLA);
		return ERROR_COLA;
	}

	ficticio=(tipoCelda*)malloc(sizeof(tipoCelda));	
	if(ficticio==NULL){
		printf(MSG_ERROR_MALLOC);
		return ERROR_MALLOC;
	}

	//ficticio->elemento=NULL;
	ficticio->sig=NULL;
	c->frente=c->fondo=ficticio;
	printf("%p\n",c->frente->elemento);

}

int vacia(Cola *c){

	if (c==NULL){
	        printf(MSG_ERROR_COLA);
		return ERROR_COLA;
	}

	if((c->frente->sig==NULL)&&(c->fondo->sig==NULL)) return 1;
	else return 0;

}

int insertaC(Cola *c, tipoElemento elemento){

	tipoCelda *nuevo;
	if (c==NULL){
	        printf(MSG_ERROR_COLA);
		return ERROR_COLA;
	}
	nuevo=(tipoCelda*)malloc(sizeof(tipoCelda));
	if(nuevo==NULL){
		printf(MSG_ERROR_MALLOC);
		return ERROR_MALLOC;
	}
	
	nuevo->elemento=elemento;
 	nuevo->sig=NULL;
	c->fondo->sig=nuevo;
        c->fondo=nuevo;
	
	/*EN EL CASO EN QUE LA COLA ESTUVIERA VACÍA*/
	if(c->frente->sig==NULL)
		c->frente->sig=nuevo;

	return 0;
}

int suprime(Cola *c){
	
	tipoCelda *aBorrar;
	
	if (c==NULL){
	        printf(MSG_ERROR_COLA);
		return ERROR_COLA;
	}

	aBorrar = c->frente->sig;
        c->frente->sig = aBorrar->sig;
        free(aBorrar);
        return 0;

}

int imprime(Cola *c){

	tipoCelda *posicion;

	if (c==NULL){
	        printf(MSG_ERROR_COLA);
		return ERROR_COLA;
	}	

	posicion=c->frente;

	while(posicion->sig!=NULL){
		printf("%p ",posicion->sig->elemento);
		posicion=posicion->sig;
	}
	printf("\n");
	
	return 0;
}

