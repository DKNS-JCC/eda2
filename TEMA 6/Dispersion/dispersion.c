#include "dispersion.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Crea un fichero hash inicialmente vacio según los criterios especificados en la práctica
// Primera tarea a realizar para  crear un fichero organizado mediante DISPERSIÓN

void creaHvacio(char *fichHash) {
    
    FILE *fHash;
    tipoCubo cubo;
    int j;
    int numCubos = CUBOS + CUBOSDESBORDE;

    memset(&cubo, 0, sizeof(cubo));

    fHash = fopen(fichHash, "wb");
    for (j = 0; j < numCubos; j++) {
        fwrite(&cubo, sizeof(cubo), 1, fHash);
    }
    
    fclose(fHash);
}

// Lee el contenido del fichero hash organizado mediante el método de DISPERSIÓN según los criterios
// especificados en la práctica. Se leen todos los cubos completos tengan registros asignados o no. La
// salida que produce esta función permite visualizar el método de DISPERSIÓN

int leeHash(char *fichHash) {
    
    FILE *f;
    tipoCubo cubo;
    int j, i = 0;
    size_t numLee;

    f = fopen(fichHash, "rb");
    rewind(f);
    fread(&cubo,sizeof(cubo),1,f);
    while (!feof(f)){
        for (j=0;j<C;j++) {
            if (j == 0) {
                printf("Cubo %2d (%2d reg. ASIGNADOS)",i,cubo.numRegAsignados);
            } else {
                printf("\t\t\t");
            }
            
            if (j < cubo.numRegAsignados) {
                printf("\t%s %s %s %s %s\n",
                       cubo.reg[j].dni,
                       cubo.reg[j].nombre,
                       cubo.reg[j].ape1,
                       cubo.reg[j].ape2,
                       cubo.reg[j].provincia);
            }
            else printf ("\n");
        }
        i++;
        fread(&cubo, sizeof(cubo), 1, f);
    }
    fclose(f);
    return i;
}


int creaHash(char *fichEntrada, char *fichSalida) {
    
    FILE *fEntrada, *fSalida;
    tipoAlumno reg;
    tipoCubo cubo;
    int i, cuboIdx, desbordeIdx = 0, numDesbordados = 0;
    
    // Inicializar todos los cubos en el archivo de salida
    creaHvacio(fichSalida);
    
    // Abrir el archivo de entrada y leer cada registro
    fEntrada = fopen(fichEntrada, "rb");
    if (fEntrada == NULL) {
        return -1;
    }
    
    while (fread(&reg, sizeof(reg), 1, fEntrada)) {
        // Calcular el índice del cubo para este registro
        cuboIdx = atoi(reg.dni) % CUBOS;
        
        // Leer el cubo correspondiente del archivo de salida
        fSalida = fopen(fichSalida, "r+b");
        if (fSalida == NULL) {
            return -2;
        }
        
        fseek(fSalida, cuboIdx * sizeof(tipoCubo), SEEK_SET);
        fread(&cubo, sizeof(cubo), 1, fSalida);
        
        // Si el cubo está lleno, añadir el registro al área de desborde
        if (cubo.numRegAsignados == C) {
            cuboIdx = CUBOS + (desbordeIdx / C);
            desbordeIdx = (desbordeIdx + 1) % (CUBOSDESBORDE * C);
            fseek(fSalida, cuboIdx * sizeof(tipoCubo), SEEK_SET);
            fread(&cubo, sizeof(cubo), 1, fSalida);
            numDesbordados++;
        }
        
        // Añadir el registro al cubo correspondiente y actualizar el archivo de salida
        cubo.reg[cubo.numRegAsignados] = reg;
        cubo.numRegAsignados++;
        fseek(fSalida, cuboIdx * sizeof(tipoCubo), SEEK_SET);
        fwrite(&cubo, sizeof(cubo), 1, fSalida);
        
        fclose(fSalida);
    }
    
    fclose(fEntrada);
    return numDesbordados;
}

int buscaReg(FILE *fHash, tipoAlumno *reg, char *dni) {
    tipoCubo cubo;
    int cuboIdx, desbordeIdx = 0;
    
    // Calcular el índice del cubo para este registro
    cuboIdx = atoi(dni) % CUBOS;
    
    // Leer el cubo correspondiente del archivo de salida
    fseek(fHash, cuboIdx * sizeof(tipoCubo), SEEK_SET);
    fread(&cubo, sizeof(cubo), 1, fHash);
    
    // Buscar el registro en el cubo
    for (int i = 0; i < cubo.numRegAsignados; i++) {
        if (!strcmp(cubo.reg[i].dni, dni)) {
            // El registro se encontró en el cubo
            *reg = cubo.reg[i];
            return cuboIdx;
        }
    }
    
    // Buscar el registro en el área de desborde
    while (cubo.numRegAsignados == C && desbordeIdx < CUBOSDESBORDE) {
        cuboIdx = CUBOS + desbordeIdx;
        desbordeIdx++;
        fseek(fHash, cuboIdx * sizeof(tipoCubo), SEEK_SET);
        fread(&cubo, sizeof(cubo), 1, fHash);
        
        for (int i = 0; i < cubo.numRegAsignados; i++) {
            if (!strcmp(cubo.reg[i].dni, dni)) {
                // El registro se encontró en el área de desborde
                *reg = cubo.reg[i];
                return cuboIdx;
            }
        }
    }
    
    // El registro no está en el archivo
    return -1;
}


//No va
int insertarReg(FILE *fHash, tipoAlumno *reg) {
    
    tipoCubo cubo;
    int cuboIdx, desbordeIdx = -1, numDesbordados = 0;
    
    // Calcular el índice del cubo para este registro
    cuboIdx = atoi(reg->dni) % CUBOS;
    
    // Leer el cubo correspondiente del archivo de salida
    fseek(fHash, cuboIdx * sizeof(tipoCubo), SEEK_SET);
    fread(&cubo, sizeof(cubo), 1, fHash);
    
    // Si el cubo está lleno, añadir el registro al área de desborde
    if (cubo.numRegAsignados == C) {
        // Buscar un cubo de desborde libre
        fseek(fHash, (CUBOS + desbordeIdx + 1) * sizeof(tipoCubo), SEEK_SET);
        fread(&cubo, sizeof(cubo), 1, fHash);
        while (cubo.numRegAsignados == C && desbordeIdx < CUBOSDESBORDE - 1) {
            desbordeIdx++;
            fseek(fHash, (CUBOS + desbordeIdx) * sizeof(tipoCubo), SEEK_SET);
            fread(&cubo, sizeof(cubo), 1, fHash);
        }
        // Si no hay cubos de desborde libres, devolver -1
        if (cubo.numRegAsignados == C) {
            return -1;
        }
        numDesbordados++;
    }
    
    // Añadir el registro al cubo correspondiente y actualizar el archivo de salida
    cubo.reg[cubo.numRegAsignados] = *reg;
    cubo.numRegAsignados++;
    fseek(fHash, cuboIdx * sizeof(tipoCubo), SEEK_SET);
    fwrite(&cubo, sizeof(cubo), 1, fHash);
    
    // Si se han añadido registros al área de desborde, actualizar el archivo de salida
    if (desbordeIdx >= 0) {
        fseek(fHash, (CUBOS + desbordeIdx) * sizeof(tipoCubo), SEEK_SET);
        fwrite(&cubo, sizeof(cubo), 1, fHash);
    }
    
    if (desbordeIdx >= 0) {
        return CUBOS + desbordeIdx;
    } else {
        return cuboIdx;
    }
}



