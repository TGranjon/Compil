#ifndef TABDECLA
#define TABDECLA

#include "include.h"

#define TYPE_BASE 0
#define TYPE_STRUCT 1
#define TYPE_TAB 2
#define TYPE_VAR 3
#define TYPE_FONCT 4
#define TYPE_PROC 5

#define DECLARATION_MAX 1000
#define MAX 100
#define DEBUT_DEBORDEMENT 500


typedef struct structDecla                                  // Structure du tableau des déclarations
{
  int nature;                                               // on prédéfini des entiers pour les différents types d'entrée.
  int suivant;
  int region;
  int description;
  int execution;
}structDecla;

structDecla tabDecla[DECLARATION_MAX];

void init_tab_decla();                             //procédure : initialisation du tableau des déclarations (4 premières lignes -> types primitifs)

int ajouter_struct(int n_lexico);                  //fonction : ajout d'un élément de type struct dans le tableau des déclarations

int ajouter_tab(int n_lexico,int n_description);   //fonction : ajout d'un élément de type tableau dans le tableau des déclarations

int ajouter_var(int n_lexico, int n_description);  //fonction : ajout d'un élément de type variable dans le tableau des déclarations

int ajouter_proc(int n_lexico);                    //fonction : ajout d'un élément de type procédure dans le tableau des déclarations

int ajouter_fct(int n_lexico);                     //fonction : ajout d'un élément de type fonction dans le tableau des déclarations

void affiche_tab_decla(structDecla tab[]);         //procédure : affichage du tableau des déclarations


#endif
