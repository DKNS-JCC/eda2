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

void iniciaMonticulo(Monticulo *m);
int vacioMonticulo(Monticulo m);
int insertar(tipoElemento x, Monticulo *m);
int eliminarMinimo(Monticulo *m, tipoElemento *minimo);
void decrementarClave(int pos, int cantidad, Monticulo *m);
void incrementarClave(int pos, int cantidad, Monticulo *m);
int esMonticulo(Monticulo m);

int filtradoDescendente(Monticulo *m, int i,tipoElemento *ultimo);
int filtradoAscendente(Monticulo *m, int i, tipoElemento x);


