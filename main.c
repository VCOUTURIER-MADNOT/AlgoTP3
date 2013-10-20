#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cellule.h"
#include "liste.h"
#include "outilsListe.h"

int main()
{
	List * list = NULL;
	list = (List*) malloc(sizeof(List));
	
	if(lectureFichier(list, "histoire_quebec.txt"))
	{
		printf("\nIl y a %d mot(s) différent dans ce fichier", compterListe(list));
	}

	return 0;
}