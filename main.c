#include "include.h"
#include "arbre.c"

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
