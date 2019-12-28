

#ifndef TEXTEDITION

#define TEXTEDITION
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <wchar.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "ttf_secure.h"  //You can disable this inclusion if you don't intend to use multi-threading.


#define TE_STYLE_NORMAL         0x00000000
#define TE_STYLE_MULTILINE      0x00000001
#define TE_STYLE_VSCROLL        0x00000011
#define TE_STYLE_HSCROLL        0x00000100
#define TE_STYLE_AUTOJUMP       0x00001001
#define TE_STYLE_READONLY       0x00010000
#define TE_STYLE_JUSTDISPLAY    0x00110000
#define TE_STYLE_BLITRGBA       0x01000000

#define TE_BLITSTYLE_BLENDED    1
#define TE_BLITSTYLE_SHADED     2
#define TE_BLITSTYLE_SOLID      3


typedef struct
{
    char c;
    int x,y;

    char prevC;
    int prevX,prevY,prevState;
} TE_CharInfo;

typedef struct
{
    int w, h;
} TE_Dimension;

typedef struct
{
    int begin, end;
} TE_Interval;

typedef struct
{
    //standard
    char *text;
    SDL_Rect pos;
    TTF_Font *font;
    SDL_Color colorFG;
    int style;
    SDL_Renderer *renderer;

    //advanced
    int blitStyle, hSpace;
    SDL_Color colorBG, colorFGSelect, colorBGSelect;
    SDL_Point blitSurfPos;
    SDL_Surface *blitSurf;

    //system
    TE_CharInfo **tab;
    TE_Dimension dimTab[256];
    int cursorPos, prevCursorPos, mouseStatus, numLines, lastLine, fontHeight, textLength;
    int offsetX, offsetY, xmax;
    int focus, insert, HSBCaught, VSBCaught, anchorHSB, anchorVSB;
    Uint32 idWriterThread;
    SDL_mutex *lockUnlockMutex, *writerMutex;
    TE_Interval selection;
    SDL_Surface *tmpSurf, *HScrollBar, *VScrollBar;
    SDL_Texture *texture;
    SDL_Point posHSB, posVSB;
} TextEdition;


int TE_Init(void);
void TE_Quit(void);

int TE_NewTextEdition(TextEdition *te, int length, SDL_Rect pos, TTF_Font *font, SDL_Color colorFG, int style, SDL_Renderer *renderer);
int TE_DeleteTextEdition(TextEdition *te);
int TE_UpdateTextEdition(TextEdition *te, int i);
int TE_DisplayTextEdition(TextEdition *te);
int TE_HoldTextEdition(TextEdition *te, SDL_Event event);

SDL_Surface* TE_RenderText(const char text[], TextEdition te, int inverted);
int TE_SetEditionText(TextEdition *te, const char text[]);
int TE_SetFocusEdition(TextEdition *te, int focus);
int TE_GetFocusEdition(TextEdition *te);
int TE_SetCursorPos(TextEdition *te, int cursorPos);
int TE_GetCursorPos(TextEdition *te);

int TE_LockEdition(TextEdition *te);
int TE_UnlockEdition(TextEdition *te);

#endif