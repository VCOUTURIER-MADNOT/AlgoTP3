#ifndef DEF_CELLULE
#define DEF_CELLULE

	typedef struct Cell1
	{
		struct Cell1 * previous;
		struct Cell1 * next;
		char * word;
	} Cell;

	Cell * creerCellule(const char * _word, int _wordSize);
	void detruireCellule(Cell ** _cell);

#endif