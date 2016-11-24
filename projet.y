%{
  #include <stdio.h>
  #include <string.h>
  extern int yylex() ;
  extern int yyerror() ;
  extern int nb_lignes ;
  int num_region = 0;
  int NIS = 0;
  int case_vide = 0;
  int nb_champs = 0;
  int nb_parametres = 0;
  int nb_dimensions = 0;
  int nb_declarations = 0; /*A supprimer si inutile*/
  int nb_instructions = 0;
%}
	%token PROG FPROG
	%token TABLEAU STRUCT FSTRUCT
	%token POINT_VIRGULE DEUX_POINTS CROCHET_OUVRANT CROCHET_FERMANT VIRGULE POINTPOINT PARENTHESE_OUVRANTE PARENTHESE_FERMANTE OPAFF PIPE
	%token EGAL INF INFEGAL SUP SUPEGAL DIFF
	%token ENTIER REEL BOOL CARACTERE VARIABLE PROCEDURE FONCTION RETOURNE CHAINE IDF 
	%token POURCENT_ENTIER POURCENT_REEL POURCENT_CHAINE POURCENT_CARACTERE

	%token SI ALORS SINON TANT_QUE FAIRE DEBUT FIN POUR JUSQUA 

	%token VIDE
	%token BOOLEEN CSTE_ENTIERE CSTE_REELE CSTE_CHAINE CSTE_CARACTERE
	%token PLUS MOINS DIV MULT
	%token ET OU
	%token LIRE ECRIRE
%%
programme		: PROG corps FPROG {$$=$2;} 
				;

corps                   : liste_declarations liste_instructions 
		      		    | liste_instructions {$$=$1;}
						;

liste_declarations	: declaration {$$=$1;}
					| liste_declarations PIPE declaration
					;

liste_instructions	: DEBUT suite_liste_inst FIN 
					;

suite_liste_inst	: instruction {$$=$1;}
					| suite_liste_inst PIPE instruction
					;

declaration		: declaration_type POINT_VIRGULE
				| declaration_variable POINT_VIRGULE
				| declaration_procedure POINT_VIRGULE /*Si les commandes s'executent a la fin de la ligne : decrementer NIS*/
				| declaration_fonction POINT_VIRGULE
				;

declaration_type	: type_simple IDF DEUX_POINTS suite_declaration_type ;

suite_declaration_type	: STRUCT liste_champs FSTRUCT {inserer_declaration_struct(int num_decl);} /*num_decl vient de l'association des noms*/ /*Ajouter une variable globale nouvelle case libre*/
						| nom_type TABLEAU dimension {inserer_declaration_tableau(int num_decl);} /*num_decl vient de l'association des noms*/ /*Ajouter une variable globale nouvelle case libre*/
						;

dimension		: CROCHET_OUVRANT liste_dimensions CROCHET_FERMANT
				;

liste_dimensions	: une_dimension {$$=$1;}
					| liste_dimensions VIRGULE une_dimension
					;

une_dimension		: CSTE_ENTIERE POINTPOINT CSTE_ENTIERE
					;

liste_champs		: un_champ {$$=$1;} /*Appeler la variable globale case_vide apres avoir entre tous les champs (et les avoir comptes)*/
					| liste_champs PIPE un_champ /*On ne compte que un_champ, liste_champs est l'appel recursif*/
					;

un_champ		: IDF DEUX_POINTS nom_type /*On peut aussi compter les champs ici*/
				;

nom_type		: type_simple {$$=$1;}
				| IDF {$$=$1;}
				;

type_simple		: ENTIER {$$=$1;}
				| REEL {$$=$1;}
				| BOOLEEN {$$=$1;}
				| CARACTERE {$$=$1;}
				| CHAINE CROCHET_OUVRANT CSTE_ENTIERE CROCHET_FERMANT {$$=$1[$3];}
				;

declaration_variable	: VARIABLE IDF DEUX_POINTS nom_type {inserer_declaration_variable(int num_decl);} /*num_decl vient de l'association des noms*/
						;

