#include "liste.h"

int Vide(Pile *pile)
{
    if(pile->premier == NULL)
        return 0;
    else
        return 1;
}
void empiler(Pile *pile)
{
    Element *nouveau = malloc(sizeof(*nouveau));
    if (pile == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->suivant = pile->premier;
    pile->premier = nouveau;
}
int depiler(Pile *pile)
{
    if (pile == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *elementDepile = pile->premier;

    if (pile != NULL && pile->premier != NULL)
    {
        pile->premier = elementDepile->suivant;
        free(elementDepile);
    }

    return 1;
}
int depiltout(Pile *pile)
{
    while( Vide(pile)!=0 )
    {
        depiler(pile);
    }
    return 0;
}
