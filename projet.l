%{
#include "arbre.h"
#include "y.tab.h"
#include "Increment.h"
int nb_lignes=1;
%}

%%
"/"[\*](([^\"\*])|([\*]*[\"][^\"]*[\"])|([\*]+[^\*\/\"]))*[\*]+"/"	/* Commentaire sur plusieurs lignes */
"//".*$ 								/* Commentaire sur une ligne. */
"pg"[0-9 a-z A-Z]+				{yylval.entier=atoi(yytext);return PROG;}
"sortie"						{yylval.entier=atoi(yytext);return FPROG;}
"tab"[0-9 a-z A-Z]+				{yylval.entier=atoi(yytext);return TABLEAU;}
"struct"[0-9 a-z A-Z]+			{yylval.entier=atoi(yytext);return STRUCT;}
"fstruct"						{yylval.entier=atoi(yytext);return FSTRUCT;}

\; 								{return POINT_VIRGULE;}
\: 								{return DEUX_POINTS;}
\[ 								{return CROCHET_OUVRANT;}
\] 								{return CROCHET_FERMANT;}
\,								{return VIRGULE;}
".."							{return POINTPOINT;}
\( 								{return PARENTHESE_OUVRANTE;}
\) 								{return PARENTHESE_FERMANTE;}
:= 								{return OPAFF;}
\|								{return PIPE;}
\< 								{return INF;}
\> 								{return SUP;}
"<=" 							{return INFEGAL;}
">=" 							{return SUPEGAL;}
"<>" 							{return DIFF;}
"=="							{return EGAL;}
\+								{return PLUS;}
\-								{return MOINS;}
\*								{return MULT;}
\/								{return DIV;}

\%entier						{return POURCENT_ENTIER;}
\%reel							{return POURCENT_REEL;}
\%chaine						{return POURCENT_CHAINE;}
\%caractere						{return POURCENT_CARACTERE;}

"entier" 						{yylval.entier=atoi(yytext);return ENTIER;}
"reel" 							{yylval.entier=atoi(yytext);return REEL;}
"booleen"						{yylval.booleen=atoi(yytext);return BOOLEEN;}
"caractere"						{yylval.entier=atoi(yytext);return CARACTERE;}
"chaine"						{yylval.entier=atoi(yytext);return CHAINE;}
"var" 							{yylval.entier=atoi(yytext);return VARIABLE;}
"proc" 							{yylval.entier=atoi(yytext);return PROCEDURE;}
"fct" 							{yylval.entier=atoi(yytext);return FONCTION;}
	
"retourne"						{return RETOURNE;}
"si" 							{return SI;}
"alors" 						{return ALORS;}
"sinon" 						{return SINON;}
"tant que" 						{return TANT_QUE;}
"faire" 						{return FAIRE;}
"debut" 						{return DEBUT;}
"fin" 							{return FIN;}
"pour"							{return POUR;}
"jusqua"						{return JUSQUA;}

"vrai"|"faux" 					{yylval.entier=atoi(yytext);return BOOL;}
0|[1-9][0-9]* 					{yylval.entier=atoi(yytext);return CSTE_ENTIERE;}
[1-9]*[0-9]\.[0-9]+ 			{yylval.entier=atoi(yytext);return CSTE_REELE;} /*au moins un chiffre après le point*/
"et" 							{return ET;}
"ou" 							{return OU;}
"vide"							{return VIDE;}

"lire"							{return LIRE;}
"ecrire"						{return ECRIRE;}

\'[a-z A-Z]\' 					{yylval.entier=atoi(yytext);return CSTE_CARACTERE;}
\"[a-z A-Z]+\" 					{yylval.entier=atoi(yytext);return CSTE_CHAINE;}
[A-Z] 							{yylval.entier=atoi(yytext);return IDF;}

\n 						   		{nb_lignes++;}
%%
