
#include "function.h"
#include "modifier.h"
#include "textedition.h"

int Modifetud(char *CIN1)
{
    char clas[5] , filiere[10] , jour[4] , mois[4] , ans[3] ;
    int textii1 = 0 , textii2 = 0 , textii3 = 0 , erreur = 0 , annul = 0;
    int textisid = 0 , textilsi = 0 , textii = 0 , textif = 0 , textrsr = 0 , textsle = 0;
    etudiant etud;
    FILE* F;
    FILE* FW;
    F=fopen("./data/etudiants.txt","r");
    FW=fopen("./data/etudiants.txt.tmp","w");
   do
    {
        fscanf(F,"%s ; %s ; %s ; %d/%d/%d ; %s ; %s ; %s ",&etud.CIN,&etud.nom ,&etud.prenom,&etud.DateNaissance.j,&etud.DateNaissance.m,&etud.DateNaissance.a,&etud.adress,&etud.clas,&etud.filiere) ;
        if(strcmp(etud.CIN,CIN1)!=0)
            fprintf(FW,"%s ; %s ; %s ; %d/%d/%d ; %s ; %s ; %s \n",etud.CIN,etud.nom ,etud.prenom,etud.DateNaissance.j,etud.DateNaissance.m,etud.DateNaissance.a,etud.adress,etud.clas,etud.filiere) ;
        else
            {
                itoa(  etud.DateNaissance.a, ans, 10);
                itoa(  etud.DateNaissance.j, jour, 10);
                itoa(  etud.DateNaissance.m, mois, 10);
                strncpy(clas , etud.clas , 3); strcpy(filiere , etud.filiere);
//------------------------------------------------------
TextEdition nom , prenom , CIN , j , m , a , ville , ii1 , ii2 , ii3;
    SDL_Rect nompos , prenompos , pos, cinpos , jpos , mpos , apos, villepos , ii1pos , ii2pos , ii3pos , ii1rect , ii2rect ;
    SDL_Rect ii3rect , isidrect , ilsirect , iirect , ifrect , rsrrect , slerect , enregrect , erreurrect , annuler;
    TTF_Font *font , *font1;
    SDL_Color color , color1 , color2;

    SDL_Window *screen;
    SDL_Renderer *renderer;
    SDL_Texture *bgTexture;
    SDL_Texture *bgTexture1;
    SDL_Texture *iconetexture , *bgerreur , *bgexiste;
    SDL_Surface *pFontSurface , *pFonterreur , *pFontnexiste;
    SDL_Event event;
    int done = 0;
if ( SDL_CreateWindowAndRenderer(758, 686, 0, &screen, &renderer) == -1)
    {
        fprintf(stderr, "Unable to set 640x480 video: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }
    // Création de la fenêtre :
    SDL_SetWindowTitle(screen, "Ajouter un etudiant ");//titre
    font1 = TTF_OpenFont("./data/font.ttf", 20);

    color1.r = 122; color1.g = 55; color1.b = 139;
    color2.r = 139; color2.g = 26; color2.b = 26;
    pFontSurface = TTF_RenderText_Solid(font1,"Entrer les donner de l'etudiant a enregistrer",color1);
    pFonterreur = TTF_RenderText_Solid(font1,"ERREUR : les donner a enregistrer sont fausse",color2);
    pFontnexiste = TTF_RenderText_Solid(font1,"Vous n'avez pas changer le CIN",color2);
    bgTexture1 = SDL_CreateTextureFromSurface(renderer, pFontSurface); //image font
    bgerreur = SDL_CreateTextureFromSurface(renderer, pFonterreur); //image font
    bgexiste = SDL_CreateTextureFromSurface(renderer, pFontnexiste); //image font
    SDL_FreeSurface(pFontSurface);
    SDL_FreeSurface(pFonterreur);
    SDL_FreeSurface(pFontnexiste);

    bgTexture = IMG_LoadTexture(renderer, "./data/ImageFond.jpg"); //image font
    iconetexture = IMG_LoadTexture(renderer, "./data/icone.jpg");

    pos.x = 67; pos.y = 21; pos.w = 608; pos.h = 68;
    nompos.x = 314; nompos.y = 109; nompos.w = 242; nompos.h = 16;
    prenompos.x = 314; prenompos.y = 139; prenompos.w = 243; prenompos.h = 18;
    cinpos.x = 314; cinpos.y = 169; cinpos.w = 240; cinpos.h = 17;
    jpos.x = 328; jpos.y = 201; jpos.w = 26; jpos.h = 24;
    mpos.x = 393; mpos.y = 201; mpos.w = 28; mpos.h = 24;
    apos.x = 456; apos.y = 201; apos.w = 56; apos.h = 24;
    villepos.x = 317; villepos.y = 239; villepos.w = 239; villepos.h = 20;
    ii1pos.x = 301; ii1pos.y = 280; ii1pos.w = 40; ii1pos.h = 31;
    ii2pos.x = 301; ii2pos.y = 315; ii2pos.w = 40; ii2pos.h = 31;
    ii3pos.x = 301; ii3pos.y = 349; ii3pos.w = 40; ii3pos.h = 31;
    ii1rect.x = 392; ii1rect.y = 283; ii1rect.w = 20; ii1rect.h = 28;
    ii2rect.x = 392; ii2rect.y = 317; ii2rect.w = 20; ii2rect.h = 28;
    ii3rect.x = 392; ii3rect.y = 352; ii3rect.w = 20; ii3rect.h = 28;
    isidrect.x = 301; isidrect.y = 401; isidrect.w = 40; isidrect.h = 31;
    ilsirect.x = 301; ilsirect.y = 436; ilsirect.w = 40; ilsirect.h = 31;
    iirect.x = 301; iirect.y = 471; iirect.w = 40; iirect.h = 31;
    ifrect.x = 301; ifrect.y = 506; ifrect.w = 40; ifrect.h = 31;
    rsrrect.x = 301; rsrrect.y = 541; rsrrect.w = 40; rsrrect.h = 31;
    slerect.x = 301; slerect.y = 577; slerect.w = 40; slerect.h = 31;
    enregrect.x = 363; enregrect.y = 619; enregrect.w = 189; enregrect.h = 60;
    erreurrect.x = 6; erreurrect.y = 625; erreurrect.w = 341; erreurrect.h = 57;
    annuler.x = 565; annuler.y = 618; annuler.w = 179; annuler.h = 63;


    font = TTF_OpenFont("./data/default.ttf", 10);
    color.r = 0; color.g = 0; color.b = 0;

    memset(&nom, 0, sizeof(TextEdition));
    memset(&prenom, 0, sizeof(TextEdition));
    memset(&CIN, 0, sizeof(TextEdition));
    memset(&j, 0, sizeof(TextEdition));
    memset(&m, 0, sizeof(TextEdition));
    memset(&a, 0, sizeof(TextEdition));
    memset(&ville, 0, sizeof(TextEdition));
    memset(&ii1, 0, sizeof(TextEdition));
    memset(&ii2, 0, sizeof(TextEdition));
    memset(&ii3, 0, sizeof(TextEdition));

    nom.blitStyle = TE_BLITSTYLE_BLENDED;
    prenom.blitStyle = TE_BLITSTYLE_BLENDED;
    CIN.blitStyle = TE_BLITSTYLE_BLENDED;
    j.blitStyle = TE_BLITSTYLE_BLENDED;
    m.blitStyle = TE_BLITSTYLE_BLENDED;
    a.blitStyle = TE_BLITSTYLE_BLENDED;
    ville.blitStyle = TE_BLITSTYLE_BLENDED;
    ii1.blitStyle = TE_BLITSTYLE_BLENDED;
    ii2.blitStyle = TE_BLITSTYLE_BLENDED;
    ii3.blitStyle = TE_BLITSTYLE_BLENDED;
    nom.colorBG = color;

    TE_NewTextEdition(&nom, 10, nompos, font, color, TE_STYLE_NORMAL | TE_STYLE_BLITRGBA, renderer); TE_SetEditionText(&nom,etud.nom);
    TE_NewTextEdition(&prenom, 15, prenompos, font, color, TE_STYLE_NORMAL | TE_STYLE_BLITRGBA, renderer); TE_SetEditionText(&prenom,etud.prenom);
    TE_NewTextEdition(&CIN, 9, cinpos, font, color, TE_STYLE_NORMAL | TE_STYLE_BLITRGBA, renderer); TE_SetEditionText(&CIN,etud.CIN);
    TE_NewTextEdition(&j, 3, jpos, font, color, TE_STYLE_NORMAL | TE_STYLE_BLITRGBA, renderer); TE_SetEditionText(&j,jour);
    TE_NewTextEdition(&m, 3, mpos, font, color, TE_STYLE_NORMAL | TE_STYLE_BLITRGBA, renderer); TE_SetEditionText(&m,mois);
    TE_NewTextEdition(&a, 5, apos, font, color, TE_STYLE_NORMAL | TE_STYLE_BLITRGBA, renderer); TE_SetEditionText(&a,ans);
    TE_NewTextEdition(&ville, 50, villepos, font, color, TE_STYLE_NORMAL | TE_STYLE_BLITRGBA, renderer); TE_SetEditionText(&ville,etud.adress);
    TE_NewTextEdition(&ii1, 2, ii1rect, font, color, TE_STYLE_NORMAL | TE_STYLE_BLITRGBA, renderer); TE_SetEditionText(&ii1,"");
    TE_NewTextEdition(&ii2, 2, ii2rect, font, color, TE_STYLE_NORMAL | TE_STYLE_BLITRGBA, renderer); TE_SetEditionText(&ii2,"");
    TE_NewTextEdition(&ii3, 2, ii3rect, font, color, TE_STYLE_NORMAL | TE_STYLE_BLITRGBA, renderer); TE_SetEditionText(&ii3,"");


    if(strcmp(clas,"II1") == 0)
        {textii1=1; textii2=0; textii3=0;}
    if(strcmp(clas,"II2") == 0)
        {textii1=0; textii2=1; textii3=0;}
    if(strcmp(clas,"II3") == 0)
        {textii1=0; textii2=0; textii3=1;}
    if(strcmp(etud.filiere,"ISID") == 0)
         {textisid=1; textilsi=0 ;textii=0; textif=0; textrsr=0 ;textsle=0;}
    if(strcmp(etud.filiere,"ILSI") == 0)
         {textisid=0; textilsi=1 ;textii=0; textif=0; textrsr=0 ;textsle=0;}
    if(strcmp(etud.filiere,"II") == 0)
         {textisid=0; textilsi=0 ;textii=1; textif=0; textrsr=0 ;textsle=0;}
    if(strcmp(etud.filiere,"IF") == 0)
         {textisid=0; textilsi=0 ;textii=0; textif=1; textrsr=0 ;textsle=0;}
    if(strcmp(etud.filiere,"RSR") == 0)
         {textisid=0; textilsi=0 ;textii=0; textif=0; textrsr=1 ;textsle=0;}
    if(strcmp(etud.filiere,"SLE") == 0)
         {textisid=0; textilsi=0 ;textii=0; textif=0; textrsr=0 ;textsle=1;}

    while (!done)
    {

        SDL_WaitEvent(&event);
        switch (event.type)
        {
            case SDL_QUIT:
                {done = 1;
                annul = 1 ;
                break;}
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE)
                    {SDL_DestroyWindow(screen);
                      done = 1 ;
                      annul = 1 ;
                     }
                break;
                case SDL_MOUSEBUTTONUP :
            //II1
            if ( ( event.button.x > ii1pos.x ) && ( event.button.x < ii1pos.x + ii1pos.w ) && ( event.button.y > ii1pos.y ) && ( event.button.y < ii1pos.y + ii1pos.h ) )
                {textii1=1; textii2=0 ;textii3=0;
                break;}
            //II2
            if ( ( event.button.x > ii2pos.x ) && ( event.button.x < ii2pos.x + ii2pos.w ) && ( event.button.y > ii2pos.y ) && ( event.button.y < ii2pos.y + ii2pos.h ) )
                { textii1=0; textii2=1; textii3=0;
                break;}
            //II3
            if ( ( event.button.x > ii3pos.x ) && ( event.button.x < ii3pos.x + ii3pos.w ) && ( event.button.y > ii3pos.y ) && ( event.button.y < ii3pos.y + ii3pos.h ) )
                {textii2=0; textii1=0; textii3=1;
                break;}
            //ISID
            if ( ( event.button.x > isidrect.x ) && ( event.button.x < isidrect.x + isidrect.w ) && ( event.button.y > isidrect.y ) && ( event.button.y < isidrect.y + isidrect.h ) )
                {textisid=1; textilsi=0 ;textii=0; textif=0; textrsr=0 ;textsle=0;
                break;}
            //ILSI
            if ( ( event.button.x > ilsirect.x ) && ( event.button.x < ilsirect.x + ilsirect.w ) && ( event.button.y > ilsirect.y ) && ( event.button.y < ilsirect.y + ilsirect.h ) )
                {textisid=0; textilsi=1 ;textii=0; textif=0; textrsr=0 ;textsle=0;
                break;}
            //II
            if ( ( event.button.x > iirect.x ) && ( event.button.x < iirect.x + iirect.w ) && ( event.button.y > iirect.y ) && ( event.button.y < iirect.y + iirect.h ) )
                {textisid=0; textilsi=0 ;textii=1; textif=0; textrsr=0 ;textsle=0;
                break;}
            //IF
            if ( ( event.button.x > ifrect.x ) && ( event.button.x < ifrect.x + ifrect.w ) && ( event.button.y > ifrect.y ) && ( event.button.y < ifrect.y + ifrect.h ) )
                {textisid=0; textilsi=0 ;textii=0; textif=1; textrsr=0 ;textsle=0;
                break;}
            //RSR
            if ( ( event.button.x > rsrrect.x ) && ( event.button.x < rsrrect.x + rsrrect.w ) && ( event.button.y > rsrrect.y ) && ( event.button.y < rsrrect.y + rsrrect.h ) )
                {textisid=0; textilsi=0 ;textii=0; textif=0; textrsr=1 ;textsle=0;
                break;}
            //SLE
            if ( ( event.button.x > slerect.x ) && ( event.button.x < slerect.x + slerect.w ) && ( event.button.y > slerect.y ) && ( event.button.y < slerect.y + slerect.h ) )
                {textisid=0; textilsi=0 ;textii=0; textif=0; textrsr=0 ;textsle=1;
                break; }
               //enregistrer
                if ( ( event.button.x > enregrect.x ) && ( event.button.x < enregrect.x + enregrect.w ) && ( event.button.y > enregrect.y ) && ( event.button.y < enregrect.y + enregrect.h ) )
                { erreur = enregistest(CIN1 ,nom.text , prenom.text , CIN.text , j.text , m.text , a.text , ville.text , clas , filiere);
                    if( erreur == 0 )
                        {
                            strcpy(etud.nom,nom.text); strcpy(etud.prenom,prenom.text); strcpy(etud.CIN,CIN.text); strcpy(etud.adress,ville.text);
                            etud.DateNaissance.j=atoi(j.text); etud.DateNaissance.m=atoi(m.text); etud.DateNaissance.a=atoi(a.text);
                            strcpy(etud.clas , clas); strcpy(etud.filiere , filiere) ;
                            SDL_DestroyWindow(screen);
                            done = 1 ;

                        }
                break;
                }
                //annuler
                if ( ( event.button.x > annuler.x ) && ( event.button.x < annuler.x + annuler.w ) && ( event.button.y > annuler.y ) && ( event.button.y < annuler.y + annuler.h ) )
                    {SDL_DestroyWindow(screen);
                     done = 1 ;
                     annul = 1 ;
                    break;
                    }
            default:
                break;
        }
    if (!done)
        {
            //bachround
            if (bgTexture)
                SDL_RenderCopy(renderer, bgTexture, NULL, NULL);
            else
                SDL_RenderClear(renderer);
            //titre du page
                if (bgTexture1)
                SDL_RenderCopy(renderer, bgTexture1, NULL, &pos);
            else
                SDL_RenderClear(renderer);

            //II1
            if(textii1 == 1)
                {if (iconetexture)
                {
                 SDL_RenderCopy(renderer, iconetexture, NULL, &ii1pos);
                 TE_HoldTextEdition(&ii1, event);
                 TE_DisplayTextEdition(&ii1);
                 strcpy(clas , "II1"); strcat(clas , ii1.text);
                }
            else
                SDL_RenderClear(renderer);
                }
                //II2
                if(textii2 == 1)
                {if (iconetexture)
                {
                 SDL_RenderCopy(renderer, iconetexture, NULL, &ii2pos);
                 TE_HoldTextEdition(&ii2, event);
                 TE_DisplayTextEdition(&ii2);
                 strcpy(clas ,"II2"); strcat(clas , ii2.text);
                }
            else
                SDL_RenderClear(renderer);
                }
                //II3
                if(textii3 == 1 )
                {if (iconetexture)
                {
                 SDL_RenderCopy(renderer, iconetexture, NULL, &ii3pos);
                 TE_HoldTextEdition(&ii3, event);
                 TE_DisplayTextEdition(&ii3);
                 strcpy(clas ,"II3"); strcat(clas , ii3.text);
                }
            else
                SDL_RenderClear(renderer);
                }
               //ISID
                if(textisid == 1 && textii1 == 0)
                {
            if (iconetexture)
                {SDL_RenderCopy(renderer, iconetexture, NULL, &isidrect);
                strcpy(filiere,"ISID");}
            else
                SDL_RenderClear(renderer);}
            //ILSI
            if(textilsi == 1 && textii1 == 0)
              {if (iconetexture)
                {SDL_RenderCopy(renderer, iconetexture, NULL, &ilsirect);
                strcpy(filiere,"ILSI");}
            else
                SDL_RenderClear(renderer);}
            //II
            if(textii == 1 && textii1 == 0)
              {if (iconetexture)
                {SDL_RenderCopy(renderer, iconetexture, NULL, &iirect);
                strcpy(filiere,"II");}
            else
                SDL_RenderClear(renderer);}
            //IF
            if(textif == 1 && textii1 == 0)
              {if (bgTexture1)
                {SDL_RenderCopy(renderer, iconetexture, NULL, &ifrect);
                strcpy(filiere,"IF");}
            else
                SDL_RenderClear(renderer);}
            // RSR
            if(textrsr == 1 && textii1 == 0)
            {if (iconetexture)
                {SDL_RenderCopy(renderer, iconetexture, NULL, &rsrrect);
                strcpy(filiere,"RSR");}
            else
                SDL_RenderClear(renderer);}
            // SLE
            if(textsle == 1 && textii1 == 0)
            {if (bgTexture1)
                {SDL_RenderCopy(renderer, iconetexture, NULL, &slerect);
                strcpy(filiere,"SLE");}
            else
                SDL_RenderClear(renderer);}
             //erreur
             if( erreur != 0 && erreur != 8 )
                {
                   if (bgerreur)
                SDL_RenderCopy(renderer, bgerreur, NULL, &erreurrect);
            else
                SDL_RenderClear(renderer);
                }
                if( erreur == 8 )
                {
                   if (bgexiste)
                SDL_RenderCopy(renderer, bgexiste, NULL, &erreurrect);
            else
                SDL_RenderClear(renderer);
                }


            TE_HoldTextEdition(&nom, event); TE_DisplayTextEdition(&nom); TE_HoldTextEdition(&prenom, event);
            TE_DisplayTextEdition(&prenom); TE_HoldTextEdition(&CIN, event); TE_DisplayTextEdition(&CIN);
            TE_HoldTextEdition(&j, event); TE_DisplayTextEdition(&j); TE_HoldTextEdition(&m, event);
            TE_DisplayTextEdition(&m); TE_HoldTextEdition(&a, event); TE_DisplayTextEdition(&a);
            TE_HoldTextEdition(&ville, event); TE_DisplayTextEdition(&ville);
            SDL_RenderPresent(renderer);
        }
    }
TE_DeleteTextEdition(&nom);
    TE_DeleteTextEdition(&prenom);
    TE_DeleteTextEdition(&CIN);
    TE_DeleteTextEdition(&j);
    TE_DeleteTextEdition(&m);
    TE_DeleteTextEdition(&a);
    TE_DeleteTextEdition(&ville);
    TE_DeleteTextEdition(&ii1);
    TE_DeleteTextEdition(&ii2);
    TE_DeleteTextEdition(&ii3);
    TE_Quit();
    TTF_CloseFont(font);
//------------------------------------------------------
              fprintf(FW,"%s ; %s ; %s ; %d/%d/%d ; %s ; %s ; %s \n",etud.CIN,etud.nom ,etud.prenom,etud.DateNaissance.j,etud.DateNaissance.m,etud.DateNaissance.a,etud.adress ,etud.clas ,etud.filiere) ;

            }
    }while(!feof(F));
    fclose(F);
    fclose(FW);
    /*remove("C:\\etudiants.txt");
    rename("C:\\etudiants.txt.tmp","C:\\etudiants.txt");
    remove("C:\\etudiants.txt.tmp");*/
    if(erreur == 0 && annul == 0 && remove("./data/etudiants.txt")==0)
        {
            rename("./data/etudiants.txt.tmp","./data/etudiants.txt");
            remove("./data/etudiants.txt.tmp");
            succeswindow();
        }
    else
       {
           probwindow();
           remove("./data/etudiants.txt.tmp");
           perror(remove);
       }
    return 0;
}
void Modifwindow()
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

    SDL_SetWindowTitle(screen, "Modifier un etudiant");
    titre = TTF_RenderText_Solid(font1,"Entrer le CIN de l'etudiant a modifier",color1);
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
                           Modifetud(te.text);
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
