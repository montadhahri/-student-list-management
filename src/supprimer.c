#include "supprimer.h"
#include "function.h"
#include "textedition.h"

int supprimetud(char CIN[10])
{
etudiant etud;
    FILE* F;
    FILE* FW;
    F=fopen("./data/etudiants.txt","r");
    FW=fopen("./data/etudiants.txt.tmp","w");
    fseek(F, 0, SEEK_SET);
    do
    	{
        	fscanf(F,"%s ; %s ; %s ; %d/%d/%d ; %s ; %s ; %s ",&etud.CIN,&etud.nom ,&etud.prenom,&etud.DateNaissance.j,&etud.DateNaissance.m,&etud.DateNaissance.a,&etud.adress,&etud.clas,&etud.filiere) ;
        	if(strcmp(etud.CIN,CIN)!=0)
            		fprintf(FW,"%s ; %s ; %s ; %d/%d/%d ; %s ; %s ; %s \n",etud.CIN,etud.nom ,etud.prenom,etud.DateNaissance.j,etud.DateNaissance.m,etud.DateNaissance.a,etud.adress,etud.clas,etud.filiere) ;
        }while(!feof(F));
    fclose(F);
    fclose(FW);
    if(remove("./data/etudiants.txt")==0)
        {
            rename("./data/etudiants.txt.tmp","./data/etudiants.txt");
            remove("./data/etudiants.txt.tmp");
            succeswindow();
        }
    else
       {
           probwindow();
           remove("./data/etudiants.txt.tmp");
       }
    return 0 ;
}
int Supprimwindow()
{

   int test = 0 ;
    TextEdition te;
    SDL_Rect pos , titrerect , annuler , modif , erreurpos;
    TTF_Font *font , *font1;
    SDL_Color color , color1 , color2;
    SDL_Window *screen;
    SDL_Renderer *renderer;
    SDL_Texture *bgTexture;
    SDL_Texture *bgtitre , *bgerreur , *bgnexiste;
    SDL_Texture *titre , *erreur , *nexiste;
    SDL_Event event;
    int done = 0;
    if ( SDL_CreateWindowAndRenderer(601, 231, 0, &screen, &renderer) == -1)
    {
        fprintf(stderr, "Unable to set 640x480 video: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }
    font1 = TTF_OpenFont("./data/font.ttf", 10);
    color1.r = 122; color1.g = 55; color1.b = 139;
    color2.r = 139; color2.g = 26; color2.b = 26;

    SDL_SetWindowTitle(screen, "Supprimer un etudiant");
    titre = TTF_RenderText_Solid(font1,"Entrer le CIN de l'etudiant a supprimer",color1);
    erreur = TTF_RenderText_Solid(font1,"ERREUR : CIN fausse",color2);
    nexiste = TTF_RenderText_Solid(font1,"l'etudiant n'existe pas",color2);
    bgtitre = SDL_CreateTextureFromSurface(renderer, titre); //image font
    bgerreur = SDL_CreateTextureFromSurface(renderer, erreur); //image font
    bgnexiste = SDL_CreateTextureFromSurface(renderer, nexiste); //image font
    bgTexture = IMG_LoadTexture(renderer, "./data/recherche.jpg");
    SDL_FreeSurface(titre);
    SDL_FreeSurface(erreur);
    SDL_FreeSurface(nexiste);

    pos.x = 159; pos.y = 92; pos.w = 260; pos.h = 35;
    titrerect.x = 94; titrerect.y = 17; titrerect.w = 390; titrerect.h = 49;
    pos.x = 159; pos.y = 92; pos.w = 260; pos.h = 35;
    annuler.x = 412; annuler.y = 172; annuler.w = 173; annuler.h = 40;
    modif.x = 241; modif.y = 172; modif.w = 163; modif.h = 40;
    erreurpos.x = 5; erreurpos.y = 165; erreurpos.w = 229; erreurpos.h = 56;

    font = TTF_OpenFont("./data/default.ttf", 10);
    color.r = 0; color.g = 0; color.b = 0;

    memset(&te, 0, sizeof(TextEdition));

    te.blitStyle = TE_BLITSTYLE_BLENDED;
    te.colorBG = color;

    TE_NewTextEdition(&te, 9, pos, font, color, TE_STYLE_NORMAL | TE_STYLE_BLITRGBA, renderer);
    TE_SetEditionText(&te, "" );

    while (!done)
    {
        SDL_WaitEvent(&event);

        switch (event.type)
        {

            case SDL_QUIT:
                done = 1;
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE)
                    {SDL_DestroyWindow(screen);
                        done = 1;
                    break;}
                    case SDL_MOUSEBUTTONUP :
            //annuler
            if ( ( event.button.x > annuler.x ) && ( event.button.x < annuler.x + annuler.w ) && ( event.button.y > annuler.y ) && ( event.button.y < annuler.y + annuler.h ) )
                {SDL_DestroyWindow(screen);
                        done = 1;
                break;}
                //modifier
            if ( ( event.button.x > modif.x ) && ( event.button.x < modif.x + modif.w ) && ( event.button.y > modif.y ) && ( event.button.y < modif.y + modif.h ) )
                {
                    test = cintest( te.text ) ;
                    if(test == 0)
                       {

                           SDL_DestroyWindow(screen);
                           done = 1;
                           supprimetud(te.text);
                       }
                break;}
            default:
                break;
        }

        if (!done)
        {
            if (bgTexture)
                SDL_RenderCopy(renderer, bgTexture, NULL, NULL);
            else
                SDL_RenderClear(renderer);
            if (bgtitre)
                SDL_RenderCopy(renderer, bgtitre, NULL, &titrerect);
            else
                SDL_RenderClear(renderer);
            if(test == 1)
            {
               if (bgerreur)
                SDL_RenderCopy(renderer, bgerreur, NULL, &erreurpos);
            else
                SDL_RenderClear(renderer);
            }
            if(test == 2)
            {
               if (bgnexiste)
                SDL_RenderCopy(renderer, bgnexiste, NULL, &erreurpos);
            else
                SDL_RenderClear(renderer);
            }
            TE_HoldTextEdition(&te, event);
            TE_DisplayTextEdition(&te);

            SDL_RenderPresent(renderer);
        }
    }
    TE_DeleteTextEdition(&te);
    TE_Quit();
    TTF_CloseFont(font);
}
int Supprimtoutwindow()
{
    const unsigned int windowWidth = 480;
    const unsigned int windowHeight = 150;
    char pcontinue = 1 ;
    int i=0;

    SDL_Window* supprimTout = NULL;
    SDL_Surface* background;
    SDL_Surface* pOui;
    SDL_Surface* pNon;
    SDL_Rect backgroundRect , ouiRect , nomRect;

   TTF_Font* pFont = NULL;
    const char* fontPath = "./data/font.ttf";
   const char* imagePath = "./data/logo1.jpg";
   const char* imagePath1 = "./data/OuiNon.jpg";
   SDL_Color fontColor = {0, 0, 0};
   SDL_Surface* pFontsupprim = NULL;
   SDL_Surface* pFontoui = NULL;
   SDL_Surface* pFontnon = NULL;
   SDL_Rect pFontsupprimRect , ouiFontRect , nomFontRect ;

   supprimTout =SDL_CreateWindow("Supprimer tout les Etudiants ",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,
                                                              480,
                                                              150,
                                                              SDL_WINDOW_SHOWN);
   if( supprimTout != NULL )
   {
       background = IMG_Load(imagePath);
        if ( background == NULL )
        {
            fprintf(stderr,"Erreur de chargement de l'image %s : %s\n",imagePath,IMG_GetError());
            SDL_DestroyWindow(supprimTout);
            return -3;
        }
        pOui = IMG_Load(imagePath1);
        if ( pOui == NULL )
        {
            fprintf(stderr,"Erreur de chargement de l'image %s : %s\n",imagePath1,IMG_GetError());
            SDL_DestroyWindow(supprimTout);
            return -3;
        }
        pNon = IMG_Load(imagePath1);
        if ( pNon == NULL )
        {
            fprintf(stderr,"Erreur de chargement de l'image %s : %s\n",imagePath1,IMG_GetError());
            SDL_DestroyWindow(supprimTout);
            return -3;
        }
        pFont = TTF_OpenFont(fontPath,25);
        if ( pFont == NULL )
        {
            fprintf(stderr,"Erreur de chargement de la police %s : %s\n",fontPath,TTF_GetError());
            SDL_DestroyWindow(supprimTout);
            return -3;
        }
        pFontsupprim = TTF_RenderText_Solid(pFont,"Vous voullez continuer :",fontColor);
        if ( !pFontsupprim )
        {
            fprintf(stderr,"Erreur pour generer le texte '%s'\n",TTF_GetError());
            SDL_DestroyWindow(supprimTout);
            return -4;
        }
        pFontoui = TTF_RenderText_Solid(pFont,"Oui ",fontColor);
        if ( !pFontsupprim )
        {
            fprintf(stderr,"Erreur pour generer le texte '%s'\n",TTF_GetError());
            SDL_DestroyWindow(supprimTout);
            return -4;
        }
        pFontnon = TTF_RenderText_Solid(pFont,"Non",fontColor);
        if ( !pFontsupprim )
        {
            fprintf(stderr,"Erreur pour generer le texte '%s'\n",TTF_GetError());
            SDL_DestroyWindow(supprimTout);
            return -4;
        }
        // Une fois l'image chargée, nous pouvons calculer une position relative à celle-ci
        // Nous centrons l'image dans la fenêtre
        backgroundRect.x = windowWidth/2 - background->w/2;
        backgroundRect.y = windowHeight/2 - background->h/2;
        backgroundRect.w = background->w;
        backgroundRect.h = background->h;
        // Une fois l'image chargée, nous pouvons calculer une position relative à celle-ci
        // Nous centrons l'image dans la fenêtre
        pFontsupprimRect.x = windowWidth/2 - pFontsupprim->w/2;
        pFontsupprimRect.y = windowHeight/4 - pFontsupprim->h/2;
        pFontsupprimRect.w = pFontsupprim->w;
        pFontsupprimRect.h = pFontsupprim->h;
        // Une fois l'image chargée, nous pouvons calculer une position relative à celle-ci
        // Nous centrons l'image dans la fenêtre
        ouiRect.x = 3*windowWidth/8 - pOui->w/2;
        ouiRect.y = 3*windowHeight/4 - pOui->h/2;
        ouiRect.w = pOui->w;
        ouiRect.h = pOui->h;
        // Une fois l'image chargée, nous pouvons calculer une position relative à celle-ci
        // Nous centrons l'image dans la fenêtre
        nomRect.x = 5*windowWidth/8 - pNon->w/2;
        nomRect.y = 3*windowHeight/4 - pNon->h/2;
        nomRect.w = pNon->w;
        nomRect.h = pNon->h;
        // Une fois l'image chargée, nous pouvons calculer une position relative à celle-ci
        // Nous centrons l'image dans la fenêtre
        ouiFontRect.x = 3*windowWidth/8 - pFontoui->w/2;
        ouiFontRect.y = 3*windowHeight/4 - pFontoui->h/2;
        ouiFontRect.w = pFontoui->w;
        ouiFontRect.h = pFontoui->h;
        // Une fois l'image chargée, nous pouvons calculer une position relative à celle-ci
        // Nous centrons l'image dans la fenêtre
        nomFontRect.x = 5*windowWidth/8 - pFontnon->w/2;
        nomFontRect.y = 3*windowHeight/4 - pFontnon->h/2;
        nomFontRect.w = pFontnon->w;
        nomFontRect.h = pFontnon->h;
       while(pcontinue)
       {
           if ( SDL_BlitSurface(background,NULL,SDL_GetWindowSurface(supprimTout),&backgroundRect) != 0 )
            {
                fprintf(stderr,"Erreur de copie de la surface sur l'écran\n");
                pcontinue=0;
            }
            if ( SDL_BlitSurface(pFontsupprim,NULL,SDL_GetWindowSurface(supprimTout),&pFontsupprimRect) != 0 )
            {
                fprintf(stderr,"Erreur de copie du texte sur l'écran\n");
                pcontinue=0;
            }
            if ( SDL_BlitSurface(pOui,NULL,SDL_GetWindowSurface(supprimTout),&ouiRect) != 0 )
            {
                fprintf(stderr,"Erreur de copie du texte sur l'écran\n");
                pcontinue=0;
            }
            if ( SDL_BlitSurface(pNon,NULL,SDL_GetWindowSurface(supprimTout),&nomRect) != 0 )
            {
                fprintf(stderr,"Erreur de copie du texte sur l'écran\n");
                pcontinue=0;
            }
            if ( SDL_BlitSurface(pFontoui,NULL,SDL_GetWindowSurface(supprimTout),&ouiFontRect) != 0 )
            {
                fprintf(stderr,"Erreur de copie du texte sur l'écran\n");
                pcontinue=0;
            }
            if ( SDL_BlitSurface(pFontnon,NULL,SDL_GetWindowSurface(supprimTout),&nomFontRect) != 0 )
            {
                fprintf(stderr,"Erreur de copie du texte sur l'écran\n");
                pcontinue=0;
            }
           SDL_UpdateWindowSurface(supprimTout);
           SDL_Event supprimToutevent;
            SDL_WaitEvent(&supprimToutevent);
            switch(supprimToutevent.type)
            {
                case SDL_QUIT :
                    pcontinue =0;
                    break ;
                case SDL_KEYDOWN :
                    switch (supprimToutevent.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            pcontinue = 0;
                            break;
                    }
                case SDL_MOUSEBUTTONUP :
            if ( ( supprimToutevent.button.x > ouiRect.x ) && ( supprimToutevent.button.x < ouiRect.x + ouiRect.w ) && ( supprimToutevent.button.y > ouiRect.y ) && ( supprimToutevent.button.y < ouiRect.y + ouiRect.h ) )
                {
                    i=SupprimerToutEtudiants();
                    pcontinue = 0;
                    SDL_DestroyWindow(supprimTout);
                    if( i==1 )
                        defaultwindow();
                    else
                        succeswindow();
                }
            if ( ( supprimToutevent.button.x > nomRect.x ) && ( supprimToutevent.button.x < nomRect.x + nomRect.w ) && ( supprimToutevent.button.y > nomRect.y ) && ( supprimToutevent.button.y < nomRect.y + nomRect.h ) )
                pcontinue = 0;
            }
        }
    SDL_DestroyWindow(supprimTout);
    SDL_FreeSurface(pOui);
    SDL_FreeSurface(pNon);
    SDL_FreeSurface(pFontsupprim);
    SDL_FreeSurface(pFontoui);
    SDL_FreeSurface(pFontnon);
    SDL_FreeSurface(background);
    TTF_CloseFont(pFont);
    }
    else
    {
        fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
        return 1;
    }
    return 0 ;
}
