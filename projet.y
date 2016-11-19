%{
  #include <stdio.h>
  #include <string.h>
  extern int yylex() ;
  extern int yyerror() ;
  extern int nb_lignes ;
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
				| declaration_procedure POINT_VIRGULE
				| declaration_fonction POINT_VIRGULE
				;

declaration_type	: type_simple IDF DEUX_POINTS suite_declaration_type ;

suite_declaration_type	: STRUCT liste_champs FSTRUCT
						| nom_type TABLEAU dimension
						;

dimension		: CROCHET_OUVRANT liste_dimensions CROCHET_FERMANT ;

liste_dimensions	: une_dimension {$$=$1;}
					| liste_dimensions VIRGULE une_dimension
					;

une_dimension		: expression1 POINTPOINT expression1 /*Le resultat devra etre entier*/
					;

liste_champs		: un_champ {$$=$1;}
					| liste_champs PIPE un_champ
					;

un_champ		: IDF DEUX_POINTS nom_type ;

nom_type		: type_simple {$$=$1;}
				| IDF {$$=$1;}
				;

type_simple		: ENTIER {$$=$1;}
				| REEL {$$=$1;}
				| BOOLEEN {$$=$1;}
				| CARACTERE {$$=$1;}
				| CHAINE CROCHET_OUVRANT CSTE_ENTIERE CROCHET_FERMANT {$$=$1[$3];}
				;

declaration_variable	: VARIABLE IDF DEUX_POINTS nom_type ;

declaration_procedure	: PROCEDURE IDF liste_parametres corps ;

declaration_fonction	: FONCTION IDF liste_parametres RETOURNE type_simple corps
						;

liste_parametres	: PARENTHESE_OUVRANTE PARENTHESE_FERMANTE {$$=NULL;}/*Est-ce possible?*/
					| PARENTHESE_OUVRANTE liste_param PARENTHESE_FERMANTE {$$=$2;}
					;

liste_param		: un_param {$$=$1;}
				| liste_param PIPE un_param
				;

un_param		: IDF DEUX_POINTS type_simple ;

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

pour			: POUR PARENTHESE_OUVRANTE variable JUSQUA variable PARENTHESE_FERMANTE FAIRE liste_instructions {for($3;$5){$8};} /*Verifier*/
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
				SINON liste_instructions {if($3){$6}else{$8};}
				;

tant_que		: TANT_QUE PARENTHESE_OUVRANTE expressioncomp  PARENTHESE_FERMANTE FAIRE liste_instructions {while($3){$6};}
				;

affectation		: variable OPAFF variable {$1=$3;}
				| varchar OPAFF expressionchar {$1=$3;}
				| variable OPAFF expression1 {$1=$3;}
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
				| CSTE_CHAINE {$$=$1};
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

expression1		: expression1 PLUS expression1 {$$=$1+$3;}
				| expression1 MOINS expression1 {$$=$1-$3;}
				| expression2 {$$=$1;}
				;

expression2		: expression2 MULT expression2 {$$=$1*$3;}
				| expression2 DIV expression2 {$$=$1/$3;}
				| expression3 {$$=$1;}
				;

expression3		: variable {$$=$1;}
				| PARENTHESE_OUVRANTE expression1 PARENTHESE_FERMANTE {$$=$2;}
				;

expressionchar		: varchar PLUS varchar {$$=strcat($1,$3);}
					;

expressioncomp		: vararithmetique comparateur vararithmetique {$$=$1 $2 $3;}
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
