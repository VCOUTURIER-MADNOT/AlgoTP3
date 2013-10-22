#include "tableHachage.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "liste.h"

HashTable * creerTableHachage(int _size)
{
	int i;
	HashTable * hashTable = NULL;

	hashTable = (HashTable *)malloc(sizeof(HashTable));
	hashTable->array = (List **) malloc(sizeof(List*) * _size);
	for(i = 0; i < _size; i++)
	{
		hashTable->array[i] = creerListe();
	}

	hashTable->size = _size;

	return hashTable;
}

void detruireTableHachage(HashTable ** _hashTable)
{
	int i;
	for (i = 0; i < (*_hashTable)->size; ++i)
	{
		detruireListe(&(*_hashTable)->array[i]);
	}
	free((*_hashTable)->array);
	free(_hashTable);
}

long convertirChEntier(const char * _word)
{
	int i, j, c = 0;

	j = 0;
	long res = 0;

	for(i = strlen(_word)-1; i >= 0; i--, j++)
	{
		c = (int) _word[i];
		res += c * pow(128,j);
	}

	return res;
}

int hachage(long _k, const HashTable * _hashTable)
{
	return _k % _hashTable->size;
}

void insererHachage(HashTable * _hashTable, Cell * _cell)
{
	List ** array = _hashTable->array;
	int key = hachage(convertirChEntier(_cell->word), _hashTable);
	inserer( array[key], _cell);
}

Cell * rechercherHachage(HashTable * _hashTable, char * _word)
{
	Cell * cell = NULL;
	int key = 0;

	key = hachage(convertirChEntier(_word), _hashTable);
	cell = rechercher(_hashTable->array[key], _word);
	
	return cell;
}

void supprimerHachage(HashTable * _hashTable, Cell * _cell)
{
	int key = 0;

	key = hachage(convertirChEntier(_cell->word), _hashTable);
	supprimer(_hashTable->array[key], _cell);
}