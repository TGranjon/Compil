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


typedef struct structDecla                                  // Structure du tableau des d�clarations
{
  int nature;                                               // on pr�d�fini des entiers pour les diff�rents types d'entr�e.
  int suivant;
  int region;
  int description;
  int execution;
}structDecla;

structDecla tabDecla[DECLARATION_MAX];

void init_tab_decla();                             //proc�dure : initialisation du tableau des d�clarations (4 premi�res lignes -> types primitifs)

int casevide_debordement(structDecla tab []);
void ajouter_struct(int numdecl,int numRegion,int numdescription) ;                //fonction : ajout d'un �l�ment de type struct dans le tableau des d�clarations

void ajouter_tab(int numdecl,int numRegion,int numdescription) ;  //fonction : ajout d'un �l�ment de type tableau dans le tableau des d�clarations

void ajouter_var(int numdecl,int numRegion,char * type) ; //fonction : ajout d'un �l�ment de type variable dans le tableau des d�clarations

void ajouter_proc(int numdecl,int numRegion,int numdescription, int execution)  ;                  //fonction : ajout d'un �l�ment de type proc�dure dans le tableau des d�clarations

void ajouter_fct(int numdecl,int numRegion,int numdescription, int execution);                    //fonction : ajout d'un �l�ment de type fonction dans le tableau des d�clarations

int association_noms(int num_lexico, int region);

void affiche_table_decla(structDecla tab[]);         //proc�dure : affichage du tableau des d�clarations


#endif
