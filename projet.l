%{
#include "y.tab.h"
int nb_lignes=1;
%}

%%
"pg[0-9 a-z A-Z]+" 			{return PROG;}

"tab[0-9 a-z A-Z]+" 		{return TABLEAU;}
"struct[0-9 a-z A-Z]+" 		{return STRUCT;}
"fstruct[0-9 a-z A-Z]+" 	{return FSTRUCT;}

\; 							{return POINT_VIRGULE;}
\: 							{return DEUX_POINTS;}
\{ 							{return CROCHET_OUVRANT;}
\} 							{return CROCHET_FERMANT;}
\,							{return VIRGULE;}
\. 							{return POINT;}
\( 							{return PARENTHESE_OUVRANTE;}
\) 							{return PARENTHESE_FERMANTE;}
:= 							{return OPAFF;}

\< 							{return INF;}
\> 							{return SUP;}
"<=" 						{return INFEGAL;}
">=" 						{return SUPEGAL;}
"<>" 						{return DIFF;}
"=="						{return EGAL;}					/*ajout*/

entier 						{return ENTIER;}
reel 						{return REEL;}
booleen 					{return BOOLEEN;}
caractere 					{return CARACTERE;}
var 						{return VARIABLE;}
proc 						{return PROCEDURE;}
fct 						{return FONCTION;}
retourne					{return RETOURNE;}
[a-z A-Z]+ 					{return CHAINE;}
[A-Z] 						{return IDF;}

si 							{return SI;}
alors 						{return ALORS;}
sinon 						{return SINON;}
"tant que" 					{return TANT_QUE;}
faire 						{return FAIRE;}
debut 						{return DEBUT;}
fin 						{return FIN;}

vrai|faux 					{return BOOLEEN;}
0|[1-9][0-9]* 				{return CSTE_ENTIERE;}
[1-9]*[0-9]\.[0-9]+ 		{return CSTE_REELE;}			/*au moins un chiffre après le point*/
\'[a-z A-Z]\' 				{return CSTE_CARACTERE;}
\"[a-z A-Z]+\" 				{return CSTE_CHAINE};

et 							{return ET;}
ou 							{return OU;}
\n 							{nb_lignes++;}

vide						{return VIDE;}			/*ajout*/

lire						{return(LIRE);}          /*ajout*/
ecrire						{return(ECRIRE);}		 /*ajout*/
%%
