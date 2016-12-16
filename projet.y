%{
  #include "include.h"
  #include "arbre.h"
  #include "Increment.h"
  #include "declaration.h"
  #include "lexhc.h"
  #include "table_rep.h"
  #include "region.h"
  
  extern int yylex() ;
  extern int yyerror() ;
  extern int nb_lignes ;
  int num_region = 0;
  int NIS = 0;
  int nb_champs = 0;
  int nb_parametres = 0;
  int nb_dimensions = 0;
%}
	%union{
      int entier;
      float reel;
      int booleen;
      char caractere;
	  char * chaine;
	  cellule arbre;
    }
	%token <entier> PROG 
	%token FPROG
	%token <chaine> TABLEAU <arbre> STRUCT
	%token FSTRUCT
	%token POINT_VIRGULE DEUX_POINTS CROCHET_OUVRANT CROCHET_FERMANT VIRGULE POINTPOINT PARENTHESE_OUVRANTE PARENTHESE_FERMANTE PIPE
	%token <entier> OPAFF
	%token <entier> EGAL INF INFEGAL SUP SUPEGAL DIFF
	%token <entier> ENTIER REEL IDF CARACTERE VARIABLE PROCEDURE FONCTION RETOURNE CHAINE
	%token <booleen> BOOL
	%token <entier> POURCENT_ENTIER POURCENT_REEL POURCENT_CHAINE POURCENT_CARACTERE
	%token <entier> SI ALORS SINON TANT_QUE FAIRE DEBUT FIN POUR JUSQUA 

	%token <entier> VIDE
	%token <booleen> BOOLEEN <entier> CSTE_ENTIERE CSTE_REELE CSTE_CHAINE CSTE_CARACTERE
	%token <entier> PLUS MOINS DIV MULT
	%token <entier> ET OU
	%token <entier> LIRE ECRIRE

	%type <arbre> programme corps liste_declarations liste_instructions suite_liste_inst declaration
	%type <arbre> declaration_procedure declaration_fonction liste_parametres liste_param un_param
	%type <arbre> instruction format pour suite_ecriture liste_variables resultat_retourne appel liste_arguments liste_args un_arg 
	%type <arbre> condition tant_que affectation variable vararithmetique varchar expression1 expression2 expression3 expressionchar expressioncomp element_tab
	%type <arbre> nom_type type_simple
	%type <entier> varlogique comparateur
%%
programme		: PROG  corps FPROG {$$=concat_pere_fils(creer_fils_frere(258,-1),$2);} 
				;

corps                   : liste_declarations liste_instructions {$$=concat_pere_frere($1,$2);}
		      		    | liste_instructions {$$=$1;}
						;

liste_declarations	: declaration {$$=$1;}
					| liste_declarations PIPE declaration {$$=concat_pere_frere($1,$3);}
					;

liste_instructions	: DEBUT {NIS++;} suite_liste_inst FIN {$$=$3;NIS--;}
					;

suite_liste_inst	: instruction {$$=$1;}
					| suite_liste_inst PIPE instruction {$$=concat_pere_frere($1,$3);}
					;

declaration		: declaration_type POINT_VIRGULE {$$=creer_arbre_vide();}
				| declaration_variable POINT_VIRGULE {$$=creer_arbre_vide();}
				| declaration_procedure POINT_VIRGULE {$$=$1;}
				| declaration_fonction POINT_VIRGULE {$$=$1;}
				;

declaration_type	: type_simple IDF DEUX_POINTS suite_declaration_type ;

suite_declaration_type	: STRUCT liste_champs FSTRUCT {/*insertnbchamps(nb_champs);zero_nb_champs(nb_champs);*/ajouter_struct($1.lexeme,num_region,case_vide(tab_rep));}
						| nom_type TABLEAU dimension {/*inserttypetab(lexeme($1.lexeme))*/;ajouter_tab($1.lexeme,num_region-NIS,case_vide(tab_rep));}
						;

dimension		: CROCHET_OUVRANT liste_dimensions CROCHET_FERMANT {/*insertnbdimensions(nb_dimensions);zero_nb_dimensions(nb_dimensions);*/}
				;

liste_dimensions	: une_dimension
					| liste_dimensions VIRGULE une_dimension
					;

une_dimension		: CSTE_ENTIERE POINTPOINT CSTE_ENTIERE {/*incrementer_nb_dimensions(nb_dimensions);*/}
					;

liste_champs		: un_champ
					| liste_champs PIPE un_champ
					;

un_champ		: IDF DEUX_POINTS nom_type {/*incrementer_nb_champs(nb_champs);insertchampstruct(lexeme($1),lexeme($3.lexeme));*/}
				;

