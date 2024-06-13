#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "pila.h"

int pilaCreaVacia (Pila *p) {
    
    if (p == NULL) {
        return -1;
    }
    
    *p = NULL;
    return 0;
}

int pilaVacia (Pila *p) {
   
    if (p == NULL) {
        return -1;
    }
    
    return (*p == NULL);
}

int pilaInserta (Pila *p, tipoElemento elemento) { 
     
    tipoCelda *nuevo;
    
    if (p == NULL) {
        return -1;
    }
    
    nuevo = (tipoCelda *)malloc(sizeof(tipoCelda));
    
    if (nuevo == NULL) {
        return -2;
    } else {
        nuevo->elemento = elemento;
        nuevo->sig = *p;
        *p = nuevo;
        return 0;
    }
}

tipoElemento pilaSuprime (Pila *p) {
   
    tipoCelda *aBorrar;
    tipoElemento elemento;
    
    if (p == NULL || *p == NULL) {
        return -1;
    } else {
        aBorrar = *p;
        elemento = (*p)->elemento;
        
        *p = (*p)->sig;
        free(aBorrar);
        
        return elemento;
    }
}
