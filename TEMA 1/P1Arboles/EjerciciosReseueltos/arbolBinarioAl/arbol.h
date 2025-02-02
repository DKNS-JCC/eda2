#ifndef __ARBOL_H
#define __ARBOL_H


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

int numNodos(Arbol raiz);
int numNodosHoja(Arbol raiz);
int numNodosInternos(Arbol raiz);
int evaluar(Arbol a);
int evaluar2(Arbol a);


#endif
