/*
 * grafos.c
 *
 *  Created on: 21/04/2014
 *      Author: MJ Polo
 */
#include <stdio.h>
#include <stdlib.h>
#include "cola.h"
#include "pila.h"
#include "grafos.h"
#include "monticulo.h"
#include "conjuntos.h"
#include "monticuloKrustal.h"

/**********************************************
/ Inicia correctamente directorio de vertices *
***********************************************/
void iniciar(tipoGrafo *g) {
    
    int i;
    pArco p;

    for(i = 1; i <= g->orden; i++){
        g->directorio[i].alcanzado = 0;
        g->directorio[i].gradoEntrada = 0;
        g->directorio[i].ordenTop = 0;
        g->directorio[i].distancia = INF;
        g->directorio[i].peso = INF;
        g->directorio[i].anterior = 0;
    }

    for(i = 1; i <= g->orden; i++){
        p = g->directorio[i].lista;
        while(p != NULL){
            g->directorio[p->v].gradoEntrada++;
            p = p->sig;
        }
    }
}

/******************************************************************************/
/* Recorrido en PROFUNDIDAD de un grafo. ¡CUIDADO! Depende del vertice inicial y del tipo de grafo */
/*********************************************************************************/
void profundidad(int v_inicio, tipoGrafo * grafo) {
    int w;
    pArco  p;
    printf("%d ", v_inicio);
    grafo->directorio[v_inicio].alcanzado = 1;
    p = grafo->directorio[v_inicio].lista;
    while (p != NULL) {
        w = p->v;
        if (!grafo->directorio[w].alcanzado)
            profundidad(w, grafo);
        p = p->sig;
    }
}

/************************************************************************************************/
/* Recorrido en AMPLITUD de un grafo. ¡CUIDADO! Depende del vertice inicial y del tipo de grafo */
/************************************************************************************************/
void amplitud(int v_inicio, tipoGrafo *grafo) {
    
    int w;
    pArco  p;
    Cola c;

    colaCreaVacia(&c);
    colaInserta(&c,v_inicio);
    while (!colaVacia(&c))  {
        w = colaSuprime(&c);
            if (!grafo->directorio[w].alcanzado) {
                printf("%d ", w);
                grafo->directorio[w].alcanzado = 1;
                p = grafo->directorio[w].lista;
                while (p != NULL){
                    w = p->v;
                    colaInserta(&c, w);
                    p = p->sig;
                }
            }
    }
      
}

void profundidadMejorado(int v_inicio, tipoGrafo *grafo) {
    
    int i;

    iniciar(grafo);
    
    profundidad(v_inicio, grafo);

    for(i = 1; i <= grafo->orden; i++){
        if(!grafo->directorio[i].alcanzado)
            profundidad(i, grafo);
    }
}

void amplitudMejorado(int v_inicio, tipoGrafo *grafo) {
    
    int i;

    iniciar(grafo);
    
    amplitud(v_inicio, grafo);

    for (i = 1; i <= grafo->orden; i++) {
        if (!grafo->directorio[i].alcanzado)
            amplitud(i, grafo);
    }
}

/* Ejercicio 2*/


int ordenTop1(tipoGrafo *grafo) {
    int orden = 1;
    pArco p;
    int v, w;

    iniciar(grafo);

    for (orden = 1; orden <= grafo->orden; orden++) {
        v = buscarVerticeGradoCeroNoOrdenTop(grafo);
        if (v == -1) {
            return -1;
        }
        grafo->directorio[v].ordenTop = orden;
        p = grafo->directorio[v].lista;
        while (p != NULL) {
            w = p->v;
            grafo->directorio[w].gradoEntrada--;
            p = p->sig;
        }
    }
    return 0;
}

int buscarVerticeGradoCeroNoOrdenTop(tipoGrafo *grafo) {
    int i;
    for (i = 1; i <= grafo->orden; i++) {
        if (grafo->directorio[i].gradoEntrada == 0 && grafo->directorio[i].ordenTop == 0) {
            return i;
        }
    }
    return -1;
}

