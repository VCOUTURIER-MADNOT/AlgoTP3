#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cellule.h"
#include "liste.h"
#include "outilsListe.h"
#include "tableHachage.h"

int main()
{
	/*				Partie 1			*/
	/*
	List * list = NULL;
	list = (List*) malloc(sizeof(List));
	
	if(lectureFichier(list, "dico.txt"))
	{
		printf("\nIl y a %d mot(s) différent dans ce fichier", compterListe(list));
	}
	*/

	/*				Partie 2			*/
	HashTable * hashTable = NULL;
	hashTable = (HashTable*) malloc(sizeof(HashTable));

	hashTable = creerTableHachage(15);
	printf("%d \n",hachage(42, hashTable));

	return 0;
}