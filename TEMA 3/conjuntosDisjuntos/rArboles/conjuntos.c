#include "conjuntos.h"
#include <stdio.h>

#ifdef ARBITRARIO
    #undef TAMANNO
    #undef ALTURA
#endif
#ifdef TAMANNO
    #undef ALTURA
    #undef ARBITRARIO
#endif
#ifdef ALTURA
    #undef TAMANNO
    #undef ARBITRARIO
#endif

// Incluir aqui las funciones que implementan las tres operaciones básicas
// en la representación de CONJUNTOS DISJUNTOS mediante ÁRBOLES


void crea(particion P) {
    int i;
    
#ifdef ARBITRARIO
    for (i = 0; i < MAXIMO; i++) {
        P[i] = i; // Cada elemento es su propio representante al principio
    }
#endif
    
#ifdef TAMANNO
    for (i = 0; i < MAXIMO; i++) {
        P[i] = -1; // inicializamos todos los elementos con -1
    }
#endif

#ifdef ALTURA
    for (i = 0; i < MAXIMO; i++) {
        P[i] = -1;
    }
#endif
    
}

tipoConjunto buscar(tipoElemento x, particion P) {
 
#ifdef ARBITRARIO
    if (P[x] == x) {
        return x;
    } else {
        P[x] = buscar(P[x], P);
        return P[x];
    }
#endif
  
#ifdef TAMANNO
    if (P[x] < 0) {
        return x; // si x es una raíz, la clase es ella misma
    } else {
        // búsqueda recursiva y compresión de caminos
        P[x] = buscar(P[x], P);
        return P[x];
    }
#endif

#ifdef ALTURA
    if (P[x] < 0) {
        return x;  // Si x es una raíz, devuelve su índice
    } else {
        // Realiza la búsqueda recursiva de la raíz del árbol que contiene x
        P[x] = buscar(P[x], P);
        return P[x];
    }
#endif
}

int unir(tipoConjunto x, tipoConjunto y, particion P) {

#ifdef ARBITRARIO
    // Establecer la nueva raíz como x
    P[y] = x;
    return 1;
#endif

#ifdef TAMANNO //NO SE ME UNE BIEN EL 2 PREGUNTAR
    if (x == y) {
        return 0; // las raíces son iguales, no hay nada que unir
    } else {
        // unimos por tamaño
        if (P[x] > P[y]) {
            P[y] += P[x];
            P[x] = y;
        } else {
            P[x] += P[y];
            P[y] = x;
        }
        return 1; // hubo unión
    }
#endif

#ifdef ALTURA
    int altura_x, altura_y;

    if (P[x] < 0) {
        altura_x = P[x];
    } else {
        altura_x = 0;
    }

    if (P[y] < 0) {
        altura_y = P[y];
    } else {
        altura_y = 0;
    }

    if (altura_x > altura_y) {
        // El arbol de x es mas alto, se convierte en el padre del arbol y
        P[y] = x;
    } else {
        if (altura_x == altura_y) {
            //Los arboles tienen la misma altura, se convierte el arbol de x en el padre del arbol de y
            P[y] = x;
            P[x]--;
        } else {
            // El arbol de y es mas alto, convierte el arbol de y en el padre del arbol de x
            P[x] = y;
        }
    }

    return 1;
#endif
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
    printf("  índices vector\n\n");
}
