#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "cola.h"


int colaCreaVacia (Cola *c) {
      
    if (c == NULL) {
        return -1;
    }
    
    c->frente = NULL;
    c->fondo = NULL;
    return 0;
}

int colaVacia (Cola *c) {

    if (c == NULL) {
        return -1;
    }
    
    return (c->fondo == NULL); //&& c->frente == NULL);
}

int colaInserta (Cola *c, tipoElemento elemento) { 
    
    tipoCelda *nuevo;
    
    if (c == NULL) {
        return -1;
    }
        
    nuevo = (tipoCelda *)malloc(sizeof(tipoCelda));
    
    if (nuevo == NULL) {
        return -2;
    } else {
        nuevo->elemento = elemento;
        nuevo->sig = NULL;
        if (c->fondo == NULL) {
            c->frente = nuevo;
            c->fondo = nuevo;
        } else {
            c->fondo->sig = nuevo;
            c->fondo = nuevo;
        }
            
        return 0;
    }
}

tipoElemento colaSuprime (Cola *c) {
    
    tipoCelda *aBorrar;
    tipoElemento elemento;
    
    if (c == NULL || c->frente == NULL) {
        return -1;
    } else {
        aBorrar = c->frente;
        elemento = c->frente->elemento;
        if (aBorrar == c->fondo) {
            c->frente = NULL;
            c->fondo = NULL;
        } else {
            c->frente = c->frente->sig;
        }
        
        free (aBorrar);
        return elemento;
    }
}
