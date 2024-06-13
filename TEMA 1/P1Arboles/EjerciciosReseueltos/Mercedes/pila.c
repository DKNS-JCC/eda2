//Mercedes Parra Sánchez

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "pila.h"



int pilaCreaVacia(Pila *p)
{
    p=NULL;
    return 0;
    
}

int pilaVacia(Pila *p)
{
    
    return(p==NULL);
    
}

int pilaInserta(Pila *p,tipoElemento elemento)
{
   
    tipoCelda *aux;
    
    if (NULL == (aux = malloc (sizeof(tipoCelda)))) {
    	return -1;
    } else if (*p == NULL) {
    	aux->elemento = elemento;
    	*p = aux;
    	aux->sig = NULL;
    } else {
    	aux->elemento = elemento;
    	aux->sig = *p;
    	*p = aux;
    }
    
    return 0;
   
   
    /*tipoCelda * temp;
    
    temp = (tipoCelda *) malloc (sizeof(tipoCelda));
    if(temp == NULL) return -1;
    
    temp->elemento=elemento;
    if(pilaVacia(p)){
        temp->sig=NULL;
    }else
        temp->sig=*p;
    *p=temp;
    
    return 0;*/
}

tipoElemento pilaSuprime(Pila *p)
{
    tipoCelda * aBorrar;
    tipoElemento x;
    
	if(*p==NULL)
		return NULL;
    aBorrar=*p;
    /*if(aBorrar==NULL) {
     return NULL;
    }*/
    
    *p=aBorrar->sig;
    x=aBorrar->elemento;
    free(aBorrar);

    return x;
}
