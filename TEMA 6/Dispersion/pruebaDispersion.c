#include "dispersion.h"
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

#define FICHERODAT "alumnos.dat"
#define FICHEROHASH "alumnos.hash"

int main() {
    
    int i, numRegDes;
    FILE *f;
    tipoAlumno reg;
    char dni[10];

    numRegDes = creaHash(FICHERODAT, FICHEROHASH);
    
    if (numRegDes == -1) {
        printf("[ERROR]: No se puede abrir el fichero %s", FICHERODAT);
    } else if (numRegDes == -2) {
        printf("[ERROR]: No se puede abrir el fichero %s", FICHEROHASH);
    } else {
        printf("\n%d Registros DESBORDADOS\n\n", numRegDes);
    }

    i = leeHash(FICHEROHASH);

    // Bœsqueda de registros
    f = fopen(FICHEROHASH, "rb");
    if (f == NULL) {
        printf("[ERROR]: No se puede abrir el fichero %s", FICHEROHASH);
        return 1;
    }

    strcpy(dni,"7389298"); // Existe en el area PRIMA
    i = buscaReg(f, &reg,dni);
    if (i < 0) {
        printf("No existe alumno con dni %s\n", dni);
    } else {
        printf("Registro encontrado en el CUBO %d", i);
        printf("\t %s %s %s %s %s\n", reg.dni, reg.nombre, reg.ape1, reg.ape2, reg.provincia);
    }
    
    strcpy(dni, "7219752"); // Existe en el area De DESBORDE
    i = buscaReg(f, &reg,dni);
    if (i < 0) {
        printf("No existe alumno con dni %s\n",dni);
    } else {
        printf("Registro encontrado en el CUBO %d",i);
        printf("\t %s %s %s %s %s\n", reg.dni, reg.nombre, reg.ape1, reg.ape2, reg.provincia);
    }
    
    strcpy(dni,"123456789"); // No existe
    i = buscaReg(f,&reg,dni);
    if (i < 0) {
        printf("\nNo existe alumno con dni %s\n",dni);
    } else {
        printf("Registro encontrado en el CUBO %d",i);
        printf("\t %s %s %s %s %s\n", reg.dni, reg.nombre, reg.ape1, reg.ape2, reg.provincia);
    }
  
    fclose(f);

    //Fin de Bœsqueda

    // Inserccion de registros en el fichero hash
    
    strcpy(reg.dni, "12345678");
    strcpy(reg.nombre, "BEATRIZ");
    strcpy(reg.ape1, "FRESNO");
    strcpy(reg.ape2, "NAUMOVA");
    strcpy(reg.provincia, "SALAMANCA");

    f = fopen(FICHEROHASH, "rb+");
    if (f == NULL) {
        printf("\n[ERROR]: No se puede abrir el fichero %s\n", FICHEROHASH);
        return 1;
    }
    
    i = insertarReg(f, &reg);
    if (i == -1) {
        printf("\nNo se pudo insertar el registro\n");
    } else {
        printf("\nRegistro insertado en el CUBO %d\n\n", i);
    }
    
    fclose(f);
    
    // Fin de inserccion
    
    i = leeHash(FICHEROHASH);
    
    return 0;
}



