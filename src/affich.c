
#include "textedition.h"
#include "affich.h"

void afficherImage(SDL_Renderer *renderer, SDL_Texture *img, SDL_Rect *r)
{
    SDL_RenderCopy(renderer, img, NULL, r);

    SDL_RenderPresent(renderer);
}
SDL_Rect afficherTexte(SDL_Renderer *renderer, const char *texte, TTF_Font *police, int x, int y, int r, int g, int b)
{
    SDL_Surface *texteSurface = NULL;
    SDL_Texture *texteTexture = NULL;
    SDL_Rect rect;
    SDL_Color couleur;
    SDL_Color noir = {192, 192, 192, 255};

    /* couleur du texte */
    couleur.r = r;
    couleur.g = g;
    couleur.b = b;
    couleur.a = 255;

    if((texteSurface = TTF_RenderText_Shaded(police, texte, couleur, noir)) != NULL)
    {
        texteTexture = SDL_CreateTextureFromSurface(renderer, texteSurface);
        SDL_FreeSurface(texteSurface);
        texteSurface = NULL;

        rect.x = x;
        rect.y = y;

        SDL_QueryTexture(texteTexture, NULL, NULL, &rect.w, &rect.h);
        afficherImage(renderer, texteTexture, &rect);

        SDL_DestroyTexture(texteTexture);
    }
    else
        printf("Le texte %s n'a pas pu être afficher : %s\n", texte, TTF_GetError());

    return rect;
}
