#include <stdio.h>
#include <stdlib.h>
#include "arbolBB.h"

int calcularfe(tipoArbolBB raiz, int* h);

int main(void){
	tipoArbolBB a;
	int fe = 0, feR = -999;

	insertar(&a,25);
 insertar(&a,35);
 insertar(&a,15);
 insertar(&a,20);
 insertar(&a,12);
 insertar(&a,13);
 insertar(&a,15);
 insertar(&a,15);
 insertar(&a,15);
 insertar(&a,45);
 insertar(&a,30);
 insertar(&a,10);

	feR = calcularfe(a, &fe);
	printf("El factor de equilibrio es: %d\n",feR);
	
}

int calcularfe(tipoArbolBB raiz, int *h){
	if(NULL == raiz){
		*h = -1;
		return 1;
	}else{
		int hizq, hder;
		if(!calcularfe(raiz->izq,&hizq) || !calcularfe(raiz->der,&hder))
			return 0;
		
		*h = 1 + ((hizq > hder) ? (hizq) : (hder));
		
		raiz->fe = hder - hizq;
		return (raiz->fe < -1 || raiz->fe > 1) ? (0) : (1);
	}
}
