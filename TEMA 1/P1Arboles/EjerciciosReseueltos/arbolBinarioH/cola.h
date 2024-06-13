#ifndef __COLA_H
#define __COLA_H

#define ERROR_COLA -1
#define MSG_ERROR_COLA "La pila no existe\n"
#define ERROR_MALLOC -2
#define MSG_ERROR_MALLOC "No se ha podido reservar memoria con malloc\n"

#include "arbol.h"


typedef Arbol tipoElemento;

typedef struct tipoCelda { 
	tipoElemento elemento; 
	struct tipoCelda * sig; 
	} tipoCelda;

typedef struct {
        tipoCelda *frente, *fondo;
} Cola;

int creaVacia(Cola *c);

int vacia(Cola *c);

int insertaC(Cola *c, tipoElemento elemento);

int suprime(Cola *c);

#endif

