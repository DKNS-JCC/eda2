#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"
#include "cola.h"


/*INTERFAZ �RBOLES*/
Arbol creaNodo(tipoInfo info){

    tipoNodo *nodoAux;

    nodoAux=(tipoNodo*)malloc(sizeof(tipoNodo));
    if(nodoAux==NULL){
        printf("ERROR: RESERVA DE MEMORIA (en crea_nodo)\n");
        exit(1);
    }
    nodoAux->info=info;
    nodoAux->izq=NULL;
    nodoAux->der=NULL;

    return nodoAux;
}


/*Recorrido del �rbol binario*/
void preOrden(Arbol raiz){

    if(raiz!=NULL){
        printf("%c ",raiz->info);
        preOrden(raiz->izq);
        preOrden(raiz->der);
    }
}


void enOrden(Arbol raiz){
    if(raiz!=NULL){

        enOrden(raiz->izq);
        printf("%c ",raiz->info);
        enOrden(raiz->der);
    }

}

void postOrden(Arbol raiz){
    if(raiz!=NULL){
        postOrden(raiz->izq);
        postOrden(raiz->der);
        printf("%c ",raiz->info);
    }
}

void amplitud(Arbol raiz){
    
    Cola c;
    Arbol nodo;
    creaVacia(&c);
    nodo=raiz;

    if(nodo!=NULL)
        insertaC(&c,nodo);
	
    while(!vacia(&c)){
		
            nodo=c.frente->sig->elemento;
            printf("%c ",nodo->info);
            suprime(&c);

            if(nodo->izq!=NULL)
                insertaC(&c,nodo->izq);
            if(nodo->der!=NULL)
                insertaC(&c,nodo->der);
    }
}


/*Caracter�sticas del �rbol binario*/
int altura(Arbol raiz){
    int h_izq, h_der;
    if(raiz!=NULL){
        h_izq=altura(raiz->izq);
        h_der=altura(raiz->der);
        if(h_izq>h_der){
            h_izq++;
            return 1+h_izq;
        }
        else{
            h_der++;
            return 1+h_der;
        }
    }
    else
        return 0;

}

/*C�lculo de la altura del nodo de SILVIA SIERRA*/
int calculaH(Arbol a){

	int a_izq, a_der, altura;
	if(a!=NULL){
		a_izq=altura(a->a_izq);
		a_der=altura(a->a_der);
		if(a_izq->a_der){
			a_izq++;
			return a_izq;
		}else{
			a_der++;
			return a_der;
		}

	}
	else return 0;
}

int numNodos(Arbol raiz){

    if(raiz!=NULL){
        return 1+ numNodos(raiz->izq)+numNodos(raiz->der);
    }
    else
        return 0;
}

int numNodosHoja(Arbol raiz){
    if(raiz!=NULL){
        if((raiz->izq==NULL)&&(raiz->der==NULL))
            return 1+ numNodosHoja(raiz->izq)+numNodosHoja(raiz->der);
        else
            return 0+ numNodosHoja(raiz->izq)+numNodosHoja(raiz->der);
    }
    else
        return 0;
}

int numNodosInternos(Arbol raiz){
    if(raiz!=NULL){
        if((raiz->izq!=NULL)||(raiz->der!=NULL))
            return 1+ numNodosInternos(raiz->izq)+numNodosInternos(raiz->der);
        else
            return 0;
    }
    else
        return 0;
}

int numX(Arbol a, tipoInfo x){
    if(a!=NULL){
        if(a->info==x)
            return 1+numX(a->izq,x)+numX(a->der,x);
        else
            return 0+numX(a->izq,x)+numX(a->der,x);
    }else return 0;
}

int numHijoUnico(Arbol raiz){
    if(raiz!=NULL){
        if((raiz->izq&&!raiz->der)||(!raiz->izq&&raiz->der))
            return 1+ numHijoUnico(raiz->izq)+numHijoUnico(raiz->der);
        else
            return 0+ numHijoUnico(raiz->izq)+numHijoUnico(raiz->der);
    }
    else
        return 0;

}

int sustituye(Arbol raiz, tipoInfo x, tipoInfo y){
    
    if(raiz!=NULL){
        if(raiz->info==x){   
		raiz->info=y;
        	return 1+ sustituye(raiz->izq,x,y)+sustituye(raiz->der,x,y);
	}else return 0+ sustituye(raiz->izq,x,y)+sustituye(raiz->der,x,y);
    }
    else return 0;

}


Arbol buscarMax(Arbol raiz){
    
	Cola c;
    tipoInfo Max;
    Arbol nodo;
    tipoNodo *pos;

   
    return pos;
}

/*Arbol buscarMin(Arbol raiz){
    Cola c;
    tipoInfo min;
    Arbol nodo;
    tipoNodo *pos;

    creaVacia(&c);
    nodo=raiz;

    if(nodo!=NULL)
        encola(&c,nodo);
    while(!vacia(&c)){
            nodo=frente(&c);
            if((nodo->info)<min){
                min=nodo->info;
                pos=nodo;
            }
            desencolar(&c);

            if(nodo->izq!=NULL)
                encola(&c,nodo->izq);
            if(nodo->der!=NULL)
                encola(&c,nodo->der);
    }
    return pos;
}*/

Arbol anula(Arbol raiz){

    raiz=NULL;
    return raiz;
}

int similares(Arbol r1,Arbol r2){
    if((r1==NULL)&&(r2==NULL))
        return 1;
    else if((r1==NULL)&&(r2!=NULL)||(r1!=NULL)&&(r2==NULL))
        return 0;
        else
            return similares(r1->izq,r2->izq)&&similares(r1->der,r2->der);

}

int equivalentes(Arbol r1,Arbol r2){
    if((r1==NULL)&&(r2==NULL))
        return 1;
    else if((r1==NULL)&&(r2!=NULL)||(r1!=NULL)&&(r2==NULL))
        return 0;
        else if(r1->info==r2->info)
            return equivalentes(r1->izq,r2->izq)&&equivalentes(r1->der,r2->der);


}
Arbol especular(Arbol raiz){
    Arbol nodo;
    if (raiz == NULL)
        return NULL;

    nodo = creaNodo(raiz->info);
    nodo->izq = especular(raiz->der);
    nodo->der = especular(raiz->izq);
    return nodo;

}