int ordenTop2(tipoGrafo *grafo) {
    
    int orden;
    int v, w;
    Cola c;
    pArco p;
    
    iniciar(grafo);
    
    colaCreaVacia(&c);
    
    for (v = 1; v <= grafo->orden; v++) {
        if (grafo->directorio[v].gradoEntrada == 0) {
            colaInserta(&c, v);
        }
    }
    
    orden = 1;
    while (!colaVacia(&c)) {
        v = colaSuprime(&c);
        grafo->directorio[v].ordenTop = orden++;
        p = grafo->directorio[v].lista;
        while (p != NULL) {
            w = p->v;
            grafo->directorio[w].gradoEntrada--;
            if (grafo->directorio[w].gradoEntrada == 0) {
                colaInserta(&c, w);
            }
            p = p->sig;
        }
    }
    //si ha alcanzado el numero total de vertices devuelvo 0
    if (orden >= grafo->orden) {
        return 0;   // Grafo acíclico (sin ciclos)
    } else {
        return -1;  //Grafo cíclico
    }
}


/* Ejercicio 3: Caminos mínimos en grafos dirigidos */
/* a) NO Ponderados */

void caminos1(int vInicio, tipoGrafo *g) {
    pArco p;
    int v, w, distanciaActual;

    iniciar(g);
    g->directorio[vInicio].distancia = 0;

    for (distanciaActual = 0; distanciaActual < g->orden; distanciaActual++) {
        for (v = 1; v <= g->orden; v++) {
            if (!g->directorio[v].alcanzado && (g->directorio[v].distancia == distanciaActual)) {
                g->directorio[v].alcanzado = 1;
                p = g->directorio[v].lista;
                while (p != NULL) {
                    w = p->v;
                    if (g->directorio[w].distancia == INF) {
                        g->directorio[w].distancia = g->directorio[v].distancia + 1;
                        g->directorio[w].anterior = v;
                    }
                    p = p->sig;
                }
            }
        }
    }
}

void caminos2(int vInicio, tipoGrafo *g) {
    
    pArco p;
    int v, w;
    Cola c;
    
    iniciar(g);
    
    g->directorio[vInicio].distancia = 0;
    
    colaCreaVacia(&c);
    
    colaInserta(&c, vInicio);

    while (!colaVacia(&c)) {
        v = colaSuprime(&c);
        p = g->directorio[v].lista;
        while (p != NULL) {
            w = p->v;
            if (g->directorio[w].distancia == INF) {
                g->directorio[w].distancia = g->directorio[v].distancia + 1;
                g->directorio[w].anterior = v;
                colaInserta(&c, w);
            }
            p = p->sig;
        }
    }
}

/* b) PONDERADOS */

void dijkstra1(int vInicio, tipoGrafo *g) {
    
    pArco p;
    int v, w, distanciaActual, i;
    
    iniciar(g);
    
    g->directorio[vInicio].distancia = 0;
    
    for (i = 1; i <= g->orden; i++) {
        v = buscarVerticeDistanciaMinimaNoAlcanzado(g);
        g->directorio[v].alcanzado = 1;
        p = g->directorio[v].lista;
        while (p != NULL) {
            w = p->v;
            if (!g->directorio[w].alcanzado) {
                if (g->directorio[v].distancia + p->peso < g->directorio[w].distancia) {
                    g->directorio[w].distancia = g->directorio[v].distancia + p->peso;
                    g->directorio[w].anterior = v;
                }
            }
            p = p->sig;
        }
    }
}

int buscarVerticeDistanciaMinimaNoAlcanzado(tipoGrafo *grafo) {
    int i, v = -1;
    int distanciaActual = INF;
    for (i = 1; i <= grafo->orden; i++) {
        if (!grafo->directorio[i].alcanzado && grafo->directorio[i].distancia < distanciaActual) {
            distanciaActual = grafo->directorio[i].distancia;
            v = i;
        }
    }
    return v;
}

void dijkstra2(int vInicio, tipoGrafo *g) {
    
    int i, v, w;
    Monticulo m;
    tipoElementoMonticulo x;
    pArco p;
    
    iniciar(g);
    g->directorio[vInicio].distancia = 0;
    iniciaMonticulo(&m);
    
    x.clave = 0;
    x.informacion = vInicio;
    insertar(x, &m);
    
    while (!vacioMonticulo(m)) {
        eliminarMinimo(&m, &x);
        v = x.informacion;
        if (!g->directorio[v].alcanzado) {
            g->directorio[v].alcanzado = 1;
            p = g->directorio[v].lista;
            while (p != NULL) {
                w = p->v;
                if (!g->directorio[w].alcanzado && g->directorio[v].distancia + p->peso < g->directorio[w].distancia) {
                    g->directorio[w].distancia = g->directorio[v].distancia + p->peso;
                    g->directorio[w].anterior = v;
                    x.clave = g->directorio[w].distancia;
                    x.informacion = w;
                    insertar(x, &m);
                }
                p = p->sig;
            }
        }
    }
}

