#include "secuencial.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define FICHERO "alumnos.dat"

int main() {
    
    int i, numReg;
    FILE *f;
    tipoAlumno reg;
    char dni[10];

    numReg = leeSecuencial(FICHERO);
    
    if (numReg == -1) {
        printf("[ERROR]: No se puede abrir el fichero %s", FICHERO);
    } else {
        printf("\nNumero de Registros: %d \n\n\n", numReg);
    }
    
    // Búsqueda de registros
    f = fopen(FICHERO, "rb");
    if (f == NULL) {
        printf("[ERROR]: No se puede abrir el fichero %s", FICHERO);
    }

    strcpy(dni, "7389298");         // Registro con NRR 38
    i = buscaReg(f, &reg, dni);
    if (i < 0) {
        printf("No existe alumno con dni %s\n\n", dni);
    } else {
        printf("Registro con NRR %d", i);
        printf("\t %s %s %s %s %s\n\n", reg.dni, reg.nombre, reg.ape1, reg.ape2, reg.provincia);
    }

    strcpy(dni, "123456789"); // No existe
    i = buscaReg(f, &reg, dni);
    if (i < 0) {
        printf("\nNo existe el alumno con dni %s\n\n",dni);
    } else {
        printf("Registro con NRR %d", i);
        printf("\t %s %s %s %s %s\n\n", reg.dni, reg.nombre, reg.ape1, reg.ape2, reg.provincia);
    }
    
    fclose(f);

    //Fin de Búsqueda

    
    // Inserción de registros
    tipoAlumno nuevoReg = {"21314153", "BEATRIZ", "FRESNO", "NAUMOVA", "SALAMANCA"};
    
    int nrr = insertaReg(FICHERO, &nuevoReg);
    if (nrr < 0) {
        printf("\nError al insertar el registro en el fichero %s\n\n", FICHERO);
    } else {
        printf("\nEl registro %s se ha insertado con éxito con NRR %d\n\n", nuevoReg.dni, nrr);
    }
    
    numReg = leeSecuencial(FICHERO);
    
    if (numReg == -1) {
        printf("[ERROR]: No se puede abrir el fichero %s", FICHERO);
    } else {
        printf("\nNumero de Registros: %d \n", numReg);
    }

}



