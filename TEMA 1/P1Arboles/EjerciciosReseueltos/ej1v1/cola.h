#ifndef __COLA_H
#define __COLA_H

#include "arbol.h"


//typedef int tipoElemento;
typedef Arbol tipoElemento;

typedef struct tipoCelda 
{ 
	tipoElemento elemento; 
	struct tipoCelda * sig; 
} tipoCelda;

typedef struct 
{
    tipoCelda *frente, *fondo;
} Cola;

int colaCreaVacia(Cola *c);
int colaVacia(Cola *c);

int colaInserta(Cola *c, tipoElemento 	elemento);

tipoElemento colaSuprime(Cola *c);
int colaImprime(Cola *c);

#endif
