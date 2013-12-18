#ifndef DEF_OUTILSTABLEHACHAGE
#define DEF_OUTILSTABLEHACHAGE

int lectureFichierTableHachage(HashTable ** _hastTable, const char * _fileName);
int compterTableHachage(HashTable * _hastTable);
void afficherTableHachage(HashTable* _hastTable);

#endif