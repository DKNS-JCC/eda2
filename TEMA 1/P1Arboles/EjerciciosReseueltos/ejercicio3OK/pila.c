#include<stdio.h>
#include<stdlib.h>
#include "pila.h"

int pilaCreaVacia(Pila *p){
	*p=NULL;
	return 0;
}

int pilaVacia(Pila *p){
	if(*p==NULL){
		return 0;
	}
	else{
		return -1;
	}
}

int pilaInserta(Pila *p,tipoElemento elemento){
	tipoCelda *nuevo;
	if((nuevo=malloc(sizeof(tipoCelda)))==NULL){
		return -1;
	}
	
	nuevo->sig=*p;
	*p=nuevo;
	nuevo->elemento=elemento;
	return 0;
}

tipoElemento pilaSuprime(Pila *p){
	if(p==NULL){
		return NULL;
	}
	tipoElemento valor;
	tipoCelda *aBorrar;
	aBorrar=*p;
	valor=aBorrar->elemento;
	*p=aBorrar->sig;
	free(aBorrar);
	return valor;
}

int pilaImprime(Pila *p){

	tipoCelda *posicion;

	if (p==NULL){
	        printf("Pila NO existente\n");
		return -1;
	}
	
	if(pilaVacia(p)==0){
		printf("Pila VACÍA\n");
		return -2;	
	}

	posicion=*p;

	while(posicion->sig!=NULL){
		printf("%p ",posicion->sig->elemento);
		posicion=posicion->sig;
	}
	printf("\n");
	
	return 0;
}


