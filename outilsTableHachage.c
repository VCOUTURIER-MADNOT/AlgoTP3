#include "tableHachage.h"
#include "outilsTableHachage.h"
#include "liste.h"
#include "outilsListe.h"
#include <stdio.h>
#include <stdlib.h>

int lectureFichierTableHachage(HashTable ** _hashTable, const char * _fileName)
{
	int i = 1;
	FILE * file = NULL;
	char * word = (char *)malloc(sizeof(char) * 50);
	Cell * cell = NULL;
	(*_hashTable) = creerTableHachage(15);
	if( (file = fopen(_fileName, "r")) == NULL)
		return 0;

	while(i)
	{
		i = (fscanf(file, "%s", word) != EOF);
		cell = rechercherHachage((*_hashTable), word);
		if (cell == NULL){
			cell = creerCellule(word, 50);
			insererHachage((*_hashTable), cell);
		}
		
	}
	fclose(file);
	return 1;
}

int compterTableHachage(HashTable * _hashTable)
{
	int i, count = 0;
	for (i = 0; i < _hashTable->size; ++i)
	{
		if(_hashTable->array[i] != NULL)
		{
			count += compterListe(_hashTable->array[i]);
		}
	}

	return count;
}