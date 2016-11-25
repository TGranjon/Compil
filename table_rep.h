#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE_MAX 5000
#define TAILLE_DIMENSIONS 5

int  tabbornes[TAILLE_DIMENSIONS*2]=malloc((TAILLE_DIMENSIONS*2)*sizeof(int));//tableau pour stocker les bornes des tableaux
int * tab_rep[TAILLE_MAX]; // declaration table representation


void init_tab_rep();       //intialisation de la table de rep

int insertstruct_tabrep(int i/*récupéré du champ description*/);
/*fonction qui renvoie la case vide dans une table*/
int case_vide(int [] tab);
/*fonction qui stocke les bornes du tableau*/
int bornes_tab(int borne1,int borne2);
void inserttab_tabrep();//insertion de tableau dans la table rep
void insertproc();//insertion de procedure
