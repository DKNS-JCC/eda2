#include <stdlib.h>
#include <stdio.h>
#include "monticulo.h"

int main(void) {
    
    Monticulo m;
    int i, n = 10;
    tipoElemento elemento;

    iniciaMonticulo(&m);

    m.tamanno = n;
    for (i = 1; i <= n; i++)
        m.elemento[i].clave = rand()%100;

    heapSort(&m);
    printf("\nEl monticulo obtenido por ordenacion heapSort es: ");
    for (i = 1; i <= m.tamanno; i++)
        printf("%d ", m.elemento[i].clave);
    
    printf("\n¿Hemos conseguido un monticulo binario correcto?: ");
    if (esMonticulo(m))
        printf("Si\n");
    else
        printf("No\n");

}




