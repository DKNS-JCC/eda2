#
#
# Regla de dependencias
#

OBJS = sintaxisPila.o  pila.o
CC = gcc
OPS = -O -c -g

pilaSintaxis : $(OBJS)
	$(CC) $(OBJS) -o pilaSintaxis

#
# Reglas de construcci¢n
sintaxisPila.o : sintaxisPila.c pila.h
	$(CC) $(OPS) sintaxisPila.c

pila.o : pila.c pila.h 
	$(CC) $(OPS) pila.c


clean:
	rm *.o 


