#include <stdlib.h>
#include <stdio.h>
#include "arbol.h"
#include "cola.h"

//
// Reserva de memoria para un nuevo nodo de árbol binario
//
Arbol creaNodo(tipoInfo info)
{ tipoNodo * nuevo;

  //   nuevo =(tipoNodo *)calloc(1, sizeof(tipoNodo));
  if ((nuevo =(tipoNodo *)malloc(sizeof(tipoNodo)))==NULL)
	return NULL;
  else
  { 	nuevo->info=info;
	nuevo->izq=NULL;
	nuevo->der=NULL;
	return nuevo;
   }
}

//
// Recorrido en amplitud o por niveles: necesita una cola de punteros a nodos de árbol binario!!!
//

void amplitud(Arbol raiz)
{ Cola c;
  tipoNodo *nodo;
  colaCreaVacia(&c);
  nodo = raiz;
  if (raiz!=NULL) colaInserta(&c,nodo);
  while (!colaVacia(&c))
  { nodo = (Arbol) colaSuprime(&c);
    printf(" %c ", nodo->info);
    if (nodo->izq!=NULL) colaInserta(&c,nodo->izq);
    if (nodo->der!=NULL) colaInserta(&c,nodo->der);
  }
}
// 
// Recorridos en profundidad "recursivos"
//
void preOrden(Arbol raiz)
{ if (raiz!=NULL)
  { printf("%c ",raiz->info);
    preOrden(raiz->izq);
    preOrden(raiz->der);
  }
}
void enOrden(Arbol raiz)
{ if (raiz!=NULL)
  { enOrden(raiz->izq);
    printf("%c ",raiz->info);
    enOrden(raiz->der);
  }
}
void postOrden(Arbol raiz)
{ if (raiz!=NULL)
  { postOrden(raiz->izq);
    postOrden(raiz->der);
    printf("%c ",raiz->info);
  }
}

int altura (Arbol raiz){
    int alt=-1;
    int temp1,temp2;
    if(raiz!=NULL){
        temp1=altura(raiz->izq);
        temp2=altura(raiz->der);
        if(temp1>temp2) alt=1+temp1;
        else alt=1+temp2;
    }
    
    return alt;
}

int numNodos(Arbol raiz){
    
    int nodos1, nodos2, total=0;
    
    if (raiz!=NULL)
    {
        nodos1=numNodos(raiz->izq);
        nodos2=numNodos(raiz->der);
        total=nodos1+nodos2+1;
    }
    return total;
}
//R******************************+
Arbol anula(Arbol raiz){
    
    if (raiz!=NULL)
    {
        raiz->izq=anula(raiz->izq);
        raiz->der=anula(raiz->der);
        free(raiz);
        raiz=NULL;
    }
    return raiz;
}

int sustituye(Arbol raiz, tipoInfo x, tipoInfo y){
    
    int numSustituciones=0;
    
    if (raiz!=NULL)
    {
        numSustituciones= sustituye(raiz->izq,x,y) + sustituye(raiz->der,x,y);
        if(raiz->info==x){
            raiz->info=y;
            numSustituciones++;
        }
        
    }
    
    return numSustituciones;
}

int numNodosHoja(Arbol raiz){
    
    int numHojas=0;
    
    if(raiz!=NULL){
        
        numHojas = numNodosHoja(raiz->izq) + numNodosHoja(raiz->der);
        if(raiz->izq==NULL && raiz->der==NULL) numHojas++;
    }
    
    return numHojas;
}

int numNodosInternos(Arbol raiz){
    
    int numInternos=0;
    
    if(raiz!=NULL){
        
        numInternos = numNodosInternos(raiz->izq) + numNodosInternos(raiz->der);
        if(raiz->izq!=NULL || raiz->der!=NULL) numInternos++;
    }
    
    return numInternos;
}

int numHijoUnico(Arbol raiz){

    int numUnico=0;
    
    if(raiz!=NULL){
        
        numUnico = numHijoUnico(raiz->izq) + numHijoUnico(raiz->der);
        if((raiz->izq!=NULL && raiz->der==NULL) || (raiz->izq==NULL && raiz->der!=NULL) ){
            numUnico++;
        }
    }
    
    return numUnico;
    
}

Arbol buscarMax(Arbol raiz){
    
    Arbol maximo1, maximo2, maximoTotal=NULL;
    
    if(raiz!=NULL){
        
        maximo1 = buscarMax(raiz->izq);
        maximo2 = buscarMax(raiz->der);
        maximoTotal= raiz;
        
        if(maximo1!=NULL)
            if(maximo1->info > maximoTotal->info) maximoTotal=maximo1;
        if(maximo2!=NULL)
            if(maximo2->info > maximoTotal->info) maximoTotal=maximo2;
        
    }
    
    return maximoTotal;
    
}

Arbol buscarMin(Arbol raiz){
    
    Arbol minimo1, minimo2, minimoTotal=NULL;
    
    if(raiz!=NULL){
        
        minimo1 = buscarMin(raiz->izq);
        minimo2 = buscarMin(raiz->der);
        minimoTotal= raiz;
        
        if(minimo1!=NULL)
            if(minimo1->info < minimoTotal->info) minimoTotal=minimo1;
        if(minimo2!=NULL)
            if(minimo2->info < minimoTotal->info) minimoTotal=minimo2;
        
    }
    
    return minimoTotal;
    
}

int similares(Arbol r1,Arbol r2){
    
    if(r1!=NULL && r2!=NULL){
        
        if( similares(r1->izq,r2->izq) && similares(r1->der,r2->der) ) return 1;
            else return 0;
    }
    if( (r1!=NULL && r2==NULL) || (r1==NULL && r2!=NULL)) return 0;
    
    return 1;
}


int equivalentes(Arbol r1, Arbol r2){
    
    if(r1!=NULL && r2!=NULL){
        
        if( equivalentes(r1->izq,r2->izq) && equivalentes(r1->der,r2->der) ){
            if(r1->info==r2->info) return 1;
            else return 0;
        }else return 0;
    }
    if( (r1!=NULL && r2==NULL) || (r1==NULL && r2!=NULL)) return 0;
    
    return 1;
}

Arbol especular(Arbol raiz){
    
    Arbol nodo=NULL;
    
    if (raiz!=NULL){
        
        nodo=creaNodo(raiz->info);
        nodo->der=especular(raiz->izq);
        //printf(" %c ", nodo->info);
        nodo->izq=especular(raiz->der);
    }
    
    return nodo;
}








