#include <stdlib.h>
#include <stdio.h>
#include "monticulo.h"


void iniciaMonticulo(Monticulo *m) {
    m->tamanno = 0; // asigna 0 al tamaño del montículo
}

int vacioMonticulo(Monticulo m) {
    return m.tamanno == 0; // devuelve verdadero si el tamaño del montículo es cero
}

int insertar(tipoElementoMonticulo x, Monticulo *m) {
    
    if(m->tamanno >= MAXIMO) {
        return -1;
    } else {
        m->tamanno++;
        m->elemento[m->tamanno] = x;
        filtradoAscendente(m, m->tamanno);
        return 0;
    }
}

int eliminarMinimo(Monticulo *m, tipoElementoMonticulo *minimo) {
    
    if (vacioMonticulo(*m)) {
        // Si el montículo está vacío, no se puede eliminar el mínimo
        return -1;
    }
        
    // Almacenamos el mínimo antes de eliminarlo
    *minimo = m->elemento[1];
        
    // Movemos el último elemento del montículo a la raíz
    m->elemento[1] = m->elemento[m->tamanno];
    m->tamanno--;
        
    // Aplicamos el filtrado descendente desde la raíz para mantener la propiedad de montículo
    filtradoDescendente(m, 1);
        
    return 0;
}

void decrementarClave(int pos, tipoClave cantidad, Monticulo *m) {
    
    if (pos <= 0 || pos > m->tamanno)
        return;
        
    m->elemento[pos].clave -= cantidad;
    filtradoAscendente(m, pos);
}

void incrementarClave(int pos, tipoClave cantidad, Monticulo *m) {
    
    if (pos <= 0 || pos > m->tamanno)
        return;
    
    m->elemento[pos].clave += cantidad;
    filtradoDescendente(m, pos);
}

int esMonticulo(Monticulo m) {
    
    int i;
    
    for (i = 1; i <= m.tamanno / 2; i++) {
        // Comprobamos que el hijo izquierdo esté ordenado correctamente
        if (m.elemento[2 * i].clave < m.elemento[i].clave) {
            return 0;
        }
        // Comprobamos que el hijo derecho esté ordenado correctamente, si existe
        if (2 * i + 1 <= m.tamanno && m.elemento[2 * i + 1].clave < m.elemento[i].clave) {
            return 0;
        }
    }
    // Si hemos llegado hasta aquí, el montículo está ordenado
    return 1;
}

/* Otra implementacion:
 
 int esMonticulo(Monticulo m){
     
    int i;

    for(i = m.tamanno; i > 1; i--){
        if(m.elemento[i/2].clave > m.elemento[i].clave)
            return 0;
    }

    return 1;
}
 
 */

void filtradoDescendente(Monticulo *m, int i) {
    
    tipoElementoMonticulo aux = m->elemento[i];
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

void filtradoAscendente(Monticulo *m, int i) {
    
    int padre = i/2;
    tipoElementoMonticulo aux = m->elemento[i];
    
    while (i > 1 && m->elemento[padre].clave > aux.clave) {
        m->elemento[i] = m->elemento[padre];
        i = padre;
        padre = i/2;
    }
    m->elemento[i] = aux;
}

void crearMonticulo(Monticulo *m) {
    
    int i;
    
    for (i = m->tamanno / 2; i >= 1; i--) {
        filtradoDescendente(m, i);
    }
    
}

void heapSort(Monticulo *m){
    
    int n, i;
    tipoElementoMonticulo maximo;
    n = m->tamanno;
    
    crearMonticulo(m);
    
    //Extraemos sucesivamente el maximo del monticulo
    for(i = 1; i <= n; i++){
        if(eliminarMinimo(m, &maximo)) {
            printf("[ERROR]: eliminarMinimo");
        }
        m->elemento[m->tamanno + 1] = maximo;
    }
    
    m->tamanno = n;
}
