#include "include.h"
#include "lexhc.h"
#define TAILLE_MAX 5000
#define TAILLE_DIMENSIONS 5



void init_tab_rep(int * tab); //initialisation de la table de représentation
void insertnbchamps(int nb_champs); //insertion struct ds la table de rep
void insertchampstruct(char* idf,char *type); // insertion champs
int case_vide(int tab[]); // la case vide dans une table
int * bornes_tab(int borne1,int borne2); //les bornes inf et sup d'un tableau 
void inserttypetab(char *type); // insertion du type d'un tableau 
void insertnbdimensions(int nb_dimensions); /*insertion nb de dinmensions d'un tableau*/
void insertbornes( int *tabbornes); //insertion des bornes inf et sup 
void insertnbparam(int nbparam); //fonction d'insertion de nb params  procedure
void insertparam(char *idf , char *type); //fonction d'insertion des params de procedure/
void inserttyperetour(char * type); //fonction d'insertionde type de retour d'une fonction
//void insertnbparamfct(int nbparam); //fonction d'insertion de nb params d'une fonction
//void insertparamfct(char *idf,char* type); //fonction d'insertion des params d'une fonctions
int case_element(int num); // l'element de la table de rep à la case de numero "num"
