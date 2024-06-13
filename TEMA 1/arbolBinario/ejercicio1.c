#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"

int main (void) {
    
    Arbol varArbol;

/* Creación arbol ejemplo de las transparencias de recorridos */
    varArbol = creaNodo('A');
    varArbol->izq = creaNodo('B');
    varArbol->der = creaNodo('C');
    varArbol->izq->izq = creaNodo('D');
    varArbol->izq->der = creaNodo('E');
    varArbol->der->izq = creaNodo('F');
    varArbol->der->der = creaNodo('G');


/* Aplicación de recorridos al arbol ejemplo */

    printf("Recorrido en PRE_ORDEN: ");
    preOrden(varArbol);
    printf("\n");
    printf("Recorrido en ORDEN: ");
    enOrden(varArbol);
    printf("\n");
    printf("Recorrido en POST_ORDEN: ");
    postOrden(varArbol);
    printf("\n");
    printf("Recorrido en AMPLITUD: ");
    amplitud(varArbol);
    printf("\n");

/* Comenzar a implementar y probar las funciones del ejercicio 2 ... y segunda parte del ejercicio 3 */
    
    printf("\nAltura del arbol: %d", altura(varArbol));
    printf("\nNumero de Nodos del arbol: %d", numNodos(varArbol));
    printf("\nNumero de Nodos Hoja del arbol: %d", numNodosHoja(varArbol));
    printf("\nNumero de Nodos Internos del arbol: %d", numNodosInternos(varArbol));
    printf ("\nNumero de Nodos con un solo hijo: %d", numHijoUnico(varArbol));
    printf ("\nBuscar maximo del arbol: %c", buscarMax(varArbol)->info);
    printf ("\nBuscar minimo del arbol: %c", buscarMin(varArbol)->info);
    
    
    
    //sustituye
    printf("\n\nSustituye el nodo que contenga %c por %c", 'C','K');
    sustituye(varArbol,'C','K');
    printf("\n   --> Nuevo Recorrido en Orden: ");
    enOrden(varArbol);
    printf("\n   --> Buscar maximo del arbol (con nodo sustituido): %c", buscarMax(varArbol)->info);
    printf("\n   --> Buscar minimo del arbol (con nodo sustituido): %c", buscarMin(varArbol)->info);

    //Creamos otro arbol para poder comprobar si son similares o equivalentes
    Arbol varArbol2;
    
    varArbol2 = creaNodo('A');
    varArbol2->izq = creaNodo('B');
    varArbol2->der = creaNodo('C');
    varArbol2->izq->izq = creaNodo('D');
    varArbol2->izq->der = creaNodo('E');
    varArbol2->der->izq = creaNodo('F');
    varArbol2->der->der = creaNodo('G');
    
    printf("\n\n{");
    amplitud(varArbol);
    printf("}   y   {");
    amplitud(varArbol2);
    printf("}");
    printf("\nComprobar si dos arboles son similares: ");
    if (similares(varArbol, varArbol2)) {
        printf("Son similares");
    } else {
        printf("NO son similares");
    }
    
    printf("\nComprobar si dos arboles son equivalentes: ");
    if (equivalentes(varArbol, varArbol2)) {
        printf("Son equivalentes");
    } else {
        printf("NO son equivalentes");
    }

    Arbol varArbol3 = especular(varArbol);
    printf("\nArbol especular de: ");
    enOrden(varArbol);
    printf("es ");
    enOrden(varArbol3);
    
    char PreOrden[]={'E','S','T','R','U','C', 'T','U','R','A','S'};
    char EnOrden[]={'R','T','U','S','E','C', 'U','T','A','R','S'};
    
    Arbol nuevo = reconstruirArbol(PreOrden, EnOrden, 0, 10, 0, 10);
    printf("\n\nAHORA HAGO EL EJERCICIO 4 ");
    printf("\n   --> Nuevo Recorrido en Orden: ");
    enOrden(nuevo);
    printf("\n   --> Nuevo Recorrido en PreOrden: ");
    preOrden(nuevo);
    printf("\n   --> Nuevo Recorrido en PostOrden: ");
    postOrden(nuevo);
    printf("\n   --> Nuevo Recorrido en Amplitud: ");
    amplitud(nuevo);
    
    printf("\n----------------\n");
    printf("Anulando arbol..."); anula(varArbol);
    printf("\n");
    
    return 1;
}

