#include <stdio.h>
#include <math.h>

double proot(int a, int b, int c)
{
    return ((-b) + sqrt((b * b) - (4.f * a * c))) / (2.f * a);
}

double nroot(int a, int b, int c)
{
    return ((-b) - sqrt((b * b) - (4.f * a * c))) / (2.f * a);
}

double pe(int a, int b, int c)
{
    return (b * b) - (4.f * a * c);
}

int main(void)
{
    int a, b, c;
    printf("a b c\n");
    scanf("%d %d %d", &a, &b, &c);

    int p = pe(a, b, c);
    if (p > 0)
        printf("two root: %f, %f\n", proot(a, b, c), nroot(a, b, c));
    else if (p == 0)
        printf("one root: %f\n", proot(a, b, c));
    else
        printf("no root\n");
}
