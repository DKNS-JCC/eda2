#define MAXIMO 100

typedef int tipoClave;
typedef int tipoInfo;

typedef struct { 
	tipoClave clave;
   	tipoInfo informacion;
} tipoElemento;

typedef struct { 
	tipoElemento elemento[MAXIMO];
    int tamanno;
} Monticulo;

void heapSort(Monticulo *m);
void heapSort1(int *vector, int N);
void heapSort2(int *vector, int N);
void heapSort3(int *vector, int N);
void iniciaMonticulo(Monticulo *m);
int vacioMonticulo(Monticulo m);
int eliminarMinimo(Monticulo *m, tipoElemento *minimo);
int insertar(tipoElemento x, Monticulo *m);

void imprimeMonticulo(Monticulo m);
