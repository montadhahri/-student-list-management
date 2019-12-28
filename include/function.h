#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

#include "textedition.h"
typedef struct naissance
{
    int j , m , a ;

}naissance;
typedef struct etudiant
{
    char CIN[9] ;
    char nom[10] , prenom[15] ;
    naissance DateNaissance ;
    char adress[20];
    char clas[10];
    char filiere[10];
}etudiant;
typedef struct etudiant1
{
    char CIN[9] ;
    char nom[10] , prenom[15] ;
    char DateNaissance[15] ;
    char adress[20];
    char clas[10];
    char filiere[10];
}etudiant1;
int EstVide(FILE* F);
int reglefich();
int SupprimerToutEtudiants();
int probwindow();
int defaultwindow();
int succeswindow();
void cleanup();
int cintest(char *CIN);
int Est_Trouver(char CIN[10]);
int bissextile (int a);
int NaissanceVrais(int j,int m,int a);
int enregistest(char* CIN1 ,char* nom ,char*  prenom ,char*  CIN ,char*  j ,char*  m ,char*  a ,char*  ville ,char*  clas ,char*  filiere );
int enregistesting(char* nom ,char*  prenom ,char*  CIN ,char*  j ,char*  m ,char*  a ,char*  ville ,char*  clas ,char*  filiere );




#endif // FUNCTION_H_INCLUDED
