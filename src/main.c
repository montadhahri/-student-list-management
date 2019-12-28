#include <stdio.h>
#include "prototype.h"
#include "ajouter.h"
#include "rechercher.h"
#include "modifier.h"
#include "supprimer.h"
#include "afficher.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>



int main(int argc, char* argv[])
{
    const unsigned int windowWidth = 640;
    const unsigned int windowHeight = 627;
    //int x , y ;
    SDL_Window* pWindow = NULL; // Ecran principal
    SDL_Surface* background = NULL;
    char mustContinue = 1; // Indicateur boolean pour la boucle principale

    int imgFlags = IMG_INIT_JPG|IMG_INIT_PNG|IMG_INIT_TIF; // Flags pour charger le support du JPG, PNG et TIF
    const char* imagePath0 = "./data/logo.jpg";
    SDL_Rect backgroundRect ,AjouterEtudRect ,RecherchEtudRect ,ModifEtudRect,SuprimEtudRect,SuprimtoutRect,AfficherRect , quitterrect;

    // Demarre SDL
    if ( SDL_Init(SDL_INIT_VIDEO) == -1 )
    {
        fprintf(stderr,"Erreur lors de l'initialisation de la SDL\n");
        return -1;
    }

    if ( IMG_Init(imgFlags) != imgFlags )
    {
        fprintf(stderr,"Erreur lors de l'initialisation de la SDL_image : '%s'\n",IMG_GetError());
        cleanup();
        return -1;
    }

    if ( TTF_Init() == -1 )
    {
        fprintf(stderr,"Erreur lors de l'initialisation de la SDL_TTF : '%s'\n",TTF_GetError());
        cleanup();
        return -1;
    }

    /* Création de la fenêtre */
    pWindow = SDL_CreateWindow("Bienvenue ",SDL_WINDOWPOS_UNDEFINED,
                                                              SDL_WINDOWPOS_UNDEFINED,
                                                              640,
                                                              627,
                                                              SDL_WINDOW_SHOWN);
    if ( pWindow != NULL )
    {
        background = IMG_Load(imagePath0);
        if ( background == NULL )
        {
            fprintf(stderr,"Erreur de chargement de l'image %s : %s\n",imagePath0,IMG_GetError());
            SDL_DestroyWindow(pWindow);
            cleanup();
            return -3;
        }



        // Une fois l'image chargée, nous pouvons calculer une position relative à celle-ci
        // Nous centrons l'image dans la fenêtre
        backgroundRect.x = windowWidth/2 - background->w/2;
        backgroundRect.y = windowHeight/2 - background->h/2;
        backgroundRect.w = background->w;
        backgroundRect.h = background->h;
        // Une fois l'image chargée, nous pouvons calculer une position relative à celle-ci
        // Nous centrons l'image dans la fenêtre
        AjouterEtudRect.x = 36;
        AjouterEtudRect.y = 310;
        AjouterEtudRect.w = 208;
        AjouterEtudRect.h = 54;
        // Une fois l'image chargée, nous pouvons calculer une position relative à celle-ci
        // Nous centrons l'image dans la fenêtre
        RecherchEtudRect.x = 359;
        RecherchEtudRect.y = 305;
        RecherchEtudRect.w = 212;
        RecherchEtudRect.h = 58;
        // Une fois l'image chargée, nous pouvons calculer une position relative à celle-ci
        // Nous centrons l'image dans la fenêtre
        ModifEtudRect.x = 33;
        ModifEtudRect.y = 388;
        ModifEtudRect.w = 215;
        ModifEtudRect.h = 56;
        // Une fois l'image chargée, nous pouvons calculer une position relative à celle-ci
        // Nous centrons l'image dans la fenêtre
        SuprimEtudRect.x = 358;
        SuprimEtudRect.y = 387;
        SuprimEtudRect.w = 212;
        SuprimEtudRect.h = 57;
        // Une fois l'image chargée, nous pouvons calculer une position relative à celle-ci
        // Nous centrons l'image dans la fenêtre
        SuprimtoutRect.x = 33;
        SuprimtoutRect.y = 467;
        SuprimtoutRect.w = 214;
        SuprimtoutRect.h = 56;
        // Une fois l'image chargée, nous pouvons calculer une position relative à celle-ci
        // Nous centrons l'image dans la fenêtre
        AfficherRect.x = 358;
        AfficherRect.y = 464;
        AfficherRect.w = 211;
        AfficherRect.h = 56;

        // Nous avons notre surface pour le texte donc nous calculons la position relative
        // Le texte est à un quart de la hauteur de l'ecran
        quitterrect.x = 206;
        quitterrect.y = 558;
        quitterrect.w = 211;
        quitterrect.h = 58;


        // Boucle principale
        while ( mustContinue )
        {
            if ( SDL_BlitSurface(background,NULL,SDL_GetWindowSurface(pWindow),&backgroundRect) != 0 )
            {
                fprintf(stderr,"Erreur de copie de la surface sur l'écran\n");
                mustContinue=0;
            }

            SDL_UpdateWindowSurface(pWindow);

            SDL_Event event;
            SDL_WaitEvent(&event);


            switch(event.type)
            {
        case SDL_QUIT :
            mustContinue =0;
            break;
        case SDL_KEYDOWN :
            switch (event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    mustContinue = 0;
                    break;
                }
        case SDL_MOUSEBUTTONUP :
            if ( ( event.button.x > AjouterEtudRect.x ) && ( event.button.x < AjouterEtudRect.x + AjouterEtudRect.w ) && ( event.button.y > AjouterEtudRect.y ) && ( event.button.y < AjouterEtudRect.y + AjouterEtudRect.h ) )
                Ajoutwindow();
            if ( ( event.button.x > RecherchEtudRect.x ) && ( event.button.x < RecherchEtudRect.x + RecherchEtudRect.w ) && ( event.button.y > RecherchEtudRect.y ) && ( event.button.y < RecherchEtudRect.y + RecherchEtudRect.h ) )
                Recherchwindow();
            if ( ( event.button.x > ModifEtudRect.x ) && ( event.button.x < ModifEtudRect.x + ModifEtudRect.w ) && ( event.button.y > ModifEtudRect.y ) && ( event.button.y < ModifEtudRect.y + ModifEtudRect.h ) )
                Modifwindow();
            if ( ( event.button.x > SuprimEtudRect.x ) && ( event.button.x < SuprimEtudRect.x + SuprimEtudRect.w ) && ( event.button.y > SuprimEtudRect.y ) && ( event.button.y < SuprimEtudRect.y + SuprimEtudRect.h ) )
                Supprimwindow();
            if ( ( event.button.x > SuprimtoutRect.x ) && ( event.button.x < SuprimtoutRect.x + SuprimtoutRect.w ) && ( event.button.y > SuprimtoutRect.y ) && ( event.button.y < SuprimtoutRect.y + SuprimtoutRect.h ) )
                Supprimtoutwindow();
            if ( ( event.button.x > AfficherRect.x ) && ( event.button.x < AfficherRect.x + AfficherRect.w ) && ( event.button.y > AfficherRect.y ) && ( event.button.y < AfficherRect.y + AfficherRect.h ) )
                Affichwindow();
            if ( ( event.button.x > quitterrect.x ) && ( event.button.x < quitterrect.x + quitterrect.w ) && ( event.button.y > quitterrect.y ) && ( event.button.y < quitterrect.y + quitterrect.h ) )
                mustContinue = 0;
            break;
            }

        }

        SDL_DestroyWindow(pWindow);
    }
    else
    {
        fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
        cleanup();
        return -3;
    }

    cleanup();

    return 0;
}