declaration_procedure	: PROCEDURE IDF liste_parametres corps /*Incrementer num region et NIS*//*Creer nouveau arbre*/{inserer_declaration_procedure(int num_decl);} /*num_decl vient de l'association des noms*//*Ajouter une variable globale nouvelle case libre*/
						;

declaration_fonction	: FONCTION IDF liste_parametres RETOURNE type_simple corps /*Incrementer num region et NIS*//*Creer nouveau arbre*/{inserer_declaration_fonction(int num_decl);} /*num_decl vient de l'association des noms*//*Ajouter une variable globale nouvelle case libre*/
						;

liste_parametres	: PARENTHESE_OUVRANTE PARENTHESE_FERMANTE {$$=NULL;}/*Est-ce possible?*/
					| PARENTHESE_OUVRANTE liste_param PARENTHESE_FERMANTE {$$=$2;}
					;

liste_param		: un_param {$$=$1;}
				| liste_param PIPE un_param
				;

un_param		: IDF DEUX_POINTS type_simple ; /*Compter le nombre de parametres puis appeller case_vide*/

instruction		: affectation POINT_VIRGULE {$$=$1;}
				| condition POINT_VIRGULE {$$=$1;}
				| tant_que POINT_VIRGULE {$$=$1;}
				| pour POINT_VIRGULE {$$=$1;}
				| appel POINT_VIRGULE {$$=$1;}
				| VIDE {$$=$1;}
				| RETOURNE resultat_retourne POINT_VIRGULE {$$=$2;}
				| LIRE PARENTHESE_OUVRANTE liste_variables PARENTHESE_FERMANTE POINT_VIRGULE {fscanf(STDIN,$3);} /*C'est etrange ca*/
				| ECRIRE PARENTHESE_OUVRANTE format suite_ecriture PARENTHESE_FERMANTE POINT_VIRGULE
				;
					  
format			: POURCENT_ENTIER {$$=$1;}
				| POURCENT_REEL {$$=$1;}
				| POURCENT_CHAINE {$$=$1;}
				| POURCENT_CARACTERE {$$=$1;}
				;

pour			: POUR PARENTHESE_OUVRANTE variable JUSQUA variable PARENTHESE_FERMANTE FAIRE liste_instructions {concat_pere_fils(creer_pere_fils(24,-1,-1),concat_pere_frere(creer_pere_fils(/*De*/),concat_pere_frere(creer_pere_frere(/*A*/),creer_pere_frere(/*Instruction*/))));}
				;

suite_ecriture		:
					| variable {$$=$1;}
					| suite_ecriture VIRGULE variable {$$=$1,$3;}
					;

liste_variables		: variable {$$=$1;}
					| liste_variables VIRGULE variable {$$=$1,$3;}
					;

resultat_retourne	: VIDE {$$=$1;}
					| variable {$$=$1;}
					;

appel			: IDF liste_arguments {$1($2);}
				;

liste_arguments		: PARENTHESE_OUVRANTE PARENTHESE_FERMANTE {$$=NULL;}/*Est-ce possible?*/
					| PARENTHESE_OUVRANTE liste_args PARENTHESE_FERMANTE {$$=$2;}
					;

liste_args		: un_arg {$$=$1;}
				| liste_args VIRGULE un_arg {$$=$1,$2;}
				;

un_arg			: variable {$$=$1;}
				;

condition		: SI PARENTHESE_OUVRANTE expressioncomp PARENTHESE_FERMANTE
				ALORS liste_instructions
				SINON liste_instructions {concat_pere_fils(creer_fils_frere(22,-1,-1),concat_pere_frere(creer_fils_frere(/*condition*/),concat_pere_frere(creer_fils_frere(/*then*/),creer_fils_frere(/*else*/))));} /*Appel a la methode numero_lexicographique*/
				;

