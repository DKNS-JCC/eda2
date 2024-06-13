#include <stdio.h>
#include "monticulo.h"



void iniciaMonticulo(Monticulo *m) {
	
	m->tamanno=0; 

}



int vacioMonticulo(Monticulo m) {

	if(m.tamanno==1) return 1; 
	return 0;

} // Fin vaciaMonticulo()




int insertar(tipoElemento x, Monticulo *m) {
	
	int i;

	if(m->tamanno == MAXIMO) {
		fprintf(stderr, "Montículo lleno!\n");
		return -1;
	}

	m->tamanno=m->tamanno+1;
	i=m->tamanno;
	
	while(m->elemento[i/2].clave > x.clave) {
		m->elemento[i].clave=m->elemento[i/2].clave;
		m->elemento[i].informacion=m->elemento[i/2].informacion;
		i=i/2;
	}

	m->elemento[i].clave=x.clave;
	m->elemento[i].informacion=x.informacion;

	return 0;

}



int eliminarMinimo(Monticulo *m, tipoElemento *minimo) {
	
	tipoElemento ultimo;
	int i, hijo, fin_filtrado;
	
	if(vacioMonticulo(*m)) {
		fprintf(stderr, "Montículo vacío!\n");
		return -1; 
	}

	minimo->clave=m->elemento[1].clave;
	minimo->informacion=m->elemento[1].informacion;
	ultimo.clave=m->elemento[m->tamanno].clave;
	ultimo.informacion=m->elemento[m->tamanno].informacion;
	m->tamanno=m->tamanno-1;
	i=1;
	fin_filtrado=0;
	
	while(2*i<=m->tamanno && !fin_filtrado) {
		hijo=2*i;
		if(hijo != m->tamanno)
			if(m->elemento[hijo+1].clave < m->elemento[hijo].clave) hijo++;
		if(ultimo.clave > m->elemento[hijo].clave) {
			m->elemento[i].clave=m->elemento[hijo].clave;
			m->elemento[i].informacion=m->elemento[hijo].informacion;
			i=hijo;
		}
		else fin_filtrado=1;
	}

	m->elemento[i].clave=ultimo.clave;
	m->elemento[i].informacion=ultimo.informacion;

	return 0;

}


void imprimeMonticulo(Monticulo m){

	int i;	
	for(i=1; i<=m.tamanno; i++) printf("%d ", m.elemento[i].clave);
 	printf("\n");

}

//Versión: utilizando el propio motículo para hacer la ordenación
void heapSort(Monticulo *m) {
	int i,j;
	int n;
	//Necesitamos dos contadores i y j. Con i recorres el montículo en una dirección y con j en la dirección opuesta
	tipoElemento min;

	n=m->tamanno; //Guardamos el tamaño inicial del montículo. Lo necesitaremos al final
	j=n;	//Iniciamos j a n ya que queremos recorrer desde el final
	for(i=1; i<=n; i++) { 
		if(!vacioMonticulo(*m)){ //Sólo eliminamos mínimo si el montículo NO está vacío
			eliminarMinimo(m, &min); //Eliminamos el mínimo
			m->elemento[j].clave=min.clave; //Insertamos el mínimo en la posición indicada por j 
			j--; //Decrementamos j para que el elemento mínimo eliminado en la siguiente iteración pase a la posición consecutiva
		}
	} // Fin for(i)
 
	m->tamanno=n;
} // Fin heapSort()

//Versión 1; Utilizando inserta y eliminarMin
void heapSort1(int *vector, int N){
	Monticulo m;
	tipoElemento x;
	int i;
	iniciaMonticulo(&m);
	for(i=0;i<N;i++){
		x.clave=vector[i];
		insertar(x,&m);
	}
	i=0;
	while(!vacioMonticulo(m)){
		eliminarMinimo(&m,&x);
		vector[i]=x.clave;
		i++;	
	}
	
}

//Versión 2: Utilizando crea montículo y eliminar mínimo
void heapsort2(int *vector,int N){
	Monticulo m;
	tipoElemento x;
	int i;
	iniciaMonticulo(&m);
	for(i=0;i<N;i++)
		m.elemento[i+1].clave=vector[i];
	m.tamanno=N;
	//creaMonticulo(&m);
	i=0;
	while(!vacioMonticulo(m)){
		eliminarMinimo(&m,&x);
		vector[i]=x.clave;
		i++;
	}
}

//Versión 3: Utilizando filtrado descendente y eliminar mínimo
void heapsort3(int *vector,int N){

	Monticulo m;
	tipoElemento x;
	int i;
	iniciaMonticulo(&m);
	for(i=0;i<N;i++)
		m.elemento[i+1].clave=vector[i];
	m.tamanno=N;
	for(i=m.tamanno/2;i>0;i--)
		//filtradoDescedente(&m,i);
	i=0;
	while(!vacioMonticulo(m)){
		eliminarMinimo(&m,&x);
		vector[i]=x.clave;
		i++;
	}
}
