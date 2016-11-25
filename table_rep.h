#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE_MAX 5000
#define TAILLE_DIMENSIONS 5

int  tabbornes[TAILLE_DIMENSIONS*2]=malloc((TAILLE_DIMENSIONS*2)*sizeof(int));//tableau pour stocker les bornes des tableaux
int * tab_rep[TAILLE_MAX]; // declaration table representation


void init_tab_rep();       //intialisation de la table de rep
int insertnbchamps(int nb_champs);
void insertchampstruct(char* idf,char *type);
int case_vide(int [] tab);
int * bornes_tab(int borne1,int borne2);
void inserttypetab(char *type);
void insertnbdimensions(int nb_dimensions);
void insertbornes( int *tabbornes);
