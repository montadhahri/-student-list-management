#ifndef AFFICH_H_INCLUDED
#define AFFICH_H_INCLUDED


void afficherImage(SDL_Renderer *renderer, SDL_Texture *img, SDL_Rect *r);
SDL_Rect afficherTexte(SDL_Renderer *renderer, const char *texte, TTF_Font *police, int x, int y, int r, int g, int b);

#endif // AFFICH_H_INCLUDED
