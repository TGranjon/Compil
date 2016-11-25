
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE_MAX 5000
#define TAILLE_DIMENSIONS 5
int  tabbornes[TAILLE_DIMENSIONS*2]=malloc((TAILLE_DIMENSIONS*2)*sizeof(int));
int * tab_rep[TAILLE_MAX]; // declaration table representation

void init_tab_rep(){       //intialisation de la table de rep
for(int i=0;i<tab_rep.length;i++)
tab_rep[i]=-1;

}//fin init_tab_rep


/*la fonction d'insertion ds la table de rep*/
// on met la case vide de tab_rep dans i
int insertstruct_tabrep(){
int i=case_vide(tab_rep);

int nature;
for(int j=0;j<=elt_tab_decl.length;j++){
if(elt_tab_decl[j]==i){
nature=elt_tab_decl[j].nature;

}//fin if
}//fin for
if(nature==1){
tab_rep[i]=nb_champs_struct;//nb champs à revoir
i++;
for(int j=0;j<nb_champs_struct;j++){

for(int p=0;p<=499;p++){
int resultat=strcmp(elt_tab_lexico[p].lexeme,IDF)
if(resultat==0)  //cherche le num lexico du idf
tab_rep[i]=p;break;

}//fin for
}//fin for
i++;

if(nom-type=="entier")
tab_rep[i]=1;
if(nom-type=="reel")
tab_rep[i]=2;
if(nom-type=="bool")
tab_rep[i]=3;
if(nom-type=="caractere")
tab_rep[i]=4;


else if (nom-type==IDF{//faux: à revoir
for (int p=0;p<=499;p++){
int resultat=strcmp(elt_tab_lexico[p].lexeme,IDF)
if(resultat==0)
tab_rep[i]=p;break;
}//fin for
}//fin if



}//fin insertstruct_tab



/*fonction qui renvoie la case vide dans une table*/
int case_vide(int [] tab){
for(int i=0;i<tab.length;i++){
if(tab[i]==-1)
return i;
}
}//fin case_vide


/* fonction sui récupere les bornes inf et sup d'un tableau */
//le tableau tbbornes est initialisé à la valeur -1
int bornes_tab(int borne1,int borne2){

for(int i=0;i<tabbornes.length;i++){
	tabbornes[i]=-1;
 }
int j=0;
while(tabbornes[j]!=-1){
	j++;
}
tabbornes[j]=borne1;
tabbornes[j+1]=borne2;
return tabbornes;
}//fin bornes_tab



void inserttab_tabrep(){

int i=case_vide(tab_rep);// cherche la position vide
int nature;
for(int j=0;j<=elt_tab_decl.length;j++){
if(elt_tab_decl[j]==i){
nature=elt_tab_decl[j].nature;

}//fin if
}//fin for

if(nature==2){

if(nom-type=="entier")
tab_rep[i]=1;
if(nom-type=="reel")
tab_rep[i]=2;
if(nom-type=="bool")
tab_rep[i]=3;
if(nom-type=="caractere")
tab_rep[i]=4;

else if (nom-type==IDF{//faux: à revoir
for (int p=0;p<=499;p++){
int resultat=strcmp(elt_tab_lexico[p].lexeme,IDF)
if(resultat==0)
tab_rep[i]=p;break;
}
}

i++;
/*nb de dimensions de tableaux à incrémenter dans le yacc*/
tab_rep[i]=nb_dimensions;
i++;
/*insertion des bornes inf et sup */

for(int j=0;j<=tabbornes.length;j++){
tab_rep[i]=tabbornes[j];
i++;
}





}//fin for
}//fin if
}//fin if
}//fin inserttab



/*fonction d'insertion de procedure*/
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

/*fonction d'insertion de fonction*/
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

