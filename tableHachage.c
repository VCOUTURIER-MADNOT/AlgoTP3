#include "tableHachage.h"
#include <string.h>

HashTable * creerTableHashage(int _size)
{
	HashTable * hashTable = NULL;

	hashTable = (HashTable *)malloc(sizeof(HashTable));
	hashTable->list = (List *) malloc(sizeof(List) * _size);

	return hashTable;
}

void detruireTableHashage(HashTable ** _hashTable)
{
	free((*_hashTable)->list);
	free(_hashTable);
}

int convertirChEntier(const char * _word)
{
	int i, j, res, c = 0;

	for(i = strlen(_word)-1; i >= 0; i--, j++)
	{
		c = (int) _word[i];
		res += c * pow(128,j);
	}

	return res;
}
