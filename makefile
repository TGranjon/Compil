tout :
	make y.tab.c
	make lex.yy.c
	make lex.yy.o
	make arbre.o
	make declaration.o
	make lexhc.o
	make region.o
	make Increment.o
	make table_rep.o
	make pile.o
	make projet

y.tab.c : projet.y
	yacc -d -v projet.y

lex.yy.c : projet.l
	lex projet.l

lex.yy.o : lex.yy.c
	gcc -c lex.yy.c

arbre.o : arbre.c arbre.h
	gcc -c arbre.c arbre.h

declaration.o : declaration.c declaration.h
	gcc -c declaration.c declaration.h

lexhc.o : lexhc.c lexhc.h
	gcc -c lexhc.c lexhc.h

region.o : region.c region.h
	gcc -c region.c region.h

Increment.o : Increment.c Increment.h
	gcc -c Increment.c Increment.h

table_rep.o : table_rep.c table_rep.h
	gcc -c table_rep.c table_rep.h

pile.o : pile.c pile.h
	gcc -c pile.c pile.h

projet : lex.yy.o y.tab.c
	gcc -o projet lex.yy.o y.tab.c arbre.o declaration.o lexhc.o region.o Increment.o table_rep.o -ly -ll

analyse :
	make y.tab.c
	make lex.yy.c
	make lex.yy.o


propre :
	rm lex.yy.c y.output y.tab.c y.tab.h *.o *.h.gch projet
