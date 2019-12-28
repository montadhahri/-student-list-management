#include "afficher.h"
#include "function.h"
#include "textedition.h"
#include "affich.h"
#include "liste.h"

char* classwindow()
{
    char clas[5];
    int testii1 = 0 , testii2 = 0 , testii3 = 0 , nerreur = 0;
    TextEdition ii1 , ii2 , ii3;
    SDL_Rect ii1rect , ii1chif , ii2rect , ii2chif , ii3rect , ii3chif , affichrect , erreurrect;
    TTF_Font *font , *font1;
    SDL_Color color , color1 , color2;
    SDL_Window *screen;
    SDL_Renderer *renderer;
    SDL_Texture *bgTexture , *iconerect , *bgerreur;
    SDL_Texture *erreur;
    SDL_Event event;
    int done = 0;
    if ( SDL_CreateWindowAndRenderer(538, 325, 0, &screen, &renderer) == -1)
    {
        fprintf(stderr, "Unable to set 640x480 video: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }
    font1 = TTF_OpenFont("./data/font.ttf", 10);
    color1.r = 122; color1.g = 55; color1.b = 139;
    color2.r = 139; color2.g = 26; color2.b = 26;

    SDL_SetWindowTitle(screen, "le class a afficher");
    erreur = TTF_RenderText_Solid(font1,"ERREUR : le class n'est pas correct",color2);
    bgerreur = SDL_CreateTextureFromSurface(renderer, erreur); //image font
    bgTexture = IMG_LoadTexture(renderer, "./data/classaffiche.jpg");
    iconerect = IMG_LoadTexture(renderer, "./data/icone.jpg");
    SDL_FreeSurface(erreur);

    ii1rect.x = 116; ii1rect.y = 97; ii1rect.w = 40; ii1rect.h = 31;
    ii1chif.x = 228; ii1chif.y = 105; ii1chif.w = 31; ii1chif.h = 25;
    ii2rect.x = 116; ii2rect.y = 141; ii2rect.w = 40; ii2rect.h = 31;
    ii2chif.x = 228; ii2chif.y = 141; ii2chif.w = 31; ii2chif.h = 25;
    ii3rect.x = 116; ii3rect.y = 185; ii3rect.w = 40; ii3rect.h = 31;
    ii3chif.x = 228; ii3chif.y = 183; ii3chif.w = 31; ii3chif.h = 25;
    affichrect.x = 301; affichrect.y = 244; affichrect.w = 190; affichrect.h = 62;
    erreurrect.x = 6; erreurrect.y = 258; erreurrect.w = 270; erreurrect.h = 45
    ;

    font = TTF_OpenFont("./data/default.ttf", 10);
    color.r = 0; color.g = 0; color.b = 0;

    memset(&ii1, 0, sizeof(TextEdition));
    memset(&ii2, 0, sizeof(TextEdition));
    memset(&ii3, 0, sizeof(TextEdition));

    ii1.blitStyle = TE_BLITSTYLE_BLENDED; ii1.colorBG = color;
    ii2.blitStyle = TE_BLITSTYLE_BLENDED; ii2.colorBG = color;
    ii3.blitStyle = TE_BLITSTYLE_BLENDED; ii3.colorBG = color;


    TE_NewTextEdition(&ii1, 2, ii1chif, font, color, TE_STYLE_NORMAL | TE_STYLE_BLITRGBA, renderer);
    TE_SetEditionText(&ii1, "" );
    TE_NewTextEdition(&ii2, 2, ii2chif, font, color, TE_STYLE_NORMAL | TE_STYLE_BLITRGBA, renderer);
    TE_SetEditionText(&ii2, "" );
    TE_NewTextEdition(&ii3, 2, ii3chif, font, color, TE_STYLE_NORMAL | TE_STYLE_BLITRGBA, renderer);
    TE_SetEditionText(&ii3, "" );

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
                        if ( ( event.button.x > ii1rect.x ) && ( event.button.x < ii1rect.x + ii1rect.w ) && ( event.button.y > ii1rect.y ) && ( event.button.y < ii1rect.y + ii1rect.h ) )
                            {testii1 = 1; testii2 = 0; testii3 = 0; break; }
                        if ( ( event.button.x > ii2rect.x ) && ( event.button.x < ii2rect.x + ii2rect.w ) && ( event.button.y > ii2rect.y ) && ( event.button.y < ii2rect.y + ii2rect.h ) )
                            {testii1 = 0; testii2 = 1; testii3 = 0; break; }
                        if ( ( event.button.x > ii3rect.x ) && ( event.button.x < ii3rect.x + ii3rect.w ) && ( event.button.y > ii3rect.y ) && ( event.button.y < ii3rect.y + ii3rect.h ) )
                            {testii1 = 0; testii2 = 0; testii3 = 1; break; }
                        if ( ( event.button.x > affichrect.x ) && ( event.button.x < affichrect.x + affichrect.w ) && ( event.button.y > affichrect.y ) && ( event.button.y < affichrect.y + affichrect.h ) )
                            {
                                if(strlen(clas) != 4)
                                    nerreur = 1;
                                else
                               {SDL_DestroyWindow(screen);
                                done = 1;}
                                break ;
                            }
            default:
                break;
        }

        if (!done)
        {
            if (bgTexture)
                SDL_RenderCopy(renderer, bgTexture, NULL, NULL);
            else
                SDL_RenderClear(renderer);
            if(testii1 == 1)
            {
                if (iconerect)
                SDL_RenderCopy(renderer, iconerect, NULL, &ii1rect);
            else
                SDL_RenderClear(renderer);
            TE_HoldTextEdition(&ii1, event);
            TE_DisplayTextEdition(&ii1);
            strcpy(clas , "II1"); strcat(clas , ii1.text);
            }
            if(testii2 == 1)
            {
                if (iconerect)
                SDL_RenderCopy(renderer, iconerect, NULL, &ii2rect);
            else
                SDL_RenderClear(renderer);
            TE_HoldTextEdition(&ii2, event);
            TE_DisplayTextEdition(&ii2);
            strcpy(clas , "II2"); strcat(clas , ii2.text);
            }
            if(testii3 == 1)
            {
                if (iconerect)
                SDL_RenderCopy(renderer, iconerect, NULL, &ii3rect);
            else
                SDL_RenderClear(renderer);
            TE_HoldTextEdition(&ii3, event);
            TE_DisplayTextEdition(&ii3);
            strcpy(clas , "II3"); strcat(clas , ii3.text);
            }
            if(nerreur == 1)
            {
                if (bgerreur)
                SDL_RenderCopy(renderer, bgerreur, NULL, &erreurrect);
            else
                SDL_RenderClear(renderer);
            }

            SDL_RenderPresent(renderer);
        }
    }
    SDL_DestroyWindow(screen);
    TE_DeleteTextEdition(&ii1);
    TE_Quit();
    TTF_CloseFont(font);
    return clas ;
}
char* filierewindow()
{
    char filiere[5];
    int testisid = 0 , testilsi = 0 , testii = 0 , testif = 0 , testrsr = 0 , testsle = 0 ,nerreur = 0;
    SDL_Rect isidrect , ilsirect , iirect , ifrect , rsrrect , slerect , affichrect , erreurrect;
    TTF_Font *font , *font1;
    SDL_Color color , color1 , color2;
    SDL_Window *screen;
    SDL_Renderer *renderer;
    SDL_Texture *bgTexture , *iconerect , *bgerreur;
    SDL_Texture *erreur;
    SDL_Event event;
    int done = 0;
    if ( SDL_CreateWindowAndRenderer(653, 483, 0, &screen, &renderer) == -1)
    {
        fprintf(stderr, "Unable to set 640x480 video: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }
    font1 = TTF_OpenFont("./data/font.ttf", 10);
    color1.r = 122; color1.g = 55; color1.b = 139;
    color2.r = 139; color2.g = 26; color2.b = 26;

    SDL_SetWindowTitle(screen, "le filiere a afficher");
    erreur = TTF_RenderText_Solid(font1,"ERREUR: vous voullez selectionner un choix",color2);
    bgerreur = SDL_CreateTextureFromSurface(renderer, erreur); //image font
    bgTexture = IMG_LoadTexture(renderer, "./data/filiereaffiche.jpg");
    iconerect = IMG_LoadTexture(renderer, "./data/icone.jpg");
    SDL_FreeSurface(erreur);

    isidrect.x = 69; isidrect.y = 109; isidrect.w = 40; isidrect.h = 31;
    ilsirect.x = 69; ilsirect.y = 148; ilsirect.w = 40; ilsirect.h = 31;
    iirect.x = 69; iirect.y = 186; iirect.w = 40; iirect.h = 31;
    ifrect.x = 69; ifrect.y = 224; ifrect.w = 40; ifrect.h = 31;
    rsrrect.x = 69; rsrrect.y = 263; rsrrect.w = 40; rsrrect.h = 31;
    slerect.x = 69; slerect.y = 302; slerect.w = 40; slerect.h = 31;
    affichrect.x = 400; affichrect.y = 387; affichrect.w = 191; affichrect.h = 56;
    erreurrect.x = 12; erreurrect.y = 376; erreurrect.w = 352; erreurrect.h = 64;

    font = TTF_OpenFont("./data/default.ttf", 10);
    color.r = 0; color.g = 0; color.b = 0;

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
                        if ( ( event.button.x > isidrect.x ) && ( event.button.x < isidrect.x + isidrect.w ) && ( event.button.y > isidrect.y ) && ( event.button.y < isidrect.y + isidrect.h ) )
                            {testisid = 1; testilsi = 0; testii = 0; testif = 0; testrsr = 0; testsle = 0; break; }
                        if ( ( event.button.x > ilsirect.x ) && ( event.button.x < ilsirect.x + ilsirect.w ) && ( event.button.y > ilsirect.y ) && ( event.button.y < ilsirect.y + ilsirect.h ) )
                            {testisid = 0; testilsi = 1; testii = 0; testif = 0; testrsr = 0; testsle = 0; break; }
                        if ( ( event.button.x > iirect.x ) && ( event.button.x < iirect.x + iirect.w ) && ( event.button.y > iirect.y ) && ( event.button.y < iirect.y + iirect.h ) )
                            {testisid = 0; testilsi = 0; testii = 1; testif = 0; testrsr = 0; testsle = 0; break; }
                      if ( ( event.button.x > ifrect.x ) && ( event.button.x < ifrect.x + ifrect.w ) && ( event.button.y > ifrect.y ) && ( event.button.y < ifrect.y + ifrect.h ) )
                            {testisid = 0; testilsi = 0; testii = 0; testif = 1; testrsr = 0; testsle = 0; break; }
                        if ( ( event.button.x > rsrrect.x ) && ( event.button.x < rsrrect.x + rsrrect.w ) && ( event.button.y > rsrrect.y ) && ( event.button.y < rsrrect.y + rsrrect.h ) )
                            {testisid = 0; testilsi = 0; testii = 0; testif = 0; testrsr = 1; testsle = 0; break; }
                        if ( ( event.button.x > slerect.x ) && ( event.button.x < slerect.x + slerect.w ) && ( event.button.y > slerect.y ) && ( event.button.y < slerect.y + slerect.h ) )
                            {testisid = 0; testilsi = 0; testii = 0; testif = 0; testrsr = 0; testsle = 1; break; }
                        if ( ( event.button.x > affichrect.x ) && ( event.button.x < affichrect.x + affichrect.w ) && ( event.button.y > affichrect.y ) && ( event.button.y < affichrect.y + affichrect.h ) )
                            {
                                if(strlen(filiere) == 0)
                                    nerreur = 1;
                                else
                               {SDL_DestroyWindow(screen);
                                done = 1;}
                                break ;
                            }
            default:
                break;
        }

        if (!done)
        {
            if (bgTexture)
                SDL_RenderCopy(renderer, bgTexture, NULL, NULL);
            else
                SDL_RenderClear(renderer);
            if(testisid == 1)
            {
                if (iconerect)
                SDL_RenderCopy(renderer, iconerect, NULL, &isidrect);
            else
                SDL_RenderClear(renderer);
            strcpy(filiere , "ISID");
            }
            if(testilsi == 1)
            {
                if (iconerect)
                SDL_RenderCopy(renderer, iconerect, NULL, &ilsirect);
            else
                SDL_RenderClear(renderer);
            strcpy(filiere , "ILSI");
            }
            if(testii == 1)
            {
                if (iconerect)
                SDL_RenderCopy(renderer, iconerect, NULL, &iirect);
            else
                SDL_RenderClear(renderer);
            strcpy(filiere , "II");
            }
            if(testif == 1)
            {
                if (iconerect)
                SDL_RenderCopy(renderer, iconerect, NULL, &ifrect);
            else
                SDL_RenderClear(renderer);
            strcpy(filiere , "IF");
            }
            if(testrsr == 1)
            {
                if (iconerect)
                SDL_RenderCopy(renderer, iconerect, NULL, &rsrrect);
            else
                SDL_RenderClear(renderer);
            strcpy(filiere , "RSR");
            }
            if(testsle == 1)
            {
                if (iconerect)
                SDL_RenderCopy(renderer, iconerect, NULL, &slerect);
            else
                SDL_RenderClear(renderer);
            strcpy(filiere , "SLE");
            }
            if(nerreur == 1)
            {
                if (bgerreur)
                SDL_RenderCopy(renderer, bgerreur, NULL, &erreurrect);
            else
                SDL_RenderClear(renderer);
            }

            SDL_RenderPresent(renderer);
        }
    }
    SDL_DestroyWindow(screen);
    TE_Quit();
    TTF_CloseFont(font);
    return filiere ;
}
char* nomwindow()
{
    char nom[10];
    int  nerreur = 0;
    TextEdition tenom ;
    SDL_Rect nomrect , affichrect , erreurrect;
    TTF_Font *font , *font1;
    SDL_Color color , color1 , color2;
    SDL_Window *screen;
    SDL_Renderer *renderer;
    SDL_Texture *bgTexture , *bgerreur;
    SDL_Texture *erreur;
    SDL_Event event;
    int done = 0;
    if ( SDL_CreateWindowAndRenderer(516, 328, 0, &screen, &renderer) == -1)
    {
        fprintf(stderr, "Unable to set 640x480 video: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }
    font1 = TTF_OpenFont("./data/font.ttf", 10);
    color1.r = 122; color1.g = 55; color1.b = 139;
    color2.r = 139; color2.g = 26; color2.b = 26;

    SDL_SetWindowTitle(screen, "le nom a afficher");
    erreur = TTF_RenderText_Solid(font1,"ERREUR : entrer un nom",color2);
    bgerreur = SDL_CreateTextureFromSurface(renderer, erreur); //image font
    bgTexture = IMG_LoadTexture(renderer, "./data/nomaffiche.jpg");
    SDL_FreeSurface(erreur);

    nomrect.x =106; nomrect.y = 138; nomrect.w = 294; nomrect.h = 36;
    affichrect.x = 296; affichrect.y = 257; affichrect.w = 199; affichrect.h = 51;
    erreurrect.x = 10; erreurrect.y = 257; erreurrect.w = 262; erreurrect.h = 57;

    font = TTF_OpenFont("./data/default.ttf", 10);
    color.r = 0; color.g = 0; color.b = 0;

    memset(&tenom, 0, sizeof(TextEdition));

    tenom.blitStyle = TE_BLITSTYLE_BLENDED; tenom.colorBG = color;


    TE_NewTextEdition(&tenom, 10, nomrect, font, color, TE_STYLE_NORMAL | TE_STYLE_BLITRGBA, renderer);
    TE_SetEditionText(&tenom, "" );
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
                        if ( ( event.button.x > affichrect.x ) && ( event.button.x < affichrect.x + affichrect.w ) && ( event.button.y > affichrect.y ) && ( event.button.y < affichrect.y + affichrect.h ) )
                            {
                                if(strlen(nom) == 0)
                                    nerreur = 1;
                                else
                               {SDL_DestroyWindow(screen);
                                done = 1;}
                                break ;
                            }
            default:
                break;
        }

        if (!done)
        {
            if (bgTexture)
                SDL_RenderCopy(renderer, bgTexture, NULL, NULL);
            else
                SDL_RenderClear(renderer);
            if(nerreur == 1)
            {
                if (bgerreur)
                SDL_RenderCopy(renderer, bgerreur, NULL, &erreurrect);
            else
                SDL_RenderClear(renderer);
            }
            TE_HoldTextEdition(&tenom, event);
            TE_DisplayTextEdition(&tenom);
            strcpy(nom , tenom.text);

            SDL_RenderPresent(renderer);
        }
    }
    SDL_DestroyWindow(screen);
    TE_DeleteTextEdition(&tenom);
    TE_Quit();
    TTF_CloseFont(font);
    return nom ;
}
int Affichwindow()
{
    etudiant1 etud;
    int i = 0 ;
    int j = 0 ;
    char option[10];
    FILE *F = NULL;
    const unsigned int windowWidth = 759;
    const unsigned int windowHeight = 464;
    SDL_Window* AffichEtud = NULL;
    SDL_Renderer *renderer;
    SDL_Texture *bgTexture;
    fpos_t pos;
    Pile p;
    p.premier=NULL;
    char pcontinue = 1 ;
    char cont = 1 ;
    char cont1 = 1 ;

    const char* imagePath0 = "./data/afficher.jpg";
    SDL_Rect backgroundRect ,classbuttonrect ,filierebuttonrect ,nombuttonrect ,retourrect , tousrect ;
   SDL_Rect nomrect , prenomrect , cinrect , naisrect , adrrect , clasrect , filiererect ;


   TTF_Font* pFont = NULL;
   const char* fontPath = "./data/default.ttf";
   SDL_Color fontColor = {0, 0, 0};
    if ( SDL_CreateWindowAndRenderer(759, 464, 0, &AffichEtud, &renderer) == -1)
    {
        fprintf(stderr, "Unable to set 640x480 video: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }
    SDL_SetWindowTitle(AffichEtud, "afficher tout les etudiants ");//titre
    bgTexture = IMG_LoadTexture(renderer, "./data/afficher.jpg");

        pFont = TTF_OpenFont(fontPath,12);
        if ( pFont == NULL )
        {
            fprintf(stderr,"Erreur de chargement de la police %s : %s\n",fontPath,TTF_GetError());
            SDL_DestroyWindow(AffichEtud);
            return -3;
        }



        tousrect.x = 16; tousrect.y = 13; tousrect.w = 102;tousrect.h = 70;
        classbuttonrect.x = 129; classbuttonrect.y = 13; classbuttonrect.w = 102; classbuttonrect.h = 70;
        filierebuttonrect.x = 243; filierebuttonrect.y = 11; filierebuttonrect.w = 102; filierebuttonrect.h = 80;
        nombuttonrect.x = 355; nombuttonrect.y = 12; nombuttonrect.w = 102; nombuttonrect.h = 80;
        retourrect.x = 468; retourrect.y = 11; retourrect.w = 103; retourrect.h = 70;

        nomrect.x = 1; nomrect.y = 128;
        prenomrect.x = 103; prenomrect.y = 128;
        cinrect.x = 199; cinrect.y = 128;
        naisrect.x = 310; naisrect.y = 128;
        adrrect.x = 442; adrrect.y = 128;
        clasrect.x = 557; clasrect.y = 128;
        filiererect.x = 659; filiererect.y = 128;



       while(pcontinue)
       {
           SDL_Event Affichevent;
           SDL_WaitEvent(&Affichevent);
            switch(Affichevent.type)
            {
                case SDL_QUIT :
                    pcontinue =0;
                    break ;
                case SDL_KEYDOWN :
                    switch (Affichevent.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            pcontinue = 0;
                            break;
                        case SDLK_s :
                            pcontinue = 0;
                            break;

                    }
                 case SDL_MOUSEBUTTONUP :
                    if ( ( Affichevent.button.x > tousrect.x ) && ( Affichevent.button.x < tousrect.x + tousrect.w ) && ( Affichevent.button.y > tousrect.y ) && ( Affichevent.button.y < tousrect.y + tousrect.h ) )
                        {
                F = fopen("./data/etudiants.txt","r");
                if(EstVide(F)==1)
                {
                   fclose(F);
                   defaultwindow();
                    break;
                }
                if(i == 0)
                {
                    depiltout(&p);
                    rewind(F);
                    fgetpos(F,&pos);
                    empiler(&p);
                    fgetpos(F,&p.premier->pos);
                }
                if( j == 0 )
                    fsetpos(F,&pos);
                else
                    {
                        if(Vide(&p)!=0)
                            {
                                depiler(&p);
                                fsetpos(F,&p.premier->pos);
                            }
                        else
                            rewind(F);
                    }
                while(adrrect.y + 27 < 464 && !feof(F) )
                {
                    fscanf(F,"%s ; %s ; %s ; %s ; %s ; %s ; %s ",&etud.CIN,&etud.nom ,&etud.prenom,&etud.DateNaissance,&etud.adress,&etud.clas,&etud.filiere) ;
                    afficherTexte(renderer, etud.nom, pFont, nomrect.x, nomrect.y, 0, 0, 0);
                    afficherTexte(renderer, etud.prenom, pFont, prenomrect.x, prenomrect.y, 0, 0, 0);
                    afficherTexte(renderer, etud.CIN, pFont, cinrect.x, cinrect.y, 0, 0, 0);
                    afficherTexte(renderer, etud.DateNaissance, pFont, naisrect.x, naisrect.y, 0, 0, 0);
                    afficherTexte(renderer, etud.adress, pFont, adrrect.x, adrrect.y, 0, 0, 0);
                    afficherTexte(renderer, etud.clas, pFont, clasrect.x, clasrect.y, 0, 0, 0);
                    afficherTexte(renderer, etud.filiere, pFont, filiererect.x, filiererect.y, 0, 0, 0);
                    nomrect.y += 27;
                    prenomrect.y += 27;
                    cinrect.y += 27;
                    naisrect.y += 27;
                    adrrect.y += 27;
                    clasrect.y += 27;
                    filiererect.y += 27;
                    }
                       nomrect.y = 128; prenomrect.y = 128; cinrect.y = 128; naisrect.y = 128; adrrect.y = 128; clasrect.y = 128; filiererect.y = 128;
                       while(cont)
                      {
                          SDL_Event ev;
                          SDL_WaitEvent(&ev);
                          switch(ev.type)
                          {
                            case SDL_KEYDOWN :
                                switch (ev.key.keysym.sym)
                                {
                                    case SDLK_ESCAPE :
                                        cont1 = -1 ;
                                        cont = 0;
                                        pcontinue = 0;
                                        break;
                                    case SDLK_UP :
                                          j = 1;
                                          i=1;
                                          SDL_PushEvent(&Affichevent);
                                        cont = 0;
                                        break;
                                    case SDLK_DOWN :
                                          if(!feof(F))
                                          {
                                              fgetpos(F,&pos);
                                              empiler(&p);
                                              fgetpos(F,&p.premier->pos);
                                              i=1;
                                              j=0;
                                          }
                                          SDL_PushEvent(&Affichevent);
                                        cont = 0;
                                        break;
                                }
                            case SDL_MOUSEBUTTONUP :
                                if ( ( ev.button.x > retourrect.x ) && ( ev.button.x < retourrect.x + retourrect.w ) && ( ev.button.y > retourrect.y ) && ( ev.button.y < retourrect.y + retourrect.h ) )
                                {
                                    i=0;
                                    j=0;
                                    pcontinue = 0;
                                    cont = 0 ;
                                    break;
                                }
                                if ( ( ev.button.x > classbuttonrect.x ) && ( ev.button.x < classbuttonrect.x + classbuttonrect.w ) && ( ev.button.y > classbuttonrect.y ) && ( ev.button.y < classbuttonrect.y + classbuttonrect.h ) )
                                {
                                    i=0;
                                    j=0;
                                    cont = 0 ;
                                    SDL_PushEvent(&ev);
                                    break;
                                }
                                if ( ( ev.button.x > filierebuttonrect.x ) && ( ev.button.x < filierebuttonrect.x + filierebuttonrect.w ) && ( ev.button.y > filierebuttonrect.y ) && ( ev.button.y < filierebuttonrect.y + filierebuttonrect.h ) )
                                {
                                    i=0;
                                    j=0;
                                    cont = 0 ;
                                    SDL_PushEvent(&ev);
                                    break;
                                }
                                if ( ( ev.button.x > nombuttonrect.x ) && ( ev.button.x < nombuttonrect.x + nombuttonrect.w ) && ( ev.button.y > nombuttonrect.y ) && ( ev.button.y < nombuttonrect.y + nombuttonrect.h ) )
                                {
                                    i=0;
                                    j=0;
                                    cont = 0 ;
                                    SDL_PushEvent(&ev);
                                    break;
                                }
                            default :
                                SDL_Delay(1);
                          }
                      }
                      cont = 1 ;
                fclose(F);
                break;
                        }
                    if ( ( Affichevent.button.x > classbuttonrect.x ) && ( Affichevent.button.x < classbuttonrect.x + classbuttonrect.w ) && ( Affichevent.button.y > classbuttonrect.y ) && ( Affichevent.button.y < classbuttonrect.y + classbuttonrect.h ) )
                        {
                F = fopen("./data/etudiants.txt","r");
                if(EstVide(F)==1)
                {
                   fclose(F);
                   defaultwindow();
                    break;
                }
                if(i == 0)
                {
                    strcpy(option , classwindow());
                    depiltout(&p);
                    rewind(F);
                    fgetpos(F,&pos);
                    empiler(&p);
                    fgetpos(F,&p.premier->pos);
                }
                if( j == 0 )
                        fsetpos(F,&pos);
                else
                    {
                        if(Vide(&p)!=0)
                            {
                                depiler(&p);
                                fsetpos(F,&p.premier->pos);

                            }
                        else
                            rewind(F);
                    }
                while(adrrect.y + 27 < 464 && !feof(F))
                {fscanf(F,"%s ; %s ; %s ; %s ; %s ; %s ; %s ",&etud.CIN,&etud.nom ,&etud.prenom,&etud.DateNaissance,&etud.adress,&etud.clas,&etud.filiere) ;
                if(strcmp(option , etud.clas) == 0)
                {afficherTexte(renderer, etud.nom, pFont, nomrect.x, nomrect.y, 0, 0, 0);
                afficherTexte(renderer, etud.prenom, pFont, prenomrect.x, prenomrect.y, 0, 0, 0);
                afficherTexte(renderer, etud.CIN, pFont, cinrect.x, cinrect.y, 0, 0, 0);
                afficherTexte(renderer, etud.DateNaissance, pFont, naisrect.x, naisrect.y, 0, 0, 0);
                afficherTexte(renderer, etud.adress, pFont, adrrect.x, adrrect.y, 0, 0, 0);
                afficherTexte(renderer, etud.clas, pFont, clasrect.x, clasrect.y, 0, 0, 0);
                afficherTexte(renderer, etud.filiere, pFont, filiererect.x, filiererect.y, 0, 0, 0);

                 nomrect.y += 27;
                 prenomrect.y += 27;
                 cinrect.y += 27;
                 naisrect.y += 27;
                 adrrect.y += 27;
                 clasrect.y += 27;
                 filiererect.y += 27;
                }
                 }

                     nomrect.y = 128; prenomrect.y = 128; cinrect.y = 128; naisrect.y = 128; adrrect.y = 128; clasrect.y = 128; filiererect.y = 128;
                     while(cont)
                      {
                          SDL_Event ev;
                          SDL_WaitEvent(&ev);
                          switch(ev.type)
                          {
                      case SDL_KEYDOWN :
                        switch (ev.key.keysym.sym)
                        {
                                case SDLK_ESCAPE :
                                cont = 0;
                                pcontinue = 0;
                                break;
                                case SDLK_UP :
                                          j = 1;
                                          i=1;
                                          SDL_PushEvent(&Affichevent);
                                        cont = 0;
                                        break;
                                case SDLK_DOWN :
                                          if(!feof(F))
                                          {
                                              fgetpos(F,&pos);
                                              empiler(&p);
                                              fgetpos(F,&p.premier->pos);
                                              i=1;
                                              j=0;
                                          }
                                          SDL_PushEvent(&Affichevent);
                                        cont = 0;
                                        break;
                        }
                      case SDL_MOUSEBUTTONUP :
                        if ( ( ev.button.x > retourrect.x ) && ( ev.button.x < retourrect.x + retourrect.w ) && ( ev.button.y > retourrect.y ) && ( ev.button.y < retourrect.y + retourrect.h ) )
                        {
                            i=0;
                            j=0;
                            pcontinue = 0;
                            cont = 0 ;
                            break;
                        }
                        if ( ( ev.button.x > tousrect.x ) && ( ev.button.x < tousrect.x + tousrect.w ) && ( ev.button.y > tousrect.y ) && ( ev.button.y < tousrect.y + tousrect.h ) )
                        {
                            i=0;
                            j=0;
                            cont = 0 ;
                            SDL_PushEvent(&ev);
                            break;
                        }
                        if ( ( ev.button.x > classbuttonrect.x ) && ( ev.button.x < classbuttonrect.x + classbuttonrect.w ) && ( ev.button.y > classbuttonrect.y ) && ( ev.button.y < classbuttonrect.y + classbuttonrect.h ) )
                        {
                             i=0; j=0;
                            cont = 0 ;
                            SDL_PushEvent(&ev);
                            break;
                        }
                        if ( ( ev.button.x > filierebuttonrect.x ) && ( ev.button.x < filierebuttonrect.x + filierebuttonrect.w ) && ( ev.button.y > filierebuttonrect.y ) && ( ev.button.y < filierebuttonrect.y + filierebuttonrect.h ) )
                        {
                             i=0; j=0;
                            cont = 0 ;
                            SDL_PushEvent(&ev);
                            break;
                        }
                    if ( ( ev.button.x > nombuttonrect.x ) && ( ev.button.x < nombuttonrect.x + nombuttonrect.w ) && ( ev.button.y > nombuttonrect.y ) && ( ev.button.y < nombuttonrect.y + nombuttonrect.h ) )
                        {
                             i=0; j=0;
                            cont = 0 ;
                            SDL_PushEvent(&ev);
                            break;
                        }
                      default :
                            SDL_Delay(1);
                          }
                      }
                      cont = 1 ;



            fclose(F);
                        break;
                        }
                    if ( ( Affichevent.button.x > filierebuttonrect.x ) && ( Affichevent.button.x < filierebuttonrect.x + filierebuttonrect.w ) && ( Affichevent.button.y > filierebuttonrect.y ) && ( Affichevent.button.y < filierebuttonrect.y + filierebuttonrect.h ) )
                        {
                            F = fopen("./data/etudiants.txt","r");
                            if(EstVide(F)==1)
                {
                   fclose(F);
                   defaultwindow();
                    break;
                }
                if(i == 0)
                {
                    strcpy(option , filierewindow());
                    depiltout(&p);
                    rewind(F);
                    fgetpos(F,&pos);
                    empiler(&p);
                    fgetpos(F,&p.premier->pos);
                }
                if( j == 0 )
                    fsetpos(F,&pos);
                else
                    {
                        if(Vide(&p)!=0)
                            {
                                depiler(&p);
                                fsetpos(F,&p.premier->pos);
                            }
                        else
                            rewind(F);
                    }
                while(adrrect.y + 27 < 464 && !feof(F))
                {fscanf(F,"%s ; %s ; %s ; %s ; %s ; %s ; %s ",&etud.CIN,&etud.nom ,&etud.prenom,&etud.DateNaissance,&etud.adress,&etud.clas,&etud.filiere) ;
                if(strcmp(option , etud.filiere) == 0)
                {afficherTexte(renderer, etud.nom, pFont, nomrect.x, nomrect.y, 0, 0, 0);
                afficherTexte(renderer, etud.prenom, pFont, prenomrect.x, prenomrect.y, 0, 0, 0);
                afficherTexte(renderer, etud.CIN, pFont, cinrect.x, cinrect.y, 0, 0, 0);
                afficherTexte(renderer, etud.DateNaissance, pFont, naisrect.x, naisrect.y, 0, 0, 0);
                afficherTexte(renderer, etud.adress, pFont, adrrect.x, adrrect.y, 0, 0, 0);
                afficherTexte(renderer, etud.clas, pFont, clasrect.x, clasrect.y, 0, 0, 0);
                afficherTexte(renderer, etud.filiere, pFont, filiererect.x, filiererect.y, 0, 0, 0);

                 nomrect.y += 27;
                 prenomrect.y += 27;
                 cinrect.y += 27;
                 naisrect.y += 27;
                 adrrect.y += 27;
                 clasrect.y += 27;
                 filiererect.y += 27;
                 }
                }

                      nomrect.y = 128; prenomrect.y = 128; cinrect.y = 128; naisrect.y = 128; adrrect.y = 128; clasrect.y = 128; filiererect.y = 128;
                      while(cont)
                      {
                          SDL_Event ev;
                          SDL_WaitEvent(&ev);
                          switch(ev.type)
                          {
                      case SDL_KEYDOWN :
                        switch (ev.key.keysym.sym)
                        {
                                case SDLK_ESCAPE :
                                cont = 0;
                                pcontinue = 0;
                                break;
                                case SDLK_UP :
                                          j = 1;
                                          i=1;
                                          SDL_PushEvent(&Affichevent);
                                        cont = 0;
                                        break;
                                case SDLK_DOWN :
                                          if(!feof(F))
                                          {
                                              fgetpos(F,&pos);
                                              empiler(&p);
                                              fgetpos(F,&p.premier->pos);
                                              i=1;
                                              j=0;
                                          }
                                          SDL_PushEvent(&Affichevent);
                                        cont = 0;
                                        break;
                        }
                      case SDL_MOUSEBUTTONUP :
                        if ( ( ev.button.x > retourrect.x ) && ( ev.button.x < retourrect.x + retourrect.w ) && ( ev.button.y > retourrect.y ) && ( ev.button.y < retourrect.y + retourrect.h ) )
                        {
                             i=0; j=0;
                            pcontinue = 0;
                            cont = 0 ;
                            break;
                        }
                        if ( ( ev.button.x > tousrect.x ) && ( ev.button.x < tousrect.x + tousrect.w ) && ( ev.button.y > tousrect.y ) && ( ev.button.y < tousrect.y + tousrect.h ) )
                        {
                             i=0; j=0;
                            cont = 0 ;
                            SDL_PushEvent(&ev);
                            break;
                        }
                        if ( ( ev.button.x > classbuttonrect.x ) && ( ev.button.x < classbuttonrect.x + classbuttonrect.w ) && ( ev.button.y > classbuttonrect.y ) && ( ev.button.y < classbuttonrect.y + classbuttonrect.h ) )
                        {
                             i=0; j=0;
                            cont = 0 ;
                            SDL_PushEvent(&ev);
                            break;
                        }
                        if ( ( ev.button.x > filierebuttonrect.x ) && ( ev.button.x < filierebuttonrect.x + filierebuttonrect.w ) && ( ev.button.y > filierebuttonrect.y ) && ( ev.button.y < filierebuttonrect.y + filierebuttonrect.h ) )
                        {
                             i=0; j=0;
                            cont = 0 ;
                            SDL_PushEvent(&ev);
                            break;
                        }
                    if ( ( ev.button.x > nombuttonrect.x ) && ( ev.button.x < nombuttonrect.x + nombuttonrect.w ) && ( ev.button.y > nombuttonrect.y ) && ( ev.button.y < nombuttonrect.y + nombuttonrect.h ) )
                        {
                             i=0; j=0;
                            cont = 0 ;
                            SDL_PushEvent(&ev);
                            break;
                        }
                      default :
                            SDL_Delay(1);
                          }
                      }
                      cont = 1 ;

            fclose(F);
                            break;
                        }
                    if ( ( Affichevent.button.x > nombuttonrect.x ) && ( Affichevent.button.x < nombuttonrect.x + nombuttonrect.w ) && ( Affichevent.button.y > nombuttonrect.y ) && ( Affichevent.button.y < nombuttonrect.y + nombuttonrect.h ) )
                        {

                            F = fopen("./data/etudiants.txt","r");
                            if(EstVide(F)==1)
                {
                   fclose(F);
                   defaultwindow();
                    break;
                }
                if(i == 0)
                {
                    strcpy(option , nomwindow());
                    depiltout(&p);
                    rewind(F);
                    fgetpos(F,&pos);
                    empiler(&p);
                    fgetpos(F,&p.premier->pos);
                }
                if( j == 0 )
                    fsetpos(F,&pos);
                else
                    {
                        if(Vide(&p)!=0)
                            {
                                depiler(&p);
                                fsetpos(F,&p.premier->pos);

                            }
                        else
                            rewind(F);

                    }
                while(adrrect.y + 27 < 464 && !feof(F))
                {fscanf(F,"%s ; %s ; %s ; %s ; %s ; %s ; %s ",&etud.CIN,&etud.nom ,&etud.prenom,&etud.DateNaissance,&etud.adress,&etud.clas,&etud.filiere) ;
                if(strcmp(option , etud.nom) == 0)
                {afficherTexte(renderer, etud.nom, pFont, nomrect.x, nomrect.y, 0, 0, 0);
                afficherTexte(renderer, etud.prenom, pFont, prenomrect.x, prenomrect.y, 0, 0, 0);
                afficherTexte(renderer, etud.CIN, pFont, cinrect.x, cinrect.y, 0, 0, 0);
                afficherTexte(renderer, etud.DateNaissance, pFont, naisrect.x, naisrect.y, 0, 0, 0);
                afficherTexte(renderer, etud.adress, pFont, adrrect.x, adrrect.y, 0, 0, 0);
                afficherTexte(renderer, etud.clas, pFont, clasrect.x, clasrect.y, 0, 0, 0);
                afficherTexte(renderer, etud.filiere, pFont, filiererect.x, filiererect.y, 0, 0, 0);

                 nomrect.y += 27;
                 prenomrect.y += 27;
                 cinrect.y += 27;
                 naisrect.y += 27;
                 adrrect.y += 27;
                 clasrect.y += 27;
                 filiererect.y += 27;
                 }
                }
                      nomrect.y = 128; prenomrect.y = 128; cinrect.y = 128; naisrect.y = 128; adrrect.y = 128; clasrect.y = 128; filiererect.y = 128;
                      while(cont)
                      {
                          SDL_Event ev;
                          SDL_WaitEvent(&ev);
                          switch(ev.type)
                          {
                      case SDL_KEYDOWN :
                        switch (ev.key.keysym.sym)
                        {
                                case SDLK_ESCAPE :
                                cont = 0;
                                pcontinue = 0;
                                break;
                                case SDLK_UP :
                                          j = 1;
                                          i=1;
                                          SDL_PushEvent(&Affichevent);
                                        cont = 0;
                                        break;
                                    case SDLK_DOWN :
                                          if(!feof(F))
                                          {
                                              fgetpos(F,&pos);
                                              empiler(&p);
                                              fgetpos(F,&p.premier->pos);
                                              i=1;
                                              j=0;
                                          }
                                          SDL_PushEvent(&Affichevent);
                                        cont = 0;
                                        break;
                        }
                      case SDL_MOUSEBUTTONUP :
                        if ( ( ev.button.x > retourrect.x ) && ( ev.button.x < retourrect.x + retourrect.w ) && ( ev.button.y > retourrect.y ) && ( ev.button.y < retourrect.y + retourrect.h ) )
                        {
                             i=0; j=0;
                            pcontinue = 0;
                            cont = 0 ;
                            break;
                        }
                        if ( ( ev.button.x > tousrect.x ) && ( ev.button.x < tousrect.x + tousrect.w ) && ( ev.button.y > tousrect.y ) && ( ev.button.y < tousrect.y + tousrect.h ) )
                        {
                             i=0; j=0;
                            cont = 0 ;
                            SDL_PushEvent(&ev);
                            break;
                        }
                        if ( ( ev.button.x > classbuttonrect.x ) && ( ev.button.x < classbuttonrect.x + classbuttonrect.w ) && ( ev.button.y > classbuttonrect.y ) && ( ev.button.y < classbuttonrect.y + classbuttonrect.h ) )
                        {
                             i=0; j=0;
                            cont = 0 ;
                            SDL_PushEvent(&ev);
                            break;
                        }
                        if ( ( ev.button.x > filierebuttonrect.x ) && ( ev.button.x < filierebuttonrect.x + filierebuttonrect.w ) && ( ev.button.y > filierebuttonrect.y ) && ( ev.button.y < filierebuttonrect.y + filierebuttonrect.h ) )
                        {
                             i=0; j=0;
                            cont = 0 ;
                            SDL_PushEvent(&ev);
                            break;
                        }
                    if ( ( ev.button.x > nombuttonrect.x ) && ( ev.button.x < nombuttonrect.x + nombuttonrect.w ) && ( ev.button.y > nombuttonrect.y ) && ( ev.button.y < nombuttonrect.y + nombuttonrect.h ) )
                        {
                             i=0; j=0;
                            cont = 0 ;
                            SDL_PushEvent(&ev);
                            break;
                        }
                      default :
                            SDL_Delay(1);
                          }
                      }
                      cont = 1 ;

            fclose(F);
                            break;
                        }
                    if ( ( Affichevent.button.x > retourrect.x ) && ( Affichevent.button.x < retourrect.x + retourrect.w ) && ( Affichevent.button.y > retourrect.y ) && ( Affichevent.button.y < retourrect.y + retourrect.h ) )
                        pcontinue = 0;
                    }
        if (pcontinue)
        {
            if (bgTexture)
                SDL_RenderCopy(renderer, bgTexture, NULL, NULL);
            else
                SDL_RenderClear(renderer);


            SDL_RenderPresent(renderer);
        }
    }
    SDL_DestroyWindow(AffichEtud);
    return 0 ;
}
