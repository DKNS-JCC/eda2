#include <stdio.h>
#include <stdlib.h>
#include "monticulo.h"



void iniciaMonticulo(Monticulo *m) {
	
	m->tamanno=1; 

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
	
	// Aplico el filtrado ascendente.
	/*while(m->elemento[i/2].clave > x.clave) {
		m->elemento[i].clave=m->elemento[i/2].clave;
		m->elemento[i].informacion=m->elemento[i/2].informacion;
		i=i/2; //falta
	}*/
	
	i=filtradoAscendente(m,i,x);
	
	m->elemento[i].clave=x.clave;
	m->elemento[i].informacion=x.informacion;

	return 0; 

}



int eliminarMinimo(Monticulo *m, tipoElemento *minimo) {
	
	tipoElemento ultimo;
	int i;
	//int hijo;
	//int fin_filtrado;
	
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
	
	// Filtrado descendente.
	/*fin_filtrado=0; 
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
	}*///Fin filtrado descendente

	i=filtradoDescendente(m,i,&ultimo);
	
	m->elemento[i].clave=ultimo.clave;
	m->elemento[i].informacion=ultimo.informacion;

	return 0; 

}



void decrementarClave(int pos, int cantidad, Monticulo *m) {

	//int fin_filtrado, hijo;
	tipoElemento ultimo;
	int i=pos;
	m->elemento[pos].clave=m->elemento[pos].clave-cantidad; 
	
	//fin_filtrado=0; 
	ultimo.clave=m->elemento[m->tamanno].clave;
	ultimo.informacion=m->elemento[m->tamanno].informacion;

	// Aplico el filtrado descendente.
	/*while(2*pos<=m->tamanno && !fin_filtrado) { // "!fin_filtrado", es decir, mientras "fin_filtrado"=0;
		hijo=2*pos;
		if(hijo != m->tamanno)
			if(m->elemento[hijo+1].clave < m->elemento[hijo].clave) hijo++;
		if(ultimo.clave > m->elemento[hijo].clave) {
			m->elemento[pos].clave=m->elemento[hijo].clave;
			m->elemento[pos].informacion=m->elemento[hijo].informacion;
			pos=hijo;
		} // Fin if
		else fin_filtrado=1; // TRUE
	}*/ // Fin while
	filtradoDescendente(m,i,&ultimo);

} 



void incrementarClave(int pos, int cantidad, Monticulo *m) {

	tipoElemento elem;
	elem=m->elemento[pos];
	m->elemento[pos].clave=m->elemento[pos].clave+cantidad; 
	// Aplico el filtrado ascendente.
	/*while(m->elemento[pos/2].clave > m->elemento[pos].clave) {
		m->elemento[pos].clave=m->elemento[pos/2].clave;
		m->elemento[pos].informacion=m->elemento[pos/2].informacion;
	}*/ // Fin while
	filtradoAscendente(m,pos,elem);

} // Fin incrementarClave()



int esMonticulo(Monticulo m) {

	int i, flag;
	
	for(i=1; i<=MAXIMO; i++) { // En el caso de los MontIculos Binarios, la posiciOn de '0' estA desocupada.
		// Si respeta la propiedad de orden y estructura entonces es un MontIculo Binario. Si no, no lo es.
		if(m.elemento[i/2].clave < m.elemento[(2*i)].clave < m.elemento[(2*i)+1].clave)	flag=1; // TRUE
		flag=0; // FALSE		
	} // Fin for(i)

return flag;

} // Fin esMonticulo()


int filtradoDescendente(Monticulo *m, int i, tipoElemento *ultimo){
	int fin_filtrado=0;
	int hijo;
	while(2*i<=m->tamanno && !fin_filtrado) { 
		hijo=2*i;
		if(hijo != m->tamanno)
			if(m->elemento[hijo+1].clave < m->elemento[hijo].clave) hijo++;
		if(ultimo->clave > m->elemento[hijo].clave) {
			m->elemento[i].clave=m->elemento[hijo].clave;
			m->elemento[i].informacion=m->elemento[hijo].informacion;
			i=hijo;
		}
		else fin_filtrado=1; 
	}
	return i;
}

int filtradoAscendente(Monticulo *m, int i, tipoElemento x){

	while(m->elemento[i/2].clave > x.clave) {
		m->elemento[i].clave=m->elemento[i/2].clave;
		m->elemento[i].informacion=m->elemento[i/2].informacion;
		i=i/2; 
	}

	return i;
}


