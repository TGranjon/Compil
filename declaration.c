#include "declaration.h"
#include"lexhc.h"
//TabDecla tabDecla[DECLARATION_MAX];
int debut_decla = 4;                        //comme pour la table lexico, les 4 premiers sont dédiés aux types de base

int debordement = DEBUT_DEBORDEMENT;
int tab_representation[MAX];


int taille_struct(){
    return 0;
}

int taille_tableau(){
    return 0;
}

void init_tab_decla()
{
    for(int i=0 ; i<=3 ; i++)
    {

	
        tabDecla[i].nature = TYPE_BASE;
        tabDecla[i].suivant = -1;
        tabDecla[i].region = 0;
        tabDecla[i].description = -1;
      	tabDecla[i].execution = -1;

        //pour les types : entier, réel, booléen, char
    }
    for(int j=4 ; j<DECLARATION_MAX ; j++)
    {
        tabDecla[j].nature = -1;
        tabDecla[j].suivant = -1;
        tabDecla[j].region = -1;
        tabDecla[j].description = -1;
      	tabDecla[j].execution = -1;
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
		//tabDecla[numdecl].execution = tailleStruct();	

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
		//tabDecla[deb].execution = tailleStruct();
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
					//tabDecla[deb].execution = tailleStruct();
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
		//tabDecla[numdecl].execution = taille_tableau();

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
		//tabDecla[deb].execution = taille_tableau();
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
					//tabDecla[deb].execution = taille_tableau();
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

    int desc=0; int i =0, trouv =0;
    while ((i<TAILLE_LEXICO) && (trouv!=1)){
        if (strcmp(tableLexico[i].lexeme, type) ==0){
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
        tabDecla[numdecl].execution = 1;
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
       		tabDecla[deb].execution = 1;
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
			        //tabDecla[deb].execution = 
                    fin=1;

                }
                else {
                    i = tabDecla[i].suivant;
                }
            }
        }
    }



}

void ajouter_proc(int numdecl,int numRegion,int numdescription, int execution)
{

    if(tabDecla[numdecl].nature == -1)
    {
        tabDecla[numdecl].nature = TYPE_PROC;
        tabDecla[numdecl].suivant = -1;
        tabDecla[numdecl].region = numRegion;
        tabDecla[numdecl].description = numdescription;
		tabDecla[numdecl].execution = execution;

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
		tabDecla[deb].execution = execution;
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
					tabDecla[deb].execution = execution;
                    fin=1;

                }
                else {
                    i = tabDecla[i].suivant;
                }
            }
        }
    }

}



void ajouter_fct(int numdecl,int numRegion,int numdescription, int execution)
{
    if(tabDecla[numdecl].nature == -1)
    {
        tabDecla[numdecl].nature = TYPE_FONCT;
        tabDecla[numdecl].suivant = -1;
        tabDecla[numdecl].region = numRegion;
        tabDecla[numdecl].description = numdescription;
		tabDecla[numdecl].execution = execution;

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
		tabDecla[deb].execution = execution;
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
					tabDecla[deb].execution = execution;
                    fin=1;

                }
                else {
                    i = tabDecla[i].suivant;
                }
            }
        }
    }
}

int association_noms(int num_lexico, int region)
{
	if(tabDecla[num_lexico].nature == -1)
	{
		return -1;
	}
	if(tabDecla[num_lexico].region == region)
	{
		return num_lexico;
	}
	else if(tabDecla[num_lexico].suivant != -1)
	{
		association_noms(tabDecla[num_lexico].suivant,region);
	}
	else return -1;
}


void affiche_table_decla(structDecla tab[])
{
    int i;
    char * nature;
    printf("\n______________Table des déclarations_______________________________\n");
    printf(" Numlex\t|Nature\t\t|Suivant|Région\t| Description\t| Exécution\n");
    for (i=0 ; i<DECLARATION_MAX ; i++)
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
	printf("\n___________________________________________________________________\n\n");
}

/*void afficher_tab_rep(){
    int i;
    printf("\n Table des déclarations \n");
    for (i = 0 ; i<numrep ; i++)
        printf(" %d", tab_representation[i]);
    printf("\n");
}*/
