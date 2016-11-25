%{
  #include "include.h"
  #include "arbre.h"
  #include "increment.h"
  extern int yylex() ;
  extern int yyerror() ;
  extern int nb_lignes ;
  int num_region = 0;
  int NIS = 0;
  int case_vide = 0; 
  int nb_champs = 0;
  int nb_parametres = 0;
  int nb_dimensions = 0;
  int nb_declarations = 0;
  int nb_instructions = 0;
  int nb_arguments = 0;
%}
	%union{
      int entier;
      float reel;
      int booleen;
      char caractere;
	  char * chaine;
	  cellule * arbre
    }
	%token <arbre> PROG 
	%token FPROG
	%token <arbre> TABLEAU STRUCT
	%token FSTRUCT
	%token POINT_VIRGULE DEUX_POINTS CROCHET_OUVRANT CROCHET_FERMANT VIRGULE POINTPOINT PARENTHESE_OUVRANTE PARENTHESE_FERMANTE PIPE
	%token <arbre> OPAFF
	%token <arbre> EGAL INF INFEGAL SUP SUPEGAL DIFF
	%token <arbre> ENTIER REEL BOOL CARACTERE VARIABLE PROCEDURE FONCTION RETOURNE CHAINE
	%token <caractere> IDF 
	%token <arbre> POURCENT_ENTIER POURCENT_REEL POURCENT_CHAINE POURCENT_CARACTERE
	%token <arbre> SI ALORS SINON TANT_QUE FAIRE DEBUT FIN POUR JUSQUA 

	%token <arbre> VIDE
	%token <booleen> BOOLEEN <entier> CSTE_ENTIERE <reel> CSTE_REELE <chaine> CSTE_CHAINE <caractere> CSTE_CARACTERE
	%token <arbre> PLUS MOINS DIV MULT
	%token <arbre> ET OU
	%token <arbre> LIRE ECRIRE

	%type <arbre> programme corps liste_declarations liste_instructions suite_liste_inst declaration
	%type <arbre> declaration_procedure declaration_fonction liste_parametres liste_param un_param
	%type <arbre> instruction format pour suite_ecriture liste_variables resultat_retourne appel liste_arguments liste_args un_arg 
	%type <arbre> condition tant_que affectation variable element_tab vararithmetique varchar expression1 expression2 expression3 expressionchar expressioncomp
	%type <entier> varlogique comparateur
	%type <chaine> nom_type type_simple
%%
programme		: PROG  corps FPROG {$$=concat_pere_fils(creer_fils_frere(0,-1),$2);} 
				;

corps                   : liste_declarations {zero_nb_declarations(nb_declarations);} /*Renvoyer nb_declarations avant le reset*/ liste_instructions {$$=concat_pere_frere($1,$3);}
		      		    | liste_instructions {$$=$1;}
						;

liste_declarations	: declaration {$$=$1;incrementer_nb_declarations(nb_declarations);}
					| liste_declarations PIPE declaration {$$=concat_pere_frere($1,$3);incrementer_nb_declarations(nb_declarations);}
					;

liste_instructions	: DEBUT {incrementer_NIS(NIS);} suite_liste_inst FIN {$$=$3;decrementer_NIS(NIS);zero_nb_instructions(nb_instructions);} /*Renvoyer nb_instructions avant le reset*/
					;

suite_liste_inst	: instruction {$$=$1;incrementer_nb_instructions(nb_instructions);}
					| suite_liste_inst PIPE instruction {$$=concat_pere_frere($1,$3);incrementer_nb_instructions(nb_instructions);}
					;

declaration		: declaration_type POINT_VIRGULE {$$=NULL;} /*N'apparait pas dans l'arbre*/
				| declaration_variable POINT_VIRGULE {$$=NULL;} /*N'apparait pas dans l'arbre*/
				| declaration_procedure POINT_VIRGULE {$$=$1;}
				| declaration_fonction POINT_VIRGULE {$$=$1;}
				;

declaration_type	: type_simple IDF DEUX_POINTS suite_declaration_type ;

suite_declaration_type	: STRUCT liste_champs FSTRUCT {zero_nb_champs(nb_champs);} /*Renvoyer nb_champs avant le reset*//*Affecter la variable globale nouvelle case libre*/
						| nom_type TABLEAU dimension {} /*Affecter la variable globale nouvelle case libre*/
						;

dimension		: CROCHET_OUVRANT liste_dimensions CROCHET_FERMANT {zero_nb_dimensions(nb_dimensions);} /*Renvoyer nb_dimensions avant le reset*/
				;

liste_dimensions	: une_dimension {}
					| liste_dimensions VIRGULE une_dimension
					;

