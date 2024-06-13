#include <stdlib.h>
#include <stdio.h>
#include "genArbol.h"
#include "pila.h"



Arbol genArbol(char *exPostfija) {
    
    Pila p = NULL;
    Arbol a = NULL;
    int i = 0;
    char simbolo;
    tipoInfo info;
    simbolo = exPostfija[i];
    while (simbolo != '\0') {
        switch(esOperador(simbolo)) {
            case 0: a = creaNodo(simbolo);
                pilaInserta(&p, a);
                break;
            case 1: a = creaNodo(simbolo);
                a->der = (Arbol) pilaSuprime(&p);
                a->izq = (Arbol) pilaSuprime(&p);
                pilaInserta(&p, a);
                break;
            default: printf("\n\n¡¡Expresión incorrecta !!\n\n");
                // anula(a);
                while (!pilaVacia(&p)) pilaSuprime(&p);
                    return NULL;
        }
        i++;
        simbolo = exPostfija[i];
    }
    return pilaSuprime(&p);
}

int esOperador(char simbolo) {
    
    if ((simbolo == '+') || (simbolo == '-') || (simbolo == '*') || (simbolo == '/'))
        return 1;
    else  if ((simbolo >= 'A' && simbolo <= 'Z') || (simbolo >= 'a' && simbolo <= 'z') || (simbolo >= '0' && simbolo <= '9'))
  		return 0;
  	else return -1;
}

int evaluar(Arbol a) {
    
    int izquierdo, derecho;

    if (a == NULL)
        return 0;

    if (a->izq == NULL && a->der == NULL)
        return a->info - '0'; //Restamos por estar en codigo ASCII

    izquierdo = evaluar(a->izq);
    derecho = evaluar(a->der);

    switch (a->info) {
        case '+':
            return izquierdo + derecho;
        case '-':
            return izquierdo - derecho;
        case '*':
            return izquierdo * derecho;
        case '/':
            return izquierdo / derecho;
        default:
            printf("Operación no reconocida\n");
            return 0;
    }
}
