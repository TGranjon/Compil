#include "include.h"
#include "arbre.c"

/*
* Dans ce fichier devra être éffectué des tests de programmes et l'affichage
* de toutesles tables et de l'arbre.
*/
int main(int argc, char *argv[])
{
    cellule cel=creer_fils_frere(PROG,12,12);
    cellule fils=creer_fils_frere(IDF,42,42);
    concat_pere_fils(&cel,&fils);
    //concat_pere_fils(&cel,creer_fils_frere(IDF,1,1));
    //lire_cellule(&fils);
    lire_cellule(&cel);
    return 0;
}
