#include "declaration.h"

//TabDecla tabDecla[DECLARATION_MAX];
int debut_decla = 4;                        //comme pour la table lexico, les 4 premiers sont dédiés aux types de base
int numRegion = 1; /*Defini dans le .y*/
int debordement = DEBUT_DEBORDEMENT;
int tab_representation[MAX];
int numrep=0;

int taille_struct(){
    return 0;
    //à coder : peut s'avérer utile
}

int taille_tableau(){
    return 0;
    //à coder : peut s'avérer utile
}

void init_tab_decla()
{
    int i;
    for(i=0 ; i<=3 ; i++)
    {
        tabDecla[i].nature = TYPE_BASE;
        tabDecla[i].suivant = -1;
        tabDecla[i].region = 0;
        tabDecla[i].description = -1;
        tabDecla[i].execution = 0;
        //pour les types : entier, réel, booléen, char
    }
    for(i=4 ; i<=DECLARATION_MAX ; i++)
    {
        tabDecla[i].nature = -1;
        tabDecla[i].suivant = -1;
        tabDecla[i].region = -1;
        tabDecla[i].description = -1;
        tabDecla[i].execution = -1;
    }
}

int ajouter_struct(int n_lexico)
{
    if(debut_decla >= DEBUT_DEBORDEMENT)
    {
        printf("Erreur, la limite mémoire a été atteinte !\n");
        return (-1);
    }

    if(tabDecla[n_lexico].nature == -1)
    {
        tabDecla[n_lexico].nature = TYPE_STRUCT;
        tabDecla[n_lexico].suivant = -1;
        tabDecla[n_lexico].region = numRegion;
        tabDecla[n_lexico].description = numrep;
        //tabDecla[n_lexico].execution =
        //faudrait que je revois le cours pour ce champ-là
        debut_decla++;
    }
    else
    {
        while(tabDecla[n_lexico].suivant != -1)
            n_lexico = tabDecla[n_lexico].suivant;

        tabDecla[n_lexico].suivant = debordement;
        tabDecla[debordement].nature = TYPE_STRUCT;
        tabDecla[debordement].suivant = -1;
        tabDecla[debordement].region = numRegion;
        tabDecla[debordement].description = numrep;
        //tabDecla[debordement].execution =
        debordement++;
    }

    // en profiter ici pour faire le lien entre la table de représentation et la pile de représentation
    return 0;
}

int ajouter_tab(int n_lexico, int n_description) /*Il faut numRegion en parametres*/
{
    if(debut_decla >= DEBUT_DEBORDEMENT)
    {
        printf("Erreur, la limite mémoire a été atteinte !\n");
        exit(-1);
    }

    if(tabDecla[n_lexico].nature == -1)
    {
        tabDecla[n_lexico].nature = TYPE_TAB;
        tabDecla[n_lexico].suivant = -1;
        tabDecla[n_lexico].region = numRegion;
        tabDecla[n_lexico].description = numrep;
        //tabDecla[n_lexico].execution =
    }
    else
    {
        while(tabDecla[n_lexico].suivant != -1)
            n_lexico = tabDecla[n_lexico].suivant;

        tabDecla[n_lexico].suivant = debordement;
        tabDecla[debordement].nature = TYPE_BASE;
        tabDecla[debordement].suivant = -1;
        tabDecla[debordement].region = numRegion;
        tabDecla[debordement].description = numrep;
        //tabDecla[debordement].execution =
        debordement++;
    }

    //idem, comme pour ajouter_struct, faire le lien entre la pile de représentations et sa table

    return 0;
}

