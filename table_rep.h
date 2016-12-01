#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE_MAX 5000
#define TAILLE_DIMENSIONS 5

int  tabbornes[TAILLE_DIMENSIONS*2]=malloc((TAILLE_DIMENSIONS*2)*sizeof(int));//tableau pour stocker les bornes des tableaux
int * tab_rep[TAILLE_MAX]; // declaration table representation


void init_tab_rep();//initialisation de la table de représentation
int insertnbchamps(int nb_champs);//insertion struct ds la table de rep
void insertchampstruct(char* idf,char *type);// insertion champs
int case_vide(int [] tab);// la case vide dans une table
int * bornes_tab(int borne1,int borne2);//les bornes inf et sup d'un tableau 
void inserttypetab(char *type);// insertion du type d'un tableau 
void insertnbdimensions(int nb_dimensions);/*insertion nb de dinmensions d'un tableau*/
void insertbornes( int *tabbornes);//insertion des bornes inf et sup 
void insertnbparamproc(int nbparam);//fonction d'insertion de nb params  procedure
void insertparamproc(char *idf , char *type);//fonction d'insertion des params de procedure/
void inserttyperetour(char * type);//fonction d'insertionde type de retour d'une fonction
void insertnbparamfct(int nbparam);//fonction d'insertion de nb params d'une fonction
void insertparamfct(char *idf,char* type);//fonction d'insertion des params d'une fonctions
int case_element(int num);// l'element de la table de rep à la case de numero "num"
int incremente_nbparam();//incrementation de nb param
int incremente_nbchamps();//incrementation de nb champs
int incremente_nbarg();//incrementation de nb champs
