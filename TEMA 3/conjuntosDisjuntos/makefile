# Ejercicio 1
cMatrices:prueba.c rMatrices/conjuntos.o  
	gcc -g prueba.c -DMATRICES rMatrices/conjuntos.o -o cMatrices
rMatrices/conjuntos.o: rMatrices/conjuntos.c rMatrices/conjuntos.h
	gcc -c -g rMatrices/conjuntos.c -o rMatrices/conjuntos.o
# Ejercicio 2
cListas:prueba.c rListas/conjuntos.o 
	gcc -g prueba.c -DLISTAS rListas/conjuntos.o -o cListas
rListas/conjuntos.o: rListas/conjuntos.c rListas/conjuntos.h
	gcc -c -g rListas/conjuntos.c -o rListas/conjuntos.o
# Ejercicio 3 
cArbolesArbitrario:prueba.c rArboles/conjuntosArbitrario.o
	gcc -g prueba.c -DARBOLES rArboles/conjuntosArbitrario.o -o cArbolesArbitrario
rArboles/conjuntosArbitrario.o: rArboles/conjuntos.c rArboles/conjuntos.h
	gcc -c -g rArboles/conjuntos.c -DARBITRARIO -o rArboles/conjuntosArbitrario.o
# Ejercicio 4
cArbolesAltura:prueba.c rArboles/conjuntosAltura.o
	gcc -g prueba.c -DARBOLES rArboles/conjuntosAltura.o -o cArbolesAltura
rArboles/conjuntosAltura.o: rArboles/conjuntos.c rArboles/conjuntos.h
	gcc -c -g rArboles/conjuntos.c -DALTURA -o rArboles/conjuntosAltura.o
# Ejercicio 5
cArbolesTamanno:prueba.c rArboles/conjuntosTamanno.o
	gcc -g prueba.c -DARBOLES rArboles/conjuntosTamanno.o -o cArbolesTamanno
rArboles/conjuntosTamanno.o: rArboles/conjuntos.c rArboles/conjuntos.h
	gcc -c -g rArboles/conjuntos.c -DTAMANNO -o rArboles/conjuntosTamanno.o

limpiar:
	rm c*
