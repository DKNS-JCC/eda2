/*  IZAN JIMENEZ CHAVES 
	71049459K
	GRUPO PA3
						*/

#include "alumno.h"
#include <stdio.h>
#include "dispersion.h"

int funcionHash(tAlumno *reg,int nCubos) {
    if (nCubos == 0) return -1;

    int valor = atoi(reg->dni);
    return valor % nCubos;
}

void mostrarReg(tAlumno *reg) {
    printf("%s | ", reg->dni);
    printf("%s  ", reg->nombre);
    printf("%s  ", reg->ape1);
    printf("%s | ", reg->ape2);
    printf("%s\n", reg->provincia);
}

int cmpClave(tAlumno *reg1, tAlumno *reg2) {
    return strcmp(reg1->dni, reg2->dni);
}

int buscar(char *fichero, char *dni) {
    tPosicion posicion;
    tAlumno reg;
    
    int resultado;
    
    FILE *fHash = fopen(fichero, "rb");
    if (fHash == NULL) {
        return -1;
    }
    
    strcpy(reg.dni, dni);
    resultado = busquedaHash(fHash, &reg, &posicion);
    if (resultado == -1) {
        printf("El alumno con DNI %s no fue encontrado.\n", dni);
    } else {
        printf("El alumno con DNI %s fue encontrado en el cubo %d (%d).\n", dni, posicion.cubo, posicion.cuboDes);
        mostrarReg(&reg);
    }
    fclose(fHash);
    return resultado;
}

int modificar(char *fichero, char *dni,char *provincia) {
    tPosicion posicion;
    tAlumno reg;
    int valor;

    FILE *fHash = fopen(fichero, "rb+");
    if (fHash == NULL) {
        fprintf(stderr, "Error al abrir el fichero de hash.\n");
        return -1;
    }

    strcpy(reg.dni, dni);
    valor = busquedaHash(fHash, &reg, &posicion);
    if (valor == -1) {
        return -1;
    }
    else {
        strcpy(reg.provincia, provincia);
        valor = modificarReg(fHash, &reg, &posicion);  
    }
    
    
    fclose(fHash);
    return 0;
}