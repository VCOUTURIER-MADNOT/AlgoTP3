#include "tableHachage.h"
#include "outilsTableHachage.h"
#include "liste.h"
#include "outilsListe.h"
#include <stdio.h>
#include <stdlib.h>

int lectureFichierTableHachage(HashTable ** _hashTable, const char * _fileName)
{
	int i = 1, totalCount = 0;
	FILE * file = NULL;
	char * word = (char *)malloc(sizeof(char) * 26);
	Cell * cell = NULL;
	(*_hashTable) = creerTableHachage(15);
	if( (file = fopen(_fileName, "r")) == NULL)
		return 0;

	while(i)
	{
		i = (fscanf(file, "%s", word) != EOF);
		if (i != 0)
		{
			totalCount++;	
		}
		cell = rechercherHachage((*_hashTable), word);
		if (cell == NULL){
			cell = creerCellule(word, 26);
			insererHachage((*_hashTable), cell);
		}
	}
	fclose(file);
	return totalCount;
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

void afficherTableHachage(HashTable* _hashTable)
{
	int i,j;
	Cell* c = NULL;
	printf("Affichage de la table de hachage :\n");

	for(i = 0; i < _hashTable->size; i++)
	{
		printf("Indice %d de la table :\n", i);
		if(_hashTable->array[i] != NULL)
		{
			j = 0;
			c = _hashTable->array[i]->cell;
			while(c != NULL){
				printf("\tElement %d : %s \n", j++, c->word);
				c=c->next;
			}
			printf("\n");
		}
		else
		{
			printf("\tIl n'y a pas d'élément à cet indice.\n");
		}
	}
}