nom_type		: type_simple {$$=$1;}
				| IDF {$$=creer_fils_frere(288,$1);}
				;

type_simple		: ENTIER {$$=creer_fils_frere(279,0);}
				| REEL {$$=creer_fils_frere(280,1);}
				| BOOLEEN {$$=creer_fils_frere(303,2);}
				| CARACTERE {$$=creer_fils_frere(282,3);}
				| CHAINE CROCHET_OUVRANT CSTE_ENTIERE CROCHET_FERMANT {$$=creer_fils_frere(306,-1);}
				;

declaration_variable	: VARIABLE IDF DEUX_POINTS nom_type {ajouter_var($2,num_region,lexeme($4.lexeme));}
						;

declaration_procedure	: PROCEDURE IDF {num_region++;NIS++;} liste_parametres corps {ajouter_proc($2,num_region-NIS,case_vide(tab_rep),num_region);creer_fils_frere(284,$2);}
						;

declaration_fonction	: FONCTION IDF {num_region++;NIS++;} liste_parametres RETOURNE type_simple corps {ajouter_fct($2,num_region-NIS,case_vide(tab_rep),num_region);creer_fils_frere(285,$2);}
						;

liste_parametres	: PARENTHESE_OUVRANTE PARENTHESE_FERMANTE {$$=creer_arbre_vide();/*zero_nb_parametres(nb_parametres);insertnbparam(0);*/}
					| PARENTHESE_OUVRANTE liste_param PARENTHESE_FERMANTE {$$=$2;/*insertnbparam(nb_parametres);zero_nb_parametres(nb_parametres);*/}
					;

liste_param		: un_param {$$=$1;} 
				| liste_param PIPE un_param {concat_pere_frere($1,$3);}
				;

un_param		: IDF DEUX_POINTS type_simple {creer_fils_frere(288,$1);/*incrementer_nb_parametres(nb_parametres);insertparam(lexeme($1),lexeme($3.lexeme));*/}
				;

instruction		: affectation POINT_VIRGULE {$$=$1;}
				| condition POINT_VIRGULE {$$=$1;}
				| tant_que POINT_VIRGULE {$$=$1;}
				| pour POINT_VIRGULE {$$=$1;}
				| appel POINT_VIRGULE {$$=$1;}
				| RETOURNE resultat_retourne POINT_VIRGULE {concat_pere_fils(creer_fils_frere(286,-1),$2);/*inserttyperetour(lexeme($2.lexeme));*/}
				| LIRE PARENTHESE_OUVRANTE liste_variables PARENTHESE_FERMANTE POINT_VIRGULE {concat_pere_fils(creer_fils_frere(314,-1),$3);}
				| ECRIRE PARENTHESE_OUVRANTE format suite_ecriture PARENTHESE_FERMANTE POINT_VIRGULE {concat_pere_fils(creer_fils_frere(315,-1),concat_pere_frere($3,$4));}
				;
					  
format			: POURCENT_ENTIER {$$=creer_fils_frere(289,$1);}
				| POURCENT_REEL {$$=creer_fils_frere(290,$1);}
				| POURCENT_CHAINE {$$=creer_fils_frere(291,$1);}
				| POURCENT_CARACTERE {$$=creer_fils_frere(292,$1);}
				;

pour			: POUR PARENTHESE_OUVRANTE variable JUSQUA variable PARENTHESE_FERMANTE FAIRE liste_instructions {concat_pere_fils(creer_fils_frere(300,-1),concat_pere_frere($3,concat_pere_frere($5,$8)));}
				;

suite_ecriture		: variable {$$=$1;}
					| suite_ecriture VIRGULE variable {$$=concat_pere_frere($1,$3);}
					;

liste_variables		: variable {$$=$1;}
					| liste_variables VIRGULE variable {$$=concat_pere_frere($1,$3);}
					;

resultat_retourne	: VIDE {$$=creer_fils_frere(302,-1);}
					| variable {$$=$1;}
					;

appel			: IDF liste_arguments {$$=concat_pere_frere(creer_fils_frere(288,$1),$2);}
				;

liste_arguments		: PARENTHESE_OUVRANTE PARENTHESE_FERMANTE {$$=creer_arbre_vide();}
					| PARENTHESE_OUVRANTE liste_args PARENTHESE_FERMANTE {$$=$2;}
					;

liste_args		: un_arg {$$=$1;}
				| liste_args VIRGULE un_arg {$$=concat_pere_frere($1,$3);}
				;

un_arg			: variable {$$=$1;}
				;

condition		: SI PARENTHESE_OUVRANTE expressioncomp PARENTHESE_FERMANTE
				ALORS liste_instructions
				SINON liste_instructions {concat_pere_fils(creer_fils_frere(293,-1),concat_pere_frere($3,concat_pere_frere($6,$8)));}
				;

