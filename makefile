CC = gcc -Wall -O3 -ansi -pedantic

all: main clean

main: main.o cellule.o liste.o outilsListe.o
	$(CC) -o main main.o cellule.o liste.o outilsListe.o

main.o: main.c
	$(CC) -o main.o -c main.c

cellule.o: cellule.c cellule.h
	$(CC) -o cellule.o -c cellule.c

liste.o: liste.c liste.h
	$(CC) -o liste.o -c liste.c

outilsListe.o: outilsListe.c outilsListe.h
	$(CC) -o outilsListe.o -c outilsListe.c

tableHachage.o: tableHachage.c tableHachage.h
	$(CC) -o tableHachage.o -c tableHachage.h
clean:
	rm -rf *.o
			
