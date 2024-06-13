#include <stdio.h>
#include <stdlib.h>
#include "cola.h"



int colaCreaVacia(Cola *c){
	if(NULL == c) return -1;

	c->frente = c->fondo = NULL;
	return 0;
}

int colaVacia(Cola *c){
	if(NULL == c) return -1;

	return (c->frente == NULL && c->fondo == NULL);
}

int colaInserta(Cola *c, tipoElementoC elemento){
	if(NULL == c) return -1;

	tipoCeldaC *celda;
	if(NULL == (celda = malloc(sizeof(tipoCeldaC))) ) return -5;
	celda->elemento = elemento;
	celda->sig = NULL;

	if(NULL == c->fondo)
		c->frente = c->fondo = celda;
	else
		c->fondo = c->fondo->sig = celda;
	
	return 0;
}

tipoElementoC colaSuprime(Cola *c){
	if(NULL == c) return NULL;
	if(NULL==c->frente) return NULL;

	tipoCeldaC *aBorrar = c->frente;
	tipoElementoC valor = aBorrar->elemento;

	c->frente = aBorrar->sig;
	if(aBorrar == c->fondo)
		c->fondo = c->frente;
	free(aBorrar);

	return valor;
}
