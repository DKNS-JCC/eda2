/*  IZAN JIMENEZ CHAVES 
	71049459K
	GRUPO PA3
						*/
                  
#include "dispersion.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Lee el contenido del fichero hash organizado mediante el método de DISPERSIÓN según los criterios
// especificados en la práctica. Se leen todos los cubos completos tengan registros asignados o no. La
// salida que produce esta función permite visualizar el método de DISPERSIÓN

int leeHash(char *fichHash) { 
   FILE *f;
   tipoCubo cubo;
   regConfig regC;
   int j,nCubo=0,densidadOcupacion;
   
      if ((f = fopen(fichHash,"rb"))==NULL) return -2;

      fread(&regC,sizeof(regConfig),1,f);
      fread(&cubo,sizeof(cubo),1,f); 
      while (!feof(f)){
         for (j=0;j<C;j++) {
            if (j==0) printf("Cubo %2d (%2d reg. ASIGNADOS)",nCubo,cubo.numRegAsignados);
            else 	if ((j==1) && cubo.desbordado) printf("DESBORDADO\t\t");
            else printf("\t\t\t");
            
            if (j < cubo.numRegAsignados) 
               mostrarReg(&(cubo.reg[j]));
            else printf ("\n");
         }
         nCubo++;
         fread(&cubo,sizeof(cubo),1,f);
      }
      fclose(f);
      printf("ORGANIZACIÓN MÉTODO DISPERSIÓN:\n\t %d CUBOS y %d CUBOS DESBORDE con capacidad %d\n",
            regC.nCubos,regC.nCubosDes, C);   
      printf("\t Contiene %d registros de los cuales se han desbordado %d:\n",regC.numReg,regC.numRegDes);
         
      densidadOcupacion = 100*regC.numReg/((regC.nCubos+regC.nCubosDes)*C);
      printf("Densidad ACTUAL de ocupación: %d \n\t(MÍNIMA permitida %d  MÁXIMA permitida %d)\n",
                  densidadOcupacion,regC.densidadMin,regC.densidadMax);
   
      if (densidadOcupacion>regC.densidadMax) {
         printf("No se respeta la densidad máxima de ocupacion\n");
      }	

      if (densidadOcupacion<regC.densidadMin) {
         printf("No se respeta la densidad mínima de ocupacion\n");
      }
      
   return 0;	
}

int creaHvacio(char *fichHash, regConfig *reg) {
   FILE *fHash;
   tipoCubo cubo;
   int j;
   int numCubos = reg->nCubos + reg->nCubosDes;
   reg->numReg = 0;
   reg->numRegDes = 0;
   reg->nCuboDesAct = reg->nCubos;
   
   memset(&cubo,0,sizeof(tipoCubo));         //inicializamos el cubo a 0

   if ((fHash = fopen(fichHash,"wb+")) == NULL) return -2;
   
   for (j=0;j<=numCubos;j++) 
      fwrite(&cubo,sizeof(cubo),1,fHash);
   fclose(fHash);

   return 0;
}

//fseek para moverse por el archivo (SEEK_CUR PARA DENTRO DEL CUBO ATUAL Y SEEK_SET PARA MOVERTE DONDE TU QUIERAS, poner sizeof(regC) + cuboALQUEMEQUIEROMOVER *
                                                                                                               // SIZEOF(cubo))
//SEEK CUR SI LE POENMOS UN NEGATIVO SE MUEVE HACIA ATRAS (-sizeof(cubo) para moverse al principio del cubo)

int creaHash(char *fichEntrada, char *fichHash, regConfig *regC) {
   FILE *fEntrada, *fHash;
   tipoReg reg;                     //registro que vamos a leer
   tipoCubo cubo;                   //cubo en el que vamos a meter el registro
   int hash;                        //hash que vamos a calcular en funcion de la clave del registro
   int densidad;                   //densidad de ocupacion

   if (creaHvacio(fichHash, regC) != 0) return -5;

   fEntrada = fopen(fichEntrada, "r");
   if (fEntrada == NULL) return -1;

   fHash = fopen(fichHash, "rb+");
   if (fHash == NULL) return -2;


   while (fread(&reg, sizeof(tipoReg), 1, fEntrada) == 1) {
      hash = funcionHash(&reg, regC->nCubos);                              //generamos el hash en funcion de la clave del registro
      fseek(fHash, sizeof(regConfig) + hash * sizeof(tipoCubo), SEEK_SET); // me voy al cubo que me toca en funcion del hash
      fread(&cubo, sizeof(tipoCubo), 1, fHash);                            //leo todos los datos del cubo en el que estoy

      if (cubo.numRegAsignados < C) {  
         cubo.reg[cubo.numRegAsignados] = reg;                                   //asgino el registro que acabo de leer al cubo
         cubo.numRegAsignados++;                                              //aumento el numero de registros asignados

         fseek(fHash, -sizeof(tipoCubo), SEEK_CUR);                        //me muevo al principio del cubo
         fwrite(&cubo, sizeof(tipoCubo), 1, fHash);                           //sobrescribo el cubo

         regC->numReg++;                                                   //aumento el numero de registros totales
      } else {
         cubo.desbordado = 1;                                                 //si el cubo esta lleno, lo marco como desbordado

         fseek(fHash, -sizeof(tipoCubo), SEEK_CUR);                        //me muevo al principio del cubo
         fwrite(&cubo, sizeof(tipoCubo), 1, fHash);

         regC->numRegDes++;                                                //aumento el numero de registros desbordados
         regC->numReg++;                                                   //aumento el numero de registros totales                    
         
         if (desborde(fHash, &reg, regC) != 0) return -5;
      }
   }

   fseek(fHash, 0, SEEK_SET);
	fwrite(regC, sizeof(regConfig), 1, fHash);

   fclose(fEntrada);
   fclose(fHash);

   densidad = 100 * regC->numReg / ((regC->nCubos + regC->nCubosDes) * C);
   if (densidad > regC->densidadMax) {
      return -3;
   } else if (densidad < regC->densidadMin) {
      return -4;
   }

   return 0;
}

