#include "region.h"

structRegion tabRegion[MAX_REGION];
int nbRegion = 0;

void init_tab_region() {
  int i;
  for (i=0 ; i<=MAX_REGION ; i++) {
      tabRegion[i].taille = 0;
      tabRegion[i].niveau_imbrication = -1;
  }
}

int ajouter_region(int niveau_imbrication){
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
