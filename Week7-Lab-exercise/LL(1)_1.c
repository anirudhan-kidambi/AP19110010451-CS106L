#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i=0, top=0;
char stack[20], ip[20];

void push(char c)
{
    if (top >= 20)
        printf("Stack Overflow");
    else
        stack[top++]=c;
}

void pop(void)
{
    if (top < 0)
        printf("Stack underflow");
    else
        top--;
}

void raise_error(void)
{
    printf("\n\nOOPS! Input string is invalid\n");
    exit(0);
}

int main()
{
    int n;
    printf("------------\n");
    printf("CFG\n");
    printf("------------\n");
    printf("S -> aBa\n");
    printf("B -> bB | ε \n");
    printf("------------\n");
    printf("\nEnter string to be parsed : ");
    scanf("%s",ip);
    n = strlen(ip);
    ip[n] = '$';
    ip[n+1] = '\0';
    push('$');
    push('S');
    while (ip[i] != '\0')
    {
        if (ip[i]=='$' && stack[top-1]=='$')
        {
            printf("\nSUCCESS: String was parsed completely.\n");
            return 1;
        }
        else if (ip[i]==stack[top-1])
        {
            printf("\n match of '%c' \n",ip[i]);
            i++;pop();
        }
        else
        {
            if (stack[top-1]=='S' && ip[i]=='a')
            {
                printf(" \n S -> aBa");
                pop();
                push('a');
                push('B');
                push('a');
            }
            else if (stack[top-1]=='B' && ip[i]=='b')
            {
                printf("\n B -> bB");
                pop();push('B');push('b');
            }
            else if (stack[top-1]=='B' && ip[i]=='a')
            {
                printf("\n B -> ε");
                pop();
            }
            else
                raise_error();
        }
    }
}
