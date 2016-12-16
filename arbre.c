#include "arbre.h"

/*Déclaration des fonctions*/

cellule creer_arbre_vide()
{
  cellule cel;
  cel.noyau = -1;
  cel.lexeme = -1;
  cel.fils = NULL;
  cel.frere = NULL;
  return cel;
}

cellule concat_pere_fils(cellule pere, cellule fils)
{
  pere.fils=fils;
  return pere;
}

cellule concat_pere_frere(cellule pere, cellule frere)
{
  pere.frere=frere;
  return pere;
}

cellule creer_fils_frere(int noy, int lex)
{
  cellule cel = creer_arbre_vide();
  cel.noyau=noy;
  cel.lexeme=lex;
  return cel;
}

int est_vide(cellule * cel)
{
  if(&cel->noyau==NULL)
    return 0; /*Condition vraie*/
  else return 1; /*Condition fausse*/
}

/*Lecture de l'arbre*/
  
/*Il faut lire l'arbre de haut en bas puis de droite a gauche
 *C'est à dire que le(s) fils doit être lu avant de lire le frère
 *La signification des entiers est contenue dans arbre.h
 */

char * lire_arbre(cellule * racine)
{
    char * texte;
    if(racine->noyau==268 || (272<=racine->noyau && racine->noyau<=278) || (308<=racine->noyau && racine->noyau<=311) || (312<=racine->noyau  & racine->noyau<=313))
    {
  sprintf(texte,"%d",racine->lexeme);
      return strcat(lire_arbre(racine->fils),strcat(texte,lire_arbre(racine->fils->frere))); /*Cas de lecture complexe (info contenue dans les fils et les petits freres)*/
    }
    if((288<=racine->noyau && racine->noyau<=292) || racine->noyau==281 || (304<=racine->noyau && racine->noyau<=307) || racine->noyau==302) /*Si c'est une constante, sa valeur est stockée dans lexeme*/
    {
  sprintf(texte,"%d",racine->lexeme);
      return texte; /*Cas de lecture unique*/
    }
    if((260<=racine->noyau && racine->noyau<=261) || (284<=racine->noyau && racine->noyau<=286) || racine->noyau==293 || racine->noyau==296 || (300<=racine->noyau && racine->noyau<=301) || (314<=racine->noyau && racine->noyau<=315))
    {
  sprintf(texte,"%d",racine->lexeme);
      return strcat(texte,lire_arbre(racine->fils)); /*Cas de lecture en ligne (info contenue uniquement dans les fils)*/
    }
    fprintf(stderr,"Erreur, noyau non reconnu\n");
}

void lire_cellule(cellule * racine)
{
  fprintf(stdout,"Noyau = %d\nLexeme = %d\n",racine->noyau,racine->lexeme);
  if(racine->fils==NULL)
  {
    fprintf(stdout,"Pas de fils\n");
  }
  else lire_cellule(racine->fils);
  if(racine->frere==NULL)
  {
    fprintf(stdout,"Pas de frere\n");
  }
  else lire_cellule(racine->frere);
}
