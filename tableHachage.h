#ifndef DEF_TABLEHACHAGE
#define DEF_TABLEHACHAGE

    #include "Liste.h"

    typedef struct{
        List * list;
    } HashTable;

    HashTable * creerTableHashage(int _size);
    void detruireTableHashage(HashTable ** _hashTable);
    int convertirChEntier(const char * _word);


#endif
