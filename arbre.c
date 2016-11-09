#include stdio.h
#include stdlib.h
/*Possible inclusion de fichiers*/
/*Ce fichier devra être inclus au moins dans le .y*/

/*Définition des codes/noyau*/
/*Chaque code coorespont à un entier de 1 à 37*/

#define TABLEAU 1
#define STRUCT 2
#define DEUX_POINTS 3
#define POINTPOINT 4
#define OPAFF 5
#define INF 6
#define SUP 7
#define INFEGAL 8
#define SUPEGAL 9
#define DIFF 10
#define EGAL 11
#define PLUS 12
#define MOINS 13
#define MULT 14
#define DIV 15
#define POURCENT_ENTIER 16
#define POURCENT_REEL 17
#define POURCENT_CHAINE 18
#define POURCENT_CARACTERE 19
#define PROCEDURE 20
#define FONCTION 21
#define RETOURNE 22
#define SIALORSSINON 23
#define TANT_QUE 24
#define POUR 25
#define JUSQUA 26
#define BOOL 27
#define CSTE_ENTIERE 28
#define CSTE_REELE 29
#define ET 30
#define OU 31
#define VIDE 32
#define LIRE 33
#define ECRIRE 34
#define CSTE_CARACTERE 35
#define CSTE_CHAINE 36
#define IDF 37

/*Déclaration de l'arbre abstrait*/

typedef struct cellule
{
  int noyau;
  int lexeme;
  int declaration;
  cellule * fils;
  cellule * frere;
}cellule;

/*Déclaration des fonctions*/

cellule * creer_fils(int noy, int lex, int decl)
{
  cellule cel;
  cel<-noyau=noy;
  cel<-lexeme=lex;
  cel<-declaration=decl;
  return &cel;
}

cellule * creer_frere(int noy, int lex, int decl)
{
  cellule  cel;
  cel<-noyau=noy;
  cel<-lexeme=lex;
  cel<-declaration=decl;
  return &cel;
}

/*Lecture de l'arbre*/
  
/*Il faut lire l'arbre de haut en bas puis de droite a gauche
 *C'est à dire que le fils doit être lu avant de lire le frère
 */

void lire_arbre(cellule * racine)
{
  
  
}
