#include <stdlib.h>
#include <stdio.h>
#include "monticuloKrustal.h"


void iniciaMonticuloKrustal(MonticuloKrustal *m) {
    m->tamanno = 0; // asigna 0 al tamaño del montículo
}

int vacioMonticuloKrustal(MonticuloKrustal m) {
    return((m.tamanno == 0) ? 1 : 0); // devuelve verdadero si el tamaño del montículo es cero
}

int insertarKrustal(tipoElementoMonticuloKrustal x, MonticuloKrustal *m) {
    
    if(m->tamanno >= MAXIMO) {
        return -1;
    } else {
        m->tamanno++;
        m->elemento[m->tamanno] = x;
        filtradoAscendenteKrustal(m, m->tamanno);
        return 0;
    }
}

int eliminarMinimoKrustal(MonticuloKrustal *m, tipoElementoMonticuloKrustal *minimo) {
    
    if (vacioMonticuloKrustal(*m)) {
        // Si el montículo está vacío, no se puede eliminar el mínimo
        return -1;
    }
        
    // Almacenamos el mínimo antes de eliminarlo
    *minimo = m->elemento[1];
        
    // Movemos el último elemento del montículo a la raíz
    m->elemento[1] = m->elemento[m->tamanno];
    m->tamanno--;
        
    // Aplicamos el filtrado descendente desde la raíz para mantener la propiedad de montículo
    filtradoDescendenteKrustal(m, 1);
        
    return 0;
}

void decrementarClaveKrustal(int pos, tipoClave cantidad, MonticuloKrustal *m) {
    
    if (pos <= 0 || pos > m->tamanno)
        return;
        
    m->elemento[pos].clave -= cantidad;
    filtradoAscendenteKrustal(m, pos);
}

void incrementarClaveKrustal(int pos, tipoClave cantidad, MonticuloKrustal *m) {
    
    if (pos <= 0 || pos > m->tamanno)
        return;
    
    m->elemento[pos].clave += cantidad;
    filtradoDescendenteKrustal(m, pos);
}

int esMonticuloKrustal(MonticuloKrustal m) {
    
    int i;

    for(i=m.tamanno; i>1; i--){

        if(m.elemento[i/2].clave > m.elemento[i].clave){
            return 1;
        }

    }

    return 0;
}

/* Otra implementacion:
 
 int esMonticulo(MonticuloKrustal m){
     
    int i;

    for(i = m.tamanno; i > 1; i--){
        if(m.elemento[i/2].clave > m.elemento[i].clave)
            return 0;
    }

    return 1;
}
 
 */

void filtradoDescendenteKrustal(MonticuloKrustal *m, int i) {
    
    tipoElementoMonticuloKrustal aux = m->elemento[i];
    int hijo;
    int finFiltrado = 0; // Inicializamos el flag a falso
    while (2 * i <= m->tamanno && !finFiltrado) { // Mientras no se llegue al final del montículo y el flag sea falso
        hijo = 2 * i;
        if (hijo < m->tamanno && m->elemento[hijo + 1].clave < m->elemento[hijo].clave) {
            hijo++;
        }
        if (m->elemento[hijo].clave < aux.clave) {
            m->elemento[i] = m->elemento[hijo];
            i = hijo;
        } else {
            finFiltrado = 1; // Si ya está en su posición final, activamos el flag
        }
    }
    m->elemento[i] = aux;
}

void filtradoAscendenteKrustal(MonticuloKrustal *m, int i) {
    
    int padre = i/2;
    tipoElementoMonticuloKrustal aux = m->elemento[i];
    
    while (i > 1 && m->elemento[padre].clave > aux.clave) {
        m->elemento[i] = m->elemento[padre];
        i = padre;
        padre = i/2;
    }
    m->elemento[i] = aux;
}

void crearMonticuloKrustal(MonticuloKrustal *m) {
    
    int i;
    
    for (i = m->tamanno / 2; i >= 1; i--) {
        filtradoDescendenteKrustal(m, i);
    }
    
}

void heapSortKrustal(MonticuloKrustal *m){
    
    int n, i;
    tipoElementoMonticuloKrustal maximo;
    n = m->tamanno;
    
    crearMonticuloKrustal(m);
    
    //Extraemos sucesivamente el maximo del monticulo
    for(i = 1; i <= n; i++){
        if(eliminarMinimoKrustal(m, &maximo)) {
            printf("[ERROR]: eliminarMinimo");
        }
        m->elemento[m->tamanno + 1] = maximo;
    }
    
    m->tamanno = n;
}
