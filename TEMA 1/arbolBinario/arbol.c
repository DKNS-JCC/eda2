#include <stdlib.h>
#include <stdio.h>
#include "arbol.h"
#include "cola.h"

//
// Reserva de memoria para un nuevo nodo de árbol binario
//
Arbol creaNodo(tipoInfo info) {
    
    tipoNodo * nuevo;

    //   nuevo =(tipoNodo *)calloc(1, sizeof(tipoNodo));
    if ((nuevo = (tipoNodo *)malloc(sizeof(tipoNodo))) == NULL) return NULL;
    else {
        nuevo->info = info;
        nuevo->izq = NULL;
        nuevo->der = NULL;
        return nuevo;
    }
}

//
// Recorrido en amplitud o por niveles: necesita una cola de punteros a nodos de árbol binario!!!
//

void amplitud(Arbol raiz) {
    
    Cola c;
    tipoNodo *nodo;
    colaCreaVacia(&c);
    
    nodo = raiz;
    if (raiz != NULL) colaInserta (&c,nodo);
    while (!colaVacia(&c)) {
        nodo = (Arbol) colaSuprime(&c);
        printf(" %c ", nodo->info);
        if (nodo->izq != NULL) colaInserta (&c, nodo->izq);
        if (nodo->der != NULL) colaInserta (&c, nodo->der);
    }
}

// 
// Recorridos en profundidad "recursivos"
//
void preOrden(Arbol raiz) {
    
    if (raiz != NULL) {
        printf("%c ", raiz->info);
        preOrden(raiz->izq);
        preOrden(raiz->der);
    }
}

void enOrden(Arbol raiz) {
    
    if (raiz != NULL) {
        enOrden(raiz->izq);
        printf("%c ", raiz->info);
        enOrden(raiz->der);
    }
}

void postOrden(Arbol raiz) {
    
    if (raiz != NULL) {
        postOrden(raiz->izq);
        postOrden(raiz->der);
        printf("%c ", raiz->info);
    }
}

//
// Funciones del ejercicio 2
//
int altura(Arbol raiz) {
    
    int alturaIzq, alturaDer;
    
    if (raiz == NULL) {
        return -1; //Porque la altura 0 es cuando tengo solo un nodo
    }
    
    alturaIzq = altura(raiz->izq);
    alturaDer = altura(raiz->der);
    
    if (alturaIzq >= alturaDer) { //Calculamos la altura del arbol maximo
        return alturaIzq + 1; //Añadimos 1 para poder contar la raiz
    } else {
        return alturaDer + 1;
    }
}

int numNodos(Arbol raiz) {
    
    if (raiz == NULL) {
        return 0;
    }
    
    return 1 + numNodos(raiz->izq) + numNodos(raiz->der);
}

Arbol anula(Arbol raiz) {
    
    if (raiz == NULL) {
        return NULL;
    }
    anula(raiz->izq);
    anula(raiz->der);
    free(raiz);
    return NULL;
    
}

int sustituye(Arbol raiz, tipoInfo x, tipoInfo y) {
    if (raiz == NULL) {
            return 0;
    } else {
        int contador = 0;
        if (raiz->info == x) {
            raiz->info = y;
            contador = 1;
        }
        contador += sustituye(raiz->izq, x, y);
        contador += sustituye(raiz->der, x, y);
        return contador;
    }
}

int numNodosHoja(Arbol raiz) {
    
    if (raiz == NULL) {
        return 0;
    }
    if ((raiz->izq == NULL) && (raiz->der == NULL)) { //Si ambos hijos son nulos es nodo Hoja
        return 1;
    }
    return numNodosHoja(raiz->izq) + numNodosHoja(raiz->der) + 0;

}

int numNodosInternos(Arbol raiz) {
    
    if (raiz == NULL || (raiz->izq == NULL && raiz->der == NULL)) {
        return 0;
    }
    
    return 1 + numNodosInternos(raiz->izq) + numNodosInternos(raiz->der);

} //La raiz se cuenta como nodoInterno

