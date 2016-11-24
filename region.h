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

int ajouter_region(int niveau_imbrication);         // Fonction : ajout d'une nouvelle région dans la table

void affiche_tab_region(structRegion region[]);     // Procédure : affichage de la table des régions

int incrementer_region(int region); 				//Fonction : incremente le numero de region dans le .y

int incrementer_NIS(int NIS);						//Fonction : incremente le NIS dans le .y

int decrementer_NIS(int NIS);						//Fonction : decremente le NIS dans le .y

int calculer_taille(int X/*Numero declaration rendu par association de nom*/);							//Fonction : calcule la taille de l'objet donné en paramètre

#endif

