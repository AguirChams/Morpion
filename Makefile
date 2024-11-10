CC=gcc
CFLAGS=-Wall -Wextra -O2

all: morpion

morpion: main.o morpion.o ia.o
	$(CC) $(CFLAGS) -o morpion main.o morpion.o ia.o

main.o: main.c morpion.h ia.h
	$(CC) $(CFLAGS) -c main.c

morpion.o: morpion.c morpion.h
	$(CC) $(CFLAGS) -c morpion.c

ia.o: ia.c ia.h
	$(CC) $(CFLAGS) -c ia.c

clean:
	rm -f *.o morpion