/* Interpretación de los algoritmos ¡Secuencia de vértices en caminos mínimos y distancias !!! */

int costeyTrayectoria(int vIni, int vFin, tipoGrafo *g) {
    
    Pila p;
    int v;

    if (g->directorio[vFin].distancia != INF) {
        pilaCreaVacia(&p);
        v = vFin;
        while (v != 0) {
            pilaInserta(&p, v);
            v = g->directorio[v].anterior;
        }

        while (!pilaVacia(&p)) {
            v = pilaSuprime(&p);
            printf("%d\t", v);  // se imprime el camino
        }
        return g->directorio[vFin].distancia;

    } else {
        return INF;
    }
}

void todosCaminosMin(int vIni, tipoGrafo *g) {
    
    int i;

    for(i = 1; i <= g->orden; i++){
        printf("\nv%d: ", i);
        costeyTrayectoria(vIni, i, g);
    }
    printf("\n");
}

/* Ejercicio 4: Árbol de Expansión en grafos NO dirigidos */
/* a) Prim  ¡ Algoritmo e interpretación del resultado!!! */
/*tipoGrafo *prim1(tipoGrafo *grafo) { //mirar
    int v, w;
    pArco p;
    int i, j;

    iniciar(grafo);
    grafo->directorio[1].peso = 0;

    for(i = 1; i <= grafo->orden; i++) {
        v = 0;
        for(j = 1; j <= grafo->orden; j++) {
            if(!grafo->directorio[j].alcanzado) {
                if(grafo->directorio[j].peso < grafo->directorio[v].peso) {
                    v = j;
                }
            }
        }
        grafo->directorio[v].alcanzado = 1;

        p = grafo->directorio[v].lista;
        while(p != NULL) {
            w = p->v;
            if(!grafo->directorio[w].alcanzado) {
                if(grafo->directorio[w].peso > p->peso) {
                    grafo->directorio[w].peso = p->peso;
                    grafo->directorio[w].anterior = v;
                }
            }
            p = p->sig;
        }
    }

    return grafo;
}*/



tipoGrafo *prim1(tipoGrafo *grafo) {
    int v, w, i;
    pArco p;
    iniciar(grafo);

    grafo->directorio[1].peso = 0;

    for (i = 1; i <= grafo->orden; i++) {
        v = buscarVerticeCostoMinimoNoAlcanzado(grafo);
        grafo->directorio[v].alcanzado = 1;
        p = grafo->directorio[v].lista;
        
        while (p != NULL) {
            w = p->v;
            if (!grafo->directorio[w].alcanzado) {
                if(grafo->directorio[w].peso > p->peso) {
                    grafo->directorio[w].peso = p->peso;
                    grafo->directorio[w].anterior = v;
                }
            }
            p = p->sig;
        }
    }

    return grafo;
}

int buscarVerticeCostoMinimoNoAlcanzado(tipoGrafo *g) {
    int minPeso = INF;
    int verticeMinPeso = -1;
    int i;

    for (i = 1; i <= g->orden; i++) {
        if (!g->directorio[i].alcanzado && g->directorio[i].peso < minPeso) {
            minPeso = g->directorio[i].peso;
            verticeMinPeso = i;
        }
    }

    return verticeMinPeso;
}

tipoGrafo *prim2(tipoGrafo *grafo) {
    
    int i, v, w;
    Monticulo m;
    tipoElementoMonticulo x;
    pArco p;
    
    iniciar(grafo);
    grafo->directorio[1].peso = 0;
    iniciaMonticulo(&m);
    
    x.clave = 0;
    x.informacion = 0;
    insertar(x, &m);
    
    while (!vacioMonticulo(m)) {
        eliminarMinimo(&m, &x);
        v = x.informacion;
        if (!grafo->directorio[v].alcanzado) {
            grafo->directorio[v].alcanzado = 1;
            p = grafo->directorio[v].lista;
            while (p != NULL) {
                w = p->v;
                if (!grafo->directorio[w].alcanzado) {
                    if (p->peso < grafo->directorio[w].distancia) {
                        grafo->directorio[w].distancia = p->peso;
                        grafo->directorio[w].anterior = v;
                        x.clave = p->peso;
                        x.informacion = w;
                        insertar(x, &m);
                    }
                }
                p = p->sig;
            }
        }
    }
    
    return grafo;
}

