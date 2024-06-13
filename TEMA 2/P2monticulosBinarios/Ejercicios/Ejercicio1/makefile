#
#
# Regla de dependencias
#

OBJS = main.o monticulo.o
CC = gcc
OPS = -O -c -g

monticulo : $(OBJS)
	$(CC) $(OBJS) -o monticulo

#
# Reglas de construcciOn
#

main.o : main.c monticulo.h
	$(CC) $(OPS) main.c

monticulo.o : monticulo.c
	$(CC) $(OPS) monticulo.c

clean:
	rm *.o
