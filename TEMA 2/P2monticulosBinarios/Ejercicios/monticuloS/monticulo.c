#include <stdio.h>
#include <stdlib.h>
#include "monticulo.h"

void iniciaMonticulo(Monticulo *m){
	m->tamanno=0;
	m->elemento[1].clave=0;
	m->elemento[1].informacion=0;
}
int vacioMonticulo(Monticulo m){
	if(m.tamanno==0)
		return 1;
	return 0;
}

void imprimirMonticulo(Monticulo m){
	int i;
	printf("\nM(%d) :", m.tamanno);
	for(i=1;i<=m.tamanno;i++)
		printf("(%d)-",m.elemento[i].clave);
	printf("\n");
}

int insertar(tipoElemento x, Monticulo *m){
	int i;
	if(m->tamanno==MAXIMO){
		printf("\nMonticulo Lleno\n");
		return -1;
	}
	else{
		m->tamanno=m->tamanno+1;
		i=m->tamanno;
		/*Con funcion de Filtrado*/
		m->elemento[i]=x;
		filtradoAscendente(m,i);
		/*Sin funcion de Filtrado Ascendente
		while((m->elemento[i/2].clave>x.clave)&& i>1){
			m->elemento[i].clave=m->elemento[i/2].clave;
			m->elemento[i].informacion=m->elemento[i/2].informacion;
			i=i/2;
		}
		m->elemento[i].clave=x.clave;
		m->elemento[i].informacion=x.informacion; */
	}
	return 0;
}

int eliminarMinimo(Monticulo *m, tipoElemento *minimo){
	tipoElemento ultimo, min;
	int i, finFiltrado, hijo;
	if(vacioMonticulo(*m)){
		printf("\nMonticulo Vacio\n");
		return -1;
	}
	else{
		minimo->elemento=m->elemento[1];
		ultimo=m->elemento[m->tamanno];
		m->elemento[1]=ultimo;
		m->tamanno=m->tamanno-1;
		i=1;
		/* Con funcion Filtrado Descendente*/
		filtradoDescendente(m,i);
		/* Sin funcion Filtrado Descendente
		finFiltrado=0;
		while((2*i<=m->tamanno)&&(!(finFiltrado))){
			hijo=2*i;
			if(hijo!=m->tamanno)
				if(m->elemento[hijo+1].clave<m->elemento[hijo].clave)
					hijo++;
				if(ultimo.clave>m->elemento[hijo].clave){
					m->elemento[i]=m->elemento[hijo];
					i=hijo;
				}
				else
					finFiltrado=1;
		}
		m->elemento[i]=ultimo; */
	}
	return 0;
}

void decrementarClave(int pos, int cantidad, Monticulo *m){
	int i;
	m->elemento[pos].clave-=cantidad;
	i=m->tamanno;
	/* Con funcion de Filtrado Ascendente*/
	filtradoAscendente(m,i);
	/* Sin funcion de Filtrado Ascendente
	while(m->elemento[i/2].clave>m->elemento[pos].clave && (i>1)){
		m->elemento[i].clave=m->elemento[i/2].clave;
		m->elemento[i].informacion=m->elemento[i/2].informacion;
		i=i/2;
	} */
}

void incrementarClave(int pos, int cantidad, Monticulo *m){
	tipoElemento ultimo;
	int finFiltrado;
	int i, hijo;
	i=pos;
	m->elemento[pos].clave+=cantidad;
	/* Con funcion Filtrado Descendente*/
	filtradoDescendente(m,i);
	/* Sin funcion Filtrado Descendente
	finFiltrado=0;
	ultimo= m->elemento[pos];
	while((2*i<=m->tamanno)&&(!(finFiltrado))){
		hijo=2*i;
		if(hijo!=m->tamanno)
			if(m->elemento[hijo+1].clave<m->elemento[hijo].clave)
				hijo++;
			if(ultimo.clave>m->elemento[hijo].clave){
				m->elemento[i]=m->elemento[hijo];
				i=hijo;
			}
			else
				finFiltrado=1;
	}
	m->elemento[i]=ultimo; */
}


int esMonticulo(Monticulo m){
	int i=1;
	while(2*i<=m.tamanno){
		if((m.elemento[i].clave>m.elemento[2*i].clave) || ((m.elemento[i].clave> m.elemento[2*i+1].clave)&&(2*i+1)<=m.tamanno))
			return 0;
			i++;
	}
	return 1;
}

void filtradoAscendente(Monticulo *m, int i){
	tipoElemento x = (m->elemento[i]);
	while(m->elemento[i/2].clave>x.clave && (i>1)){
		m->elemento[i]=m->elemento[i/2];
		i=i/2;
	}
	m->elemento[i]=x;
}

void filtradoDescendente(Monticulo *m, int i){
	int hijo, finFiltrado=0;
	tipoElemento ultimo=m->elemento[i];
	while((2*i<=m->tamanno)&&(!(finFiltrado))){
		hijo=2*i;
		if(hijo!=m->tamanno)
			if(m->elemento[hijo+1].clave < m->elemento[hijo].clave)
				hijo++;
		if(ultimo.clave > m->elemento[hijo].clave)
		{
			m->elemento[i]=m->elemento[hijo];
			i=hijo;
		}
		else
			finFiltrado=1;
		}
		m->elemento[i]=ultimo;
}

void crearMonticulo(Monticulo *m){
	int i, n;
	n=m->tamanno;
	for(i=n/2;i>=1;i--)
		filtradoDescendente(m,i);
}

void heapsort(Monticulo *m){
	int i;
	Monticulo o;
	iniciaMonticulo(&o);
	for(i=1;i<=m->tamanno;i++)
		insertar(m->elemento[i],&o);
	for(i=1;i<=m->tamanno;i++)
		eliminarMinimo(&o,&m->elemento[i]);
}
