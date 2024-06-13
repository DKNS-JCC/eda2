#include "conjuntos.h"
#include <stdio.h>

/// Incluir aqui las funciones que implementan las tres operaciones básicas 
/// en la representación de CONJUNTOS DISJUNTOS mediante ÁRBOLES
/// ......................................................................
void crea(particion P){
	int i;
	
	for(i = 0; i < MAXIMO_CONJ; i++)
		P[i] = -1;
}


tipoElemento buscar(tipoElemento x, particion P){
    
    if (P[x] < 0) {
        return x;  // Si x es una raíz, devuelve su índice
    } else {
        // Realiza la búsqueda recursiva de la raíz del árbol que contiene x
        P[x] = buscar(P[x], P);
        return P[x];
    }
}

int unir(tipoElemento x, tipoElemento y, particion P){
    
    if (x == y) {
        return 0;
    }
    
    if (P[x] > P[y]) {
        P[y] += P[x];
        P[x] = y;
    } else {
        P[x] += P[y];
        P[y] = x;
    }
    
    return 1;
    
}


//
// Función auxiliar para ver contenido de Partición 
//
void verParticion(particion C){
    
    int i;
    printf("\n");
    for (i = 0; i < MAXIMO_CONJ; i++) printf("|%2d",C[i]);
    printf("| contenido  vector\n");
    for (i = 0; i < MAXIMO_CONJ; i++) printf("---");
    printf("\n");
    for (i = 0; i < MAXIMO_CONJ; i++) printf(" %2d",i);
    printf("  índices vector\n\n");
}
