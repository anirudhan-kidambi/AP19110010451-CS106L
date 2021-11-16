/*
 C program for lexical analyser:
 Keywords:
 Identifier:
 Number : Integers
 Relational Operators: <, <=, >, >=, ==, !=
 Multi line Comments:

 Symbol table implementation: Array
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

clock_t t1, t2;
float time_taken;

char keyword[30][30] = {
    "int","while","break","for","do","if","float","char",
    "switch", "double","short","long","unsigned","sizeof","else","register",
    "extern","static","auto ","case","break","volatile","enum","typedef"
};

char id[20], num[10];

// symbol table as a 2D array of characters
char symb_tab[100][30];

int check_keyword(char s[])
{
    int i;
    for (i=0; i<24; i++)
        if (strcmp(s,keyword[i]) == 0)
            return 1;

    return 0;
}

/*
 Write a function to store identifier in symbol table.
 Check whether the id is already available in the symbol table.
 If available,  ignore. otherwise add it.
 */
int store_symb_tab(char id[])
{
    int i;
    for (i=0; i<100; i++)
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

int main()
{
    FILE *fp1,*fp2,*fp3;
    char c;
    char op_prefix;

    int state=0;
    int i=0,j=0;
    int status;

    fp1 = fopen("input/float.txt","r");        //input
    fp2 = fopen("y.txt","w");                   //output
    fp3 = fopen("report/arr_float.txt","w");   //report

    fprintf(fp3,"-------------------------------\n");
    fprintf(fp3,"identifier \t task \t time\n");
    fprintf(fp3,"-------------------------------\n");

    while ( (c=fgetc(fp1)) != EOF )
    {
        switch (state)
        {
            case 0:
                if(isalpha(c)) {
                    state=1;
                    id[i++]=c;
                } else if (isdigit(c)) {
                    state=3;
                    num[j++]=c;
                } else if (c=='<' || c=='>') {
                    state=5;
                    op_prefix=c;
                } else if(c=='=' || c=='!') {
                    state=8;
                    op_prefix=c;
                } else if(c=='/') {
                    state=10;
                } else if (c==' ' || c=='\t' || c=='\n') {
                    state=0;
                } else {
                    fprintf(fp2,"\n%c",c);
                }
                break;

            case 1:
                if (isalnum(c)) {
                    state=1;
                    id[i++]=c;
                } else {
                    id[i]='\0';
                    if (check_keyword(id)) {
                        fprintf(fp2,"\n%s : keyword",id);
                    } else {
                        fprintf(fp2,"\n%s : identifier",id);

                        // call a function which stores id in symbol table
                        // and returns a status

                        t1 = clock();
                        status = store_symb_tab(id);
                        t2 = clock();

                        time_taken = (double)(t2-t1)/CLOCKS_PER_SEC;


                        switch (status)
                        {
                            case 0:
                                fprintf(fp3,"%10s \t insert\t %f s\n", id, time_taken);
                                break;
                            case 1:
                                fprintf(fp3,"%10s \t search\t %f s\n", id, time_taken);
                                break;
                            case -1:
                                fprintf(fp3,"*** Symbol Table is full !\n");
                        }

                    }

                    state=0;
                    i=0;
                    ungetc(c,fp1);
                }
                break;

            case 3:
                if (isdigit(c)) {
                    num[j++]=c;
                    state=3;
                } else {
                    num[j]='\0';
                    fprintf(fp2,"\n%s : number",num);
                    state=0;
                    j=0;
                    ungetc(c,fp1);
                }
                break;

            case 5:
                if (c=='=') {
                    fprintf(fp2,"\nrelational operator ");

                    // write code to print specific operator like <= or >=
                    fprintf(fp2,"%c=", op_prefix);

                    op_prefix = '\0';
                    state=0;
                } else {
                    fprintf(fp2,"\nrelational operator ");

                    // write code to print specific operator like <, >
                    fprintf(fp2,"%c", op_prefix);

                    op_prefix = '\0';
                    state=0;
                    ungetc(c,fp1);
                }
                break;

            case 8:
                if (c=='=') {
                    fprintf(fp2,"\nrelational operator ");

                    // write code to print specific operator like == or !=
                    fprintf(fp2,"%c=", op_prefix);

                    op_prefix = '\0';
                    state=0;
                } else {
                    ungetc(c,fp1);
                    state=0;
                }
                break;

            case 10:
                if (c=='*') {
                    state=11;
                } else {
                    fprintf(fp2,"\ninvalid lexeme");
                    state=0;
                }
                break;

            case 11:
                if (c=='*') {
                    state=12;
                } else {
                    state=11;
                }
                break;

            case 12:
                if (c=='*') {
                    state=12;
                } else if (c=='/') {
                    state=0;
                } else {
                    state=11;
                }
                break;

        } // end of switch
    } // end of while

    if (state==11)
        fprintf(fp2,"\ncomment did not close");

    fclose(fp1);
    fclose(fp2);

    printf("Finished Lexical Analysis.\n\n");
    printf("Symbol Table Generated.\n\n");

    i=-1;
    while( symb_tab[++i][0] ) {
        printf("%2d  %s\n",i,symb_tab[i]);
    }

    return 0;
 }
