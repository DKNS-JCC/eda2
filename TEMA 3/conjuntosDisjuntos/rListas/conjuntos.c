#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conjuntos.h"

// Incluir aqui las funciones que implementan las tres operaciones básicas
// en la representación de CONJUNTOS DISJUNTOS mediante LISTAS

void crea(particion P) {
    
    int i;
    tipoCelda *nuevo;

    for(i = 0; i < MAXIMO; i++){
        if(NULL == (nuevo = malloc(sizeof(tipoCelda)))){
            printf("No se pudo reservar memoria para un nuevo nodo.\n");
            exit(-1);
        }
        nuevo->elemento = i;
        nuevo->sig = NULL;
        P[i].primero = P[i].ultimo = nuevo;
    }
}

tipoConjunto buscar(tipoElemento x, particion P) {
    
    int i;
    tipoCelda* aux;
    
    if(x < 0 || x > MAXIMO) {
        return -1;
    }

    for(i = 0; i < MAXIMO; i++){
        aux = P[i].primero;
        while(aux != NULL){
            if(aux->elemento == x){
                return i;
            }
            aux = aux->sig;
        }
    }

    return -1;

}

int unir(tipoConjunto x, tipoConjunto y, particion P) {
    
    /*
     * Esto se pone para que no de segmentation fault en el programa
     * principal, ya que la llamada a esta funcion sera de la forma
     * unir(buscar(x,P), buscar(y,P), P), si la llamada fuera correcta
     * no haria falta ponerlo
     */
    x = buscar(x,P);
    y = buscar(y,P);
    
    if(x == y) {
        return 0; // ya pertenecen a la misma clase de quivalencia
    }

    P[x].ultimo->sig = P[y].primero;
    P[x].ultimo = P[y].ultimo;
    P[y].primero = P[y].ultimo = NULL;
    
    return 1;
}



void verParticion(particion P) {
    
    int i;
    tipoCelda *aux;
    
    for (i = 0; i < MAXIMO; i++) {
        aux = P[i].primero;
        if (aux != NULL)
            printf("\n\nClase equivalencia representante %d: ",i);
        while (aux!=NULL) {
            printf("%d ",aux->elemento);
            aux=aux->sig;
        }
    }
    printf("\n\n");
}

void verClaseEquivalencia(tipoElemento x,particion P) {
    
    int representante;
    tipoCelda *aux;
  
    representante = buscar(x,P);
    printf("\n\nClase de Equivalencia de %d cuyo representante es %d: ", x, representante);
    aux = P[representante].primero;
    while (aux) {
        printf(" %d ",aux->elemento);
        aux=aux->sig;
    }
    printf("\n\n");
}
