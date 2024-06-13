#include "arbol.h"

#ifndef __COLA_H
#define __COLA_H

typedef Arbol tipoElementoC;

#ifndef TIPOCELDAC__
#define TIPOCELDAC__
typedef struct tipoCeldaC { 
	tipoElementoC elemento; 
	struct tipoCeldaC * sig; 
	} tipoCeldaC;
#endif

typedef struct {
        tipoCeldaC *frente, *fondo;
} Cola;

int colaCreaVacia(Cola *c);

// En vacía no sería necesario el paso por referencia
// pero por mantener la misma interfaz con la implementación
// de matrices
int colaVacia(Cola *c);

int colaInserta(Cola *c, tipoElementoC elemento);

tipoElementoC colaSuprime(Cola *c);

#endif
