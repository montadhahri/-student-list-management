#ifndef LISTE_H_INCLUDED
#define LISTE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef struct Element Element;
struct Element
{
    fpos_t pos;
    Element *suivant;
};

typedef struct Pile Pile;
struct Pile
{
    Element *premier;
};
int Vide(Pile *pile);
void empiler(Pile *pile );
int depiler(Pile *pile);
int depiltout(Pile *pile);


#endif // LISTE_H_INCLUDED
