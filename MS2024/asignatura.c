/*  IZAN JIMENEZ CHAVES 
	71049459K
	GRUPO PA3
						*/

#include "asignatura.h"
#include <stdio.h>
#include <stdlib.h>
#include "dispersion.h"

int funcionHash(tAsignatura *reg,int nCubos) {
    if (nCubos == 0) return -1;

    int valor = reg->codigo;
    return valor % nCubos;
}

void mostrarReg(tAsignatura *reg)  {
    printf("%d | ", reg->codigo);
    printf("%s  ", reg->nombre);
    printf("%c  ", reg->curso);
    printf("%f | ", reg->creditosT);
    printf("%f  ", reg->creditosP);
    printf("%c  ", reg->tipo);
    printf("%c  ", reg->cuatrimestre);
    printf("%d  ", reg->numGrT);
    printf("/ %d\n", reg->numGrP);
}

int cmpClave(tAsignatura *reg1, tAsignatura *reg2) {
    if (reg1->codigo == reg2->codigo) return 0;
    else return 1;
}

int buscar(char *fichero, int codigo) {
    tPosicion posicion;
    tAsignatura reg;
    
    int resultado;
    
    FILE *fHash = fopen(fichero, "rb");
    if (fHash == NULL) {
        return -1;
    }
    
    reg.codigo = codigo;
    resultado = busquedaHash(fHash, &reg, &posicion);
    if (resultado == -1) {
        printf("La asignatura con código %d no fue encontrada.\n", codigo);
    } else {
        printf("La asignatura con código %d fue encontrada en el cubo %d (%d).\n", codigo, posicion.cubo, posicion.cuboDes);
        mostrarReg(&reg);
    }
    fclose(fHash);
    return resultado;
}

int modificar(char *fichero, int codigo,float creditosT, float creditosP){
    tPosicion posicion;
    tAsignatura reg;
    int valor;

    FILE *fHash = fopen(fichero, "rb+");
    if (fHash == NULL) {
        fprintf(stderr, "Error al abrir el fichero de hash.\n");
        return -1;
    }

    reg.codigo = codigo;
    valor = busquedaHash(fHash, &reg, &posicion);
    if (valor == -1) {
        return -1;
    }
    else {
        reg.creditosT = creditosT;
        reg.creditosP = creditosP;
        valor = modificarReg(fHash, &reg, &posicion);  
    }
    
    
    fclose(fHash);
    return 0;
}