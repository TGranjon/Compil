#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Déclaration de l'arbre abstrait*/

struct cellule
{
  int noyau; /*Correspond aux codes ci-dessus*/
  int lexeme; /*Code lexicographique correspondant*/
  int declaration; /*Code correspondant a l'entrée dans la table des déclarations*/
  struct cellule * fils; /*Pointeur vers le premier fils*/
  struct cellule * frere; /*Pointeur vers le premier frere*/
};

typedef struct cellule cellule;

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

/*Prototype des fonctions*/

cellule creer_arbre();

void concat_pere_fils(cellule pere, cellule fils);

void concat_pere_frere(cellule pere, cellule frere);

cellule creer_fils(int noy, int lex, int decl);

cellule creer_frere(int noy, int lex, int decl);

int est_vide(cellule * cel);

char * lire_arbre(cellule * racine);

