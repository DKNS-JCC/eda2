#ifndef MONTICULOKRUSTAL_H
#define MONTICULOKRUSTAL_H

#define MAXIMO 100

typedef int tipoClave;
typedef struct {
    tipoClave u;
    tipoClave v;
} tipoInfoKrustal;

typedef struct{
    tipoClave clave;
    tipoInfoKrustal  informacion;
} tipoElementoMonticuloKrustal;

typedef struct {
    tipoElementoMonticuloKrustal elemento[MAXIMO];
    int tamanno;
} MonticuloKrustal;


/* Ejercicio 1 */

void iniciaMonticuloKrustal(MonticuloKrustal *m);
int vacioMonticuloKrustal(MonticuloKrustal m);
int insertarKrustal(tipoElementoMonticuloKrustal x, MonticuloKrustal *m);
int eliminarMinimoKrustal(MonticuloKrustal *m, tipoElementoMonticuloKrustal *minimo);
void decrementarClaveKrustal(int pos, tipoClave cantidad, MonticuloKrustal *m);
void incrementarClaveKrustal(int pos, tipoClave cantidad, MonticuloKrustal *m);
int esMonticuloKrustal(MonticuloKrustal m);

/* Funciones auxiliares que conviene implementar: las dos estrategias de filtrado en las 
   que se basan todos los algoritmos que manejan montículos */

void filtradoDescendenteKrustal(MonticuloKrustal *m, int i);
void filtradoAscendenteKrustal(MonticuloKrustal *m, int i);

/* Operación crearMonticulo la utilizaremos en ejercicio 2 y en tema de grafos */ 

void crearMonticuloKrustal(MonticuloKrustal *m);

/* Ejercicio 2 */

void heapSortKrustal(MonticuloKrustal *m);

#endif


