#ifndef TABLEXHC
#define TABLEXHC

#define TAILLE_LEXICO 1000
#define TAILLE_HASH 32
#include "include.h"

typedef struct structLexico											// Structure de la table lexicographique
{
    int indice_n_lex;
	int longueur;
	char lexeme [256];
	int suivant;
} structLexico;

structLexico tableLexico[TAILLE_LEXICO];					        //d�claration : table lexicographique de taille TAILLE_LEXICO
int tab_hash_code[TAILLE_HASH];								        //d�claration : table de hash code


int hash_code(char * lexeme);										//fonction : calcul du hash code du lexeme

void init_hash_code(int * tab);
void init_tab_lex();									            //proc�dure : initialisation du tableau � -1 et des premi�res lignes associ�es aux types primitifs

int inserer_lexeme (char * lexeme);									//fonction : insertion du lexeme non d�j� int�gr� dans la table lexicographique
																	//et retourne son num�ro lexicographique

char * lexeme (int num_lexico);										//fonction : retourne le lexeme associ� � un num�ro lexicographique donn�

int avoir_num_lexico (char * lexeme);								//fonction : retourne le numero lexicographique li� au lexeme donn� (ou l'insere si il n'y est pas)

void affiche_table_lexico(structLexico tab[], int n);				//proc�dure : affiche la table lexicographique
void affiche_table_hash_code(int tab[]);							//proc�dure : affiche la table de hash code

#endif
