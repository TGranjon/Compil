#include "declaration.h"
#include"lexhc.h"
//TabDecla tabDecla[DECLARATION_MAX];
int debut_decla = 4;                        //comme pour la table lexico, les 4 premiers sont dédiés aux types de base

int debordement = DEBUT_DEBORDEMENT;
int tab_representation[MAX];


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
      //  tabDecla[i].execution = 0;
        //pour les types : entier, réel, booléen, char
    }
    for(i=4 ; i<=DECLARATION_MAX ; i++)
    {
        tabDecla[i].nature = -1;
        tabDecla[i].suivant = -1;
        tabDecla[i].region = -1;
        tabDecla[i].description = -1;
      //  tabDecla[i].execution = -1;
    }
}


int casevide_debordement(structDecla tab []){
    int trouv = 0,i=debordement;
    while ((i<=DECLARATION_MAX) &&( trouv!=1)){
           if (tab[i].nature==-1){
                trouv=1;

              }
              else {i++;}
           }
 if (trouv==1){return i;}
 else { return -1;}
}

void ajouter_struct(int numdecl,int numRegion,int numdescription)
{

    if(tabDecla[numdecl].nature == -1)
    {
        tabDecla[numdecl].nature = TYPE_STRUCT;
        tabDecla[numdecl].suivant = -1;
        tabDecla[numdecl].region = numRegion;
        tabDecla[numdecl].description = numdescription;


    }
    else
    {
        if (tabDecla[numdecl].suivant==-1){
            int deb=casevide_debordement(tabDecla);
         tabDecla[numdecl].suivant=deb;
        tabDecla[deb].nature = TYPE_STRUCT;
        tabDecla[deb].suivant = -1;
        tabDecla[deb].region = numRegion;
        tabDecla[deb].description = numdescription;
        }
        else {
            int i = tabDecla[numdecl].suivant; int fin =0;
            while (fin!=1){
                if (tabDecla[i].suivant==-1){
                    int deb =casevide_debordement(tabDecla);
                    tabDecla[i].suivant=deb;
                    tabDecla[deb].nature = TYPE_STRUCT;
                    tabDecla[deb].suivant = -1;
                    tabDecla[deb].region = numRegion;
                    tabDecla[deb].description = numdescription;
                    fin=1;

                }
                else {
                    i = tabDecla[i].suivant;
                }
            }
        }
    }

}

void ajouter_tab(int numdecl,int numRegion,int numdescription)
{
      if(tabDecla[numdecl].nature == -1)
    {
        tabDecla[numdecl].nature = TYPE_TAB;
        tabDecla[numdecl].suivant = -1;
        tabDecla[numdecl].region = numRegion;
        tabDecla[numdecl].description = numdescription;


    }
    else
    {
        if (tabDecla[numdecl].suivant==-1){
            int deb=casevide_debordement(tabDecla);
         tabDecla[numdecl].suivant=deb;
        tabDecla[deb].nature = TYPE_TAB;
        tabDecla[deb].suivant = -1;
        tabDecla[deb].region = numRegion;
        tabDecla[deb].description = numdescription;
        }
        else {
            int i = tabDecla[numdecl].suivant; int fin =0;
            while (fin!=1){
                if (tabDecla[i].suivant==-1){
                    int deb =casevide_debordement(tabDecla);
                    tabDecla[i].suivant=deb;
                    tabDecla[deb].nature = TYPE_TAB;
                    tabDecla[deb].suivant = -1;
                    tabDecla[deb].region = numRegion;
                    tabDecla[deb].description = numdescription;
                    fin=1;

                }
                else {
                    i = tabDecla[i].suivant;
                }
            }
        }
    }


}

