#ifndef REG
#define REG

#include "include.h"
#include "arbre.h"

#define MAX_REGION 15

typedef struct structRegion {                       // Structure de la table des r�gions
    int taille;
    int niveau_imbrication;
    cellule arbre;
}structRegion;

void init_tab_region();                             // Fonction : initialisation de la table des r�gions : taille <- -1, NIS <- -1, arbre <- NULL (pointeur)

int ajouter_region(int niveau_imbrication);         // Fonction : ajout d'une nouvelle r�gion dans la table

void affiche_tab_region(structRegion region[]);     // Proc�dure : affichage de la table des r�gions

#endif

