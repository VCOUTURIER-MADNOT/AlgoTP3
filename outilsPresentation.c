#include "outilsPresentation.h"
#include "liste.h"
#include "tableHachage.h"
#include "outilsListe.h"
#include "outilsTableHachage.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "outilsSaisie.h"

void comparaisonFichier(const char* _nomFichier)
{
	List * list = NULL;
	HashTable * hashTable = NULL;
	int count;
	double tempsListe, tempsTable;
	time_t debutListe, finListe, debutTable, finTable;

	list = (List*) malloc(sizeof(List));
	hashTable = (HashTable*) malloc(sizeof(HashTable));


	printf("\nLe fichier à comparer est : %s \n", _nomFichier);

	/*				Partie 1			*/
	printf("\nDébut de la comparaison avec une liste\n");

	debutListe = time(NULL);
	if((count = lectureFichier(&list, _nomFichier)))
	{
		printf("Il y a %d mot(s) dans ce fichier\n", count);
		printf("Il y a %d mot(s) différents dans ce fichier \n\n", compterListe(list));
	}
	finListe = time(NULL);


	/*				Partie 2			*/
	printf("Début de la comparaison avec une table de hachage\n");
	
	debutTable = time(NULL);
	if((count = lectureFichierTableHachage(&hashTable, _nomFichier)))
	{
		printf("Il y a %d mot(s) dans ce fichier\n", count);
		printf("Il y a %d mot(s) différents dans ce fichier\n\n", compterTableHachage(hashTable));
	}
	finTable = time(NULL);

	tempsListe = difftime(finListe,debutListe);
	tempsTable = difftime(finTable, debutTable);

	printf("Pour ce fichier, la liste a mis %f secondes pour le traiter.\n", tempsListe);
	printf("Pour ce fichier, la table de hachage a mis %f secondes pour le traiter.\n", tempsTable);

	detruireListe(&list);
}

int saisieListeUtil()
{
	int resultat = 1;

	int choix = 0;
	char * mot = (char*) malloc(sizeof(char) * 26);
	Cell * cell = NULL;
	List* list = creerListe();
	while(1)
	{
		printf("\nBienvenue dans l'assistant de création d'une liste de mots (un mot est composé de moins de 50 caractères! \n");
		printf("1 - Ajouter un mot \n");
		printf("2 - Rechercher un mot \n");
		printf("3 - Supprimer un mot \n");
		printf("4 - Afficher la liste \n");
		printf("0 - Quitter \n\n");

		choix = choixInt(4);
		
		switch(choix)
		{
			case 1:
				printf("\nVeuillez saisir un mot : ");
				scanf("%s", mot);
				cell = creerCellule(mot, 50);
				inserer(list, cell);
				break;
			case 2:
				printf("\nVeuillez saisir le mot à rechercher : ");
				scanf("%s", mot);
				cell = rechercher(list, mot);
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
				cell = rechercher(list, mot);
				if (cell == NULL)
				{
					printf("\n Le mot recherché n'est pas dans la liste !");
				}
				else
				{
					supprimer(list, cell);
				}
				break;
			case 4:
				afficherListe(list);
				break;
			case 0:
				return 0;
		}
	}

	return resultat;
}

int saisieTableHachage()
{
	int taille;
	int resultat = 1;
	int choix = 0;
	char * mot = (char*) malloc(sizeof(char) * 26);
	Cell* cell = NULL;
	HashTable* hashTable = NULL;
	
	printf("\nBienvenue dans l'assistant de création d'une table de hachage de mots (un mot est composé de moins de 50 caractères! \n");
	printf("De quelle taille voulez-vous que la table soit ?\n");

	taille = choixInt(10000);
	hashTable = creerTableHachage(taille);

	while(1)
	{
		printf("1 - Ajouter un mot \n");
		printf("2 - Rechercher un mot \n");
		printf("3 - Supprimer un mot \n");
		printf("4 - Afficher la table \n");
		printf("0 - Quitter \n\n");

		choix = choixInt(4);
		
		switch(choix)
		{
			case 1:
				printf("\nVeuillez saisir un mot : ");
				scanf("%s", mot);
				cell = creerCellule(mot, 50);
				insererHachage(hashTable, cell);
				break;
			case 2:
				printf("\nVeuillez saisir le mot à rechercher : ");
				scanf("%s", mot);
				cell = rechercherHachage(hashTable, mot);
				if (cell == NULL)
				{
					printf("\n Le mot recherché n'est pas dans la table !\n");
				}
				else
				{
					printf("\n Le mot est présent dans la table.\n");
				}
				break;

			case 3:
				printf("\nVeuillez saisir le mot à supprimer : ");
				scanf("%s", mot);
				cell = rechercherHachage(hashTable, mot);
				if (cell == NULL)
				{
					printf("\n Le mot recherché n'est pas dans la table !\n");
				}
				else
				{
					supprimerHachage(hashTable, cell);
				}
				break;
			case 4:
				afficherTableHachage(hashTable);
				break;
			case 0:
				return 0;
		}
	}

	return resultat;
}