int numHijoUnico(Arbol raiz) {
    
    if (raiz == NULL || (raiz->izq == NULL && raiz->der == NULL)) {
        return 0;
    }
    
    if (raiz->izq != NULL && raiz->der != NULL) {
        return numHijoUnico(raiz->izq) + numHijoUnico(raiz->der);
    } else {
        if (raiz->izq != NULL) {
            return 1 + numHijoUnico(raiz->izq);
        }
        else {
            return 1 + numHijoUnico(raiz->der);
        }
    }
}

Arbol buscarMax(Arbol raiz) { 
    
    Arbol nodoMax = raiz;
    Arbol temp;

    if (raiz == NULL)
        return NULL;

    if (raiz->izq != NULL) {
        temp = buscarMax(raiz->izq);
        if (temp->info > nodoMax->info)
            nodoMax = temp;
    }

    if (raiz->der != NULL) {
        temp = buscarMax(raiz->der);
        if (temp->info > nodoMax->info)
            nodoMax = temp;
    }

    return nodoMax;
}

Arbol buscarMin(Arbol raiz) { 
    
    Arbol nodoMin = raiz;
    Arbol temp;

    if (raiz == NULL)
        return NULL;

    if (raiz->izq != NULL) {
        temp = buscarMin(raiz->izq);
        if (temp->info < nodoMin->info)
            nodoMin = temp;
    }

    if (raiz->der != NULL) {
        temp = buscarMin(raiz->der);
        if (temp->info < nodoMin->info)
            nodoMin = temp;
    }

    return nodoMin;
}


int similares(Arbol r1, Arbol r2) {
    
    if (r1 == NULL && r2 == NULL) {
        return 1; //Devuelve verdadero si son similares
    }
    if (r1 == NULL || r2 == NULL) {
        return 0; //Devuelve falso, si no son similares
    }
    
    return similares(r1->izq, r2->izq) && similares(r1->der, r2->der);
}

int equivalentes(Arbol r1, Arbol r2) {
    
    if (r1 == NULL && r2 == NULL) {
        return 1; //Devuelve verdadero si son equivalentes
    }
    if (r1 == NULL || r2 == NULL) {
        return 0; //Devuelve falso si no son similares
    }
    if (r1->info != r2->info) {
        return 0; //Devuelve falso si la informacion no es igual en cada uno de ellos
    }
    return equivalentes(r1->izq, r2->izq) && equivalentes(r1->der, r2->der);
}

Arbol especular(Arbol raiz) {
    
    if (raiz == NULL) {
        return NULL;
    }

    Arbol nuevo = creaNodo(raiz->info);
    nuevo->izq = especular(raiz->der);
    nuevo->der = especular(raiz->izq);

    return nuevo;
}

//
// Ejercicio 4: Reconstruir Arbol a traves, de sus recorridos Preorden y enOrden
//

Arbol reconstruirArbol(char *PreOrden, char *EnOrden, int inicioPre, int finPre, int inicioEn, int finEn) {

    if (inicioPre > finPre) { // Caso base: subárbol vacío
        return NULL;
    }

    // Creamos un nuevo nodo con el primer elemento del recorrido en PreOrden
    tipoInfo valorRaiz = PreOrden[inicioPre];
    Arbol raiz = creaNodo(valorRaiz);

    // Buscamos la posición de la raíz en el recorrido en EnOrden
    int posRaizEn = inicioEn;
    while (EnOrden[posRaizEn] != valorRaiz) {
        posRaizEn++;
    }

    // Recursivamente construimos los subárboles izquierdo y derecho
    int numNodosIzq = posRaizEn - inicioEn;
    raiz->izq = reconstruirArbol(PreOrden, EnOrden, inicioPre + 1, inicioPre + numNodosIzq, inicioEn, posRaizEn - 1);
    raiz->der = reconstruirArbol(PreOrden, EnOrden, inicioPre + numNodosIzq + 1, finPre, posRaizEn + 1, finEn);

    return raiz;
}
