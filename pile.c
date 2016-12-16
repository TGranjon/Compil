#include <unistd.h>

int pile[15];
int indice=0;//indice de la case libre qui est renvoyé à chaque fois on empile



//intilaiser la pile à -1
void init_pile(){
	int i;

	for(i=0;i<15;i++){
		pile[i]=-1;

		}
}


//empiler: sachant de num region dans yacc s'incremente à chaque fois on rencontre une proc/fct

void empile_region(int num_region){
  pile[indice]=num_region;
  ++indice;

}

void depile_region(){

	pile[indice-1]=-1;//on met la case d'indice-1 à la valeur -1

	--indice;//on met à jour l'indice libre 

}
