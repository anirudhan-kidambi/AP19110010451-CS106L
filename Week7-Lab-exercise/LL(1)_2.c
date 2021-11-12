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
    printf("---------------\n");
    printf("CFG\n");
    printf("---------------\n");
    printf("E -> TE'\n");
    printf("E'-> +TE' | ε \n");
    printf("T -> FT' \n");
    printf("T'-> *FT' | ε \n");
    printf("F -> (E)  | d \n\n");
    printf("---------------\n");
    printf("\nEnter string to be parsed : ");
    scanf("%s",ip);
    n = strlen(ip);
    ip[n] = '$';
    ip[n+1] = '\0';
    push('$');
    push('E');
    while (ip[i] != '\0')
    {
        if (ip[i]=='$' && stack[top-1]=='$')
        {
            printf("\n\nSUCCESS: String was parsed completely.\n");
            return 1;
        }
        else if (ip[i]==stack[top-1])
        {
            printf("\n match of '%c' \n",ip[i]);
            i++;pop();
        }
        else
        {
            if ( stack[top-1]=='E' &&
                    (ip[i]=='d' || ip[i]=='(')
               )
            {
                printf("\n E -> TE'");
                pop();
                push('A');//E'
                push('T');
            }
            else if (stack[top-1]=='A' && ip[i]=='+') //E'
            {
                printf("\n E' -> +TE'");
                pop();push('A');push('T');push('+');
            }
            else if ( stack[top-1]=='A' &&
                        (ip[i]==')' || ip[i]=='$')
                    )
            {
                printf("\n E' -> ε");
                pop();
            }
            else if ( stack[top-1]=='T' &&
                        (ip[i]=='d' || ip[i]=='(')
                    )
            {
                printf("\n T -> FT'");
                pop();push('B');push('F'); //B is T'
            }
            else if (stack[top-1]=='B' && ip[i]=='*')
            {
                printf("\n T' -> *FT'");
                pop();push('B');push('F');push('*');
            }
            else if ( stack[top-1]=='B' &&
                        (ip[i]=='+' || ip[i]==')'|| ip[i]=='$')
                    )
            {
                printf("\n T' -> ε");
                pop();
            }
            else if (stack[top-1]=='F' && ip[i]=='d')
            {
                printf("\n F -> d");
                pop();push('d');
            }
            else if (stack[top-1]=='F' && ip[i]=='(')
            {
                printf("\n F -> (E)");
                pop();push(')');push('E');push('(');
            }
            else
                raise_error();
        }
    }
}
