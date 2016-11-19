#include "arbre.h"
/*Possible inclusion de fichiers*/
/*Ce fichier devra être inclus au moins dans le .y*/

/*Déclaration des fonctions*/

cellule creer_arbre_vide()
{
  cellule cel;
  cel.noyau = -1;
  cel.lexeme = -1;
  cel.declaration = -1;
  cel.fils = NULL;
  cel.frere = NULL;
  return cel;
}

void concat_pere_fils(cellule * pere, cellule * fils) /*Permet d'ajouter la cellule fils en tant que fils de la cellule pere*/
{
  pere->fils=fils;
}

void concat_pere_frere(cellule * pere, cellule * frere) /*Permet d'ajouter la cellule frere en tant que frere de la cellule pere*/
{
  pere->frere=frere;
}

cellule creer_fils_frere(int noy, int lex, int decl)
{
  cellule cel = creer_arbre_vide();
  cel.noyau=noy;
  cel.lexeme=lex;
  cel.declaration=decl;
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
 */

char * lire_arbre(cellule * racine)
{
    char * texte;
    if(3<=racine->noyau<=14 || 29<=racine->noyau<=30)
    {
  sprintf(texte,"%d",racine->declaration);
      return strcat(lire_arbre(racine->fils),strcat(texte,lire_arbre(racine->fils->frere))); /*Cas de lecture complexe (info contenue dans les fils et les petits freres)*/
    }
    if(15<=racine->noyau<=18 || 26<=racine->noyau<=28 || racine->noyau==31 || 34<=racine->noyau<=36)
    {
  sprintf(texte,"%d",racine->declaration);
      return texte; /*Cas de lecture unique*/
    }
    if(1<=racine->noyau<=2 || 19<=racine->noyau<=20 || 21<=racine->noyau<=25 || 32<=racine->noyau<=33)
    {
  sprintf(texte,"%d",racine->declaration);
      return strcat(texte,lire_arbre(racine->fils)); /*Cas de lecture en ligne (info contenue uniquement dans les fils)*/
    }
    fprintf(stderr,"Erreur, noyau non reconnu\n");
}
/*Il faut renvoyer (l'opérateur)? et les deux opérandes (num declaration ou valeur)*/

void lire_cellule(cellule * racine) /*Affiche le contenu d'une cellule (pour des tests)*/
{
  fprintf(stdout,"Noyau = %d\nLexeme = %d\nDeclaration = %d\n",racine->noyau,racine->lexeme,racine->declaration);
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
