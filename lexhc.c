#include"lexhc.h"

/*
structLexico tableLexico[TAILLE_LEXICO];					//d�claration : table lexicographique de taille TAILLE_LEXICO
int tab_hash_code[TAILLE_HASH];								//d�claration : table de hash code
*/

int debut_lex = 4;                                          //Les pr�c�dents �tant les types de base
                                                            //il repr�sente �galement la premi�re ligne non remplie

int hash_code(char * lexeme)
{
	int i = 0;
	int sommeascii = 0;
	for(i = 0 ; i <= strlen(lexeme) ; i++){
		sommeascii += lexeme[i];
	}

	return sommeascii%32;
}

void init_hash_code(int * tab)
{
    //proc�dure : initialisation de toutes les cases de la table hash code � -1
	int i = 0;
	for(i=0;i<TAILLE_HASH;i++){
		tab[i]=-1;
	}
}

void init_tab_lex(){
    int i;
    //On initialise les 4 premi�res structures, par convention, les types entier, r�el, bool�en et char
    tableLexico[0].indice_n_lex=0;
    tableLexico[0].longueur=strlen("entier");
    strcpy(tableLexico[0].lexeme,"entier");
    tableLexico[0].suivant=-1;

    tableLexico[1].indice_n_lex=1;
    tableLexico[1].longueur=strlen("reel");
    strcpy(tableLexico[1].lexeme,"reel");
    tableLexico[1].suivant=-1;

    tableLexico[2].indice_n_lex=2;
    tableLexico[2].longueur=strlen("booleen");
    strcpy(tableLexico[2].lexeme,"booleen");
    tableLexico[2].suivant=-1;

    tableLexico[3].indice_n_lex=3;
    tableLexico[3].longueur=strlen("char");
    strcpy(tableLexico[3].lexeme,"char");
    tableLexico[3].suivant=-1;

    for(i=4;i<TAILLE_LEXICO;i++){
        tableLexico[i].indice_n_lex=i; /*On continue � compter les indices*/
        tableLexico[i].longueur=-1; /*On initialise longueur � -1*/
        strcpy(tableLexico[i].lexeme,""); /*On initialise lexeme � chaine vide*/
        tableLexico[i].suivant=-1; /*On initialise suivant � -1*/
    }
}

int inserer_lexeme (char * n_lexeme){
	int num_hash_code = hash_code(n_lexeme);        // On calcule le hash code du lexeme pass� en param�tre
    int indice = tab_hash_code[num_hash_code];      // on r�cup�re dans a l'indice du premier �l�ment stock� dans la table lexicograpique
    int nouv_num;                              // num�ro lexicographique du lexeme pass� en param�tre

    if ( indice == -1)                                // cas o� le lex�me n'a pas encore �t� stock� dans la table
    {
        tableLexico[debut_lex].indice_n_lex = debut_lex;
        tableLexico[debut_lex].longueur = strlen(n_lexeme);
        strcpy(tableLexico[debut_lex].lexeme,n_lexeme);
        tableLexico[debut_lex].suivant=-1;
        tab_hash_code[num_hash_code]=debut_lex;
        debut_lex++;
        nouv_num = debut_lex-1;
    }
    else                                            // cas o� s'il existe un ou plusieurs lex�mes (suivants) ayant le m�me hash code
    {
        while(tableLexico[indice].suivant != -1 && strcmp(tableLexico[indice].lexeme,n_lexeme)!=0) // on v�rifie si la cha�ne n'est pas d�j� dans le tableau (une fois ou avec des suivants)
            indice=tableLexico[indice].suivant;

        if(strcmp(tableLexico[indice].lexeme,n_lexeme)!=0) // cas o� le lex�me est in�dit
        {
            tableLexico[debut_lex].indice_n_lex=debut_lex;
            tableLexico[debut_lex].longueur=strlen(n_lexeme);
            strcpy(tableLexico[debut_lex].lexeme,n_lexeme);
            tableLexico[indice].suivant = debut_lex;
            tableLexico[debut_lex].suivant=-1;
            debut_lex++;
            nouv_num =  debut_lex-1;
        }
        else if (strcmp(tableLexico[indice].lexeme, n_lexeme) ==0) // cas o� le lex�me est d�j� stock� dans la table
            nouv_num =  tableLexico[indice].indice_n_lex;
    }
    return nouv_num;
}


char * lexeme (int num_lexico){
	return tableLexico[num_lexico].lexeme;
}

int avoir_num_lexico (char * lexeme){
	int num_hash_code = hash_code(lexeme);
	int indice = tab_hash_code[num_hash_code];
	int suivant;
	if(strcmp(tableLexico[indice].lexeme,lexeme)==0){
		return indice;
	}
	else{
		suivant = tableLexico[indice].suivant;
		while(suivant!=-1){
			if(strcmp(tableLexico[suivant].lexeme,lexeme)==0){
				return indice;
			}
		}
		inserer_lexeme(lexeme);
	}
}


void affiche_table_lexico(structLexico lex_tab[], int n){
	assert(n <= TAILLE_LEXICO);

	int i = 0;

	printf("\n/* _______________Table lexicographique________________ */\n");
	printf("|   numero lex   |   longueur   |   lexeme   |   suivant   |\n");
	for (i = 0 ; i < n ; i++){
		printf("|      %d         |      %d      |   %s        |   %d   |\n",lex_tab[i].indice_n_lex,lex_tab[i].longueur, lex_tab[i].lexeme, lex_tab[i].suivant);
	}
	printf("\n/* ____________________________________________________ */\n");
}

void affiche_table_hash_code(int tab_hc[]){

	int i = 0;
	printf("\n/* __________table de hachage__________ */\n");
	for( i = 0 ; i < 32 ; i++)
	{
    printf("                    %d\n", tab_hc[i]);
	}
	printf("\n/* ____________________________________ */\n");
}

