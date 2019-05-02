
%{

#include <stdio.h>
#include <stdlib.h>
  void yyerror(char *s);
  int yylex();
%}
%union{
  char* val;
 }
%start postal
%token <val> NAMETOKEN 1
%token <val> IDENTIFIER 2
%token <val> NAME_INITIAL_TOKEN 3
%token <val> ROMANTOKEN 4
%token <val> SR 5
%token <val> JR 6
%token <val> EOLTOKEN 7
%token <val> INTTOKEN 8
%token <val> COMMATOKEN 9
%token <val> DASHTOKEN 10
%token <val> HASHTOKEN 11
%type <val> postal address name person lastnom suff streetadd streetnum streetname loc town state zip

%%
postal : address EOLTOKEN postal
       | address
       ;
address : name streetadd  loc
        ;
name : person lastnom suff EOLTOKEN
     | person lastnom EOLTOKEN
     | error EOLTOKEN {printf("Bad name. . . skipping to newline.\n");}
     ;

person : NAMETOKEN { fprintf(stderr,"<First Name>%s</First Name>\n", $1);}
       | NAME_INITIAL_TOKEN {fprintf(stderr,"<First Name>%s</First Name>\n",$1);}
       ;

lastnom : NAMETOKEN {fprintf(stderr,"<Last Name>%s</Last Name>\n", $1);}
        ;

suff : SR {fprintf(stderr,"<Suffix>%s</Suffix>\n", $1);}
     | JR {fprintf(stderr,"<Suffix>%s</Suffix>\n", $1);}
     | ROMANTOKEN {fprintf(stderr,"<Suffix>%s</Suffix>\n", $1);}
     ;

streetadd : streetnum streetname INTTOKEN EOLTOKEN {fprintf(stderr,"<AptNum>%d</AptNum>\n", atoi($3));} 
     | streetnum streetname HASHTOKEN INTTOKEN EOLTOKEN {fprintf(stderr,"<AptNum>%d</AptNum>\n", atoi($4));}
          | streetnum streetname EOLTOKEN
          | error EOLTOKEN {printf("Bad street address. . . Skipping to newline\n"); }
          ;

streetnum : INTTOKEN {fprintf(stderr,"<HouseNum>%d</HouseNum>\n", atoi($1));}
          | IDENTIFIER {fprintf(stderr,"<HouseNum>%s</HouseNum>\n", $1);}
          ;

streetname : NAMETOKEN {fprintf(stderr,"<StreetName>%s</StreetName>\n",$1);}
           ;

loc : town COMMATOKEN state zip EOLTOKEN
    | error EOLTOKEN { printf("Bad location line. . . Skipping to newline\n");} 
    ;

town  : NAMETOKEN {fprintf(stderr, "<City>%s</City>\n", $1);}
      ;

state : NAMETOKEN {fprintf(stderr,"<State>%s</State>\n", $1);}
      ;

   zip   : INTTOKEN DASHTOKEN INTTOKEN {fprintf(stderr, "<Zip5>%d</Zip5>\n<Zip4>%d</Zip4>\n\n", atoi($1), atoi($3));}
     | INTTOKEN {fprintf(stderr, "<Zip5>%d</Zip5>\n\n", atoi($1));}
      ;

%%
 void yyerror(char *s) {;}
