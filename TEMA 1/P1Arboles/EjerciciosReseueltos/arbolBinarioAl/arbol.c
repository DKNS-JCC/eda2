#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"



/*INTERFAZ ÁRBOLES*/
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


/*Recorrido del árbol binario*/
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
            return 1;
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

int evaluar(Arbol a){
	int n1, n2;
	int resultado;
	if(a!=NULL){
		if((a->izq!=NULL)&&(a->der!=NULL)){
			n1=evaluar(a->izq);
			n2=evaluar(a->der);
			printf("%d\t%d\n",n1,n2);
			switch(a->info){
				case '+': resultado=n1+n2; break;
				case '-': resultado=n1-n2; break;
				case '*': resultado=n1*n2; break;
			}		
		}else resultado=((int)(a->info))-48;
		return resultado;
	}else return -99999;
}

int evaluar2(Arbol a){
	
	if(a==NULL) return -99999;
	if(a->info=='+')
		return (evaluar(a->izq)+evaluar(a->der));

	if(a->info=='-')
		return (evaluar(a->izq)-evaluar(a->der));
	
	if(a->info=='*')
		return (evaluar(a->izq)*evaluar(a->der));

	return (a->info-48);
}



