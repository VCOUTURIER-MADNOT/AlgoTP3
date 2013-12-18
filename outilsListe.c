#include "liste.h"
#include "outilsListe.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void afficherListe(List * _list)
{	
	int i = 0;
	printf("Affichage de la liste : \n");
	if(_list->cell != NULL){
		Cell* c = _list->cell;
		while(c != NULL){
			printf("Element %d : %s \n", i++, c->word);
			c=c->next;
		}
		printf("\n");
	}
	else
		printf("Erreur: rien a afficher!\n");
}

int lectureFichier(List ** _list, const char * _fileName)
{
	int i = 1, totalCount = 0;
	FILE * file = NULL;
	char * word = (char *)malloc(sizeof(char) * 26);
	Cell * cell = NULL;

	(*_list) = creerListe();
	if( (file = fopen(_fileName, "r")) == NULL)
		return 0;

	while(i)
	{
		i = (fscanf(file, "%s", word) != EOF);
		if(i != 0)
		{
			totalCount++;
		}

		cell = rechercher((*_list), word);
		if (cell == NULL){
			cell = creerCellule(word, 26);
			inserer((*_list), cell);
		}
	}
	fclose(file);
	return totalCount;
}

int compterListe(List * _list)
{
	Cell * cell = NULL;
	int count = 0;

	if((cell = _list->cell) == NULL)
	{
		return 0;
	}
	else
	{
		count++;
	}

	while((cell = cell->next) != NULL)
	{
		count++;
	}

	return count;
	
}