void ajouter_var(int numdecl,int numRegion,char *type)
{
    int desc; int i =0, trouv =0;
    while ((i<TAILLE_LEXICO) && (trouv!=1)){
        if (tableLexico[i].lexeme==type){
            desc=i;
            trouv=1;
        }
        i++;
    }


    if(tabDecla[numdecl].nature == -1)
    {
        tabDecla[numdecl].nature = TYPE_VAR;
        tabDecla[numdecl].suivant = -1;
        tabDecla[numdecl].region = numRegion;
        tabDecla[numdecl].description=desc;

    }
    else
    {
        if (tabDecla[numdecl].suivant==-1){
            int deb=casevide_debordement(tabDecla);
         tabDecla[numdecl].suivant=deb;
        tabDecla[deb].nature = TYPE_VAR;
        tabDecla[deb].suivant = -1;
        tabDecla[deb].region = numRegion;
         tabDecla[deb].description=desc;

        }
        else {
            int i = tabDecla[numdecl].suivant; int fin =0;
            while (fin!=1){
                if (tabDecla[i].suivant==-1){
                    int deb =casevide_debordement(tabDecla);
                    tabDecla[i].suivant=deb;
                    tabDecla[deb].nature = TYPE_VAR;
                    tabDecla[deb].suivant = -1;
                    tabDecla[deb].region = numRegion;
                    tabDecla[deb].description=desc;
                    fin=1;

                }
                else {
                    i = tabDecla[i].suivant;
                }
            }
        }
    }



}

void ajouter_proc(int numdecl,int numRegion,int numdescription)
{

    if(tabDecla[numdecl].nature == -1)
    {
        tabDecla[numdecl].nature = TYPE_PROC;
        tabDecla[numdecl].suivant = -1;
        tabDecla[numdecl].region = numRegion;
        tabDecla[numdecl].description = numdescription;


    }
    else
    {
        if (tabDecla[numdecl].suivant==-1){
            int deb=casevide_debordement(tabDecla);
         tabDecla[numdecl].suivant=deb;
        tabDecla[deb].nature = TYPE_PROC;
        tabDecla[deb].suivant = -1;
        tabDecla[deb].region = numRegion;
        tabDecla[deb].description = numdescription;
        }
        else {
            int i = tabDecla[numdecl].suivant; int fin =0;
            while (fin!=1){
                if (tabDecla[i].suivant==-1){
                    int deb =casevide_debordement(tabDecla);
                    tabDecla[i].suivant=deb;
                    tabDecla[deb].nature = TYPE_PROC;
                    tabDecla[deb].suivant = -1;
                    tabDecla[deb].region = numRegion;
                    tabDecla[deb].description = numdescription;
                    fin=1;

                }
                else {
                    i = tabDecla[i].suivant;
                }
            }
        }
    }



}



void ajouter_fct(int numdecl,int numRegion,int numdescription)
{
    if(tabDecla[numdecl].nature == -1)
    {
        tabDecla[numdecl].nature = TYPE_FONCT;
        tabDecla[numdecl].suivant = -1;
        tabDecla[numdecl].region = numRegion;
        tabDecla[numdecl].description = numdescription;


    }
    else
    {
        if (tabDecla[numdecl].suivant==-1){
            int deb=casevide_debordement(tabDecla);
         tabDecla[numdecl].suivant=deb;
        tabDecla[deb].nature = TYPE_FONCT;
        tabDecla[deb].suivant = -1;
        tabDecla[deb].region = numRegion;
        tabDecla[deb].description = numdescription;
        }
        else {
            int i = tabDecla[numdecl].suivant; int fin =0;
            while (fin!=1){
                if (tabDecla[i].suivant==-1){
                    int deb =casevide_debordement(tabDecla);
                    tabDecla[i].suivant=deb;
                    tabDecla[deb].nature = TYPE_FONCT;
                    tabDecla[deb].suivant = -1;
                    tabDecla[deb].region = numRegion;
                    tabDecla[deb].description = numdescription;
                    fin=1;

                }
                else {
                    i = tabDecla[i].suivant;
                }
            }
        }
    }



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

/*void afficher_tab_rep(){
    int i;
    printf("\n Table des déclarations \n");
    for (i = 0 ; i<numrep ; i++)
        printf(" %d", tab_representation[i]);
    printf("\n");
}*/
