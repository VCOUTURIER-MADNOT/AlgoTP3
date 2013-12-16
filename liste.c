#include "liste.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outilsListe.h"

List * creerListe()
{
	List * list = NULL;
	list = (List *)malloc(sizeof(List));

	list->cell = NULL;

	return list;
}

void detruireListe(List ** _list)
{

	if ((*_list)->cell ==  NULL)
		return;

	detruireCellule(&(*_list)->cell);
	free(*_list);
}

void inserer(List * _list, Cell * _cell)
{
	_cell->next = _list->cell;
	if (_list->cell != NULL)
	{
		Cell * cell = _list->cell;
		cell->previous = _cell;
	}
	_list->cell = _cell;
	_cell->previous = NULL;
}

Cell * rechercher(List * _list, char * _word)
{
	Cell * cell = NULL;
	cell = _list->cell;
	while(cell != NULL && strcmp(cell->word, _word))
	{
		cell = cell->next;
	}
	
	return cell;
}

void supprimer(List * _list, Cell * _cell)
{
	if(_cell != NULL){
		if(_cell->previous != NULL)
		{
			Cell * previous = _cell->previous;
			previous->next = _cell->next;
		}
		else
		{
			_list->cell = _cell->next;
		}

		if(_cell->next != NULL)
		{

			Cell * next = _cell->next;
			next->previous = _cell->previous;
		}
		detruireCellule(&_cell);
	}
}
