#ifndef ARBRE_H
#define ARBRE_H

#include "include.h"

/*Déclaration de l'arbre abstrait*/

struct cellule
{
  int noyau; /*Correspond aux codes ci-dessus*/
  int lexeme; /*Code lexicographique correspondant*/
  struct cellule * fils; /*Pointeur vers le premier fils*/
  struct cellule * frere; /*Pointeur vers le premier frere*/
};

/*Les constantes ont leur valeur dans lexeme*/
typedef struct cellule cellule;

/*Définition des codes/noyau*/
/*Tiré de y.tab.h*/
/*
*  #define PROG 258
*  #define FPROG 259
*  #define TABLEAU 260
*  #define STRUCT 261
*  #define FSTRUCT 262
*  #define POINT_VIRGULE 263
*  #define DEUX_POINTS 264
*  #define CROCHET_OUVRANT 265
*  #define CROCHET_FERMANT 266
*  #define VIRGULE 267
*  #define POINTPOINT 268
*  #define PARENTHESE_OUVRANTE 269
*  #define PARENTHESE_FERMANTE 270
*  #define PIPE 271
*  #define OPAFF 272
*  #define EGAL 273
*  #define INF 274
*  #define INFEGAL 275
*  #define SUP 276
*  #define SUPEGAL 277
*  #define DIFF 278
*  #define ENTIER 279
*  #define REEL 280
*  #define BOOL 281
*  #define CARACTERE 282
*  #define VARIABLE 283
*  #define PROCEDURE 284
*  #define FONCTION 285
*  #define RETOURNE 286
*  #define CHAINE 287
*  #define IDF 288
*  #define POURCENT_ENTIER 289
*  #define POURCENT_REEL 290
*  #define POURCENT_CHAINE 291
*  #define POURCENT_CARACTERE 292
*  #define SI 293
*  #define ALORS 294
*  #define SINON 295
*  #define TANT_QUE 296
*  #define FAIRE 297
*  #define DEBUT 298
*  #define FIN 299
*  #define POUR 300
*  #define JUSQUA 301
*  #define VIDE 302
*  #define BOOLEEN 303
*  #define CSTE_ENTIERE 304
*  #define CSTE_REELE 305
*  #define CSTE_CHAINE 306
*  #define CSTE_CARACTERE 307
*  #define PLUS 308
*  #define MOINS 309
*  #define DIV 310
*  #define MULT 311
*  #define ET 312
*  #define OU 313
*  #define LIRE 314
*  #define ECRIRE 315
*/

/*Prototype des fonctions*/

cellule creer_arbre_vide(); /*Creation et initialisation d'un arbre vide*/

cellule concat_pere_fils(cellule pere, cellule fils); /*Permet d'ajouter la cellule fils en tant que fils de la cellule pere*/

cellule concat_pere_frere(cellule pere, cellule frere); /*Permet d'ajouter la cellule frere en tant que frere de la cellule pere*/

cellule creer_fils_frere(int noy, int lex);

int est_vide(cellule * cel);

char * lire_arbre(cellule * racine); /*Affiche le contenu d'une cellule (pour des tests)*/

void lire_cellule(cellule * racine);

#endif
