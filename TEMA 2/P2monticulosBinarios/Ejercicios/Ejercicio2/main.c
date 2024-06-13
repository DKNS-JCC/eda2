#include <stdio.h>
#include <stdlib.h>
#include "monticulo.h"



int main(void) { 

	Monticulo m;
	int i, n=10;
	tipoElemento elemento;

	iniciaMonticulo(&m);
	printf("Monticulo iniciado\n");

	for(i=1;i<=n;i++){
		elemento.clave=rand()%100;
		insertar(elemento,&m);
		imprimeMonticulo(m);
	}

	heapSort(&m);
	printf("MONTÍCULO ORDENADO:\n");
	imprimeMonticulo(m);
}




