#
#
# Regla de dependencias
#

OBJS = prueba1.o arbol.o cola.o 
CC = gcc
OPS = -O -c -g

arbol : $(OBJS)
	$(CC) $(OBJS) -o arbol

#
# Reglas de construcción
#

prueba1.o : prueba1.c arbol.h cola.h 
	$(CC) $(OPS) prueba1.c

arbol.o : arbol.c arbol.h cola.h 
	$(CC) $(OPS) arbol.c

cola.o: cola.c cola.h arbol.h 
	$(CC) $(OPS) cola.c


clean:
	rm *.o 


