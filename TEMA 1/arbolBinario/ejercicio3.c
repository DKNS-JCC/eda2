#include <stdio.h>
#include <string.h>
#include "arbol.h"
#include "genArbol.h"

int main(void) {
    
    Arbol arbol;
    char ex_postfija[10];

/* Generación del arbol algebraico */
    strcpy(ex_postfija,"AB+CDE+**\0");

    arbol = genArbol(ex_postfija);

/* Recorrido en amplitud o por niveles */
    amplitud(arbol);

/* Aplicacion de algunas operaciones y recorridos al arbol ejemplo */

    printf("Recorrido en PRE_ORDEN: ");
    preOrden(arbol);
    printf("\n");

    printf("Recorrido en ORDEN: ");
    enOrden(arbol);
    printf("\n");
    printf("Recorrido en POST_ORDEN: ");
    postOrden(arbol);
    printf("\n");
    printf("Debe coinicidir con la expresion postfija inicial\n");

    printf("El arbol tiene %d nodos \n", numNodos(arbol));
    printf("y altura: %d\n",altura(arbol));

    printf("El arbol tiene %d nodos\n", numNodos(arbol));
    arbol = anula(arbol);
    printf("Despues de anula el arbol queda vacio, por tanto la altura ser 0.\n");
    if (altura(arbol) != -1)		// Cuidado con definicion de altura
        printf("El arbol no se ha anulado correctamente\n");
    else
        printf("O.K. Parece que la operacion anula funciona!!!\n");


/* Evaluacion de un arbol algebraico: operandos entre '0' y '9'*/

    strcpy(ex_postfija,"23+713+**\0");
    arbol = genArbol(ex_postfija);
    printf("evalua: %d\n", evaluar(arbol));
    printf("Recorrido en PRE_ORDEN (prefija): ");
    preOrden(arbol);
    printf("\n");
    printf("Recorrido en ORDEN(infija): ");
    enOrden(arbol);
    printf("\n");
    printf("Recorrido en POST_ORDEN(postfija): ");
    postOrden(arbol);
    printf("\n");

/* Aplicar a este arbol las funciones del ejercicio 2 */

    return 1;
}
