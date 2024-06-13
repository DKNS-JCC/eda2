#ifndef __ARBOL_H
#define __ARBOL_H

#define ERROR_COLA -1
#define MSG_ERROR_COLA "La pila no existe\n"
#define ERROR_MALLOC -2
#define MSG_ERROR_MALLOC "No se ha podido reservar memoria con malloc\n"


/*TIPOS ÁRBOLES*/
typedef char tipoInfo;

typedef struct tipoNodo {
        tipoInfo info;
        struct tipoNodo *izq,*der;
        } tipoNodo;

typedef tipoNodo * Arbol;


Arbol creaNodo(tipoInfo info);

/*INTERFAZ ÁRBOLES*/
void preOrden(Arbol raiz);
void enOrden(Arbol raiz);
void postOrden(Arbol raiz);
void amplitud(Arbol raiz);

int altura(Arbol raiz);
int numNodos(Arbol raiz);
int numNodosHoja(Arbol raiz);
int numNodosInternos(Arbol raiz);
int numHijoUnico(Arbol raiz);
int sustiuye(Arbol raiz, tipoInfo x, tipoInfo y);
Arbol buscarMax(Arbol raiz);
Arbol buscarMin(Arbol raiz);
Arbol anula(Arbol raiz);
int similares(Arbol r1,Arbol r2);
int equivalentes(Arbol r1,Arbol r2);
Arbol especular(Arbol raiz);

int numX(Arbol a, tipoInfo x);

#endif
