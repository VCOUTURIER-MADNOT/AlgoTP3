#include <stdio.h>
#include <stdlib.h>
#include "outilsSaisie.h"
#include "outilsPresentation.h"

int main()
{
	int choix;

	printf("/************************************************/ \n");
	printf("\\*\t\t\t TP3 \t\t\t*\\\n");
	printf("/************************************************/ \n");

	printf("Choisissez ce que vous souhaitez faire : \n");
	printf("\t1 - Comparer des fichiers\n");
	printf("\t2 - Implementer une liste\n");
	printf("\t3 - Implementer une table de hachage\n");
	printf("\t0 - Quitter le programme\n");

	choix = choixInt(3);
	printf("choix : %d\n", choix);
	switch(choix)
	{
		case 0:
			printf("Au revoir !\n");
			return 1;
			break;
		case 1:
			comparaisonFichier(saisieNomFichier());
			break;
		case 2:
			saisieListeUtil();
			break;
		case 3:
			saisieTableHachage();
			break;
	}
	return 1;
}