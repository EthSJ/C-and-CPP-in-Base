%{


#include "y.tab.h"
%}
%option nounput
%option yylineno
%option noinput

%%
\# {yylval.val = yytext; return HASHTOKEN;}
\- {yylval.val = yytext; return DASHTOKEN;}
\, {yylval.val = yytext;  return COMMATOKEN;}
[0-9]* {yylval.val = yytext; return INTTOKEN;}
\n {yylval.val = yytext; return EOLTOKEN;}
[Jr]. {yylval.val = yytext; return JR;}
[Sr]. {yylval.val = yytext; return SR;}
M{0,4}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3}) {yylval.val = yytext;return ROMANTOKEN;}
[A-Z]\. {yylval.val = yytext; return NAME_INITIAL_TOKEN;}
[A-Z]([a-zA-Z]){1,2}[a-zA-Z]* {yylval.val = yytext; return NAMETOKEN;}
[A-Z]. {yylval.val = yytext; return NAME_INITIAL_TOKEN;}
[a-zA-Z0-9]* {yylval.val = yytext; return IDENTIFIER;}
.



%%

int yywrap(void)
{
return 1;
}