une_dimension		: CSTE_ENTIERE POINTPOINT CSTE_ENTIERE {incrementer_nb_dimensions(nb_dimensions);}
					;

liste_champs		: un_champ {} /*Appeler la variable globale case_vide apres avoir entré tous les champs (et les avoir comptes)*/
					| liste_champs PIPE un_champ {}
					;

un_champ		: IDF DEUX_POINTS nom_type {incrementer_nb_champs(nb_champs);}
				;

nom_type		: type_simple {$$=$1;}
				| IDF {$$=$1;}
				;

type_simple		: ENTIER {$$=$1;}
				| REEL {$$=$1;}
				| BOOLEEN {$$=$1;}
				| CARACTERE {$$=$1;}
				| CHAINE CROCHET_OUVRANT CSTE_ENTIERE CROCHET_FERMANT {} /*Comment representer le contenu de la chaine*/
				;

declaration_variable	: VARIABLE IDF DEUX_POINTS nom_type {}
						;

declaration_procedure	: PROCEDURE IDF liste_parametres corps {incrementer_num_region(num_region);incrementer_NIS(NIS);creer_fils_frere(19,avoir_num_lexico($2));} /*Affecter la variable globale nouvelle case libre*/
						;

declaration_fonction	: FONCTION IDF liste_parametres RETOURNE type_simple corps {incrementer_num_region(num_region);incrementer_NIS(NIS);creer_fils_frere(20,avoir_num_lexico($2));} /*Affecter la variable globale nouvelle case libre*/
						;

liste_parametres	: PARENTHESE_OUVRANTE PARENTHESE_FERMANTE {$$=creer_fils_frere(31,-1);zero_nb_parametres(nb_parametres);} /*Renvoyer nb_parametres a 0*/
					| PARENTHESE_OUVRANTE liste_param PARENTHESE_FERMANTE {$$=$2;zero_nb_parametres(nb_parametres);} /*Renvoyer nb_parametres avant le reset*/
					;

liste_param		: un_param {$$=$1;}
				| liste_param PIPE un_param {concat_pere_frere($1,$3);}
				;

un_param		: IDF DEUX_POINTS type_simple {creer_pere_frere(36,avoir_num_lexico ($1));incrementer_nb_parametres(nb_parametres);} /*Compter le nombre de parametres puis appeller case_vide*/
				;

instruction		: affectation POINT_VIRGULE {$$=$1;}
				| condition POINT_VIRGULE {$$=$1;}
				| tant_que POINT_VIRGULE {$$=$1;}
				| pour POINT_VIRGULE {$$=$1;}
				| appel POINT_VIRGULE {$$=$1;}
				| RETOURNE resultat_retourne POINT_VIRGULE {concat_pere_fils(creer_fils_frere(21,-1),$2);}
				| LIRE PARENTHESE_OUVRANTE liste_variables PARENTHESE_FERMANTE POINT_VIRGULE {concat_pere_fils(creer_fils_frere(32,-1),$3);}
				| ECRIRE PARENTHESE_OUVRANTE format suite_ecriture PARENTHESE_FERMANTE POINT_VIRGULE {concat_pere_fils(creer_fils_frere(33,-1),concat_pere_frere($3,$4));}
				;
					  
format			: POURCENT_ENTIER {$$=creer_fils_frere(15,$1);}
				| POURCENT_REEL {$$=creer_fils_frere(16,$1);}
				| POURCENT_CHAINE {$$=creer_fils_frere(17,$1);}
				| POURCENT_CARACTERE {$$=creer_fils_frere(18,$1);}
				;

pour			: POUR PARENTHESE_OUVRANTE variable JUSQUA variable PARENTHESE_FERMANTE FAIRE liste_instructions {concat_pere_fils(creer_pere_fils(24,-1),concat_pere_frere($3,concat_pere_frere($5,$8)));}
				;

suite_ecriture		: variable {$$=$1;}
					| suite_ecriture VIRGULE variable {$$=concat_pere_frere($1,$3);}
					;

liste_variables		: variable {$$=$1;}
					| liste_variables VIRGULE variable {$$=concat_pere_frere($1,$3);}
					;

resultat_retourne	: VIDE {$$=creer_fils_frere(31,-1);}
					| variable {$$=$1;}
					;

appel			: IDF liste_arguments {$$=concat_pere_frere(creer_fils_frere(36,$1),$2);}
				;

liste_arguments		: PARENTHESE_OUVRANTE PARENTHESE_FERMANTE {$$=NULL;zero_nb_arguments(nb_arguments);} /*Renvoyer nb_arguments a 0*/
					| PARENTHESE_OUVRANTE liste_args PARENTHESE_FERMANTE {$$=$2;zero_nb_arguments(nb_arguments);} /*Renvoyer nb_arguments avant le reset*/
					;