/* c) Kruskal*/

tipoGrafo* kruskal(tipoGrafo *g) {
    MonticuloKrustal A;
    int numAristasAceptadas = 0;
    particion B;
    tipoConjunto conjuntoU, conjuntoV;
    tipoElementoMonticuloKrustal x;
    
    tipoGrafo* arbolExp = calloc(1,sizeof(tipoGrafo));
    arbolExp->orden = g->orden;

    iniciar(arbolExp);

    crea(B);

    construirMonticuloDeAristas(g, &A);

    while (numAristasAceptadas < g->orden - 1) {
        eliminarMinimoKrustal(&A, &x);
        conjuntoU = buscar(x.informacion.u, B);
        conjuntoV = buscar(x.informacion.v, B);
        if (conjuntoU != conjuntoV) {
            unir(buscar(conjuntoU, B), buscar(conjuntoV, B), B);
            numAristasAceptadas++;
            aceptarArista(x, arbolExp);
        }
    }
    return arbolExp;
}

void construirMonticuloDeAristas(tipoGrafo *g, MonticuloKrustal *A) {
    int i, j;
    pArco p;
    tipoElementoMonticuloKrustal elemento;

    iniciaMonticuloKrustal(A);

    for(i = 1; i <= g->orden; i++){
        p = g->directorio[i].lista;
        while(p != NULL){
            if (p->v > i) {
                elemento.informacion.u = i;
                elemento.informacion.v = p->v;
                elemento.clave = p->peso;
                insertarKrustal(elemento, A);
            }
            p = p->sig;
        }
    }
}

void aceptarArista(tipoElementoMonticuloKrustal arista, tipoGrafo* arbolExp){
     pArco nuevoArco = malloc(sizeof(arco));
     nuevoArco->v = arista.informacion.v;
     nuevoArco->peso = arista.clave;
     nuevoArco->sig = arbolExp->directorio[arista.informacion.u].lista;
     arbolExp->directorio[arista.informacion.u].lista = nuevoArco;

     nuevoArco = malloc(sizeof(arco));
     nuevoArco->v = arista.informacion.u;
     nuevoArco->peso = arista.clave;
     nuevoArco->sig = arbolExp->directorio[arista.informacion.v].lista;
     arbolExp->directorio[arista.informacion.v].lista = nuevoArco;
 }


int conexo(tipoGrafo *g) {
    particion P;
    int i, j;
    pArco arco;
    
    // Inicializamos la partición
    crea(P);
    
    // Recorremos todas las aristas del grafo
    for (i = 0; i < g->orden; i++) {
        for (arco = g->directorio[i].lista; arco != NULL; arco = arco->sig) {
            j = arco->v;
            // Si los vértices i y j no están en la misma clase de equivalencia, se unen
            if (unir(buscar(i, P), buscar(j, P), P)) {
                // Si todos los vértices están en la misma clase de equivalencia, el grafo es conexo
                if (P[buscar(i, P)] == -(g->orden)) {
                    return 1;
                }
            }
        }
    }
    
    // Si no se ha encontrado un camino que conecte todos los vértices, el grafo no es conexo
    return 0;
}






/**********************************************************************************************/
/* Función auxiliar para ver el contenido de la estructura que representa un grafo en memoria */
/**********************************************************************************************/

void verGrafo(tipoGrafo *g) {
    
    int i;
    pArco p;

    printf("\nGrafo  (Orden %d)\n\n",g->orden);
    printf("       alc gEnt oTop dist peso ant \n");
    printf("     +----+----+----+----+----+----+\n");

   for(i = 1; i <= g->orden; i++) {
       printf("  %2d | %2d | %2d | %2d |", i, g->directorio[i].alcanzado,
                       g->directorio[i].gradoEntrada, g->directorio[i].ordenTop);
       if (g->directorio[i].distancia == INF)
           printf("  * |");
       else
           printf(" %2d |", g->directorio[i].distancia);
       
       if (g->directorio[i].peso == INF)
           printf("  * |");
       else
           printf(" %2d |", g->directorio[i].peso);
       
       printf(" %2d |", g->directorio[i].anterior);
       p = g->directorio[i].lista;
       while (p != NULL) {
           //printf(" ->%2d", p->v);	// Grafos no ponderados
           printf(" ->%2d, %2d |", p->v, p->peso); // Grafos ponderados
           p = p->sig;
       }
       printf("\n");
   }
   printf("     +----+----+----+----+----+----+\n\n");
}
