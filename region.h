#ifndef REG
#define REG

#include "include.h"
#include "arbre.h"

#define MAX_REGION 15

typedef struct structRegion {                       // Structure de la table des régions
    int taille;
    int niveau_imbrication;
    cellule arbre;
}structRegion;

void init_tab_region();                             // Fonction : initialisation de la table des régions : taille <- -1, NIS <- -1, arbre <- NULL (pointeur)

int ajouter_region(int taille, int niveau_imbrication, cellule arbre);         // Fonction : ajout d'une nouvelle région dans la table

void affiche_tab_region(structRegion region[]);     // Procédure : affichage de la table des régions

int calculer_taille(int X/*Numero declaration rendu par association de nom*/);							//Fonction : calcule la taille de l'objet donné en paramètre

#endif

