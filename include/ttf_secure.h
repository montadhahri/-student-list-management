

#ifndef TTFSECUREH

#define TTFSECUREH

#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

TTF_Font* TTFS_OpenFontSecure(const char *fileName, int ptSize);
void TTFS_CloseFontSecure(TTF_Font *font);
SDL_Surface* TTFS_RenderTextSecure(TTF_Font *font, const char *text, SDL_Color c1, SDL_Color c2, int type);
int TTFS_FontLineSkipSecure(TTF_Font *font);


#define TTFS_BLENDED    0
#define TTFS_SHADED     1
#define TTFS_SOLID      2

#define TTF_OpenFont(n,s)                   TTFS_OpenFontSecure(n,s)
#define TTF_CloseFont(f)                    TTFS_CloseFontSecure(f)
#define TTF_RenderText_Blended(f,t,c)       TTFS_RenderTextSecure(f,t,c,c,TTFS_BLENDED)
#define TTF_RenderText_Shaded(f,t,c1,c2)    TTFS_RenderTextSecure(f,t,c1,c2,TTFS_SHADED)
#define TTF_RenderText_Solid(f,t,c)         TTFS_RenderTextSecure(f,t,c,c,TTFS_SOLID)
#define TTF_FontLineSkip(f)                 TTFS_FontLineSkipSecure(f)





 #endif