tant_que		: TANT_QUE PARENTHESE_OUVRANTE expressioncomp  PARENTHESE_FERMANTE FAIRE liste_instructions {concat_pere_fils(creer_fils_frere(23,-1-1),concat_pere_frere(creer_fils_frere(/*condition*/),creer_fils_frere(/*instruction*/)));}
				;

affectation		: variable OPAFF variable {concat_pere_fils(creer_fils_frere(4,-1,-1),concat_pere_frere(creer_fils_frere(/*var1*/),creer_fils_frere(/*var2*/)));}
				| varchar OPAFF expressionchar {concat_pere_fils(creer_fils_frere(4,-1,-1),concat_pere_frere(creer_fils_frere(/*var1*/),creer_fils_frere(/*var2*/)));}
				| variable OPAFF expression1 {concat_pere_fils(creer_fils_frere(4,-1,-1),concat_pere_frere(creer_fils_frere(/*var1*/),creer_fils_frere(/*var2*/)));}
				;

variable		: vararithmetique {$$=$1;}
				| varchar {$$=$1;}
				| IDF {$$=$1;}
				| TABLEAU {$$=$1;}
				| element_tab {$$=$1;}
				| BOOL {$$=$1;}
				| appel {$$=$1;}
				;
					  
element_tab		: TABLEAU CROCHET_OUVRANT CSTE_ENTIERE CROCHET_FERMANT {$1[$3];} /*Comment indiquer l'element lui meme*/
				;

vararithmetique		: CSTE_ENTIERE {$$=$1;}
					| CSTE_REELE {$$=$1;}
					;

varchar			: CSTE_CARACTERE {$$=$1;}
				| CSTE_CHAINE {$$=$1}; /*Chaine n'est pas reconnu par la pile*/
				;

varlogique		: ET {$$=$1};
				| OU {$$=$1};
				;

comparateur		: SUP {$$=$1};
				| INF {$$=$1};
				| SUPEGAL {$$=$1};
				| INFEGAL {$$=$1};
				| EGAL {$$=$1};
				| DIFF {$$=$1};
				;

expression1		: expression1 PLUS expression1 {concat_pere_fils(creer_fils_frere(11,-1,-1),concat_pere_frere(creer_fils_frere(/*var1*/),creer_fils_frere(/*var2*/)));}
				| expression1 MOINS expression1 {concat_pere_fils(creer_fils_frere(12,-1,-1),concat_pere_frere(creer_fils_frere(/*var1*/),creer_fils_frere(/*var2*/)));}
				| expression2 {$$=$1;}
				;

expression2		: expression2 MULT expression2 {concat_pere_fils(creer_fils_frere(13,-1,-1),concat_pere_frere(creer_fils_frere(/*var1*/),creer_fils_frere(/*var2*/)));}
				| expression2 DIV expression2 {concat_pere_fils(creer_fils_frere(14,-1,-1),concat_pere_frere(creer_fils_frere(/*var1*/),creer_fils_frere(/*var2*/)));}
				| expression3 {$$=$1;}
				;

expression3		: variable {$$=$1;}
				| PARENTHESE_OUVRANTE expression1 PARENTHESE_FERMANTE {$$=$2;}
				;

expressionchar		: varchar PLUS varchar {concat_pere_fils(creer_fils_frere(11,-1,-1),concat_pere_frere(creer_fils_frere(/*var1*/),creer_fils_frere(/*var2*/)));} /*C'est une concatenation et non une addition*/
					;

expressioncomp		: vararithmetique comparateur vararithmetique {$$=$1 $2 $3;} /*creer arbre comparaison*/
					| varchar comparateur varchar {$$=$1 $2 $3;}
					| BOOL varlogique BOOL {$$=$1 $2 $3;}
					| expressioncomp varlogique BOOL {$$=$1 $2 $3;}
					| expressioncomp varlogique expressioncomp {$$=$1 $2 $3;}
					| variable comparateur VIDE {$$=$1 $2 $3;}
					| variable comparateur variable {$$=$1 $2 $3;}
					;

%%
int yyerror()
{
  printf("Erreur de syntaxe en ligne %d\n",nb_lignes) ;
}
