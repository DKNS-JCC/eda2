#include <stdlib.h>
#include <stdio.h>
#include "monticulo.h"

int main(void) {
    
    Monticulo m;
    tipoElemento elemento, minimo;
    int i, n = 10;

    iniciaMonticulo(&m);
    elemento.clave = 12;
    elemento.informacion = 0;

    i = insertar(elemento, &m);

    while (m.tamanno < n) {
        elemento.clave = rand()%100;
        i = insertar(elemento, &m);
    }
    
    printf("\nEl monticulo obtenido es: ");
    for (i = 1; i <= m.tamanno; i++)
        printf("%d ", m.elemento[i].clave);
    
    printf("\n¿Hemos conseguido un monticulo binario correcto?: ");
    if (esMonticulo(m))
        printf("Si\n");
    else
        printf("No\n");

    printf("\nDecrementamos la posicion 7 en 20 unidades");
    decrementarClave(7, 20, &m);
    printf("\nEl monticulo obtenido es: ");
    for (i = 1; i <= m.tamanno; i++)
        printf("%d ", m.elemento[i].clave);
   
    printf("\n¿Hemos conseguido un monticulo binario correcto?: ");
    if (esMonticulo(m))
        printf("Si\n");
    else
        printf("No\n");
    
    printf("\nAumentamos la posicion 3 en 30 unidades");
    incrementarClave(3, 30, &m);
    printf("\nEl monticulo obtenido es: ");
    for (i = 1; i <= m.tamanno; i++)
        printf("%d ", m.elemento[i].clave);
    
    printf("\n¿Hemos conseguido un monticulo binario correcto?: ");
    if (esMonticulo(m))
        printf("Si\n");
    else
        printf("No\n");
    
    

    eliminarMinimo(&m, &minimo);
    printf("\nEliminamos el valor minimo del monticulo: %d", minimo.clave);
    printf("\nEl monticulo obtenido es: ");
    for (i = 1; i<= m.tamanno; i++)
        printf("%d ", m.elemento[i].clave);
    
    printf("\n¿Hemos conseguido un monticulo binario correcto?: ");
    if (esMonticulo(m))
        printf("Si\n");
    else
        printf("No\n");

    heapSort(&m);
    printf("\nEl monticulo obtenido por ordenacion heapSort es: ");
    for (i = 1; i <= m.tamanno; i++)
        printf("%d ", m.elemento[i].clave);

}




