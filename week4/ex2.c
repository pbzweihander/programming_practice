#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fight(int p, int c)
{
    // 0O: Rock, 1X: Scissor, 2#: Paper
    return (p == 0 && c == 1) || (p == 1 && c == 2) || (p == 2 && c == 0);
}

char* to_string(int i)
{
    switch (i)
    {
        case 0:
            return "rock";
        case 1:
            return "scissor";
        case 2:
            return "paper";
        default:
            return "";
    }
}

int main(void)
{
    srand(time(NULL));

    printf("Game start!\n");
    int won = 0;
    do
    {
        char s;
        printf("Choose rock(O), scissor(X), paper(#)\n");
        scanf("%c", &s);
        getchar();

        int p;
        int c = rand() % 3;
        switch (s)
        {
            case 'O':
                p = 0;
                break;
            case 'X':
                p = 1;
                break;
            case '#':
                p = 2;
                break;
            default:
                return 0;
        }

        printf("user: %s, computer: %s\n", to_string(p), to_string(c));

        won = fight(p, c);
        if (won)
            printf("You win\n\n");
        else
            printf("You lose\n\n");

    } while (!won);
    return 0;
}
