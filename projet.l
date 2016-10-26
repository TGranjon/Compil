%{
#include "y.tab.h"
int nb_lignes=1;
%}

%%
<<<<<<< HEAD
"pg"[0-9 a-z A-Z]+			{return PROG;}
"sortie"					{return FPROG;}
"tab"[0-9 a-z A-Z]+		    {return TABLEAU;}
"struct"[0-9 a-z A-Z]+		{return STRUCT;}
"fstruct"				    {return FSTRUCT;}
=======
"/"[\*](([^\"\*])|([\*]*[\"][^\"]*[\"])|([\*]+[^\*\/\"]))*[\*]+"/"	/* Commentaire sur plusieurs lignes */
"//".*$ 								/* Commentaire sur une ligne. */
"pg"[0-9 a-z A-Z]+					{return PROG;}
"sortie"						{return FPROG;}
"tab"[0-9 a-z A-Z]+					{return TABLEAU;}
"struct"[0-9 a-z A-Z]+					{return STRUCT;}
"fstruct"						{return FSTRUCT;}
>>>>>>> master

\; 							{return POINT_VIRGULE;}
\: 							{return DEUX_POINTS;}
\[ 							{return CROCHET_OUVRANT;}
\] 							{return CROCHET_FERMANT;}
\,							{return VIRGULE;}
\. 							{return POINT;}
".."							{return POINTPOINT;}
\( 							{return PARENTHESE_OUVRANTE;}
\) 							{return PARENTHESE_FERMANTE;}
:= 							{return OPAFF;}
\|							{return PIPE;}
\< 							{return INF;}
\> 							{return SUP;}
"<=" 							{return INFEGAL;}
">=" 							{return SUPEGAL;}
"<>" 							{return DIFF;}
"=="							{return EGAL;}
\+							{return PLUS;}
\-							{return MOINS;}
\*							{return MULT;}
\/							{return DIV;}

<<<<<<< HEAD
\%entier					{return POURCENT_ENTIER;}
\%reel						{return POURCENT_REEL;}
\%chaine					{return POURCENT_CHAINE;}
\%caractere					{return POURCENT_CARACTERE;}

"entier" 					{return ENTIER;}
"reel" 						{return REEL;}
"booleen"					{return BOOLEEN;}
"caractere"					{return CARACTERE;}
"chaine"					{return CHAINE;}
"var" 						{return VARIABLE;}
"proc" 						{return PROCEDURE;}
"fct" 						{return FONCTION;}

"retourne"					{return RETOURNE;}
"si" 						{return SI;}
"alors" 					{return ALORS;}
"sinon" 					{return SINON;}
"tant que" 					{return TANT_QUE;}
"faire" 					{return FAIRE;}
"debut" 					{return DEBUT;}
"fin" 						{return FIN;}
"pour"						{return POUR;}
"jusqua"					{return JUSQUA;}

"vrai"|"faux" 				{return BOOL;}
0|[1-9][0-9]* 				{return CSTE_ENTIERE;}
[1-9]*[0-9]\.[0-9]+ 		{return CSTE_REELE;}/*au moins un chiffre après le point*/
"et" 						{return ET;}
"ou" 						{return OU;}
"vide"						{return VIDE;}

"lire"						{return LIRE;}
"ecrire"					{return ECRIRE;}

\'[a-z A-Z]\' 				{return CSTE_CARACTERE;}
\"[a-z A-Z]+\" 				{return CSTE_CHAINE;}
[A-Z] 						{return IDF;}

\n 						    {nb_lignes++;}
%%
