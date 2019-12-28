#include "function.h"
#include "textedition.h"
#include <SDL2/SDL.h>
#include "textedition.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

//les fonction du stocage du donnees
int EstVide(FILE* F)
{
    int caracterePremier = 0;
    //On lit le prmeier caractère du fichier
    caracterePremier = fgetc(F);
    if(caracterePremier==EOF)
    {
        return 1;//le fichier est vide donc on retourne 1
    }
    return 0;//le fichier n'est pas vide donc on retourne 0
}
int SupprimerToutEtudiants()
{
     FILE* F;
     F=fopen("./data/etudiants.txt","r");
     if(F == NULL || EstVide(F)==1)
        return 1;
     else
        {
            fclose(F);
            F=fopen("./data/etudiants.txt","w");
            fclose(F);
        }

     return 0;
}
int reglefich()
{
    int i = 1 , j = 1;
    i = remove("./data/etudiants.txt");
    j = rename("./data/etudiants.txt.tmp","./data/etudiants.txt");
    if(i == 0 && j == 0)
        return 0;
    else
        return 1 ;
}
//les fonctions graphique
int probwindow()
{
   const unsigned int windowWidth = 480;
   const unsigned int windowHeight = 150;
   char pcontinue = 1 ;

   SDL_Window* defaulwindow = NULL;
   SDL_Surface* background;
   SDL_Surface* OKimage;
   SDL_Rect backgroundRect ,OKimageRect ;
   TTF_Font* pFont = NULL;
   const char* fontPath = "./data/font.ttf";
   const char* imagePath = "./data/logo1.jpg";
   const char* imagePath1 = "./data/OuiNon.jpg";
   SDL_Color fontColor = {0, 0, 0};
   SDL_Surface* Fontdefaul;
   SDL_Surface* Fontok;
   SDL_Rect FontdefaulRect ,FontokRect ;

   defaulwindow =SDL_CreateWindow("default d'operation  ",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,
                                                              480,
                                                              150,
                                                              SDL_WINDOW_SHOWN);
   if( defaulwindow != NULL )
   {
       background = IMG_Load(imagePath);
       if ( background == NULL )
        {
            fprintf(stderr,"Erreur de chargement de l'image %s : %s\n",imagePath,IMG_GetError());
            SDL_DestroyWindow(defaulwindow);
            return -3;
        }
        OKimage = IMG_Load(imagePath1);
       if ( OKimage == NULL )
        {
            fprintf(stderr,"Erreur de chargement de l'image %s : %s\n",imagePath1,IMG_GetError());
            SDL_DestroyWindow(defaulwindow);
            return -3;
        }
        pFont = TTF_OpenFont(fontPath,25);
        if ( pFont == NULL )
        {
            fprintf(stderr,"Erreur de chargement de la police %s : %s\n",fontPath,TTF_GetError());
            SDL_DestroyWindow(defaulwindow);
            return -3;
        }
        Fontdefaul = TTF_RenderText_Solid(pFont,"problem lors de l'operation ",fontColor);
        if ( !Fontdefaul )
        {
            fprintf(stderr,"Erreur pour generer le texte '%s'\n",TTF_GetError());
            SDL_DestroyWindow(defaulwindow);
            return -4;
        }
        Fontok = TTF_RenderText_Solid(pFont," OK ",fontColor);
        if ( !Fontok )
        {
            fprintf(stderr,"Erreur pour generer le texte '%s'\n",TTF_GetError());
            SDL_DestroyWindow(defaulwindow);
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
        OKimageRect.x = windowWidth/2 - OKimage->w/2;
        OKimageRect.y = 3*windowHeight/4 - OKimage->h/2;
        OKimageRect.w = OKimage->w;
        OKimageRect.h = OKimage->h;
        // Une fois l'image chargée, nous pouvons calculer une position relative à celle-ci
        // Nous centrons l'image dans la fenêtre
        FontdefaulRect.x = windowWidth/2 - Fontdefaul->w/2;
        FontdefaulRect.y = windowHeight/4 - Fontdefaul->h/2;
        FontdefaulRect.w = Fontdefaul->w;
        FontdefaulRect.h = Fontdefaul->h;
        // Une fois l'image chargée, nous pouvons calculer une position relative à celle-ci
        // Nous centrons l'image dans la fenêtre
        FontokRect.x = windowWidth/2 - Fontok->w/2;
        FontokRect.y = 3*windowHeight/4 - Fontok->h/2;
        FontokRect.w = Fontok->w;
        FontokRect.h = Fontok->h;
       while(pcontinue)
       {
           if ( SDL_BlitSurface(background,NULL,SDL_GetWindowSurface(defaulwindow),&backgroundRect) != 0 )
            {
                fprintf(stderr,"Erreur de copie de la surface sur l'écran\n");
                pcontinue=0;
            }
            if ( SDL_BlitSurface(OKimage,NULL,SDL_GetWindowSurface(defaulwindow),&OKimageRect) != 0 )
            {
                fprintf(stderr,"Erreur de copie de la surface sur l'écran\n");
                pcontinue=0;
            }
            if ( SDL_BlitSurface(Fontdefaul,NULL,SDL_GetWindowSurface(defaulwindow),&FontdefaulRect) != 0 )
            {
                fprintf(stderr,"Erreur de copie du texte sur l'écran\n");
                pcontinue=0;
            }
            if ( SDL_BlitSurface(Fontok,NULL,SDL_GetWindowSurface(defaulwindow),&FontokRect) != 0 )
            {
                fprintf(stderr,"Erreur de copie du texte sur l'écran\n");
                pcontinue=0;
            }
           SDL_UpdateWindowSurface(defaulwindow);
           SDL_Event defaulevent;
            SDL_WaitEvent(&defaulevent);
            switch(defaulevent.type)
            {
                case SDL_QUIT :
                    pcontinue =0;
                    return 2 ;
                case SDL_KEYDOWN :
                    switch (defaulevent.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            pcontinue = 0;
                            break;
                    }
                 case SDL_MOUSEBUTTONUP :
                    if ( ( defaulevent.button.x > FontokRect.x ) && ( defaulevent.button.x < FontokRect.x + FontokRect.w ) && ( defaulevent.button.y > FontokRect.y ) && ( defaulevent.button.y < FontokRect.y + FontokRect.h ) )
                        pcontinue = 0;
            }
        }
    SDL_DestroyWindow(defaulwindow);
    }
    else
    {
        fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
        return 1;
    }
    return 0 ;
}
int defaultwindow()
{
    const unsigned int windowWidth = 480;
   const unsigned int windowHeight = 150;
   char pcontinue = 1 ;

   SDL_Window* defaulwindow = NULL;
   SDL_Surface* background;
   SDL_Surface* OKimage;
   SDL_Rect backgroundRect ,OKimageRect ;
   TTF_Font* pFont = NULL;
   const char* fontPath = "./data/font.ttf";
   const char* imagePath = "./data/logo1.jpg";
   const char* imagePath1 = "./data/OuiNon.jpg";
   SDL_Color fontColor = {0, 0, 0};
   SDL_Surface* Fontdefaul;
   SDL_Surface* Fontok;
   SDL_Rect FontdefaulRect ,FontokRect ;

   defaulwindow =SDL_CreateWindow("default de l'operation  ",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,
                                                              480,
                                                              150,
                                                              SDL_WINDOW_SHOWN);
   if( defaulwindow != NULL )
   {
       background = IMG_Load(imagePath);
       if ( background == NULL )
        {
            fprintf(stderr,"Erreur de chargement de l'image %s : %s\n",imagePath,IMG_GetError());
            SDL_DestroyWindow(defaulwindow);
            return -3;
        }
        OKimage = IMG_Load(imagePath1);
       if ( OKimage == NULL )
        {
            fprintf(stderr,"Erreur de chargement de l'image %s : %s\n",imagePath1,IMG_GetError());
            SDL_DestroyWindow(defaulwindow);
            return -3;
        }
        pFont = TTF_OpenFont(fontPath,25);
        if ( pFont == NULL )
        {
            fprintf(stderr,"Erreur de chargement de la police %s : %s\n",fontPath,TTF_GetError());
            SDL_DestroyWindow(defaulwindow);
            return -3;
        }
        Fontdefaul = TTF_RenderText_Solid(pFont,"il n y a auccun etudiant ",fontColor);
        if ( !Fontdefaul )
        {
            fprintf(stderr,"Erreur pour generer le texte '%s'\n",TTF_GetError());
            SDL_DestroyWindow(defaulwindow);
            return -4;
        }
        Fontok = TTF_RenderText_Solid(pFont," OK ",fontColor);
        if ( !Fontok )
        {
            fprintf(stderr,"Erreur pour generer le texte '%s'\n",TTF_GetError());
            SDL_DestroyWindow(defaulwindow);
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
        OKimageRect.x = windowWidth/2 - OKimage->w/2;
        OKimageRect.y = 3*windowHeight/4 - OKimage->h/2;
        OKimageRect.w = OKimage->w;
        OKimageRect.h = OKimage->h;
        // Une fois l'image chargée, nous pouvons calculer une position relative à celle-ci
        // Nous centrons l'image dans la fenêtre
        FontdefaulRect.x = windowWidth/2 - Fontdefaul->w/2;
        FontdefaulRect.y = windowHeight/4 - Fontdefaul->h/2;
        FontdefaulRect.w = Fontdefaul->w;
        FontdefaulRect.h = Fontdefaul->h;
        // Une fois l'image chargée, nous pouvons calculer une position relative à celle-ci
        // Nous centrons l'image dans la fenêtre
        FontokRect.x = windowWidth/2 - Fontok->w/2;
        FontokRect.y = 3*windowHeight/4 - Fontok->h/2;
        FontokRect.w = Fontok->w;
        FontokRect.h = Fontok->h;
       while(pcontinue)
       {
           if ( SDL_BlitSurface(background,NULL,SDL_GetWindowSurface(defaulwindow),&backgroundRect) != 0 )
            {
                fprintf(stderr,"Erreur de copie de la surface sur l'écran\n");
                pcontinue=0;
            }
            if ( SDL_BlitSurface(OKimage,NULL,SDL_GetWindowSurface(defaulwindow),&OKimageRect) != 0 )
            {
                fprintf(stderr,"Erreur de copie de la surface sur l'écran\n");
                pcontinue=0;
            }
            if ( SDL_BlitSurface(Fontdefaul,NULL,SDL_GetWindowSurface(defaulwindow),&FontdefaulRect) != 0 )
            {
                fprintf(stderr,"Erreur de copie du texte sur l'écran\n");
                pcontinue=0;
            }
            if ( SDL_BlitSurface(Fontok,NULL,SDL_GetWindowSurface(defaulwindow),&FontokRect) != 0 )
            {
                fprintf(stderr,"Erreur de copie du texte sur l'écran\n");
                pcontinue=0;
            }
           SDL_UpdateWindowSurface(defaulwindow);
           SDL_Event defaulevent;
            SDL_WaitEvent(&defaulevent);
            switch(defaulevent.type)
            {
                case SDL_QUIT :
                    pcontinue =0;
                    return 2 ;
                case SDL_KEYDOWN :
                    switch (defaulevent.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            pcontinue = 0;
                            break;
                    }
                 case SDL_MOUSEBUTTONUP :
                    if ( ( defaulevent.button.x > FontokRect.x ) && ( defaulevent.button.x < FontokRect.x + FontokRect.w ) && ( defaulevent.button.y > FontokRect.y ) && ( defaulevent.button.y < FontokRect.y + FontokRect.h ) )
                        pcontinue = 0;
            }
        }
    SDL_DestroyWindow(defaulwindow);
    }
    else
    {
        fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
        return 1;
    }
    return 0 ;
}
int succeswindow()
{
   const unsigned int windowWidth = 480;
   const unsigned int windowHeight = 150;
   char pcontinue = 1 ;

   SDL_Window* succeswindow = NULL;
   SDL_Surface* background;
   SDL_Surface* OKimage;
   SDL_Rect backgroundRect ,OKimageRect ;
   TTF_Font* pFont = NULL;
   const char* fontPath = "./data/font.ttf";
   const char* imagePath = "./data/logo1.jpg";
   const char* imagePath1 = "./data/OuiNon.jpg";
   SDL_Color fontColor = {0, 0, 0};
   SDL_Surface* Fontsucces;
   SDL_Surface* Fontok;
   SDL_Rect FontsuccesRect ,FontokRect ;

   succeswindow =SDL_CreateWindow("Succes de l'operation  ",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,
                                                              480,
                                                              150,
                                                              SDL_WINDOW_SHOWN);
   if( succeswindow != NULL )
   {
       background = IMG_Load(imagePath);
       if ( background == NULL )
        {
            fprintf(stderr,"Erreur de chargement de l'image %s : %s\n",imagePath,IMG_GetError());
            SDL_DestroyWindow(succeswindow);
            return -3;
        }
        OKimage = IMG_Load(imagePath1);
       if ( OKimage == NULL )
        {
            fprintf(stderr,"Erreur de chargement de l'image %s : %s\n",imagePath1,IMG_GetError());
            SDL_DestroyWindow(succeswindow);
            return -3;
        }
        pFont = TTF_OpenFont(fontPath,25);
        if ( pFont == NULL )
        {
            fprintf(stderr,"Erreur de chargement de la police %s : %s\n",fontPath,TTF_GetError());
            SDL_DestroyWindow(succeswindow);
            return -3;
        }
        Fontsucces = TTF_RenderText_Solid(pFont,"L'operation fait avec succes",fontColor);
        if ( !Fontsucces )
        {
            fprintf(stderr,"Erreur pour generer le texte '%s'\n",TTF_GetError());
            SDL_DestroyWindow(succeswindow);
            return -4;
        }
        Fontok = TTF_RenderText_Solid(pFont," OK ",fontColor);
        if ( !Fontok )
        {
            fprintf(stderr,"Erreur pour generer le texte '%s'\n",TTF_GetError());
            SDL_DestroyWindow(succeswindow);
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
        OKimageRect.x = windowWidth/2 - OKimage->w/2;
        OKimageRect.y = 3*windowHeight/4 - OKimage->h/2;
        OKimageRect.w = OKimage->w;
        OKimageRect.h = OKimage->h;
        // Une fois l'image chargée, nous pouvons calculer une position relative à celle-ci
        // Nous centrons l'image dans la fenêtre
        FontsuccesRect.x = windowWidth/2 - Fontsucces->w/2;
        FontsuccesRect.y = windowHeight/4 - Fontsucces->h/2;
        FontsuccesRect.w = Fontsucces->w;
        FontsuccesRect.h = Fontsucces->h;
        // Une fois l'image chargée, nous pouvons calculer une position relative à celle-ci
        // Nous centrons l'image dans la fenêtre
        FontokRect.x = windowWidth/2 - Fontok->w/2;
        FontokRect.y = 3*windowHeight/4 - Fontok->h/2;
        FontokRect.w = Fontok->w;
        FontokRect.h = Fontok->h;
       while(pcontinue)
       {
           if ( SDL_BlitSurface(background,NULL,SDL_GetWindowSurface(succeswindow),&backgroundRect) != 0 )
            {
                fprintf(stderr,"Erreur de copie de la surface sur l'écran\n");
                pcontinue=0;
            }
            if ( SDL_BlitSurface(OKimage,NULL,SDL_GetWindowSurface(succeswindow),&OKimageRect) != 0 )
            {
                fprintf(stderr,"Erreur de copie de la surface sur l'écran\n");
                pcontinue=0;
            }
            if ( SDL_BlitSurface(Fontsucces,NULL,SDL_GetWindowSurface(succeswindow),&FontsuccesRect) != 0 )
            {
                fprintf(stderr,"Erreur de copie du texte sur l'écran\n");
                pcontinue=0;
            }
            if ( SDL_BlitSurface(Fontok,NULL,SDL_GetWindowSurface(succeswindow),&FontokRect) != 0 )
            {
                fprintf(stderr,"Erreur de copie du texte sur l'écran\n");
                pcontinue=0;
            }
           SDL_UpdateWindowSurface(succeswindow);
           SDL_Event seccesevent;
            SDL_WaitEvent(&seccesevent);
            switch(seccesevent.type)
            {
                case SDL_QUIT :
                    pcontinue =0;
                    return 2 ;
                case SDL_KEYDOWN :
                    switch (seccesevent.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            pcontinue = 0;
                            break;
                    }
                 case SDL_MOUSEBUTTONUP :
                    if ( ( seccesevent.button.x > FontokRect.x ) && ( seccesevent.button.x < FontokRect.x + FontokRect.w ) && ( seccesevent.button.y > FontokRect.y ) && ( seccesevent.button.y < FontokRect.y + FontokRect.h ) )
                        pcontinue = 0;
            }
        }
    SDL_DestroyWindow(succeswindow);
    }
    else
    {
        fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
        return 1;
    }
    return 0 ;
}
void cleanup()
{
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}
int cintest(char *CIN)
{
    int test = 0 ;
    if( atoi(CIN) == 0 || strlen(CIN)!= 8)
        test = 1 ;
    else
       {
          if( Est_Trouver(CIN) == 0 )
            test = 2 ;
        }
    return test ;
}
int Est_Trouver(char CIN[10])
{
    etudiant etud;
    FILE* F;
    F=fopen("./data/etudiants.txt","r");
    do
    {
       fscanf(F,"%s ; %s ; %s ; %d/%d/%d ; %s ; %s ; %s ",&etud.CIN,&etud.nom ,&etud.prenom,&etud.DateNaissance.j,&etud.DateNaissance.m,&etud.DateNaissance.a,&etud.adress,&etud.clas,&etud.filiere) ;
       if(strcmp(CIN,etud.CIN)==0)
       {
           fclose(F);
           return 1;
       }
    }while(!feof(F));
    fclose(F);
    return 0;
}
int bissextile (int a)
{
   if (a % 400 == 0)
        return 1;
   if (a % 100 ==0)
        return 0;
   if (a % 4 == 0)
        return 1;
   return 0;
}
int NaissanceVrais(int j,int m,int a)
{
    int valid = 1;
   int jour_mois[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
   if (bissextile(a)) {
      jour_mois[2] = 29;
   }
   if (m < 1 || m > 12) {
      valid = 0;
   } else if ( j < 1 || j > jour_mois[m] ) {
      valid = 0;
   }
   return valid;
}
 int enregistest(char* CIN1 ,char* nom ,char*  prenom ,char*  CIN ,char*  j ,char*  m ,char*  a ,char*  ville ,char*  clas ,char*  filiere )
{
    int test = 0 , jour , mois , ans ;
    char ch;
    //nom  JUSTE
    if( strlen(nom) == 0)
        test = 1 ;
    //naissance FAUSSE
    if( atoi(j) == 0 || atoi(m) == 0 || atoi(a) == 0)
        test = 4 ;
    else
    {

        jour = atoi(j);
        mois = atoi(m);
        ans = atoi(a);
        if( NaissanceVrais(jour , mois , ans) == 0 )
            test = 4 ;
    }
    //ville JUSTE
    if( strlen(ville) == 0 )
        test = 5 ;
    // clas JUSTE
    ch = clas[3];
    if( strlen(clas) == 0 || (isupper(ch) == 0 && islower(ch) == 0 ) )
        test = 6 ;
    //filiere JUSTE
    if(clas[2] == '1')
        strcpy(filiere , "auccun");
    if(strlen(filiere) == 0 )
        test = 7 ;

    //prenom JUSTE
    if( strlen(prenom) == 0)
        test = 2 ;
    //CIN JUSTE
    if( atoi(CIN) == 0 || strlen(CIN)!= 8)
        test = 3 ;
        else
        {
            if( strcmp(CIN , CIN1 ) != 0 )
             test = 8 ;
        }
    return test ;
}
 int enregistesting(char* nom ,char*  prenom ,char*  CIN ,char*  j ,char*  m ,char*  a ,char*  ville ,char*  clas ,char*  filiere )
{
    int test = 0 , jour , mois , ans ;
    char ch;
    FILE* F;
    F=fopen("./data/etudiants.txt","a");
    //nom  JUSTE
    if( strlen(nom) == 0)
        test = 1 ;
    //naissance FAUSSE
    if( atoi(j) == 0 || atoi(m) == 0 || atoi(a) == 0)
        test = 4 ;
    else
    {

        jour = atoi(j);
        mois = atoi(m);
        ans = atoi(a);
        if( NaissanceVrais(jour , mois , ans) == 0 )
            test = 4 ;
    }
    //ville JUSTE
    if( strlen(ville) == 0 )
        test = 5 ;
    // clas JUSTE
    ch = clas[3];
    if( strlen(clas) == 0 || (isupper(ch) == 0 && islower(ch) == 0 ) )
        test = 6 ;
    //filiere JUSTE
    if(clas[2] == '1')
          strcpy(filiere , "auccun");
    if(strlen(filiere) == 0 )
        test = 7 ;
          //prenom JUSTE
    if( strlen(prenom) == 0)
        test = 2 ;
    //CIN JUSTE
    if( atoi(CIN) == 0 || strlen(CIN)!= 8)
        test = 3 ;
        else
        {
            if( Est_Trouver(CIN) == 1 )
             test = 8 ;
        }
    //enregistrer
    if(test == 0)
        fprintf(F,"%s ; %s ; %s ; %d/%d/%d ; %s ; %s ; %s \n",CIN,nom ,prenom,jour,mois,ans,ville,clas,filiere);
    fclose(F);
    return test ;
}
