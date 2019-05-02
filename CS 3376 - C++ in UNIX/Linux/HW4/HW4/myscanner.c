
#include <stdio.h>
#include <string.h>
#include <libgen.h>

extern int yylex();
extern int yylineno;
extern char* yytext;
extern FILE* yyin;
extern int yyparse();

char* name[] = {"NULL", "NAME", "IDENTIFIER", "NAME_INITIAL", "ROMAN", "SR", "JR", "EOLTOKEN", "INT", "COMMA", "DASH", "HASH"};

int main(int argc, char* argv[]) 
{
  if(strcmp("scanner",basename(argv[0])) == 0)
    {
      int ntoken;
      ntoken = yylex();
      printf("Operating scan mode.\n\n");
      while(ntoken) 
	{
	  if(strcmp("\n", yytext)==0)
	    {
	      printf("yylex returned %s token (%d)\n", name[ntoken], 267);
	    }
	  else
	    { printf("yylex returned %s token (%s)\n", name[ntoken], yytext); }
	  ntoken =yylex();
	}
    }
  else if(strcmp("parser",basename(argv[0])) == 0)
    {
      printf("Operating in parse mode.\n\n");
      yyparse();
      printf("\nParse Successful!\n");
    }
  return 0;
}
