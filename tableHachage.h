#ifndef DEF_TABLEHACHAGE
#define DEF_TABLEHACHAGE

#include "liste.h"

typedef struct{
	List * array;
	int size;
} HashTable;

HashTable * creerTableHachage(int _size);
void detruireTableHachage(HashTable ** _hashTable);
int convertirChEntier(const char * _word);

int hachage(int _k, const HashTable * _hashTable);

void insererHachage(Cell * _cell, HashTable * _hashTable);
void rechercherHachage(char * _word, HashTable * _hashTable);
void supprimerHachage(Cell * _cell, HashTable * _hashTable);


#endif