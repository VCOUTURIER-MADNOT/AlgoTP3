#ifndef DEF_TABLEHACHAGE
#define DEF_TABLEHACHAGE

#include "liste.h"

typedef struct{
	List ** array;
	int size;
} HashTable;

HashTable * creerTableHachage(int _size);
void detruireTableHachage(HashTable ** _hashTable);
unsigned long convertirChEntier(const char * _word);

int hachage(unsigned long _k, const HashTable * _hashTable);

void insererHachage(HashTable * _hashTable, Cell * _cell);
Cell * rechercherHachage(HashTable * _hashTable, char * _word);
void supprimerHachage(HashTable * _hashTable, Cell * _cell);


#endif