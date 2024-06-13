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
		fprintf(stderr, "Mont�culo lleno!\n");
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
		fprintf(stderr, "Mont�culo vac�o!\n");
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

//Versi�n: utilizando el propio mot�culo para hacer la ordenaci�n
void heapSort(Monticulo *m) {
	int i,j;
	int n;
	//Necesitamos dos contadores i y j. Con i recorres el mont�culo en una direcci�n y con j en la direcci�n opuesta
	tipoElemento min;

	n=m->tamanno; //Guardamos el tama�o inicial del mont�culo. Lo necesitaremos al final
	j=n;	//Iniciamos j a n ya que queremos recorrer desde el final
	for(i=1; i<=n; i++) { 
		if(!vacioMonticulo(*m)){ //S�lo eliminamos m�nimo si el mont�culo NO est� vac�o
			eliminarMinimo(m, &min); //Eliminamos el m�nimo
			m->elemento[j].clave=min.clave; //Insertamos el m�nimo en la posici�n indicada por j 
			j--; //Decrementamos j para que el elemento m�nimo eliminado en la siguiente iteraci�n pase a la posici�n consecutiva
		}
	} // Fin for(i)
 
	m->tamanno=n;
} // Fin heapSort()

//Versi�n 1; Utilizando inserta y eliminarMin
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

//Versi�n 2: Utilizando crea mont�culo y eliminar m�nimo
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

//Versi�n 3: Utilizando filtrado descendente y eliminar m�nimo
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
