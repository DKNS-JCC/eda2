#
#
# Regla de dependencias
#

OBJS = prueba1.o arbol.o
CC = gcc
OPS = -O -c -g

arbol : $(OBJS)
	$(CC) $(OBJS) -o arbol

#
# Reglas de construcción
#

prueba1.o : arbol.c arbol.h
	$(CC) $(OPS) prueba1.c

arbol.o : arbol.c arbol.h
	$(CC) $(OPS) arbol.c



clean:
	rm *.o 


