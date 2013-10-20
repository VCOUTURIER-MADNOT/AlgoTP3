#include "tableHachage.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

HashTable * creerTableHachage(int _size)
{
	HashTable * hashTable = NULL;

	hashTable = (HashTable *)malloc(sizeof(HashTable));
	hashTable->array = (List *) malloc(sizeof(List) * _size);
	hashTable->size = _size;

	return hashTable;
}

void detruireTableHachage(HashTable ** _hashTable)
{
	free((*_hashTable)->array);
	free(_hashTable);
}

int convertirChEntier(const char * _word)
{
	int i, j, res, c = 0;

	j = 0;
	res = 0;

	for(i = strlen(_word)-1; i >= 0; i--, j++)
	{
		c = (int) _word[i];
		res += c * pow(128,j);
	}

	return res;
}

int hachage(int _k, const HashTable * _hashTable)
{
	return _k % _hashTable->size;
}

void insererHachage(Cell * _cell, HashTable * _hashTable)
{
	/* TODO */
}

void rechercherHachage(char * _word, HashTable * _hashTable)
{
	/* TODO */
}

void supprimerHachage(Cell * _cell, HashTable * _hashTable)
{
	/* TODO */
}