CC = gcc -Wall -O3 -ansi -pedantic

all: main clean

main: main.o cellule.o liste.o outilsListe.o tableHachage.o outilsTableHachage.o outilsSaisie.o outilsPresentation.o
	$(CC) -o main main.o cellule.o liste.o outilsListe.o tableHachage.o outilsTableHachage.o outilsSaisie.o outilsPresentation.o -lm

main.o: main.c
	$(CC) -o main.o -c main.c

cellule.o: cellule.c cellule.h
	$(CC) -o cellule.o -c cellule.c

liste.o: liste.c liste.h
	$(CC) -o liste.o -c liste.c

outilsListe.o: outilsListe.c outilsListe.h
	$(CC) -o outilsListe.o -c outilsListe.c

tableHachage.o: tableHachage.c tableHachage.h
	$(CC) -o tableHachage.o -c tableHachage.c

outilsTableHachage.o: outilsTableHachage.c outilsTableHachage.h
	$(CC) -o outilsTableHachage.o -c outilsTableHachage.c

outilsSaisie.o: outilsSaisie.c outilsSaisie.h
	$(CC) -o outilsSaisie.o -c outilsSaisie.c

outilsPresentation.o: outilsPresentation.c outilsPresentation.h
	$(CC) -o outilsPresentation.o -c outilsPresentation.c

clean:
	rm -rf *.o
			