liste_args		: un_arg {$$=$1;}
				| liste_args VIRGULE un_arg {$$=concat_pere_frere($1,$3);}
				;

un_arg			: variable {$$=$1;incrementer_nb_arguments(nb_arguments);}
				;

condition		: SI PARENTHESE_OUVRANTE expressioncomp PARENTHESE_FERMANTE
				ALORS liste_instructions
				SINON liste_instructions {concat_pere_fils(creer_fils_frere(22,-1),concat_pere_frere($3,concat_pere_frere($6,$8)));}
				;

tant_que		: TANT_QUE PARENTHESE_OUVRANTE expressioncomp  PARENTHESE_FERMANTE FAIRE liste_instructions {concat_pere_fils(creer_fils_frere(23,-1),concat_pere_frere($3,$6));}
				;

affectation		: variable OPAFF variable {concat_pere_fils(creer_fils_frere(4,-1),concat_pere_frere($1,$3));}
				| varchar OPAFF expressionchar {concat_pere_fils(creer_fils_frere(4,-1),concat_pere_frere($1,$3));}
				| variable OPAFF expression1 {concat_pere_fils(creer_fils_frere(4,-1),concat_pere_frere($1,$3));}
				;

variable		: vararithmetique {$$=$1;}
				| varchar {$$=$1;}
				| IDF {$$=creer_fils_frere(36,$1);}
				| TABLEAU {$$=creer_fils_frere(1,$1);}
				| element_tab {$$=$1;}
				| BOOL {$$=creer_fils_frere(26,$1);}
				| appel {$$=$1;}
				;
					  
element_tab		: TABLEAU CROCHET_OUVRANT CSTE_ENTIERE CROCHET_FERMANT /*Comment indiquer l'element lui même ?*/
				;

vararithmetique		: CSTE_ENTIERE {$$=creer_fils_frere(27,$1);}
					| CSTE_REELE {$$=creer_fils_frere(28,$1;}
					;

varchar			: CSTE_CARACTERE {$$=creer_fils_frere(34,$1);}
				| CSTE_CHAINE {$$=creer_fils_frere(35,$1);}
				;

varlogique		: ET {$$=29};
				| OU {$$=30};
				;

comparateur		: SUP {$$=5};
				| INF {$$=6};
				| SUPEGAL {$$=7};
				| INFEGAL {$$=8};
				| EGAL {$$=9};
				| DIFF {$$=10};
				;

expression1		: expression1 PLUS expression1 {concat_pere_fils(creer_fils_frere(11,-1),concat_pere_frere($1,$3));}
				| expression1 MOINS expression1 {concat_pere_fils(creer_fils_frere(12,-1),concat_pere_frere($1,$3));}
				| expression2 {$$=$1;}
				;

expression2		: expression2 MULT expression2 {concat_pere_fils(creer_fils_frere(13,-1),concat_pere_frere($1,$3));}
				| expression2 DIV expression2 {concat_pere_fils(creer_fils_frere(14,-1),concat_pere_frere($1,$3));}
				| expression3 {$$=$1;}
				;

expression3		: variable {$$=$1;}
				| PARENTHESE_OUVRANTE expression1 PARENTHESE_FERMANTE {$$=$2;}
				;

expressionchar		: varchar PLUS varchar {concat_pere_fils(creer_fils_frere(11,-1),concat_pere_frere($1,$3));} /*C'est une concatenation et non une addition*/
					;

expressioncomp		: vararithmetique comparateur vararithmetique {concat_pere_fils(creer_fils_frere($2,-1),concat_pere_frere($1,$3));}
					| varchar comparateur varchar {concat_pere_fils(creer_fils_frere($2,-1),concat_pere_frere($1,$3));}
					| BOOL varlogique BOOL {concat_pere_fils(creer_fils_frere($2,-1),concat_pere_frere($1,$3));}
					| expressioncomp varlogique BOOL {concat_pere_fils(creer_fils_frere($2,-1),concat_pere_frere($1,$3));}
					| expressioncomp varlogique expressioncomp {concat_pere_fils(creer_fils_frere($2,-1),concat_pere_frere($1,$3));}
					| variable comparateur VIDE {concat_pere_fils(creer_fils_frere($2,-1),concat_pere_frere($1,$3));}
					| variable comparateur variable {concat_pere_fils(creer_fils_frere($2,-1),concat_pere_frere($1,$3));}
					;

%%
int yyerror()
{
  printf("Erreur de syntaxe en ligne %d\n",nb_lignes) ;
}
