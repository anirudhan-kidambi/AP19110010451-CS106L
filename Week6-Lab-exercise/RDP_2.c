#include <stdio.h>
#include <string.h>

int S(), L(), Ldash();

char *ip;
char string[50];

int main()
{
    printf("--------------\n");
    printf("CFG\n");
    printf("--------------\n");
    printf("S -> (L) | a  \n");
    printf("L -> SL'      \n");
    printf("L'-> ,SL'| ε \n");
    printf("--------------\n");
    printf("\nEnter input string: ");
    scanf("%s",string);
    ip=string;
    printf("\n\n%20s\tAction\n----------------------------------\n", "Input");
    if(S() && *ip=='\0'){
        printf("\n----------------------------------\n");
        printf("\nSUCCESS: String was completely parsed\n");
    }
    else{
        printf("\n----------------------------------\n");
        printf("ERROR: Bad string\n");
    }
}

int S()
{
    if(*ip=='(')
    {
        printf("%20s\tS -> (L) \n",ip);
        ip++;
        if(L())
        {
            if(*ip==')')
            {
                ip++;
                return 1;
            }
            else
                return 0;
        }
        else
            return 0;
    }
    else if(*ip=='a')
    {
        ip++;
        printf("%20s\tS -> a \n",ip);
        return 1;
    }
    else
        return 0;
}

int L()
{
    printf("%20s\tL -> SL' \n",ip);
    if(S())
    {
        if(Ldash())
        {
            return 1;
        }
        else
            return 0;
    }
    else
        return 0;
}

int Ldash()
{
    if(*ip==',')
    {
        printf("%20s\tL'-> ,SL' \n",ip);
        ip++;
        if(S())
        {
            if(Ldash())
            {
                return 1;
            }
            else
                return 0;
        }
        else
            return 0;
    }
    else
    {
        printf("%20s\tL'-> ε \n",ip);
        return 1;
    }
}
