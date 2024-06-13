#include "conjuntos.h"
#include <stdio.h>

// Incluir aqui las funciones que implementan las tres operaciones básicas
// en la representación de CONJUNTOS DISJUNTOS mediante MATRICES

void crea(particion P) {
    
    int i;
    for (i = 0; i < MAXIMO; i++) {
        P[i] = i;  // cada elemento es su propio representante al principio
    }
}

tipoConjunto buscar(tipoElemento x, particion P) {
    
    if (x >= 0 && x < MAXIMO) {
        return P[x];
    } else {
        return -1;
    }
}


int unir(tipoConjunto x, tipoConjunto y, particion P) {
    
    int i;
    if (x != y) {
        for (i = 0; i < MAXIMO; i++) {
            if (P[i] == y) {
                P[i] = x;
            }
        }
        return 1; // devolvemos VERDADERO
    }
    return 0; // devolvemos FALSO si ya están unidos
}


//
// Función auxiliar para ver contenido de Partición 
//
void verParticion(particion P) {
    int i;
    printf("\n");
    for (i = 0; i < MAXIMO; i++) printf("|%2d", P[i]);
    printf("| contenido  vector\n");
    for (i = 0; i < MAXIMO; i++) printf("---");
    printf("\n");
    for (i = 0; i < MAXIMO; i++) printf(" %2d", i);
    printf("  indices vector\n\n");
}
