id [a-zA-Z_][a-zA-Z0-9_]*
digits [+-]?[0-9]+
floats [+-]?[0-9]*\.[0-9]+
exp ({floats}|{digits})[eE]{digits}
keyword int|float|char|long|double|if|else|struct|break|short|unsigned|do|for|sizeof|typedef|case|while|switch|return

%{
#include <stdio.h>
#include <string.h>
int i, com=0, scom=0;
char symb_tab[30][30];
int store_symb_tab(char id[]);
%}

%%
\n   {scom=0;}
"//" {scom=1; fprintf(yyout, "\n%10s \t single line comment",yytext);}
"/*" {com=1;  fprintf(yyout, "\n%10s \t start of multiline comment",yytext);}
"*/" {com=0;  fprintf(yyout, "\n%10s \t end of multiline comment",yytext);}
"<=" {if(!com&&!scom) fprintf(yyout, "\n%10s \t relational operator less than or equal to",yytext);}
"<"  {if(!com&&!scom) fprintf(yyout, "\n%10s \t relational operator less than",yytext);}
">=" {if(!com&&!scom) fprintf(yyout, "\n%10s \t relational operator greater than or equal to",yytext);}
">"  {if(!com&&!scom) fprintf(yyout, "\n%10s \t relational operator greater than",yytext);}
"==" {if(!com&&!scom) fprintf(yyout, "\n%10s \t relational operator equal to",yytext);}
"!=" {if(!com&&!scom) fprintf(yyout, "\n%10s \t relational operator not equal to",yytext);}
"="  {if(!com&&!scom) fprintf(yyout, "\n%10s \t assignment operator",yytext);}
{keyword} {if(!com&&!scom) fprintf(yyout, "\n%10s \t keyword",yytext);}
{id} {
        if (!com&&!scom) {
            fprintf(yyout, "\n%10s \t identifier",yytext);
            store_symb_tab(yytext);
        }
     }
{exp} {if(!com&&!scom) fprintf(yyout, "\n%10s \t exponential number",yytext);}
{floats} {if(!com&&!scom) fprintf(yyout, "\n%10s \t floating point number",yytext);}
{digits} {if(!com&&!scom) fprintf(yyout, "\n%10s \t integer",yytext);}
.
%%

int main(int argc, char** argv)
{
	yyin =fopen(argv[1],"r");
	yyout=fopen("y.txt","w");

    fprintf(yyout, "%s\n","---------------------------------------------");
    fprintf(yyout, "%10s \t Token","Symbol");
    fprintf(yyout, "\n%s","---------------------------------------------");

	yylex();

    printf("\nFinished Lexical Analysis\n\n");
    printf("Symbol Table Generated\n\n");
    i=-1;
    while( symb_tab[++i][0] ) {
        printf("%2d  %s\n",i,symb_tab[i]);
    }
    printf("\n");

    return 0;
}

int store_symb_tab(char id[])
{
    int i;
    for (i=0; i<30; i++)
    {
        if ( strcmp(id,symb_tab[i])==0 ) {
            return 1;
        } else if (symb_tab[i][0]=='\0') {
            strcpy(symb_tab[i],id);
            return 0;
        }
    }
    return -1;
}

int yywrap()
{
    return 1;
}
