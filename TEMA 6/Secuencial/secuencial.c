/*
 * secuencial.c
 *
 *  Created on: 21/04/2014
 *      Author: MJ Polo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "secuencial.h"

int leeSecuencial(char *fichero) {
    
    FILE *fSecuencial;
    tipoAlumno reg;
    int nRegistros = 0;

    fSecuencial = fopen(fichero, "rb");
    if (fSecuencial == NULL) {
        return -1;
    }


    while (fread(&reg, sizeof(tipoAlumno), 1, fSecuencial) == 1) {
        nRegistros++;
        printf("%3d%12s%15s%15s%15s%15s\n",
                nRegistros, reg.dni, reg.nombre, reg.ape1, reg.ape2, reg.provincia);
    }

    fclose(fSecuencial);
    return nRegistros;
}


int buscaReg(FILE *fSecuencial, tipoAlumno *reg, char *dni) {
    
    tipoAlumno alumno;
    int nrr = 0;

    while (fread(&alumno, sizeof(tipoAlumno), 1, fSecuencial) == 1) {
        nrr++;
        if (!strcmp(alumno.dni, dni)) { // Si se encuentra el registro buscado
            *reg = alumno;              // Se copia el registro completo al parámetro reg
            return nrr;                 // Se devuelve el NRR en el fichero
        }
    }

    return -1; // Si no se encuentra el registro buscado se devuelve -1
}

int insertaReg(char *fSecuencial, tipoAlumno *reg) {
    
    FILE *f;
    int nrr = 0;

    f = fopen(fSecuencial, "ab");
    if (f == NULL) {
        printf("No se pudo abrir el fichero %s\n", fSecuencial);
        return -1;
    }
    
    if (fwrite(reg, sizeof(tipoAlumno), 1, f) != 1) {
        printf("Error al escribir en el fichero %s\n", fSecuencial);
        fclose(f);
        return -1;
    }

    if ((nrr = ftell(f) / sizeof(tipoAlumno)) < 0) {
        printf("Error al obtener la posición relativa en el fichero %s\n", fSecuencial);
        fclose(f);
        return -1;
    }

    fclose(f);
    return nrr;
    
}



