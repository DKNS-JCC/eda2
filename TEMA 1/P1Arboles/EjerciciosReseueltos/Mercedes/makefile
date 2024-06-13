#Ejercicio3 TAD arbol algebraico

genArbol2: genArbol2.c arbol.o pila.o cola.o
	gcc -g genArbol2.c arbol.o pila.o cola.o -o genArbol2
arbol.o: arbol.h arbol.c 
	gcc -c -g arbol.c 
cola.o: cola.h cola.c 
	gcc -g -c cola.c
pila.o: pila.c pila.h arbol.h
	gcc -c pila.c
limpiar:
	rm *.o




