#include "region.h"

structRegion tabRegion[MAX_REGION];
int nbRegion = 0;

void init_tab_region() {
  int i;
  for (i=0 ; i<=MAX_REGION ; i++) {
      tabRegion[i].taille = 0;
      tabRegion[i].niveau_imbrication = -1;
	  tabRegion[i].arbre = creer_arbre_vide();
  }
}

int ajouter_region(int taille, int niveau_imbrication, cellule arbre){
  if(nbRegion > MAX_REGION) {
    printf("Erreur, la limite mémoire a été atteinte !\n");
    exit(-1);
  }
  tabRegion[nbRegion].niveau_imbrication = niveau_imbrication;
  nbRegion++;
  return 0;
}

void affiche_tab_region(structRegion region[]) {

  int i;
  printf("\n-----Table des régions-----\n");
  printf(" Region\t|Taille\t| NIS\t| Arbre\n");
  for (i=0 ; i<=nbRegion ; i++)
    printf(" %d\t| %d\t| %d\t|\n",i, region[i].taille, region[i].niveau_imbrication);
}


/*int calculer_taille(int X) { /*X sera a modifier cf region.h*/
//  if((X==0)||(X==1)||(X==2)||(X==3)) /*X représente le num lexicographique*/
//	{
//		return 1;
//	}
//  else if(X.nature == 3)
//	{
//		int Y = /*Fonction de recuperation du contenu de la case X dans la table de representation*/
//		calculer_taille(Y);
//	}
//  else 
//	{
		/*Cas complexe des fonctions, procedures, tableaux, structures ou la fonction doit etre appellee recursivement sur chaque element de l'objet*/
//	}
//}
