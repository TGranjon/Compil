#include "table_rep.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE_MAX 5000
#define TAILLE_DIMENSIONS 5


int  tabbornes[TAILLE_DIMENSIONS*2]=malloc((TAILLE_DIMENSIONS*2)*sizeof(int));
/**************************declaration table representation*****************************************/

int * tab_rep[TAILLE_MAX];  
/**************************intialisation de la table de rep*****************************************/
void init_tab_rep(){      
for(int i=0;i<tab_rep.length;i++)
tab_rep[i]=-1;

}


/****************************insertion struct ds la table de rep***********************************/

int insertnbchamps(int nb_champs){


int i=case_vide(tab_rep);
tab_rep[i]=nb_champs;
}
/*************************************** insertion champs****************************************/
void insertchampstruct(char* idf,char *type){
int i=0;
while(stcmp(TableLexico[i].lexeme,idf)!=0){

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
while(stcmp(TableLexico[i].lexeme,type)!=0){

i=i+1;
}
tab_rep[j]=i;

}



/*************************************** la case vide dans une table********************************/
int case_vide(int [] tab){
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
	while(stcmp(TableLexico[i].lexeme,type)!=0){
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
/**********************************fonction d'insertion de procedure********************************/
//nb params procedure à récuperer dans le yacc

void insertproc(){

int i=case_vide(tab_rep);
int nature;
for(int j=0;j<=elt_tab_decl.length;j++){
if(elt_tab_decl[j]==i){
nature=elt_tab_decl[j].nature;

}
}

if (nature==4){
tab_rep[i]=nb_params_proc;
i++;
for(int j=1;j<=nb_params_proc;j++){

for (int p=0;p<=499;p++){
int resultat=strcmp(elt_tab_lexico[p].lexeme,IDF/*idf param*/)
if(resultat==0)
tab_rep[i]=p;break;}

i++;
if(nom-type/*du param*/=="entier")
tab_rep[i]=1;
if(nom-type=="reel")
tab_rep[i]=2;
if(nom-type=="bool")
tab_rep[i]=3;
if(nom-type=="caractere")
tab_rep[i]=4;

}

}
}//fin insertproc
 
/************************************fonction d'insertion de fonction*******************************/
// type_retour à récupérer dans le yacc
//nb params fonction à récupoerer dans le yacc
void insertfct(){

int i=case_vide(tab_rep);
int nature;
for(int j=0;j<=elt_tab_decl.length;j++){
if(elt_tab_decl[j]==i){
nature=elt_tab_decl[j].nature;

}
}

if(nature==5){

tab_rep[i]==type_retour;
i++;
tab_rep[i]=nb_params_fct;
i++;
for(int j=1;j<=nb_params_fct;j++){

for (int p=0;p<=499;p++){
int resultat=strcmp(elt_tab_lexico[p].lexeme,IDF/*idf param*/)
if(resultat==0)
tab_rep[i]=p;break;}

i++;
if(nom-type/*du param*/=="entier")
tab_rep[i]=1;
if(nom-type=="reel")
tab_rep[i]=2;
if(nom-type=="bool")
tab_rep[i]=3;
if(nom-type=="caractere")
tab_rep[i]=4;

}


}
}//fin insertfct


/******************** l'element de la table de rep à la case de numero "num" **********************/

int case_element(int num){

if(num>=0){

	return tab_rep[num];
}

else
	return -1;

}
/***************************************************************************************************/
//incrementation de nb param
int incremente_nbparam(){
nb_parametres++;

return nb_parametres;


}
//incrementation de nb champs
int incremente_nbchamps(){
nb_champs++;
return nb_champs;

}

//incrementation de nb champs
int incremente_nbarg(){
nb_arguments++;
return nb_arguments;

}
