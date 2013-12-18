#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cellule.h"
#include "liste.h"
#include "outilsListe.h"
#include "tableHachage.h"
#include "outilsTableHachage.h"
#include "outilsSaisie.h"

int main()
{
	char nom[50];
	List * list = NULL;
	HashTable * hashTable = NULL;
	int count;
	list = (List*) malloc(sizeof(List));
	hashTable = (HashTable*) malloc(sizeof(HashTable));

	printf("Entrez le fichier à comparer : \n");
	scanf("%50s", nom);
	printf("Le fichier à comparer est : %s", nom);

	/*				Partie 1			*/
	printf("\nDébut de la comparaison avec une liste");
	

	if((count = lectureFichier(&list, nom)))
	{
		printf("\nIl y a %d mot(s) dans ce fichier", count);
		printf("\nIl y a %d mot(s) différents dans ce fichier \n", compterListe(list));
	}


	/*				Partie 2			*/
	printf("\nDébut de la comparaison avec une table de hachage");
	

	if((count = lectureFichierTableHachage(&hashTable, nom)))
	{
		printf("\nIl y a %d mot(s) dans ce fichier", count);
		printf("\nIl y a %d mot(s) différents dans ce fichier\n", compterTableHachage(hashTable));
	}
	
	return 0;
}