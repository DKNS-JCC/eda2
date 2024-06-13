#include <stdio.h>
#include <stdlib.h>

#ifdef MATRICES
#include "rMatrices/conjuntos.h"
#endif
#ifdef LISTAS
#include "rListas/conjuntos.h"
#endif
#ifdef ARBOLES
#include "rArboles/conjuntos.h"
#endif


int main() {
    
    particion P;
    int i;

	crea(P);
	printf("\nSituacion INICIAL: ");
	verParticion(P);

	// Se forman las siguientes clases de equivalencia haciendo al primer elemento del conjunto su representante:
	// {7,0,13,15},{2,3,8,12},{11,1,4,6,14},{9,5,10}

	if (unir(buscar(13,P),buscar(15,P),P) && unir(buscar(7,P),buscar(0,P),P) && unir(buscar(7,P),buscar(13,P),P))
		printf("Formada clase de equivalencia {7,0,13,15}\n");
	else 
   		printf("No puede formase la clase de equivalencia {7,0,13,15}\n");

	if (unir(buscar(8,P),buscar(12,P),P) && unir(buscar(3,P),buscar(8,P),P) && unir(buscar(2,P),buscar(3,P),P))
		printf("Formada clase de equivalencia {2,3,8,12}\n");
	else 
		printf("No puede formase la clase de equivalencia {2,3,8,12}\n");

	if (unir(buscar(6,P),buscar(1,P),P) && unir(buscar(6,P),buscar(4,P),P) && unir(buscar(11,P),buscar(14,P),P) && unir(buscar(11,P),buscar(6,P),P))
		printf("Formada clase de equivalencia {11,1,4,6,14}\n");
	else 
		printf("No puede formase la clase de equivalencia {11,1,4,6,14}\n");

	if (unir(buscar(5,P),buscar(10,P),P) && unir(buscar(9,P),buscar(5,P),P))
		printf("Formada clase de equivalencia {5,9,10}\n");
	else 
		printf("No puede formase la clase de equivalencia {5,9,10}\n");

	printf("\nSituacion FINAL:   ");

	verParticion(P);

	printf("\nEl elemento 5 pertenence a la clase de equivalencia con representante %d\n",buscar(5,P));

  	// ATENCION Ejemplo con parametros incorrectos para relacionar el elemento 6 con el 15
    #ifdef MATRICES
	if (unir(6,15,P))
		printf("Relacionado elemento 6 con 15 ...\n");
	else 
		printf("No puede formase la clase de equivalencia ...\n");

	printf("\nLa particion no ha cambiado...[ERROR]\n   ");
	verParticion(P);
    #endif

	// Para asegurar que los parametros son correctos mejor usar siempre  unir(buscar(x,P),buscar(y,P),P)

	unir(buscar(6,P),buscar(15,P),P);
	printf("\nAhora la particion ha cambiado: Se han relacionado 6 y 15? Como han quedado las clases de equivalencia?\n");
	verParticion(P);

	#ifdef LISTAS
	verClaseEquivalencia(5,P);
	#endif

	// ¿Qué operación seria necesaria para relacionar el elemento 12 con el 15?
    //  unir(buscar(12,P),buscar(15,P),P);



}
