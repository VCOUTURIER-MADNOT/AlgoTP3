#include "liste.h"
#include "outilsListe.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void afficherListe(List * _list)
{
	int i;
	Cell * cell = NULL;
	
	printf("**********\n");
	printf("Affichage de la liste\n");
	printf("**********\n");

	i = 0;
	cell = _list->cell;
	if(cell == NULL)
	{
		printf("La liste est vide !!!!!!!!!! \n");
	}
	while(cell != NULL)
	{
		printf("Element numéro %d : %s\n", i++, cell->word);
		cell = cell->next;
	}
}

int saisieListeUtil(List * _list)
{
	int resultat = 1;

	int choix = 0;
	char * mot = (char*) malloc(sizeof(char) * 50);
	Cell * cell = NULL;

	printf("\nBienvenue dans l'assistant de création d'une liste de mots (un mot est composé de moins de 50 caractères! \n");
	printf("1. Ajouter un mot \n");
	printf("2. Rechercher un mot \n");
	printf("3. Supprimer un mot \n");
	printf("4. Afficher la liste \n");
	printf("5. Détruire la liste (quitte le programme) \n\n");

	while (choix > 5 || choix < 1)
	{
		printf("Quel est votre choix ? ");
		scanf("%d", &choix);
	}

	switch(choix)
	{
		case 1:
			printf("\nVeuillez saisir un mot : ");
			scanf("%s", mot);
			cell = creerCellule(mot, 50);
			inserer(_list, cell);
			cell = NULL;
			mot = NULL;
			break;
		case 2:
			printf("\nVeuillez saisir le mot à rechercher : ");
			scanf("%s", mot);
			cell = rechercher(_list, mot);
			if (cell == NULL)
			{
				printf("\n Le mot recherché n'est pas dans la liste !");
			}
			else
			{
				printf("\n Le mot est présent dans la liste.");
			}
			break;

		case 3:
			printf("\nVeuillez saisir le mot à supprimer : ");
			scanf("%s", mot);
			cell = rechercher(_list, mot);
			if (cell == NULL)
			{
				printf("\n Le mot recherché n'est pas dans la liste !");
			}
			else
			{
				supprimer(_list, cell);
			}
			break;
		case 4:
			afficherListe(_list);
			break;
		case 5:
			detruireListe(&_list);
			resultat = 0;
	}

	return resultat;
}

int lectureFichier(List ** _list, const char * _fileName)
{
	int i = 1;
	FILE * file = NULL;
	char * word = (char *)malloc(sizeof(char) * 50);
	Cell * cell = NULL;

	(*_list) = creerListe();
	if( (file = fopen(_fileName, "r")) == NULL)
		return 0;

	while(i)
	{
		i = (fscanf(file, "%s", word) != EOF);
		cell = rechercher((*_list), word);
		if (cell == NULL){
			cell = creerCellule(word, 50);
			inserer((*_list), cell);
		}
	}
	fclose(file);
	return 1;
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