tant_que		: TANT_QUE PARENTHESE_OUVRANTE expressioncomp  PARENTHESE_FERMANTE FAIRE liste_instructions {concat_pere_fils(creer_fils_frere(296,-1),concat_pere_frere($3,$6));}
				;

affectation		: variable OPAFF variable {concat_pere_fils(creer_fils_frere(272,-1),concat_pere_frere($1,$3));}
				| varchar OPAFF expressionchar {concat_pere_fils(creer_fils_frere(272,-1),concat_pere_frere($1,$3));}
				| variable OPAFF expression1 {concat_pere_fils(creer_fils_frere(272,-1),concat_pere_frere($1,$3));}
				;

variable		: vararithmetique {$$=$1;}
				| varchar {$$=$1;}
				| IDF {$$=creer_fils_frere(288,$1);}
				| TABLEAU {$$=creer_fils_frere(260,avoir_num_lexico($1));}
				| element_tab {$$=$1;}
				| BOOL {$$=creer_fils_frere(281,$1);}
				| appel {$$=$1;}
				;
					  
element_tab		: TABLEAU CROCHET_OUVRANT CSTE_ENTIERE CROCHET_FERMANT {$$=creer_arbre_vide(260,avoir_num_lexico($1));}
				;

vararithmetique		: CSTE_ENTIERE {$$=creer_fils_frere(304,$1);}
					| CSTE_REELE {$$=creer_fils_frere(305,$1);}
					;

varchar			: CSTE_CARACTERE {$$=creer_fils_frere(307,$1);}
				| CSTE_CHAINE {$$=creer_fils_frere(306,$1);}
				;

varlogique		: ET {$$=312;}
				| OU {$$=313;}
				;

comparateur		: SUP {$$=276;}
				| INF {$$=274;}
				| SUPEGAL {$$=277;}
				| INFEGAL {$$=275;}
				| EGAL {$$=273;}
				| DIFF {$$=278;}
				;

expression1		: expression1 PLUS expression1 {concat_pere_fils(creer_fils_frere(308,-1),concat_pere_frere($1,$3));}
				| expression1 MOINS expression1 {concat_pere_fils(creer_fils_frere(309,-1),concat_pere_frere($1,$3));}
				| expression2 {$$=$1;}
				;

expression2		: expression2 MULT expression2 {concat_pere_fils(creer_fils_frere(311,-1),concat_pere_frere($1,$3));}
				| expression2 DIV expression2 {concat_pere_fils(creer_fils_frere(310,-1),concat_pere_frere($1,$3));}
				| expression3 {$$=$1;}
				;

expression3		: variable {$$=$1;}
				| PARENTHESE_OUVRANTE expression1 PARENTHESE_FERMANTE {$$=$2;}
				;

expressionchar		: varchar PLUS varchar {concat_pere_fils(creer_fils_frere(308,-1),concat_pere_frere($1,$3));} /*C'est une concatenation et non une addition*/
					;

expressioncomp		: vararithmetique comparateur vararithmetique {concat_pere_fils(creer_fils_frere($2,-1),concat_pere_frere($1,$3));}
					| varchar comparateur varchar {concat_pere_fils(creer_fils_frere($2,-1),concat_pere_frere($1,$3));}
					| BOOL varlogique BOOL {concat_pere_fils(creer_fils_frere($2,-1),concat_pere_frere(creer_fils_frere(281,$1),creer_fils_frere(281,$3)));}
					| expressioncomp varlogique BOOL {concat_pere_fils(creer_fils_frere($2,-1),concat_pere_frere($1,creer_fils_frere(281,$3)));}
					| expressioncomp varlogique expressioncomp {concat_pere_fils(creer_fils_frere($2,-1),concat_pere_frere($1,$3));}
					| variable comparateur VIDE {concat_pere_fils(creer_fils_frere($2,-1),concat_pere_frere($1,creer_fils_frere(302,$3)));}
					| variable comparateur variable {concat_pere_fils(creer_fils_frere($2,-1),concat_pere_frere($1,$3));}
					;

%%
int yyerror()
{
  printf("Erreur de syntaxe en ligne %d\n",nb_lignes) ;
  exit(-1);
}

int main(){
	init_tab_lex();
	init_hash_code(tab_hash_code);
	init_tab_decla();
	init_tab_region();
	init_tab_rep(tab_rep);
	yyparse();


	affiche_table_hash_code(tab_hash_code);
	affiche_table_lexico(tableLexico,10);
	affiche_table_decla(tabDecla);

	init_tab_rep(tab_rep);
}
