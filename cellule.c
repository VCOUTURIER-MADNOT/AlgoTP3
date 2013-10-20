#include "cellule.h"
#include <stdlib.h>
#include <string.h>

Cell * creerCellule(const char * _word, int _wordSize)
{
	Cell * cell;

	cell = (Cell *) malloc(sizeof(Cell));
	cell->word = (char *)malloc(sizeof(char) * _wordSize);
	strcpy(cell->word, _word);

	return cell;
}

void detruireCellule(Cell ** _cell)
{
	free((*_cell)->word);
	free(*_cell);
}