#include <stdio.h>
#include <stdlib.h>

/*
 * Recognizer for language with last two symbols being same
 * Alphabets : a, b
 */
int main()
{
    int state = 0;

    printf("Enter input string: ");
    char token = getchar();

    while(token != '\n')
    {
        switch(state)
        {
            case 0:
                if (token == 'a') {
                    state = 1;
                } else if (token == 'b') {
                    state = 2;
                } else {
                    printf("Invalid token");
                    exit(0);
                }
                break;
            case 1:
                if (token == 'a') {
                    state = 3;
                } else if (token == 'b') {
                    state = 2;
                } else {
                    printf("Invalid token");
                    exit(0);
                }
                break;
            case 2:
                if (token == 'a') {
                    state = 1;
                } else if (token == 'b') {
                    state = 4;
                } else {
                    printf("Invalid token");
                    exit(0);
                }
                break;
            case 3:
                if (token == 'a') {
                    state = 3;
                } else if (token == 'b') {
                    state = 2;
                } else {
                    printf("Invalid token");
                    exit(0);
                }
                break;
            case 4:
                if (token == 'a') {
                    state = 1;
                } else if (token == 'b') {
                    state = 4;
                } else {
                    printf("Invalid token");
                    exit(0);
                }
                break;
            default:
                printf("\nReached an undefined State\n");
                exit(0);
                break;
        }

        printf(">>> current token = %c , state = %d\n", token, state);
        token = getchar();
    }

    if (state == 3 || state == 4)
        printf("\nString accepted\n");
    else
        printf("\nString NOT accepted\n");

    return 0;
}
