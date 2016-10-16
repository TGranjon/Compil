%{

%}
	%token PROG POINT_VIRGULE DEBUT FIN TYPE IDF DEUX_POINTS STRUCT FSTRUCT
	%token TABLEAU CROCHET_OUVRANT CROCHET_FERMANT VIRGULE POINT ENTIER
	%token REEL BOOLEEN CARACTERE CHAINE CSTE_ENTIERE VARIABLE PROCEDURE
	%token FONCTION PARENTHESE_OUVRANTE PARENTHESE_FERMANTE VIDE RETOURNE SI
	%token ALORS SINON TANT_QUE FAIRE OPAFF INF INFEGAL SUP SUEGAL CSTE_REELE
	%token DIFF ET OU CSTE_CARACTERE CSTE_CHAINE
%%
programme             : PROG corps ;

corps                 : liste_declarations liste_instructions
		              | liste_instructions
					  ;

liste_declarations    : declaration 
				      | liste_declarations POINT_VIRGULE declaration
					  ;

liste_instructions    : DEBUT suite_liste_inst FIN ;

suite_liste_inst      : instruction
			          | suite_liste_inst POINT_VIRGULE instruction
					  ;

declaration           : declaration_type
					  | declaration_variable
					  | declaration_procedure
					  | declaration_fonction
					  ;

declaration_type      : TYPE IDF DEUX_POINTS suite_declaration_type ;

suite_declaration_type : STRUCT liste_champs FSTRUCT
					   | nom_type TABLEAU dimension
					   ;

dimension             : CROCHET_OUVRANT liste_dimensions CROCHET_FERMANT ;

liste_dimensions      : une_dimension
					  | liste_dimensions VIRGULE une_dimension
					  ;

une_dimension         : expression POINT POINT expression

liste_champs          : un_champ
					  | liste_champs POINT_VIRGULE un_champ
					  ;

un_champ              : IDF DEUX_POINTS nom_type ;

nom_type              : type_simple
					  | IDF
					  ;

type_simple           : ENTIER
					  | REEL
					  | BOOLEEN
					  | CARACTERE
					  | CHAINE CROCHET_OUVRANT CSTE_ENTIERE CROCHET_FERMANT
					  ;

declaration_variable  : VARIABLE IDF DEUX_POINTS nom_type ;

declaration_procedure : PROCEDURE IDF liste_parametres corps ;

declaration_fonction  : FONCTION IDF liste_parametres RETOURNE type_simple corps
					  ;

liste_parametres      :
					  | PARENTHESE_OUVRANTE liste_param PARENTHESE_FERMANTE
					  ;

liste_param           : un_param
					  | liste_param POINT_VIRGULE un_param
					  ;

un_param              : IDF DEUX_POINTS type_simple ;

instruction           : affectation
					  | condition
					  | tant_que
					  | appel
					  | VIDE
					  | RETOURNE resultat_retourne
					  ;

resultat_retourne     :
					  | expression
					  ;

appel                 : IDF liste_arguments ;

liste_arguments       :
					  |  PARENTHESE_OUVRANTE liste_args PARENTHESE_FERMANTE
					  ;

liste_args            : un_arg
					  | liste_args VIRGULE un_arg
					  ;

un_arg                : expression ;

condition             :  SI expression
                         ALORS liste_instructions
                         SINON liste_instructions
					  ;

tant_que              : TANT_QUE expression FAIRE liste_instructions ;

affectation           : variable OPAFF expression1 ;

vararithmetique       : CSTE_ENTIERE
					  | CSTE_REELE
					  ;

varchar				  : CSTE_CARACTERE
					  | CSTE_CHAINE
					  ;

varcomparative		  : VIDE
					  | BOOL
					  ;

varlogique			  : ET
					  | OU
					  ;

comparateur           : SUP
					  | INF
					  | SUPEGAL
					  | INFEGAL
					  | EGAL
					  | DIFF
					  ;

expression1            : expression1 PLUS expression1
					   | expression1 MOINS expression1
					   | expression2;
					   ;

expression2			   : expression2 MULT expression2
					   | expression2 DIV expression2
					   | expression3
				       ;

expression3			   : vararithmetique
					   | PARENTHESE_OUVRANTE expression1 PARENTHESE_FERMANTE
					   ;

expressionchar		   : varchar PLUS varchar ;

expressioncomp		   : vararithmetique comparateur vararithmetique
					   | varchar comparateur varchar
					   | BOOL varlogique BOOL
					   | expressioncomp varlogique expressioncomp
					   | expressioncomp varlogique BOOL
					   ;

%%
