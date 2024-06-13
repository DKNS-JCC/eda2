//Mercedes Parra Sánchez

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "cola.h"



int colaCreaVacia(Cola *p)
{
    p->frente=NULL;
    p->fondo=NULL;
    return 0;
}

int colaVacia(Cola *p)
{
    return(p->frente==NULL && p->fondo==NULL);
    
}

int colaInserta(Cola *p,tipoElemento elemento)
{
    tipoCelda * temp;
    
    temp = (tipoCelda *) malloc (sizeof(tipoCelda));
    if(temp==NULL) return -1;
    
    temp->elemento=elemento;
    temp->sig=NULL;
    
    if(colaVacia(p)){
        p->frente=temp;
        p->fondo=temp;
        return 0;
    }
    if(p->fondo!=NULL){
        p->fondo->sig=temp;
        p->fondo=temp;
        return 0;
    }
    
    return -2;
    
}

tipoElemento colaSuprime(Cola *p)
{
    
    tipoCelda * aBorrar;
    tipoElemento x;
    
    if(colaVacia(p)) return NULL;
    
    if(p->frente!=NULL){
        
        aBorrar=p->frente;
        x = aBorrar->elemento;
        
        if(p->frente==p->fondo){
            p->frente=NULL;
            p->fondo=NULL;
        }else{
            p->frente=p->frente->sig;
        }
        free(aBorrar);
        return x;
    }
    
    return NULL;
    
    
}
