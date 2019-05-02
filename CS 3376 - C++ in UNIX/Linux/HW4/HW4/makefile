
#CS 3376

all: myscanner.c lex.yy.c y.tab.c
	gcc myscanner.c lex.yy.c y.tab.c -g -Wall -lfl -o myscanner

lex.yy.c: y.tab.c myscanner.l
	flex myscanner.l

y.tab.c: myscanner.y
	bison -dy myscanner.y
clean:
	rm -f myscanner
	rm -f lex.yy.c
	rm -f y.tab.c
	rm -f y.tab.h
