

/*********taille_tableau**********************************************/

int taille_tableau(int tabbornes[]){
	int i;
	int diff;
	int taille=0;
	while(i<TAILLE_DIMENSIONS*2){
		diff=tabbornes[i+1]-tabbornes[i];
		taille*=diff;
		i=i+2;
	}
	return taille;
}
/************************ tailleStruct()*******************************/
int tailleStruct(char *type){
	int taille=0;
	int i=0;
	if(strcmp(type,"entier")==0)
		taille+=1;
	else if(strcmp(type,"reel")==1)
		taille+=1;
	else if(strcmp(type,"bool")==2)
		taille+=1;
	else if(strcmp(type,"caractere")==3)
		taille+=1;
		//le cas d'un champ de type struct ou un tableau
	else { 
		while(strcmp(tableLexico[i].lexeme,type)!=0){
			i=i+1;
		}
		if(tabDecla[i].nature==1){//le cas struct declarée,sa taille est calculée 
			taille+=tabDecla[i].execution;
		}
		if(tabDecla[i].nature==2){//cas tableau bien sur deja declaré,sa taille est calculée aussi
			taille+=tabDecla[i].execution;
		} 
	
}
/*********************************************************************/
int calculer_taille(int X) { 
  if((X==0)||(X==1)||(X==2)||(X==3)) //X représente le num lexicographique
	{
		return 1;
	}
  else if(tabDecla[X].nature == 3)//le cas d'une variable qui n'est pa de type base
	{
		int Y = tabDecla[X].description;// récupération de son type
		calculer_taille(Y);// calcul de taille de son type
	}
	//Cas complexe des fcts, procs, tab, structs ou la fonction doit etre appellee recursivement sur chaque element de l'objet
	
 else  if(tabDecla[X].nature == 1)//le cas d'une structure
	{
		//return tailleStruct() 
		
	}
else  if(tabDecla[X].nature == 2)//le cas d'un tableau
	{
		//return taille_tableau
		
	}

}
/********************************************************************************/
int taille_region(int num){//numero de la region
	int taille = 0; 
	
	for (int i = 0; i < DECLARATION_MAX; i++){
		if (tabDecla[i].region == num ){
			taille += calculer_taille(tabDecla[i].description);
		}
	}
	
	return taille;
}