int desborde(FILE *fHash, tipoReg *reg, regConfig *regC) {
   tipoCubo c;

   fseek(fHash, sizeof(regConfig) + regC->nCuboDesAct * sizeof(tipoCubo), SEEK_SET);
   fread(&c, sizeof(tipoCubo), 1, fHash);

   c.reg[c.numRegAsignados] = *reg;
   c.numRegAsignados++;

   fseek(fHash, -sizeof(tipoCubo), SEEK_CUR);
   fwrite(&c, sizeof(tipoCubo), 1, fHash);

   if (c.numRegAsignados == C) {
      regC->nCuboDesAct++;

      if (regC->nCuboDesAct >= regC->nCubos + regC->nCubosDes) {
         fseek(fHash, sizeof(regConfig) + regC->nCuboDesAct * sizeof(tipoCubo), SEEK_SET);
         memset(&c, 0, sizeof(tipoCubo));
         fwrite(&c, sizeof(tipoCubo), 1, fHash);
      }

      return 0;
   } 

   return 0;
} 

//PARTE 2

int busquedaHash(FILE *fHash, tipoReg *reg, tPosicion *posicion) {
   regConfig regC;
   tipoCubo cubo;
   if (fHash == NULL) return -1;

   fread(&regC, sizeof(regConfig), 1, fHash);

   int cuboP = funcionHash(reg, regC.nCubos);

   fseek(fHash, sizeof(regConfig) + cuboP * sizeof(tipoCubo), SEEK_SET);
   fread(&cubo, sizeof(tipoCubo), 1, fHash);

   for (int i = 0; i < C; i++) {
      if (cmpClave(&cubo.reg[i], reg) == 0) {
         posicion->cubo = cuboP;
         posicion->cuboDes = -1;
         posicion->posReg = i;
         *reg = cubo.reg[i];
         return 0;
      }
   }

   if (cubo.desbordado == 1) {
      int cuboDes = regC.nCubos;
      while (1) {
         fseek(fHash, sizeof(regConfig) + cuboDes * sizeof(tipoCubo), SEEK_SET);
         fread(&cubo, sizeof(tipoCubo), 1, fHash);

         for (int i = 0; i < C; i++) {
            if (cmpClave(&cubo.reg[i], reg) == 0) {
               posicion->cubo = cuboP;
               posicion->cuboDes = cuboDes;
               posicion->posReg = i;
               *reg = cubo.reg[i];
               return 0;
            }
         }

         cuboDes++;
         if (cuboDes >= regC.nCubos + regC.nCubosDes) {
            break;
         }
      }
   }

   return 1;

}

int modificarReg(FILE *fHash, tipoReg *reg, tPosicion *posicion) {
   regConfig regC;
   tipoCubo cubo;

   if (fHash == NULL) return -1;

   if (posicion->cuboDes == -1) {
      fseek(fHash, sizeof(regConfig) + posicion->cubo * sizeof(tipoCubo), SEEK_SET);
      //fseek(fHash, posicion->posReg * sizeof(tipoCubo), SEEK_CUR);
      fread(&cubo, sizeof(tipoCubo), 1, fHash);
   }
   else {
      fseek(fHash, sizeof(regConfig) + posicion->cuboDes * sizeof(tipoCubo), SEEK_SET);
      //fseek(fHash, posicion->posReg * sizeof(tipoCubo), SEEK_CUR);
      fread(&cubo, sizeof(tipoCubo), 1, fHash);
   }

   cubo.reg[posicion->posReg] = *reg;

   fseek(fHash, -sizeof(tipoCubo), SEEK_CUR); 
   fwrite(&cubo, sizeof(tipoCubo), 1, fHash);
   

   return 0;
}