#include "rechercher.h"
#include "function.h"
#include "textedition.h"


int recherchetud(char *CIN)
{

    SDL_Window* etudrecherch = NULL; // Ecran principal
    SDL_Surface* background = NULL;
    SDL_Rect backgroundRect , okrect;
    char mustContinue = 1; // Indicateur boolean pour la boucle principale

    int imgFlags = IMG_INIT_JPG|IMG_INIT_PNG|IMG_INIT_TIF; // Flags pour charger le support du JPG, PNG et TIF
    const char* imagePath = "./data/resultatrech.jpg";


    TTF_Font* pFont = NULL;
    const char* fontPath = "./data/font.ttf";
    SDL_Color fontColor = {0, 0, 0};
    SDL_Surface* nomfont = NULL;
    SDL_Surface* prenomfont = NULL;
    SDL_Surface* cinfont = NULL;
    SDL_Surface* naissancefont = NULL;
    SDL_Surface* adressefont = NULL;
    SDL_Surface* classfont = NULL;
    SDL_Surface* filierefont = NULL;
    SDL_Rect nomfontrect , prenomfontrect , cinfontrect , naissancefontrect , adressefontrect , classfontrect , filierefontrect;
    etudiant1 etud;
    FILE* F;
    F=fopen("./data/etudiants.txt","r");
    fseek(F, 0, SEEK_SET);
    do
    {
        fscanf(F,"%s ; %s ; %s ; %s ; %s ; %s ; %s ",&etud.CIN,&etud.nom ,&etud.prenom,&etud.DateNaissance,&etud.adress,&etud.clas,&etud.filiere) ;
        if(strcmp(CIN,etud.CIN)==0)
        {
             etudrecherch = SDL_CreateWindow("L'etudiant a recherchee ",SDL_WINDOWPOS_UNDEFINED,
                                                              SDL_WINDOWPOS_UNDEFINED,
                                                              519,
                                                              407,
                                                              SDL_WINDOW_SHOWN);
             if ( etudrecherch != NULL )
               {
                  background = IMG_Load(imagePath);//image
                  if ( background == NULL )
                    {
                        fprintf(stderr,"Erreur de chargement de l'image %s : %s\n",imagePath,IMG_GetError());
                        SDL_DestroyWindow(etudrecherch);
                        return -3;
                    }
                   pFont = TTF_OpenFont(fontPath,22);//font
                   if ( pFont == NULL )
                    {
                      fprintf(stderr,"Erreur de chargement de la police %s : %s\n",fontPath,TTF_GetError());
                      SDL_DestroyWindow(etudrecherch);
                      return -3;
                    }
                    nomfont = TTF_RenderText_Solid(pFont,etud.nom,fontColor);
                    if ( !nomfont )
                      {
                         fprintf(stderr,"Erreur pour generer le texte '%s'\n",TTF_GetError());
                         SDL_DestroyWindow(etudrecherch);
                         return -4;
                      }
                      prenomfont = TTF_RenderText_Solid(pFont,etud.prenom,fontColor);
                     if ( !prenomfont )
                      {
                         fprintf(stderr,"Erreur pour generer le texte '%s'\n",TTF_GetError());
                         SDL_DestroyWindow(etudrecherch);
                         return -4;
                      }
                      naissancefont = TTF_RenderText_Solid(pFont,etud.DateNaissance,fontColor);
                     if ( !naissancefont )
                      {
                         fprintf(stderr,"Erreur pour generer le texte '%s'\n",TTF_GetError());
                         SDL_DestroyWindow(etudrecherch);
                         return -4;
                      }
                      cinfont = TTF_RenderText_Solid(pFont,etud.CIN,fontColor);
                     if ( !cinfont )
                      {
                         fprintf(stderr,"Erreur pour generer le texte '%s'\n",TTF_GetError());
                         SDL_DestroyWindow(etudrecherch);
                         return -4;
                      }
                      adressefont = TTF_RenderText_Solid(pFont,etud.adress,fontColor);
                     if ( !adressefont )
                      {
                         fprintf(stderr,"Erreur pour generer le texte '%s'\n",TTF_GetError());
                         SDL_DestroyWindow(etudrecherch);
                         return -4;
                      }
                      classfont = TTF_RenderText_Solid(pFont,etud.clas,fontColor);
                     if ( !classfont )
                      {
                         fprintf(stderr,"Erreur pour generer le texte '%s'\n",TTF_GetError());
                         SDL_DestroyWindow(etudrecherch);
                         return -4;
                      }
                      filierefont = TTF_RenderText_Solid(pFont,etud.filiere,fontColor);
                     if ( !filierefont )
                      {
                         fprintf(stderr,"Erreur pour generer le texte '%s'\n",TTF_GetError());
                         SDL_DestroyWindow(etudrecherch);
                         return -4;
                      }
                  backgroundRect.x = 0; backgroundRect.y = 0; backgroundRect.w = 519; backgroundRect.h = 407;
                  okrect.x = 295; okrect.y = 323; okrect.w = 123; okrect.h = 72;
                  nomfontrect.x = 125; nomfontrect.y = 93; nomfontrect.w = 215; nomfontrect.h = 14;
                  prenomfontrect.x = 162; prenomfontrect.y = 125; prenomfontrect.w = 215; prenomfontrect.h = 14;
                  naissancefontrect.x = 279; naissancefontrect.y = 154; naissancefontrect.w = 192; naissancefontrect.h = 14;
                  cinfontrect.x = 110; cinfontrect.y = 183; cinfontrect.w = 215; cinfontrect.h = 14;
                  adressefontrect.x = 234; adressefontrect.y = 212; adressefontrect.w = 215; adressefontrect.h = 14;
                  classfontrect.x = 125; classfontrect.y = 246; classfontrect.w = 215; classfontrect.h = 14;
                  filierefontrect.x = 139; filierefontrect.y = 275; filierefontrect.w = 215; filierefontrect.h = 14;

                  while ( mustContinue )
                   {
                      if ( SDL_BlitSurface(background,NULL,SDL_GetWindowSurface(etudrecherch),&backgroundRect) != 0 )
                        {
                            fprintf(stderr,"Erreur de copie de la surface sur l'écran\n");
                            mustContinue=0;
                        }
                        if ( SDL_BlitSurface(nomfont,NULL,SDL_GetWindowSurface(etudrecherch),&nomfontrect) != 0 )
                        {
                            fprintf(stderr,"Erreur de copie de la surface sur l'écran\n");
                            mustContinue=0;
                        }
                        if ( SDL_BlitSurface(prenomfont,NULL,SDL_GetWindowSurface(etudrecherch),&prenomfontrect) != 0 )
                        {
                            fprintf(stderr,"Erreur de copie de la surface sur l'écran\n");
                            mustContinue=0;
                        }
                        if ( SDL_BlitSurface(naissancefont,NULL,SDL_GetWindowSurface(etudrecherch),&naissancefontrect) != 0 )
                        {
                            fprintf(stderr,"Erreur de copie de la surface sur l'écran\n");
                            mustContinue=0;
                        }
                        if ( SDL_BlitSurface(cinfont,NULL,SDL_GetWindowSurface(etudrecherch),&cinfontrect) != 0 )
                        {
                            fprintf(stderr,"Erreur de copie de la surface sur l'écran\n");
                            mustContinue=0;
                        }
                        if ( SDL_BlitSurface(adressefont,NULL,SDL_GetWindowSurface(etudrecherch),&adressefontrect) != 0 )
                        {
                            fprintf(stderr,"Erreur de copie de la surface sur l'écran\n");
                            mustContinue=0;
                        }
                        if ( SDL_BlitSurface(classfont,NULL,SDL_GetWindowSurface(etudrecherch),&classfontrect) != 0 )
                        {
                            fprintf(stderr,"Erreur de copie de la surface sur l'écran\n");
                            mustContinue=0;
                        }
                        if ( SDL_BlitSurface(filierefont,NULL,SDL_GetWindowSurface(etudrecherch),&filierefontrect) != 0 )
                        {
                            fprintf(stderr,"Erreur de copie de la surface sur l'écran\n");
                            mustContinue=0;
                        }

                      SDL_UpdateWindowSurface(etudrecherch);
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
                               if ( ( event.button.x > okrect.x ) && ( event.button.x < okrect.x + okrect.w ) && ( event.button.y > okrect.y ) && ( event.button.y < okrect.y + okrect.h ) )
                                  {
                                    SDL_DestroyWindow(etudrecherch);
                                    mustContinue = 0;

	                           break;}
                        }
                    }
                  SDL_DestroyWindow(etudrecherch);
	              TTF_CloseFont(pFont);
                }
               else
                {
                   fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
                   return -3;
                }
          }
       }while(!feof(F));
}
int Recherchwindow()
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

    SDL_SetWindowTitle(screen, "recherche a un etudiant");
    titre = TTF_RenderText_Solid(font1," Entrer le CIN de l'etudiant a rechercher  ",color1);
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
                //rechercher
            if ( ( event.button.x > modif.x ) && ( event.button.x < modif.x + modif.w ) && ( event.button.y > modif.y ) && ( event.button.y < modif.y + modif.h ) )
                {
                    test = cintest( te.text ) ;
                    if(test == 0)
                       {
                           SDL_DestroyWindow(screen);
                           done = 1;
                           recherchetud(te.text);
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
