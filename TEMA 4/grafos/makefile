# Sesión Grafos

ejercicio1: ejercicio1.c grafos.h grafos.o cola.o monticulo.o pila.o conjuntos.o monticuloKrustal.o
	gcc -g ejercicio1.c grafos.o cola.o monticulo.o pila.o conjuntos.o monticuloKrustal.o -o ejercicio1
ejercicio2: ejercicio2.c grafos.h grafos.o cola.o monticulo.o pila.o conjuntos.o monticuloKrustal.o
	gcc -g ejercicio2.c grafos.o cola.o monticulo.o pila.o conjuntos.o monticuloKrustal.o -o ejercicio2
ejercicio3: ejercicio3.c grafos.h grafos.o cola.o monticulo.o pila.o conjuntos.o monticuloKrustal.o
	gcc -g ejercicio3.c grafos.o cola.o pila.o monticulo.o conjuntos.o monticuloKrustal.o -o ejercicio3
ejercicio4: ejercicio4.c grafos.h grafos.o cola.o monticulo.o pila.o conjuntos.o monticuloKrustal.o
	gcc -g ejercicio4.c grafos.o cola.o pila.o monticulo.o conjuntos.o monticuloKrustal.o -o ejercicio4



grafos.o: grafos.c grafos.h
	gcc -g -c grafos.c
cola.o: cola.c cola.h
	gcc -g -c cola.c
pila.o: pila.c pila.h
	gcc -g -c pila.c
monticulo.o: monticulo.c monticulo.h
	gcc -g -c monticulo.c
conjuntos.o: conjuntos.c conjuntos.h
	gcc -g -c conjuntos.c
monticuloKrustal.o: monticuloKrustal.c monticuloKrustal.h
	gcc -g -c monticuloKrustal.c
limpiar:
	rm *.o	


