#include "table_rep.h"
#define TAILLE_MAX 5000
#define TAILLE_DIMENSIONS 5


int tabbornes[TAILLE_DIMENSIONS*2];

/**************************intialisation de la table de rep*****************************************/
void init_tab_rep(int * tab){      
	for(int i=0;i<TAILLE_MAX;i++)
		tab[i]=-1;

}


/****************************insertion struct ds la table de rep***********************************/

void insertnbchamps(int nb_champs){


	int i=case_vide(tab_rep);
	tab_rep[i]=nb_champs;
}
/*************************************** insertion champs****************************************/
void insertchampstruct(char* idf,char *type){
	int i=0;
	while(strcmp(tableLexico[i].lexeme,idf)!=0){

		i=i+1;
	}
	int j=case_vide(tab_rep);
	tab_rep[j]=i;
	j++;
	if(strcmp(type,"entier")==0)
		tab_rep[j]=0;
	else if(strcmp(type,"reel")==1)
		tab_rep[j]=1;
	else if(strcmp(type,"bool")==2)
		tab_rep[j]=2;
	else if(strcmp(type,"caractere")==3)
		tab_rep[j]=3;

	else {
		i=0;
		while(strcmp(tableLexico[i].lexeme,type)!=0){

		i=i+1;
		}
		tab_rep[j]=i;

	}
}



/*************************************** la case vide dans une table********************************/
int case_vide(int tab[]){
	int i=0;
	while(tab[i]!=-1 && i<TAILLE_MAX){
	i++;

	}
	return i;
}


/* **********************les bornes inf et sup d'un tableau ****************************************/
/******le tableau tbbornes est initialisé à la valeur -1//yacc: bornes_tab($1cste entiere,$3cste_entiere)************/
int * bornes_tab(int borne1,int borne2){

	for(int i=0;i<TAILLE_DIMENSIONS*2;i++){
		tabbornes[i]=-1;
	}
	int j=0;
	while(tabbornes[j]!=-1){
		j=j+1;
	}
	tabbornes[j]=borne1;
	tabbornes[j+1]=borne2;

	return tabbornes;
}


/************************************* insertion du type d'un tableau ******************************/
/*************************yacc:inserttypetab($1nomtype)*****************************/
void inserttypetab(char *type){

	int i=0;
	int j=case_vide(tab_rep);
	if(strcmp(type,"entier")==0)
		tab_rep[j]=0;
	else if(strcmp(type,"reel")==1)
		tab_rep[j]=1;
	else if(strcmp(type,"bool")==2)
		tab_rep[j]=2;
	else if(strcmp(type,"caractere")==3)
		tab_rep[j]=3;

	else {
		while(strcmp(tableLexico[i].lexeme,type)!=0){
			i=i+1;
		}
		tab_rep[j]=i;
	}



}
/***************************************************************************************************/
/*insertion nb de dinmensions d'un tableau*/
void insertnbdimensions(int nb_dimensions){

	int j=case_vide(tab_rep);
	tab_rep[j]=nb_dimensions;

}
/*************************insertion des bornes inf et sup *****************************************/
void insertbornes( int *tabbornes){

	int j=case_vide(tab_rep);
	for(int i=0;i<=TAILLE_DIMENSIONS*2;i++){
		tab_rep[j]=tabbornes[i];
		j++;
	}


}
/**********************************fonction d'insertion de nb params ********************************/

void insertnbparam(int nbparam){

	int j=case_vide(tab_rep);

	tab_rep[j]=nbparam;

}



/*******************************fonction d'insertion des params *******************/
 
void insertparam(char *idf , char *type){

	int j=case_vide(tab_rep);
	int i=0;
	while(strcmp(tableLexico[i].lexeme,idf)!=0){

		i=i+1;
		}

	tab_rep[j]=i;
	j++;

	if(strcmp(type,"entier")==0)
		tab_rep[j]=0;
	else if(strcmp(type,"reel")==1)
		tab_rep[j]=1;
	else if(strcmp(type,"bool")==2)
		tab_rep[j]=2;
	else if(strcmp(type,"caractere")==3)
		tab_rep[j]=3;

	else {
		while(strcmp(tableLexico[i].lexeme,type)!=0){
			i=i+1;
		}
		tab_rep[j]=i;
	}



}
/****************fonction d'insertionde type de retour d'une fonction *************/

void inserttyperetour(char * type){

	int i = 0;
	int j=case_vide(tab_rep);

	if(strcmp(type,"entier")==0)
		tab_rep[j]=0;
	else if(strcmp(type,"reel")==1)
		tab_rep[j]=1;
	else if(strcmp(type,"bool")==2)
		tab_rep[j]=2;
	else if(strcmp(type,"caractere")==3)
		tab_rep[j]=3;

	else {
		while(strcmp(tableLexico[i].lexeme,type)!=0){
			i=i+1;
		}
		tab_rep[j]=i;
	}
	
}



/********************fonction d'insertion de nb params d'une fonction***************/

/*void insertnbparamfct(int nbparam){

	int j=case_vide(tab_rep);
	tab_rep[j]=nbparam;
}*/

/*******************fonction d'insertion des params d'une fonctions****************/
/*void insertparamfct(char *idf,char* type){
	int j=case_vide(tab_rep);
	int i=0;
	while(strcmp(tableLexico[i].lexeme,idf)!=0){

		i=i+1;
	}

	tab_rep[j]=i;
	j++;

	if(strcmp(type,"entier")==0)
		tab_rep[j]=0;
	else if(strcmp(type,"reel")==1)
		tab_rep[j]=1;
	else if(strcmp(type,"bool")==2)
		tab_rep[j]=2;
	else if(strcmp(type,"caractere")==3)
		tab_rep[j]=3;

	else {
		while(strcmp(tableLexico[i].lexeme,type)!=0){
			i=i+1;
		}
		tab_rep[j]=i;
	}


}*/




/******************** l'element de la table de rep à la case de numero "num" **********************/

int case_element(int num){

	if(num>=0){

		return tab_rep[num];
	}

	else
		return -1;

}