int ajouter_var(int n_lexico, int n_description)
{
    if(debut_decla >= DEBUT_DEBORDEMENT)
    {
        printf("Erreur, la limite mémoire a été atteinte !\n");
        return (-1);
    }

    if(tabDecla[n_lexico].nature == -1)
    {
        tabDecla[n_lexico].nature = TYPE_VAR;
        tabDecla[n_lexico].suivant = -1; /*suivant n'est jamais à autre chose que -1*/
        //tabDecla[n_lexico].region =
        //créer une fonction qui retourne la région dans laquelle se trouve la var
        tabDecla[n_lexico].description = n_description;
        //tabDecla[n_lexico].execution =
        debut_decla++;
    }
    else
    {
        while(tabDecla[n_lexico].suivant != -1)
            n_lexico = tabDecla[n_lexico].suivant;

        tabDecla[n_lexico].suivant = debordement;
        tabDecla[debordement].nature = TYPE_VAR;
        tabDecla[debordement].suivant = -1;
        //tabDecla[debordement].region =
        tabDecla[debordement].description = n_description;
        //tabDecla[debordement].execution =
        debordement++;
    }
        return 0;
}

int ajouter_proc(int numLexico)
{
    if(debut_decla >= DEBUT_DEBORDEMENT)
    {
        printf("Erreur, la limite mémoire a été atteinte !\n");
        return (-1);
    }

    if(tabDecla[numLexico].nature == -1)
    {
        tabDecla[numLexico].nature = TYPE_PROC;
        tabDecla[numLexico].suivant = -1;
        //tabDecla[numLexico].region =
        tabDecla[numLexico].description = numrep;
        //tabDecla[numLexico].execution =
        debut_decla++;
    }
    else
    {
        while(tabDecla[numLexico].suivant != -1)
            numLexico = tabDecla[numLexico].suivant;

        tabDecla[numLexico].suivant = debordement;
        tabDecla[debordement].nature = TYPE_PROC;
        tabDecla[debordement].suivant = -1;
        //tabDecla[debordement].region =
        tabDecla[debordement].description = numrep;
        //tabDecla[debordement].execution =
        debordement++;
    }

    // Lien table et pile de représentation

    return 0;
}

int ajouter_fct(int n_lexico)
{
    if(debut_decla >= DEBUT_DEBORDEMENT)
    {
        printf("Erreur, la limite mémoire a été atteinte !\n");
        return (-1);
    }

    if(tabDecla[n_lexico].nature == -1)
    {
        tabDecla[n_lexico].nature = TYPE_FONCT;
        tabDecla[n_lexico].suivant = -1;
        //tabDecla[n_lexico].region =
        tabDecla[n_lexico].description = numrep;
        //tabDecla[n_lexico].execution =
        debut_decla++;
    }
    else
    {
        while(tabDecla[n_lexico].suivant != -1)
            n_lexico = tabDecla[n_lexico].suivant;

        tabDecla[n_lexico].suivant = debordement;
        tabDecla[debordement].nature = TYPE_FONCT;
        tabDecla[debordement].suivant = -1;
        //tabDecla[debordement].region =
        tabDecla[debordement].description = numrep;
        //tabDecla[debordement].execution =
        debordement++;
    }

    // Lien table et pile de représentation

    return 0;
}


void affiche_tab_decla(structDecla tab[])
{
    int i;
    char * nature;
    printf("\n______________Table des déclarations______________\n");
    printf(" Numlex\t|Nature\t|Suivant|Région\t| Description\t| Exécution\n");
    for (i=0 ; i<debordement ; i++)
        if(tab[i].nature != -1){
                switch(tab[i].nature){
                    case TYPE_BASE :
                        nature = "TYPE_BASE"; break;
                    case TYPE_STRUCT :
                        nature = "TYPE_STRUCT"; break;
                    case TYPE_TAB :
                        nature = "TYPE_TAB"; break;
                    case TYPE_VAR :
                        nature = "TYPE_VAR"; break;
                    case TYPE_PROC :
                        nature = "TYPE_PROC"; break;
                    case TYPE_FONCT :
                        nature = "TYPE_FONCT"; break;
                    default :
                        nature = "Type inconnu...";
                }

                    printf(" %d\t| %s\t| %d\t| %d\t| %d\t\t| %d\n",i, nature, tab[i].suivant, tab[i].region, tab[i].description, tab[i].execution);

        }
}

void afficher_tab_rep(){
    int i;
    printf("\n Table des déclarations \n");
    for (i = 0 ; i<numrep ; i++)
        printf(" %d", tab_representation[i]);
    printf("\n");
}
