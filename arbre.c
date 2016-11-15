#include stdio.h
#include stdlib.h
/*Possible inclusion de fichiers*/
/*Ce fichier devra être inclus au moins dans le .y*/

/*Définition des codes/noyau*/
/*Chaque code coorespont à un entier de 1 à 36*/

#define TABLEAU 1
#define STRUCT 2
#define POINTPOINT 3
#define OPAFF 4
#define INF 5
#define SUP 6
#define INFEGAL 7
#define SUPEGAL 8
#define DIFF 9
#define EGAL 10
#define PLUS 11
#define MOINS 12
#define MULT 13
#define DIV 14
#define POURCENT_ENTIER 15
#define POURCENT_REEL 16
#define POURCENT_CHAINE 17
#define POURCENT_CARACTERE 18
#define PROCEDURE 19
#define FONCTION 20
#define RETOURNE 21
#define SIALORSSINON 22
#define TANT_QUE 23
#define POUR 24
#define JUSQUA 25
#define BOOL 26
#define CSTE_ENTIERE 27
#define CSTE_REELE 28
#define ET 29
#define OU 30
#define VIDE 31
#define LIRE 32
#define ECRIRE 33
#define CSTE_CARACTERE 34
#define CSTE_CHAINE 35
#define IDF 36

/*Déclaration de l'arbre abstrait*/

typedef struct cellule
{
  int noyau; /*Correspond aux codes ci-dessus*/
  int lexeme; /*Code lexicographique correspondant*/
  int declaration; /*Code correspondant a l'entrée dans la table des déclarations*/
  cellule * fils; /*Pointeur vers le premier fils*/
  cellule * frere; /*Pointeur vers le premier frere*/
}cellule;

/*Déclaration des fonctions*/

cellule * creer_fils(int noy, int lex, int decl)
{
  cellule cel;
  cel.noyau=noy;
  cel.lexeme=lex;
  cel.declaration=decl;
  return &cel;
}

cellule * creer_frere(int noy, int lex, int decl)
{
  cellule  cel;
  cel.noyau=noy;
  cel.lexeme=lex;
  cel.declaration=decl;
  return &cel;
}

bool est_vide(cellule * cel)
{
	if(cel.noyau==NULL)
		return true;
	else return false;
}

/*Lecture de l'arbre*/
  
/*Il faut lire l'arbre de haut en bas puis de droite a gauche
 *C'est à dire que le(s) fils doit être lu avant de lire le frère
 */

char * lire_arbre(cellule * racine)
{
    if(3<=racine.noyau<=14 || 29<=racine.noyau<=30)
    {
    	return strcat(lire_arbre(racine.fils.noyau),strcat(racine.noyau,lire_arbre(racine.fils.frere.noyau))); /*Cas de lecture complexe (info contenue dans les fils et les petits freres)*/
    }
    if(15<=racine.noyau<=18 || 26<=racine.noyau<=28 || racine.noyau==31 || 34<=racine.noyau<=36)
    {
    	return racine.noyau; /*Cas de lecture unique*/
    }
    if(1<=racine.noyau<=2 || 19<=racine.noyau<=20 || 21<=racine.noyau<=25 || 32<=racine.noyau<=33)
    {
    	return strcat(racine.noyau,lire_arbre(racine.fils)); /*Cas de lecture en liste (info contenue uniquement dans les fils)*/
    }
    fprintf(STDERR,"Erreur, noyau non reconnu\n");
}
