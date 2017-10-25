#include <stdio.h>

void print_day(int d)
{
    if (d > 9)
        printf("%d", d);
    else
        printf(" %d", d);
}

int main(void)
{
    printf("AUGUST\n");

    int yoil = 2;
    printf("SU MO TU WE TH FR SA\n");
    printf("      ");
    for (int i = 1; i <= 31; i++)
    {
        print_day(i);
        printf(" ");
        yoil++;
        if (yoil > 6)
        {
            printf("\n");
            yoil = 0;
        }
    }
    printf("\n");
}


