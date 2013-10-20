#ifndef DEF_CELLULE
#define DEF_CELLULE

	typedef struct
	{
		struct Cell * previous;
		struct Cell * next;
		char * word;
	} Cell;

	Cell * creerCellule(const char * _word, int _wordSize);
	void detruireCellule(Cell ** _cell);

#endif