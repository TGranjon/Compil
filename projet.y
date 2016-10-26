%{
  #include <stdio.h>
  extern int yylex() ;
  extern int yyerror() ;
  extern int nb_lignes ;
%}
	%token PROG FPROG
	%token TABLEAU STRUCT FSTRUCT
	%token POINT_VIRGULE DEUX_POINTS CROCHET_OUVRANT CROCHET_FERMANT VIRGULE POINT POINTPOINT PARENTHESE_OUVRANTE PARENTHESE_FERMANTE OPAFF PIPE
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
programme		: PROG corps FPROG;

corps                   : liste_declarations liste_instructions
		        | liste_instructions
			;

liste_declarations	: declaration 
			| liste_declarations PIPE declaration
			;

liste_instructions	: DEBUT suite_liste_inst FIN ;

suite_liste_inst	: instruction
			| suite_liste_inst PIPE instruction
			;

declaration		: declaration_type POINT_VIRGULE
			| declaration_variable POINT_VIRGULE
			| declaration_procedure POINT_VIRGULE
			| declaration_fonction POINT_VIRGULE
			;

declaration_type	: type_simple IDF DEUX_POINTS suite_declaration_type ;

suite_declaration_type	: STRUCT liste_champs FSTRUCT
			| nom_type TABLEAU dimension
			;

dimension		: CROCHET_OUVRANT liste_dimensions CROCHET_FERMANT ;

liste_dimensions	: une_dimension
			| liste_dimensions VIRGULE une_dimension
			;

une_dimension		: expression1 POINTPOINT expression1; /*Le resultat devra etre entier*/

liste_champs		: un_champ
			| liste_champs PIPE un_champ
			;

un_champ		: IDF DEUX_POINTS nom_type ;

nom_type		: type_simple
			| IDF
			;

type_simple		: ENTIER
			| REEL
			| BOOLEEN
			| CARACTERE
			| CHAINE CROCHET_OUVRANT CSTE_ENTIERE CROCHET_FERMANT
			;

declaration_variable	: VARIABLE IDF DEUX_POINTS nom_type ;

declaration_procedure	: PROCEDURE IDF liste_parametres corps ;

declaration_fonction	: FONCTION IDF liste_parametres RETOURNE type_simple corps
			;

liste_parametres	: PARENTHESE_OUVRANTE PARENTHESE_FERMANTE
			| PARENTHESE_OUVRANTE liste_param PARENTHESE_FERMANTE
			;

liste_param		: un_param
			| liste_param PIPE un_param
			;

un_param		: IDF DEUX_POINTS type_simple ;

instruction		: affectation POINT_VIRGULE
			| condition POINT_VIRGULE
			| tant_que POINT_VIRGULE
			| pour POINT_VIRGULE
			| appel POINT_VIRGULE
			| VIDE
			| RETOURNE resultat_retourne POINT_VIRGULE
			| LIRE PARENTHESE_OUVRANTE liste_variables PARENTHESE_FERMANTE POINT_VIRGULE
			| ECRIRE PARENTHESE_OUVRANTE format suite_ecriture PARENTHESE_FERMANTE POINT_VIRGULE
			;
					  
format			: POURCENT_ENTIER
			| POURCENT_REEL
			| POURCENT_CHAINE
			| POURCENT_CARACTERE
			;

pour			: POUR PARENTHESE_OUVRANTE variable JUSQUA variable PARENTHESE_FERMANTE FAIRE liste_instructions;

suite_ecriture		:
			| variable
			| suite_ecriture VIRGULE variable
			;

liste_variables		: variable
			| liste_variables VIRGULE variable
			;

resultat_retourne	: VIDE
			| variable
			;

appel			: IDF liste_arguments ;

liste_arguments		: PARENTHESE_OUVRANTE PARENTHESE_FERMANTE
			| PARENTHESE_OUVRANTE liste_args PARENTHESE_FERMANTE
			;

liste_args		: un_arg
			| liste_args VIRGULE un_arg
			;

un_arg			: variable ;

condition		: SI PARENTHESE_OUVRANTE expressioncomp PARENTHESE_FERMANTE
				ALORS liste_instructions
				SINON liste_instructions
			;

tant_que		: TANT_QUE PARENTHESE_OUVRANTE expressioncomp PARENTHESE_FERMANTE FAIRE liste_instructions ;

affectation		: variable OPAFF variable
			| varchar OPAFF expressionchar
			| variable OPAFF expression1
			;

variable		: vararithmetique
			| varchar
			| IDF
			| TABLEAU
			| element_tab
			| BOOL
			| appel
			;
					  
element_tab		: TABLEAU CROCHET_OUVRANT CSTE_ENTIERE CROCHET_FERMANT ;

vararithmetique		: CSTE_ENTIERE
			| CSTE_REELE
			;

varchar			: CSTE_CARACTERE
			| CSTE_CHAINE
			;

varlogique		: ET
			| OU
			;

comparateur		: SUP
			| INF
			| SUPEGAL
			| INFEGAL
			| EGAL
			| DIFF
			;

expression1		: expression1 PLUS expression1
			| expression1 MOINS expression1
			| expression2;
			;

expression2		: expression2 MULT expression2
			| expression2 DIV expression2
			| expression3
			;

expression3		: variable
			| PARENTHESE_OUVRANTE expression1 PARENTHESE_FERMANTE
			;

expressionchar		: varchar PLUS varchar ;

expressioncomp		: vararithmetique comparateur vararithmetique
			| varchar comparateur varchar
			| BOOL varlogique BOOL
			| expressioncomp varlogique BOOL
			| expressioncomp varlogique expressioncomp
			| variable comparateur VIDE
			| variable comparateur variable
			;

%%
int yyerror()
{
  printf("Erreur de syntaxe en ligne %d\n",nb_lignes) ;
}
